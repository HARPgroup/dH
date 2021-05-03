<?php

/**
 * @file
 * Definition of dh_timeseries_views_handler_field_entity.
 */

/**
 * A handler to display data from timeseries entity objects.
 *
 * @code views_entity_{ENTITY_TYPE} @endcode.
 *
 * @ingroup views_field_handlers
 */
class dh_timeseries_views_handler_field_entity extends entity_views_handler_field_entity {

  public function render($values) {
    // Note: Views result sets MUST have tid column included, even if hidden, in order to show a rendered ts entity.
    //dpm($values,'render');
    $rendered = EntityFieldHandlerHelper::render($this, $values);
    return $rendered;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $options = array(
      'label' => t('Show entity label'),
      'id' => t('Show entity ID'),
      'event_title' => t('Show title suitable for event calendar - supports plugins'),
      'event_description' => t('Show description suitable for event calendar - supports plugins'),
      'view' => t('Show complete entity'),
    );
    $form['display'] = array(
      '#type' => 'select',
      '#title' => t('Display'),
      '#description' => t('Decide how this field will be displayed.'),
      '#options' => $options,
      '#default_value' => $this->options['display'],
    );
  }
  
  public function render_single_value($entity, $values) {
    $type = $this->field_entity_type;
    // custom handling here for plugins, otherwise, we call the parent method
    
    switch ($this->options['display']) {
      case 'view':
        switch ($this->options['view_mode']){ 
          case 'plugin':
          case 'openmi_json':
            // by calling entity_build_content instead of entity_view omits things like the link to the original piece of content that is forced by entity.tpl.php
            $entity_view = entity_build_content($type, $entity, $this->options['view_mode']);
            //dpm($entity_view,'e view');
            return drupal_render($entity_view);
          break;
        }
      break;
      
      case 'event_title':
        return $entity->dh_getValue(FALSE, 'event_title');
      break;
      
      case 'event_description':
        return $entity->dh_getValue(FALSE, 'event_description');
      break;
    }
    return parent::render_single_value($entity, $values);
  }

  /**
   * Overridden to return the entity object, or a certain property of the entity.
   */
  function get_value($values, $field = NULL) {
    //dpm($values, "get_value called.");
    //dpm($field, "field .");
    return parent::get_value($values, $field);
  }
  
  /*
  // may add token support for rendered TS with plugins
  // since this must be robust, we cannot add plugin speicific keys, but we CAN add plugin specific values
  // for some predefined set of keys, for example we might define:
  // * title
  // * view_link
  // * edit_link
  // * code_formatted - tscode formatted (like from a code to a readable value)
  // * code_raw = raw tscode
  // * teaser
  // * body
  // * values (would show tsvalue, tscode, or both
  // code copied from: http://data.agaric.com/add-replacement-pattern-token-views-field-rewrite-results
  function document_self_tokens(&$tokens) {
    $field = $this->field_info;
    foreach ($field['columns'] as $id => $column) {
      $tokens['[' . $this->options['id'] . '-' . $id . ']'] = t('Raw @column', array('@column' => $id));
      $tokens['[' . $this->options['id'] . '-' . 'term-pretty-path]'] = t('Term pretty path');
      $tokens['[' . $this->options['id'] . '-' . 'vocabulary-pretty-path]'] = t('Vocabulary pretty path');
    }
  }
  
  function add_self_tokens(&$tokens, $item) {
    $field = $this->field_info;
    foreach ($field['columns'] as $id => $column) {
      // Use filter_xss_admin because it's user data and we can't be sure it is safe.
      // We know nothing about the data, though, so we can't really do much else.
      if (isset($item['raw'])) {
        // If $item['raw'] is an array then we can use as is, if it's an object
        // we cast it to an array, if it's neither, we can't use it.
        $raw = is_array($item['raw']) ? $item['raw'] :
               (is_object($item['raw']) ? (array)$item['raw'] : NULL);
      }
      if (isset($raw) && isset($raw[$id]) && is_scalar($raw[$id])) {
        $path_string = cultura_archive_term_pretty_path($raw[$id]);
        $path = explode('/', $path_string);
        $tokens['[' . $this->options['id'] . '-term-pretty-path]'] = $path[1];
        $tokens['[' . $this->options['id'] . '-vocabulary-pretty-path]'] = $path[0];
      }
      else {
        // Take sure that empty values are replaced as well.
        $tokens['[' . $this->options['id'] . '-term-pretty-path]'] = '';
        $tokens['[' . $this->options['id'] . '-vocabulary-pretty-path]'] = '';
      }
    }
  }
  */
}
