<?php
module_load_include('inc', 'dh', 'plugins/dh.display');
module_load_include('module', 'dh');

  
class dHVarWithTableFieldBase extends dHVariablePluginDefault {
  var $matrix_field = 'field_dh_matrix';
  // @todo: Decide if this should be renamed with a non-om prefix 
  // -- seems reasonable to have something this basic in the dh module, and in doesn't require any
  //    additional plumbing.  Either way, something needs to add the bundle in the module install code
  var $default_bundle = 'om_data_matrix'; 
  
  public function optionDefaults($conf = array()) {
    parent::optionDefaults($conf);
    foreach ($this->hiddenFields() as $hide_this) {
      $this->property_conf_default[$hide_this]['hidden'] = 1;
    }
  }
  
  public function hiddenFields() {
    return array('pid', 'startdate', 'enddate', 'varid', 'featureid', 'entity_type', 'bundle','dh_link_admin_pr_condition');
  }
  
  public function entityDefaults(&$entity) {
    //dpm($entity,'entity');
    // special render handlers when displaying in a grouped property block
    $entity->bundle = $this->default_bundle;
    $datatable = $this->tableDefault($entity);
    $this->setCSVTableField($entity, $datatable);
    //dpm($entity, 'entityDefaults');
  }
  
  public function formRowRender(&$rowvalues, &$row) {
    // special render handlers when displaying in a grouped property block
    $row->propvalue = number_format($row->propvalue, 3);
  }
  
  public function formRowEdit(&$rowform, $entity) {
    // special render handlers when displaying in a grouped property block
    $this->hideFormRowEditFields($rowform);
  }
  
  public function setUp(&$entity) {
    //dpm($entity, 'setUp()');
  }
  
  public function load(&$entity) {
    // get field default basics
    //dpm($entity, 'load()');
    if ($entity->is_new or $entity->reset_defaults) {
      $datatable = $this->tableDefault($entity);
      $this->setCSVTableField($entity, $datatable);
    }
  }
  
  public function tableDefault($entity) {
    // Returns associative array keyed table (like is used in OM)
    // This format is not used by Drupal however, so a translation 
    //   with tablefield_parse_assoc() is usually in order (such as is done in load)
    // set up defaults - we can sub-class this to handle each version of the model land use
    // This version is based on the Chesapeake Bay Watershed Phase 5.3.2 model land uses
    // this brings in an associative array keyed as $table[$luname] = array( $year => $area )
    $table = array();
    $table[] = array('col1', 'col2', 'col3');
    $table[] = array(1,2,3);
    return $table;
  }
  
  public function create(&$entity) {
    // set up defaults?
    if ($this->default_bundle) {
      $entity->bundle = $this->default_bundle;
    }
  }
  
  public function save(&$entity) {
    parent::save($entity);
  }
  
  function setCSVTableField(&$entity, $csvtable) {
    // requires a table to be set in non-associative format (essentially a csv)
    $instance = field_info_instance($entity->entityType(), $this->matrix_field, $entity->bundle);
    $field = field_info_field($this->matrix_field);
    $default = field_get_default_value($entity->entityType(), $entity, $field, $instance);
    //dpm($default,'default');
    list($imported_tablefield, $row_count, $max_col_count) = dh_tablefield_parse_array($csvtable);
    // set some default basics
    $default[0]['tablefield']['tabledata'] = $imported_tablefield;
    $default[0]['tablefield']['rebuild']['count_cols'] = $max_col_count;
    $default[0]['tablefield']['rebuild']['count_rows'] = $row_count;
    if (function_exists('tablefield_serialize')) {
      $default[0]['value'] = tablefield_serialize($field, $default[0]['tablefield']);
    } else {
      $default[0]['value'] = serialize($default[0]['tablefield']);
    }
    $default[0]['format'] = !isset($default[0]['format']) ? NULL : $default[0]['format'];
    $entity->{$this->matrix_field} = array(
      'und' => $default
    );
  }
}

?>