<?php 
// if this is a scenario, we will look to the parent featureid for the list to show
// we do this on a null constant because
// modifying $handler->argument in this context overwrites the argument in the parent view!
$obj_pid = $view->args[0];
if (is_numeric($obj_pid)) {
  // load the property and get it's class
  $prop = entity_load_single('dh_properties', $obj_pid);
  $scen_varid = dh_varkey2varid('om_scenario', TRUE);
  if (is_object($prop)) {
    //dpm($prop, "found prop, scen_varid = $scen_varid");
    if ($prop->varid == $scen_varid) {
      // this is a scenario, look to the parent
      $obj_pid = $prop->featureid;
      //dpm($obj_pid, "setting pid to show scenarios from ");
    }
  }
}
return $obj_pid;


?>