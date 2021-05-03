<?php
module_load_include('inc', 'dh', 'plugins/dh.display');
/**
 * @file
 * Pane for multiple data layer leaflet maps.
 */

$plugin = array(
  'title' => t('Default TimeSeries Panel Form'),
  'description' => t('Display a TimeSeries Entity form in a panel page.'),
  'module' => 'timeseries_form',
  'category' => t('dH Meta-Modeling'),
  'single' => TRUE,
  'defaults' => array(),
  'admin info' => 'timeseries_form_admin_info',
  'render callback' => 'timeseries_form_render',
  'edit form' => 'timeseries_form_edit_form',
  'all contexts' => TRUE, 
);

/**
 * Callback for page_manager admin UI information.
 */
function timeseries_form_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

    $admin_info = t('@entity_type (@formid)', array(
      '@entity_type' => $conf['timeseries_form_settings']['entity_type'],
      '@formid' => $conf['timeseries_form_settings']['formid'],
    ));
    $block->content = $admin_info;

    return $block;
  }
}

/**
 * Callback to render the entity add/edit form in a pane.
 */
function timeseries_form_edit_form($form, &$form_state) {
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  //dpm($conf, "entity_settings to edit form");
  // extract info about the root entity of the form
  $tsg = new dhTimeSeriesGroup($conf);
  $tsg->buildOptionsForm($form, $form_state);
  //drupal_render($form);
  return $form;
}


function timeseries_form_render($subtype, $conf, $panels_args, &$context) {
  // Build the pane.
  $pane = new stdClass();
  $pane->module = 'ctools';
  // This title can/should be overriden in the page manager UI.
  $pane->title = 'TimeSeries Pane Form';
  if (!isset($context->form)) {
    // not really sure what to do here, if anything
  } else {
    // same as above, but perhaps it is relevant?
  }

  switch ($conf['entity_settings']['display_type']) {
    case 'table':
      $pob = new dhTimeSeriesGroup($conf['entity_settings']);
      $pob->prepareQuery();
      $pob->getData();
      $pane->content = $pob->viewTable();
    break;
    case 'form':
    default:
      $form_state = array();
      $form_state['conf'] = $conf;
      $elements = drupal_build_form('timeseries_panel_form', $form_state);
      $pane->content = drupal_render($elements);
    break;
  }
  //dpm($tsg,'ts object handler');

  return $pane;
}

function timeseries_panel_form_submit($form, &$form_state) {
  //dpm($form_state,"Form State");
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  $tsg = new dhTimeSeriesGroup($conf);
  //dpm($tsg,'ts object handler');
  $tsg->submitForm($form, $form_state);
}

function timeseries_panel_form_validate($timeseries, $form, &$form_state) {
  //dpm($form_state,"Validating Form State");
}
function timeseries_panel_form_alter(&$form, &$form_state, $form_id) {
  // iterate through grouprecords
  // if an insert is called with null values for ALL of the fields in ->skip_null
  // we assume that the given record is not intended for saving.  We alert the user, and unset the form_state record?
}

function timeseries_panel_form($form, &$form_state, $ts_entity = null, $op = 'edit') {
  //dpm($form_state['conf'], "Form conf passed in");
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $form_state['conf']['entity_settings'];
  $tsg = new dhTimeSeriesGroup($conf);
  $tsg->prepareQuery();
  $tsg->getData();
  $tsg->buildForm($form, $form_state);
  $tsg->addFormActions($form, $form_state);
  return $form;
}

/**
 * Submit handler just puts non-empty values into $form_state['conf'].
 */
function timeseries_form_edit_form_submit($form, &$form_state) {
  //dpm($form_state['values']['entity_settings'], "Form values entity_settings to SUBMIT");
  foreach (element_children($form['entity_settings']) as $key) {
    if (isset($form_state['values']['entity_settings'][$key])) {
      $form_state['conf']['entity_settings'][$key] = $form_state['values']['entity_settings'][$key];
    }
  }
}
