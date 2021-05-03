<?php

/**
 * @file
 * Definition of dh_views_handler_field_date_extended.
 */

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class dh_views_handler_field_date_extended extends views_handler_field_date {
  function query() {
    parent::query();
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['alter']['contains']['alter_date_format'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['alter']['alter_date_format'] = array(
      '#type' => 'select',
      '#options' => array(
        FALSE => 'FALSE',
        TRUE => 'TRUE'
      ),
      '#title' => t('Apply Date Formatting to Re-Written Value'),
      '#description' => t('Use selected date format on value of rewrite.  Will process a numerical values as a unix time stamp, or a string date using dH smart date handler.'),
      '#default_value' => $this->options['alter']['alter_date_format'],
    );
  }
  
  function render_altered($alter, $tokens) {
    $value = parent::render_altered($alter, $tokens);
    if ($alter['alter_date_format']) {
      $value = $this->apply_date_formatting($value);
    }
    return $value;
  }
  
  function apply_date_formatting($value) {
    $format = $this->options['date_format'];
    if (in_array($format, array('custom', 'raw time ago', 'time ago', 'raw time hence', 'time hence', 'raw time span', 'time span', 'raw time span', 'inverse time span', 'time span'))) {
      $custom_format = $this->options['custom_date_format'];
    }
    $timezone = !empty($this->options['timezone']) ? $this->options['timezone'] : NULL;
    $time_diff = REQUEST_TIME - $value; // will be positive for a datetime in the past (ago), and negative for a datetime in the future (hence)
    switch ($format) {
      case 'raw time ago':
        return format_interval($time_diff, is_numeric($custom_format) ? $custom_format : 2);
      case 'time ago':
        return t('%time ago', array('%time' => format_interval($time_diff, is_numeric($custom_format) ? $custom_format : 2)));
      case 'raw time hence':
        return format_interval(-$time_diff, is_numeric($custom_format) ? $custom_format : 2);
      case 'time hence':
        return t('%time hence', array('%time' => format_interval(-$time_diff, is_numeric($custom_format) ? $custom_format : 2)));
      case 'raw time span':
        return ($time_diff < 0 ? '-' : '') . format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2);
      case 'inverse time span':
        return ($time_diff > 0 ? '-' : '') . format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2);
      case 'time span':
        return t(($time_diff < 0 ? '%time hence' : '%time ago'), array('%time' => format_interval(abs($time_diff), is_numeric($custom_format) ? $custom_format : 2)));
      case 'custom':
        if ($custom_format == 'r') {
          return format_date($value, $format, $custom_format, $timezone, 'en');
        }
        return format_date($value, $format, $custom_format, $timezone);
      default:
        return format_date($value, $format, '', $timezone);
    }
  }
  
  function render($values) {
    $value = $this->get_value($values);
    if ($value) {
      return $this->apply_date_formatting($value);
    }
  }
}

