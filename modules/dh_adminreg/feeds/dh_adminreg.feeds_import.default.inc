<?php
/**
 * Implementation of hook_feeds_importer_default().
 */

function dh_adminreg_feeds_importer_default() {
  $importers = array();
  $importers['dh_adminreg_import_organization'] = dh_ar_feeds_org();
  $importers['dha_import_permit'] = dh_ar_feeds_permit();
  $importers['dh_import_deq_well'] = dh_ar_feeds_well();
  $importers['dha_import_facilities'] = dh_ar_feeds_facility();
  $importers['dh_ar_feeds_authority'] = dh_ar_feeds_authority();
	return $importers;
}

function dh_ar_feeds_authority() {

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dha_issuing_authorities';
  $feeds_importer->config = array(
    'name' => 'dHA - Issuing Authorities',
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
      'plugin_key' => 'FeedsEntityProcessorDh_adminreg_feature',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'admincode',
            'target' => 'admincode',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'ftype',
            'target' => 'ftype',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'admincode',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'authority',
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
  return $feeds_importer;
}

function dh_ar_feeds_facility() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dha_import_facilities';
  $feeds_importer->config = array(
    'name' => 'dHA - Import Facilities',
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
      'plugin_key' => 'FeedsEntityProcessorDh_feature',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'ftype',
            'target' => 'ftype',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'address1',
            'target' => 'address1',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'address2',
            'target' => 'address2',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'city',
            'target' => 'city',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'state',
            'target' => 'state',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'postal_code',
            'target' => 'postal_code',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'hydrocode',
            'target' => 'hydrocode',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'hydrocode',
            'target' => 'guid',
            'unique' => 1,
          ),
          9 => array(
            'source' => 'permit_id',
            'target' => 'entityreference:dh_link_admin_location',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'description',
            'target' => 'description',
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
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );

  return $feeds_importer;
}

function dh_ar_feeds_well() {
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

  return $feeds_importer;
}

function dh_ar_feeds_permit() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dha_import_permit';
  $feeds_importer->config = array(
    'name' => 'dHA - Import Permit',
    'description' => 'Imports Permit Bundle dHA Feature - with admincode links to Org and Authority if supplied in file.',
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
      'plugin_key' => 'FeedsEntityProcessorDh_adminreg_feature',
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
            'source' => 'org_hydrocode',
            'target' => 'entityreference:dh_link_admin_reg_holder',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'issuer_hydrocode',
            'target' => 'entityreference:dh_link_admin_reg_issuer',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'admincode',
            'target' => 'admincode',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'permit_id',
            'target' => 'permit_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'admincode',
            'target' => 'guid',
            'unique' => 1,
          ),
          7 => array(
            'source' => 'startdate',
            'target' => 'startdate',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'enddate',
            'target' => 'enddate',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'permit',
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

  return $feeds_importer;
}
function dh_ar_feeds_org() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dh_adminreg_import_organization';
  $feeds_importer->config = array(
    'name' => 'dH AdminReg - Import Organization',
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
      'plugin_key' => 'FeedsEntityProcessorDh_adminreg_feature',
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
            'source' => 'admincode',
            'target' => 'admincode',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'admincode',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'address1',
            'target' => 'address1',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'address2',
            'target' => 'address2',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'city',
            'target' => 'city',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'state',
            'target' => 'state',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'postal_code',
            'target' => 'postal_code',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'organization',
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

  return $feeds_importer;
}

?>