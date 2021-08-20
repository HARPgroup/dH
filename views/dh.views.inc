<?php

/**
 * Implements hook_views_handlers().
 */
function dh_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'dh') . '/views',
    ),
    'handlers' => array(
      'dh_views_handler_field_date_extended' => array(
        'parent' => 'views_handler_field_date',
      ),
      'dh_views_handler_argument_tsvalue' => array(
        'parent' => 'views_handler_argument',
      ),
      'views_handler_filter_in_operator_on' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'dh_views_handler_filter_in_operator_on' => array(
        'parent' => 'views_handler_filter_in_operator_on',
      ),
    ),
  );
}


/**
 * Implements hook_views_data_alter().
 */
//function dh_views_data() {
//  $all_data = entity_views_data();
//  $data['dh_feature'] = $all_data['entity_dh_feature'];
//  $data['dh_properties'] = $all_data['entity_dh_properties'];
//  $data['dh_timeseries'] = $all_data['entity_dh_timeseries'];
//  $data['dh_boreholelog'] = $all_data['entity_dh_boreholelog'];
//  $data['dh_hydrogeologicunit'] = $all_data['entity_dh_hydrogeologicunit'];
function dh_views_data_alter(&$data) {
  // comment out "return $data;" if using alter mode
  // do date setups
  $defaults_date = array(
    'field' => array(
    'handler' => 'dh_views_handler_field_date_extended',
    'click sortable' => TRUE,
    ),
    'sort' => array(
    'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
    'handler' => 'views_handler_filter_date',
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
  // Add editable field for hydrocode.
  //error_log("Data entries: " . print_r($data['dh_feature'],1));
  // this is now done in the module code
  /*
  $feature_fields = array('ftype', 'hydrocode', 'name', 'fstatus');
  foreach ($feature_fields as $thisfield) {
		$editname = 'editable_' . $thisfield;
	   $data['dh_feature'][$editname] = array(
		  'title' => $data['dh_feature'][$thisfield]['title'] . ' ' . t('(editable)'),
		  'help'  => $data['dh_feature'][$thisfield]['help'],
	   );
	  $data['dh_feature'][$editname]['field'] = $data['dh_feature'][$thisfield]['field'];
	  $data['dh_feature'][$editname]['field']['handler'] = 'dh_editableviews_handler_dh_feature';
	  // This is needed by insert_form_elements(). Outside of FieldAPI fields, this
	  // is simply the key of the element that our handler adds to the form.
	  $data['dh_feature'][$editname]['field']['field_name'] = $thisfield;
	}
  */
  $data['dh_feature']['bundle']['filter']['handler'] = 'views_handler_filter_in_operator_on';
  $data['dh_feature']['fstatus']['filter']['handler'] = 'views_handler_filter_dh_fstatus';
  $retitle_fields = array(
    'dh_feature' => array(
      'hydroid' => 'HydroID - Unique Feature ID', 
      'name' => 'Feature Name'
    ),
    'dh_variabledefinition' => array(
      'hydroid' => 'HydroID - Unique Feature ID (VarID in Time Series)', 
      'varname' => 'Variable Name',
      'varkey' => 'Variable Key (may be short name or = varname)'
    ),
    'dh_properties' => array(
      'propname' => 'Property Name'
    ),
  );
  foreach ($retitle_fields as $class => $fields) {
    foreach ($fields as $fname => $title) {
      $data[$class][$fname]['title'] = $title;
    }
  }
  $boreholelog_fields = array('fromdepth', 'todepth', 'ftype', 'diameter');
  foreach ($boreholelog_fields as $thisfield) {
		$editname = 'editable_' . $thisfield;
	   $data['dh_boreholelog'][$editname] = array(
		  'title' => $data['dh_boreholelog'][$thisfield]['title'] . ' ' . t('(editable)'),
		  'help'  => isset($data['dh_boreholelog'][$thisfield]['help']) ? $data['dh_boreholelog'][$thisfield]['help'] : $thisfield,
	   );
	  $data['dh_boreholelog'][$editname]['field'] = $data['dh_boreholelog'][$thisfield]['field'];
	  $data['dh_boreholelog'][$editname]['field']['handler'] = 'dh_editableviews_handler_dh_feature';
	  // This is needed by insert_form_elements(). Outside of FieldAPI fields, this
	  // is simply the key of the element that our handler adds to the form.
	  $data['dh_boreholelog'][$editname]['field']['field_name'] = $thisfield;
	}
  // editable field for variabledefinition
  
  /*
  $variabledefinition_fields = array('varname', 'varkey', 'varcode', 'vocabulary', 'varunits', 'datatype', 'data_entry');
  foreach ($variabledefinition_fields as $thisfield) {
		$editname = 'editable_' . $thisfield;
	   $data['dh_variabledefinition'][$editname] = array(
		  'title' => $data['dh_variabledefinition'][$thisfield]['title'] . ' ' . t('(editable)'),
		  'help'  => isset($data['dh_variabledefinition'][$thisfield]['help']) ? $data['dh_variabledefinition'][$thisfield]['help'] : $thisfield,
	   );
	  $data['dh_variabledefinition'][$editname]['field'] = $data['dh_variabledefinition'][$thisfield]['field'];
	  $data['dh_variabledefinition'][$editname]['field']['handler'] = 'dh_editableviews_handler_dh_feature';
	  // This is needed by insert_form_elements(). Outside of FieldAPI fields, this
	  // is simply the key of the element that our handler adds to the form.
	  $data['dh_variabledefinition'][$editname]['field']['field_name'] = $thisfield;
	}
	*/
	
	// do date setups
   $datecols = array('tstime', 'tsendtime', 'modified');
   foreach ($datecols as $thiscol) {
      $data['dh_timeseries'][$thiscol]['title'] = $thiscol;
      $data['dh_timeseries'][$thiscol]['field'] = $defaults_date['field'];
      $data['dh_timeseries'][$thiscol]['sort'] = $defaults_date['sort'];
      $data['dh_timeseries'][$thiscol]['filter'] = $defaults_date['filter'];
   }
   // @todo: allow plugin rendering of individual property fields on ts/prop entity
   //$data['dh_timeseries']['tsvalue']['field']['handler'] = 'views_handler_field_dh_pluggable_numeric';
   // Over-ride the default setting for Views renderer
   $data['views_entity_dh_timeseries']['rendered_entity']['field']['handler'] = 'dh_timeseries_views_handler_field_entity';
   $data['views_entity_dh_properties']['rendered_entity']['field']['handler'] = 'dh_timeseries_views_handler_field_entity';
/*   
  // commented out in favor of using the existing Editable Views plumbing via meta-data
  // as defined in hook_entity_property_info_alter
  $ts_editable_fields = array('tsvalue', 'tstime');
  foreach ($ts_editable_fields as $thisfield) {
		$editname = 'editable_' . $thisfield;
	   $data['dh_timeseries'][$editname] = array(
		  'title' => $data['dh_timeseries'][$thisfield]['title'] . ' ' . t('(editable)'),
		  'help'  => isset($data['dh_timeseries'][$thisfield]['help']) ? $data['dh_timeseries'][$thisfield]['help'] : $thisfield,
	   );
	  $data['dh_timeseries'][$editname]['field'] = $data['dh_timeseries'][$thisfield]['field'];
	  $data['dh_timeseries'][$editname]['field']['handler'] = 'dh_editableviews_handler_dh_feature';
	  // This is needed by insert_form_elements(). Outside of FieldAPI fields, this
	  // is simply the key of the element that our handler adds to the form.
	  $data['dh_timeseries'][$editname]['field']['field_name'] = $thisfield;
	}
*/	
	// join var def to tsdata
   $data['dh_timeseries']['table']['join']['dh_variabledefinition'] = array(
     'left_table' => 'dh_variabledefinition',
     'left_field' => 'hydroid',
     'field' => 'varid'
   );
  // special filter that uses a select widget
  // and preserves reverse compatibility
  $data['dh_timeseries']['hydroid'] = array();
  $data['dh_timeseries']['varidid']['real field'] = 'varid';
  //$data['dh_timeseries']['varidid']['group'] = $data['dh_timeseries']['varid']['group'];
  $data['dh_timeseries']['varidid']['title'] = $data['dh_timeseries']['varid']['title'] . " (selector)";
  $data['dh_timeseries']['varidid']['help'] = $data['dh_timeseries']['varid']['title'] . " (selector)";
  $data['dh_timeseries']['varidid']['filter'] = array(
    'label' => "TS Variable Name/Key (selector)",
    //'handler' => 'dh_views_handler_filter_in_operator_on',
    'handler' => 'views_handler_filter_dh_propvarkey',
    'options callback' => 'dh_vardef_varselect_options',
  );
	
  // TimeSeries data connections
	// join tsdata to var def 
   $data['dh_variabledefinition']['table']['join']['dh_timeseries'] = array(
     'left_table' => 'dh_timeseries',
     'left_field' => 'varid',
     'field' => 'hydroid'
   );
	// join tsdata to dH_feature
  $data['dh_feature']['table']['join']['dh_timeseries'] = array(
    'left_table' => 'dh_timeseries',
    'left_field' => 'featureid',
    'field' => 'hydroid'
  );
  // support date_tools
  module_load_include('module', 'date_tools');
  if (function_exists('date_tools_link_date_field_ts')) {
    date_tools_link_date_field_ts($data, 'dh_timeseries', 'tstime', 'tstime', 'ts');
  }
  $data['dh_variabledefinition']['varname']['filter']['handler'] = 'views_handler_filter_in_operator_on';
  $data['dh_variabledefinition']['varname']['filter']['options callback'] = 'dh_vardef_varname_options';
  $data['dh_variabledefinition']['vocabulary']['filter']['handler'] = 'views_handler_filter_in_operator_on';
  $data['dh_variabledefinition']['vocabulary']['filter']['options callback'] = 'dh_vardef_vocab_options';
  
  // special filters that use a select widget
  // and preserves reverse compatibility
  $data['dh_variabledefinition']['varidid'] = array();
  $data['dh_variabledefinition']['varidid']['real field'] = 'hydroid';
  //$data['dh_variabledefinition']['varidid']['group'] = $data['dh_variabledefinition']['hydroid']['group'];
  $data['dh_variabledefinition']['varidid']['title'] = $data['dh_variabledefinition']['hydroid']['title'] . " (selector)";
  $data['dh_variabledefinition']['varidid']['help'] = $data['dh_variabledefinition']['hydroid']['title'] . " (selector)";
  $data['dh_variabledefinition']['varidid']['filter'] = array(
    'label' =>  "Vardef Variable Name/Key (selector)",
    'handler' => 'dh_views_handler_filter_in_operator_on',
    'options callback' => 'dh_vardef_varselect_options',
  );
  $data['dh_variabledefinition']['varkeykey'] = array();
  $data['dh_variabledefinition']['varkeykey']['real field'] = 'varkey';
  //$data['dh_variabledefinition']['varkeykey']['group'] = $data['dh_variabledefinition']['varkey']['group'];
  $data['dh_variabledefinition']['varkeykey']['title'] = $data['dh_variabledefinition']['varkey']['title'] . " (selector)";
  $data['dh_variabledefinition']['varkeykey']['help'] = $data['dh_variabledefinition']['varkey']['title'] . " (selector)";
  $data['dh_variabledefinition']['varkeykey']['filter'] = array(
    'label' =>  "Vardef Variable Key (selector)",
    'handler' => 'views_handler_filter_dh_varkey',
    'options callback' => 'dh_varkey_varselect_options',
  );
  // LINKING FEATURES TO VARIABLES
  // APPROACH #1 - vardef to feature via props, and ts
  /*
	// tells variabledefinition that it has a linkage path to dh_feature THRU dh_timeseries 
   $data['dh_variabledefinition']['table']['join']['dh_feature'] = array(
     'left_table' => 'dh_timeseries',
     'left_field' => 'varid',
     'field' => 'hydroid'
   );
	// tells variabledefinition that it has a linkage path to dh_feature THRU dh_properties 
   $data['dh_variabledefinition']['table']['join']['dh_feature-ts'] = array(
     'table' => 'dh_feature',
     'left_table' => 'dh_properties',
     'left_field' => 'varid',
     'field' => 'hydroid'
   );
  */
  // APPROACH #2 - feature to vardef via props, ts
  /*
	// tells variabledefinition that it has a linkage path to dh_feature THRU dh_timeseries 
   $data['dh_feature']['table']['join']['dh_variabledefinition'] = array(
     'left_table' => 'dh_timeseries',
     'left_field' => 'featureid',
     'field' => 'hydroid'
   );
	// tells variabledefinition that it has a linkage path to dh_feature THRU dh_properties 
   $data['dh_variabledefinition']['table']['join']['dh_feature-ts'] = array(
     'table' => 'dh_feature',
     'left_table' => 'dh_properties',
     'left_field' => 'varid',
     'field' => 'hydroid'
   );
  */
  // APPROACH #3 - create a special explicitly added relationship from vardef to timeseries
  //               to be added as needed
  //$data['dh_timeseries']['ts_vardef'] = array(
  //  'title' => t('Explicitly Link TimeSeries to Vardef'),
  //  'help' => t('Explicitly Link TimeSeries to Vardef'),
  //  'relationship' => array(
  //    'handler' => 'views_handler_relationship',
  //    'label' => t('Include a link from TimeSeries to Vardef'),
  //    'base' => 'dh_variabledefinition',
  //    'base field' => 'hydroid',
  //    'relationship field' => 'varid',
  //  )
  //);
	// join dH_feature to TimeSeries
  // we should use http://deq2.bse.vt.edu/d.alpha/?q=help/views/api-tables
  // define a table as "possible base", which may help joining fields of secondary tables?
    // Advertise this table as a possible base table
    //  $data['node']['table']['base'] = array(
    //    'field' => 'nid',
    //    'title' => t('Node'),
    //    'help' => t("Nodes are a Drupal site's primary content."),
    //    'weight' => -10,
    //  );
  $data['dh_timeseries']['ts_feature'] = array(
    'title' => t('Explicitly Link TimeSeries to dH Feature'),
    'help' => t('Explicitly Link TimeSeries to dH Feature'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('Include a link from TimeSeries to dH Feature'),
      'base' => 'dh_feature',
      'base field' => 'hydroid',
      'relationship field' => 'featureid',
    )
  );

  // adjust dh_timeseries filters
  $data['dh_timeseries']['tscode']['filter']['allow empty'] = TRUE;

  // add capability for explicit joins from props to entities
  // this provides "cross-tab" functionality
  $e = entity_get_info();
  // for properties
  foreach ($e as $ename => $einfo) {
    $ebase = $einfo['base table'];
    $elabel = $einfo['label'];
    $eidcol = $einfo['entity keys']['id'];
    if ($eidcol) {
      // should go through and add a relationship for all entity types
      $data[$ebase]['crosstab_' . $ebase] = array(
        'real field' => 'adminid',
        'relationship' => array(
          'title' => $ebase . ' LEFT OUTER JOIN dH Properties',
          'help' => 'Links a dH Properties entry to base table ' . $ebase,
          'handler' => 'views_handler_relationship',
          'label' => t($elabel . ' LEFT OUTER JOIN dH Properties'),
          'base' => 'dh_properties',
          'base field' => 'featureid',
          'left_table' => $ebase,
          'field' => $eidcol,
        )
      );
      if (!isset($data[$ebase]['crosstab_' . $ebase]['relationship']['extra'])) { 
        $data[$ebase]['crosstab_' . $ebase]['relationship']['extra'] = array();
      }
      $data[$ebase]['crosstab_' . $ebase]['relationship']['extra'][] = array(
        'field' => 'entity_type', 
        'value' => $ename
      );
    }
  }
  
  // for timeseries
  foreach ($e as $ename => $einfo) {
    $ebase = $einfo['base table'];
    $elabel = $einfo['label'];
    $eidcol = $einfo['entity keys']['id'];
    if ($eidcol) {
      // should go through and add a relationship for all entity types
      $data[$ebase]['crossts_' . $ebase] = array(
        'real field' => 'adminid',
        'relationship' => array(
          'title' => $ebase . ' LEFT OUTER JOIN dH Timeseries',
          'help' => 'Links a dH Timeseries entry to base table ' . $ebase,
          'handler' => 'views_handler_relationship',
          'label' => t($elabel . ' LEFT OUTER JOIN dH Timeseries'),
          'base' => 'dh_timeseries',
          'base field' => 'featureid',
          'left_table' => $ebase,
          'field' => $eidcol,
        )
      );
      if (!isset($data[$ebase]['crossts_' . $ebase]['relationship']['extra'])) { 
        $data[$ebase]['crossts_' . $ebase]['relationship']['extra'] = array();
      }
      $data[$ebase]['crossts_' . $ebase]['relationship']['extra'][] = array(
        'field' => 'entity_type', 
        'value' => $ename
      );
    }
  }
  
  // Now add capability for explicit joins from entities to props and ts
  // this provides "cross-tab" functionality
  $e = entity_get_info();
  // for properties
  foreach ($e as $ename => $einfo) {
    $ebase = $einfo['base table'];
    $elabel = $einfo['label'];
    $eidcol = $einfo['entity keys']['id'];
    if ($eidcol and $ebase <> 'dh_timeseries' and $ebase <> 'dh_properties') {
      // tiemseries has already added a link to properties so no need
      // should go through and add a relationship for all entity types
      $data['dh_properties']['crosstab_' . $ebase] = array(
        'real field' => 'adminid',
        'relationship' => array(
          'title' => ' Link to dH Properties LEFT OUTER JOIN to ' . $ebase,
          'help' => 'dH Properties LEFT OUTER JOIN to ' . $ebase,
          'handler' => 'views_handler_relationship',
          'label' => t('dH Properties LEFT OUTER JOIN to ' . $elabel),
          'base' => $ebase,
          'base field' => $eidcol,
          'left_table' => 'dh_properties',
          'field' => 'featureid',
        )
      );
      if (!isset($data['dh_properties']['crosstab_' . $ebase]['relationship']['extra'])) { 
        $data['dh_properties']['crosstab_' . $ebase]['relationship']['extra'] = array();
      }
      $data['dh_properties']['crosstab_' . $ebase]['relationship']['extra'][] = array(
        'table' => 'dh_properties', 
        'field' => 'entity_type', 
        'value' => $ename
      );
    }
  }
  
  // for timeseries - enable other tables to be joined to timeseries as a base table
  foreach ($e as $ename => $einfo) {
    $ebase = $einfo['base table'];
    $elabel = $einfo['label'];
    $eidcol = $einfo['entity keys']['id'];
    if ($eidcol and $ebase <> 'dh_properties') {
      // properties has already added a link to TS so no need
      // should go through and add a relationship for all entity types
      $data['dh_timeseries']['crossts_' . $ebase] = array(
        'real field' => 'adminid',
        'relationship' => array(
          'title' => ' Link to dH Timeseries LEFT OUTER JOIN to ' . $ebase,
          'help' => 'dH Timeseries LEFT OUTER JOIN to ' . $ebase,
          'handler' => 'views_handler_relationship',
          'label' => t('dH Timeseries LEFT OUTER JOIN to ' . $elabel),
          'base' => $ebase,
          'base field' => $eidcol,
          'left_table' => 'dh_timeseries',
          'field' => 'featureid',
        )
      );
      if (!isset($data['dh_timeseries']['crossts_' . $ebase]['relationship']['extra'])) { 
        $data['dh_timeseries']['crossts_' . $ebase]['relationship']['extra'] = array();
      }
      $data['dh_timeseries']['crossts_' . $ebase]['relationship']['extra'][] = array(
//        'left_field' => 'entity_type',
// --- replaced with 
//        'table' => 'dh_timeseries',
//        'field' => 'entity_type',
        'table' => 'dh_timeseries', 
        'field' => 'entity_type', 
        'value' => $ename
      );
    }
  }
  
  
  // special vardef to props and ts 
  $e = entity_get_info();
  // for properties
  $vtabs = array('dh_properties', 'dh_timeseries');
  foreach ($vtabs as $ename) {
    $einfo = $e[$ename];
    $ebase = $einfo['base table'];
    $elabel = $einfo['label'];
    if ($eidcol) {
      // should go through and add a relationship for all entity types
      $data[$ebase]['vardef_' . $ebase] = array(
        'real field' => 'hydroid',
        'relationship' => array(
          'title' => 'Variable Definition for ' . $ebase,
          'help' => 'Joins the variable definition entry to ' . $ebase,
          'handler' => 'views_handler_relationship',
          'label' => t($elabel . ' Variable Definition'),
          'base' => 'dh_variabledefinition',
          'base field' => 'hydroid',
          'left_table' => $ebase,
          'field' => 'varid',
        )
      );
    }
  }

   // dh_properties basics
   $datecols = array('startdate', 'enddate');
   foreach ($datecols as $thiscol) {
      $data['dh_properties'][$thiscol]['field'] = $defaults_date['field'];
      $data['dh_properties'][$thiscol]['sort'] = $defaults_date['sort'];
      $data['dh_properties'][$thiscol]['filter'] = $defaults_date['filter'];
   }
   
  // dh_properties special adjustments
  $data['dh_properties']['propcode']['filter']['allow empty'] = TRUE;
  $data['dh_properties']['propcode']['filter'] = array(
    'label' =>  "dH Propcode Filter",
    'handler' => 'views_handler_filter_string',
    //'options callback' => 'dh_vardef_varselect_options',
  );

  // special filter that uses a select widget
  // and preserves reverse compatibility
  $data['dh_properties']['varidid'] = array();
  $data['dh_properties']['varidid']['real field'] = 'varid';
  //$data['dh_properties']['varidid']['group'] = $data['dh_properties']['varid']['group'];
  $data['dh_properties']['varidid']['title'] = $data['dh_properties']['varid']['title'] . " (selector)";
  $data['dh_properties']['varidid']['help'] = $data['dh_properties']['varid']['title'] . " (selector)";
  $data['dh_properties']['varidid']['filter'] = array(
    'label' =>  "dH Props Variable Name/Key (selector)",
    'handler' => 'views_handler_filter_dh_propvarkey',
    //'options callback' => 'dh_vardef_varselect_options',
  );
  
  // dh_timeseries special adjustments
  $data['dh_timeseries']['tscode']['filter']['allow empty'] = TRUE;
  $data['dh_timeseries']['tstime']['filter']['allow empty'] = TRUE;
  $data['dh_timeseries']['tsendtime']['filter']['allow empty'] = TRUE;
  
  $data['dh_timeseries']['table']['join']['dh_feature'] = array(
    'left_table' => 'dh_feature',
    'left_field' => 'hydroid',
    'field' => 'featureid'
  );   
  $data['field_data_tstext']['table']['join']['dh_feature'] = array(
    'left_table' => 'dh_timeseries',
    'left_field' => 'tid',
    'field' => 'entity_id',
    'extra' => array(
      0 => array('right_table' => 'field_data_tstext', 'field' => 'entity_type', 'value' => 'dh_timeseries') 
    ),
  );	
	
  // dh_Properties data connections
	// join properties to var def 
   $data['dh_variabledefinition']['table']['join']['dh_properties'] = array(
     'left_table' => 'dh_properties',
     'left_field' => 'varid',
     'field' => 'hydroid'
   );
	// join property table to dH_feature
   $data['dh_feature']['table']['join']['dh_properties'] = array(
     'left_table' => 'dh_properties',
     'left_field' => 'featureid',
     'field' => 'hydroid'
   );
   // dH Properties Views setup
	// join properties to var def
  $data['dh_properties']['table']['join']['dh_variabledefinition'] = array(
    'left_table' => 'dh_variabledefinition',
    'left_field' => 'hydroid',
    'field' => 'varid'
  );
	// join Property to dH_feature 
   $data['dh_properties']['table']['join']['dh_feature'] = array(
     'left_table' => 'dh_feature',
     'left_field' => 'hydroid',
     'field' => 'featureid'
   );
  
  // dh feature vars - creates a matrix of features and variables for use 
  // in present/absent tables
  $q = "  create or replace view view_dh_proptext as ";
  $q .= " select a.pid, a.varid, a.featureid, b.proptext_value ";
  $q .= " from dh_properties as a ";
  $q .= " LEFT OUTER JOIN field_data_proptext as b ";
  $q .= " on (a.pid = b.entity_id and b.entity_type = 'dh_properties') ";
  db_query($q);
 
  // dh_variabledefinition to dh_feature extra join
  $data['view_dh_proptext']['table'] = array(
    'group' => 'DH Properties',
    'title' => t('PropText: View dH Property Text Field'),
    'help' => t('PropText: View dH Property Text Field.')
  );
	// Format Text Field Display
   $data['view_dh_proptext']['proptext_value'] = $defaults_string;
   $data['view_dh_proptext']['proptext_value']['title'] = 'PropText: View dH Property Text Field';
   $data['view_dh_proptext']['proptext_value']['help'] = 'PropText: View dH Property Text Field';
	// Format pid Field Display
   $data['view_dh_proptext']['pid'] = $defaults_numeric;
   $data['view_dh_proptext']['pid']['title'] = 'PropText PID: View dH Property Text pid Field';
   $data['view_dh_proptext']['pid']['help'] = 'PropText PID: View dH Property Text pid Field';
	// Format varid Field Display
   $data['view_dh_proptext']['varid'] = $defaults_numeric;
   $data['view_dh_proptext']['varid']['title'] = 'PropText VARID: View dH Property Text varid Field';
   $data['view_dh_proptext']['varid']['help'] = 'PropText VARID: View dH Property Text varid Field';
	// join properties to var def
  $data['view_dh_proptext']['table']['join']['dh_variabledefinition'] = array(
    'left_table' => 'dh_variabledefinition',
    'left_field' => 'hydroid',
    'field' => 'varid'
  );
  $data['view_dh_proptext']['table']['join']['dh_properties'] = array(
    'left_table' => 'dh_properties',
    'left_field' => 'pid',
    'field' => 'pid',
    'extra' => array(
      0 => array('left_table' => 'dh_properties', 'field' => 'varid', 'left_field' => 'varid') ,
      1 => array('left_table' => 'dh_properties', 'field' => 'featureid', 'left_field' => 'featureid') 
    ),
  );
	// join Property to dH_feature 
   $data['view_dh_proptext']['table']['join']['dh_feature'] = array(
     'left_table' => 'dh_feature',
     'left_field' => 'hydroid',
     'field' => 'featureid'
   );
  
  // dH BoreholeLog Views Setup
	// join boreholelog to HGU table
   $data['dh_boreholelog']['table']['join']['dh_hydrogeologicunit'] = array(
     'left_table' => 'dh_hydrogeologicunit',
     'left_field' => 'hydroid',
     'field' => 'hguid'
   );
	
	// join HGU to boreholelog table
   $data['dh_hydrogeologicunit']['table']['join']['dh_boreholelog'] = array(
     'left_table' => 'dh_boreholelog',
     'left_field' => 'hguid',
     'field' => 'hydroid'
   );

  // dh feature vars - creates a matrix of features and variables for use 
  // in present/absent tables
  if (db_table_exists('dh_feature_vars')) {
    $q = "  drop view dh_feature_vars ";
    db_query($q);
  }
  $q = "  create or replace view dh_feature_vars as ";
  $q .= " select a.hydroid as varid, a.varkey as varkey, ";
  $q .= " a.vocabulary as vocabulary, a.vardesc, b.hydroid as featureid ";
  $q .= " from dh_variabledefinition as a ";
  $q .= " CROSS JOIN dh_feature as b ";
  db_query($q);
 
  // dh_variabledefinition to dh_feature extra join
  $data['dh_feature_vars']['table'] = array(
    'group' => 'dH Feature',
    'title' => t('All dH Feature:Variable Combos'),
    'help' => t('All dH Feature:Variable Combos.')
  );
	// join to var def
   $data['dh_feature_vars']['varid'] = $defaults_numeric;
   $data['dh_feature_vars']['varid']['title'] = 'dH Feature-Vars Variable ID';
   $data['dh_feature_vars']['varid']['help'] = 'dH Feature-Vars Variable ID';
   $data['dh_feature_vars']['featureid'] = $defaults_numeric;
   $data['dh_feature_vars']['featureid']['title'] = 'dH Feature-Vars Feature ID';
   $data['dh_feature_vars']['featureid']['help'] = 'dH Feature-Vars Feature ID';
   $data['dh_feature_vars']['varkey'] = $defaults_string;
   $data['dh_feature_vars']['varkey']['title'] = 'dH Feature-Vars VarKey';
   $data['dh_feature_vars']['varkey']['help'] = 'dH Feature-Vars VarKey';
   $data['dh_feature_vars']['vardesc'] = $defaults_string;
   $data['dh_feature_vars']['vardesc']['title'] = 'dH Feature-Vars Description';
   $data['dh_feature_vars']['vardesc']['help'] = 'dH Feature-Vars Description';
   $data['dh_feature_vars']['vocabulary'] = $defaults_string;
   $data['dh_feature_vars']['vocabulary']['title'] = 'dH Feature-Vars Vocabulary';
   $data['dh_feature_vars']['vocabulary']['help'] = 'dH Feature-Vars Vocabulary';
   // is this an error? I think it should be "table" not "vocabulary" here
   //$data['dh_feature_vars']['vocabulary']['join']['dh_variabledefinition'] = array(
   $data['dh_feature_vars']['table']['join']['dh_variabledefinition'] = array(
     'left_table' => 'dh_variabledefinition',
     'left_field' => 'hydroid',
     'field' => 'varid'
   );
	// join to dH AdminReg Features
   $data['dh_feature_vars']['table']['join']['dh_feature'] = array(
     'left_table' => 'dh_feature',
     'left_field' => 'hydroid',
     'field' => 'featureid'
   );
  $data['dh_feature_vars']['ts_feature_vardef'] = array(
    'title' => t('Link to Matrix of TimeSeries, Feature and VarDef Combo'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('TimeSeries, Feature and VarDef Combo'),
      'base' => 'dh_timeseries',
      'base field' => 'featureid',
      'relationship field' => 'featureid',
      'extra' => array(
        0 => array('left_table' => 'dh_feature_vars', 'field' => 'varid', 'left_field' => 'varid') 
      ),
    ),
  );
  $data['dh_feature_vars']['prop_feature_vardef'] = array(
    'title' => t('Link to Matrix of Property, Feature and VarDef Combo'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('dH Properties, Feature and VarDef Combo'),
      'base' => 'dh_properties',
      'base field' => 'featureid',
      'relationship field' => 'featureid',
      'extra' => array(
        0 => array('left_table' => 'dh_feature_vars', 'field' => 'varid', 'left_field' => 'varid') 
      ),
    ),
  );
  
  /*
  $data['views']['tsvalue_compare'] = array(
    'group' => t('Numerical Filters'),
    'real field'  => 'tsvalue_compare',
    'title' => t('Filter TimeSeries Value'),
    'help' => t('Filter TimeSeries on Field Value [operator] Filter Value.'),
    'argument' => array(
      'handler' => 'dh_views_handler_argument_tsvalue'
    ),
  );
  */
  
  // add-ons for webform
  /**
   * Components table definitions.
   */
  $data['webform_component']['table']['group'] = t('Webform components');
  $data['webform_component']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Webform components'),
    'help' => t('Components that make up Webform forms.'),
  );
	// join to dH AdminReg Features
   $data['webform_component']['table']['join']['node'] = array(
     'left_table' => 'node',
     'left_field' => 'nid',
     'field' => 'nid'
   );
  // NID.
  $data['webform_component']['nid'] = array(
    'title' => t('Node'),
    'help' => t('The webform node this component belongs to.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Webform Node'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
  );
  $data['webform_component']['weight'] = array(
    'title' => t('Weight'),
    'help' => t('This component fields order on the form.'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'title' => t('Weight'), // Distinguish from the normal value handler.
      'help' => t('This component fields order on the form.'),
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
       'handler' => 'views_handler_argument_numeric',
    ),
  );
  // name
  $data['webform_component']['name'] = array(
    'title' => t('Component Name'),
    'help' => t('The name of this component field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Component Name'),
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // name
  $data['webform_component']['form_key'] = array(
    'title' => t('Component Form Key'),
    'help' => t('The form key of this component field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Component form key'),
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // name
  $data['webform_component']['type'] = array(
    'title' => t('Component Type'),
    'help' => t('The form field type of this component.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Component Type'),
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  //return $data;
}
