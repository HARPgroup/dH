<?php 
/**
 * @file
 * Definition of views_handler_filter_dh_varkey.
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
class views_handler_filter_dh_fstatus extends views_handler_filter_in_operator_on {
  
  function get_value_options() {
    $this->value_options = dh_fstatus_options();
    return $this->value_options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}
