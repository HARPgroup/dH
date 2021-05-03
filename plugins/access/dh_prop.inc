<?php 

$plugin = array(
  'title' => t('dH Feature Props'),
  'description' => t('Checks for specific properties of a requested entity.'),
  'callback' => 'dh_prop_check',
  'default' => array('negate' => 0),
  'summary' => 'dh_prop_check_summary',
  'settings form' => 'dh_prop_check_settings',
  'required context' => array(),
);

/**
 * Settings form for the 'title hide' access plugin.
 */
function dh_prop_check_settings($form, &$form_state, $conf) {
  $form['settings']['ftype'] = array(
    '#title' => t('FType'),
    '#type' => 'textfield',
    '#description' => t('FType field will be searched for entered string.'),
    '#default_value' => $conf['ftype'],
    '#required' => TRUE,
  );
  
  return $form;
}

/**
 * Provide a summary description.
 */
function dh_prop_check_summary($conf, $context) {
  $replacement = array('@ftype' => $conf['ftype']);
  return t('Checks if ftype = "@ftype".', $replacement);
}

/**
 * Check for access.
 */
function dh_prop_check($conf, $context) {
  $a = arg();
  $e = entity_load_single('dh_feature', $a[1]);
  if ($e) {
    if ($e->ftype == $conf['ftype']) {
      return TRUE;
    }
  }
  return FALSE;
}
?>