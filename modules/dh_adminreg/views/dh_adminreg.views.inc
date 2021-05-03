<?php

// Implements hook_view_data_alter().

  // comment out "return $data;" if using alter mode
//function dh_adminreg_views_data() {
//  $all_data = entity_views_data();
//  dpm($all_data, 'entity_views_data');
//  $data['dh_adminreg_feature'] = $all_data['entity_dh_adminreg_feature'];
//  $data['dh_adminreg_contact'] = $all_data['entity_dh_adminreg_contact'];
//  // do date setups
function dh_adminreg_views_data_alter(&$data) {
  $defaults_date = array(
    'field' => array(
      'handler' => 'dh_views_handler_field_date_extended',
      'click sortable' => TRUE,
      'is date' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
      'is date' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'is date' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'is date' => TRUE,
    ),
  );
   $defaults_numeric = array(
      'title' => t('Numeric Field'),
      'help' => t('Numeric Field.'), // The help that appears on the UI,
      'argument' => array(
         'handler' => 'views_handler_argument_numeric',
      ),
      'field' => array(
         'handler' => 'views_handler_field_numeric',
         'click sortable' => TRUE,
			'float' => TRUE, // enables advanced formatting options
      ),
      'filter' => array(
         'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
         'handler' => 'views_handler_sort',
      )
   );
   $defaults_string = array(
      'title' => t('String Field'),
      'help' => t('String Field.'), // The help that appears on the UI,
      'argument' => array(
         'handler' => 'views_handler_argument_string',
      ),
      'field' => array(
         'handler' => 'views_handler_field',
         'click sortable' => TRUE,
      ),
      'filter' => array(
         'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
         'handler' => 'views_handler_sort',
      )
   );
   
  // date fields:
  $datecols = array('startdate', 'enddate', 'date_received', 'modified');
  foreach ($datecols as $thiscol) {
    $data['dh_adminreg_feature'][$thiscol]['title'] = $thiscol;
    $data['dh_adminreg_feature'][$thiscol]['field'] = $defaults_date['field'];
    $data['dh_adminreg_feature'][$thiscol]['sort'] = $defaults_date['sort'];
    $data['dh_adminreg_feature'][$thiscol]['filter'] = $defaults_date['filter'];
    //$data['dh_adminreg_feature'][$thiscol]['argument'] = $defaults_date['argument'];
    // create link to date_tools_calendar if it exists
    // this will not be necessary once we move dh views info from hook_views_data() to hook_views_data_alter()
    // use $dtc_rel to avoid the long ass name
    $dtc_rel = array(
      'real field' => 'adminid',
      'relationship' => array(
        'title' => 'All Dates Link to ' . 'dh_adminreg_feature' . ' ' . $thiscol,
        'help' => 'Will join ' . 'dh_adminreg_feature' . ':' . $thiscol . ' to date_tools_calendar:ts',
        'handler' => 'views_handler_relationship',
        'label' => t('Date: Link ' . 'dh_adminreg_feature' . ':' . $thiscol . ' to date table.'),
        'left_table' => 'date_tools_calendar',
        'field' => 'ts',
        'base' => 'dh_adminreg_feature',
        'base field' => $thiscol,
        'operator' => '<=',
        'join_handler' => 'date_views_join',
      )
    );
    if (!isset($dtc_rel['extra'])) { 
      $dtc_rel['relationship']['extra'] = array();
    }
    $dtc_rel['relationship']['extra'][] = array(
      //'table' => 'dh_adminreg_feature', 
      'field' => $thiscol, 
      'left_table' => 'date_tools_calendar', 
      'left_field' => 'ts + 86400', 
      'operator' => '<',
    );
    $data['date_tools_calendar']['date_link_' . 'dh_adminreg_feature' . '_' . $thiscol] = $dtc_rel;
  }
  // @todo: subclass the basic string filter to include ON clause
// instead of maintaining patched version of string filter
  //$data['dh_adminreg_feature']['ftype']['filter']['handler'] = 'views_handler_filter_string_on';
  $data['dh_adminreg_feature']['bundle']['filter']['handler'] = 'views_handler_filter_in_operator_on';
  
  // TimeSeries data connections
	// join tsdata to dh_adminreg
	$data['dh_adminreg_feature']['table']['join']['dh_timeseries'] = array(
    'left_table' => 'dh_timeseries',
    'left_field' => 'featureid',
    'extra' => array(
      'field' => 'entity_type', 
      'value' => 'dh_adminreg_feature'
    )
  );
	// join properties to dh_adminreg
	$data['dh_adminreg_feature']['table']['join']['dh_properties'] = array(
    'left_table' => 'dh_properties',
    'left_field' => 'featureid',
    'field' => 'adminid'
	);
  // *************************************************
  // LINKING VARIABLE DEFINITION to AdminReg Features
  // Must take different routes for TS and Props
	// tells variabledefinition that it has a linkage path to dh_adminreg THRU dh_timeseries 
  /*
	$data['dh_variabledefinition']['table']['join']['dh_adminreg_feature'] = array(
	 'left_table' => 'dh_timeseries',
	 'left_field' => 'varid',
	 'field' => 'hydroid'
	);
	// tells adminreg that it has a linkage path to variabledefinition THRU dh_properties 
	$data['dh_variabledefinition']['table']['join']['dh_adminreg_feature'] = array(
	 'left_table' => 'dh_timeseries',
	 'left_field' => 'varid',
	 'field' => 'hydroid'
	);
  */
  // END - LINK VARIABLE DEFINITION to AdminReg Features
  // *************************************************
  
	// join dh_adminreg to TimeSeries
	$data['dh_timeseries']['table']['join']['dh_adminreg_feature'] = array(
	 'left_field' => 'adminid',
	 'field' => 'featureid'
	);
  $data['field_data_tstext']['table']['join']['dh_adminreg_feature'] = array(
    'left_table' => 'dh_timeseries',
    'left_field' => 'tid',
    'field' => 'entity_id',
  );	
  
	// join Property to dH_adminreg_feature 
  $data['dh_properties']['table']['join']['dh_adminreg_feature'] = array(
    'left_table' => 'dh_adminreg_feature',
    'left_field' => 'adminid',
    'field' => 'featureid'
  );
  
  // dha feature vars
  $q = "  drop view dha_feature_vars ";
  db_query($q);
  $q = "  create or replace view dha_feature_vars as ";
  $q .= " select a.hydroid as varid, a.varkey as varkey, a.varname, ";
  $q .= " a.vocabulary as vocabulary, a.vardesc, b.adminid as featureid ";
  $q .= " from dh_variabledefinition as a ";
  $q .= " CROSS JOIN dh_adminreg_feature as b ";
  db_query($q);
 
  // dh_variabledefinition to dh_feature extra join
  $data['dha_feature_vars']['table'] = array(
    'group' => 'dH AdminReg Feature',
    'title' => t('All dHA Feature:Variable Combos'),
    'help' => t('All dHA Feature:Variable Combos.')
  );
	// join to var def
  $data['dha_feature_vars']['varid'] = $defaults_numeric;
  $data['dha_feature_vars']['varid']['title'] = 'dHA Feature-Vars Variable ID';
  $data['dha_feature_vars']['varid']['help'] = 'dHA Feature-Vars Variable ID';
  $data['dha_feature_vars']['featureid'] = $defaults_numeric;
  $data['dha_feature_vars']['featureid']['title'] = 'dHA Feature-Vars AdminReg Feature ID';
  $data['dha_feature_vars']['featureid']['help'] = 'dHA Feature-Vars AdminReg Feature ID';
  $data['dha_feature_vars']['varkey'] = $defaults_string;
  $data['dha_feature_vars']['varkey']['title'] = 'dHA Feature-Vars VarKey';
  $data['dha_feature_vars']['varkey']['help'] = 'dHA Feature-Vars VarKey';
  $data['dha_feature_vars']['varname'] = $defaults_string;
  $data['dha_feature_vars']['varname']['title'] = 'dHA Feature-Vars Variable Name';
  $data['dha_feature_vars']['varname']['help'] = 'dHA Feature-Vars Variable name';
  $data['dha_feature_vars']['varname']['filter']['handler'] = 'views_handler_filter_in_operator';
  $data['dha_feature_vars']['varname']['filter']['options callback'] = 'dh_vardef_varname_options';
  $data['dha_feature_vars']['vardesc'] = $defaults_string;
  $data['dha_feature_vars']['vardesc']['title'] = 'dHA Feature-Vars Description';
  $data['dha_feature_vars']['vardesc']['help'] = 'dHA Feature-Vars Description';
  $data['dha_feature_vars']['vocabulary'] = $defaults_string;
  $data['dha_feature_vars']['vocabulary']['title'] = 'dHA Feature-Vars Vocabulary';
  $data['dha_feature_vars']['vocabulary']['help'] = 'dHA Feature-Vars Vocabulary';
  $data['dha_feature_vars']['table']['join']['dh_variabledefinition'] = array(
    'left_table' => 'dh_variabledefinition',
    'left_field' => 'hydroid',
    'field' => 'varid'
  );
  $data['dha_feature_vars']['varidid']['real field'] = 'varid';
  //$data['dha_feature_vars']['varidid']['group'] = $data['dha_feature_vars']['varid']['group'];
  $data['dha_feature_vars']['varidid']['title'] = $data['dha_feature_vars']['varid']['title'] . " (selector)";
  $data['dha_feature_vars']['varidid']['help'] = $data['dha_feature_vars']['varid']['title'] . " (selector)";
  $data['dha_feature_vars']['varidid']['filter'] = array(
    'label' => "AdminReg FeatureVars Variable Name/Key (selector)",
    //'handler' => 'dh_views_handler_filter_in_operator_on',
    'handler' => 'views_handler_filter_dh_propvarkey',
    'options callback' => 'dh_vardef_varselect_options',
  );
	// join to dHA AdminReg Features
   $data['dha_feature_vars']['table']['join']['dh_adminreg_feature'] = array(
     'left_table' => 'dh_adminreg_feature',
     'left_field' => 'adminid',
     'field' => 'featureid'
   );
  $data['dha_feature_vars']['ts_feature_vardef']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'label' => t('TimeSeries, Feature and VarDef Combo'),
    'base' => 'dh_timeseries',
    'base field' => 'featureid',
    'relationship field' => 'featureid',
    'extra' => array(
      0 => array('left_table' => 'dha_feature_vars', 'field' => 'varid', 'left_field' => 'varid') 
    ),
  );
  $data['dha_feature_vars']['prop_feature_vardef']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'label' => t('dH Properties, Feature and VarDef Combo'),
    'base' => 'dh_properties',
    'base field' => 'featureid',
    'relationship field' => 'featureid',
    'extra' => array(
      0 => array('left_table' => 'dha_feature_vars', 'field' => 'varid', 'left_field' => 'varid') 
    ),
  );
  // only use this if we are using hook_views_data() not hook_views_data_alter()
  //return $data;
}

 