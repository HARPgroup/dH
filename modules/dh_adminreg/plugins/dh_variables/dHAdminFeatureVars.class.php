<?php
module_load_include('inc', 'dh', 'plugins/dh.display');

class dHAdminFeatureVarDefault extends dHVariablePluginDefault {
  public function __construct($conf = array()) {
    parent::__construct($conf);
  }
  
  public function optionDefaults($conf = array()) {
    parent::optionDefaults($conf);
    $hidden = array('pid', 'propvalue', 'featureid', 'entity_type', 'bundle');
    foreach ($hidden as $hide_this) {
      $this->property_conf_default[$hide_this]['hidden'] = 1;
    }
  }
  
  public function formRowEdit(&$rowform, $row) {
    // @todo: figure this visibility into one single place
    // thse should automatically be hidden by the optionDefaults setting but for some reason...
    $hidden = array('pid', 'propvalue', 'featureid', 'entity_type', 'bundle');
    foreach ($hidden as $hide_this) {
      $rowform[$hide_this]['#type'] = 'hidden';
    }
    $rowform[$this->row_map['value']]['#size'] = 1;
    
  }
    
  public function buildContent(&$content, &$entity, $view_mode) {
    $hidden = array_keys($content);
    foreach ($hidden as $col) {
      $content[$col]['#type'] = 'hidden';
    }
    $feature = $this->getParentEntity($entity);
    $content['title']['#markup'] = $feature->name . ' modified on ' . date('Y-m-d', $feature->modified); 
    // see docs for drupal function l() for link config syntax
    $content['link'] = array(
      '#type' => 'link',
      '#prefix' => '&nbsp;',
      '#title' => 'View',
      '#href' => 'dh_adminreg_feature/' . $feature->adminid,
    );

  }
  
}
?>