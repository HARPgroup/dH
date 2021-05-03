<?php

/**
 * @file
 * Definition of views_handler_field_custom.
 */

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_date_extended extends views_handler_field_date {
  function query() {
    parent::query();
  }

  function option_definition() {
    $options = parent::option_definition();

    // Override the alter text option to always alter the text.
    $options['format'] =  array(
      'default' => FALSE, 
      'bool' => FALSE, 
    );
    $options['hide_alter_empty'] = array('default' => FALSE, 'bool' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['alter']['alter_date_format'] = array(
      '#type' => 'select',
      '#title' => t('Rewrite the output of this field'),
      '#description' => t('Use selected date format on value of rewrite.  Will process a numerical values as a unix time stamp, or a string date using dH smart date handler.'),
      '#default_value' => $this->options['alter']['alter_date_format'],
    );
  }
  function advanced_render($values) {
    dpm($values,"Advanced render called.");
  }
}

