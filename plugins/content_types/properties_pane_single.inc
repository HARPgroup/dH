<?php
module_load_include('inc', 'dh', 'plugins/dh.display');
module_load_include('inc', 'dh', 'dh.admin');
/**
 * @file
 * Pane for multiple data layer leaflet maps.
 */

$plugin = array(
  'title' => t('Single Properties Panel Form'),
  'description' => t('Display a Properties Entity form in a panel page.'),
  'module' => 'properties_form',
  'category' => t('dH Meta-Modeling'),
  'single' => TRUE,
  'defaults' => array(),
  'admin info' => 'properties_single_form_admin_info',
  'render callback' => 'properties_single_form_render',
  'edit form' => 'properties_single_form_edit_form',
  'all contexts' => TRUE, 
);

/**
 * Callback for page_manager admin UI information.
 */
function properties_single_form_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

    $admin_info = t('@entity_type (@formid)', array(
      '@entity_type' => $conf['properties_single_form_settings']['entity_type'],
      '@formid' => $conf['properties_single_form_settings']['formid'],
    ));
    $block->content = $admin_info;

    return $block;
  }
}

/**
 * Callback to render the entity add/edit form in a pane.
 */
function properties_single_form_edit_form($form, &$form_state) {
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  //dpm($conf, "entity_settings to edit form");
  // extract info about the root entity of the form
  $pob = new dhPropertiesSingle($conf);
  $pob->buildOptionsForm($form, $form_state);
  //drupal_render($form);
  return $form;
}

/**
 * Submit handler just puts non-empty values into $form_state['conf'].
 */
function properties_single_form_edit_form_submit($form, &$form_state) {
  //dpm($form_state['values']['entity_settings'], "Form values entity_settings to SUBMIT");
  //dpm($form_state, "All Form values entity_settings to SUBMIT");
  foreach (element_children($form['entity_settings']) as $key) {
    if (isset($form_state['values']['entity_settings'][$key])) {
      $form_state['conf']['entity_settings'][$key] = $form_state['values']['entity_settings'][$key];
    }
  }
}


function properties_single_form_render($subtype, $conf, $panels_args, &$context) {
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
  $display_type = 'form'; // hard-wired here as we don't wish to offer the display, but we may later?
  // if so, we do:
  // $display_type = $conf['entity_settings']['display_type'];
  //dpm($conf);
  switch ($conf['entity_settings']['display_type']) {
    case 'table':
      $pob = new dhPropertiesSingle($conf['entity_settings']);
      $pob->prepareQuery();
      $pob->getData();
      $pane->content = $pob->viewBlock();
    break;
    case 'form':
    default:
      //$conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
      $pob = new dhPropertiesSingle($conf['entity_settings']);
      // don't need to do this since the form object handles retrieval of a single entity
      //$pob->prepareQuery();
      //$pob->getData();
      $form = array();
      $pob->buildForm($form, $form_state);
      $pob->addFormActions($form, $form_state);
      $pane->content = $form;
    break;
  }
  return $pane;
}

function properties_single_panel_form_submit($form, &$form_state) {
  //dpm($form_state['values']['entity_settings'], "Form values entity_settings to SUBMIT");
  //dpm($form_state, "All Form values entity_settings to SUBMIT");
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  $pob = new dhPropertiesSingle($conf);
  $pob->validateForm($form, $form_state);
  $pob->submitForm($form, $form_state);
  //dpm($pob->conf['destination'], 'object destination');
  if ($pob->conf['destination'] <> '') {
    $form_state['redirect'] = $pob->conf['destination'];
  }
}

//function properties_single_panel_form_validate($properties, $form, &$form_state) {
  //dpm($form_state,"Validating Form State");
//}

function properties_single_panel_form_alter(&$form, &$form_state, $form_id) {
  // @todo: identify what may be needed here
}

function properties_single_panel_form($form, &$form_state, $ts_entity = null, $op = 'edit') {
  //dpm($form_state['conf'], "Form conf passed in");
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  //dpm($conf, "Final conf");
  $pob = new dhPropertiesSingle($conf);
  $pob->prepareQuery();
  $pob->getData();
  $pob->buildForm($form, $form_state);
  $pob->addFormActions($form, $form_state);
  return $form;
}
