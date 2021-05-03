<?php


function dh_webform_getmap() {
  // dH Webform integration
  $wfmap = array(); // keyed on name from webform table 
  $wfmap = array_merge($wfmap,  dh_webform_watercomp());
  $wfmap = array_merge($wfmap,  dh_webform_organization());
  $wfmap = array_merge($wfmap,  dh_webform_facility());
  $wfmap = array_merge($wfmap,  dh_webform_contact());
  $wfmap = array_merge($wfmap,  dh_webform_permit());
  $wfmap = array_merge($wfmap,  dh_webform_registration());
  $wfmap = array_merge($wfmap,  dh_webform_well());   
  $wfmap = array_merge($wfmap,  dh_webform_feature_contact());
  $wfmap = array_merge($wfmap,  dh_webform_permitconditions());
  $wfmap = array_merge($wfmap,  dh_webform_waterquality());
  $wfmap = array_merge($wfmap,  dh_webform_boreholelog());
  $wfmap = array_merge($wfmap,  dh_webform_tsevent());
  $wfmap = array_merge($wfmap,  dh_webform_prop());
  $wfmap = array_merge($wfmap,  dh_webform_waterlevel());
  $wfmap = array_merge($wfmap,  dh_webform_specialcondition());
  $wfmap = array_merge($wfmap,  dh_webform_generalpermitcondition());
  $wfmap = array_merge($wfmap,  dh_webform_wateruse_facility());
  $wfmap = array_merge($wfmap,  dh_webform_waterquality_facility());
  $wfmap = array_merge($wfmap,  dh_webform_waterlevel_facility());
  $wfmap = array_merge($wfmap,  dh_webform_compliance_report());
  $wfmap = array_merge($wfmap,  dh_webform_compliancestatus());
  $wfmap = array_merge($wfmap,  dh_webform_pointsassessment());
  // new style of array returned
  $wfmap['Create_Permit_Milestone'] = dh_webform_milestone();
  $wfmap['gw2'] = dh_webform_gw2();
  $wfmap['gw2_driller'] = dh_webform_gw2_driller();
  $wfmap['dh_webform_test'] = dh_webform_test();
  $wfmap['gw2_abandon'] = dh_webform_gw2_abandonment();
  $wfmap['gw2_geologicinfo'] = dh_webform_gw2_geologic_info();
  $wfmap['gw2_officeuseonly'] = dh_webform_gw2_office_certification();
  $wfmap['dh_webform_ar_prop'] = dh_webform_ar_prop();
  $wfmap['dh_webform_entity_prop'] = dh_webform_entity_prop();
  $wfmap['webform_draft_test'] = dh_webform_draft_test();
  $wfmap['gw2_revision'] = dh_webform_gw2_revision();
  $wfmap['gw2_revision_test'] = dh_webform_gw2_revision_test();
  $wfmap['gw2_pump_modification'] = dh_webform_gw2_pump_modification();
  $wfmap['gw2_full_abandonment'] = dh_webform_gw2_full_abandonment();

  return $wfmap;
}

function dh_webform_draft_test() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'node',
    'description' => 'dH Organization',
    'bundle' => 'page',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'form_key', 'refvalue' => 'draft_name', 'fieldname' => 'title'),
    ),
    'resultid' => 'orgnid',
    'writeback' => array(
      'organization_id' => 'orgnid',
    ),
  );
  return $wfmap;
}

function dh_webform_organization() {
  $wfmap = array();
  $wfmap['Create_New_Organization'][] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'dH Organization',
    'bundle' => 'organization',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'form_key', 'refvalue' => 'organization_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address', 'fieldname'=> 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address2', 'fieldname'=> 'address2'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'zip_code', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'tax_id', 'fieldname' => 'taxid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'organization_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'start_issuance_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'end_expiration_date', 'fieldname'=> 'enddate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'orgid',
    'writeback' => array(
      'organization_id' => 'orgid',
    ),
  );
  return $wfmap;
}

function dh_webform_gw2() {
  $wfmap = array();
  // first thing needs to be a registration record, with VDH as authority
  // then, all contact records can refer back to that registration record
  // alternatively, we could allow adminreg contact records to link to facilities and/or wells
  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Facility',
    'bundle' => 'facility',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_location'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_facility', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_address', 'fieldname'=> 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_state', 'fieldname'=> 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_zip', 'fieldname'=> 'postal_code'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_fa_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'facilityid',
  );
  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Well',
    'bundle' => 'well',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_facility_mps'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_num', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_use', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'production', 'fieldname' => 'fstatus'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_depth', 'fieldname' => 'dh_welldepth'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_elevation', 'fieldname' => 'dh_landelev'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_mps_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      // add geometry support, only one of the next two will get used
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'wellid',
    'writeback' => array(
      'well_id' => 'wellid',
    ),
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ Well Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'deq_well_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'deq_wellno'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_deq_well_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deqwellnumber_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH HDIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_hdin', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_hdin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_hdin_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_hdin_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH PWSID',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_pwsid', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_pwsid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_pwsid_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_pwsid_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'USGS Local',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'usgs_local_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'usgs_local'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_usgs_local_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'usgslocal_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geothermal Well Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'geothermal_well_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geothermal_well_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geothermal_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'geothermal_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Cooling Heating Discharge Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Cooling Heating Discharge', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cooling_heating_discharge'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_cooling_heating_discharge', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'coolingheating_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Subdivision',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'subdivision_name', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_subdivision'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_subdivision_name', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'subdivision_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Section',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'section', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_section'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_section', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'section_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Block',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'block', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_block'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_block', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'block_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lot Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'lot_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_lot_no'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lot_no', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'lot_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Tax Map/GPIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'tax_map_gpin_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_tax_map_gpin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_tax_map_gpin', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'tax_map_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lat/Long Source',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_source', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'spatial_data_source'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lat_long_source', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'latlong_source_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Location Info Collected By',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_collector', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_data_collector'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_location_information_collected_by', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'spatial_data_collector_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Location Description',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'physical_location_description', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'location_description'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'location_description_pid',
  );
  
  //Construction Event
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Construction Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_started', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'tsendtime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_event'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_class_well', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_depth', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_construction_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction Start Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'construction_start_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_st_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_started', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'const_date_started_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction End Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'construction_completion_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_comp_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'const_date_ended_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Rig',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'type_of_rig', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'rig_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_rig_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'rig_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Class Well',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'class_well', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_clss'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_class_well', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'class_well_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_construction_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_construction_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'const_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Borehole Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'borehole_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'borehole_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_borehole_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'borehole_depth_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth to Bedrock',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'depth_to_bedrock', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'bdrck_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_depth_to_bedrock', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'bedrock_depth_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Estimated Yield',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'estimated_yield', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'estimated_yield'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_estimated_yield', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'estimated_yield_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Finish Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_finish_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_finish_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_finish_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'well_finish_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Seal',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'seal_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_seal_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_seal_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'seal_type_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Camera Survey',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_construction_camera_survey', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_camera_survey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_camera_survey', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'camera_survey_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Camera Survey Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'camera_survey_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'camera_survey_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'camera_survey_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'camera_survey_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Construction Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_construction_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_construction_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_well_const_comments_propid',
  );

  //Disinfection Section
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Disinfection Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfection_date', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_contact_time_hrs', 'fieldname'=> 'tsendtime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfection_event'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfectant', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfectant_vol_gal', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'disinfection_event',
  );
  
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Disinfected',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'disinfected', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfected'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfected', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'disinfected_pid',
  );
  
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Disinfection Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'disindate', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfect_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfect_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'disinfect_date_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Static Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'swl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'swl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'swl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'SWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'swl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stbwl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stbwl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'stbwl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'STBWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'stbwl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Test Pump Intake Depth (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'test_pmp_int_dpt', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'test_pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_pmp_int_dpt', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'test_pmp_int_dpt_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_gpm', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stb_yld_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield Time (hrs)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_hrs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_hrs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_hrs', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stb_yld_hrs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_obs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_obs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_obs', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'q_nat_obs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow Rate (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_gpm', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'q_nat_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'pmp_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Horsepower',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_hp', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_hp'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_hp', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'pmp_hp_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Production Pump Intake Depth (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_int_dpt', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_int_dpt', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_int_dpt_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Rated Capacity (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_cap_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth of Capacity Measurement (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap_hd', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap_hd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap_hd', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_cap_hd_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Hole Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_hole_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_hole_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_hole_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_casing_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_casing_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Height',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'casing_height', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'casing_height'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_height', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_casing_height_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'casing_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'casing_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_depth', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_casing_depth_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Screen Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_screen_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_screen_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_screen_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Zone Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_waterzone_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_waterzone_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_waterzone_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Gravel Pack Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_gravelpack_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_gravelpack_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_gravelpack_propid',
  );  

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Grout Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_grout_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_grout_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_grout_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Liner Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_liner_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_liner', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_wellliner_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Job Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_job_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_job_number'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_job_number', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_jobnumber_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Installed',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_pump_installed', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pump_installed'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_installed', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'gw2_pumpinstalled_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Hydro Developed',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_hydro_developed_well', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'hydro_developed_well'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_hydro_developed', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'gw2_hydrodeveloped_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Air Lift Test Yield',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_air_lift_test', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'air_lift_yield'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_air_lift_yield', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_air_lift_yield_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Plumbing Size',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_plumbing_size', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plumbing_size'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_plumb_size', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_plumbingsize_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Plumbing Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propcode'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_plumbing_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plumbing_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_plumb_type', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'gw2_plumbingtype_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Formation',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_formation', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'formation'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_formation', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_formation_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type Logs',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_type_logs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'type_logs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_log_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_typelog_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lithology',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lithology'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_lithology_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Cuttings',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cutt_strd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_cuttings_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Province',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_province', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'province'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_province', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_province_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Aquifer Test Performed',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'aquifer_test'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_aquifer_test_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Map Used',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_map', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_map'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_map_used', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_map_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'WQ Results',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_wq_results_attached', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_results_const'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_wq_results', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_wq_results_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_comments_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Drillers Log',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_drillers_log', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_drillers_log', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_drillerslog_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'Driller Log Upload',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // entity reference based on resultid
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW2 Drillers Log', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW2 Drillers Log', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Drillers Log Upload', 'fieldname' => 'description'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'gw2_upload_drillers_log', 'fieldname'=> 'field_dha_submittal_document'),
    ),
    'resultid' => 'gw2_drillerslogupload',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Well Infilled',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_infilled', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cs_well_infilled'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_infilled', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_well_infilled_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Infilled Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_infilled_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'infilled_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_infilled_depth', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_infilled_depth_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Drillers Log Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_drillers_log_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_log_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_drillers_log_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_drillerslogcomments_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller Certification',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_driller_certification', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_driller_certification'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_certification', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_driller_certification_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Well Driller Signature',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_driller_signature', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_driller_signature'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_signature', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_driller_signature_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller Certification Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_driller_certification_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_certification_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_certification_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'gw2_certification_date_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller License Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_driller_license_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_license_number'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_license_number', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_license_number_propid',
  );

  // submittal is the actual GW-2 form, which is linked to the Webform document
  // Sys provider is the permittee who makes the submittal
  // submittal is linked to the facility via dh_link_feature_submittal
  // submittal is linked to the SysProvider via dh_link_admin_submittal_pr
  // sys provider is be linked to the facility via dh_link_admin_location
  // sys provider is be linked to the well via dh_link_admin_location
  
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'GW-2 Submittal Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname'=> 'wellid'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_gw2_submittal'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_submittal', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'constant', 'refvalue' => 1, 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'gw2_submission_event',
  );
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Submittal Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_form', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submission_event', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'gw2_form_upload', 'fieldname'=> 'field_dha_submittal_document'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_submittal_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Submittal Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => false,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_submittal_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  ); 
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Add Submittal to Driller Record',
    'bundle' => 'dh_adminreg_contact',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'driller_id', 'fieldname' => 'contactid'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'fieldname'=> 'dh_link_admin_contact'),
    ),
    'resultid' => '',
  ); 
    
  // 
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Owner',
    'bundle' => 'dh_adminreg_contact',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'fieldname'=> 'dh_link_admin_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'constant', 'refvalue' => 'owner', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_lastname', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_address', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_zip', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_phone', 'fieldname' => 'phone'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_email', 'fieldname' => 'email'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
    ),
    'resultid' => 'ownerid',
  );

  // the driller contact will be passed in via a URL, 
  // all we need to do is to connect the driller contact record to the Registration record
  // can we do this?  This requires a new kind of handler... "entity_references"
  //$wfmap[] = array(
  //  'entity' => 'entityreference',
  //  'description' => 'Driller',
  //  'bundle' => 'entityreference',
  //  'debug' => FALSE,
  //  'entity_references' => array( 
  //    array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'webform_targettype' => 'form_key', 'targetvalue' => 'driller_id', 'fieldname'=> 'dh_link_admin_contact'),
  //  ),
  //);
  
  return $wfmap;
}

function dh_webform_gw2_abandonment() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Well Abandoned Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    //'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => '1', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_abandoned_event_tid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Static Water Level at Well Abandoned',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_abandoned_date', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_swl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_abandoned_swl_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Abandoned',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_abandoned', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_abandoned', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'well_abandoned_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Start Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'abandate', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'abandate_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Completion Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'abandate_complete', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'abandate_complete_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Rig',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'aband_rig_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'rig_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_rig_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'aband_rig_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Static Water Level at Abandonment',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'aband_swl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_swl_ft', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'aband_swl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Pulled',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    //'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_casing_pulled', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_casing_pulled'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_casing_pulled', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_casing_pulled_comment', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_casing_pulled',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth of and Type Fill',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    //'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_fill_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_fill_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_fill_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_fill_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_fill_depth_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_casing_intervals_abandonment', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_abandon', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_casing_abandonment_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Grout Abandonment Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_grout_intervals_abandonment', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_grout_abandon', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_grout_abandonment_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Method of Location Marking',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_marking_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_marking_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_marking_method', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_marking_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_abandonment_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandonment_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandonment_comment', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_abandon_comments_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Abandonment Submittal Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_abandonment', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandonment_comment', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'well_abandoned_event_tid', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_submittal_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Abandonment Submittal Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_submittal_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  );
  return $wfmap;
}

function dh_webform_gw2_office_certification() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ Well Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'deq_well_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'deq_wellno'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_deq_well_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deqwellnumber_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH HDIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_hdin', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_hdin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_hdin_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_hdin_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH PWSID',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_pwsid', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_pwsid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_pwsid_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_pwsid_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'USGS Local',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'usgs_local_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'usgs_local'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_usgs_local_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'usgslocal_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Inspecting Official Certification',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_inspecting_official_certification', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'gw2_office_certification'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_official_certification', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_official_certification_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Inspecting Official Signature',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_inspecting_official_signature', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'inspecting_official_signature'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_certification_signature', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_certification_signature_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Office Certification Date',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tstime'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_certification_signature', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'office_certification_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_office_certification_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'gw2_office_certification_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Office Certification',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_office_use_only_form', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Official Certification', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_office_certification_date_pid', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      //array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_officeuse_submittal_id',
  );

  return $wfmap;
}


function dh_webform_gw2_geologic_info() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Formation',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_formation', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'formation'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_formation', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_formation_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type Logs',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_type_logs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'type_logs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_log_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_typelog_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lithology',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lithology'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_lithology_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Cuttings',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cutt_strd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_cuttings_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Province',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_province', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'province'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_province', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_province_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Aquifer Test Performed',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'aquifer_test'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_aquifer_test_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Map Used',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_map', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_map'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_map_used', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_map_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'WQ Results',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_wq_results_attached', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_results_const'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_wq_results', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_wq_results_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_comments_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Geologic Info Submittal',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_information_form', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Geologic Information Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      //array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submission_event', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      //array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'env', 'refvalue' => 'sid', 'fieldname' => 'formid'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'results_file', 'fieldname'=> 'field_dha_submittal_document'),
    ),
    'resultid' => 'gw2_geologic_info_id',
  );

  return $wfmap;
}

function dh_webform_test() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Submittal Doc',
    'bundle' => 'submittal',
    'debug' => TRUE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_form', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'env', 'refvalue' => 'sid', 'fieldname' => 'formid'),
    ),
    'resultid' => 'gw2_submittal_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Submittal Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => TRUE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_submittal_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'env', 'refvalue' => 'sid', 'fieldname' => 'formid'),
    ),
    'resultid' => 'upsid',
  ); 
  
  
  return $wfmap;
}


function dh_webform_gw2_driller() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Driller',
    'bundle' => 'dh_adminreg_contact',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'providerid', 'fieldname'=> 'dh_link_admin_contact'),
      array('webform_reftype' => 'constant', 'refvalue' => 'driller', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_firstname', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_lastname', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_address', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_zipcode', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_phone', 'fieldname' => 'phone'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
    ),
    'resultid' => 'drillerid',
    'writeback' => array(
      'driller_id' => 'drillerid',
    ),
  );
  return $wfmap;
}


function dh_webform_facility() {
  $wfmap = array();
  $wfmap['Create_New_Facility'][] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Facility',
    'bundle' => 'facility',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'permit_id', 'fieldname'=> 'dh_link_admin_location'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'facility_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'facility_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address', 'fieldname'=> 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address2', 'fieldname'=> 'address2'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'zip_code', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_fa_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'county'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'facility_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
      // add geometry support, only one of the next two will get used
      // they are both marked as "notnull=true" so that it will skip whichever is 
      // missing from the form
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'latitude', 'lon'=>'longitude', 'srid'=>'projection'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'fac_latitude_degrees', 'lat_min' => 'fac_latitude_minutes', 'lat_sec'=>'fac_latitude_seconds', 'lon_deg'=>'fac_longitude_degrees', 'lon_min'=>'fac_longitude_minutes', 'lon_sec' => 'fac_longitude_seconds', 'srid'=>'projection'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'facilityid',
    'writeback' => array(
      'facility_id' => 'facilityid',
    ),
  );
  
  $wfmap['Create_New_Facility'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Latitude',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'latitude', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lat_dd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'latitude', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'facility_latitude',
  );

  $wfmap['Create_New_Facility'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Longitude',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'longitude', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lon_dd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'longitude', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'facility_longitude',
  );

  $wfmap['Create_New_Facility'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Projection',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'source_projection', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'epsg_srid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'projection', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'facility_projection',
  );
  return $wfmap;
}

function dh_webform_contact() {
  $wfmap = array();
  $wfmap['Create_New_Contact'][] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'dH Admin Contact',
    'bundle' => 'dh_adminreg_contact',
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'admin_id', 'fieldname'=> 'dh_link_admin_contact'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'contact_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'first_name', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'last_name', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address1', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address2', 'fieldname' => 'address2'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'zip_code', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'phone_number', 'fieldname' => 'phone'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'email_address', 'fieldname' => 'email'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'website', 'fieldname' => 'website'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'contact_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'contactid',
    'writeback' => array(
      'contact_id' => 'contactid',
    ),
  );
  return $wfmap;
}



function dh_webform_permit() {
  $wfmap = array();
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'dH Admin/Regulatory Permit Document',
    'bundle' => 'permit',
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_reg_holder'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_status', 'fieldname' => 'fstatus'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'date_received', 'fieldname'=> 'date_received'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw_permit_id', 'fieldname'=> 'permit_id'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'permit_writer', 'fieldname' => 'dh_link_admin_record_mgr_id'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'ows_authority', 'fieldname' => 'dh_link_admin_reg_issuer'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'permitid',
    'writeback' => array(
      'permit_id' => 'permitid',
    ),
  );
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Date Received',
    'bundle' => 'dh_timeseries',
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'permitid', 'fieldname'=> 'dh_link_admin_reg_holder'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_event_appreceived'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'date_received', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 0, 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'tid_app_received',
  );

// create a compliance report Document feature
  // then link the TS values to it
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'Permit Application Fields',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'permit_application', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Permit Application', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Permit Application Submittal', 'fieldname' => 'description'),
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'daily_wd_request' => 'wd_limit_gpd'),
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'monthly_wd_request' => 'wd_limit_gpmo'),
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'annual_wd_request' => 'wd_limit_gpy'),
      // entity reference based on resultid
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'permitid', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'tid_app_received', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
    ),
    'resultid' => 'compliance_featureid',
  );
  
  // Water use Cat
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Use Categories',
    'bundle' => 'dh_properties',
    'debug' => false,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gwc_use_cat', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'gwc_use_cat'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_category', 'fieldname'=> 'proptext', 'concat' => ','),
    ),
    'resultid' => 'wd_need_method',
  );

  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Permit Fee',
    'bundle' => 'dh_properties',
    'debug' => false,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'permit_fee', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'permit_fee'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_fee', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'permit_fee',
  );

  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Permit Fee Date Deposited',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'permit_fee_deposited', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'date_deposited'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'date_deposited', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'permit_fee_date_deposited',
  );

  // VDH Permit Number
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH Permit Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_ww_op_num', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_ww_op_num'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'vdh_permit_number', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'vdh_permit_number',
  );
  
  // VDH Permit Withdrawal Limit
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH Permit Withdrawal Limit',
    'bundle' => 'dh_properties',
    //'debug' => 'true',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_permit_wd_lmit', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_permit_wd_limit'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'vdh_permit_withdrawal_limit', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'vdh_permit_wd_limit',
  );

  // Requested Limits
  // Monthly
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Need Justification Method',
    'bundle' => 'dh_properties',
    'debug' => false,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_need_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_need_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_need_method', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'need_method',
  );
  
  // Requested Limits
  // Monthly
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Monthly Limit Condition',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'requested_monthly_limit_gpmo', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'requested_wd_limit_gpmo'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'monthly_wd_request', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'condition_monthly_limit_gpmo',
  );

  // Requested Limits
  // Annual
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Annual Limit Condition',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'requested_annual_limit_gpy', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'requested_wd_limit_gpy'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'annual_wd_request', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'condition_annual_limit_gpy',
  );

  // Requested Limits
  // Daily
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Daily Limit Condition',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'requested_daily_limit_g', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'requested_wd_limit_gpd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_wd_request', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'condition_daily_limit_g',
  );

  // Requested Limits
  // MultiYear Withdrawal
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multiyear Limit',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'requested_multiyear_wd_g', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'requested_multiyear_wd_g'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_request_g', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'requested_multiyear_limit_g',
  );

  // Requested Limits
  // Multiyear Period
  $wfmap['Create_New_Permit'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multiyear Period',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'permitid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'requested_multiyear_wd_period', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'requested_multiyear_wd_period'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_request_pd', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'requested_multiyear_wd_period',
  );
  return $wfmap;
}


function dh_webform_registration() {
  $wfmap = array();
  $wfmap['Voluntary_Registration'][] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'dH Admin/Regulatory Entity/Facility Registration',
    'bundle' => 'registration',
    'fields' => array(
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname'=> 'dh_link_admin_reg_holder'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'registration_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'registration_status', 'fieldname' => 'fstatus'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'registration_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'date_received', 'fieldname'=> 'date_received'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'start_issuance_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'end_expiration_date', 'fieldname'=> 'enddate'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'permit_writer', 'fieldname' => 'dh_link_admin_record_mgr_id'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'registrationid',
    'writeback' => array(
      'registration_id' => 'registrationid',
    ),
  );
  return $wfmap;
}


function dh_webform_well() {
  $wfmap = array();
  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Well',
    'debug' => false,
    'bundle' => 'well',
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'facility_id', 'fieldname'=> 'dh_link_facility_mps'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_type', 'fieldname'=> 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_depth', 'fieldname' => 'dh_welldepth'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'land_surface_elevation', 'fieldname'=> 'dh_landelev'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_description', 'fieldname'=> 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_status', 'fieldname'=> 'fstatus'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'latitude', 'lon'=>'longitude', 'srid'=>'projection'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'well_latitude_degrees', 'lat_min' => 'well_latitude_minutes', 'lat_sec'=>'well_latitude_seconds', 'lon_deg'=>'well_longitude_degrees', 'lon_min'=>'well_longitude_minutes', 'lon_sec' => 'well_longitude_seconds', 'srid'=>'projection'), 'dms_string_name' => 'well_dms_string', 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'hydroid',
    'writeback' => array(
      'hydro_id' => 'hydroid',
    ),
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ Well No',
    'bundle' => 'dh_properties',
    'debug' => false,
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'deq_wellno', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'deq_wellno'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'deq_well_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deq_wellno',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ MPID',
    'bundle' => 'dh_properties',
    'debug' => false,
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vadeq_mpid', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_mpid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'mpid', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deq_mpid',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Lat/Lon DMS',
    'bundle' => 'dh_properties',
    'debug' => false,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'latlon_dms', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'latlon_dms'), 
        ),
      ),
      array('webform_reftype' => 'result', 'refvalue' => 'well_dms_string', 'fieldname'=> 'proptext'),
    ),
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Latitude',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'latitude', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lat_dd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'latitude', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'well_latitude',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Longitude',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'longitude', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lon_dd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'longitude', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'well_longitude',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Projection',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'source_projection', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'epsg_srid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'projection', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'well_projection',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Setting',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pump_intake_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'pump_setting', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pump_setting_well',
  );

  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Max Pump Setting',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'hydroid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'max_pump_intake_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'max_pump_setting_well',
  );

// create a compliance report Document feature
  // then link the TS values to it
  $wfmap['Create_New_Well'][] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'Geo Log Upload',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'geophysical log', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Geophysical Log', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Geophysical Log Submittal', 'fieldname' => 'description'),
      // entity reference based on resultid
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'hydroid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'attach_geophysical_log', 'fieldname'=> 'field_dha_submittal_document'),
    ),
    'resultid' => 'compliance_featureid',
  );

  return $wfmap;
}


function dh_webform_milestone() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'dH Milestone',
    'bundle' => 'milestone',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'admin_id', 'fieldname' => 'dh_link_admin_milestone'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'milestone_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'due_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'completion_date', 'fieldname'=> 'enddate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'milestoneid',
    'writeback' => array(
      'milestone_id' => 'milestoneid',
    ),
  );

  //Compliance Event
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Action Date',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'milestoneid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'date_received', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'compliance_action_date'), 
        ),
      ),
    ),
    'resultid' => 'compliance_action_date',
  );
  return $wfmap;
}


function dh_webform_feature_contact() {
  $wfmap = array();
  $wfmap['Create_New_Feature_Contact'][] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'dH Feature Contact',
    'bundle' => 'dh_adminreg_contact',
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'admin_id', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'contact_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'first_name', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'last_name', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address1', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'address2', 'fieldname' => 'address2'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'zip_code', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'phone_number', 'fieldname' => 'phone'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'email_address', 'fieldname' => 'email'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'website', 'fieldname' => 'website'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'contact_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'featcontactid',
    'writeback' => array(
      'featurecontact_id' => 'featcontactid',
    ),
  );
  return $wfmap;
}

function dh_webform_permitconditions() {
  $wfmap = array();
$wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Annual Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpy', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpy'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'yearly_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'annual_limit_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_annual_limit_gpy',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Monthly Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpmo', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpmo'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'monthly_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'monthly_limit_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_monthly_limit_gpmo',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Daily Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpd', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_limit_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_daily_limit_gpd',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Max Pump Setting',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'max_pump_intake_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_limit_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'max_pump_setting_depth',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multi-Year Withdrawal Reporting Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'multiyear_wd_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'boolean_integer'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multi_year_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multi_year_withdrawal_limit_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_multiyear_wd_reporting',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multi Year Withdrawal Amount Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'multiyear_limit_g', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'multiyear_wd_limit_g'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_amount', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_amount_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_multiyear_limit_g',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multi Year Withdrawal Duration Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'multiyear_limit_numyears', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_years'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_years', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_years_notes', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_multiyear_duration_g',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Quality Reporting Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_quality_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wq'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_quality_reporting', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_quality_reporting',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Quality Observation Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_obs_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_quality_observation_interval',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Quality Reporting Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_quality_reporting_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_quality_reporting_interval',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Level Reporting Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_reporting', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_level_reporting',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Level Observation Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wl_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_obs_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_level_observation_interval',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Level Reporting Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_reporting_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wl_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_level_reporting_interval',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Use Reporting Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_use_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_reporting', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_use_reporting',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Use Observation Interval',
    'bundle' => 'dh_properties',
   'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_use_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_obs_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_use_observation_interval',
  );

  $wfmap['Add_Permit_Conditions'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Use Reporting Interval',
    'bundle' => 'dh_properties',
   'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_use_reporting_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_rep_interval', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'condition_water_use_reporting_interval',
  );
  return $wfmap;
}

function dh_webform_watercomp() {
  $wfmap = array();
  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'January Use',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 1, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'january', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jan',
  );
  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'February Use',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 2, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'),
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'february', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_feb',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'March Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 3, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'march', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_mar',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'April Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 4, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'april', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_apr',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'May Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 5, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'),
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'may', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_may',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'June Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 6, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'june', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jun',
  );
  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'July Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 7, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'july', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jul',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'August Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 8, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'august', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_aug',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'September Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 9, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'september', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_sep',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'October Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 10, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'october', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_oct',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'November Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 11, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'november', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_nov',
  );

  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'December Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 12, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'december', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_dec',
  );

  
  // this creates a single entry per permit, based on whether or not the URL has the variable add_receipt = 1
  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wateruse_comp_rtid',
  );
  
  // this is a decision point - in old GWPermit there was a data entry date as well as a due date and received date,
  // however, GWPermit seems to add one of these per permit, per wq/wd/wl report needed, 
  //   but ultimately this only tracks staff entry of receipt records, 
  //  the real question may be whether or not staff are actually entering data? 
  //   In which case it should be entered for each well x wd/wl/wq entry event
  
  $wfmap['Water_Use_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Data Entry Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
	  // add to the permit
      //array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_permit_id', 'fieldname'=> 'featureid'),
	  // or add to the well
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'admin_data_entered'), 
        ),
      ),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wateruse_comp_detid',
  );
  
  // another decision point: create a submittal doc or just rely on TS events to track the submittal?
  // thus far, submittals have been used for more unique events (like add-info response, permit application), 
  // not regularly occuring compliance events.  
  // If we DO decide to include this, only one of these per PERMIT and per reporting cycle should be used
  // would have to do some extra work in order to get a submittal record to link back to all the pieces of the submittal
  /*
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'Submittal Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      array('webform_reftype' => 'constant', 'refvalue' => 'vadeq_permit_compliance', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GWPermit Compliance Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wateruse_permit_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wateruse_comp_rtid', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wateruse_comp_detid', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gwp_submittal_id',
  ); 
  */

  return $wfmap;
}


function dh_webform_waterquality() {
  $wfmap = array();
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Alkalinity',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'alkalinity_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_alkalinity_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_alkalinity',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Alkalinity BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'alkalinity_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_alkalinity_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_alkalinity_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Calcium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'calcium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_calcium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_calcium',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Calcium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'calcium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_calcium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_calcium_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Chloride',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'chlorides_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_chloride_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_chloride',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Chloride BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'chlorides_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_chloride_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_chloride_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Fluoride',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'fluoride_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_fluoride_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_fluoride',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Fluoride BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'fluoride_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_fluoride_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_fluoride_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Iron',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'iron_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_iron_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_iron',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Iron BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'iron_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_iron_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_iron_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Magnesium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'magnesium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_magnesium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_magnesium',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Magnesium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'magnesium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_magnesium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_magnesium_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Manganese',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'manganese_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_manganese_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_manganese',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Manganese BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'managanese_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_manganese_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_manganese_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Potassium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'potassium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_potassium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_potassium',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Potassium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'potassium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_potassium_bdll', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_potassium_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Selenium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'selenium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_selenium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_selenium',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Selenium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'selenium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_selenium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_selenium_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sodium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sodium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sodium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sodium',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sodium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sodium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sodium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sodium_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sulfate',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sulfate_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sulfate_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sulfate',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sulfate BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sulfate_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sulfate_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sulfate_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Dissolved Solids',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totaldissolvedsolids_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_dissolved_solids_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totaldissolvedsolids',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Dissolved Solids BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totaldissolvedsolids_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_dissolved_solids_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totaldissolvedsolids_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Hardness',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totalhardness_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_hardness_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totalhardness',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Hardness BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totalhardness_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_hardness_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totalhardness_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'zinc',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'zinc _mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_zinc_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_zinc',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'zinc BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'zinc _bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_zinc_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_zinc_bdl',
  );
  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'pH',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'ph_num'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_ph', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_ph',
  );

  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Conductivity',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'conductivity_mscm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'conductivity_mscm', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_conductivity',
  );

  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Mass Balance',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'massbalance'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'mass_balance', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_massbalance',
  );

  $wfmap['Water_Quality_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wq'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'waterquality_complianceid',
  );

  return $wfmap;
}


function dh_webform_boreholelog() {
  $wfmap = array();
  $wfmap['Interval_Data_Entry'][] = array(
    'entity' => 'dh_boreholelog',
    'description' => 'Interval',
    'bundle' => 'dh_boreholelog',
    'debug' => false,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'hydro_id', 'fieldname' => 'wellid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'interval_type', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'well_diameter', 'fieldname'=> 'diameter'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'from_depth', 'fieldname'=> 'fromdepth'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'to_depth', 'fieldname' => 'todepth'),
      array('webform_reftype' => 'constant', 'refvalue' => 'feet', 'fieldname' => 'elevunits'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'reference_elevation', 'fieldname' => 'refelev'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'material_interval', 'fieldname' => 'material'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'hgu_code', 'fieldname'=> 'hguid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'log_type', 'fieldname'=> 'logtype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname' => 'modified'),
    ),
    'resultid' => 'intervalid',
    'writeback' => array(
      'interval_id' => 'intervalid',
    ),
  );
  return $wfmap;
}

function dh_webform_tsevent() {
  $wfmap = array();
  $wfmap['dh_webform_tsevent'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Event',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'tstime', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'vadeq_event_duedate', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'constant', 'refvalue' => 0, 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'tstext', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'tid_app_received',
  );
  return $wfmap;
}

function dh_webform_compliancestatus() {
  $wfmap = array();
  $wfmap['dh_webform_compliancestatus'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Compliance Status',
    'debug' => false,
    'bundle' => 'dh_properties',
    'handler' => 'dh_webform_insert_properties', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'tstime', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'compliance_status', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'boolean_status', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'compliancestatus_pid',
  );

  $wfmap['dh_webform_compliancestatus'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Compliance Status',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'handler' => 'dh_webform_insert_properties', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'tstime', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'boolean_status', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'compliance_status', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'compliancestatus_tid',
  );

  return $wfmap;
}

function dh_webform_pointsassessment() {
  $wfmap = array();
  $wfmap['dh_webform_pointsassessment'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Points Assessment',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'handler' => 'dh_webform_insert_properties', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'action_date', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'closure_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'comp_action_comments', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'points_assessed', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'compliancepoints_tid',
  );

  return $wfmap;
}


function dh_webform_prop() {
  // generic processor to add props to a dh feature (for adminreg features, see dh_webform_ar_prop, flexible features see dh_webform_entity_prop
  $wfmap = array();
  $wfmap['dh_webform_prop'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Prop',
    'debug' => false,
    'bundle' => 'dh_properties',
    'handler' => 'dh_webform_insert_property', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'varkey', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propvalue', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'entity_type', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'proptext', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propdate', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'tid_app_received',
  );
  return $wfmap;
}


function dh_webform_ar_prop() {
  // generic processor to add props to a dh adminreg feature (for dh features, see dh_webform_ar_prop, flexible features see dh_webform_entity_prop)
  $wfmap = array();
  $wfmap['dh_webform_prop'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Prop',
    'debug' => false,
    'bundle' => 'dh_properties',
    'handler' => 'dh_webform_insert_property', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'varkey', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propvalue', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'entity_type', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'proptext', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propdate', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'tid_app_received',
  );
  return $wfmap;
}


function dh_webform_entity_prop() {
  // generic processor to add props to any entity (for dh feature see dh_add_prop, for adminreg features see dh_webform_ar_prop)
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Prop',
    'debug' => false,
    'bundle' => 'dh_properties',
    'handler' => 'dh_webform_insert_property', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'entity_type', 'fieldname'=> 'entity_type'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'varkey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'varkey', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propvalue', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'entity_type', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'proptext', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propdate', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'tid_app_received',
  );
  return $wfmap;
}

function dh_webform_waterlevel() {
  $wfmap = array();  
  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'January Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jan', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jan', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jan_tid',
  );

  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'February Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_feb', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_feb', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_feb_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'March Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_mar', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_mar', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_mar_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'April Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_apr', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_apr', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_apr_tid',
  );

  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'May Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_may', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_may', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_may_tid',
  );

  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'June Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jun', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jun', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jun_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'July Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jul', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jul', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jul_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'August Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_aug', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_aug', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_aug_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'September Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_sep', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_sep', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_sep_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'October Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_oct', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_oct', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_oct_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'November Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_nov', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_nov', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_nov_tid',
  );


  $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'December Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_dec', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_dec', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_dec_tid',
  );


 $wfmap['Water_Level_Compliance_Report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'constant', 'refvalue' => 'today', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wl_complianceid',
  );

  return $wfmap;
}


function dh_webform_specialcondition() {
  $wfmap = array();
  $wfmap['dh_webform_specialcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Permit Special Conditions',
    'debug' => false,
    'bundle' => 'dh_properties',
    'handler' => 'dh_webform_insert_property', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'featureid', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property_webformkey', 'property' => 'varkey', 'value' => 'gwp_special_condition'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'special_condition_due_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'special_condition_completion_date', 'fieldname'=> 'enddate'),
      array('webform_reftype' => 'constant', 'refvalue' => 0, 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'special_condition_comments', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'propname', 'fieldname'=> 'propname'),
    ),
    'resultid' => 'gwp_special_condition',
  );
  return $wfmap;
}

function dh_webform_generalpermitcondition() {
  $wfmap = array();
  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Annual Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpy', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpy'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'yearly_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'annual_limit_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_annual_limit_gpy',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Monthly Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpmo', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpmo'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'monthly_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'monthly_limit_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_monthly_limit_gpmo',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Daily Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'wd_limit_gpd', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_gpd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_withdrawal_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_limit_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_daily_limit_gpd',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Max Pump Setting',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'max_pump_intake_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'max_pump_intake_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'daily_limit_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'max_pump_setting_depth',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multi Year Withdrawal Amount Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'multiyear_limit_mg', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_mg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_amount', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_amount_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_multiyear_limit_mg',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Multi Year Withdrawal Duration Limit Condition',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'multiyear_limit_numyears', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_limit_years'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_years', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'multiyear_wd_limit_years_notes', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_multiyear_duration_mg',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Quality Observation Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_obs_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_quality_observation_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Quality Reporting Interval and Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_quality_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => '1', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_rep_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_quality_reporting_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Level Observation Interval',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wl_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_obs_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_level_observation_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Level Reporting Interval and Required',
    'bundle' => 'dh_properties',
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_level_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wl_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => '1', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_rep_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_level_reporting_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Use Observation Interval',
    'bundle' => 'dh_properties',
   'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_use_observation_interval', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_obs_interval'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_obs_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_use_observation_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Use Reporting Interval',
    'bundle' => 'dh_properties',
   'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'water_use_reporting', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wd_rep_interval'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => '1', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_rep_interval', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_water_use_reporting_interval',
  );

  $wfmap['dh_webform_generalpermitcondition'][] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH Permit Withdrawal Limit',
    'bundle' => 'dh_properties',
   'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'admin_id', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_permit_withdrawal_limit', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_permit_wd_limit'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'vdh_permit_wd_limit', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'startdate', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'enddate', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'condition_vdh_permit_wd_limit',
  );


  return $wfmap;
}

function dh_webform_wateruse_facility() {
  $wfmap = array();
  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'January Use',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 1, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'january', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jan',
  );
  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'February Use',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 2, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'),
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'february', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_feb',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'March Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 3, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'march', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_mar',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'April Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 4, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'april', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_apr',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'May Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 5, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'),
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'may', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_may',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'June Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 6, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'june', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jun',
  );
  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'July Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 7, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'july', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_jul',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'August Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 8, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'august', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_aug',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'September Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 9, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
      ),
    ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'september', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_sep',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'October Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 10, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'october', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_oct',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'November Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 11, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'november', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_nov',
  );

  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'December Use',
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_admin_id', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 12, 'fieldname'=> 'month'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wlg'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'december', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
    ),
    'resultid' => 'tid_dec',
  );

  
  // create a compliance report Document feature
  // then link the TS values to it
  $wfmap['dh_webform_wateruse_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wateruse_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_year', 'fieldname'=> 'year'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'water_use_quarter', 'fieldname'=> 'quarter'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wateruse_comp_rtid',
  );
  

  return $wfmap;
}


function dh_webform_waterquality_facility() {
  $wfmap = array();
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Alkalinity',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'alkalinity_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_alkalinity_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_alkalinity',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Alkalinity BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'alkalinity_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_alkalinity_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_alkalinity_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Calcium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'calcium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_calcium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_calcium',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Calcium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'calcium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_calcium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_calcium_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Chloride',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'chlorides_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_chloride_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_chloride',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Chloride BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'chlorides_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_chloride_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_chloride_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Fluoride',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'fluoride_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_fluoride_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_fluoride',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Fluoride BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'fluoride_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_fluoride_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_fluoride_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Iron',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'iron_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_iron_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_iron',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Iron BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'iron_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_iron_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_iron_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Magnesium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'magnesium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_magnesium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_magnesium',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Magnesium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'magnesium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_magnesium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_magnesium_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Manganese',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'manganese_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_manganese_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_manganese',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Manganese BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'managanese_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_manganese_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_manganese_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Potassium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'potassium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_potassium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_potassium',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Potassium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'potassium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_potassium_bdll', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_potassium_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Selenium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'selenium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_selenium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_selenium',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Selenium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'selenium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_selenium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_selenium_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sodium',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sodium_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sodium_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sodium',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sodium BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sodium_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sodium_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sodium_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sulfate',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sulfate_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sulfate_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sulfate',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Sulfate BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'sulfate_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sulfate_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_sulfate_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Dissolved Solids',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totaldissolvedsolids_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_dissolved_solids_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totaldissolvedsolids',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Dissolved Solids BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totaldissolvedsolids_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_dissolved_solids_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totaldissolvedsolids_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Hardness',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totalhardness_mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_hardness_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totalhardness',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Total Hardness BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'totalhardness_bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_total_hardness_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_totalhardness_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'zinc',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'zinc _mgl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_zinc_mgl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_zinc',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'zinc BDL',
    'bundle' => 'dh_timeseries',
   'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'zinc _bdl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_zinc_bdl', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_zinc_bdl',
  );
  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'pH',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'ph_num'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_ph', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_ph',
  );

  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Conductivity',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'conductivity_mscm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'conductivity_mscm', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_conductivity',
  );

  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Mass Balance',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_admin_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'massbalance'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'mass_balance', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_sample_date', 'fieldname'=> 'tstime'),
    ),
    'resultid' => 'tid_massbalance',
  );

  $wfmap['dh_webform_waterquality_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wq'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'waterquality_complianceid',
  );

  return $wfmap;
}

function dh_webform_waterlevel_facility() {
  $wfmap = array();  
  $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'January Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jan', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jan', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jan_tid',
  );

 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'February Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_feb', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_feb', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_feb_tid',
  );

 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'March Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_mar', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_mar', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_mar_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'April Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_apr', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_apr', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_apr_tid',
  );

 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'May Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_may', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_may', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_may_tid',
  );

 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'June Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jun', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jun', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jun_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'July Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_jul', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_jul', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_jul_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'August Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_aug', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_aug', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_aug_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'September Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_sep', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_sep', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_sep_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'October Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_oct', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_oct', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_oct_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'November Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_nov', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_nov', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_nov_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'December Water Level Sample',
    'debug' => false,
    'bundle' => 'dh_timeseries',
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_hydro_id', 'fieldname'=> 'featureid'),
    array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
      array('type' => 'property', 'property' => 'varkey', 'value' => 'water_level_ft'),
      ),
    ),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_sample_date_dec', 'fieldname' => 'tstime'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'wl_depth_dec', 'fieldname'=> 'tsvalue'),
    array('webform_reftype' => 'form_key', 'refvalue' => 'water_level_comments', 'fieldname'=> 'tstext'),
  ),
  'resultid' => 'wl_compliance_dec_tid',
  );


 $wfmap['dh_webform_waterlevel_facility'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'add_receipt', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'constant', 'refvalue' => 'today', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wl_complianceid',
  );

  return $wfmap;
}


function dh_webform_compliance_report() {
  $wfmap = array(); 
  $wfmap['dh_webform_compliance_report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'WD Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wd_recvd', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'comments', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wd_reportreceived_id',
  );
  $wfmap['dh_webform_compliance_report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'WQ Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wq'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wq_recvd', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'comments', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wq_reportreceived_id',
  );
  $wfmap['dh_webform_compliance_report'][] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Water Level Report Submittal Event Logged',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'permit_id', 'fieldname'=> 'featureid'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_report_wl'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'wl_recvd', 'fieldname'=> 'tsvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'comments', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'submittal_date', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'duedate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_adminreg_feature', 'fieldname'=> 'entity_type'),
    ),
    'resultid' => 'wl_reportreceived_id',
  );

  return $wfmap;
}

function dh_webform_gw2_revision() {
  $wfmap = array();
  // first thing needs to be a registration record, with VDH as authority
  // then, all contact records can refer back to that registration record
  // alternatively, we could allow adminreg contact records to link to facilities and/or wells
  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Facility',
    'bundle' => 'facility',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_location'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_facility', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_address', 'fieldname'=> 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_state', 'fieldname'=> 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_zip', 'fieldname'=> 'postal_code'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_fa_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'facilityid',
  );
  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Well',
    'bundle' => 'well',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_facility_mps'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_num', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_use', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_depth', 'fieldname' => 'dh_welldepth'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_mps_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      // add geometry support, only one of the next two will get used
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'wellid',
    'writeback' => array(
      'well_id' => 'wellid',
    ),
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ Well Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'deq_well_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'deq_wellno'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_deq_well_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deqwellnumber_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH HDIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_hdin', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_hdin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_hdin_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_hdin_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH PWSID',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_pwsid', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_pwsid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_pwsid_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_pwsid_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'USGS Local',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'usgs_local_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'usgs_local'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_usgs_local_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'usgslocal_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geothermal Well Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'geothermal_well_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geothermal_well_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geothermal_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'geothermal_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Cooling Heating Discharge Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Cooling Heating Discharge', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cooling_heating_discharge'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_cooling_heating_discharge', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'coolingheating_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Subdivision',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'subdivision_name', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_subdivision'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_subdivision_name', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'subdivision_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Section',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'section', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_section'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_section', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'section_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Block',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'block', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_block'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_block', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'block_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lot Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'lot_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_lot_no'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lot_no', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'lot_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Tax Map/GPIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'tax_map_gpin_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_tax_map_gpin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_tax_map_gpin', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'tax_map_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lat/Long Source',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_source', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'spatial_data_source'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lat_long_source', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'latlong_source_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Location Info Collected By',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_collector', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_data_collector'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_location_information_collected_by', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'spatial_data_collector_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Location Description',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'physical_location_description', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'location_description'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'location_description_pid',
  );
  
  //Construction Event
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Construction Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_started', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'tsendtime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_event'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_class_well', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_depth', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_construction_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction Start Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'construction_start_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_st_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_started', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'const_date_started_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction End Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'construction_completion_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_comp_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'const_date_ended_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Rig',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'type_of_rig', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'rig_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_rig_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'rig_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Class Well',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'class_well', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_clss'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_class_well', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'class_well_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Construction Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_construction_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_construction_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'const_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Borehole Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'borehole_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'borehole_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_borehole_depth', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'borehole_depth_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth to Bedrock',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'depth_to_bedrock', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'bdrck_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_depth_to_bedrock', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'bedrock_depth_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Finish Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_finish_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_finish_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_finish_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_finish_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Seal',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'seal_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_seal_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_seal_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'seal_type_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Camera Survey',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_construction_camera_survey', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_camera_survey'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_camera_survey', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'camera_survey_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Camera Survey Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'camera_survey_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'camera_survey_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'camera_survey_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'camera_survey_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Construction Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_construction_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_construction_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_construction_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_well_const_comments_propid',
  );

  //Disinfection Section
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Disinfection Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfection_date', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_contact_time_hrs', 'fieldname'=> 'tsendtime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfection_event'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfectant', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfectant_vol_gal', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'disinfection_event',
  );
  
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Disinfected',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'disinfected', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfected'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfected', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'disinfected_pid',
  );
  
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Disinfection Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'disindate', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfect_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfect_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'disinfect_date_pid',
  );


  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Static Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'swl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'swl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'swl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'SWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'swl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stbwl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stbwl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'stbwl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'STBWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'stbwl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Test Pump Intake Depth (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'test_pmp_int_dpt', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'test_pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_pmp_int_dpt', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'test_pmp_int_dpt_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_gpm', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stb_yld_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield Time (hrs)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_hrs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_hrs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_hrs', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'stb_yld_hrs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_obs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_obs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_obs', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'q_nat_obs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow Rate (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_gpm', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'q_nat_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'pmp_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Horsepower',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_hp', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_hp'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_hp', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'pmp_hp_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Production Pump Intake Depth (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_int_dpt', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_int_dpt', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_int_dpt_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Rated Capacity (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_cap_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth of Capacity Measurement (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap_hd', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap_hd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap_hd', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'pmp_cap_hd_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Hole Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_hole_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_hole_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_hole_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_casing_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_casing_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Height',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'casing_height', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'casing_height'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_height', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_casing_height_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'casing_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'casing_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_depth', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_casing_depth_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Screen Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_screen_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_screen_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_screen_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Water Zone Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_waterzone_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_waterzone_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_waterzone_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Gravel Pack Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_gravelpack_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_gravelpack_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_gravelpack_propid',
  );  

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Grout Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_grout_intervals', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_grout_intervals', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_grout_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Formation',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_formation', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'formation'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_formation', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_formation_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type Logs',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_type_logs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'type_logs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_log_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_typelog_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lithology',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'lithology'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lithology', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_lithology_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Cuttings',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'cutt_strd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_cuttings', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_cuttings_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Province',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_province', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'province'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_province', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_province_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Aquifer Test Performed',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'aquifer_test'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aquifer_test', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_aquifer_test_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Map Used',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_map', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_map'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_map_used', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_map_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'WQ Results',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_wq_results_attached', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'wq_results_const'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_wq_results', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_wq_results_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geologic Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geologic_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geologic_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_geologic_comments_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Drillers Log',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_drillers_log', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_drillers_log', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_drillerslog_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'Driller Log Upload',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // entity reference based on resultid
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW2 Drillers Log', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW2 Drillers Log', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Drillers Log Upload', 'fieldname' => 'description'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'gw2_upload_drillers_log', 'fieldname'=> 'field_dha_submittal_document'),
    ),
    'resultid' => 'gw2_drillerslogupload',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Drillers Log Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_drillers_log_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_log_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_drillers_log_comments', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_drillerslogcomments_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller Certification',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_driller_certification', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_driller_certification'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_certification', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'gw2_driller_certification_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Well Driller Signature',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_well_driller_signature', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_driller_signature'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_driller_signature', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_driller_signature_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller Certification Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_driller_certification_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_certification_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_certification_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'gw2_certification_date_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'GW2 Driller License Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_driller_license_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'driller_license_number'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_license_number', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_license_number_propid',
  );

  // submittal is the actual GW-2 form, which is linked to the Webform document
  // Sys provider is the permittee who makes the submittal
  // submittal is linked to the facility via dh_link_feature_submittal
  // submittal is linked to the SysProvider via dh_link_admin_submittal_pr
  // sys provider is be linked to the facility via dh_link_admin_location
  // sys provider is be linked to the well via dh_link_admin_location
  
  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'GW-2 Submittal Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_gw2_submittal'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_revision', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'constant', 'refvalue' => 1, 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'gw2_revision_event',
  );
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Revision Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_submittal_modification', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Revision', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'submittal_id', 'fieldname'=> 'field_dha_link_modification'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_revision_event', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'gw2_form_upload', 'fieldname'=> 'field_dha_submittal_document'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_revision_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Revision Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => false,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_revision_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  ); 
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Add Submittal to Driller Record',
    'bundle' => 'dh_adminreg_contact',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'driller_id', 'fieldname' => 'contactid'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'fieldname'=> 'dh_link_admin_contact'),
    ),
    'resultid' => '',
  ); 
    
  // 
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Owner',
    'bundle' => 'dh_adminreg_contact',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_revision_id', 'fieldname'=> 'dh_link_admin_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'constant', 'refvalue' => 'owner', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_lastname', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_address', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_zip', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_phone', 'fieldname' => 'phone'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
    ),
    'resultid' => 'ownerid',
  );

  // the driller contact will be passed in via a URL, 
  // all we need to do is to connect the driller contact record to the Registration record
  // can we do this?  This requires a new kind of handler... "entity_references"
  //$wfmap[] = array(
  //  'entity' => 'entityreference',
  //  'description' => 'Driller',
  //  'bundle' => 'entityreference',
  //  'debug' => FALSE,
  //  'entity_references' => array( 
  //    array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'webform_targettype' => 'form_key', 'targetvalue' => 'driller_id', 'fieldname'=> 'dh_link_admin_contact'),
  //  ),
  //);
  
  return $wfmap;
}

function dh_webform_gw2_revision_test() {
  $wfmap = array();
  // first thing needs to be a registration record, with VDH as authority
  // then, all contact records can refer back to that registration record
  // alternatively, we could allow adminreg contact records to link to facilities and/or wells
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Revision Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'driller_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_submittal_modification', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Revision', 'fieldname' => 'name'),
      array('webform_reftype' => 'constant', 'refvalue' => '', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'submittal_id', 'fieldname'=> 'field_dha_link_modification'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_certification_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'well_id', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'facility_id', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'file_form_key', 'notnull' => true, 'refvalue' => 'gw2_form_upload', 'fieldname'=> 'field_dha_submittal_document'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_revision_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Revision Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => false,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'driller_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_revision_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  );
  return $wfmap;

}

function dh_webform_gw2_pump_modification() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Static Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'swl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'swl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'SWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'swl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'swl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'SWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_test_swl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'swl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Water Level (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stbwl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stbwl_date_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'STBWL Test Method',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stbwl_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stbwl_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'STBWL Pump Test Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    'notnull_fields' => array('tstime'), // if they do supply a time, we will record the event, otherwise, the info gets stored in properties only
    'handler' => 'dh_webform_insert_timeseries', // NOT USED YET - could later add custom functions
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname'=> 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_date', 'fieldname'=> 'tstime'),
      array('entity' => 'dh_variabledefinition', 'webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stbwl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_method', 'fieldname'=> 'tstext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stbwl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'stbwl_ft_event',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_gpm', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stb_yld_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Stabilized Yield Time (hrs)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'stb_yld_hrs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'stb_yld_hrs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_stb_yld_hrs', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'stb_yld_hrs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_obs', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_obs'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_obs', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'q_nat_obs_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Natural Flow Rate (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'q_nat_gpm', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'q_nat_gpm'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_q_nat_gpm', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'q_nat_gpm_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_type', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pmp_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Horsepower',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_hp', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_hp'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_hp', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pmp_hp_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Production Pump Intake Depth (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_int_dpt', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_int_dpt'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_int_dpt', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pmp_int_dpt_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Rated Capacity (gpm)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pmp_cap_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth of Capacity Measurement (ft)',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'pmp_cap_hd', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pmp_cap_hd'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pmp_cap_hd', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pmp_cap_hd_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Plumbing Size',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_plumbing_size', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plumbing_size'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_plumb_size', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'gw2_plumbingsize_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Plumbing Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_plumbing_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plumbing_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_plumb_type', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'gw2_plumbingtype_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_pump_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pump_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_comments', 'fieldname'=> 'proptext'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pumpcomment_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Pump Setting Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'pump_setting_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'pumpcomment_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Pump Modification Submittal Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_pumpmodification', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Pump Modification Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_comments', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_pump_setting_date', 'fieldname'=> 'startdate'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_submittal_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Pump Modification Submittal Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_submittal_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  );
  return $wfmap;
}

function dh_webform_gw2_full_abandonment() {
  $wfmap = array();
  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Facility',
    'bundle' => 'facility',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_location'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_facility', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_address', 'fieldname'=> 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_state', 'fieldname'=> 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_zip', 'fieldname'=> 'postal_code'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_fa_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'facilityid',
  );

  $wfmap[] = array(
    'entity' => 'dh_feature',
    'description' => 'dH Well',
    'bundle' => 'well',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_facility_mps'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_num', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname' => 'description'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_type_of_use', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'abandoned', 'fieldname' => 'fstatus'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_depth', 'fieldname' => 'dh_welldepth'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_elevation', 'fieldname' => 'dh_landelev'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
      array('webform_reftype' => 'EntityFieldQuery_eref', 'fieldname'=> 'dh_link_admin_mps_usafips', 'entity' => 'dh_feature', 'notnull' => TRUE, 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'field_webformkey', 'field' => 'dh_fips', 'property' => 'value', 'value' => 'gw2_locality'), 
        ),
      ),
      // add geometry support, only one of the next two will get used
      // same info for well and facility
      // Geometry given in DD
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat'=>'gw2_latitude', 'lon'=>'gw2_longitude', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
      // Geometry given in DMS
      array('webform_reftype' => 'geo_point_form_key', 'notnull' => true, 'refvalue' => array('lat_deg'=>'gw2_latitude_degrees', 'lat_min' => 'gw2_latitude_minutes', 'lat_sec'=>'gw2_latitude_seconds', 'lon_deg'=>'gw2_longitude_degrees', 'lon_min'=>'gw2_longitude_minutes', 'lon_sec' => 'gw2_longitude_seconds', 'srid'=>'gw2_horizontal_datum_source'), 'fieldname' => 'dh_geofield'),
    ),
    'resultid' => 'wellid',
    'writeback' => array(
      'well_id' => 'wellid',
    ),
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'DEQ Well Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'deq_well_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'deq_wellno'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_deq_well_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'deqwellnumber_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH HDIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_hdin', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_hdin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_hdin_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_hdin_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'VDH PWSID',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'vdh_pwsid', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vdh_pwsid'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_vdh_pwsid_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'vdh_pwsid_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'USGS Local',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'usgs_local_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'usgs_local'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_usgs_local_number', 'fieldname'=> 'propcode'),
    ),
    'resultid' => 'usgslocal_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Geothermal Well Type',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'geothermal_well_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'geothermal_well_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_geothermal_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'geothermal_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Subdivision',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'subdivision_name', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_subdivision'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_subdivision_name', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'subdivision_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Section',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'section', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_section'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_section', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'section_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Block',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'block', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_block'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_block', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'block_pid',
  ); 

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lot Number',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'lot_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_lot_no'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lot_no', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'lot_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Tax Map/GPIN',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'facilityid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'tax_map_gpin_number', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'plat_tax_map_gpin'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_tax_map_gpin', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'tax_map_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Lat/Long Source',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_source', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'spatial_data_source'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_lat_long_source', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'latlong_source_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Location Info Collected By',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'spatial_data_collector', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'vadeq_data_collector'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_location_information_collected_by', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'spatial_data_collector_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Location Description',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'physical_location_description', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'location_description'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_physical_location_description', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'location_description_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Well Abandoned Event',
    'bundle' => 'dh_timeseries',
    'debug' => false,
    //'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned'), 
        ),
      ),
      array('webform_reftype' => 'constant', 'refvalue' => '1', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_abandoned_event_tid',
  );

  $wfmap[] = array(
    'entity' => 'dh_timeseries',
    'description' => 'Static Water Level at Well Abandoned',
    'bundle' => 'dh_timeseries',
    'debug' => FALSE,
    'notnull_fields' => array('tsvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_abandoned_date', 'fieldname'=> 'tstime'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'tsendtime'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_swl_ft', 'fieldname'=> 'tsvalue'),
    ),
    'resultid' => 'well_abandoned_swl_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Well Abandoned',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_abandoned', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_abandoned', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'well_abandoned_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Start Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('startdate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'abandate', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'abandate_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Completion Date',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('enddate'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'abandate_complete', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandoned_date'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandate_complete', 'fieldname'=> 'enddate'),
    ),
    'resultid' => 'abandate_complete_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Type of Rig',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'aband_rig_type', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'rig_type'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_rig_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'aband_rig_type_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Static Water Level at Abandonment',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'aband_swl_ft', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'swl_ft'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_aband_swl_ft', 'fieldname'=> 'propvalue'),
    ),
    'resultid' => 'aband_swl_ft_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Pulled',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    //'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_casing_pulled', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_casing_pulled'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_casing_pulled', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_casing_pulled_comment', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_casing_pulled',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Depth of and Type Fill',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    //'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_fill_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_fill_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_fill_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_fill_type', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_fill_depth_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Casing Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('featureid'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_casing_intervals_abandonment', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_casing_abandon', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_casing_abandonment_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Grout Abandonment Table',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_grout_intervals_abandonment', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'other_data'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_grout_abandon', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'gw2_grout_abandonment_propid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Method of Location Marking',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_marking_method', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_marking_method'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_well_marking_method', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_marking_method_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Abandonment Comments',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('proptext'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'well_abandonment_comments', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'well_abandonment_comments'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandonment_comment', 'fieldname'=> 'proptext'),
    ),
    'resultid' => 'well_abandon_comments_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Borehole Depth',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'borehole_depth', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'borehole_depth'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_borehole_depth', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_date_completed', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'borehole_depth_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_properties',
    'description' => 'Disinfected',
    'bundle' => 'dh_properties',
    'debug' => FALSE,
    'notnull_fields' => array('propvalue'),
    'handler' => 'dh_webform_insert_property', // a function to handle this record type. we should have a default function to handle easy cases for each dH Entity Type, but allow custom functions too
    'fields' => array(
      array('webform_reftype' => 'result', 'refvalue' => 'wellid', 'fieldname' => 'featureid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'dh_feature', 'fieldname'=> 'entity_type'),
      array('webform_reftype' => 'constant', 'refvalue' => 'disinfected', 'fieldname'=> 'propname'),
      array('webform_reftype' => 'EntityFieldQuery', 'fieldname'=> 'varid', 'entity' => 'dh_variabledefinition', 'queryfield' => 'hydroid', 'queryparams' => array(
        array('type' => 'property', 'property' => 'varkey', 'value' => 'disinfected'), 
        ),
      ),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfected', 'fieldname'=> 'propvalue'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_disinfected_date', 'fieldname'=> 'startdate'),
    ),
    'resultid' => 'disinfected_pid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Add Submittal to Driller Record',
    'bundle' => 'dh_adminreg_contact',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      array('webform_reftype' => 'form_key', 'refvalue' => 'driller_id', 'fieldname' => 'contactid'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'fieldname'=> 'dh_link_admin_contact'),
    ),
    'resultid' => '',
  ); 
    
  // 
  $wfmap[] = array(
    'entity' => 'dh_adminreg_contact',
    'description' => 'Owner',
    'bundle' => 'dh_adminreg_contact',
    'debug' => FALSE,
    'fields' => array( 
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'gw2_submittal_id', 'fieldname'=> 'dh_link_admin_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'facilityid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_contact'),
      array('webform_reftype' => 'constant', 'refvalue' => 'owner', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_name', 'fieldname' => 'firstname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_lastname', 'fieldname' => 'lastname'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_address', 'fieldname' => 'address1'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_city', 'fieldname' => 'city'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_state', 'fieldname' => 'state'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_zip', 'fieldname' => 'postal_code'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_owner_phone', 'fieldname' => 'phone'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_email', 'fieldname' => 'email'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname' => 'modified'),
    ),
    'resultid' => 'ownerid',
  );

  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Abandonment Submittal Doc',
    'bundle' => 'submittal',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'constant', 'refvalue' => 'gw2_abandonment', 'fieldname' => 'ftype'),
      array('webform_reftype' => 'constant', 'refvalue' => 'GW-2 Form Submission', 'fieldname' => 'name'),
      array('webform_reftype' => 'form_key', 'refvalue' => 'gw2_abandonment_comment', 'fieldname' => 'description'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'gw2_provider_id', 'fieldname'=> 'dh_link_admin_submittal_pr'),
      array('webform_reftype' => 'entity_reference_rid', 'refvalue' => 'well_abandoned_event_tid', 'fieldname'=> 'dh_link_admin_timeseries'),
      array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'wellid', 'fieldname'=> 'dh_link_feature_submittal'),
      array('webform_reftype' => 'env', 'refvalue' => 'now', 'fieldname'=> 'modified'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
    ),
    'resultid' => 'gw2_submittal_id',
  ); 
  
  $wfmap[] = array(
    'entity' => 'dh_adminreg_feature',
    'description' => 'GW-2 Abandonment Submittal Doc',
    'bundle' => 'submittal',
    'hook' => 'insert',
    'debug' => FALSE,
    'fields' => array(
      // this link is not yet active
      //array('webform_reftype' => 'entity_reference_formkey', 'refvalue' => 'organization_id', 'fieldname' => 'dh_link_admin_submittal_org'),
      array('webform_reftype' => 'result', 'refvalue' => 'gw2_submittal_id', 'fieldname' => 'adminid'),
      array('webform_reftype' => 'constant', 'refvalue' => 'Webform Form', 'fieldname' => 'formtype'),
      array('webform_reftype' => 'entity_reference_env', 'refvalue' => 'sid', 'fieldname' => 'dh_link_webform_submittal'),
    ),
    'resultid' => '',
  );
  return $wfmap;
}
  
?>
