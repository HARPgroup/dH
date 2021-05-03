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
class views_handler_field_dh_pluggable_numeric extends views_handler_field_numeric {
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

    // Remove the checkbox
    //unset($form['alter']['alter_text']);
    $format_options =  array(
      'default' => 'Default', 
      'plugin' => 'Use Plugins', 
    );
    $form['format'] = array(
      '#type' => 'select',
      '#title' => t('Value Format'),
      '#description' => t('Whether or not to modify the format of the data with dH plugins.'),
      '#default_value' => $this->options['format'],
      '#options' => $format_options,
    );
  }

  function get_value($values, $field = NULL) {
    //dpm($values, 'values');
    foreach ($values->_entity_properties['entity object']->dh_variables_plugins as $plug) {
      dpm($plug, 'plugin');
    }
    //dpm($values,'field values');
    return parent::get_value($values, $field);
    switch ($this->options['format']) {
      case 'plugin':
        $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
        if (isset($values->{$alias})) {
          $rawvalue = $values->{$alias};
        }
      break;
      
      default:
        return get_value($values, $field);
      break;
    }
  }
}

