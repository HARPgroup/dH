<?php
module_load_include('inc', 'dh', 'plugins/dh.display');
/**
 * @file
 * Pane for multiple data layer leaflet maps.
 */

$plugin = array(
  'title' => t('Default Properties Panel Form'),
  'description' => t('Display a Properties Entity form in a panel page.'),
  'module' => 'properties_form',
  'category' => t('dH Meta-Modeling'),
  'single' => TRUE,
  'defaults' => array(),
  'admin info' => 'properties_form_admin_info',
  'render callback' => 'properties_form_render',
  'edit form' => 'properties_form_edit_form',
  'all contexts' => TRUE, 
);

/**
 * Callback for page_manager admin UI information.
 */
function properties_form_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

    $admin_info = t('@entity_type (@formid)', array(
      '@entity_type' => $conf['properties_form_settings']['entity_type'],
      '@formid' => $conf['properties_form_settings']['formid'],
    ));
    $block->content = $admin_info;

    return $block;
  }
}

/**
 * Callback to render the entity add/edit form in a pane.
 */
function properties_form_edit_form($form, &$form_state) {
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  // extract info about the root entity of the form
  $tsg = new dhPropertiesGroup($conf);
  $tsg->buildOptionsForm($form, $form_state);
  //drupal_render($form);
  return $form;
}


function properties_form_render($subtype, $conf, $panels_args, &$context) {
  // Build the pane.
  $pane = new stdClass();
  $pane->module = 'ctools';
  // This title can/should be overriden in the page manager UI.
  $pane->title = 'Properties Pane Form';
  if (!isset($context->form)) {
    // not really sure what to do here, if anything
  } else {
    // same as above, but perhaps it is relevant?
  }
  switch ($conf['entity_settings']['display_type']) {
    case 'table':
      $pob = new dhPropertiesGroup($conf['entity_settings']);
      $pob->prepareQuery();
      $pob->getData();
      $pane->content = $pob->viewTable();
      //dpm($pob,'pob');
    break;
    case 'form':
    default:
      $form_state = array();
      $form_state['conf'] = $conf;
      $elements = drupal_build_form('properties_panel_form', $form_state);
      $pane->content = drupal_render($elements);
    break;
  }

  return $pane;
}

/**
 * Submit handler just puts non-empty values into $form_state['conf'].
 */
function properties_form_edit_form_submit($form, &$form_state) {
  //dpm($form_state['values']['entity_settings'], "Form values entity_settings to SUBMIT");
  //dpm($form,"form");
  //dpm($form_state,"form_state");
  //dpm($form_state['conf'],"form_state['conf']");
  //dpm(element_children($form['entity_settings']),"element_children(form['entity_settings'])");
  foreach (element_children($form['entity_settings']) as $key) {
    if (isset($form_state['values']['entity_settings'][$key])) {
      $form_state['conf']['entity_settings'][$key] = $form_state['values']['entity_settings'][$key];
    }
  }
  //dpm($form_state['conf'],"form_state['conf']");
}