<?php

//****************************
// Georaster Table
//****************************

class dHGeoRasterUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

	
  // Extend the 'add' path.
  $items[$this->path . '/add'] = array(
    'title' => 'Add Georaster',
	'description' => 'A form to enter dH Georaster',
    'page callback' => 'entity_ui_get_bundle_add_form',
    'page arguments' => array($this->entityType,$this->id_count + 1),
    'access callback' => 'entity_access',
    'access arguments' => array('create', $this->entityType),
    'type' => MENU_LOCAL_ACTION,
  );
      
    return $items;
  }		
}

/**
 * dH Georaster editing form.
 */

function dh_georaster_form($form, &$form_state, $dh_georaster, $op = 'edit') {
  if ($op == 'clone') {
    $dh_georaster->name .= ' (cloned)';
    $dh_georaster->bundle = '';
  }

/*  $form['tid'] = array(
    '#title' => t('Time Series ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->tid,
    '#description' => t('Primary key for Variables'),
    '#required' => TRUE,
    '#size' => 64,
  );*/

  $form['horizonid'] = array(
    '#title' => t('Horizon ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_georaster->horizonid,
    '#description' => t('Horizon ID: Defines the  depositional sequence; always from bottom to top'),
    '#required' => TRUE,
    '#size' => 64,
  );
  
  $form['clip'] = array(
    '#title' => t('Clip'),
    '#type' => 'textfield',
    '#default_value' => $dh_georaster->clip,
    '#description' => t('Option to clip the surface.'),
    '#required' => TRUE,
    '#size' => 64,
  );
  
  $form['fill'] = array(
    '#title' => t('Fill'),
    '#type' => 'textfield',
    '#default_value' => $dh_georaster->fill,
    '#description' => t('Option to fill from bottom up.'),
    '#required' => TRUE,
    '#size' => 64,
  );
 
  $form['hguid'] = array(
    '#title' => t('Hydrogeological Unit ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_georaster->hguid,
    '#description' => t('Hydrogeological Unit ID in Hydrogeologic Unit table '),
    '#required' => TRUE,
    '#size' => 64,
  ); 
  
  //field_attach_form('dh_georaster', $dh_georaster, $form, $form_state);
          
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Raster'),
    '#weight' => 40,
  );
  return $form;
}

/* Form API submit callback for the type form.
 */
function dh_georaster_form_submit(&$form, &$form_state) {
  $dh_georaster = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_georaster->save();
  $form_state['redirect'] = 'admin/content/dh_georaster/';
}

?>