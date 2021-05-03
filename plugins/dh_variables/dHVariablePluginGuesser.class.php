<?php

// @todo: this might never be needed as we should make a more robust method and automatically
//        set the config options for each variable based on the CSV data display settings

class dHVariablePluginGuesser extends dHVariablePluginDefault {
  // @todo:
  var $entity_type;
  var $variable_label;
  var $value_label;
  var $start_label;
  var $end_label;
  var $code_label;
  var $row_map;
  
  public function __construct($conf = array()) {
    $this->conf = $conf;
    $this->optionDefaults();
  }
  
  public function optionDefaults($conf = array()) {
    if (!isset($conf['entity_type'])) {
      return FALSE;
    } else {
      $this->entity_type = $conf['entity_type'];
    }
    switch ($this->entity_type) {
      case 'dh_timeseries':
      $this->row_map = array(
        'id' => array('name'=>'tid','hidden' => 1),
        'value' => array('name'=>'tsvalue','hidden' => 0),
        'text' => array('name'=>'tstext','hidden' => 0),
        // where to put the varname label?  This will only be used by the old-school method of guessing
        'varname' => array('name'=>'varname','hidden' => 0),
        'code' => array('name'=>'tscode','hidden' => 0),
        'start' => array('name'=>'tstime','hidden' => 0),
        'end' => array('name'=>'tsendtime','hidden' => 0),
        'featureid' => array('name'=>'featureid','hidden' => 1),
        'entity_type' => array('name'=>'entity_type','hidden' => 1),
      );
      break;
      case 'dh_properties':
      $map = array(
        'varid' => 'varid',
        'id' => 'pid',
        'value' => 'propvalue',
        'text' => 'proptext',
        'varname' => 'propvalue',
        'code' => 'propcode',
        'start' => 'startdate',
        'end' => 'enddate',
        'featureid' => 'featureid',
        'entity_type' => 'entity_type',
        'name' => 'propname',
      );
      break;
      
      default:
      // will not process anything
      $this->row_map = array();
      break;
    }
    if (isset($conf['row_map'])) {
      $this->row_map = $conf['row_map'] + $this->row_map;
    }
  }
  
  public function handleVariableIDPrepop(&$rowform, &$varid) {
    
    // this is an insert request, need to handle variables here because 
    // prepopulate module does not allow setting of invisibles
    // if prepopulate is not used and varid is set, this will return the form varid
    if (isset($_REQUEST['edit'])) {
      if (!empty($_REQUEST['edit']['varid'])) {
        $varid = intval($_REQUEST['edit']['varid']);
        $oldvarid = $rowform['varid']['#value'];
        $rowform['varid']['#value'] = $varid;
      }
      if (!empty($_REQUEST['edit']['featureid'])) {
        $featureid = intval($_REQUEST['edit']['featureid']);
        $rowform['featureid']['#value'] = $featureid;
      }
      if (!empty($_REQUEST['edit']['entity_type'])) {
        $entity_type = $_REQUEST['edit']['entity_type'];
        $rowform['entity_type']['#value'] = $entity_type;
      }
      if (!empty($_REQUEST['edit']['propname'])) {
        $propname = $_REQUEST['edit']['propname'];
        $rowform['propname']['#value'] = $propname;
      }
    } else {
      if (isset($rowform['varid']['#default_value'])) {
        if (intval($rowform['varid']['#default_value']) > 0) {
          $varid = intval($rowform['varid']['#default_value']);
        }
      }
    }
  }
  
  public function formRowEdit(&$rowform, $row) {
    $this->optionDefaults();
    // Row Record:
    $rowform['featureid'] = array(
      '#type' => $this->property_conf_default['featureid']['#type'],
      '#default_value' => $row->featureid,
    );
    $rowform['varname'] = array(
      '#coltitle' => 'Var Name',
      '#markup' => $row->varname,
    );
    $map = $this->property_conf_default;
    // @todo: support broader settings in a "config" column on dh_variable_definition table
    //   For each property (id, value, text, varname, ...) support the following settings:
    //     - #title 
    //     - visible (select T/F)
    //     - Read/Write (select R/W)
    //     - #weight (select -15 to +15) - this can be used in the config form as well as render form
    // $_REQUEST is variable used by prepopulate module 
    $visibility = array();
    $vinfo = array();
    $varid = FALSE;
    // get info from variable prepopulate or form current contents
    // for varid, entity_type, featureid 
    $this->handleVariableIDPrepop($rowform, $varid);
    $this->handleVisibility($rowform, $visibility, $varid, $vinfo);  
    $this->applyLabels($rowform, $visibility, $vinfo);
  }
  public function applyLabels(&$rowform, $visibility, $vinfo) {
    
    // guess variable name position based on visibility, value is first choice, then code, then text
    if ($visibility[$map['value']['name']]) {
      $rowform[$map['varname']['name']]['#label'] = $vinfo->varname;
      $rowform[$map['varname']['name']]['#title'] = $vinfo->varname;
      $rowform[$map['varname']['name']]['#description'] = $vinfo->vardesc;
    } else {
      if ($visibility[$map['code']['name']]) {
        $rowform[$map['code']['name']]['#label'] = $vinfo->varname;
        $rowform[$map['code']['name']]['#title'] = $vinfo->varname;
        $rowform[$map['code']['name']]['#description'] = $vinfo->vardesc;
      } else {
        if ($visibility[$map['start']['name']]) {
          $rowform[$map['start']['name']]['#label'] = $vinfo->varname;
          $rowform[$map['start']['name']]['#title'] = $vinfo->varname;
          $rowform[$map['start']['name']]['#description'] = $vinfo->vardesc;
        } else {
          if ($visibility[$map['end']['name']]) {
            $rowform[$map['end']['name']]['#label'] = $vinfo->varname;
            $rowform[$map['end']['name']]['#title'] = $vinfo->varname;
            $rowform[$map['end']['name']]['#description'] = $vinfo->vardesc;
          } else {
            if ($visibility[$map['text']['name']]) {
              $rowform[$map['text']['name']]['und'][0]['value']['#title'] = $vinfo->varname;
              $rowform[$map['text']['name']]['und'][0]['value']['#description'] = $vinfo->vardesc;
            }
          }
        }
      }
    }
  }
  
  public function handleVisibility(&$rowform, &$visibility, $varid, &$vinfo) {
    if ($varid) {
      $vinfo = dh_vardef_info($varid);
      if ($vinfo->hydroid <> $varid) {
        // this was a varkey query, so we replace varid in _REQUEST
        $_REQUEST['edit']['varid'] = $vinfo->hydroid;
      }
      if ($vinfo) {
        if (strlen(trim($vinfo->data_entry)) > 0) {
          $var_display_types = explode(',', $vinfo->data_entry);
          // override 
          $rowform[$map['varname']['name']]['#label'] = $vinfo->varname;
          $rowform[$map['varname']['name']]['#title'] = $vinfo->varname;
          $rowform[$map['varname']['name']]['#description'] = $vinfo->vardesc;
          $visibility = array_fill_keys(array_unique(array_values($map)), FALSE);
          foreach ($var_display_types as $dtype) {
            switch (trim($dtype)) {
              case 'numeric':
              case 'value':
              $visibility[$map['value']['name']] = TRUE;
              break;
              case 'text':
              $visibility[$map['text']['name']] = TRUE;
              break;
              case 'boolean':
              $visibility[$map['value']['name']] = TRUE;
              // set value as select list
              $options = array(
                0 => 'FALSE',
                1 => 'TRUE',
              );
              $rowform[$map['value']['name']]['#type'] = 'select'; 
              $rowform[$map['value']['name']]['#options'] = $options; 
              $rowform[$map['value']['name']]['#size'] = 1; 
              break;
              case 'date_start':
              $visibility[$map['start']['name']] = TRUE;
              break;
              case 'date_end':
              $visibility[$map['end']['name']] = TRUE;
              break;
              case 'code':
              $visibility[$map['code']['name']] = TRUE;
              break;
              case 'index':
              $visibility[$map['value']['name']] = TRUE;
              break;
              case 'name':
              if (isset($map['name'])) {
                $visibility[$map['name']] = TRUE;
              }
              break;
            }
          }
        }
      }
    } else {
      $vinfo = FALSE;
    }
    foreach ($visibility as $vk => $vv) {
      if (!$vv) {
        if (isset($rowform[$vk])) {
          $rowform[$vk]['#type'] = 'hidden';
        }
      }
    }
  }
  
  public function propertyOptions(&$rowform, $rowform_state) {
    // this sets up properties that are to be controlled in the form
  }  
  
  public function buildOptionsForm(&$rowform, $rowform_state) {
    // Form for configuration when editing in variable defintion interface
    // called from dh_variabledefinition_form()
  }
  
}

?>