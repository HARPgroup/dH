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
class dh_views_handler_field_week_numeric extends views_handler_field {
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
    unset($form['alter']['alter_text']);
    $format_options =  array(
      'unformatted' => 'Unformatted (integer week of year)', 
      'date_span_md' => 'Date Span (MM1/DD1 to MM2/DD2)', 
      'date_span_begin_ymd' => 'Week-Start YYYY-MM-DD', 
      'date_span_midwk_ymd' => 'Mid-Week YYYY-MM-DD', 
      'date_span_end_ymd' => 'Week-End YYYY-MM-DD', 
    );
    $form['format'] = array(
      '#type' => 'select',
      '#title' => t('Render Format'),
      '#description' => t('Method of rendering the week of year.'),
      '#default_value' => $this->options['format'],
      '#options' => $format_options,
    );
  }

  function render($values) {
    //dpm($values, 'week handler render() values');
    // Return the text, so the code never thinks the value is empty.
    
    // get the day of the week so we can back caculate to find the week beginning
    $day = date('w', $values->ts);
    $tsdate = new DateTime;
    $tsdate->setTimestamp($values->ts);
    switch ($this->options['format']) {
      case 'date_span_md':
      $week_start = date('m-d', $values->ts - $day * 86400);
      $week_end = date('m-d', $values->ts + (7-$day) * 86400);
      $formatted = "$week_start to $week_end";
      break;
      
      case 'date_span_begin_ymd':
      $formatted = date('Y-m-d', $values->ts - $day * 86400);
      break;
      
      case 'date_span_end_ymd':
      $formatted = date('Y-m-d', $values->ts + (6-$day) * 86400);
      break;
      
      case 'date_span_midwk_ymd':
      $formatted = date('Y-m-d', $values->ts + (3-$day) * 86400);
      break;
      
      default:
        $formatted = $this->sanitize_value($this->get_value($values));
      break;
    }
    return $formatted;
  }
}

