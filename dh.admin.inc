<?php

/**
 * @file
 * Model editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */
/**
 * UI controller.
 */
 //****************************
// TimeSeries
//****************************

class dHPropertiesTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Properties types, including adding	and removing fields and the display of fields.';
    return $items;
  }
}

//****************************
// TimeSeries
//****************************

class dHTimeSeriesTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Time Series types, including adding	and removing fields and the display of fields.';
    return $items;
  }
}
//****************************
// Feature
//****************************

class dHFeatureTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Feature types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

//****************************
// Borehole Log Type
//****************************

class dHBoreHoleLogTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Borehole log types, including adding
		and removing fields and the display of fields.';
    return $items;
  }

}

//****************************
// Feature
//****************************

class dHFeatureUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
/*	$items[$this->path] = array(
      'title' => 'dH Feature',
      'description' => 'Manage dH entity types, including adding and removing fields and the display of fields.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );*/
    
    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;	
	
    // Extend the 'add' path.
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'entity_ui_bundle_add_page',
      'page arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    $items[$this->path . '/add/%'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType, $this->id_count + 1),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
    );
    // attempt to create a view page
    // not yet working...
    $items['view/%dh_feature'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array(1),
      'page callback' => 'dh_feature_page_view',
      'page arguments' => array(1),
      'access arguments' => array('view dh_feature entities'),
      'type' => MENU_CALLBACK,
    );

    if (!empty($this->entityInfo['admin ui']['file'])) {
      // Add in the include file for the entity form.
      foreach (array('/add', '/add/%') as $path_end) {
        $items[$this->path . $path_end]['file'] = $this->entityInfo['admin ui']['file'];
        $items[$this->path . $path_end]['file path'] = isset($this->entityInfo['admin ui']['file path']) ? $this->entityInfo['admin ui']['file path'] : drupal_get_path('module', $this->entityInfo['module']);
      }
    }

    return $items;
  }
}

// dh_feature_page_view Referenced above in dHFeatureUIController hook_menu()
// in attempt to create a view page
// not yet working...
function dh_feature_page_view($dh_feature, $view_mode = 'full'){
  $dh_feature->content = array();
 
  // Build fields content.
  field_attach_prepare_view('dh_feature', array($dh_feature->hydroid => $dh_feature), $view_mode);
  entity_prepare_view('dh_feature', array($dh_feature->hydroid => $dh_feature));
  $dh_feature->content += field_attach_view('dh_feature', $dh_feature, $view_mode);
 
  return $dh_feature->content;
}

//****************************
// Hydrogeologic unit
//****************************

class dHHydroGeologicUnitUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

/*    $items[$this->path] = array(
      'title' => 'dH HydroGeologicUnit',
      'description' => 'Manage dH Hydro Geologic types, including adding and removing fields and the display of fields.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
*/
    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

	
  // Extend the 'add' path.
  $items[$this->path . '/add'] = array(
    'title' => 'Add Hydrogeologic Unit',
	'description' => 'A form to enter Hydrogeologic unit',
    'page callback' => 'entity_ui_get_bundle_add_form',
    'page arguments' => array($this->entityType,$this->id_count + 1),
    'access callback' => 'entity_access',
    'access arguments' => array('create', $this->entityType),
    'type' => MENU_LOCAL_ACTION,
  );
      
    return $items;
  }		
}

//****************************
// Borehole Log
//****************************

class dHBoreHoleLogUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Extend the 'add' path.
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'entity_ui_bundle_add_page',
      'page arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    $items[$this->path . '/add/%'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType, $this->id_count + 1),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
    );
    // attempt to create a view page
    // not yet working...
    $items['view/%dh_boreholelog'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array(1),
      'page callback' => 'dh_boreholelog_page_view',
      'page arguments' => array(1),
      'access arguments' => array('view dh_boreholelog entities'),
      'type' => MENU_CALLBACK,
    );

    if (!empty($this->entityInfo['admin ui']['file'])) {
      // Add in the include file for the entity form.
      foreach (array('/add', '/add/%') as $path_end) {
        $items[$this->path . $path_end]['file'] = $this->entityInfo['admin ui']['file'];
        $items[$this->path . $path_end]['file path'] = isset($this->entityInfo['admin ui']['file path']) ? $this->entityInfo['admin ui']['file path'] : drupal_get_path('module', $this->entityInfo['module']);
      }
    }

    return $items;
  }
}	

//****************************
// TimeSeries table
//****************************

class dHTimeSeriesTableUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

	
  // Extend the 'add' path.
  $items[$this->path . '/add'] = array(
    'title' => 'Add Time Series Data',
	  'description' => 'A form to enter Time Series data',
    'page callback' => 'entity_ui_get_bundle_add_form',
    'page arguments' => array($this->entityType,$this->id_count + 1),
    'access callback' => 'entity_access',
    'access arguments' => array('create', $this->entityType),
    'type' => MENU_LOCAL_ACTION,
  );
      
    return $items;
  }	
}

//****************************
// VariableDefinition table
//****************************

class dHVariableDefinitionUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

	
  // Extend the 'add' path.
  $items[$this->path . '/add'] = array(
    'title' => 'Add Variable Definition Data',
	'description' => 'A form to enter Varieable Definition',
    'page callback' => 'entity_ui_get_bundle_add_form',
    'page arguments' => array($this->entityType,$this->id_count + 1),
    'access callback' => 'entity_access',
    'access arguments' => array('create', $this->entityType),
    'type' => MENU_LOCAL_ACTION,
  );
      
    return $items;
  }		
}

//****************************
// Properties Table
//****************************

class dHPropertiesUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();

    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

	
    // Extend the 'add' path.
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'entity_ui_bundle_add_page',
      'page arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    $items[$this->path . '/add/%'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType, $this->id_count + 1),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
    );
    // attempt to create a view page
    // not yet working...
    $items['view/%dh_properties'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array(1),
      'page callback' => 'dh_properties_page_view',
      'page arguments' => array(1),
      'access arguments' => array('view dh_properties entities'),
      'type' => MENU_CALLBACK,
    );

    if (!empty($this->entityInfo['admin ui']['file'])) {
      // Add in the include file for the entity form.
      foreach (array('/add', '/add/%') as $path_end) {
        $items[$this->path . $path_end]['file'] = $this->entityInfo['admin ui']['file'];
        $items[$this->path . $path_end]['file path'] = isset($this->entityInfo['admin ui']['file path']) ? $this->entityInfo['admin ui']['file path'] : drupal_get_path('module', $this->entityInfo['module']);
      }
    }
    return $items;
  }		
}

// FORM Stuff

/**
 * dH Feature Type editing form.
 */
function dh_feature_type_form($form, &$form_state, $dh_feature_type, $op = 'edit') {

  if ($op == 'clone') {
    $dh_feature_type->name .= ' (cloned)';
    $dh_feature_type->bundle = '';
  }

  $form['name'] = array(
    '#title' => t('Feature Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_feature_type->name,
    '#description' => t('The human-readable name of this dH Feature type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	  '#type' => 'machine_name',
    '#default_value' => isset($dh_feature_type->bundle) ? $dh_feature_type->bundle : '',
    '#maxlength' => 32,
//    '#disabled' => $dh_feature_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'dh_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_feature_type->description,
    '#description' => t('Detailed description of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 255,
  );
    
 // $form['data']['#tree'] = TRUE;


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH Feature type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  ///*if (!$dh_feature_type->isLocked() && $op != 'add') {
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete model type'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_feature_type_form_submit_delete')
  );
  //}*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function dh_feature_type_form_submit(&$form, &$form_state) {
  $dh_feature_type = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_feature_type->save();
  $form_state['redirect'] = 'admin/structure/dh_feature_type';
}

/**
 * Form API submit callback for the delete button.
 */
function dh_feature_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/dh_feature_type/manage/' . $form_state['dh_feature_type']->bundle . '/delete';
}


/**
 * dH Feature editing form.
 */
function dh_feature_form($form, &$form_state, $dh_feature, $op = 'edit') {

  if ($op == 'clone') {
    $dh_feature->name .= ' (cloned)';
    $dh_feature->bundle = '';
  }

/*  $form['name'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $dh_feature->name,
    '#description' => t('The human-readable name of this dH Feature type.'),
    '#required' => TRUE,
    '#size' => 30,
  );*/

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_feature->name,
    '#description' => t('Name'),
    '#required' => TRUE,
    '#size' => 30,
  );  

  $form['ftype'] = array(
    '#title' => t('FType'),
    '#type' => 'textfield',
    '#default_value' => $dh_feature->ftype,
    '#description' => t('FType'),
    '#required' => TRUE,
    '#size' => 30,
  );  
  if (trim($dh_feature->hydrocode) == '') {
    $dh_feature->hydrocode = str_replace(' ', '_', strtolower($dh_feature->name ));
  }
  $form['hydrocode'] = array(
    '#title' => t('HydroCode'),
    '#type' => 'textfield',
    '#default_value' => $dh_feature->hydrocode,
    '#description' => t('The unique identifier used by the originating agency of this dH Feature type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  $form['fstatus'] = array(
    '#title' => t('Status'),
    '#type' => 'select',
    '#options' => array(
      'proposed' => t('Proposed/Unknown/Other'),
      'active' => t('Active'),
      'inactive' => t('Out of Service/Temporarily Inactive'),
      'abandoned' => t('Abandoned'),
      'duplicate' => t('Duplicate'),
    ),
    '#default_value' => $dh_feature->fstatus,
    '#description' => t('The unique identifier used by the originating agency of this dH Feature type.'),
    '#required' => TRUE,
    '#multiple' => FALSE,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($dh_feature->bundle) ? $dh_feature->bundle : '',
    '#maxlength' => 32,
    '#attributes' => array('disabled' => 'disabled'),
    '#machine_name' => array(
      'exists' => 'dh_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );


  field_attach_form('dh_feature', $dh_feature, $form, $form_state);
  
  $form['data']['#tree'] = TRUE;
/*  $form['data']['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_feature->description,
    '#description' => t('Detailed description of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 255,
  );
*/
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH Feature type'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete type'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_feature_form_submit_delete')
  );

  //Locking not supported yet
  /*if (!$dh_feature->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete model type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('dh_feature_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function dh_feature_form_submit(&$form, &$form_state) {
  $dh_feature = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_feature->save();
  $form_state['redirect'] = 'admin/content/dh_features';
}

/**
 * Form API submit callback for the delete button.
 */
function dh_feature_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/dh_features/manage/' . $form_state['dh_feature']->hydroid . '/delete';
}

// Misc Fields


function dh_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'om_data_table-om_data_table-field_om_data_starttime'
  $field_instances['dh_timeseries-tstime'] = array(
    'bundle' => 'dh_timeseries',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'dh_timeseries',
    'field_name' => 'tstime',
    'label' => 'Time',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 1,
    ),
  );
  
  $field_instances['dh_timeseries-tsendtime'] = $field_instances['dh_timeseries-tstime'];
  $field_instances['dh_timeseries-tsendtime']['field_name'] = 'tsendtime';
  $field_instances['dh_timeseries-modified'] = $field_instances['dh_timeseries-modified'];
  $field_instances['dh_timeseries-modified']['field_name'] = 'modified';

  // Exported field_instance: 'om_data_table-om_data_table-field_om_data_starttime'
  $field_instances['dh_properties-startdate'] = array(
    'bundle' => 'dh_properties',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'dh_properties',
    'field_name' => 'startdate',
    'label' => 'Time',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 1,
    ),
  );
  
  $field_instances['dh_properties-enddate'] = $field_instances['dh_properties-startdate'];
  $field_instances['dh_properties-enddate']['field_name'] = 'enddate';
  $field_instances['dh_properties-enddate'] = $field_instances['dh_properties-startdate'];
  $field_instances['dh_properties-modified']['field_name'] = 'modified';
  $field_instances['dh_properties-modified'] = $field_instances['dh_properties-startdate'];
  // Translatables
  // Included for use with string extractors like potx.
  t('Start Time');

  return $field_instances;
}

/**
 * dH HydrogeologicUnit editing form.
 */

function dh_hydrogeologicunit_form($form, &$form_state, $dh_hydrogeologicunit, $op = 'edit') {
  if ($op == 'clone') {
    $dh_hydrogeologicunit->name .= ' (cloned)';
    $dh_hydrogeologicunit->bundle = '';
  }

/*  $form['hydroid'] = array(
    '#title' => t('hydroid'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->hydroid,
    '#description' => t('Primary key for Variables'),
    '#required' => TRUE,
    '#size' => 64,
  );*/

  $form['hgucode'] = array(
    '#title' => t('Hydrogeologic Unit Code (HGU Code)'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->hgucode,
    '#description' => t('Hydrogeologic unit code. The permanent identification code of hydrogeologic units, used to establish a linkage with external information systems.'),
    '#required' => TRUE,
    '#size' => 64,
  );
  
  $form['hguname'] = array(
    '#title' => t('Hydrogeologic Unit Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->hguname,
    '#description' => t('Text descriptor of hydrogeologic units used for labeling and symbolization.'),
    '#required' => TRUE,
    '#size' => 64,
  );
  
  $form['aqcode'] = array(
    '#title' => t('Aquifer Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->aqcode,
    '#description' => t('Aquifer code. Text descriptor of the aquifer used for labeling, symbolization, and querying.'),
    '#required' => FALSE,
    '#size' => 64,
  );    
  
  $form['hydrocode'] = array(
    '#title' => t('Hydro Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->hydrocode,
    '#description' => t('Text field to associate with external data source.'),
    '#required' => TRUE,
    '#size' => 64,
  );   
  
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => $dh_hydrogeologicunit->description,
    '#description' => t('Text for storing detailed descriptions of hydrogeologic units.'),
    '#required' => FALSE,
    '#size' => 255,
  );   
      
    
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH HGU type'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete HGU'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_hydrogeologicunit_form_submit_delete')
  );
  return $form;
}

/*function dh_hydrogeologicunit_form_validate($form, &$form_state) {
  //if (!($form_state['values']['price'] > 0)){
  //  form_set_error('price', t('Price must be a positive number.'));
//  }
}*/
/**
 * Form API submit callback for the type form.
 */
function dh_hydrogeologicunit_form_submit(&$form, &$form_state) {
  $dh_hydrogeologicunit = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_hydrogeologicunit->save();
  $form_state['redirect'] = 'admin/content/dh_hydrogeologicunit/';
}
function dh_hydrogeologicunit_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/dh_hydrogeologicunit/manage/' . $form_state['dh_hydrogeologicunit']->hydroid . '/delete';
}


/**
 * dH Feature Type editing form.
 */
function dh_boreholelog_type_form($form, &$form_state, $dh_boreholelog_type, $op = 'edit') {

  if ($op == 'clone') {
    $dh_boreholelog_type->name .= ' (cloned)';
    $dh_boreholelog_type->bundle = '';
  }

  $form['name'] = array(
    '#title' => t('Borehole Log Type Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog_type->name,
    '#description' => t('The human-readable name of this Borehole type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	'#type' => 'machine_name',
    '#default_value' => isset($dh_boreholelog_type->bundle) ? $dh_boreholelog_type->bundle : '',
    '#maxlength' => 32,
//    '#disabled' => $dh_boreholelog_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'dh_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog_type->description,
    '#description' => t('Detailed description of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 255,
  );
    
 // $form['data']['#tree'] = TRUE;


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH Borehole type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  ///*if (!$dh_boreholelog_type->isLocked() && $op != 'add') {
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete model type'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_boreholelog_type_form_submit_delete')
  );
  //}*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function dh_boreholelog_type_form_submit(&$form, &$form_state) {
  $dh_boreholelog_type = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_boreholelog_type->save();
  $form_state['redirect'] = 'admin/structure/dh_boreholelog_type';
}

/**
 * Form API submit callback for the delete button.
 */
function dh_boreholelog_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/dh_boreholelog_type/manage/' . $form_state['dh_boreholelog_type']->bundle . '/delete';
}


/**
 * dH Boreholelog editing form.
 */

function dh_boreholelog_form($form, &$form_state, $dh_boreholelog, $op = 'edit') {
  if ($op == 'clone') {
    $dh_boreholelog->name .= ' (cloned)';
    $dh_boreholelog->bundle = '';
  }

/*  $form['bhlid'] = array(
    '#title' => t('Boreholelog ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->bhlid,
    '#description' => t('Primary key for Variables'),
    '#required' => TRUE,
    '#size' => 64,
  );*/

  $form['fromdepth'] = array(
    '#title' => t('From Depth'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->fromdepth,
    '#description' => t('The top elevation of an interval measured as depth along the borehole.'),
    '#required' => FALSE,
    '#size' => 64,
  );
  
  $form['todepth'] = array(
    '#title' => t('To Depth'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->todepth,
    '#description' => t('The bottom elevation of an interval measured as depth along the borehole.'),
    '#required' => FALSE,
    '#size' => 64,
  );
  
  $form['topelev'] = array(
    '#title' => t('Top Elevation'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->topelev,
    '#description' => t('Top elevation of an interval represented in absolute elevation units (e.g., feet above mean sea level).'),
    '#required' => FALSE,
    '#size' => 64,
  );    
  
  $form['bottomelev'] = array(
    '#title' => t('Bottom Elevation'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->bottomelev,
    '#description' => t('Bottom elevation of an interval represented in absolute elevation units (e.g., feet above mean sea level).'),
    '#required' => FALSE,
    '#size' => 64,
  );   
  
  $form['refelev'] = array(
    '#title' => t('Reference Elevation'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->refelev,
    '#description' => t('Text for storing detailed descriptions of hydrogeologic units.'),
    '#required' => FALSE,
    '#size' => 255,
  );   
      
  $form['material'] = array(
    '#title' => t('Material'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->material,
    '#description' => t('Description of strata observed along a borehole. Usually documented in drilling logs and later classified into geologic/hydrogeologic units.'),
    '#required' => FALSE,
    '#size' => 255,
  );   
      
	  
  $form['hgucode'] = array(
    '#title' => t('HGU Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->hgucode,
    '#description' => t('Hydrogeologic unit code. Text for classifying, symbolizing, and labeling hydrogeologic units. (External)'),
    '#required' => FALSE,
    '#size' => 255,
  );   
      
  $form['logtype'] = array(
    '#title' => t('Log Type'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->logtype,
    '#description' => t('Distinguishes between types of borehole logs (e.g., well completion, hydrostratigraphy).'),
    '#required' => FALSE,
    '#size' => 255,
  );
  $itype = array(
    'casing' => 'Casing',
    'grout' => 'Grout',
    'unit' => 'Unit',
    'gravel_pack' => 'Gravel Pack',
    'hole' => 'Hole',
    'screen' => 'Screen',
    'modflow_huf' => 'MODFLOW HUF',
    'waterzone' => 'Water Zone',
    'seal' => 'Seal',
    'gravel_grout' => 'Undefined - Gravel or Grout',
    'aquifer_top' => 'Aquifer Top',
  );
  ksort($itype);
  $form['ftype'] = array(
    '#title' => t('Interval Type'),
    '#type' => 'select',
    '#default_value' => $dh_boreholelog->ftype,
    '#description' => t('Feature Type (grout, screen, casing)'),
    '#required' => FALSE,
    '#options' => $itype,
  );   
  
  $valid = false;
  $hguid_options = array();
  $result = db_query("select hydroid, hguname from {dh_hydrogeologicunit} order by hguname");
  while($rez = $result->fetchAssoc()) {
    $hguid_options[$rez['hydroid']] = $rez['hguname'];
    $valid = TRUE;
  }
  if (!$valid) {
    $form['hguid'] = array(
      '#title' => t('HGU ID'),
      '#type' => 'textfield',
      '#default_value' => $dh_boreholelog->hguid,
      '#description' => t('Link to ID column of table geologic/hydrogeologic units.'),
      '#required' => FALSE,
      '#size' => 8,
    );
  } else {
    // got a list, let's use it
    $form['hguid'] = array(
      '#title' => t('HGU ID'),
      '#type' => 'select',
      '#options' => $hguid_options,
      '#default_value' => $dh_boreholelog->hguid,
      '#description' => t('Link to ID column of table geologic/hydrogeologic units.'),
      '#required' => FALSE,
    );
  }
      	  
  $form['diameter'] = array(
    '#title' => t('Diameter'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->diameter,
    '#description' => t('Well diameter (in).'),
    '#required' => FALSE,
    '#size' => 255,
  );   
      		  	  	  
  $form['elevunits'] = array(
    '#title' => t('Elevation Units'),
    '#type' => 'textfield',
    '#default_value' => $dh_boreholelog->elevunits,
    '#description' => t('Units of elevations stored in the TopElev and BottomElev attributes.'),
    '#required' => FALSE,
    '#size' => 255,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($dh_boreholelog->bundle) ? $dh_boreholelog->bundle : '',
    '#maxlength' => 32,
    '#attributes' => array('disabled' => 'disabled'),
    '#machine_name' => array(
      'exists' => 'dh_boreholelog_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  // for some reason edit forms hang when this is enabled?
  // maybe this is because it is not bundled?
  field_attach_form('dh_boreholelog', $dh_boreholelog, $form, $form_state);
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save borehole data'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete Entry'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_boreholelog_form_submit_delete')
  );
  return $form;
}

/* Form API submit callback for the type form.
 */
function dh_boreholelog_form_submit(&$form, &$form_state) {
  $dh_boreholelog = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_boreholelog->save();
  $form_state['redirect'] = 'admin/content/dh_boreholelog/';
}
function dh_boreholelog_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/dh_boreholelog/manage/' . $form_state['dh_boreholelog']->bhlid . '/delete';
}

/** 
 * dh timeseries plugins
 *   function dh_variables_getPlugins($dh_varobject) - MOVED TO dh.module
*/


function dh_variables_createRowPlugins(&$dh_varobject) {
  $plugin = dh_variables_getPlugins($dh_varobject);
  if ($plugin) {
    $plugin->entityDefaults($dh_varobject);
  }
}


function dh_variables_formRowPlugins(&$rowform, &$dh_varobject) {
  $plugin = dh_variables_getPlugins($dh_varobject);
  if ($plugin) {
    $plugin->formRowEdit($rowform, $dh_varobject);
  }
}


function dh_variables_formSubmitPlugins(&$rowform, &$dh_varobject) {
  $plugin = dh_variables_getPlugins($dh_varobject);
  if ($plugin) {
    $plugin->formRowSave($rowform, $dh_varobject);
  }
}

/**
 * dH Time Series editing form.
 */

function dh_timeseries_form($form, &$form_state, $dh_timeseries, $op = 'edit') {
  if ($op == 'clone') {
    $dh_timeseries->name .= ' (cloned)';
    $dh_timeseries->bundle = '';
  }
  $p = drupal_get_query_parameters();
  // handle url vars
  $url_varid = isset($p['varid']) ? $p['varid'] : FALSE;
  if (!is_numeric($url_varid)) {
    $url_varid = dh_varkey2varid($url_varid, TRUE);
  }
  $url_featureid = isset($p['featureid']) ? $p['featureid'] : FALSE;
  $url_entity_type = isset($p['entity_type']) ? $p['entity_type'] : FALSE;
  $dh_timeseries->varid = !$dh_timeseries->varid ? $url_varid : $dh_timeseries->varid;
  $dh_timeseries->featureid = !$dh_timeseries->featureid ? $url_featureid : $dh_timeseries->featureid;
  $dh_timeseries->entity_type = !$dh_timeseries->entity_type ? $url_entity_type : $dh_timeseries->entity_type;

  $form['tid'] = array(
    '#title' => t('Time Series ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->tid,
    '#description' => t('Primary key'),
 //   '#required' => TRUE,
    '#size' => 64,
  );

  $date_format = 'Y-m-d';
  $form['tstime'] = array(
    '#title' => t('Event Date/Time'),
    '#default_value' => empty($dh_timeseries->tstime) ? date($date_format) : date($date_format,$dh_timeseries->tstime),
    '#description' => t('Timestamp for monitored value.'),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-100:+50',
    '#required' => TRUE,
  );
  $form['tsendtime'] = array(
    '#title' => t('Event End Time'),
    '#default_value' => empty($dh_timeseries->tsendtime) ? $dh_timeseries->tsendtime : date($date_format,$dh_timeseries->tsendtime),
    '#description' => t('Timestamp for endtime value.'),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-100:+100',
    '#required' => FALSE,
  );
  $form['tsvalue'] = array(
    '#title' => t('Value'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->tsvalue,
    '#description' => t('The numerical value itself.'),
    '#required' => FALSE,
    '#element_validate' => array('element_validate_number'),
    '#size' => 16,
  );    

  $form['tscode'] = array(
    '#title' => t('Event Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->tscode,
    '#description' => t('Short Text Attribute.'),
    '#required' => FALSE,
    '#size' => 32,
  );
  
  $form['featureid'] = array(
    '#title' => t('Feature ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->featureid,
    '#description' => t('Unique numerical identifier of a feature within the geodatabase. Usually, the FeatureID of a TimeSeries record is equal to the HydroID of a feature (e.g., well, monitoring point).'),
    '#required' => TRUE,
    '#size' => 64,
  ); 
  $entities = entity_get_info();
  $form['entity_type'] = array(
    '#title' => t('Entity Type of Feature'),
    '#type' => 'select',
    '#options' => array_combine( array_keys($entities) , array_keys($entities) ),
    '#default_value' => $dh_timeseries->entity_type,
    '#description' => t('Supports linkage to multiple entities (dh_feature, dh_adminreg_feature, node, etc.).'),
    '#required' => FALSE,
    '#size' => 64,
  );
  
  $form['varid'] = array(
    '#title' => t('Variable ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_timeseries->varid,
    '#description' => t('Unique numerical identifier of a variable within the geodatabase. Variables are defined in the VariableDefinition table.'),
    '#required' => TRUE,
    '#size' => 255,
  );
  
  field_attach_form('dh_timeseries', $dh_timeseries, $form, $form_state);
  // we override this setting 
  $form['tstext']['und'][0]['value']['#title'] = t('Event Comments/Description.');
  $form['tstext']['#weight'] = 10;
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_timeseries_form_submit_delete')
  );

  $map = array(
    'varid' => 'varid',
    'id' => 'tid',
    'value' => 'tsvalue',
    'text' => 'tstext',
    'varname' => 'tsvalue',
    'code' => 'tscode',
    'start' => 'tstime',
    'end' => 'tsendtime',
    'featureid' => 'featureid',
    'entity_type' => 'entity_type',
  );
  dh_variable_set_form_visibility($form, $form_state, $map);
  if (!$dh_timeseries->varid) {
    // new entities will not have settable vars in the URL processed yet, but we need this to add plugins
    // check the form got it's URL variables if passed in
    // @todo: check to see if we add this in a form hook so that this check is unneccessary and secure?
    if ($form['varid']['#value']) {
      $dh_timeseries->varid = $form['varid']['#value'];
    }
  }
  dh_variables_formRowPlugins($form, $dh_timeseries);
  return $form;
}

function dh_variable_set_form_visibility(&$form, &$form_state, $map) {
  // @todo: support broader settings in a "config" column on dh_variable_definition table
  //   For each property (id, value, text, varname, ...) support the following settings:
  //     - #title 
  //     - visible (select T/F)
  //     - Read/Write (select R/W)
  //     - #weight (select -15 to +15) - this can be used in the config form as well as render form
  // $_REQUEST is variable used by prepopulate module 
  $visibility = array();
  $default = array(
    'id' => 'tid',
    'value' => 'tsvalue',
    'text' => 'tstext',
    'varname' => 'tsvalue',
    'code' => 'tscode',
    'start' => 'tstime',
    'end' => 'tsendtime',
    'featureid' => 'featureid',
    'entity_type' => 'entity_type',
  );
  $map = $map + $default;
  $varid = FALSE;

  //dpm($_REQUEST['edit'],'request edit');
  // this is an insert request, need to handle variables here because prepopulate module does not allow setting of invisibles
  if (isset($_REQUEST['edit'])) {
    if (!empty($_REQUEST['edit']['varid'])) {
      $varid = intval($_REQUEST['edit']['varid']);
      $oldvarid = $form['varid']['#value'];
      $form['varid']['#value'] = $varid;
    }
    if (!empty($_REQUEST['edit']['featureid'])) {
      $featureid = intval($_REQUEST['edit']['featureid']);
      $form['featureid']['#value'] = $featureid;
    }
    if (!empty($_REQUEST['edit']['entity_type'])) {
      $entity_type = $_REQUEST['edit']['entity_type'];
      $form['entity_type']['#value'] = $entity_type;
    }
    if (!empty($_REQUEST['edit']['propname'])) {
      $propname = $_REQUEST['edit']['propname'];
      $form['propname']['#value'] = $propname;
    }
  } else {
    if (isset($form['varid']['#default_value'])) {
      if (intval($form['varid']['#default_value']) > 0) {
        $varid = intval($form['varid']['#default_value']);
      }
    }
  }
  if ($varid) {
    $vinfo = dh_vardef_info($varid);
    if ($vinfo->hydroid <> $varid) {
      // this was a varkey query, so we replace varid in _REQUEST
      $_REQUEST['edit']['varid'] = $vinfo->hydroid;
    }
    if ($vinfo) {
      if (strlen(trim($vinfo->data_entry)) > 0) {
        $var_display_types = explode(',', $vinfo->data_entry);
        // override 
        $form[$map['varname']]['#label'] = $vinfo->varname;
        $form[$map['varname']]['#title'] = $vinfo->varname;
        $form[$map['varname']]['#description'] = $vinfo->vardesc;
        $visibility = array_fill_keys(array_unique(array_values($map)), FALSE);
        foreach ($var_display_types as $dtype) {
          switch (trim($dtype)) {
            case 'numeric':
            case 'value':
            $visibility[$map['value']] = TRUE;
            break;
            case 'text':
            $visibility[$map['text']] = TRUE;
            break;
            case 'boolean':
            $visibility[$map['value']] = TRUE;
            // set value as select list
            $options = array(
              0 => 'FALSE',
              1 => 'TRUE',
            );
            $form[$map['value']]['#type'] = 'select'; 
            $form[$map['value']]['#options'] = $options; 
            $form[$map['value']]['#size'] = 1; 
            break;
            case 'date_start':
            $visibility[$map['start']] = TRUE;
            break;
            case 'date_end':
            $visibility[$map['end']] = TRUE;
            break;
            case 'code':
            $visibility[$map['code']] = TRUE;
            break;
            case 'index':
            $visibility[$map['value']] = TRUE;
            break;
            case 'name':
            if (isset($map['name'])) {
              $visibility[$map['name']] = TRUE;
            }
            break;
          }
        }
      }
    }
  } else {
    $vinfo = FALSE;
  }
  // guess variable name position based on visibility, value is first choice, then code, then text
  if (isset($visibility[$map['value']]) and $visibility[$map['value']]) {
    $form[$map['varname']]['#label'] = $vinfo->varname;
    $form[$map['varname']]['#title'] = $vinfo->varname;
    $form[$map['varname']]['#description'] = $vinfo->vardesc;
  } else {
    if (isset($visibility[$map['code']]) and $visibility[$map['code']]) {
      $form[$map['code']]['#label'] = $vinfo->varname;
      $form[$map['code']]['#title'] = $vinfo->varname;
      $form[$map['code']]['#description'] = $vinfo->vardesc;
    } else {
      if (isset($visibility[$map['start']]) and $visibility[$map['start']]) {
        $form[$map['start']]['#label'] = $vinfo->varname;
        $form[$map['start']]['#title'] = $vinfo->varname;
        $form[$map['start']]['#description'] = $vinfo->vardesc;
      } else {
        if (isset($visibility[$map['end']]) and $visibility[$map['end']]) {
          $form[$map['end']]['#label'] = $vinfo->varname;
          $form[$map['end']]['#title'] = $vinfo->varname;
          $form[$map['end']]['#description'] = $vinfo->vardesc;
        } else {
          if (isset($visibility[$map['text']]) and $visibility[$map['text']]) {
            $form[$map['text']]['und'][0]['value']['#title'] = $vinfo->varname;
            $form[$map['text']]['und'][0]['value']['#description'] = $vinfo->vardesc;
          }
        }
      }
    }
  }
  foreach ($visibility as $vk => $vv) {
    if (!$vv) {
      if (isset($form[$vk])) {
        $form[$vk]['#type'] = 'hidden';
      }
    }
  }
}

/* Form API submit callback for the type form.
 */
function dh_timeseries_form_submit(&$form, &$form_state) {
  //dpm($form, 'form ');
  //dpm($form_state, 'form_state: ');
  $dh_timeseries = entity_ui_form_submit_build_entity($form, $form_state);
  dh_variables_formSubmitPlugins($form_state['values'], $dh_timeseries);
  $dh_timeseries->save();
  $url = 'admin/content/dh_timeseries/';
  $parms = drupal_get_query_parameters();
  if (isset($parms['finaldest'])) {
    $url = $parms['finaldest'];
    //$form_state['redirect'] = $url;
  } else {
    if (isset($parms['destination'])) {
      $url = drupal_get_destination();
      unset($_GET['destination']);
      //$form_state['redirect'] = $url;
    }
  }
  $form_state['redirect'] = $url;
}
function dh_timeseries_form_submit_delete(&$form, &$form_state) {
  $destination = array();
  $parms = drupal_get_query_parameters();
  if (isset($parms['finaldest'])) {
    $url = $parms['finaldest'];
    //$form_state['redirect'] = $url;
  }
  if (isset($_GET['destination'])) {
    $url = drupal_get_destination();
    unset($_GET['destination']);
    //$form_state['redirect'] = $url;
  }
  $form_state['redirect'] = 'admin/content/dh_timeseries/manage/' . $form_state['dh_timeseries']->tid . '/delete' . "&destination=$url";
}

/**
 * dH Variable Definition editing form.
 */

function dh_variabledefinition_form($form, &$form_state, $dh_variabledefinition, $op = 'edit') {
  if ($op == 'clone') {
    $dh_variabledefinition->name .= ' (cloned)';
    $dh_variabledefinition->bundle = '';
  }

/*  $form['hydroid'] = array(
    '#title' => t('Hydro ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->hydroid,
    '#description' => t('Primary key for Variables'),
    '#required' => TRUE,
    '#size' => 64,
  );*/

  $form['varname'] = array(
    '#title' => t('Variable Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->varname,
    '#description' => t('The name of the variable.'),
    '#required' => TRUE,
    '#size' => 64,
  );
  
  $form['vardesc'] = array(
    '#title' => t('Variable Description'),
    '#type' => 'textarea',
    '#default_value' => $dh_variabledefinition->vardesc,
    '#description' => t('The description of the variable.'),
    '#required' => TRUE,
    '#rows' => 3,
    '#cols' => 60,
  );
  
  $form['varabbrev'] = array(
    '#title' => t('Variable Abbreviation'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->varabbrev,
    '#description' => t('For use in compact displays.'),
    '#required' => FALSE,
    '#size' => 24,
  );
  ctools_include('plugins');
  $plugin_defs = ctools_get_plugins('dh', 'dh_variables');
  $plugins = array();
  foreach ($plugin_defs as $key => $def) {
    $plugins[$key] = $def['label'];
  }
  asort($plugins);
  $plugins = array('dHVariablePluginDefault'=>'Default Variable Plugin') + $plugins;
  $form['plugin'] = array(
    '#title' => t('Plugin'),
    '#type' => 'select',
    '#options' => $plugins,
    '#default_value' => empty($dh_variabledefinition->plugin) ? 'dHVariablePluginDefault' : $dh_variabledefinition->plugin,
    '#description' => t('Plugin to use for custom formatting for edit and display.'),
    '#required' => FALSE,
  );    
  
  $form['vocabulary'] = array(
    '#title' => t('Vocabulary'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->vocabulary,
    '#description' => t('Name of the list of variables in which a particular VarCode is defined (e.g., USGS NWIS).'),
    '#required' => TRUE,
    '#size' => 64,
  );    
  
  $form['varunits'] = array(
    '#title' => t('Variable Unit'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->varunits,
    '#description' => t('Units of measure for the variable.'),
    '#required' => TRUE,
    '#size' => 64,
  );   
  
  $form['varkey'] = array(
    '#title' => t('Variable Key'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->varkey,
    '#description' => t('Unique text ID for a variable, used when a variable is indexed in an attribute series table via field names.'),
    '#required' => TRUE,
    '#size' => 255,
  );
  // Note: this is a limite list of options for use only with automatic on update/save.
  //       there are a number of other options available for querying.  
  //       The 'all' option, however, should NEVER be allowed here.  it would effectively 
  //       render any entity with an "all" multiplicity variable for on update as the only ts/propcode
  //       that it could ever have until that ts/prop was deleted.
  $moptions = array(
    'default' => 'Default (None for timeseries, and Name for properties)',
    'none' => 'No Automatic Setting (properties will still be required to have a unique name)',
    'tstime_singular' => 'Start Time/Date + Varid (timeseries/properties) Singular',
    'tspan_singular' => 'Start and End Time/Date + Varid (exact time span) Singular',
    'trange' => 'Within Start and End Time/Date + Varid (anything inside of time span) Singular',
    'code_singular' => 'Code: Only 1 value allowed per tscode/propcode',
  );
  $form['multiplicity'] = array(
    '#title' => t('Multiplicity Setting'),
    '#type' => 'select',
    '#options' => $moptions,
    '#default_value' => $dh_variabledefinition->multiplicity,
    '#description' => t('Variable uniqueness, automatically enforced on update() and insert().  Default is varid+tstime for timeseries, and name for properties.'),
    '#required' => FALSE,
    "#empty_option"=> t('- None/Default -'),
  );   
  $form['datatype'] = array(
    '#title' => t('Data Type'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->datatype,
    '#description' => t('Describes whether the time series contains instantaneous measurements, cumulative values, etc.'),
    '#required' => TRUE,
    '#size' => 255,
  );   
      
  $form['data_entry'] = array(
    '#title' => t('Data Fields'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->data_entry,
    '#description' => t('Describes which form fields to show and their format, comma delimited options: numeric,text,boolean,index,date_start, date_end.'),
    '#required' => FALSE,
    '#size' => 255,
  );   
    
  $form['varcode'] = array(
    '#title' => t('Variable Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->varcode,
    '#description' => t('Public identifier for a variable (e.g., "00060" for discharge in USGS NWIS).'),
    '#required' => TRUE,
    '#size' => 255,
  );   
	
  $form['isregular'] = array(
    '#title' => t('Is Regular'),
    '#type' => 'radios',
	  '#options' => array( 1 => t("Yes"),0 => t("No")),
    '#default_value' => $dh_variabledefinition->isregular,
    '#description' => t('Integer field that stores 1 (TRUE) if the time series values are regularly spaced in time, or 0 (FALSE) if the time series is irregular.'),
    '#required' => TRUE,
  );   
    
  $form['timestep'] = array(
    '#title' => t('Time Step'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->timestep,
    '#description' => t('For regular time series, the number of TimeUnits between each occurrence of a time series value.'),
    '#required' => TRUE,
  );   
    	
  $form['timeunits'] = array(
    '#title' => t('Time Unit'),
    '#type' => 'textfield',
    '#default_value' => $dh_variabledefinition->timeunits,
    '#description' => t('For regular time series, the time unit used to describe the length of time between occurrences of a time series value.'),
    '#required' => TRUE,
    '#size' => 255,
  );   
    
  $form['nodataval'] = array(
    '#title' => t('No Data Value'),
    '#type' => 'radios',
	  '#options' => array( 1 => t("Yes"),0 => t("No")),
    '#default_value' => $dh_variabledefinition->nodataval,
    '#description' => t('Numerical value used to indicate a "No Data Value" (e.g., a missing value) in the time series table.'),
    '#required' => TRUE,
  );   
    					
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Variable Definition'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete Entry'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_variabledefinition_form_submit_delete')
  );
  return $form;
}

/* Form API submit callback for the type form.
 */
function dh_variabledefinition_form_submit(&$form, &$form_state) {
  $dh_variabledefinition = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_variabledefinition->save();
  $form_state['redirect'] = 'admin/content/dh_variabledefinition/';
}
function dh_variabledefinition_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/dh_variabledefinition/manage/' . $form_state['dh_variabledefinition']->hydroid . '/delete';
}



/**
 * dH Properties Type editing form.
 */
function dh_properties_type_form($form, &$form_state, $dh_properties_type, $op = 'edit') {

  if ($op == 'clone') {
    $dh_properties_type->name .= ' (cloned)';
    $dh_properties_type->bundle = '';
  }

  $form['name'] = array(
    '#title' => t('Property Type Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_properties_type->name,
    '#description' => t('The human-readable name of this Borehole type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	  '#type' => 'machine_name',
    '#default_value' => isset($dh_properties_type->bundle) ? $dh_properties_type->bundle : '',
    '#maxlength' => 32,
    //'disabled' => $dh_properties_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'dh_properties_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_properties_type->description,
    '#description' => t('Detailed description of this dH Property type.'),
    '#required' => FALSE,
    '#size' => 255,
  );
    
 // $form['data']['#tree'] = TRUE;


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );

  //Locking not supported yet
  ///*if (!$dh_properties_type->isLocked() && $op != 'add') {
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete Property type'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_properties_type_form_submit_delete')
  );
  //}*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function dh_properties_type_form_submit(&$form, &$form_state) {
  $dh_properties_type = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_properties_type->save();
  $form_state['redirect'] = 'admin/structure/dh_properties_type';
}

/**
 * Form API submit callback for the delete button.
 */
function dh_properties_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/dh_properties_type/manage/' . $form_state['dh_properties_type']->bundle . '/delete';
}



/**
 * dH Properties editing form.
 */

function dh_properties_form($form, &$form_state, $dh_properties, $op = 'edit') {
  if ($op == 'clone') {
    $dh_properties->name .= ' (cloned)';
    $dh_properties->bundle = ''; // @todo -- this must be killing trhe clone routine, no?
  }
  // tell it to add a revision entry
  $dh_properties->is_new_revision = TRUE;
  $p = drupal_get_query_parameters();
  // handle url vars
  $url_varid = isset($p['varid']) ? $p['varid'] : FALSE;
  $url_featureid = isset($p['featureid']) ? $p['featureid'] : FALSE;
  $url_entity_type = isset($p['entity_type']) ? $p['entity_type'] : FALSE;
  $dh_properties->varid = !$dh_properties->varid ? $url_varid : $dh_properties->varid;
  $dh_properties->featureid = !$dh_properties->featureid ? $url_featureid : $dh_properties->featureid;
  $dh_properties->entity_type = !$dh_properties->entity_type ? $url_entity_type : $dh_properties->entity_type;
  if ($dh_properties->varid) {
    $varinfo = dh_vardef_info($dh_properties->varid);
    $defname = $varinfo->varkey;
    $dh_properties->varid = $varinfo->hydroid;
  } else {
    $defname = NULL;
  }
  // apply create plugins if this is new
  if ($dh_properties->is_new or ($op == 'new')) {
    dh_variables_createRowPlugins($dh_properties);
  }
  $form['pid'] = array(
    '#type' => 'hidden',
    '#default_value' => $dh_properties->pid,
    '#size' => 8,
  );
  $form['propname'] = array(
    '#title' => t('Property Name'),
    '#type' => 'textfield',
    '#default_value' => empty($dh_properties->propname) ? $defname : $dh_properties->propname,
    '#description' => t('The name of this property (allows multiple to occur)'),
    '#required' => TRUE,
    '#size' => 64,
  );

  $form['propvalue'] = array(
    '#title' => t('Properties Value'),
    '#type' => 'textfield',
    '#default_value' => $dh_properties->propvalue,
    '#description' => t('The numerical value itself.'),
    '#required' => FALSE,
    '#size' => 64,
  );

  $form['propcode'] = array(
    '#title' => t('Property Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_properties->propcode,
    '#description' => t('Short Text Attribute.'),
    '#required' => FALSE,
    '#size' => 32,
  );

  // Machine-readable type name.
  
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	  '#type' => 'hidden',
    '#default_value' => !empty($dh_properties->bundle) ? $dh_properties->bundle : 'dh_properties',
    '#maxlength' => 32,
//    '#disabled' => $dh_feature_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'dh_properties_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $form['featureid'] = array(
    '#title' => t('Feature ID'),
    '#type' => 'textfield',
    '#default_value' => $dh_properties->featureid,
    '#description' => t('Unique numerical identifier of a feature within the geodatabase. Usually, the FeatureID of a TimeSeries record is equal to the HydroID of a feature (e.g., well, monitoring point).'),
    '#required' => TRUE,
    '#size' => 64,
  );
  $entities = entity_get_info();
  $form['entity_type'] = array(
    '#title' => t('Entity Type of Feature'),
    '#type' => 'select',
    '#options' => array_combine( array_keys($entities) , array_keys($entities) ),
    '#default_value' => (isset($dh_properties->entity_type) and ($dh_properties->entity_type <> '')) ? $dh_properties->entity_type : 'dh_feature',
    '#description' => t('Supports linkage to multiple entities (dh_Feature, dh_adminreg_feature, node, etc.).'),
    '#required' => TRUE,
    '#size' => 1,
  );
  
  $form['varid'] = array(
    '#title' => t('Variable ID'),
    '#type' => 'select',
    '#options' => dh_vardef_varselect_options(),
    '#default_value' => $dh_properties->varid,
    '#description' => t('Unique numerical identifier of a variable within the geodatabase. Variables are defined in the VariableDefinition table.'),
    '#required' => TRUE,
    //'#size' => 64,
  );
  $date_format = 'Y-m-d';
  $form['startdate'] = array(
    '#title' => t('Start/Issuance Date'),
    '#description' => t('Start/Issuance date for property enabled.'),
    '#required' => FALSE,
    '#default_value' => empty($dh_properties->startdate) ? NULL : date($date_format,$dh_properties->startdate),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-100:+5',
  );
  $form['enddate'] = array(
    '#title' => t('End/Expiration Date'),
    '#description' => t('End/Expiration date for property enabled.'),
    '#default_value' => empty($dh_properties->enddate) ? NULL : date($date_format,$dh_properties->enddate),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-100:+5',
    '#required' => FALSE,
  );
  
  field_attach_form('dh_properties', $dh_properties, $form, $form_state);
          
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete Entry'),
    '#weight' => 45,
    '#limit_validation_errors' => array(),
    '#submit' => array('dh_properties_form_submit_delete')
  );
  $map = array(
    'varid' => 'varid',
    'id' => 'pid',
    'value' => 'propvalue',
    'text' => 'proptext',
    'varname' => 'propvalue',
    'code' => 'propcode',
    'start' => 'startdate',
    'end' => 'enddate',
    'featureid' => 'featureid',
    'entity_type' => 'entity_type',
    'name' => 'propname',
  );
  //dpm($form,'after build called');
  // @todo - move this to the default plugin 
  dh_variable_set_form_visibility($form, $form_state, $map);
  //dpm($dh_properties,'object');
//dpm($form,'pre form');
  if (!$dh_properties->varid) {
    // new entities will not have settable vars in the URL processed yet, but we need this to add plugins
    // check the form got it's URL variables if passed in
    // @todo: check to see if we add this in a form hook so that this check is unneccessary and secure?
    if ($form['varid']['#value']) {
      $dh_properties->varid = $form['varid']['#value'];
    }
  }
  dh_variables_formRowPlugins($form, $dh_properties);
  return $form;
}

/* Form API submit callback for the type form.
 */
function dh_properties_form_submit(&$form, &$form_state) {
  $dh_properties = entity_ui_form_submit_build_entity($form, $form_state);
  dh_variables_formSubmitPlugins($form_state['values'], $dh_properties);
  //dpm($dh_properties,'final object to save');
  $dh_properties->save();
  //dpm($dh_properties,'final object post-save');
  $def_settings = isset($form_state['conf']) ? $form_state['conf'] : array();
  $conf = isset($form_state['values']['entity_settings']) ? $form_state['values']['entity_settings'] : $def_settings;
  $destination = ($conf['destination'] <> '') ? $conf['destination'] : 'admin/content/dh_properties/';
  $form_state['redirect'] = $destination;
}
function dh_properties_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/dh_properties/manage/' . $form_state['dh_properties']->pid . '/delete';
}

?>
