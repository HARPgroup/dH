<?php

/**
 * Field handler for node title editable field.
 */
class dh_editableviews_handler_dh_feature extends views_handler_field {

  /**
   * Boolean to indicate to the style plugin that this field is editable.
   *
   * We do this here rather than just check the class parentage to allow field
   * handlers to provide form elements for non-FieldAPI entity properties.
   */
  public $editable = TRUE;

  function option_definition() {
    $options = parent::option_definition();

    $options['textfield_size'] = array('default' => NULL);

    return $options;
  }
  function field_name() {
    return $this->options['property'];
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['textfield_size'] = array(
      '#type' => 'textfield',
      '#title' => t('Textfield size'),
      '#description' => t("The size of the textfield for this form element."),
      '#default_value' => $this->options['textfield_size'],
      '#size' => 6,
    );
  }

  /**
   * Return the edit form for the field.
   */
  function edit_form($entity_type, $entity, &$element, &$form_state) {
    // Just do the same thing as node_content_form().
	 $realfield = $this->real_field;
    $element[$realfield] = array(
      '#type' => 'textfield',
      '#title' => $realfield,
      '#required' => FALSE,
      '#default_value' => isset($entity->$realfield) ? $entity->$realfield : '',
      '#size' => $this->options['textfield_size'],
      '#maxlength' => 255,
    );
  }

  /**
   * Handle the form validation for this field's form element.
   */
  function edit_form_validate() {
    // Nothing to do.
  }

  /**
   * Handle the form submission for this field's form element.
   */
  function edit_form_submit($entity_type, $entity, &$element, &$form_state) {
    $parents = $element['#parents'];
	 $realfield = $this->real_field;
    $parents[] = $realfield;

    // Get the value out of the form state.
    $value = drupal_array_get_nested_value($form_state['values'], $parents);

    // Set it on the node.
    $entity->$realfield = $value;
  }

}
