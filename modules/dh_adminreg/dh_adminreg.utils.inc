<?php

global $dhar_entityreferences;
$dhar_entityreferences = array(
  'organization' => array('user' => 'dh_link_admin_record_mgr_id'),
  'permit' => array('user' => 'dh_link_admin_record_mgr_id'),
);

// **************************************************
// ***********    dHW Tree Functions    *************
// **  return array of form
// **  array(
// **   'weather_station' => array('ids' => array()), 
// **   'weather_sensor' => array('ids' => array()),
// **   'om_model' => array('ids' => array()), 
// **   'user' => array('ids' => array()), 
// **  );
// **************************************************


// Weather Station/Sensor/Model Tree by user
// Usage in Contextual Filter Validation PHP:
//   module_load_include('inc', 'dh_weather', 'dh_weather.utils');
//   $models = dh_weather_usertree($uid);
//   $handler->argument = implode($models, '+');
//   return true;
function dh_adminreg_usertree($uid, $bundle = 'organization') {
  global $dhar_entityreferences;
  // query for user, then station, then sensor, then model links
  // foreach as $bundle => $target => $eref_col
  $etype = 'dh_adminreg_feature';
  $target_type = 'dh_adminreg_feature';
  $target_id = $uid;
  $target_pk = 'adminid';
  $ret = array(
    'organization'=>array('ids'=>array()),
    'user'=>array('ids'=>array($uid)),
  );
  $models = array();
  $sensors = array();
  drupal_set_message("calling dh_weather_tree_query($etype, $bundle, $target_type, $target_id) ");
  $ret = dh_adminreg_tree_query($etype, $bundle, $target_type, $target_pk, $target_id);
  drupal_set_message("result " . print_r($ret ,1) );
  $stations = $ret['weather_station'];
  foreach ($stations['ids'] as $sta) {
    $sens = dh_weather_tree_query($etype, 'weather_sensor', 'weather_station', $target_pk, $sta);
    foreach ($sens as $thissen) {
      $sensors = array_merge($sensors, $thissen['ids']);
      foreach ($thissen['ids'] as $thisid) {
        $mods = dh_weather_tree_query($etype, 'om_model', 'weather_sensor', $target_pk, $thisid);
        foreach ($mods as $thismod) {
          $models = array_merge($models, $thismod['ids']);
        }
      }
    }
  }
  $ret['om_model']['ids'] = $models;
  $ret['weather_station']['ids'] = $stations;
  $ret['weather_sensor']['ids'] = $sensors;
  //drupal_set_message("Models: " . print_r($ret,1));
  return $ret;
}
  
function dh_adminreg_tree_query($etype, $bundle, $ftype, $target_type, $target_pk, $target_id, $debug = 0) {
  global $dhar_entityreferences;
  $ret = array();
  $efq = new EntityFieldQuery(); 
  $efq->entityCondition('entity_type', $etype);
  $efq->entityCondition('bundle', $bundle);
  //$efq->entityCondition('ftype', $ftype);
  drupal_set_message("dhar_entityreferences : <pre>" . print_r($dhar_entityreferences,1) . "</pre>");
  $refname = $dhar_entityreferences[$bundle][$target_type];
  drupal_set_message("efq for $refname [$bundle][$target_type] $target_id: ");
  $efq->fieldCondition($refname, 'target_id', $target_id, '=');
  $ret[$bundle]['ids'] = array();
  $result = $efq->execute();
  drupal_set_message("efq for [$bundle][$target_type] $target_id: " . print_r($result ,1) );
  if (isset($result[$etype])) {
    foreach ($result[$etype] as $rez) {
      if (property_exists($rez, $target_pk)) {
        $ret[$bundle]['ids'][] = $rez->$target_pk;
      } else {
        drupal_set_message("Prop $target_pk not on " . print_r((array)$rez,1));
      }
    }
  }
  return $ret;
}


function dh_adminreg_reverse_ref_query($conf, $debug = 0) {
  global $dhar_entityreferences;
  // conf is in form: 
  //  array(
  //    'src_etype' - source entity class 
  //    'src_bundle' - source bundle
  //    'src_ftype' - source ftype (not yet working)
  //    'src_pk' - source_entity pk field (adminid) 
  //    'target_type' - target entity type
  //    'target_id' - target pk field value
  $etype = $conf['src_etype'];
  $bundle = $conf['src_bundle'];
  $ftype = $conf['src_ftype'];
  $src_pk = $conf['src_pk'];
  $target_type = $conf['target_type'];
  $target_id = $conf['target_id'];
  $ret = array();
  $efq = new EntityFieldQuery(); 
  $efq->entityCondition('entity_type', $etype);
  $efq->entityCondition('bundle', $bundle);
  //$efq->entityCondition('ftype', $ftype);
  if ($debug) drupal_set_message("dhar_entityreferences : <pre>" . print_r($dhar_entityreferences,1) . "</pre>");
  $refname = $dhar_entityreferences[$bundle][$target_type];
  if ($debug) drupal_set_message("efq for $refname [$bundle][$target_type] $target_id: ");
  $efq->fieldCondition($refname, 'target_id', $target_id, '=');
  $ret = array();
  $result = $efq->execute();
  if ($debug) drupal_set_message("efq for [$bundle][$target_type] $target_id: " . print_r($result ,1) );
  if (isset($result[$etype])) {
    foreach ($result[$etype] as $rez) {
      if (property_exists($rez, $src_pk)) {
        $ret[] = $rez->$src_pk;
      } else {
        if ($debug) drupal_set_message("Prop $target_pk not on " . print_r((array)$rez,1));
      }
    }
  }
  return $ret;
}

?>