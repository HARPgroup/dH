<?php

/**
 * @file
 * Model editing UI.
 *
 */
 
/**
 * UI controllers
 */
 
//****************************
// dHAdminRegFeatureType
//****************************

class dHAdminRegFeatureTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Feature types, including adding
		and removing fields and the display of fields.';
    return $items;
  }

}

//****************************
// dHAdminRegFeature table
//****************************

class dHAdminRegFeatureUIController extends EntityDefaultUIController {
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
// dHAdminRegContact table
//****************************

class dHAdminRegContactTypeUIController extends EntityDefaultUIController {
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage dH Adminreg Contact types, including adding
		and removing fields and the display of fields.';
    return $items;
  }

}
class dHAdminRegContactUIController extends EntityDefaultUIController {
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

// Field formatting

function dh_adminreg_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'om_data_table-om_data_table-field_om_data_starttime'
  $field_instances['dh_adminreg_feature-startdate'] = array(
    'bundle' => 'dh_adminreg_feature',
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
    'entity_type' => 'dh_adminreg_feature',
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
  
  $field_instances['dh_adminreg_feature-enddate'] = $field_instances['dh_adminreg_feature-startdate'];
  $field_instances['dh_adminreg_feature-enddate']['field_name'] = 'enddate';
  $field_instances['dh_adminreg_feature-modified'] = $field_instances['dh_adminreg_feature-startdate'];
  $field_instances['dh_adminreg_feature-modified']['field_name'] = 'modified';
  // Translatables
  // Included for use with string extractors like potx.
  t('Start Time');
  $field_instances['dh_adminreg_feature-milestone-date_received'] = $field_instances['dh_adminreg_feature-startdate'];
  $field_instances['dh_adminreg_feature-milestone-date_received']['field_name'] = 'date_received';
  $field_instances['dh_adminreg_feature-date_received'] = $field_instances['dh_adminreg_feature-startdate'];
  $field_instances['dh_adminreg_feature-date_received']['field_name'] = 'date_received';

  return $field_instances;
}

// FORM Stuff

/**
 * dH Time Series editing form.
 */

/**
 * dH Feature Type editing form.
 */
function dh_adminreg_feature_type_form($form, &$form_state, $dh_adminreg_type, $op = 'edit') {

  if ($op == 'clone') {
    $dh_adminreg_type->name .= ' (cloned)';
    $dh_adminreg_type->bundle = '';
  }

  $form['name'] = array(
    '#title' => t('Admin Entity Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_type->name,
    '#description' => t('The human-readable name of this dH Feature type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	'#type' => 'machine_name',
    '#default_value' => isset($dh_adminreg_type->bundle) ? $dh_adminreg_type->bundle : '',
    '#maxlength' => 32,
//    '#disabled' => $dh_adminreg_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'dh_adminreg_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_type->description,
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
  /*if (!$dh_adminreg_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete model type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('dh_adminreg_type_form_submit_delete')
    );
  }*/
  return $form;
}
/**
 * Form API submit callback for the type form.
 */
function dh_adminreg_feature_type_form_submit(&$form, &$form_state) {
  $dh_feature_type = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_feature_type->save();
  $form_state['redirect'] = 'admin/structure/dh_adminreg_feature_type';
}

/**
 * dH AdminReg editing form.
 */
function dh_adminreg_feature_form($form, &$form_state, $dh_adminreg_feature, $op = 'edit') {

  if ($op == 'clone') {
    $dh_adminreg_feature->name .= ' (cloned)';
    $dh_adminreg_feature->bundle = '';
  }

  $form['admincode'] = array(
    '#title' => t('admincode'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_feature->admincode,
    '#description' => t('The unique identifier used by the originating agency of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 30,
  );
  // entity status
  $form['status'] = array(
    '#type' => 'hidden',
    '#default_value' => 1,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($dh_adminreg_feature->bundle) ? $dh_adminreg_feature->bundle : '',
    '#maxlength' => 32,
    #'#attributes' => array('disabled' => 'disabled'),
    //'#machine_name' => array(
    //  'exists' => 'dh_adminreg_feature_get_types',
   //   'source' => array('bundle'),
   // ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_feature->name,
    '#description' => t('Name'),
    '#required' => TRUE,
    '#size' => 30,
  );  
  $form['ftype'] = array(
    '#title' => t('FType'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_feature->ftype,
    '#description' => t('FType'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $fsopts = array(
    'unknown' => t('Unknown'),
    'active' => t('Active'),
    'application' => t('Application'),
    'preapplication' => t('Pre-Application'),
    'active' => t('Active'),
    'inactive' => t('Inactive'),
    'duplicate' => t('Duplicate'),
    'expired' => t('Expired'),
    'revoked' => t('Revoked'),
    'submitted' => t('Submitted'),
    'proposed' => t('Proposed'),
    'other' => t('Other'),
  );
  ksort($fsopts);
  $form['fstatus'] = array(
    '#title' => t('Status'),
    '#type' => 'select',
    '#default_value' => $dh_adminreg_feature->fstatus,
    '#options' => $fsopts,
    '#description' => t('Status'),
    '#required' => FALSE,
  );
  $date_format = 'Y-m-d';
  $form['startdate'] = array(
    '#title' => t('Start/Issuance Date'),
    '#description' => t('Start/Issuance date for administrative record.'),
    '#required' => FALSE,
    '#default_value' => empty($dh_adminreg_feature->startdate) ? $dh_adminreg_feature->startdate : date($date_format,$dh_adminreg_feature->startdate),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-30:+60',
  );
  $form['enddate'] = array(
    '#title' => t('End/Expiration Date'),
    '#description' => t('End/Expiration date for administrative record.'),
    '#required' => FALSE,
    '#default_value' => empty($dh_adminreg_feature->enddate) ? $dh_adminreg_feature->enddate : date($date_format,$dh_adminreg_feature->enddate),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-30:+60',
  );
  $form['modified'] = array(
    '#title' => t('Last Modified Date'),
    '#description' => t('Date of most recent edit of this record.'),
    '#required' => FALSE,
    '#default_value' => empty($dh_adminreg_feature->modified) ? $dh_adminreg_feature->modified : date($date_format,$dh_adminreg_feature->modified),
    '#date_format' => $date_format,
    '#type' => 'date_select',
    '#date_year_range' => '-30:+60',
  );

  field_attach_form('dh_adminreg_feature', $dh_adminreg_feature, $form, $form_state);
  
  unset($form['date_received']);
  
  $form['data']['#tree'] = TRUE;
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );

  return $form;
}


/* Form API submit callback for the type form.
 */
function dh_adminreg_feature_form_submit(&$form, &$form_state) {
  $dh_adminreg_feature = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_adminreg_feature->save();
  $form_state['redirect'] = 'admin/content/dh_adminreg_feature/';
}


/**
 * dH AR Contact Type editing form.
 */
function dh_adminreg_contact_type_form($form, &$form_state, $dh_adminreg_contact_type, $op = 'edit') {

  if ($op == 'clone') {
    $dh_adminreg_contact_type->name .= ' (cloned)';
    $dh_adminreg_contact_type->bundle = '';
  }

  $form['name'] = array(
    '#title' => t('Admin Entity Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact_type->name,
    '#description' => t('The human-readable name of this dH Feature type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	  '#type' => 'machine_name',
    '#default_value' => isset($dh_adminreg_contact_type->bundle) ? $dh_adminreg_contact_type->bundle : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'dh_adminreg_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact_type->description,
    '#description' => t('Detailed description of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 255,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH Feature type'),
    '#weight' => 40,
  );

  return $form;
}
/**
 * Form API submit callback for the type form.
 */
function dh_adminreg_contact_type_form_submit(&$form, &$form_state) {
  $dh_adminreg_contact_type = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_adminreg_contact_type->save();
  $form_state['redirect'] = 'admin/structure/dh_adminreg_contact_type';
}
/**
 * dH AdminReg editing form.
 */
function dh_adminreg_contact_form($form, &$form_state, $dh_adminreg_contact, $op = 'edit') {

  if ($op == 'clone') {
    $dh_adminreg_contact->name .= ' (cloned)';
    $dh_adminreg_contact->bundle = '';
  }

  $form['admincode'] = array(
    '#title' => t('admincode'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->admincode,
    '#description' => t('The unique identifier used by the originating agency of this dH Feature type.'),
    '#required' => FALSE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['bundle'] = array(
    '#title' => t('Bundle Name'),
	  '#type' => 'machine_name',
    '#default_value' => isset($dh_adminreg_contact->bundle) ? $dh_adminreg_contact->bundle : 'dh_adminreg_contact',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'dh_adminreg_feature_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  $form['ftype'] = array(
    '#title' => t('ftype'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->ftype,
    '#description' => t('Contact Type (primary, secondary, tertiary, emergency).'),
    '#required' => TRUE,
    '#size' => 30,
  );
  $form['prefix'] = array(
    '#title' => t('Prefix'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->prefix,
    '#description' => t('Prefix'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['suffix'] = array(
    '#title' => t('Suffix'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->suffix,
    '#description' => t('Suffix'),
    '#required' => FALSE,
    '#size' => 30,
  );      

  $form['name'] = array(
    '#title' => t('Full Name or Title'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->name,
    '#description' => t('Name'),
    '#required' => TRUE,
    '#size' => 30,
  );  
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => $dh_adminreg_contact->description,
    '#description' => t('Description'),
    '#required' => FALSE,
    '#cols' => 60,
    '#rows' => 5,
    '#maxlength' => null,
  );  
  $form['firstname'] = array(
    '#title' => t('First Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->firstname,
    '#description' => t('First Name'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['lastname'] = array(
    '#title' => t('Last Name'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->lastname,
    '#description' => t('Last Name'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['address1'] = array(
    '#title' => t('Address Line 1'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->address1,
    '#description' => t('Address Line 1'),
    '#required' => FALSE,
    '#size' => 64,
  );
  $form['address2'] = array(
    '#title' => t('Address Line 2'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->address2,
    '#description' => t('Address Line 2'),
    '#required' => FALSE,
    '#size' => 64,
  );  
  $form['city'] = array(
    '#title' => t('City'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->city,
    '#description' => t('City'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['state'] = array(
    '#title' => t('State'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->state,
    '#description' => t('State'),
    '#required' => FALSE,
    '#size' => 8,
  );  
  $form['postal_code'] = array(
    '#title' => t('Zip/Postal Code'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->postal_code,
    '#description' => t('Zip/Postal Code'),
    '#required' => FALSE,
    '#size' => 16,
  );  
  $form['phone'] = array(
    '#title' => t('Phone'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->phone,
    '#description' => t('Phone'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['email'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->email,
    '#description' => t('Email'),
    '#required' => FALSE,
    '#size' => 30,
  );  
  $form['uri'] = array(
    '#title' => t('Web Site'),
    '#type' => 'textfield',
    '#default_value' => $dh_adminreg_contact->uri,
    '#description' => t('Web Site'),
    '#required' => FALSE,
    '#size' => 64,
  );  
  
  field_attach_form('dh_adminreg_contact', $dh_adminreg_contact, $form, $form_state);
  
  $form['data']['#tree'] = TRUE;
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save dH Contact type'),
    '#weight' => 40,
  );

  return $form;
}


/* Form API submit callback for the type form.
 */
function dh_adminreg_contact_form_submit(&$form, &$form_state) {
  $dh_adminreg_contact = entity_ui_form_submit_build_entity($form, $form_state);
  $dh_adminreg_contact->save();
  $form_state['redirect'] = 'admin/content/dh_adminreg_contact/';
}

?>
