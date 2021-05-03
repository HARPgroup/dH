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

class views_handler_filter_dh_varkey extends views_handler_filter_in_operator_on {
  function option_definition() {
    $options = parent::option_definition();
    $options['vocabulary'] = array(
      'default' => array(), 
      'export' => 'export_plugin',
    );

    return $options;
  }
  
  function get_value_options() {
    $conditions = array();
    if (count($this->options['vocabulary']) > 0) {
      $vocab_clause = "vocabulary in ( '" . implode("', '", $this->options['vocabulary']) . "')";
      $conditions = array($vocab_clause);
    }
    $this->value_options = dh_vardef_varselect_options($conditions, 'varkey');
    return $this->value_options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $options = dh_vardef_vocab_options(TRUE);
    $form['vocabulary'] = array(
      '#title' => t('Vocabulary'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['vocabulary'],
      '#description' => t('What vocabulary to retrieve variables for - must save and re-open to update variable list.'),
      '#size' => 5,
      '#multiple' => TRUE,
      '#required' => FALSE,
    );
  }
}
