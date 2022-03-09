<?php
/**
 * @file
 * Grouped dH entity handler classes.
 * See also: plugins/components/properties_pane_default.inc 
 *   for UI integration setup  
 */
 
ctools_include('plugins');
    
interface dhFormInterface {
  // see d8 FormInterface for details
  public function getFormId();
  // @todo -- deprecate pass by reference for form in future versions
  //   - Drupal 8 EntityForm = public function buildForm(array $form, FormStateInterface $form_state)
  public function buildForm(array &$form, &$form_state);
  public function buildOptionsForm(array &$form, $form_state);
  public function validateForm(array &$form, $form_state);
  public function submitForm(array &$form, $form_state);
  public function OptionDefaults();
  public function EntityDefaults();
  public function EntityOptions();
  public function PropertyOptions();
  public function FieldOptions();
  public function extraOptions(array &$form, $form_state);
  public function FormEntityMap(array &$form_entity_map, array $row);

}

class EntityGroupConfigurator {
  var $efq;
  var $base_entity_type = NULL;
  var $base_bundle;
  var $base_form_id;
  var $property_conf_default = array();
  var $entity_defaults = array();
  var $row_data_defaults = array();
  var $conf = array();
  var $destination;
  var $nextpage;
  var $headers;
  var $form_columns;
  var $allprops = FALSE;  // should we add props in the form_values array if they don't exist on base class?
  var $use_rebuild_code = FALSE; // used to test dynamic rebuilding in ajax
  var $data;
  var $id;
  var $start = 0;
  var $limit = 25;
  var $entity_info;
  var $entity_tokens = array();
  var $row_tokens = array();
  var $query = FALSE;
  var $save_method = 'default';
  var $render_layout = 'table';
  
  function __construct($conf = array()) {
    if (!is_array($conf)) {
      $conf = array();
    }
    //dpm($conf,'conf to construct');
    // what default column formats are present on this class?
    $this->optionDefaults();
    // what default column formats are defined in this classes default form?
    $this->headerDefaults();
    // What defaults are passed in via ctools or calling function?
    // these options should take precedence
    $this->conf = $conf + $this->conf;
    $this->entityDefaults();
    $this->data = array();
    $this->id = array();
    $this->limit = isset($conf['limit']) ? $conf['limit'] : $this->limit;
    $this->base_entity_type = isset($conf['entity_type']) ? $conf['entity_type'] : $this->base_entity_type;
    $this->base_bundle = isset($conf['display']['bundle']) ? $conf['display']['bundle'] : NULL;
    $this->destination = isset($conf['destination']) ? $conf['destination'] : NULL;
    $this->base_form_id = isset($conf['form_id']) ? $conf['form_id'] : NULL;
    $this->form_columns = isset($conf['form_columns']) ? $conf['form_columns'] : $this->entity_defaults['form_columns'];
    $this->add = isset($conf['add']) ? $conf['add'] : 0;
    $this->entity_info = entity_get_info($this->base_entity_type);
    $this->applySettings();
  }
  
  public function FormEntityMap(&$form_entity_map = array(), $row = array()) {
  }
  
  function submitForm(array &$form, $form_state) {
    $this->applyEntityTokens();
    $this->applySettings();
    // identify records that this is supposed to handle
      // main form field name $this->groupname, i.e. ts_group
    // iterate through, do updates for those with PKID, inserts for those with NULL PKID
    if ($this->save_method == 'form_entity_map') {
      $this->SubmitFormEntityMap($form, $form_state);
    } else {
      $this->SubmitFormCustom($form, $form_state);
    }
  }
  function SubmitFormCustom(array &$form, $form_state) {
    foreach ($form_state['values'][$this->groupname] as $record_group) {
      //dpm($record_group,"Record Group");
    }
  }
  
  public function applyFormStateEntityProperties(&$entity, $record_group) {
    foreach ($record_group as $key => $val) {
      if (property_exists($entity, $key) or $this->allprops) {
        $entity->{$key} = $val;
      }
    }
  }
  
  public function entity_save($entity_type, $e) {
    // children classes can do any pre-save mods here 
    entity_save($entity_type, $e);
  }
  
  function SubmitFormEntityMap(array &$form, $form_state) {
    // uses entity_map to handle all inserts and updates
    foreach ($form_state['values'][$this->groupname] as $record_group) {
      $form_entity_map = array();
      // set up defaults
     
      $this->FormEntityMap($form_entity_map, $record_group);
      foreach ($form_entity_map as $config) {
        $values = array();
        if (!isset($config['bundle'])) {
          $config['bundle'] = null;
        }
        $entity_type = $config['entity_type'];
        $bundle = $config['bundle'];
        // is this an edit or insert?
        // load the key
        $pk = $this->HandleFormMap($config['entity_key'], $record_group);
        // load the values array
        $values = array();
        $values['groupname'] = $this->groupname; // pass this in for special hook handling
        foreach ($config['fields'] as $key => $map) {
          if ($map['value_src_type']) {
            $values[$key] = $this->HandleFormMap($map, $record_group);
          } else {
            // @todo - throw an error or alert about malformed entry
          }
        }
        if ($pk) {
          // PK set, so this is an update
          $e = entity_load_single($entity_type, $pk);
          foreach ($values as $key => $val) {
            $e->{$key} = $val;
          }
        } else {
          // no PK set, so this is an insert
          $values['bundle'] = $bundle;
          $e = entity_create($entity_type, $values);
        }
        // now that values are assigned load formRowPlugins for the row and process save functions
        $this->formRowPlugins($record_group, $e, 'save');
        if ($e) {
          //dpm($e,'entity to save');
          $this->entity_save($entity_type, $e);
        }
      }
    }
  }
    
  public function HandleFormMap($map, $data) {
    // returns value or FALSE if not handled
    //dpm($map, "Handling map");
    //dpm($data, "Data");
    switch($map['value_src_type']) {
      case 'form_key':
        $value = $this->HandleFormMap_form_key($map, $data);
      break;
      case 'constant':
        $value = $this->HandleFormMap_constant($map, $data);
      break;
      case 'env':
        $value = $this->HandleFormMap_env($map, $data);
      break;
    }
    return $value;
  }
  
  public function HandleFormMap_form_key($map, $data) {
    $key = $map['value_val_key'];
    if (isset($data[$key])) {
      if (isset($map['concat'])) {
        $value = implode($map['concat'], $data[$key]);
      } else {
        $value = $data[$key];
      }
      if ($debug) drupal_set_message("CID $thiskey contains value " . $submission->data[$thiskey][0] . "From array " . print_r($submission->data[$thiskey],1));
    } else {
      // pk is not set but we should check to see if there is a 
      // set of unique conditions in the map, 
      //    ex: 'unique' => array('entity_type', 'featureid', 'varid')
      //    this would say this can only have one entry per varid
      // would have to have an action to follow up, like overwrite 
      // we can also allow sub-classes to handle this by just sub-classing
      return FALSE;
    }
    return $value;
  }
  
  public function HandleFormMap_constant($map, $data) {
    return $map['value_val_key'];
  }
  
  public function SaveDataObjectsAsForm($data = array()) {
    // takes an array of objects, converts them into facsimile of $form_state['values']
    // and then calls the regular form handling plumbing to save
    // defaults to object data array
    if (count($data) == 0) {
      $data = $this->data;
    }
    $psuedo_form = array();
    $psuedo_form_state = array(
      'values' => array(
        $this->groupname => array()
      )
    );
    foreach ($data as $record) {
      if (is_object($record)) {
        $psuedo_form_state['values'][$this->groupname][] = get_object_vars($record);
      } else {
        if (is_array($record)) {
          $psuedo_form_state['values'][$this->groupname][] = $record;
        } else {
          watchdog('dh_entity_group_configurator', "Malformed data array sent to SaveDataObjectsAsForm()");
        }
      }
    }
    //dpm($psuedo_form_state, "final psuedo_form_state");
    if (count($psuedo_form_state['values'][$this->groupname]) > 0) {
      $this->submitForm($psuedo_form, $psuedo_form_state); 
    } else {
      watchdog('dh_entity_group_configurator', "SaveDataObjectsAsForm() called with empty data array.");
    }
  }
  
  public function HandleFormMap_env($map, $data) {
    // @todo - log a message about missing env
    return $this->env[$map['value_val_key']];
  }
  
  public function validateForm(array &$form, $form_state) {
    drupal_validate_form($this->getFormId, $form, $form_state);
  }
  
  function getFormStateData($form, $form_state) {
    error_log("Looking for form_state[$this->groupname]");
    if (!isset($form_state['values'][$this->groupname])) {
       error_log("Could not find form_state['values'][$this->groupname]");
      // throw exception un-prepared query
      return FALSE;
    }
    foreach ($form_state['values'][$this->groupname] as $row) {
      //error_log("Adding row: " . print_r($row,1));
      $this->data[] = (object)$row;
    }
  }
  
  function hidePropCols($hidden) {
    foreach ($hidden as $hide) {
      $this->conf['display']['properties'][$hide]['hidden'] = TRUE;
    }
  }
  
  function showPropCols($shown) {
    foreach ($shown as $show) {
      $this->conf['display']['properties'][$show]['hidden'] = FALSE;
    }
  }
  
  function applyRowDataDefaults(&$row, $defaults = array()) {
    // - config search array
    //   - 'criteria' => (could be pid, propname, varid, varkey, ...)
    //   - 'values' (values to apply if criteria is matched key/value array could be propname, varid, varkey -- all but pid)
    // handle both object and array as row
    if (count($defaults) == 0) {
      $defaults = $this->row_data_defaults;
    }
    uasort($defaults, 'element_sort');
    //dpm($row,"Evaluating criteria for row");
    $match = FALSE;
    foreach ($defaults as $defs) {
      unset($match);
      foreach ($defs['criteria'] as $key => $criteria) {
        $required = isset($criteria['required']) ? $criteria['required'] : TRUE;
        $rowmatch = $this->evaluateRowCriteria($row, $key, $criteria);
        switch ($required) {
          case FALSE:
          $match = isset($match) ? $rowmatch || $match : $rowmatch;
          break;
          case TRUE:
          default:
          $match = isset($match) ? $rowmatch && $match : $rowmatch;
          break;
        }
        //dpm($match, "after criteria $key match = ");
      }
      if ($match) {
        // apply defaults
        //dpm($defs['values'], "applying values");
        foreach ($defs['values'] as $key => $value) {
          $this->applyRowValue($row, $key, $value);
        }
      }
    }
  }
  
  function evaluateRowCriteria($row, $key, $criteria) {
    //dpm($row, "row - key = $key");
    //dpm($criteria, "criteria");
    if (is_object($row)) {
      if (!property_exists($row, $key)) {
        watchdog('dh_entity_group_configurator', "evaluateRowCriteria() called with invalid key: $key");
        return FALSE;
      }
      $value = $row->$key;
    } else {
      if (!is_array($row)) {
        watchdog('dh_entity_group_configurator', "evaluateRowCriteria() called with invalid row - must be array or object.");
        return FALSE;
      }
      $value = $row[$key];
    }
    if (!isset($criteria['op'])) {
      $criteria['op'] = '=';
    }
    //dpm(($value == $criteria['value']), "(value == criteria['value'])");
    switch ($criteria['op']) {
       case '=':
       case 'eq':
       default:
         return ($value == $criteria['value']);
       break;
    }
  }
  
  function applyRowValue(&$row, $key, $value) {
    if (is_object($row)) {
      if (!property_exists($row, $key)) {
        watchdog('dh_entity_group_configurator', "applyRowValue() called with invalid key: $key");
        return FALSE;
      }
      $row->$key = $value;
    } else {
      if (!is_array($row)) {
        watchdog('dh_entity_group_configurator', "applyRowValue() called with invalid row - must be array or object.");
        return FALSE;
      }
      $row[$key] = $value;
    }
  }
  
  function getData() {
    if (!is_object($this->efq)) {
      // throw exception un-prepared query
      return FALSE;
    }
    $result = $this->efq->execute();
    //drupal_set_message("efq: <pre>" . print_r($result ,1) . "</pre>");
    if (isset($result[$this->base_entity_type])) {
      $this->data = entity_load($this->base_entity_type, array_keys($result[$this->base_entity_type]));
    }
    //dpm($this->data, "Data");
    // now need to take this list of entity ids and return it as a proper dataset.
    // this is where certain sub-classes may want to override this method and use a straight query if it is more economical
  }
  
  public function applySettings() {
    // add extras to fields to display
    foreach (array_keys($this->conf['display']['properties']) as $field_key) {
      if (!in_array($field_key, array('addlink','deletelink','editlink'))) {
        //dpm($this->conf['display']['properties'][$field_key], "conf for $field_key");
        if (!isset($this->conf['display']['properties'][$field_key])) {
          if (isset($this->property_conf_default[$field_key])) {
            $this->conf['display']['properties'][$field_key] = $this->property_conf_default[$field_key];
          }
        }
        //dpm($this->conf['display']['properties'][$field_key], "after default check for $field_key");
        $this->conf['display']['properties'][$field_key]['hidden'] = !isset($this->conf['display']['properties'][$field_key]['hidden']) ? FALSE : $this->conf['display']['properties'][$field_key]['hidden'];
        if (!$this->conf['display']['properties'][$field_key]['hidden']) {
          // add it to form_columns if it does not exist
          if (!in_array($field_key,$this->form_columns)) {
            $this->form_columns[] = $field_key;
          }
        }
      }
    }
    foreach (array_keys($this->conf['display']['fields']) as $field_key) {
      if (!$this->conf['display']['fields'][$field_key]['hidden']) {
        // add it to form_columns if it does not exist
        if (!in_array($field_key,$this->form_columns)) {
          $this->form_columns[] = $field_key;
        }
      }
    }
    // now add the special ones
    $this->form_columns[] = 'deletelink';
    $this->form_columns[] = 'editlink';
    $this->form_columns[] = '#weight';
  }
  
  public function applyRowTokens($text, $row) {
    foreach ($this->row_tokens as $token) {
      if (property_exists($row, $token)) {
        $tokens["[$token]"] = $row->$token;
      }
    }
    return strtr($text, (array)$tokens);
  }
  
  public function applyEntityTokens() {
    $row_token_keys = array('default');
    // apply entity tokens
    foreach ($this->entity_tokens as $token) {
      $val = NULL;
      if (property_exists($this, $token) and isset($this->conf[$token])) {
        $val = token_replace($this->conf[$token], array(), array('clear'=>TRUE));
      }
      $this->conf[$token] = $val;
    }
    // apply row tokens if requested
    foreach ($this->row_tokens as $token) {
      foreach ($row_token_keys as $key) {
        if (isset($this->conf['display']['properties'][$token][$key])) {
          $val = token_replace($this->conf['display']['properties'][$token][$key], array(), array('clear'=>TRUE));
          $this->conf['display']['properties'][$token][$key] = $val;
        }
        if (isset($this->conf['display']['fields'][$token][$key])) {
          $val = token_replace($this->conf['display']['fields'][$token][$key], array(), array('clear'=>TRUE));
          $this->conf['display']['fields'][$token][$key] = $val;
        }
      }
    }
  }
  
  function prepareQuery() {
    $this->applyEntityTokens();
    $this->applySettings();
    // children can call this parent method and then add additional
    // EFQ conditions if more sophisticated behavior is desired
    if (!strlen($this->base_entity_type)) {
      return FALSE;
    }
    $einfo = $this->entity_info;
    if (!isset($einfo['entity keys']['id'])) {
      // throw malformed entity exception and return
      return FALSE;
    }
    $this->efq = new EntityFieldQuery;
    $this->efq->entityCondition('entity_type', $this->base_entity_type);
    $this->efq->range($this->start, $this->limit);
    if (!empty($this->id)) {
      $this->efq->propertyCondition($einfo['entity keys']['id'], $this->id, '=');
      //drupal_set_message("Arg: '$argument'");
    }
    if (!empty($this->base_bundle)) {
      $binfo = field_info_instances($this->base_entity_type, $this->base_bundle);
      foreach (array_keys((array)$binfo) as $field) {
        if (property_exists($this,$field)) {
          if (!empty($this->$field)) {
            $this->efq->fieldCondition($field,NULL,$this->$field);
          }
        }
      }
    }
    foreach ($einfo['property info'] as $prop) {
      //dpm($prop, "prop");
      if (property_exists($this,$prop)) {
        if (!empty($this->$prop)) {
          //dpm($this->$prop, "prop exists");
          $this->efq->propertyCondition($prop,$this->$prop);
        }
      }
    }
    //dpm($this->efq, "Final EFQ");
    return TRUE;
  }
  
  public function buildOptionsForm(&$form, $form_state) {
    $this->entity_info = entity_get_info($this->base_entity_type);
    $this->entityOptions($form, $form_state);
    $this->propertyOptions($form, $form_state);
    $this->fieldOptions($form, $form_state);
    $this->extraOptions($form, $form_state);
  }
  
  public function extraOptions(&$form, $form_state) {
    
  }
  
  public function optionDefaults() {
    $this->property_conf_default = array();
  }
  
  public function entityDefaults() {
    // get default list and order of form columns from blank form
    // HEADERS - sets 
    $this->env = array(
      'now' => date('r'),
      'epoch' => date('U'),
    );
    // entries in the entity_defaults array get special handling:
    // * for each $key in $this->entity_defaults, if a matching value is 
    //   present in the $conf array, the object property of the 
    //   the name $this->$key is set in $this->applySettings()
    
    $this->entity_defaults['render_layout'] = 'table';
    $this->entity_defaults['row_data_defaults'] = array();
  }
  
  public function headerDefaults() {
    $this->entity_defaults['headers'] = array();
    // get default list and order of form columns from blank form
    $blank_form_row = array();
    $blank_object = entity_create($this->base_entity_type, array());
    if (!$blank_object) {
      $blank_object = new StdClass;
    }
    $this->formRowDefaults($blank_form_row, $blank_object);
    // set form_columns - control WHAT is included (not visibility), and the ORDER
    $this->entity_defaults['form_columns'] = array_keys($blank_form_row);
    //dpm($this->entity_defaults,'defs');
    // now, we must set headers up here because we do not have a config view 
    foreach ($blank_form_row as $col => $formfield) {
      $this->conf['display']['properties'][$col]['title'] = $formfield['#coltitle'];
      $this->entity_defaults['headers'][$col] = $formfield['#coltitle'];
      if ($formfield['#type'] == 'hidden') {
        $this->conf['display']['properties'][$col]['hidden'] = 1;
        $this->entity_defaults['headers'][$col] = '';
      }
    }
  }
  
  public function entityOptions(&$form, $form_state) {
    $form['entity_settings'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => 'Entity Base Form Info',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#description' => 'Entity Base Form Info',
    );
    $dispoptions = array('form' => t('Edit Form'), 'table' => t('Table View'));
    $form['entity_settings']['display_type'] = array(
      '#title' => 'Type of Display',
      '#type' => 'select',
      '#default_value' => isset($this->conf['display_type']) ? $this->conf['display_type'] : 'form',
      '#description' => t('Form of data display.'),
      '#options' => $dispoptions,
    );
    $layout_options = array(
      'unformatted' => t('Un-Formatted'), 
      'unformatted_striped' => t('Un-Formatted w/Striping'), 
      'table' => t('Table View')
    );
    $form['entity_settings']['render_layout'] = array(
      '#title' => 'Render Layout',
      '#type' => 'select',
      '#default_value' => isset($this->conf['render_layout']) ? $this->conf['render_layout'] : 'table',
      '#description' => t('Render mode of selected Display.'),
      '#options' => $layout_options,
    );
    $form['entity_settings']['limit'] = array(
      '#title' => t('Max # Records'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['limit']) > 0) ? $this->conf['limit'] : $this->limit,
      '#description' => t('Max number of entities to retrieve.'),
      '#size' => 10,
      '#required' => FALSE,
    );  
    $form['entity_settings']['entity_type'] = array(
      '#type' => 'hidden',
      '#default_value' => $this->base_entity_type,
      '#required' => TRUE,
    );
    $form['entity_settings']['destination'] = array(
      '#title' => t('Destination'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['destination']) > 0) ? $this->conf['destination'] : NULL,
      '#description' => t('Destination after save (accepts tokens).  Blank uses form default.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['save_label'] = array(
      '#title' => t('Save Label'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['save_label']) > 0) ? $this->conf['save_label'] : NULL,
      '#description' => t('Save Button Text (accepts tokens). Default \"Save\".'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['nextpage'] = array(
      '#title' => t('Next Page'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['nextpage']) > 0) ? $this->conf['nextpage'] : NULL,
      '#description' => t('Destination after Next Button (accepts tokens).  Blank will show no Next Button.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['nextlabel'] = array(
      '#title' => t('Next Label'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['nextlabel']) > 0) ? $this->conf['nextlabel'] : NULL,
      '#description' => t('Next Button Text (accepts tokens). Default \"Next\".'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $addoptions = array(0 => t('FALSE'), 1 => t('TRUE'));
    $form['entity_settings']['add'] = array(
      '#title' => 'Add New Records?',
      '#type' => 'select',
      '#default_value' => isset($this->conf['add']) ? $this->conf['add'] : 0,
      '#description' => t('Checking this will enable Add Form.  The specific handler sub-class must opt to handle this.  The default form will not support this (currently).'),
      '#options' => $addoptions,
    );
    $form['entity_settings']['display'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => 'Entity Field & Properties Info',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#prefix' => "<div id='update-display-options'>",
      '#suffix' => "</div>",
      '#description' => 'Entity Field & Properties Info',
    );
    if ($this->base_entity_type) {
      $entity_info = $this->entity_info;
      $bundle_options = array_combine( array_keys($entity_info['bundles']) , array_keys($entity_info['bundles']) );
    } else {
      $bundle_options = array();
    }
    $form['entity_settings']['display']['bundle'] = array(
      '#title' => t('Entity bundle'),
      '#type' => 'select',
      '#options' => $bundle_options,
      '#description' => t('Entity bundle'),
      '#required' => TRUE,
    // TODO - allow certain types of bundle fields (short text, select, numeric) in table
      //'#ajax' => array(
      //  'callback' => 'entity_pane_form_fields_update',
      //  'wrapper' => 'update-field-options',
      //),
    );
    // only set this if we have a match, otherwise, we have switched entities, or are a new form
    // either of which should show an un-selected list
    //dpm($form['entity_settings'],'entity settings group object');
    //dpm($this,'prop group object');
    //dpm($bundle_options,'bundle_options');
    if ( in_array($this->base_bundle, $bundle_options) ) {
      $form['entity_settings']['display']['bundle']['#default_value'] = $this->base_bundle;
      $form['entity_settings']['display']['bundle']['#value'];
    } else {
      unset($form['entity_settings']['display']['bundle']['#default_value']);
      unset($form['entity_settings']['display']['bundle']['#value']);
    }
  }
  
  public function formRowVisibility(&$rowform, $row) {
    // sub-classes that implement full visibility control may override this method
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        if (isset($this->conf['display']['properties'][$colname]['hidden']) and ($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          $rowform[$colname]['#type'] = 'hidden';
        }
      }
    }
  }
  
  public function formRowPlugins(&$rowform, $row, $mode = 'build_form') {
    // check to see if we are using plugins, if so:
    //   1. get the varid from this row
    //   2. load the plugin associated with it
    //   3. call plugins 
    //dpm($row, "formRowPlugins");
    if ($row->varid) {
      //@todo: use map to see if varid is using a different field name
      $varinfo = dh_vardef_info($row->varid);
      //error_log("Handling $varinfo->varkey : $varinfo->varname");
      //error_log("Trying to load: ctools_get_plugins('dh', 'dh_variables', $varinfo->plugin)");
      if ($varinfo->plugin == 'dHVariablePluginDefault]') {
        $plugin_def = array(
          'label' => t('Deprecated method for guessing labels for variable display and edit'),
          'handler' =>  array(
            'class' => 'dHVariablePluginDefault',
            'file' => 'dh.display.inc',
          ),
        );
        $class = 'dHVariablePluginDefault';
      } else {
        $plugin_def = ctools_get_plugins('dh', 'dh_variables', $varinfo->plugin);
        $class = ctools_plugin_get_class($plugin_def, 'handler');
      }
      if (!empty($plugin_def)) {
        if (class_exists($class)) {
          $conf = array(
            'entity_type' => $this->base_entity_type,
          );
          $row_plugin = new $class($conf);
          switch ($mode) {
            case 'save':
              $row_plugin->formRowSave($rowform, $row);
            break;
            case 'build_form':
              $row_plugin->formRowEdit($rowform, $row);
            break;
            case 'render':
              $row_plugin->formRowRender($rowform, $row);
            break;
            case 'entity_defaults':
              $row_plugin->entityDefaults($row);
            break;
          }
        }
      } else {
        error_log("Failed: ctools_get_plugins('dh', 'dh_variables', $varinfo->plugin)");
      }
    }
  }
  
  public function formRowDefaults(&$rowform, $row) {
    // load a default from the entity's own form, or other if requested
  }
  
  public function fieldOptions(&$form, $form_state) {
    $form['entity_settings']['display']['fields'] = $this->fieldElements();
  }
  
  public function fieldElements() {
    $element = array(
      '#tree' => TRUE,
      '#prefix' => "<div id='update-field-options'>",
      '#suffix' => "</div>",
    );
    $form_fields_conf = $this->conf['display']['fields'];
    $fields = array();
    $fields_conf = array();
    foreach ($form_fields_conf as $thisconf) {
      $fields_conf[$thisconf['name']] = $thisconf;
    }
    $element[] = array(
      '#markup' => '<div class="view-content"><table class="views-table">',
    );
    $element[] = $this->fields_header();
    if (isset($this->base_entity_type) and isset($this->base_bundle)) {
      $fields = field_info_instances($this->base_entity_type, $this->base_bundle);
    }
    foreach ($fields as $fieldkey => $settings) {
      $field_conf = isset($fields_conf[$fieldkey]) ? $fields_conf[$fieldkey] : array(
        'name' => $fieldkey, 
        'description' => $settings['description'], 
        'default' => $settings['default_value'], 
        'title' => $settings['title'], 
        'hidden' => ($settings['display']['default']['type'] == 'hidden') ? 1 : 0,
      );
      $hidden = array(0 => t('FALSE'), 1 => t('TRUE'));
      $line = array(
        'name' =>  array(
          '#type' => 'textfield',
          '#disabled' => TRUE,
          '#value' => $field_conf['name'],
          '#size' => '12',
        ),
        'hidden' =>  array(
          '#type' => 'select',
          '#default_value' => isset($field_conf['hidden']) ? $field_conf['hidden'] : 0,
          '#options' => $hidden,
        ),
        'default' =>  array(
          '#default_value' => isset($field_conf['default']) ? $field_conf['default'] : NULL,
          '#type' => 'textfield',
          '#size' => '12',
        ),
        'title' =>  array(
          '#default_value' => isset($field_conf['title']) ? $field_conf['title'] : NULL,
          '#type' => 'textfield',
          '#size' => '12',
        ),
        'description' =>  array(
          '#type' => 'textfield',
          '#default_value' => isset($field_conf['description']) ? $field_conf['description'] : NULL,
          '#size' => '24',
        )
      );
      $this->tabularize($line);
      $element[$fieldkey] = $line;
    }
    $element[] = array(
      '#markup' => "</table></div>",
    );
    //drupal_set_message("element : <pre> " . print_r($element,1) . "</pre>");
    return $element;
  }
  
  public function propertyOptions(&$form, $form_state) {
    $form['entity_settings']['display']['properties'] = $this->propertyElements();
  }
  
  public function propertyElements() {
    $element = array(
      '#tree' => TRUE,
    );
    $form_prop_conf = isset($this->conf['display']['properties']) ? $this->conf['display']['properties'] : $this->property_conf_default;
    //dpm($form_prop_conf, "Props conf");
    $properties_conf = array();
    foreach ($form_prop_conf as $thisconf) {
      $properties_conf[$thisconf['name']] = $thisconf;
    }
    // add any mandated by class setting
    //dpm($this->property_conf_default, 'adding mandated');
    foreach ($this->property_conf_default as $thisconf) {
      //dpm($thisconf['name'], "adding");
      if (!isset($properties_conf[$thisconf['name']])) {
        $properties_conf[$thisconf['name']] = $thisconf;
      }
    }
    $element[] = array(
      '#markup' => '<div class="view-content"><table class="views-table">',
    );
    //dpm($properties_conf, "properties to add to entity_get_property_info");
    $element[] = $this->properties_header();
    if (isset($this->base_entity_type)) {
      //$properties = array_merge($properties_conf, entity_get_property_info($this->base_entity_type)['properties']);
      $properties = $properties_conf + entity_get_property_info($this->base_entity_type)['properties'];
    } else {
      drupal_set_message("No base entity type set");
    }
    //dpm($properties, "fnal properties to config");
    foreach ($properties as $propkey => $settings) {
      //drupal_set_message("Property conf: " . print_r($settings,1));
      $property_conf = isset($properties_conf[$propkey]) ? $properties_conf[$propkey] : array('name' => $propkey, 'description' => $settings['description']);
      $hidden = array(0 => t('FALSE'), 1 => t('TRUE'));
      if (!isset($property_conf['no_config'])) {
        $line = array(
          'name' =>  array(
            '#type' => 'textfield',
            '#disabled' => TRUE,
            '#value' => $property_conf['name'],
            '#value' => $property_conf['name'],
            '#size' => '12',
          ),
          'hidden' =>  array(
            '#type' => 'select',
            '#default_value' => isset($property_conf['hidden']) ? $property_conf['hidden'] : 0,
            '#options' => $hidden,
          ),
          'default' =>  array(
            '#default_value' => isset($property_conf['default']) ? $property_conf['default'] : NULL,
            '#type' => 'textfield',
            '#size' => '12',
          ),
          'title' =>  array(
            '#default_value' => isset($property_conf['title']) ? $property_conf['title'] : NULL,
            '#type' => 'textfield',
            '#size' => '12',
          ),
          'description' =>  array(
            '#type' => 'textfield',
            '#default_value' => isset($property_conf['description']) ? $property_conf['description'] : NULL,
            '#size' => '24',
          )
        );
        $this->tabularize($line);
        $element[$propkey] = $line;
      }
    }
    $element[] = array(
      '#markup' => "</table></div>",
    );
    //drupal_set_message("element : <pre> " . print_r($element,1) . "</pre>");
    return $element;
  }
  
  function fields_header() {
    // for now these have the same headers
    $this->properties_header();
  }
  function properties_header() {
    $line = array(
      'name' =>  array(
        '#markup' => "Name",
      ),
      'hidden' =>  array(
        '#markup' => "Hidden",
        '#description' => t('Controls visibility - invisible fields may still use tokens to change settings.'),
      ),
      'default' =>  array(
        '#markup' => "Default (token allowed)",
      ),
      'title' =>  array(
        '#markup' => "Title",
      ),
      'description' =>  array(
        '#markup' => "Description",
      )
    );
    $this->tabularize($line);
    return $line;
  }
  
  public function renderFormRow(&$form, &$form_state, &$line, &$row) {
    // default method to render a row simply creates a markup entry
    // we could later default to using whatever the default form element for this column is
    // form_id = entity_type + _form
    // sub-classes can choose to use the default form elements or to render their own here
  
    $rowform = array();
    // @todo: explicitly send form_state to plugins
    $row->form_state = $form_state; // stash a link here to allow queries by plugins
    $this->formRowDefaults($rowform, $row);
    $this->formRowPlugins($rowform, $row);
    $this->formRowVisibility($rowform, $row);
    //dpm($row, "This row");
    foreach ($this->form_columns as $colname) {
      //dpm($colname, "Colname");
      if (isset($rowform[$colname])) {
        //dpm($rowform[$colname], "adding $colname ");
        $line[$colname] = $rowform[$colname];
      }
    }
  }
  
  public function getGroupParents() {
    // support for nested props should go here, for now we just assume its handled
    if (!is_array($this->groupname)) {
      return array($this->groupname);
    }
    return $this->groupname;
  }
  
  public function buildForm(&$form, &$form_state) {
  // @todo -- deprecate pass by reference for form & form_state in future versions
  //   - Drupal 8 EntityForm = public function buildForm(array $form, FormStateInterface $form_state)
  // always return form
    $this->applyEntityTokens();
    $this->applySettings();
    // this stores settings in form state for later use.
    // we previously had it before applySettings(), but should not matter? Check if it breaks.
    $form_state['conf']['entity_settings'][$this->groupname] = $this->conf;
    $element = array(
      '#tree' => TRUE,
      '#type' => '#fieldset',
    );
    $table_classes = 'views-table sticky-enabled table table-hover table-striped tableheader-processed sticky-table';
    $ix_header = 0; // default to NOT add an offset to the first form_element_index
    switch($this->render_layout) {
      case 'unformatted':
      break;
      case 'unformatted_striped':
        $element[] = array(
          '#markup' => '<div class="view-content"><table class="' . $table_classes . '">',
        );
      break;
      case '2-column':
      case 'table':
      default:
        $ix_header = 1; // add an offset to the first form_element_index
        $element[] = array(
          '#markup' => '<div class="view-content"><table class="' . $table_classes . '">',
        );
      break;
    }
    if (strlen($this->conf['destination']) > 0) {
      $form_state['redirect'] = $this->conf['destination'];
    }
    $i = 1;
    $oe = 'odd';
    foreach ($this->data as $row) {
      $line = array();
      // Calculate the element index for generating unique identifiers related to the row
      end($element);
      $key = key($element) + 1;
      $ix = ($i == 1) ? $ix_header + $key : $key;
      $row->form_element_index = $ix;
      $row_parents = $this->getGroupParents(); // get base form loc in form_state['entities']
      array_push($row_parents, $key); // add matching key index to form_state['entities']
      $value_parents = $this->getGroupParents(); // get base form loc in form_state['entities']
      array_unshift($value_parents, 'values'); // prepend values
      array_push($value_parents, $key); // add matching key index to form_state['entities']
      if ($form_state['rebuild'] and $this->use_rebuild_code) {
        // try to retrieve values from the form to pass on to the plugins in case they do calculations
        $row_exists = FALSE;
        //error_log("Looking for value_parents:" . print_r($value_parents,1));
        $record_group = drupal_array_get_nested_value($form_state, $value_parents, $row_exists);
        if ($row_exists) {
          $this->applyFormStateEntityProperties($row, $record_group);
          //error_log("Setting entity from form_state:" . print_r($record_group,1));
        }
      }
      $this->renderFormRow($form, $form_state, $line, $row);
      if ( $this->use_rebuild_code) {
        $entity_parents = $row_parents;
        array_unshift($entity_parents, 'entities');
        drupal_array_set_nested_value($form_state, $entity_parents, $row); // stash the entity for later reference
      }
      $rowform['#entity_type'] = $this->base_entity_type;
      $rowform['#entity'] = $row;
      //dpm($rowform,'setting entity and entity type in form rowform');
      
      // **************************************************
      // add header if this is first
      // **************************************************
      switch($this->render_layout) {
        case 'unformatted_striped':
        break;
        case '2-column':
        case 'table':
        default:
          if ($i == 1) {
            $header = array();
            $this->formHeader($header, $row);
            $this->tabularize($header, 'header');
            $element[] = $header;
          }
        break;
      }
      // **************************************************
      //  Add content
      // **************************************************
      switch($this->render_layout) {
        case 'unformatted':
        break;
        case 'unformatted_striped':
          $line['#prefix'] = "<tr class='tablefield-row-0 $oe'><td>";
          $line['#suffix'] = "</td></tr>";
          $oe = ($oe == 'odd') ? 'even' : 'odd';
        break;
        case '2-column':
        case 'table':
        default:
          //dpm($line, "Final line");
          $oe = ($i&1) ? 'odd' : 'even';
          unset($line['#weight']);
          $this->tabularize($line, $oe);
        break;
      }
      $line['#entity'] = $rowform['#entity'];
      $line['#entity_type'] = $rowform['#entity_type'];
      $element[] = $line;
      $i++;
    }
    switch($this->render_layout) {
      case 'unformatted':
      break;
      case 'unformatted_striped':
        $element[] = array(
          '#markup' => "</table></div>",
        );
      break;
      case '2-column':
      case 'table':
      default:
        $element[] = array(
          '#markup' => "</table></div>",
        );
      break;
    }
    $form[$this->groupname] = $element;
    //dpm($form, 'form');
    return $form;
  }
  
  public function viewTable() {
    // this base class does nothing but show rows in this->data, all data pop will be done by sub-classes.
    $this->applyEntityTokens();
    $this->applySettings();
    $rows = array();
    $header = array();
    $this->renderHeader($header);
    // assemble header in the row loop
    $i = 1;
    foreach ($this->data as $row) {
      $line = array();
      $this->formRowPlugins($line, $row, 'render');
      $this->renderRow($line, $row);
      unset($line['#weight']);
      $rows[] = $line;
      $i++;
    }
    return theme('table', array('header' => $header, 'rows' => $rows));
  }
  
  public function addFormActions(&$form, $form_state) {
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#weight' => 20,
      '#limit_validation_errors' => array(),
      '#submit' => array('dh_grouped_entity_panel_form_cancel')
    );
    $save_label = $this->conf['save_label'];
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => strlen($save_label) ? $save_label : t('Save '),
      '#weight' => 30,
    );
    // add next button if configured
    $nextlabel = $this->conf['nextlabel'];
    $nextpage = $this->conf['nextpage'];
    if (strlen($nextpage) > 0) {
      $form['actions']['next'] = array(
        '#type' => 'submit',
        '#value' => strlen($nextlabel) ? $nextlabel : t('Next '),
        '#weight' => 40,
      );
    }
    switch ($op) {
      case 'add':
      break;
      case 'edit':
      $form['actions']['delete'] = array(
        '#type' => 'submit',
        '#value' => t('Delete type'),
        '#weight' => 45,
        '#limit_validation_errors' => array(),
        '#submit' => array('dh_grouped_entity_panel_form_delete')
      );
      break;
    }
  }
  
  function renderHeaderOld(&$header) {
    // @todo: check to see if the function below is a better implementation
    // header for table view (not edit)
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        $header[$colname] = $this->conf['display']['properties'][$colname]['title'];
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($header[$colname]);
        } 
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        $header[$colname] = $this->conf['display']['fields'][$colname]['title'];
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          unset($header[$colname]);
        }
      }
    }
  }
  
  function renderHeader(&$header) {
    // header for table view (not edit)
    //dpm($this->render_layout,'render_layout');
    switch($this->render_layout) {
      case 'unformatted':
      // do we need to handle a header for unformatted striped? or simply none?
      case 'unformatted_striped':
        $this->renderHeaderUnformatted($header);
      break;
      case 'table':
      default:
        $this->renderHeaderTable($header);
      break;
    }
  }
  
  function renderHeaderTable(&$header) {
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        $header[$colname] = $this->conf['display']['properties'][$colname]['title'];
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($header[$colname]);
        } 
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        $header[$colname] = $this->conf['display']['fields'][$colname]['title'];
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          unset($header[$colname]);
        }
      }
    }
  }
  
  function renderHeaderUnformatted(&$header) {
    $headerline = '';
    $elements = array();
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        $elements[$colname] = $this->conf['display']['properties'][$colname]['title'];
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($elements[$colname]);
        } 
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        $elements[$colname] = $this->conf['display']['fields'][$colname]['title'];
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          unset($elements[$colname]);
        }
      }
    }
    $header = array(implode($this->delimiter, $elements));
  }
  
  public function renderRow(&$line, &$row) {
    // default method to render a row simply creates a markup entry
    // we could later default to using whatever the default form element for this column is
    // form_id = entity_type + _form
    // sub-classes can choose to use the default form elements or to render their own here
    //dpm($this->form_columns,'form cols');
        
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        if (property_exists($row, $colname)) { 
          $line[$colname] = $row->$colname;
        }
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($line[$colname]);
        }
      }
      
      if (isset($this->conf['display']['fields'][$colname])) {
        // @todo need to add code to handle fields properly
        //   field_info_field to get language
        //   field_info_field to get value field
        if (property_exists($row, $colname)) { 
          foreach ($row->$colname as $lang => $vals) {
            foreach ($row->$colname[$lang] as $key => $val) {
              $line[$colname] .= $row->$colname[$lang][$key]['value'] . ' ';
            }
          }
          if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
            unset($line[$colname]);
          }
        }
      }
    }
  }
  
  function formHeader(&$header, $row) {
    // renders tabular form headers in same order as colnames
    foreach ($this->form_columns as $colname) {
      if (isset($this->conf['display']['properties'][$colname])) {
        $header[$colname] = array(
          '#markup' => $this->conf['display']['properties'][$colname]['title']
        );
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          $header[$colname]['#hidden'] = TRUE;
          unset($header[$colname]['#markup']);
          //dpm(1,"hiding $colname");
        }
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        $header[$colname] = array(
          '#markup' => $this->conf['display']['fields'][$colname]['title']
        );
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          $header[$colname]['#hidden'] = TRUE;
          unset($header[$colname]['#markup']);
        }
      }
    }
  }
  
  function tabularize(&$line, $oe = 'odd') {
    if ($oe == 'header') {
      $oe = 'even';
      $tr_pre = '<thead>';
      $tr_suf = '</thead>';
      $tag = 'th';
    } else {
      $tag = 'td';
      $tr_pre = '';
      $tr_suf = '';
    }
    // works only for a form entity
    $i = 0;
    foreach (array_keys($line) as $key) {
      if (is_array($line[$key])) {
        if (isset($line[$key]['#type']) and ($line[$key]['#type'] == 'hidden') ) {
          $style = 'style=\"display:none;\"';
        } else {
          $style = 'class="views-field"';
        }
        $line[$key]['#suffix'] = array_key_exists('#suffix', $line[$key]) ? $line[$key]['#suffix'] : '';
        $line[$key]['#prefix'] = array_key_exists('#prefix', $line[$key]) ? $line[$key]['#prefix'] : '';
        switch ($i) {
          case 0:
            if ($tr_pre == '<thead>') {
              $line[$key]['#prefix'] = "$tr_pre<tr><$tag $style>" . $line[$key]['#prefix'];
            } else {
              $line[$key]['#prefix'] = "$tr_pre<tr class='$oe'><$tag $style>" . $line[$key]['#prefix'];
            }
            //$line[$key]['#prefix'] = "$tr_pre<tr class='tablefield-row-0 $oe'><$tag $style>" . $line[$key]['#prefix'];
            $line[$key]['#suffix'] .= "</$tag>";
          break;
          case (count($line) - 1):
            $line[$key]['#prefix'] = "<$tag $style>" . $line[$key]['#prefix'];
            $line[$key]['#suffix'] .= "</$tag></tr>$tr_suf";
          break;
          default:
            $line[$key]['#prefix'] = "<$tag $style>" . $line[$key]['#prefix'];
            $line[$key]['#suffix'] .= "</$tag>";
          break;
        }
        $i++;
      }
    }
  }
}

function theme_dh_form_table_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  //dpm($attributes,'attributes');
  
  if (isset($attributes['class']) and is_array($attributes['class'])) {
    $attributes['class'][] = 'form-item';
  } else {
    $attributes['class'] = array('form-item');
  }
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

class dhTimeSeriesGroup extends EntityGroupConfigurator {
  var $groupname;
  var $varid;
  var $id;
  var $starttime;
  var $endtime;
  var $featureid;
  var $erefs;
  var $allprops = FALSE;  // should we add props in the form_values array if they don't exist on base class?
  var $base_entity_type = 'dh_timeseries'; // the type of entity that is storing ts data
  var $ts_entity_type; // the type of entity that is storing ts data
  var $limit = 25;
  var $entity_tokens = array('featureid', 'starttime', 'endtime', 'varid', 'dh_link_admin_timeseries', 'nextpage');
  var $row_tokens = array('tstext', 'tscode', 'tsvalue', 'tid', 'featureid', 'tstime', 'tsendtime', 'varname');
  
  public function __construct($conf) {
    parent::__construct($conf);
  }
  
  function applySettings() {
    $csv2array = array('featureid', 'entity_type', 'varid', 'dh_link_admin_timeseries');
    foreach ($this->entity_defaults as $key => $def) {
      $this->$key = isset($this->conf[$key]) ? $this->conf[$key] : $def;
      if (in_array($key, $csv2array)) {
        if (!is_array($this->$key)) {
          $this->$key = explode(',', $this->$key);
        }
      }
    }
    parent::applySettings();
  }
  
  public function entityDefaults() {
    parent::entityDefaults();
    $this->entity_defaults['groupname'] = 'ts_group';
    $this->entity_defaults['varid'] = array();
    $this->entity_defaults['id'] = array();
    $this->entity_defaults['starttime'] = FALSE;
    $this->entity_defaults['endtime'] = FALSE;
    $this->entity_defaults['ts_entity_type'] = 'dh_feature';
    $this->entity_defaults['featureid'] = array();
    $this->entity_defaults['dh_link_admin_timeseries'] = array();
    $this->entity_defaults['maxrecords'] = 25;
  }
  
  public function optionDefaults() {
    $this->property_conf_default = array(
      'tid' => array('name'=>'tid','hidden' => 1),
      'utcoffset' => array('name'=>'utcoffset','hidden' => 1, 'no_config' => TRUE),
      'entity_type' => array('name'=>'entity_type','hidden' => 1),
      'featureid' => array('name'=>'featureid','hidden' => 1),
      'timeline' => array('name'=>'timeline','hidden' => 1),
      'status' => array('name'=>'status','hidden' => 1, 'no_config' => TRUE),
      'module' => array('name'=>'module','hidden' => 1, 'no_config' => TRUE),
      'url' => array('name'=>'url','hidden' => 1, 'no_config' => TRUE),
      'feed_nid' => array('name'=>'feed_nid','hidden' => 1, 'no_config' => TRUE),
      'varname' => array('name'=>'varname','hidden' => 0),
      'varunits' => array('name'=>'varunits','hidden' => 0),
      'editlink' => array('name'=>'editlink','hidden' => 1),
      'addlink' => array('name'=>'addlink','hidden' => 1),
      'deletelink' => array('name'=>'deletelink','hidden' => 1),
    );
  }
  
  public function getFormId() {
    return 'timeseries_panel_form';
  }
  
  function getTSEntityInfo() {
    // get ts data parent entity type table name
    $ei = entity_get_info($this->ts_entity_type);
    if (!isset($ei['entity keys']['id']) or !isset($ei['base table'])) {
      // fail with malformed entity exception
      //dpm($ei,"Problem with entity info from entity_get_info($this->ts_entity_type)");
      return FALSE;
    }
    // insure only numeric
    return $ei;
  }
  
  function prepareQuery() {
    $this->query = FALSE;
    $this->applyEntityTokens();
    $this->applySettings();
    //parent::prepareQuery();
    // get ts data parent entity type table name
    $ei = $this->getTSEntityInfo();
    if (!isset($ei['entity keys']['id']) or !isset($ei['base table'])) {
      // fail with malformed entity exception
      //dpm($ei,"Problem with entity info from entity_get_info($this->ts_entity_type)");
      dsm("Problem with entity info from entity_get_info($this->ts_entity_type)");
      return FALSE;
    }
    $this->featureid = array_filter($this->featureid, 'is_numeric');
    $eidcol = $ei['entity keys']['id'];
    $ts_entity_table = $ei['base table'];
    // get varid
    // create a query that outer joins if insert ability is requested
    $q = "  select ent.$eidcol as featureid, ts.tid, ";
    $q .= " var.hydroid as varid, var.varname, ";
    $q .= " var.varkey, var.varunits ";
    $q .= " from {$ts_entity_table} as ent ";
    $q .= " left outer join {dh_variabledefinition} as var ";
    if (count($this->varid) > 0) {
      $varids = implode(", ", $this->varid);
      $q .= " on (var.hydroid in ($varids)) ";
    } else {
      // fail with malformed query exception - 
      dsm("malformed query - no varid specified");
      return FALSE;
    }
    $q .= " left outer join {dh_timeseries} as ts ";
    $q .= " on ( ";
    $q .= "   ts.featureid = ent.$eidcol ";
    $q .= "   AND var.hydroid = ts.varid ";
    $q .= "   AND ts.entity_type = '$this->ts_entity_type' ";
    $q .= " ) ";
    // we must have a match in the TS table
    $q .= " WHERE var.hydroid IS NOT NULL ";
    if (count($this->featureid) > 0) {
      $features = implode(", ", $this->featureid);
      $q .= " AND (ent.$eidcol in ($features)) ";
    }
    if (strlen($this->starttime) > 0) {
      $starttime = dh_handletimestamp($this->starttime);
      $q .= " AND (ts.tstime >= $starttime) ";
    }
    if (strlen($this->endtime) > 0) {
      $endtime = dh_handletimestamp($this->endtime);
      $q .= " AND (ts.tstime <= $endtime) ";
    }
    if (count($this->tstime) > 0) {
      $tstime = implode(", ", $this->tstime);
      $q .= " AND (ts.tstime in ($tstime)) ";
    }
    if (count($this->tsendtime) > 0) {
      $tsendtime = implode(", ", $this->tsendtime);
      $q .= " AND (ts.tsendtime in ($tsendtime)) ";
    }
//    if (count($this->dh_link_admin_timeseries) > 0) {
//      $dh_link_admin_timeseries = implode(", ", $this->dh_link_admin_timeseries);
//      $q .= " AND (ts.tid in (select dh_link_admin_timeseries_target_id from field_data_dh_link_admin_timeseries where entity_id in ($dh_link_admin_timeseries))) ";
//    }
    if (!$this->add) {
      $q .= " AND ts.featureid IS NOT NULL ";
    }
    $q .= " LIMIT $this->limit ";
    $this->query = $q;
    //dpm($q, "Query");
    //error_log( "Query:" . $q);
    return TRUE;
  }
  
  function getData() {
    if (!$this->query) {
      // malformed or non existent query
      return FALSE;
    }
    $this->data = array();
    $q = db_query($this->query);
    //dpm($q, "initial data");
    foreach ($q as $tsrow) {
      if ($tsrow->tid == NULL) {
        // this is an insert request
        //dpm((array)$tsrow, "Creating blank");
        $this->data[] = entity_create($this->base_entity_type, (array)$tsrow);
      } else {
        $this->data[] = array_shift(entity_load($this->base_entity_type, array($tsrow->tid)));
      }
    }
    //dpm($this->data, "Final data");
    // now, go through the returned data and if we have "show_blank" property set
    // we append new object form entries for these
    // create a matrix of entity_type, property_conditions & field_conditions?
    // a better approach would be to use a query that would return prefilled null records like an outer join
  }
  
  function buildOptionsForm(&$form, $form_state) {
    parent::buildOptionsForm($form, $form_state);
  }
  
  public function entityOptions(&$form, $form_state) {
    parent::entityOptions($form, $form_state);
    
    $form['entity_settings']['featureid'] = array(
      '#title' => t('Feature IDs'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['featureid']) > 0) ? $this->conf['featureid'] : NULL,
      '#description' => t('What entity id to retrieve TS values for.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $conditions = array();
    $options = dh_vardef_vocab_options(TRUE);
    $form['entity_settings']['vocabulary'] = array(
      '#title' => t('Vocabulary'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => (count($this->conf['vocabulary']) > 0) ? $this->conf['vocabulary'] : NULL,
      '#description' => t('What vocabulary to retrieve variables for - must save and re-open to update variable list.'),
      '#size' => 5,
      '#multiple' => TRUE,
      '#required' => FALSE,
    );
    $conditions = array();
    if (count($this->conf['vocabulary']) > 0) {
      $vocab_clause = "vocabulary in ( '" . implode("', '", $this->conf['vocabulary']) . "')";
      //dpm($vocab_clause, "Vocab Clause");
      $conditions = array($vocab_clause);
    }
    $options = dh_vardef_varselect_options($conditions);
    $form['entity_settings']['varid'] = array(
      '#title' => t('Variables'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => (count($this->conf['varid']) > 0) ? $this->conf['varid'] : NULL,
      '#description' => t('What varid to retrieve TS values for.'),
      '#size' => 12,
      '#multiple' => TRUE,
      '#required' => FALSE,
      '#prefix' => "<div id='update-varid-options'>",
      '#suffix' => '</div>',
    );
    $entities = entity_get_info();
    $form['entity_settings']['ts_entity_type'] = array(
      '#title' => t('Entity Type'),
      '#type' => 'select',
      '#options' => array_combine( array_keys($entities) , array_keys($entities) ),
      '#default_value' => isset($this->ts_entity_type) ? $this->ts_entity_type : 'dh_feature',
      '#description' => t('Entity Type'),
      '#required' => TRUE,
    );
    $form['entity_settings']['id'] = array(
      '#title' => t('TimeSeries IDs'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['id']) > 0) ? $this->conf['id'] : NULL,
      '#description' => t('What tid to retrieve TS values for.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['starttime'] = array(
      '#title' => t('Beginning of TimeSpan'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['starttime']) > 0) ? $this->conf['starttime'] : NULL,
      '#description' => t('Will select events whose tstime >= this value (unix timestamp of yyy-mm-dd).'),
      '#size' => 24,
      '#required' => FALSE,
    );  
    $form['entity_settings']['endtime'] = array(
      '#title' => t('End of TimeSpan'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['endtime']) > 0) ? $this->conf['endtime'] : NULL,
      '#description' => t('Will select events whose tstime <= this value (unix timestamp of yyy-mm-dd).'),
      '#size' => 24,
      '#required' => FALSE,
    );  
    $form['entity_settings']['dh_link_admin_timeseries'] = array(
      '#title' => t('TimeSeries Admin Submittal EREFs'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['dh_link_admin_timeseries']) > 0) ? $this->conf['dh_link_admin_timeseries'] : NULL,
      '#description' => t('What dh_link_admin_timeseries to retrieve TS values for.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
  }
  
  public function formRowDefaults(&$rowform, $row) {
    parent::formRowDefaults($rowform, $row);
    $pc = $this->conf['display']['properties'];
    //dpm($pc, "Prop conf");
    $fc = $this->conf['display']['fields'];
    $rowform['tid'] = array(
      '#type' => ($pc['tid']['hidden'] == 1) ? 'hidden' : 'textfield',
      '#default_value' => $row->tid,
   //   '#required' => TRUE,
      '#size' => 8,
      '#coltitle' => 'Event ID (tid)', 
    );
    $rowform['varname'] = array(
      '#coltitle' => 'Var Name',
      '#attributes' => array(
        'class' => array('editlink'),
      ),
      '#markup' => $row->varname,
    );

    $date_format = 'Y-m-d';
    $rowform['tstime'] = array(
      '#coltitle' => 'Event Time (tstime)', 
      '#default_value' => empty($row->tstime) ? $this->conf['display']['properties']['tstime']['default'] : date($date_format,$row->tstime),
      '#date_format' => $date_format,
      '#type' => 'date_select',
      '#date_year_range' => '-100:+5',
      '#required' => TRUE,
    );
    $rowform['tsendtime'] = array(
      '#coltitle' => 'Event End Time (tsendtime)', 
      '#default_value' => empty($row->tsendtime) ? $this->conf['display']['properties']['tsendtime']['default'] : date($date_format,$row->tsendtime),
      '#date_format' => $date_format,
      '#type' => 'date_select',
      '#date_year_range' => '-100:+5',
      '#required' => FALSE,
    );
    
    $rowform['tsvalue'] = array(
      '#coltitle' => 'Value (tsvalue)',
      '#type' => 'textfield',
      '#default_value' => empty($row->tsvalue) ? $this->conf['display']['properties']['tsvalue']['default'] : $row->tsvalue,
      '#required' => TRUE,
      '#size' => 8,
    );    
    $rowform['tscode'] = array(
      '#coltitle' => 'Code',
      '#type' => 'textfield',
      '#default_value' => empty($row->tscode) ? $this->conf['display']['properties']['tscode']['default'] : $row->tscode,
      '#required' => FALSE,
      '#size' => 16,
    );
    
    $rowform['featureid'] = array(
      '#type' => 'textfield',
      '#default_value' => empty($row->featureid) ? $this->conf['display']['properties']['featureid']['default'] : $row->featureid,
      '#required' => TRUE,
      '#size' => 8,
    ); 
    $rowform['entity_type'] = array(
      '#type' => 'textfield',
      '#default_value' => empty($row->entity_type) ? $this->conf['display']['properties']['entity_type']['default'] : $row->entity_type,
      '#required' => FALSE,
      '#size' => 32,
    );
    if ($row->varid > 0) {
      $conditions = array();
      $conditions[] = 'hydroid = ' . $row->varid;
      $options = dh_vardef_varselect_options($conditions);
    } else {
      $options = array();
    } 
    //dpm($options,"options");
    if (count($options) > 1) {
      $rowform['varid'] = array(
        '#coltitle' => 'Varid',
        '#type' => 'select',
        '#default_value' => empty($row->varid) ? $this->conf['display']['properties']['varid']['default'] : $row->varid,
        '#options' => $options,
        '#required' => TRUE,
      );
    } else {
      $label = array_shift($options);
      $rowform['varid'] = array(
        '#coltitle' => 'Varid',
        '#type' => 'hidden',
        '#attributes' => array('disabled' => 'disabled'),
        '#default_value' => empty($row->varid) ? $this->conf['display']['properties']['varid']['default'] : $row->varid,
        '#required' => TRUE,
      );
      if (!($this->conf['display']['properties']['varid']['hidden'] == 1)) {
        // add a text label in here if we are requesting to show (should use 
        // varname instead, but this adds flexibility
        $rowform['varid']['#prefix'] = $label;
      }
    }
    
    // need to spoof a form_state for the row to properly load attached fields
    
  }
  
  public function renderFormRow(&$form, &$form_state, &$line, &$row) {
    parent::renderFormRow($form, $form_state, $line, $row);
  }
  
  // when we go to D8 FormStateInterface will be relevant
  //public function buildOptionsForm(&$form, FormStateInterface $form_state) {
  // until then, we use the old school method
  public function buildForm(&$form, &$form_state) {
    //parent::buildForm($form, $form_state);
    //dpm($this->data, "calling parent::build_form");
    parent::buildForm($form, $form_state);
  }
  
  // when we go to D8 FormStateInterface will be relevant
  //public function validateForm(array &$form, FormStateInterface $form_state) {
  // until then, we use the old school method
  public function validateForm(array &$form, $form_state) {
    
  }

  /**
   * {@inheritdoc}
   */
  // when we go to D8 FormStateInterface will be relevant
  //public function submitForm(array &$form, FormStateInterface $form_state) {
  // until then, we use the old school method
  public function submitFormCustom(array &$form, $form_state) {
    // iterate through, do updates for those with PKID, inserts for those with NULL PKID
    foreach ($form_state['values'][$this->groupname] as $record_group) {
      if ($record_group[$this->entity_info['entity keys']['id']] > 0) {
        $e = entity_load_single($this->base_entity_type, $record_group[$this->entity_info['entity keys']['id']]);
      } else {
        // provide default bundle if not set 
        // TODO: this shouldn't ever happen and we should log exception
        $record_group['bundle'] = isset($record_group['bundle']) ? $record_group['bundle'] : $this->base_bundle;
        $e = entity_create($this->base_entity_type, $record_group);
        $e->entity_type = $this->ts_entity_type;
        $e->bundle = $this->base_bundle;
      }
      foreach ($record_group as $key => $val) {
        if (property_exists($e, $key) or $this->allprops) {
          $e->{$key} = $val;
        }
      }
      $e->save();
    }
  }
  
  public function listView() {
    // produces a renderable list
  }


  public function renderRow(&$line, &$row) {
    // over-rides parent form method
    //dpm($this->conf,'conf');
    foreach ($this->form_columns as $colname) {
      // handle special ones editlink, deletelink
      if ($row->tid) {
        switch ($colname) {
          case 'editlink':
            $edit_url = $this->applyRowTokens($this->conf['editurl'], $row);
            $edit_url = (strlen($edit_url) > 0) ? $edit_url : "admin/content/dh_timeseries/manage/$row->tid";
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $eparms = array(
              'attributes' => array(
                'class' => array('editlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if ($eparms['query']['destination'] == NULL) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", $edit_url, $eparms);
          break;
          
          case 'deletelink':
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $dparms = array(
              'attributes' => array(
                'class' => array('subtractlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if ($eparms['query']['destination'] == NULL) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", "admin/content/dh_timeseries/manage/$row->tid/delete", $dparms);
          break;
        }
      } else {
        // check to see if we offer an add link
        switch ($colname) {
          case 'editlink':
            $add_url = $this->applyRowTokens($this->conf['addurl'], $row);
            if (strlen($add_url) == 0) {
              // do not add featureid, varid stuff, but DO add destination
            }
            $add_url = (strlen($add_url) > 0) ? $add_url : "admin/content/dh_timeseries/add/$this->base_bundle";
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $eparms = array(
              'attributes' => array(
                'class' => array('addlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'edit[featureid]=' => $this->featureid,
                'edit[varid]=' => $row->varid,
                'edit[entity_type]=' => $this->ts_entity_type,
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if ($eparms['query']['destination'] == NULL) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", $add_url, $eparms);
          break;
          
          case 'deletelink':
            $line[$colname] = "";
          break;
        }
      }
      // now check visibility for all columns
      if (isset($this->conf['display']['properties'][$colname])) {
        if (property_exists($row, $colname)) { 
          $line[$colname] = $row->$colname;
        }
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($line[$colname]);
        }
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        // @todo need to add code to handle fields properly
        if (property_exists($row, $colname)) { 
          $line[$colname] = $row->$colname;
        }
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          unset($line[$colname]);
        }
      }
    }
  }
}

class dhPropertiesGroup extends EntityGroupConfigurator {
  var $groupname;
  var $varid;
  var $id;
  var $startdate;
  var $enddate;
  var $featureid;
  var $erefs;
  var $destination;
  var $addurl;
  var $editurl;
  var $base_entity_type = 'dh_properties';
  var $maxrecords = 25;
  var $entity_tokens = array('featureid', 'startdate', 'enddate', 'varid', 'destination', 'addurl', 'editurl', 'nextpage');
  var $row_tokens = array('propvalue', 'proptext', 'propcode', 'varid', 'pid', 'featureid', 'startdate', 'enddate', 'varname');
  
  public function __construct($conf) {
    parent::__construct($conf);
  }
  
  function applySettings() {
    // sub-classes parent method
    $csv2array = array('featureid', 'entity_type');
    foreach ($this->entity_defaults as $key => $def) {
      $this->$key = isset($this->conf[$key]) ? $this->conf[$key] : $def;
      if (in_array($key, $csv2array)) {
        if (!is_array($this->$key)) {
          $this->$key = explode(',', $this->$key);
        }
      }
    }
    parent::applySettings();
  }
  
  public function entityDefaults() {
    parent::entityDefaults();
    $this->entity_defaults['groupname'] = 'prop_group';
    $this->entity_defaults['varid'] = array();
    $this->entity_defaults['id'] = array();
    $this->entity_defaults['starttime'] = FALSE;
    $this->entity_defaults['endtime'] = FALSE;
    $this->entity_defaults['prop_entity_type'] = 'dh_feature';
    // @todo: I commented this out because it is over-writing settings.  Is this OK?
    $this->entity_defaults['base_bundle'] = 'dh_properties';
    $this->entity_defaults['featureid'] = array();
    $this->entity_defaults['erefs'] = array();
    $this->entity_defaults['maxrecords'] = 25;
  }
  
  public function optionDefaults() {
    // set up config form default options
    $this->property_conf_default = array(
      'pid' => array('name'=>'pid','hidden' => 1),
      'entity_type' => array('name'=>'entity_type','hidden' => 1),
      'featureid' => array('name'=>'featureid','hidden' => 1),
      'propname' => array('name'=>'propname','hidden' => 0),
      'status' => array('name'=>'status','hidden' => 1, 'no_config' => TRUE),
      'propcode' => array('name'=>'feed_nid','hidden' => 1),
      'varname' => array('name'=>'varname','hidden' => 0),
      'varid' => array('name'=>'varid', 'hidden' => 1),
      'varunits' => array('name'=>'varunits','hidden' => 0),
      'startdate' => array('name'=>'startdate','hidden' => 1),
      'enddate' => array('name'=>'enddate','hidden' => 1),
      'editlink' => array('name'=>'editlink','hidden' => 1),
      'addlink' => array('name'=>'addlink','hidden' => 1),
      'deletelink' => array('name'=>'deletelink','hidden' => 1),
    );
  }
  
  public function getFormId() {
    return 'properties_panel_form';
  }
  
  function getPropEntityInfo() {
    // get ts data parent entity type table name
    $ei = entity_get_info($this->prop_entity_type);
    if (!isset($ei['entity keys']['id']) or !isset($ei['base table'])) {
      // fail with malformed entity exception
      //dpm($ei,"Problem with entity info from entity_get_info($this->prop_entity_type)");
      return FALSE;
    }
    // insure only numeric
    return $ei;
  }
  
  function prepareQuery() {
    $this->applyEntityTokens();
    $this->applySettings();
    //parent::prepareQuery();
    $ei = $this->getPropEntityInfo();
    if (!$ei) {
      return FALSE;
    }
    $this->featureid = array_filter($this->featureid, 'is_numeric');
    $eidcol = $ei['entity keys']['id'];
    $prop_entity_table = $ei['base table'];
    // get varid
    // create a query that outer joins if insert ability is requested
    $q = "  select ent.$eidcol as featureid, var.hydroid as varid, ";
    $q .= " var.varname, var.varkey, ";
    $q .= " p.pid, var.varunits ";
    $q .= " from {$prop_entity_table} as ent ";
    $q .= " left outer join {dh_variabledefinition} as var ";
    if (count($this->varid) > 0) {
      $v1 = $this->varid[min(array_keys($this->varid))];
      if (intval($v1) > 0) {
        $varids = implode(", ", $this->varid);
        $q .= " on (var.hydroid in ($varids)) ";
      } else {
        $varids = implode("', '", $this->varid);
        $q .= " on (var.varkey in ('$varids')) ";
      }
    } else {
      // fail with malformed query exception - 
      drupal_set_message("malformed query - no varid specified");
      return FALSE;
    }
    $q .= " left outer join {dh_properties} as p ";
    $q .= " on ( ";
    $q .= "   p.featureid = ent.$eidcol ";
    $q .= "   AND var.hydroid = p.varid ";
    $q .= "   AND p.entity_type = '$this->prop_entity_type' ";
    $q .= " ) ";
    // we must have a match in the TS table
    $q .= " WHERE var.hydroid IS NOT NULL ";
    if (count($this->featureid) > 0) {
      $features = implode(", ", $this->featureid);
      $q .= " AND (ent.$eidcol in ($features)) ";
    }
    if (!$this->add) {
      $q .= " AND p.featureid IS NOT NULL ";
    }
    // @todo: make this selectable in the interface
    $q .= " ORDER BY var.vocabulary, var.varname ";
    $q .= " LIMIT $this->limit ";
    $this->query = $q;
    //dpm($q, "Query");
    return TRUE;
  }
  
  function getData() {
    if (!isset($this->query) or !$this->query) {
      // malformed or non existent query
      return FALSE;
    }
    $this->data = array();
    $q = db_query($this->query);
    //dpm($q, "initial data");
    foreach ($q as $prow) {
      if ($prow->pid == NULL) {
        // this is an insert request
        $prow->propname = $prow->varkey;
        $prow->entity_type = $this->prop_entity_type;
        //dpm($prow, "Creating blank");
        $blank = entity_create($this->base_entity_type, (array)$prow);
        //dpm($blank, "before applying defaults");
        $this->applyRowDataDefaults($blank);
        //dpm($blank, "after applying defaults");
        $this->data[] = $blank;
      } else {
        $proprez = entity_load($this->base_entity_type, array($prow->pid));
        $dh_properties = array_shift($proprez);
        // add variable info
        $dh_properties->varunits = $prow->varunits;
        $dh_properties->varname = $prow->varname;
        $dh_properties->varid = $prow->varid;
        $this->data[] = $dh_properties;
      }
    }
    //dpm($this->data, "Final data");
    // now, go through the returned data and if we have "show_blank" property set
    // we append new object form entries for these
    // create a matrix of entity_type, property_conditions & field_conditions?
    // a better approach would be to use a query that would return prefilled null records like an outer join
  }
  
  function buildOptionsForm(&$form, $form_state) {
    parent::buildOptionsForm($form, $form_state);
  }
  
  public function entityOptions(&$form, $form_state) {
    parent::entityOptions($form, $form_state);
    
    $form['entity_settings']['featureid'] = array(
      '#title' => t('Feature IDs'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['featureid']) > 0) ? $this->conf['featureid'] : NULL,
      '#description' => t('What entity id to retrieve TS values for.'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $conditions = array();
    $options = dh_vardef_vocab_options(TRUE);
    $form['entity_settings']['vocabulary'] = array(
      '#title' => t('Vocabulary'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => (count($this->conf['vocabulary']) > 0) ? $this->conf['vocabulary'] : NULL,
      '#description' => t('What vocabulary to retrieve variables for - must save and re-open to update variable list.'),
      '#size' => 5,
      '#multiple' => TRUE,
      '#required' => FALSE,
    );
    $conditions = array();
    if (count($this->conf['vocabulary']) > 0) {
      $vocab_clause = "vocabulary in ( '" . implode("', '", $this->conf['vocabulary']) . "')";
      //dpm($vocab_clause, "Vocab Clause");
      $conditions = array($vocab_clause);
    }
    $options = dh_vardef_varselect_options($conditions);
    $form['entity_settings']['varid'] = array(
      '#title' => t('Variables'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => (count($this->conf['varid']) > 0) ? $this->conf['varid'] : NULL,
      '#description' => t('What varid to retrieve TS values for.'),
      '#size' => 12,
      '#multiple' => TRUE,
      '#required' => FALSE,
      '#prefix' => "<div id='update-varid-options'>",
      '#suffix' => '</div>',
    );
    //error_log("Showing the entity selector");
    $entities = entity_get_info();
    $form['entity_settings']['prop_entity_type'] = array(
      '#title' => t('Entity Type'),
      '#type' => 'select',
      '#options' => array_combine( array_keys($entities) , array_keys($entities) ),
      '#default_value' => !empty($this->prop_entity_type) ? $this->prop_entity_type : 'dh_feature',
      '#description' => t('Entity Type'),
      '#required' => TRUE,
    );
    //error_log("Finished the entity selector" . print_r($form['entity_settings']['prop_entity_type'],1));
    $form['entity_settings']['id'] = array(
      '#title' => t('Properties IDs'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['id']) > 0) ? $this->conf['id'] : NULL,
      '#description' => t('What pid to retrieve Property values for.'),
      '#size' => 30,
      '#required' => FALSE,
    );
    $form['entity_settings']['addurl'] = array(
      '#title' => t('Add URL'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['addurl']) > 0) ? $this->conf['addurl'] : NULL,
      '#description' => t('URL For add screen (tokens allowed).'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['editurl'] = array(
      '#title' => t('Edit URL'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['editurl']) > 0) ? $this->conf['editurl'] : NULL,
      '#description' => t('URL For edit screen (tokens allowed).'),
      '#size' => 30,
      '#required' => FALSE,
    );  
  }
  
  public function formRowDefaults(&$rowform, $row) {
    parent::formRowDefaults($rowform, $row);
    $pc = $this->conf['display']['properties'];
    //dpm($pc, "Prop conf");
    $fc = $this->conf['display']['fields'];
    $rowform['pid'] = array(
      '#type' => ($pc['pid']['hidden'] == 1) ? 'hidden' : 'textfield',
      '#default_value' => $row->pid,
      '#coltitle' => 'pid',
   //   '#required' => TRUE,
      '#size' => 8,
      //'#theme' => 'dh_form_table_element',
    );
    $rowform['bundle'] = array(
      '#coltitle' => 'bundle',
      '#type' => 'hidden',
      '#default_value' => strlen($row->bundle) ? $row->bundle : $this->base_bundle,
      '#required' => TRUE,
      '#size' => 8,
    );
    $rowform['propname'] = array(
      '#coltitle' => 'Prop Name',
      '#type' => ($pc['propname']['hidden'] == 1) ? 'hidden' : 'textfield',
      '#default_value' => $row->propname,
   //   '#required' => TRUE,
      '#size' => 8,
    );
    $rowform['varname'] = array(
      '#coltitle' => 'Var Name',
      '#type' => 'item',
      '#disabled' => TRUE,
      '#title' => $row->varname,
      '#attributes' => array(
        'class' => array('control-label')
      ),
    );
    
    if ($row->varid > 0) {
      $conditions = array();
      $conditions[] = 'hydroid = ' . $row->varid;
      $options = dh_vardef_varselect_options($conditions);
    } else {
      $options = array();
    } 
    //dpm($options,"options");
    if (count($options) > 1) {
      $rowform['varid'] = array(
        '#coltitle' => 'Varid',
        '#type' => 'select',
        '#default_value' => empty($row->varid) ? $this->conf['display']['properties']['varid']['default'] : $row->varid,
        '#options' => $options,
        '#required' => TRUE,
      );
    } else {
      $label = array_shift($options);
      $rowform['varid'] = array(
        '#coltitle' => 'Varid',
        '#type' => 'hidden',
        '#attributes' => array('disabled' => 'disabled'),
        '#default_value' => empty($row->varid) ? $this->conf['display']['properties']['varid']['default'] : $row->varid,
        '#required' => TRUE,
      );
      if (!($this->conf['display']['properties']['varid']['hidden'] == 1)) {
        // add a text label in here if we are requesting to show (should use 
        // varname instead, but this adds flexibility
        $rowform['varid']['#prefix'] = $label;
      }
    }
    //dpm($this->conf['display']['properties']['varid']);

    $date_format = 'Y-m-d';
    $rowform['startdate'] = array(
      '#coltitle' => 'Start Date',
      '#default_value' => empty($row->startdate) ? $this->conf['display']['properties']['startdate']['default'] : date($date_format,$row->startdate),
      '#date_format' => $date_format,
      '#type' => 'date_select',
      '#date_year_range' => '-100:+5',
      '#required' => FALSE,
      //'#theme' => 'dh_form_table_element',
    );
    $rowform['enddate'] = array(
      '#coltitle' => 'End Date',
      '#default_value' => empty($row->enddate) ? $this->conf['display']['properties']['enddate']['default'] : date($date_format,$row->enddate),
      '#date_format' => $date_format,
      '#type' => 'date_select',
      '#date_year_range' => '-100:+5',
      '#required' => FALSE,
      //'#theme' => 'dh_form_table_element',
    );
    
    $rowform['propvalue'] = array(
      '#coltitle' => 'Value',
      '#type' => 'textfield',
      '#default_value' => !strlen($row->propvalue) ? $this->conf['display']['properties']['propvalue']['default'] : $row->propvalue,
      '#required' => FALSE,
      '#element_validate' => array('element_validate_number'),
      '#size' => 8,
      //'#theme' => 'dh_form_table_element',
    );
    
    $rowform['varunits'] = array(
      '#coltitle' => 'Units',
      '#markup' => empty($row->varunits) ? 'undef' : $row->varunits,
    );
    
    $rowform['propcode'] = array(
      '#coltitle' => 'Code',
      '#type' => 'textfield',
      '#default_value' => empty($row->propcode) ? $this->conf['display']['properties']['propcode']['default'] : $row->propcode,
      '#required' => FALSE,
      '#size' => 16,
    );
    
    $rowform['featureid'] = array(
      '#coltitle' => 'Feature ID',
      '#type' => 'textfield',
      '#default_value' => empty($row->featureid) ? $this->conf['display']['properties']['featureid']['default'] : $row->featureid,
      '#required' => TRUE,
      '#size' => 8,
      //'#theme' => 'dh_form_table_element',
    ); 
    $rowform['entity_type'] = array(
      '#coltitle' => 'Entity Type',
      '#type' => 'textfield',
      '#default_value' => empty($row->entity_type) ? $this->conf['display']['properties']['entity_type']['default'] : $row->entity_type,
      '#required' => FALSE,
      '#size' => 32,
      //'#theme' => 'dh_form_table_element',
    );
    $rowform['uid'] = array(
      '#type' => 'hidden' ,
      '#markup' => $row->uid,
      '#coltitle' => 'pid',
   //   '#required' => TRUE,
      '#size' => 8,
      //'#theme' => 'dh_form_table_element',
    );
    
    /*
    // the delete link should probably be a check box rather than these which 
    // are copeied from the delete link in the list view
    $dparms = array(
      'class' => array('deletelink'),
      'destination' => (strlen($this->conf['destination']) > 0) ? $this->conf['destination'] : NULL,
    );
    $rowform['deletelink'] = array(
      '#markup' => l("&nbsp;", "admin/content/properties/manage/$row->pid/delete" . $dobj->format('Y-m-d'), $dparms),
      //'#theme' => 'dh_form_table_element',
    );
    */
    
    // need to spoof a form_state for the row to properly load attached fields
    
  }
  
  public function renderFormRow(&$form, &$form_state, &$line, &$row) {
    parent::renderFormRow($form, $form_state, $line, $row);
  }
  
  // when we go to D8 FormStateInterface will be relevant
  //public function buildOptionsForm(&$form, FormStateInterface $form_state) {
  // until then, we use the old school method
  public function buildForm(&$form, &$form_state) {
    //parent::buildForm($form, $form_state);
    //dpm($this->data, "calling parent::build_form");
    parent::buildForm($form, $form_state);
  }
  
  // when we go to D8 FormStateInterface will be relevant
  //public function validateForm(array &$form, FormStateInterface $form_state) {
  // until then, we use the old school method
  public function validateForm(array &$form, $form_state) {
    parent::validateForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  // when we go to D8 FormStateInterface will be relevant
  //public function submitForm(array &$form, FormStateInterface $form_state) {
  // until then, we use the old school method  public function submitFormCustom(array &$form, $form_state) {
    // iterate through, do updates for those with PKID, inserts for those with NULL PKID
  public function submitFormCustom(array &$form, $form_state) {
    //dpm($form_state,"SubmitForm");
    // identify records that this is supposed to handle
      // main form field name $this->groupname, i.e. ts_group
    // iterate through, do updates for those with PKID, inserts for those with NULL PKID
    foreach ($form_state['values'][$this->groupname] as $record_group) {
      if ($record_group[$this->entity_info['entity keys']['id']] > 0) {
        $e = entity_load_single($this->base_entity_type, $record_group[$this->entity_info['entity keys']['id']]);
        $pinfo = entity_get_property_info('dh_properties');
      } else {
        //dpm(1,"Entity created - need to save");
        $record_group['bundle'] = !empty($record_group['bundle']) ? $record_group['bundle'] : $this->base_bundle;
        $record_group['groupname'] = $this->groupname; // pass this in for special hook handling
        $e = entity_create($this->base_entity_type, $record_group);
        $e->entity_type = $this->prop_entity_type;
        $e->bundle = $this->base_bundle;
      }
      // save the entity
      // entity API, but does not work? Tried two options
      //$wrapper = entity_metadata_wrapper('dh_properties', $e, array('property info' => $pinfo['properties']));
      //$wrapper = entity_metadata_wrapper('dh_properties', $e);
      // need to upgrade to Entity API 7.x-1.6 for this
      // $wrapper = $e->wrapper();
      foreach ($record_group as $key => $val) {
        // entity API, but does not work?
        //if (property_exists($wrapper, $key)) {
          // entity API, but does not work?
          //$wrapper->{$key}->set($val);
        //} else {
        //dpm($wrapper, "Missing key $key");
        //}
        if (property_exists($e, $key)) {
          $e->{$key} = $val;
        }
      }
      $e->save();
    }
  }
  
  public function listView() {
    // produces a renderable list
  }

  public function addLink($row) {
    $link = '';
    if ($row->varid) {
      //
      $row->addlabel = property_exists($row, 'addlabel') ? $row->addlabel : '';
      $add_url = $this->applyRowTokens($this->conf['addurl'], $row);
      if (strlen($add_url) == 0) {
        // do not add featureid, varid stuff, but DO add destination
      }
      $row->bundle = $row->bundle ? $row->bundle : $this->base_bundle;
      $add_url = (strlen($add_url) > 0) ? $add_url : "admin/content/dh_properties/add/$row->bundle";
      $destination = $this->applyRowTokens($this->conf['destination'], $row);
      $eparms = array(
        'attributes' => array(
          'class' => array('addlink'),
        ),
        'html' => TRUE,
        'query' => array(
          'edit[featureid]=' => $row->featureid,
          'edit[varid]=' => $row->varid,
          'edit[propname]=' => $row->propname,
          'edit[entity_type]=' => $this->prop_entity_type,
          'destination' => (strlen($destination) > 0) ? $destination : NULL,
        ),
      );
      if ($eparms['query']['destination'] == NULL) {
        unset($eparms['query']['destination']);
      }
      $link = l("&nbsp;" . $row->addlabel, $add_url, $eparms);
    }
    return $link;
  }
  
  public function renderRow(&$line, &$row) {
    // over-rides parent method
    foreach ($this->form_columns as $colname) {
      // default to show, then see if it should be hidden
      $line[$colname] = "&nbsp;";
      // handle special ones editlink, deletelink
      if ($row->pid) {
        switch ($colname) {
          case 'startdate':
          case 'enddate':
            $row->$colname = empty($row->$colname) ? $row->$colname : date('Y-m-d', $row->$colname);
          break;
          
          case 'editlink':
            $edit_url = $this->applyRowTokens($this->conf['editurl'], $row);
            $edit_url = (strlen($edit_url) > 0) ? $edit_url : "admin/content/dh_properties/manage/$row->pid";
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $eparms = array(
              'attributes' => array(
                'class' => array('editlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if ($eparms['query']['destination'] == NULL) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", $edit_url, $eparms);
          break;
          
          case 'deletelink':
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $dparms = array(
              'attributes' => array(
                'class' => array('subtractlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if (isset($eparms['query']['destination']) and ($eparms['query']['destination'] == NULL)) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", "admin/content/dh_properties/manage/$row->pid/delete", $dparms);
          break;
        }
      } else {
        // check to see if we offer an add link
        switch ($colname) {
          case 'editlink':
            $this->formRowPlugins($line, $row, 'entity_defaults');
            $row->bundle = $row->bundle ? $row->bundle : $this->base_bundle;
            $add_url = $this->applyRowTokens($this->conf['addurl'], $row);
            if (strlen($add_url) == 0) {
              // do not add featureid, varid stuff, but DO add destination
            }
            $add_url = (strlen($add_url) > 0) ? $add_url : "admin/content/dh_properties/add/$row->bundle";
            $destination = $this->applyRowTokens($this->conf['destination'], $row);
            $eparms = array(
              'attributes' => array(
                'class' => array('addlink'),
              ),
              'html' => TRUE,
              'query' => array(
                'edit[featureid]=' => $row->featureid,
                'featureid' => $row->featureid,
                'edit[varid]=' => $row->varid,
                'varid' => $row->varid,
                'edit[propname]=' => $row->propname,
                'edit[entity_type]=' => $this->prop_entity_type,
                'entity_type' => $this->prop_entity_type,
                'destination' => (strlen($destination) > 0) ? $destination : NULL,
              ),
            );
            if ($eparms['query']['destination'] == NULL) {
              unset($eparms['query']['destination']);
            }
            $line[$colname] = l("&nbsp;", $add_url, $eparms);
          break;
          
          case 'deletelink':
            $line[$colname] = "";
          break;
        }
      }
      // now check visibility for all columns
      if (isset($this->conf['display']['properties'][$colname])) {
        if (property_exists($row, $colname)) { 
          $line[$colname] = $row->$colname;
        }
        if (($this->conf['display']['properties'][$colname]['hidden'] == 1)) {
          unset($line[$colname]);
        }
      }
      if (isset($this->conf['display']['fields'][$colname])) {
        // @todo need to add code to handle fields properly
        if (property_exists($row, $colname)) { 
          foreach ($row->$colname as $lang => $vals) {
            foreach ($vals as $key => $val) {
              $line[$colname] .= $val['value'] . " ";
            }
          }
        }
        if (($this->conf['display']['fields'][$colname]['hidden'] == 1)) {
          unset($line[$colname]);
        }
      }
    }
  }
}


class dhPropertiesSingle extends dhPropertiesGroup {
  var $entity_tokens = array('featureid', 'startdate', 'enddate', 'varid', 'destination', 'addurl', 'editurl', 'id', 'pid', 'nextpage');
  var $row_tokens = array('propvalue', 'proptext', 'propcode', 'varid', 'pid', 'featureid', 'startdate', 'enddate', 'varname', 'vardesc');
  
  public function getFormId() {
    return 'properties_single_panel_form';
  }
  public function prepareQuery() {
    // this is where we should check to see that the form allows the varid requested
    // set watchdog if not allowed
    //dpm($this,'dhPropertiesSingle');
    parent::prepareQuery();
    //return TRUE;
  }
  public function getData() {
    // load the entity or create new
    // drupal_set_message and set watchdog if not able to load
    $this->limit = 1;
    parent::getData();
    //return TRUE;
  }
  public function viewTable() {
    // nothing to do here since we are using all the normal form plumbing
    return '';
  }
  function buildOptionsForm(&$form, $form_state) {
    parent::buildOptionsForm($form, $form_state);
  }
  
  public function entityOptions(&$form, $form_state) {
    parent::entityOptions($form, $form_state);
    unset($form['entity_settings']['addurl']);
    unset($form['entity_settings']['editurl']);
    //$form['entity_settings']['display_type']['#type'] = 'hidden';
    //$form['entity_settings']['display_type']['#default_value'] = 'form';
    $form['entity_settings']['varid']['#title']= t('Restrict Access to Variables');
    $form['entity_settings']['varid']['#description'] = t('Restrict Access to add/retrieve TS values for.  Show warning if mis-matched variable is requested.');
    $form['entity_settings']['adddest'] = array(
      '#title' => t('Save after Add Destination URL'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['adddest']) > 0) ? $this->conf['adddest'] : NULL,
      '#description' => t('Destination URL For Save after Add (tokens allowed).'),
      '#size' => 30,
      '#required' => FALSE,
    );  
    $form['entity_settings']['editdest'] = array(
      '#title' => t('Save after Edit Destination URL'),
      '#type' => 'textfield',
      '#default_value' => (strlen($this->conf['editdest']) > 0) ? $this->conf['editdest'] : NULL,
      '#description' => t('Destination URL For Save after Edit (tokens allowed).'),
      '#size' => 30,
      '#required' => FALSE,
    );  
  }
  public function buildForm(&$form, &$form_state) {
    // check variables requested since form settings allow restricting to specific vars
    // check action requested
    // do token substitution
    $this->applyEntityTokens();
    //dpm($this,'post token');
    $this->applySettings();
    //dpm($this,'post settings');
    if ($this->id == 'add') {
      $op = 'add';
      $this->id = 0;
    }
    //dpm($form_state,'form_state');
    //dpm($this,'this');
    //dpm($this->conf,'conf');
    // load or create a property for this form
    $prop = NULL;
    if (intval($this->id) > 0) {
      $prop = entity_load_single('dh_properties', $this->id);
      if ($prop) {
        $op = 'edit';
      }
    }
    $varid = array_shift($this->varid);
    $fid = array_shift($this->featureid);
    $prop = is_object($prop) ? $prop : entity_create('dh_properties', array('bundle' => $this->base_bundle, 'featureid' => $fid, 'varid' => $varid, 'entity_type'=>$this->prop_entity_type));
    // just grab the regular form now
    // but load into conf property
    $form_state['conf'] = $this->conf;
    //dpm($prop,'prop');
    $elements = entity_ui_get_form('dh_properties', $prop, $op, $form_state);
    // call to applyFieldOverrides will be removed later,
    // since we have added the "conf" to the form_state,
    // our base form handlers in dh.admin.inc Can apply any local over-rides
    // we just have to aler the code
    //dpm($elements,'before applyFieldOverrides');
    $this->applyFieldOverrides($elements, $prop);
    $form = drupal_render($elements);
    //dpm($form,'after applyFieldOverrides');
  }
  public function applyFieldOverrides(&$elements, $prop) {
    //dpm($elements, "Elements to check for over-ride");
    foreach ($this->conf['display']['properties'] as $propname => $settings) {
      if (isset($elements[$propname])) {
        $elements[$propname]['#title'] = (strlen($this->conf['display']['properties'][$propname]['title']) > 0) ? $this->applyRowTokens($this->conf['display']['properties'][$propname]['title'], $prop) : $elements[$propname]['#title'];
        $elements[$propname]['#description'] = (strlen($this->conf['display']['properties'][$propname]['description']) > 0) ? $this->applyRowTokens($this->conf['display']['properties'][$propname]['description'], $prop) : $elements[$propname]['#description'];
        if ($this->conf['display']['properties'][$propname]['hidden']) {
          $elements[$propname]['#type'] = 'hidden';
          $elements[$propname]['#theme'] = 'hidden';
        }
      }
    }
    foreach ($this->conf['display']['fields'] as $fieldname => $settings) {
      if (isset($elements[$fieldname])) {
        $elements[$fieldname]['und'][0]['#title'] = (strlen($this->conf['display']['fields'][$fieldname]['title']) > 0) ? $this->applyRowTokens($this->conf['display']['fields'][$fieldname]['title'], $prop) : $elements[$fieldname]['#title'];
        $elements[$fieldname]['und'][0]['#description'] = (strlen($this->conf['display']['fields'][$fieldname]['description']) > 0) ? $this->applyRowTokens($this->conf['display']['fields'][$fieldname]['description'], $prop) : $elements[$fieldname]['#description'];
        if ($this->conf['display']['fields'][$fieldname]['hidden']) {
          $elements[$fieldname]['#type'] = 'hidden';
          $elements[$fieldname]['#theme'] = 'hidden';
        }
        //dpm($elements[$fieldname],"final setting for $fieldname");
      }
    }
    
  }
  public function addFormActions(&$form, $form_state) {
    // nothing to do here since we are using all the normal form plumbing
  }
  public function validateForm(array &$form, $form_state) {
    // nothing to do here since we are using all the normal form plumbing
  }
  public function submitForm(array &$form, $form_state) {
    // since we are loading the standard form in BuildForm above
    // this is not needed since the normal form handles saving.
    $this->applyEntityTokens();
    $this->applySettings();
  }
  
  public function viewBlock() {
    // this base class does nothing but show block in this->data, all data pop will be done by sub-classes.
    $this->applyEntityTokens();
    $this->applySettings();
    $prop = NULL;
    $rows = array();
    if (!(count($this->data) > 0)) {
      return '';
    }
    $out = '';
    foreach ( $this->data as $prop) {
      if ($prop->pid > 0) {
        $header = array('title' => 'Name', 'value' => '');
        // assemble header in the row loop
        $i = 1;
        foreach ($this->conf['display']['properties'] as $propname => $settings) {
          if (property_exists($prop,$propname ) and !$this->conf['display']['properties'][$propname]['hidden']) {
            $rows[$propname]['title'] = $this->applyRowTokens($this->conf['display']['properties'][$propname]['title'], $prop);
            $rows[$propname]['value'] = $prop->$propname;
            // should put a popup span enclosing this
            //$popup = $this->conf['display']['properties'][$propname]['description'];
          }
        }
        foreach ($this->conf['display']['fields'] as $fieldname => $settings) {
          if (property_exists($prop,$fieldname )) {
            $fields[$fieldname] = $this->applyRowTokens($this->conf['display']['fields'][$fieldname]['title'], $prop);
            // now add the fully rendered field
            // @todo - replace the title of this field
            $fields[$fieldname] .= drupal_render(field_view_field('dh_properties', $prop, $fieldname));
            // should put a popup span enclosing this
            //$popup = $this->conf['display']['fields'][$fieldname]['description'];
          }
        }
        if (count($rows) > 0) {
          $out .= theme('table', array('header' => $header, 'rows' => $rows));
        }
        if (count($fields) > 0) {
          $out .= implode("\n<br>", $fields);
        }
        // see if we offer an edit link
      } else {
        // no property found, see if we offer an add link
        //dpm($prop,'blank value');
        $prop->addlabel = $prop->varname;
        $out .= $this->addLink($prop);
      }
    }
    return $out;
  }
}

// Entity Reference selector based on View
// standard eref form widget gives variable format: dh_link_admin_reg_issuer[und][###][target_id] - where ### = 0,1,2 ... depending on number of items
  // what naming convention to use?
// user supplies:
  // view / view-display (like in emapping widget)
  // entity_type - type of referencing entity
  // bundle - bundle of referencing entity
  // entity_id - id of Referencing entity
  // entity reference field - field residing on referencing entity
  // target_id_col - select list of potential referenced entities based on view columns
  // selected_id_col - column containing indication of selection status (0 or null indicates not selected anything else indicates selected)
  // (maybe) Put Selected At Top (T/F): this COULD/SHOULD be controlled by the Views own sorting
// use case: could be a standalone form, or could call buildForm without addFormActions to use as embedded in larger form, such as a dH model widget.

class entityreference_checklist_select {
  var $size;
  var $target_type;
  var $multiple;
  
  public function __construct($conf) {
    foreach ($conf as $key => $val) {
      if (property_exists($this, $key)) {
        $this->{$key} = $val;
      }
    }
  }
  
  public function settingsForm(){
    
  }
  
  public function getFieldSetting($setting_key) {
    return property_exists($this, $setting_key) ? $this->{$setting_key} : FALSE;
  }
  
  public function formElement($items, $delta, array $element, array &$form, $form_state) {
    //dpm($items,"Items");
    if ($this->promote_selected) {
      $options = array();
      foreach ($items as $thisitem) {
        
      }
    } else {
      $options = $items;
    }
    $element += array(
      '#type' => 'select',
      '#target_type' => $this->getFieldSetting('target_type'),
      '#maxlength' => 1024,
      '#multiple' => $this->getFieldSetting('multiple'),
      '#options' => $items,
      '#default_value' => NULL,
      '#size' => $this->getSetting('size'),
    );

    return array('target_id' => $element);
  }
}

class dHVariablePluginDefault {
  // @todo:
  var $entity_type;
  var $variable_label;
  var $value_label;
  var $start_label;
  var $end_label;
  var $code_label;
  var $row_map;
  var $idf;
  var $textf;
  var $valuef;
  var $codef;
  var $default_bundle = FALSE;
  
  public function __construct($conf = array()) {
    $this->conf = $conf;
    $this->optionDefaults($conf);
  }
  
  public function create(&$entity) {
    // set up defaults?
    if ($this->default_bundle) {
      $entity->bundle = $this->default_bundle;
    }
  }
  
  public function setUp(&$entity) {
    // setup tasks go here any time an entity is loaded
  }
  
  public function getParentEntity($entity) {
    if (property_exists($entity, 'entity_type') and property_exists($entity, 'featureid') and !empty($entity->entity_type) and !empty($entity->featureid)) {
      return entity_load_single($entity->entity_type, $entity->featureid);
    } else {
      watchdog('dh', "dHVariablePluginDefault called without properly formatted entity");
    }
  }
  
  public function optionDefaults($conf = FALSE) {
    if (!($this->conf['entity_type'])) {
      return FALSE;
    }
    switch ($this->conf['entity_type']) {
      case 'dh_timeseries':
      $this->row_map = array(
        'id' => 'tid',
        'varid' => 'varid',
        'value' => 'tsvalue',
        'text' => 'tstext',
        'code' => 'tscode',
        'start' => 'tstime',
        'end' => 'tsendtime',
        'featureid' => 'featureid',
        'entity_type' => 'entity_type',
      );
      break;
      case 'dh_properties':
      $this->row_map = array(
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
    $this->idf = $this->row_map['text'];
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
  
  public function hiddenFields() {
    return array();
  }
  
  public function hideFormRowEditFields(&$rowform) {
    foreach ($this->hiddenFields() as $hide_this) {
      $rowform[$hide_this]['#type'] = 'hidden';
    }
  }
  public function handleFormPropname($pn) {
    // @todo: move to base class
    return str_replace(" ","_",$pn);
  }
  
  public function applyEntityAttribute(&$prop, $value) {
    if (is_numeric($value)) {
      $prop->propvalue = $value;
    } else {
      if (gettype($value) == 'string') {
        $prop->propcode = $value;
      } else {
        watchdog('dh', 'dH Properties propcode cannot handle type ' . gettype($value) . ' in handle_form_prop_objects');
      }
    }
  }
  
  public function entityDefaults(&$entity) {
    // set any default for entity creation here such as bundle
    if ($this->default_bundle) {
      $entity->bundle = $this->default_bundle;
    }
  }
  
  public function formRowDefaults(&$rowform, $row) {
    $this->formRowEdit($rowform, $row);
  }
  
  public function formRowEdit(&$rowform, $row) {
    // do nothing - subclasses control form elements with this function
    $this->hideFormRowEditFields($rowform);
  }
  
  public function formRowSave(&$rowvalues, &$row) {
    // special form save handlers
  }
  
  public function formRowValidate(&$rowvalues, &$row) {
    // special form validation handlers
    // @todo: this is not called by the form entities yet so it does nothing.
  }
  
  public function save(&$entity) {
    // special save handlers - this may be called with a null tid/pid since if entity is new
    //   use update or insert if a tid/pid is required (for adding atributes for example)
  }
  
  public function delete(&$entity) {
    // special delete handlers - this may be called with a null tid/pid since if entity is new
    //   use update or insert if a tid/pid is required (for adding atributes for example)
  }
  
  // *******************************************************************************
  // update() and insert() are called after the TS or prop entity is saved, which allows 
  // us to do things that require a final, saved object, such as insure we have a tid/pid
  // @todo: we need to make some rules to prevent infinite recursion wherein:
  //   - some prop/ts of type "A" trigger the creation of prop/ts "B" 
  //   - prop/ts "B" triggers the creation of a prop/ts of type "A"
  // To prevent this we can:
  //   - not allow ts to trigger creation of ts attached to it 
  //   - not allow props whose entity_type is ts to trigger creation of a ts attached to it
  //   - not allow props whose entity_type is prop to trigger creation of a ts attached to it
  //     - this will effectively limit props to having one layer of children created automatically by plugins
  //   - set some global drupal session variable to track # of times plugins iterate 
  //     and return after some max
  //     This could be a variable set on the controller class?
  //   - check $entity->from_cache which tells us if it was loaded de novo or from cache 
  //     if from_cache, may be a recursion
  public function update(&$entity) {
    // special update handlers - these are called any time an update is made
    $this->updateLinked($entity);
  }
  
  public function insert(&$entity) {
    // special insert handlers - only called when object is first created
    $this->updateLinked($entity);
  }
  
  public function formRowRender(&$rowvalues, &$row) {
    // special render handlers when displaying in a grouped property block
  }
  
  public function buildContent(&$content, &$entity, $view_mode) {
    // @todo: handle teaser mode and full mode with plugin support
    foreach ($this->hiddenFields() as $hide) {
      unset($content[$hide]);
    }
    $modate = date("Y-m-d h:m a", dh_handletimestamp($entity->modified) );
    switch ($view_mode) {
      case 'plugin':
      case 'teaser':
      default:
        $content['propname'] = array(
          '#type' => 'item',
          '#markup' => "<b>Name:</b> $entity->propname<sub>($entity->varname)</sub> <br>(mod: $modate)"
        );
        if (isset($content['propvalue'])) {
          $content['propvalue'] = array(
            '#type' => 'item',
            '#markup' => "<b>Value:</b> " . $entity->propvalue,
          ); 
        }
        if (isset($content['propcode'])) {
          $content['propcode'] = array(
            '#type' => 'item',
            '#markup' => "<b>Code:</b> " . $entity->propcode,
          ); 
        }
      break;
      
      case 'openmi_json':
        $exp = $this->exportOpenMI($entity);
        $content = array();
        $content['entities'] = array(
          '#type' => 'item',
          '#markup' => json_encode($exp, JSON_PRETTY_PRINT)
        );
        
        //$content[] = json_encode($exp, JSON_PRETTY_PRINT);
      break;
    }
  }
  
  public function propertyOptions(&$rowform, $rowform_state) {
    // this sets up properties that are to be controlled in the form
  }  
  
  public function buildOptionsForm(&$rowform, $rowform_state) {
    // Form for configuration when editing in variable defintion interface
    // called from dh_variabledefinition_form()
  }
  
  // 
  public function dh_getValue($entity, $ts = FALSE, $propname = FALSE, $config = array()) {
    // @todo: implement om routines
    // called by the entity's own om_getValue routines
    // entity checks for plugins, if they exists, it runs the plugins om_getValue routine, if not, it 
    // uses its default
    if (!isset($entity->{$this->row_map['value']})) {
      return FALSE;
    }
    return $entity->{$this->row_map['value']}; // nothing fancy done by default
  }
  
  public function dh_getProp($entity, $propname = NULL, $view='') {
    // @todo: implement om routines
    // called by the entity's own om_getValue routines
    // entity checks for plugins, if they exists, it runs the plugins om_getValue routine, if not, it 
    // uses its default
  }
  
  public function loadReplicant(&$entity, $varkey, $exclude_cached = FALSE, $repl_bundle = FALSE) {
    // to prevent infinite loops of accidentally recursive replicants 
    // we need some protections:
    //   $exclude_cached - if it was retrieved from the cache it might be recursive

    if ($entity->entityType() == 'dh_properties') {
      $bundle = !$repl_bundle ? 'dh_properties' : $repl_bundle;
      $replicant_info = array(
        'featureid' => $entity->featureid,
        'entity_type' => $entity->entity_type,
        'bundle' => $bundle,
        'varkey' => $varkey,
      );
      $replicant_entity = dh_properties_enforce_singularity($replicant_info, 'singular');
    } else {
      // must be timeseries
      $replicant_info = array(
        'featureid' => $entity->featureid,
        'entity_type' => $entity->entity_type,
        'tstime' => $entity->tstime,
        'tsendtime' => $entity->tsendtime,
        'varkey' => $varkey,
      );
      $replicant_entity = dh_timeseries_enforce_singularity($replicant_info, 'tstime_singular');
    }
    if (!is_object($replicant_entity)) {
      $replicant_entity = entity_create($entity->entityType(), $replicant_info);
    }
    // check custody chain -- return false if a match exists indicating recursion
    if (in_array($entity, $entity->entity_chain) and $exclude_cached) {
      $replicant_entity = FALSE;
    } else {
      $entity->entity_chain[] = &$replicant_entity;
      $replicant_entity->entity_chain = $entity->entity_chain;
    }
    return $replicant_entity;
  }
  
  public function updateLinked(&$entity) {
    // special update handlers to linked properties/ts or other.
  }
  
  // @todo: move this into dh module once we are satisifed that it is robust
  public function attachNamedForm(&$form, $entity) {
    $varinfo = $entity->varid ? dh_vardef_info($entity->varid) : FALSE;
    //dpm($varinfo,'var info');
    if (!$varinfo) {
      return FALSE;
    }
    //dpm($entity, 'attaching');
    $formshell = array();
    // use standard formatting to enable choices.
    $this->formRowEdit($formshell, $entity);
    $mname = $this->handleFormPropname($entity->propname);
    $vname = $this->row_map['value'];
    if (isset($entity->{$vname})) {
      $form[$mname] = $formshell[$vname];
      $form[$mname]['#title'] = isset($entity->title) ? t($entity->title) : t($entity->propname);
      $form[$mname]['#description'] = t($entity->vardesc);
      $form[$mname]['#type'] = 'textfield';
      if ( ($vname == 'tsvalue') or ($vname == 'propvalue')) {
        $form[$mname]['#element_validate'] = array('element_validate_number');
      }
      $form[$mname]['#default_value'] = !empty($entity->{$vname}) ? $entity->{$vname} : 0.0;
    }
  }
  
  public function exportOpenMI($entity) {
    // creates an array that can later be serialized as json, xml, or whatever
    $export = $this->exportOpenMIBase($entity);
    // load subComponents 
    $procnames = dh_get_dh_propnames('dh_properties', $entity->identifier());
    foreach ($procnames as $thisname) {
      $sub_entity = om_load_dh_property($entity, $thisname);
      $plugin = dh_variables_getPlugins($sub_entity);
      //dpm($plugin,'plugin');
      if (is_object($plugin) and method_exists($plugin, 'exportOpenMI')) {
        $sub_export = $plugin->exportOpenMI($sub_entity);
      } else {
        $sub_export = array(
          $sub_entity->propname => array(
            'host' => $_SERVER['HTTP_HOST'], 
            'id' => $sub_entity->pid, 
            'name' => $sub_entity->propname, 
            'value' => $sub_entity->propvalue, 
            'code' => $sub_entity->propcode, 
          )
        );
      }
      $export[$entity->propname][$thisname] = $sub_export[$sub_entity->propname];
    }
    return $export;
  }
  
  public function exportVarDefs($entity, &$export = array()) {
    // creates an array that can later be serialized as json, xml, or whatever
    $export[$entity->varcode] = (array)dh_vardef_info($entity->varid);
    $export[$entity->varcode]['varid'] = $export[$entity->varcode]['hydroid'];
    unset($export[$entity->varcode]['hydroid']);
    // load subComponents 
    $procnames = dh_get_dh_propnames('dh_properties', $entity->identifier());
    foreach ($procnames as $thisname) {
      $sub_entity = om_load_dh_property($entity, $thisname);
      $plugin = dh_variables_getPlugins($sub_entity);
      //dpm($plugin,'plugin');
      if (is_object($plugin) and method_exists($plugin, 'exportVarDefs')) {
        $plugin->exportVarDefs($sub_entity, $export);
      }
    }
    return $export;
  }
  
  public function exportOpenMIBase($entity) {
    // creates the base properties for this class
    $export = array(
      $entity->propname => array(
        'host' => $_SERVER['HTTP_HOST'], 
        'id' => $entity->pid, 
        'name' => $entity->propname, 
        'value' => $entity->propvalue, 
        'code' => $entity->propcode, 
      )
    );
    return $export;
  }
}

?>
