<?php

/**
 * @file
 * Definition of views_handler_filter_in_operator_on.
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

class views_handler_filter_in_operator_on extends views_handler_filter_in_operator {
  var $op_location = 'WHERE';

  /**
   * @var array
   * Stores all operations which are available on the form.
   */
  var $value_options = NULL;

  function construct() {
    parent::construct();
    $this->op_location = 'WHERE';
  }

  
  function init(&$view, &$options) {
    parent::init($view, $options);
    // at some time in the future we wil deprecate this check
    $this->value = is_array($this->value) ? $this->value : array($this->value);
    $this->operator = ($this->operator == '=') ? 'in' : $this->operator;
    $this->operator = ($this->operator == '!=') ? 'not in' : $this->operator;
    //$this->operator = in_array($this->operator, array('in', 'not in')) ? $this->operator : 'in';
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['op_location'] = array(
      'default' => 'WHERE', 
      'export' => 'export_plugin',
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['op_location'] = array(
      '#type' => 'select',
      '#required' => FALSE,
      '#title' => t('Condition Location'),
      '#description' => t('Advanced: Apply condition in WHERE clause, or in JOIN ON clause.'),
      '#options' => array(
        'WHERE' => 'WHERE',
        'ON' => 'ON',
      ),
      '#default_value' => $this->options['op_location'],
    );
  }

  function query() {
    // determine if this condition should appear on the WHERE or on clause
    $this->op_location();
    parent::query();
  }
  
  function op_location() {
    $this->ensure_my_table();
    // determine if this condition should appear on the WHERE or on clause
    $op_location = empty($this->options['op_location']) ? 'WHERE' : $this->options['op_location'];
    // force it to the WHERE clause if its the base table (should not allow option if this is base table)
    $this->op_location = ($this->query->table_queue[$this->table_alias]['join'] === null) ? 'WHERE' : $op_location;
  }

  function op_simple() {
    if (empty($this->value)) {
      return;
    }
    $this->ensure_my_table();
    switch ($this->op_location) {
      case 'ON':
        $this->query->table_queue[$this->table_alias]['join']->extra[] = array(
          'field' => $this->real_field,
          'value' => array_values($this->value),
          'operator' => $this->operator, 
          'numeric' => TRUE, 
        );
      break;
      case 'WHERE':
      default:
        // We use array_values() because the checkboxes keep keys and that can cause
        // array addition problems.
        $this->query->add_WHERE($this->options['group'], "$this->table_alias.$this->real_field", array_values($this->value), $this->operator);
      break;
    }
  }

  function op_empty() {
    $this->ensure_my_table();
    if ($this->operator == 'empty') {
      $operator = "IS NULL";
    }
    else {
      $operator = "IS NOT NULL";
    }

    switch ($this->op_location) {
      case 'ON':
        $this->query->table_queue[$this->table_alias]['join']->extra[] = array(
          'field' => $this->real_field,
          'value' => NULL,
          'operator' => $this->operator, 
          'numeric' => TRUE, 
        );
      break;
      case 'WHERE':
      default:
        // We use array_values() because the checkboxes keep keys and that can cause
        // array addition problems.
        $this->query->add_WHERE($this->options['group'], "$this->table_alias.$this->real_field", NULL, $operator);
      break;
    }
    
  }

}
