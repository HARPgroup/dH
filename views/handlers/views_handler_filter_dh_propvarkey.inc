<?php

/**
 * @file
 * Definition of views_handler_filter_dh_propvarkey.
 */

/**
 * Simple filter to handle matching of multiple options selectable via checkboxes
 *
 * Definition items:
 * - options callback: The function to call in order to generate the value options. If omitted, the options 'Yes' and 'No' will be used.
 * - options arguments: An array of arguments to pass to the options callback.
 *
 * @ingroup views_filter_handlers
 */

class views_handler_filter_dh_propvarkey extends views_handler_filter_dh_varkey {
  
  function op_location() {
    parent::op_location();
    // translate options values from varkey to varid
    foreach ($this->value as $vkey => $vval) {
      // be ok if previous config was old school varid
      $this->value[$vkey] = is_integer($vval) ? $vval : dh_varkey2varid($vval);
    }
  }
  
  function init(&$view, &$options) {
    parent::init($view, $options);
    // at some time in the future we wil deprecate this check
    // check to see if the value(s) are numeric, if so, we try to find the varkey associated with them
    $holder = $this->value;
    $first = array_shift($holder);
    if (intval($first) > 0) {
      //watchdog('dh',"Trying to convert varid to varkey " . print_r($this->value,1));
      $this->value = dh_varid2varkey($this->value);
      //watchdog('dh',"Conversion resulted in " . print_r($this->value,1));
    }
  }
}
