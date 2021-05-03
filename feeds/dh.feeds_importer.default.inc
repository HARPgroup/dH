<?php
/**
 * Implementation of hook_feeds_importer_default().
 */

function dh_feeds_importer_default() {
   $export = array();

	// aquifer
	$feeds_importer = new stdClass();
	$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
	$feeds_importer->api_version = 1;
	$feeds_importer->id = 'dh_import_aquifer';
	$feeds_importer->config = array(
	  'name' => 'dH - Import Aquifer',
	  'description' => '',
	  'fetcher' => array(
		 'plugin_key' => 'FeedsHTTPFetcher',
		 'config' => array(
			'auto_detect_feeds' => FALSE,
			'use_pubsubhubbub' => FALSE,
			'designated_hub' => '',
			'request_timeout' => NULL,
			'auto_scheme' => 'http',
		 ),
	  ),
	  'parser' => array(
		 'plugin_key' => 'FeedsCSVParser',
		 'config' => array(
			'delimiter' => 'TAB',
			'no_headers' => 0,
		 ),
	  ),
	  'processor' => array(
		 'plugin_key' => 'FeedsEntityProcessorDh_feature',
		 'config' => array(
			'mappings' => array(
			  0 => array(
				 'source' => 'name',
				 'target' => 'name',
				 'unique' => FALSE,
			  ),
			  1 => array(
				 'source' => 'deqid',
				 'target' => 'hydrocode',
				 'unique' => FALSE,
			  ),
			  2 => array(
				 'source' => 'wktgeom',
				 'target' => 'dh_geofield:wkt',
				 'unique' => FALSE,
			  ),
			),
			'update_existing' => '0',
			'input_format' => 'plain_text',
			'skip_hash_check' => 0,
			'bundle' => 'aquifer',
			'values' => array(),
		 ),
	  ),
	  'content_type' => '',
	  'update' => 0,
	  'import_period' => '-1',
	  'expire_period' => 3600,
	  'import_on_create' => 1,
	  'process_in_background' => 0,
	);

   $export['dh_import_aquifer'] = $feeds_importer;
	
	// HGU
	$feeds_importer = new stdClass();
	$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
	$feeds_importer->api_version = 1;
	$feeds_importer->id = 'dh_import_hydrogeologic_units';
	$feeds_importer->config = array(
	  'name' => 'dH - Import Hydrogeologic Units',
	  'description' => '',
	  'fetcher' => array(
		 'plugin_key' => 'FeedsHTTPFetcher',
		 'config' => array(
			'auto_detect_feeds' => FALSE,
			'use_pubsubhubbub' => FALSE,
			'designated_hub' => '',
			'request_timeout' => NULL,
			'auto_scheme' => 'http',
		 ),
	  ),
	  'parser' => array(
		 'plugin_key' => 'FeedsCSVParser',
		 'config' => array(
			'delimiter' => ',',
			'no_headers' => 0,
		 ),
	  ),
	  'processor' => array(
		 'plugin_key' => 'FeedsEntityProcessorDh_hydrogeologicunit',
		 'config' => array(
			'mappings' => array(
			  0 => array(
				 'source' => 'hgucode',
				 'target' => 'hgucode',
				 'unique' => FALSE,
			  ),
			  1 => array(
				 'source' => 'hguname',
				 'target' => 'hguname',
				 'unique' => FALSE,
			  ),
			),
			'update_existing' => '2',
			'input_format' => 'plain_text',
			'skip_hash_check' => 0,
			'bundle' => 'dh_hydrogeologicunit',
			'values' => array(),
		 ),
	  ),
	  'content_type' => '',
	  'update' => 0,
	  'import_period' => 1800,
	  'expire_period' => 3600,
	  'import_on_create' => TRUE,
	  'process_in_background' => FALSE,
	);
   $export['dh_import_hydrogeologic_units'] = $feeds_importer;
	
	// Well
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dh_import_deq_well';
  $feeds_importer->config = array(
    'name' => 'dH - Import DEQ Well',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorDh_feature',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'mpid',
            'target' => 'hydrocode',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'tot_depth',
            'target' => 'dh_welldepth',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'elev',
            'target' => 'dh_landelev',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'wkt',
            'target' => 'dh_geofield:wkt',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'aq',
            'target' => 'entityreference:aquiferid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'mpid',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'ftype',
            'target' => 'ftype',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'fac_hydrocode',
            'target' => 'entityreference:dh_link_facility_mps',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'well',
        'values' => array(),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );

   $export['dh_import_deq_well'] = $feeds_importer;
   
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dh_adminreg_import_facility_contacts';
  $feeds_importer->config = array(
    'name' => 'dH AdminReg - Import Facility Contacts',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorDh_adminreg_contact',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'ftype',
            'target' => 'ftype',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lastname',
            'target' => 'lastname',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'firstname',
            'target' => 'firstname',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'phone',
            'target' => 'phone',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'address1',
            'target' => 'address1',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'address2',
            'target' => 'address2',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'city',
            'target' => 'city',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'state',
            'target' => 'state',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'postal_code',
            'target' => 'postal_code',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'hydrocode',
            'target' => 'entityreference:dh_link_feature_contact',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'facility',
        'values' => array(),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['dh_adminreg_import_facility_contacts'] = $feeds_importer;

	return $export;
}

?>