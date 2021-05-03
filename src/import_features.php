#!/user/bin/env drush
<?php

$args = array();
while ($arg = drush_shift()) {
  $args[] = $arg;
}
echo "import_features.php called with " . print_r($args,1) . "\n";

$update = FALSE;
$mode = 'ignore';
// Expects file with columns name, hydrocode, ftype, bundle, wkt 
if (count($args) >= 1) {
  // Do command line, single element settings
  // set these if doing a single -- will fail if both not set
  // $elementid = 340385; // set these if doing a single
  // $hydrocode = 'vahydrosw_wshed_JB0_7050_0000_yarmouth'; 
  $filepath = $args[0];
  if (isset($args[1])) {
    $mode = $args[1];
  }
  $filepath = $args[0];
} else {
  error_log("Usage: import_features.php filepath [update_mode=ignore/update/replace");
  error_log("File Headers: hydrocode, bundle, ftype, wkt, name ");
  die;
}

$handle = fopen($filepath, 'r');
echo "Called $filepath with Replace = $update \n";
echo "Opening $filepath \n";
$i = 0;
while ($values = fgetcsv($handle, 0, "\t")) {
  $i++;
  if ($i == 1) {
    $keys = $values;
    if ($mode <> 'ignore') {
      if (count(array_intersect(array('hydrocode', 'bundle', 'ftype'), $keys)) < 3) {
        error_log("Overwriting MUST include hydrocode, bundle and ftype to function.");
        break;
      }
    }
    continue;
  }
  $info = array_combine($keys, $values);
  error_log("Looking for $info[name]");
  $feature = dh_search_feature($info['hydrocode'], $info['bundle'], $info['ftype']);
  // only insert new ones, no updatez
  if (!($feature) or !($mode == 'ignore')) {
    if (!($feature)) {
      $icopy = $info;
      unset($icopy['wkt']);
      error_log("Trying to create feature with" . print_r($icopy,1) . "\n");
      $feature = entity_create('dh_feature', $info);
    } else {
      $feature = entity_load_single('dh_feature', $feature);
      error_log("Trying to $mode feature $feature->hydroid ");
      if ($mode == 'delete') {
        $feature->delete();
        continue;
      }
    }
    if (is_object($feature)) {
      $feature->dh_geofield = array(
        LANGUAGE_NONE => array(
          0 => array(
            'input_format' => GEOFIELD_INPUT_WKT, 
            'geom' => $info['wkt'],
          ),
        )
      );
    }
    echo "Saving $feature->name $feature->hydrocode \n";
    $feature->save();
  }
}
?>