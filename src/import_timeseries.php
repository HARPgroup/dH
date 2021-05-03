#!/user/bin/env drush
<?php
module_load_include('inc', 'om', 'src/om_translate_to_dh');

$args = array();
while ($arg = drush_shift()) {
  $args[] = $arg;
}

if (count($args) < 1) {
  error_log("Usage: php import_timeseries.php query_type entity_type featureid varkey tsvalue tscode [extras as urlenc key1=val1&key2=val2...] ");
  die;
}
error_log("Args:" . print_r($args,1));
$query_type = $args[0];
$data = array();
if ($query_type == 'cmd') {
  if (count($args) >= 6) {
    $vars = array();
    $vars['entity_type'] = $args[1];
    $vars['featureid'] = $args[2];
    $vars['varkey']= $args[3];
    $vars['tsvalue'] = $args[4];
    $vars['tscode'] = $args[5];
    $vars['extras'] = $args[6];
    $data[] = $vars;
  } else {
    error_log("Usage: php import_timeseries.php query_type entity_type featureid varkey tsvalue tscode [extras as urlenc key1=val1&key2=val2...] ");
    die;
  }
} else {
  $filepath = $args[1];
  error_log("File requested: $filepath");
  $file = fopen($filepath, 'r');
  $header = fgetcsv($file, 0, "\t");
  if (count($header) == 0) {
    $header = fgetcsv($file, 0, "\t");
  }
  while ($line = fgetcsv($file, 0, "\t")) {
    $data[] = array_combine($header,$line);
  }
  error_log("File opened with records: " . count($data));
  error_log("Header: " . print_r($header,1));
  error_log("Record 1: " . print_r($data[0],1));
}



foreach ($data as $element) {
  if (isset($element['varkey'])) {
    $element['varid'] = dh_varkey2varid($element['varkey'], TRUE);
    unset($element['varkey']);
  }
  /*
  $q = "
    select tid from {dh_timeseries} 
    where tstime = $element[tstime] 
    and entity_type = '$element[entity_type]' 
    and featureid = $element[featureid] 
    and varid = $element[varid] ";
  error_log($q);
  $result = db_query($q);
  $tids = $result->fetchCol();
  
  if (count($tids) > 0) {
    error_log("Loading $tids[0] ");
    $ts = entity_load_single( 'dh_timeseries', $tids[0] );
    foreach ($element as $key => $val) {
      $entity->$key = $val;
    }
    $ts->save();
  } else {
    error_log("Creating");
    $ts = entity_create('dh_timeseries', $element);
    $ts->save();
  }
  */
  $tid = dh_update_timeseries($element);
  $i++;
  if ( ($i/5) == intval($i/5)) {
    echo "... $i ";
  }
}
echo " - total $i records ";
?>
