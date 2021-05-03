<?php

/**
 * Implements hook_views_default_views().
 */
function dh_adminreg_views_default_views() {
   $views = array();
   $views['dh_contacts'] = dh_adminreg_views_contacts();
   $views['dha_entity_contacts'] = dh_adminreg_views_entity_contacts();
   $views['dha_organization_contacts'] = dh_adminreg_views_org_contacts();
   $views['dha_organization_facilities'] = dh_adminreg_views_org_facilities();
   $views['dha_organization_tabs'] = dh_adminreg_views_org_tabs();
   $views['dha_permit_tabs'] = dh_adminreg_views_permit_tabs();
   $views['dha_registrant_tabs'] = dh_adminreg_views_registrant_tabs();
   $views['dh_adminreg_add_list_facility'] = dh_adminreg_views_add_list_facility();
   $views['dh_adminreg_add_list_organization'] = dh_adminreg_views_add_list_organization();
   $views['dh_adminreg_add_list_permit_reg'] = dh_adminreg_views_add_list_permit_reg();
   $views['dh_adminreg_add_list_mp'] = dh_adminreg_views_add_list_mp();
   $views['dh_adminreg_agencies_offices'] = dh_adminreg_views_agencies_offices();
   $views['dha_facility_tabs'] = dh_adminreg_views_facility_tabs();
   $views['dha_monitoring_points'] = dh_adminreg_views_monitoring_points();
   $views['dha_map_monitoring_points'] = dh_adminreg_views_map_monitoring_points();
   $views['dha_breadcrumb_facility'] = dh_adminreg_views_breadcrumb_facility();
   $views['dha_breadcrumb_mp'] = dh_adminreg_views_breadcrumb_mp();
   $views['dha_breadcrumb_pr'] = dh_adminreg_views_breadcrumb_pr();
   $views['dha_breadcrumb_org'] = dh_adminreg_views_breadcrumb_org();
   $views['dha_search_entities'] = dh_adminreg_views_search_entities();
   $views['dha_pr_facilities'] = dh_adminreg_views_dha_pr_facilities();
   $views['dha_entity_submittals'] = dh_adminreg_views_dha_entity_submittals();
   $views['dha_manage_ar_contact'] = dh_adminreg_views_dha_manage_ar_contact();
   return $views;
}


function dh_adminreg_views_add_list_mp() {
  $view = new view();
  $view->name = 'dha_add_list_mp';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Add List - MP';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Add List - MP';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['id'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['table'] = 'field_data_dh_link_facility_mps';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['field'] = 'dh_link_facility_mps_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['id'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['table'] = 'field_data_dh_link_admin_location';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['field'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['relationship'] = 'dh_link_facility_mps_target_id';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_2']['id'] = 'hydroid_2';
  $handler->display->display_options['fields']['hydroid_2']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_2']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_2']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['hydroid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_2']['separator'] = '';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['label'] = '';
  $handler->display->display_options['fields']['hydroid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['text'] = 'Water Use Reporting Form';
  $handler->display->display_options['fields']['hydroid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['path'] = 'waterusecompliance/';
  $handler->display->display_options['fields']['hydroid_1']['alter']['path_query_parameters'] = 'admin_id=[hydroid]&permit_id=[adminid]';
  $handler->display->display_options['fields']['hydroid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_3']['id'] = 'hydroid_3';
  $handler->display->display_options['fields']['hydroid_3']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_3']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['text'] = 'Water Quality Reporting Form';
  $handler->display->display_options['fields']['hydroid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['path'] = 'dh_water_quality/form/';
  $handler->display->display_options['fields']['hydroid_3']['alter']['path_query_parameters'] = '&edit[featureid]=[hydroid]&destination=dh-feature-detail/[hydroid]/';
  $handler->display->display_options['fields']['hydroid_3']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_4']['id'] = 'hydroid_4';
  $handler->display->display_options['fields']['hydroid_4']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_4']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_4']['label'] = 'WQ Reporting';
  $handler->display->display_options['fields']['hydroid_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_4']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_4']['alter']['text'] = 'Water Quality Compliance Reporting';
  $handler->display->display_options['fields']['hydroid_4']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_4']['alter']['path'] = 'waterqualitycompliance/';
  $handler->display->display_options['fields']['hydroid_4']['alter']['path_query_parameters'] = 'admin_id=[hydroid]&permit_id=[adminid]';
  $handler->display->display_options['fields']['hydroid_4']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_5']['id'] = 'hydroid_5';
  $handler->display->display_options['fields']['hydroid_5']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_5']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_5']['label'] = 'Interval Data';
  $handler->display->display_options['fields']['hydroid_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_5']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_5']['alter']['text'] = 'Add Borehole Log/Interval Data';
  $handler->display->display_options['fields']['hydroid_5']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_5']['alter']['path'] = 'intervalentry/';
  $handler->display->display_options['fields']['hydroid_5']['alter']['path_query_parameters'] = 'hydro_id=[hydroid]';
  $handler->display->display_options['fields']['hydroid_5']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
    <li>[hydroid_1]
    <li>[hydroid_4]
    <li>[hydroid_5]
    </ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-adminreg-addlist-mp';
  return $view;

}


function dh_adminreg_views_dha_entity_submittals() {
  $view = new view();
  $view->name = 'dha_entity_submittals';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Entity Submittals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Entity Submittals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'tstime',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'ftype',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'adminid' => 'adminid',
    'ftype' => 'ftype',
    'tstime' => 'tstime',
    'modified' => 'modified',
    'propname' => 'propname',
    'propvalue' => 'propvalue',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adminid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ftype' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tstime' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'modified' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'propname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'propvalue' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Linked permit/Reg */
  $handler->display->display_options['relationships']['dh_link_admin_submittal_pr_target_id']['id'] = 'dh_link_admin_submittal_pr_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_submittal_pr_target_id']['table'] = 'field_data_dh_link_admin_submittal_pr';
  $handler->display->display_options['relationships']['dh_link_admin_submittal_pr_target_id']['field'] = 'dh_link_admin_submittal_pr_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_submittal_pr_target_id']['ui_name'] = 'Linked permit/Reg';
  $handler->display->display_options['relationships']['dh_link_admin_submittal_pr_target_id']['label'] = 'Linked permit/Reg';
  /* Relationship: Time Series Date Received from Permit/Reg */
  $handler->display->display_options['relationships']['dh_link_admin_timeseries_target_id']['id'] = 'dh_link_admin_timeseries_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_timeseries_target_id']['table'] = 'field_data_dh_link_admin_timeseries';
  $handler->display->display_options['relationships']['dh_link_admin_timeseries_target_id']['field'] = 'dh_link_admin_timeseries_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_timeseries_target_id']['ui_name'] = 'Time Series Date Received from Permit/Reg';
  $handler->display->display_options['relationships']['dh_link_admin_timeseries_target_id']['label'] = 'Time Series Date Received from Permit/Reg';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['exclude'] = TRUE;
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['relationship'] = 'dh_link_admin_timeseries_target_id';
  $handler->display->display_options['fields']['tstime']['label'] = 'Date Submitted';
  $handler->display->display_options['fields']['tstime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tstime']['date_format'] = 'medium';
  $handler->display->display_options['fields']['tstime']['second_date_format'] = 'long';
  /* Field: DH AdminReg Feature: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['label'] = 'Entered/Updated';
  $handler->display->display_options['fields']['modified']['date_format'] = 'short';
  $handler->display->display_options['fields']['modified']['second_date_format'] = 'long';
  /* Field: DH Properties: Property Name */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  /* Field: DH Properties: Propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['precision'] = '0';
  $handler->display->display_options['fields']['propvalue']['separator'] = '';
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['text'] = 'Edit Record';
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['path'] = 'admin/content/dh_properties/manage/[pid]';
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['relationship'] = 'dh_link_admin_submittal_pr_target_id';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'submittal' => 'submittal',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-entity-submittals';

  return $view;
}

function dh_adminreg_views_dha_pr_facilities() {
  $view = new view();
  $view->name = 'dha_pr_facilities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - PR Facilities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Permit-Reg Facilities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'adminid' => 'adminid',
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adminid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Link to Facilty */
  $handler->display->display_options['relationships']['reverse_dh_link_admin_location_dh_feature']['id'] = 'reverse_dh_link_admin_location_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_location_dh_feature']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_location_dh_feature']['field'] = 'reverse_dh_link_admin_location_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_location_dh_feature']['ui_name'] = 'Link to Facilty';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_location_dh_feature']['label'] = 'Link to Facilty';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['ui_name'] = 'Bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['relationship'] = 'reverse_dh_link_admin_location_dh_feature';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_dh_link_admin_location_dh_feature';
  $handler->display->display_options['fields']['name']['label'] = 'Facility Name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dha-facility-tabs/[hydroid]/info';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'permit' => 'permit',
    'registration' => 'registration',
  );

  /* Display: Facilities */
  $handler = $view->new_display('page', 'Facilities', 'page_1');
  $handler->display->display_options['path'] = 'dha-org-facilities';
  return $view;
}

function dh_adminreg_views_breadcrumb_pr() {
  $view = new view();
  $view->name = 'dha_breadcrumb_pr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Breadcrumb - Permit/Reg';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Breadcrumb - MP';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_3' => 'name_3',
    'name_2' => 'name_2',
    'name_1' => 'name_1',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: PR to Org (Reg Holder) */
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['id'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['table'] = 'field_data_dh_link_admin_reg_holder';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['field'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['ui_name'] = 'PR to Org (Reg Holder)';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['label'] = 'PR to Org (Reg Holder)';
  /* Field: P/R ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['adminid']['ui_name'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['label'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Org ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['label'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Home';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'adash1/';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['name_3']['label'] = '';
  $handler->display->display_options['fields']['name_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['path'] = 'dha-organization-tabs/[adminid_1]/info';
  $handler->display->display_options['fields']['name_3']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['alter']['path'] = 'dha-[bundle]-tabs/[adminid]/info';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-breadcrumb-pr';

  return $view;
}

function dh_adminreg_views_breadcrumb_org() {
  $view = new view();
  $view->name = 'dha_breadcrumb_org';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Breadcrumb - Org';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Breadcrumb - Org';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_1' => 'name_1',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = 'Home';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['path'] = 'adash1/';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-breadcrumb-org';

  return $view;
}

function dh_adminreg_views_breadcrumb_mp() {
  $view = new view();
  $view->name = 'dha_breadcrumb_mp';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Breadcrumb - MP';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Breadcrumb - MP';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_4' => 'name_4',
    'name_3' => 'name_3',
    'name_2' => 'name_2',
    'name_1' => 'name_1',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: MP to Facility */
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['id'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['table'] = 'field_data_dh_link_facility_mps';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['field'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['ui_name'] = 'MP to Facility';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['label'] = 'MP to Facility';
  $handler->display->display_options['relationships']['dh_link_facility_mps_target_id']['required'] = TRUE;
  /* Relationship: Permit/Reg Link */
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['id'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['table'] = 'field_data_dh_link_admin_location';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['field'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['ui_name'] = 'Permit/Reg Link';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['label'] = 'Facility to P/R';
  /* Relationship: PR to Org (Reg Holder) */
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['id'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['table'] = 'field_data_dh_link_admin_reg_holder';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['field'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['ui_name'] = 'PR to Org (Reg Holder)';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['label'] = 'PR to Org (Reg Holder)';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Facility ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['hydroid_1']['ui_name'] = 'Facility ID';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'Facility ID';
  $handler->display->display_options['fields']['hydroid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: P/R ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['adminid']['ui_name'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['label'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Org ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['label'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name_4']['id'] = 'name_4';
  $handler->display->display_options['fields']['name_4']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name_4']['field'] = 'name';
  $handler->display->display_options['fields']['name_4']['label'] = '';
  $handler->display->display_options['fields']['name_4']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_4']['alter']['text'] = 'Home';
  $handler->display->display_options['fields']['name_4']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_4']['alter']['path'] = 'adash1/';
  $handler->display->display_options['fields']['name_4']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['name_3']['label'] = '';
  $handler->display->display_options['fields']['name_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['path'] = 'dha-organization-tabs/[adminid_1]/info';
  $handler->display->display_options['fields']['name_3']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['path'] = 'dha-[bundle]-tabs/[adminid]/info';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['path'] = 'dha-facility-tabs/[hydroid_1]/mps';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-breadcrumb-mp';
  return $view;
}

function dh_adminreg_views_breadcrumb_facility() {
  $view = new view();
  $view->name = 'dha_breadcrumb_facility';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Breadcrumb - Facility';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Breadcrumb - MP';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_3' => 'name_3',
    'name_2' => 'name_2',
    'name_1' => 'name_1',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Permit/Reg Link */
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['id'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['table'] = 'field_data_dh_link_admin_location';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['field'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['ui_name'] = 'Permit/Reg Link';
  $handler->display->display_options['relationships']['dh_link_admin_location_target_id']['label'] = 'Facility to P/R';
  /* Relationship: PR to Org (Reg Holder) */
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['id'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['table'] = 'field_data_dh_link_admin_reg_holder';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['field'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['ui_name'] = 'PR to Org (Reg Holder)';
  $handler->display->display_options['relationships']['dh_link_admin_reg_holder_target_id']['label'] = 'PR to Org (Reg Holder)';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Facility ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['ui_name'] = 'Facility ID';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'Facility ID';
  $handler->display->display_options['fields']['hydroid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: P/R ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['adminid']['ui_name'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['label'] = 'P/R ID';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Org ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['label'] = 'Org ID';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Home';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'adash1/';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'dh_link_admin_reg_holder_target_id';
  $handler->display->display_options['fields']['name_3']['label'] = '';
  $handler->display->display_options['fields']['name_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_3']['alter']['path'] = 'dha-organization-tabs/[adminid_1]/info';
  $handler->display->display_options['fields']['name_3']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['path'] = 'dha-[bundle]-tabs/[adminid]/info';
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['path'] = 'dha-facility-tabs/[hydroid_1]/mps';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-breadcrumb-fac';
  return $view;
}

function dh_adminreg_views_map_monitoring_points() {
  $view = new view();
  $view->name = 'dha_monitoring_points_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Monitoring Points Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Monitoring Points Map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'dh_geofield';
  $handler->display->display_options['style_options']['name_field'] = 'name';
  $handler->display->display_options['style_options']['description_field'] = 'name';
  $handler->display->display_options['style_options']['map'] = 'google-high-res';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '14';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['id'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['table'] = 'dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['field'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['label'] = 'Linked MPs';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['required'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Facility Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'MP Feature ID';
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'dh_link_facility_mps_target_id';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Facility Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'MP Feature ID';
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dh-[bundle]-detail/[hydroid_1]/info';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['dh_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['path'] = 'dha-feature-mps-map';
  $handler->display->display_options['menu']['title'] = 'MPs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}

function dh_adminreg_views_monitoring_points() {
  $view = new view();
  $view->name = 'dha_monitoring_points';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Monitoring Points';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Monitoring Points';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'dh_geofield';
  $handler->display->display_options['style_options']['name_field'] = 'name';
  $handler->display->display_options['style_options']['description_field'] = 'name';
  $handler->display->display_options['style_options']['map'] = 'google-high-res';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['id'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['table'] = 'dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['field'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['label'] = 'Monitoring Points';
  $handler->display->display_options['relationships']['reverse_dh_link_facility_mps_dh_feature']['required'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Facility Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'MP Feature ID';
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'dh_link_facility_mps_target_id';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;
  /* Filter criterion: dH Feature: Geometry (dh_geofield:geom) */
  $handler->display->display_options['filters']['dh_geofield_geom']['id'] = 'dh_geofield_geom';
  $handler->display->display_options['filters']['dh_geofield_geom']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['filters']['dh_geofield_geom']['field'] = 'dh_geofield_geom';
  $handler->display->display_options['filters']['dh_geofield_geom']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['filters']['dh_geofield_geom']['operator'] = 'not empty';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'hydroid' => 'hydroid',
    'hydroid_1' => 'hydroid_1',
    'name' => 'name',
    'dh_geofield' => 'dh_geofield',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'hydroid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hydroid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dh_geofield' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Facility Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['label'] = 'MP Feature ID';
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dh-[bundle]-detail/[hydroid_1]';
  $handler->display->display_options['fields']['name']['empty'] = 'un-named';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['relationship'] = 'reverse_dh_link_facility_mps_dh_feature';
  $handler->display->display_options['fields']['dh_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'dha-feature-mps';
  $handler->display->display_options['menu']['title'] = 'MPs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  return $view;
}

function dh_adminreg_views_entity_contacts() {
  $view = new view();
  $view->name = 'dha_entity_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - AR Feature Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Entity Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'adminid' => 'adminid',
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adminid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Linked Contact */
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['id'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['field'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['ui_name'] = 'Linked Contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['label'] = 'Linked Contact';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Contact: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['label'] = 'Title';
  /* Field: DH AdminReg Contact: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['ftype']['label'] = 'Contact Type';
  $handler->display->display_options['fields']['ftype']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['ftype']['alter']['path'] = 'dha-manage-contact/[contactid]';
  /* Field: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['fields']['contactid']['id'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid']['field'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid']['label'] = '';
  $handler->display->display_options['fields']['contactid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contactid']['alter']['text'] = 'View Full Contact';
  $handler->display->display_options['fields']['contactid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contactid']['alter']['path'] = 'dha-manage-contact/[contactid]/view';
  $handler->display->display_options['fields']['contactid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contactid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['contactid']['separator'] = '';
  /* Field: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['fields']['contactid_1']['id'] = 'contactid_1';
  $handler->display->display_options['fields']['contactid_1']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid_1']['field'] = 'contactid';
  $handler->display->display_options['fields']['contactid_1']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid_1']['label'] = '';
  $handler->display->display_options['fields']['contactid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contactid_1']['alter']['text'] = 'Edit Contact';
  $handler->display->display_options['fields']['contactid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contactid_1']['alter']['path'] = 'admin/content/dh_adminreg_contact/manage/[contactid_1]';
  $handler->display->display_options['fields']['contactid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contactid_1']['separator'] = '';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_1');
  $handler->display->display_options['path'] = 'dha-entity-contacts';

  return $view;
}

function dh_adminreg_views_search_entities() {
  $view = new view();
  $view->name = 'dh_list_organizations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dh - List Admin Entities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dh - List Organizations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'Type';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Owner/Party Name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dha-[bundle]-tabs/[adminid]/info';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Type';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[bundle]';
  /* Field: DH AdminReg Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'organization' => 'organization',
  );
  $handler->display->display_options['filters']['bundle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle']['expose']['operator_id'] = 'bundle_op';
  $handler->display->display_options['filters']['bundle']['expose']['label'] = 'Select Type';
  $handler->display->display_options['filters']['bundle']['expose']['operator'] = 'bundle_op';
  $handler->display->display_options['filters']['bundle']['expose']['identifier'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['bundle']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['bundle']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: DH AdminReg Feature: Label */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'word';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Search Owner/Responsible Party Name';
  $handler->display->display_options['filters']['name']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-list-adminfeatures';
  return $view;
}

function dh_adminreg_views_facility_tabs() {
  $view = new view();
  $view->name = 'dha_facility_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dHA - Facility Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_facility';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!hydroid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = 'Actions';
  $handler->display->display_options['footer']['view_field']['view'] = 'dh_adminreg_add_list_facility';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!hydroid]';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Facility Name';
  /* Field: Field: Address 1 */
  $handler->display->display_options['fields']['address1']['id'] = 'address1';
  $handler->display->display_options['fields']['address1']['table'] = 'field_data_address1';
  $handler->display->display_options['fields']['address1']['field'] = 'address1';
  /* Field: Field: Address 2 */
  $handler->display->display_options['fields']['address2']['id'] = 'address2';
  $handler->display->display_options['fields']['address2']['table'] = 'field_data_address2';
  $handler->display->display_options['fields']['address2']['field'] = 'address2';
  /* Field: Field: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'field_data_city';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  /* Field: Field: State/Province */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'field_data_state';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Field: Zip/Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'field_data_postal_code';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_center' => array(
      'lat' => '37.5391522',
      'lon' => '-77.4398137',
      'geocode' => 'Find my location',
    ),
    'geofield_map_zoom' => '8',
    'geofield_map_min_zoom' => '0',
    'geofield_map_max_zoom' => '0',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'standard',
    'geofield_map_pancontrol' => 1,
    'geofield_map_maptype' => 'map',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 0,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 1,
    'geofield_map_draggable' => 1,
    'geofield_map_streetview_show' => 0,
  );
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-facility-tabs';

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Facility Name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_features/manage/[hydroid]';
  /* Field: Field: Address 1 */
  $handler->display->display_options['fields']['address1']['id'] = 'address1';
  $handler->display->display_options['fields']['address1']['table'] = 'field_data_address1';
  $handler->display->display_options['fields']['address1']['field'] = 'address1';
  /* Field: Field: Address 2 */
  $handler->display->display_options['fields']['address2']['id'] = 'address2';
  $handler->display->display_options['fields']['address2']['table'] = 'field_data_address2';
  $handler->display->display_options['fields']['address2']['field'] = 'address2';
  /* Field: Field: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'field_data_city';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  /* Field: Field: State/Province */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'field_data_state';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Field: Zip/Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'field_data_postal_code';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_center' => array(
      'lat' => '37.5391522',
      'lon' => '-77.4398137',
      'geocode' => 'Find my location',
    ),
    'geofield_map_zoom' => '8',
    'geofield_map_min_zoom' => '0',
    'geofield_map_max_zoom' => '0',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'standard',
    'geofield_map_pancontrol' => 1,
    'geofield_map_maptype' => 'map',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 0,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 1,
    'geofield_map_draggable' => 1,
    'geofield_map_streetview_show' => 0,
  );
  $handler->display->display_options['path'] = 'dha-facility-tabs/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add Contact';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_adminreg_contact/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'dh_feature=[hydroid]';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: List Contacts */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'List Contacts';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_contacts';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dha-facility-tabs/%/contacts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: MPs */
  $handler = $view->new_display('page', 'MPs', 'page_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add Monitoring Point';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_features/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'dh_feature=[hydroid]';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Wells & Intakes Attached to [name]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: MP List */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'MP List';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_monitoring_points';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  /* Field: MP Map */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'MP Map';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'dha_monitoring_points_map';
  $handler->display->display_options['fields']['view_1']['display'] = 'page';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dha-facility-tabs/%/mps';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'MPs';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Misc */
  $handler = $view->new_display('page', 'Misc', 'page_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Facility Name';
  /* Field: Attached Properties */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'Attached Properties';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dha-facility-tabs/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Misc';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}

function dh_adminreg_views_add_list_permit_reg() {
  $view = new view();
  $view->name = 'dh_adminreg_add_list_permit_reg';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dH AdminReg - Add List - Permit-Reg';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH AdminReg - Add List - Permit/Reg';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Add Facility Link */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Add Facility Link';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add New Facility';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newfacility/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'permitreg_id=[adminid]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: Add Contact Link */
  $handler->display->display_options['fields']['adminid_3']['id'] = 'adminid_3';
  $handler->display->display_options['fields']['adminid_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_3']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_3']['ui_name'] = 'Add Contact Link';
  $handler->display->display_options['fields']['adminid_3']['label'] = '';
  $handler->display->display_options['fields']['adminid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['text'] = 'Add Contact';
  $handler->display->display_options['fields']['adminid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['adminid_3']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_3']['separator'] = '';
  /* Field: Link HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Link HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
    <li>[adminid_1]
    <li>[adminid_3]
    </ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: Add Facility Link */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Add Facility Link';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add New Facility';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newfacility/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'permitreg_id=[adminid]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: Add Contact Link */
  $handler->display->display_options['fields']['adminid_3']['id'] = 'adminid_3';
  $handler->display->display_options['fields']['adminid_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_3']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_3']['ui_name'] = 'Add Contact Link';
  $handler->display->display_options['fields']['adminid_3']['label'] = '';
  $handler->display->display_options['fields']['adminid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['text'] = 'Add Contact';
  $handler->display->display_options['fields']['adminid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['adminid_3']['alter']['path_query_parameters'] = 'admin_id=[adminid]&dest=dha-[bundle]-tabs';
  $handler->display->display_options['fields']['adminid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_3']['separator'] = '';
  /* Field: Add Milestone */
  $handler->display->display_options['fields']['adminid_2']['id'] = 'adminid_2';
  $handler->display->display_options['fields']['adminid_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_2']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_2']['ui_name'] = 'Add Milestone';
  $handler->display->display_options['fields']['adminid_2']['label'] = '';
  $handler->display->display_options['fields']['adminid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['text'] = 'Add Milestone';
  $handler->display->display_options['fields']['adminid_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['path'] = 'newmilestone/';
  $handler->display->display_options['fields']['adminid_2']['alter']['path_query_parameters'] = 'admin_id=[adminid]&dest=dha-[bundle]-tabs';
  $handler->display->display_options['fields']['adminid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_2']['separator'] = '';
  /* Field: Link HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Link HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
    <li>[adminid_1]
    <li>[adminid_3]
    <li>[adminid_2]
    </ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'dh-adminreg-add-list-pr';


  return $view;
}
function dh_adminreg_views_agencies_offices() {
  $view = new view();
  $view->name = 'dh_adminreg_agencies_offices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dH AdminReg - Agencies/Offices';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH AdminReg - Agencies/Offices';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  /* Field: DH AdminReg Feature: enddate */
  $handler->display->display_options['fields']['enddate']['id'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['enddate']['field'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['separator'] = '';
  /* Field: DH AdminReg Feature: ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: DH AdminReg Feature: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['separator'] = '';
  /* Field: DH AdminReg Feature: startdate */
  $handler->display->display_options['fields']['startdate']['id'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['startdate']['field'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['separator'] = '';
  /* Field: DH AdminReg Feature: status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['separator'] = '';
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'authority' => 'authority',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-adminreg-agencies-offices';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'dh_ar_export_agencies';

  return $view;
}

function dh_adminreg_views_add_list_organization() {
  $view = new view();
  $view->name = 'dh_adminreg_add_list_organization';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dH AdminReg - Add List - Organization';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH AdminReg - Add List - Organization';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: Add Permit Link */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['ui_name'] = 'Add Permit Link';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add New Permit';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newpermit/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: Add Registration Link */
  $handler->display->display_options['fields']['adminid_2']['id'] = 'adminid_2';
  $handler->display->display_options['fields']['adminid_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_2']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_2']['ui_name'] = 'Add Registration Link';
  $handler->display->display_options['fields']['adminid_2']['label'] = '';
  $handler->display->display_options['fields']['adminid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['text'] = 'Add Registration (non-permit)';
  $handler->display->display_options['fields']['adminid_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['path'] = 'newregistration/';
  $handler->display->display_options['fields']['adminid_2']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_2']['separator'] = '';
  /* Field: Add Contact Link */
  $handler->display->display_options['fields']['adminid_3']['id'] = 'adminid_3';
  $handler->display->display_options['fields']['adminid_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_3']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_3']['ui_name'] = 'Add Contact Link';
  $handler->display->display_options['fields']['adminid_3']['label'] = '';
  $handler->display->display_options['fields']['adminid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['text'] = 'Add Contact';
  $handler->display->display_options['fields']['adminid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['adminid_3']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_3']['separator'] = '';
  /* Field: Link HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Link HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
  <li>[adminid_1]
  <li>[adminid_2]
  <li>[adminid_3]
  </ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-adminreg-add-list-organization';
  return $view;
}

function dh_adminreg_views_add_list_facility() {
  $view = new view();
  $view->name = 'dh_adminreg_add_list_facility';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH AdminReg - Add List - Facility';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH AdminReg - Add List - Facility';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Add Well Link */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['ui_name'] = 'Add Well Link';
  $handler->display->display_options['fields']['hydroid_1']['label'] = '';
  $handler->display->display_options['fields']['hydroid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['text'] = 'Add New Well';
  $handler->display->display_options['fields']['hydroid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['alter']['path'] = 'newwell/';
  $handler->display->display_options['fields']['hydroid_1']['alter']['path_query_parameters'] = 'facility_id=[hydroid]';
  $handler->display->display_options['fields']['hydroid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: Add Intake Link */
  $handler->display->display_options['fields']['hydroid_2']['id'] = 'hydroid_2';
  $handler->display->display_options['fields']['hydroid_2']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_2']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_2']['ui_name'] = 'Add Intake Link';
  $handler->display->display_options['fields']['hydroid_2']['label'] = '';
  $handler->display->display_options['fields']['hydroid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_2']['alter']['text'] = 'Add Surface Water Intake';
  $handler->display->display_options['fields']['hydroid_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_2']['alter']['path'] = 'addintake/';
  $handler->display->display_options['fields']['hydroid_2']['alter']['path_query_parameters'] = 'facility_id=[hydroid]';
  $handler->display->display_options['fields']['hydroid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid_2']['separator'] = '';
  /* Field: Add Contact Link */
  $handler->display->display_options['fields']['hydroid_3']['id'] = 'hydroid_3';
  $handler->display->display_options['fields']['hydroid_3']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_3']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_3']['ui_name'] = 'Add Contact Link';
  $handler->display->display_options['fields']['hydroid_3']['label'] = '';
  $handler->display->display_options['fields']['hydroid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['text'] = 'Add Contact';
  $handler->display->display_options['fields']['hydroid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid_3']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['hydroid_3']['alter']['path_query_parameters'] = 'admin_id=[hydroid]';
  $handler->display->display_options['fields']['hydroid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid_3']['separator'] = '';
  /* Field: Link HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Link HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
  <li>[hydroid_1]
  <li>[hydroid_2]
  <li>[hydroid_3]
  </ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-adminreg-add-list-facility';

  return $view;
}

function dh_adminreg_views_registrant_tabs() {
  $view = new view();
  $view->name = 'dha_registrant_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Registrant Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Registration Tabs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = 'Breadcrumb';
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_pr';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!adminid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = 'Actions';
  $handler->display->display_options['footer']['view_field']['view'] = 'dh_adminreg_add_list_permit_reg';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!adminid]';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Registration Title';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Registration ID';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Click to add new Facility to this [bundle].';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newfacility/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'permitreg_id=[adminid]';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'permit' => 'permit',
    'registration' => 'registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['path'] = 'dha-registration-tabs';

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_1');
  $handler->display->display_options['path'] = 'dha-registration-tabs/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Facilities & MPs */
  $handler = $view->new_display('page', 'Facilities & MPs', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Click to add new Facility to this [bundle].';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newfacility/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'permitreg_id=[adminid]';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Facilities under this Registration';
  $handler->display->display_options['fields']['view']['view'] = 'dha_pr_facilities';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-registration-tabs/%/facilities';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Facilities & MPs';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Submittals */
  $handler = $view->new_display('page', 'Submittals', 'page_3');
  $handler->display->display_options['path'] = 'dha-registration-tabs/%/submittals';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Submittals';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Registration Title';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Registration ID';
  $handler->display->display_options['fields']['admincode']['exclude'] = TRUE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Click to add new Facility to this [bundle].';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newfacility/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'permitreg_id=[adminid]';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Registration Contacts';
  $handler->display->display_options['fields']['view']['view'] = 'dha_entity_contacts';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-registration-tabs/%/contacts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}

function dh_adminreg_views_permit_tabs() {
  $view = new view();
  $view->name = 'dha_permit_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Permit Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Permit Tabs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Breadcrumb */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['ui_name'] = 'Breadcrumb';
  $handler->display->display_options['header']['view_field']['label'] = 'Breadcrumb';
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_pr';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!adminid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = 'Actions';
  $handler->display->display_options['footer']['view_field']['view'] = 'dh_adminreg_add_list_permit_reg';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!adminid]';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  /* Field: dH AdminReg Feature: Permit ID */
  $handler->display->display_options['fields']['permit_id']['id'] = 'permit_id';
  $handler->display->display_options['fields']['permit_id']['table'] = 'field_data_permit_id';
  $handler->display->display_options['fields']['permit_id']['field'] = 'permit_id';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'permit' => 'permit',
    'registration' => 'registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dha-permit-tabs';

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  /* Field: dH AdminReg Feature: Permit ID */
  $handler->display->display_options['fields']['permit_id']['id'] = 'permit_id';
  $handler->display->display_options['fields']['permit_id']['table'] = 'field_data_permit_id';
  $handler->display->display_options['fields']['permit_id']['field'] = 'permit_id';
  $handler->display->display_options['path'] = 'dha-permit-tabs/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Facilities & MPs */
  $handler = $view->new_display('page', 'Facilities & MPs', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  $handler->display->display_options['fields']['admincode']['exclude'] = TRUE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'dha_pr_facilities';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-permit-tabs/%/facilities';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Facilities & MPs';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Submittals */
  $handler = $view->new_display('page', 'Submittals', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_entity_submittals';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-permit-tabs/%/submittals';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Submittals';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_5');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  $handler->display->display_options['fields']['admincode']['exclude'] = TRUE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'dha_entity_contacts';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-permit-tabs/%/contacts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Props */
  $handler = $view->new_display('page', 'Props', 'page_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Permit Title';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_adminreg_feature/manage/[adminid]';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['label'] = 'Permit ID';
  $handler->display->display_options['fields']['admincode']['exclude'] = TRUE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  /* Field: dH AdminReg Feature: Permit ID */
  $handler->display->display_options['fields']['permit_id']['id'] = 'permit_id';
  $handler->display->display_options['fields']['permit_id']['table'] = 'field_data_permit_id';
  $handler->display->display_options['fields']['permit_id']['field'] = 'permit_id';
  $handler->display->display_options['fields']['permit_id']['exclude'] = TRUE;
  $handler->display->display_options['path'] = 'dha-permit-tabs/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Props';
  $handler->display->display_options['menu']['weight'] = '25';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}

function dh_adminreg_views_org_tabs() {
  $view = new view();
  $view->name = 'dha_organization_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Organization Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Organization Tabs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_org';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!adminid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = 'Actions';
  $handler->display->display_options['footer']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['footer']['view_field']['view'] = 'dh_adminreg_add_list_organization';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!adminid]';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Organization Name';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_entity_contacts';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add a Contact Record';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'organization_id=[adminid_1]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'organization' => 'organization',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Organization Name';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_organization_facilities';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-organization-tabs';

  /* Display: Permitted/Registerd Facilities */
  $handler = $view->new_display('page', 'Permitted/Registerd Facilities', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Facilities associated with [name].';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['label'] = '';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid']['alter']['text'] = 'Add a New Permit to This Organization.';
  $handler->display->display_options['fields']['adminid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid']['alter']['path'] = 'newpermit/';
  $handler->display->display_options['fields']['adminid']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add new voluntary registration.';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newregistration/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'organization_id=[adminid_1]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_organization_facilities';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  $handler->display->display_options['path'] = 'dha-organization-tabs/%/prs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Registrations & Permits';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'description_1' => 'description_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Organization Name';
  /* Field: Field: Description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'field_data_description';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  /* Field: Create a new non-permit registration for this organization. */
  $handler->display->display_options['fields']['adminid_2']['id'] = 'adminid_2';
  $handler->display->display_options['fields']['adminid_2']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_2']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_2']['ui_name'] = 'Create a new non-permit registration for this organization.';
  $handler->display->display_options['fields']['adminid_2']['label'] = '';
  $handler->display->display_options['fields']['adminid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['text'] = 'Add a new voluntary registration';
  $handler->display->display_options['fields']['adminid_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_2']['alter']['path'] = 'newregistration/';
  $handler->display->display_options['fields']['adminid_2']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_2']['separator'] = '';
  /* Field: Create a new permit registration for this organization. */
  $handler->display->display_options['fields']['adminid_3']['id'] = 'adminid_3';
  $handler->display->display_options['fields']['adminid_3']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_3']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_3']['ui_name'] = 'Create a new permit registration for this organization.';
  $handler->display->display_options['fields']['adminid_3']['label'] = '';
  $handler->display->display_options['fields']['adminid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['text'] = 'Add a new Permit Record for this organization.';
  $handler->display->display_options['fields']['adminid_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_3']['alter']['path'] = 'newpermit/';
  $handler->display->display_options['fields']['adminid_3']['alter']['path_query_parameters'] = 'organization_id=[adminid]';
  $handler->display->display_options['fields']['adminid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_3']['separator'] = '';
  $handler->display->display_options['path'] = 'dha-organization-tabs/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['label'] = 'Feature ID';
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Organization Name';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'dha_entity_contacts';
  $handler->display->display_options['fields']['view']['display'] = 'page_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!adminid]';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['label'] = '';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['text'] = 'Add a Contact Record';
  $handler->display->display_options['fields']['adminid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['alter']['path'] = 'newcontact/';
  $handler->display->display_options['fields']['adminid_1']['alter']['path_query_parameters'] = 'organization_id=[adminid_1]';
  $handler->display->display_options['fields']['adminid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  $handler->display->display_options['path'] = 'dha-organization-tabs/%/contacts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}

function dh_adminreg_views_org_facilities() {
  $view = new view();
  $view->name = 'dha_organization_facilities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Organization Facilities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Organization Tabs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'adminid' => 'adminid',
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adminid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Associated Permits */
  $handler->display->display_options['relationships']['reverse_dh_link_admin_reg_holder_dh_adminreg_feature']['id'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_reg_holder_dh_adminreg_feature']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_reg_holder_dh_adminreg_feature']['field'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_reg_holder_dh_adminreg_feature']['ui_name'] = 'Associated Permits';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_reg_holder_dh_adminreg_feature']['label'] = 'Associated Permits';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid_1']['id'] = 'adminid_1';
  $handler->display->display_options['fields']['adminid_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid_1']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid_1']['separator'] = '';
  /* Field: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle']['ui_name'] = 'Bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Organization Name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['name_1']['label'] = 'Registration or Permit Name';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['path'] = 'dha-[bundle]-tabs/[adminid_1]/info';
  /* Field: DH AdminReg Feature: Bundle */
  $handler->display->display_options['fields']['bundle_1']['id'] = 'bundle_1';
  $handler->display->display_options['fields']['bundle_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle_1']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle_1']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['bundle_1']['label'] = 'Type';
  $handler->display->display_options['fields']['bundle_1']['machine_name'] = TRUE;
  /* Field: DH AdminReg Feature: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  /* Field: DH AdminReg Feature: Admincode */
  $handler->display->display_options['fields']['admincode']['id'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['field'] = 'admincode';
  $handler->display->display_options['fields']['admincode']['relationship'] = 'reverse_dh_link_admin_reg_holder_dh_adminreg_feature';
  $handler->display->display_options['fields']['admincode']['label'] = 'Registrant/Permit ID';
  $handler->display->display_options['fields']['admincode']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['admincode']['alter']['path'] = 'dha-[bundle]-tabs/[adminid_1]/info';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['adminid']['comparator'] = TRUE;
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'organization' => 'organization',
  );

  /* Display: Facilities */
  $handler = $view->new_display('page', 'Facilities', 'page_1');
  $handler->display->display_options['path'] = 'dha-org-facilities';


  return $view;

}
function dh_adminreg_views_org_contacts() {
  $view = new view();
  $view->name = 'dha_organization_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Organization Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dHA - Organization Tabs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'adminid' => 'adminid',
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adminid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['dh_link_admin_contact_target_id']['id'] = 'dh_link_admin_contact_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_contact_target_id']['table'] = 'field_data_dh_link_admin_contact';
  $handler->display->display_options['relationships']['dh_link_admin_contact_target_id']['field'] = 'dh_link_admin_contact_target_id';
  $handler->display->display_options['relationships']['dh_link_admin_contact_target_id']['label'] = 'Organizations Contacts';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: DH AdminReg Contact: email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'dh_link_admin_contact_target_id';
  /* Field: DH AdminReg Contact: firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['relationship'] = 'dh_link_admin_contact_target_id';
  $handler->display->display_options['fields']['firstname']['label'] = 'Firstname';
  /* Field: DH AdminReg Contact: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'dh_link_admin_contact_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Label';
  /* Field: DH AdminReg Contact: lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  /* Contextual filter: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['arguments']['adminid']['id'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['arguments']['adminid']['field'] = 'adminid';
  $handler->display->display_options['arguments']['adminid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['adminid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['adminid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adminid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adminid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: DH AdminReg Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'organization' => 'organization',
  );

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page_1');
  $handler->display->display_options['path'] = 'dha-org-contacts';

  return $view;
}

function dh_adminreg_views_dha_manage_ar_contact() {
  $view = new view();
  $view->name = 'dha_manage_ar_contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_feature';
  $view->human_name = 'dHA - Manage AR Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'View Contact Information';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Linked Contact */
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['id'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['field'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['ui_name'] = 'Linked Contact';
  $handler->display->display_options['relationships']['reverse_dh_link_admin_contact_dh_adminreg_contact']['label'] = 'Linked Contact';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  /* Field: DH AdminReg Feature: Label */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Organization Name';
  /* Field: DH AdminReg Contact: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['ftype']['label'] = 'Contact Type';
  /* Field: DH AdminReg Contact: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['label'] = 'Contact Title';
  /* Field: DH AdminReg Contact: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['firstname']['label'] = 'First Name';
  /* Field: DH AdminReg Contact: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['lastname']['label'] = 'Last Name';
  /* Field: DH AdminReg Contact: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Address1 */
  $handler->display->display_options['fields']['address1']['id'] = 'address1';
  $handler->display->display_options['fields']['address1']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['address1']['field'] = 'address1';
  $handler->display->display_options['fields']['address1']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['address1']['label'] = 'Address';
  /* Field: DH AdminReg Contact: Address2 */
  $handler->display->display_options['fields']['address2']['id'] = 'address2';
  $handler->display->display_options['fields']['address2']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['address2']['field'] = 'address2';
  $handler->display->display_options['fields']['address2']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['address2']['label'] = 'Address 2';
  /* Field: DH AdminReg Contact: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  /* Field: DH AdminReg Contact: Postal_code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['postal_code']['label'] = 'Postal Code';
  /* Field: DH AdminReg Contact: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['description']['label'] = 'Comments';
  /* Field: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['fields']['contactid']['id'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid']['field'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid']['exclude'] = TRUE;
  /* Contextual filter: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['arguments']['contactid']['id'] = 'contactid';
  $handler->display->display_options['arguments']['contactid']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['arguments']['contactid']['field'] = 'contactid';
  $handler->display->display_options['arguments']['contactid']['relationship'] = 'reverse_dh_link_admin_contact_dh_adminreg_contact';
  $handler->display->display_options['arguments']['contactid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['contactid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contactid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contactid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contactid']['comparator'] = TRUE;

  /* Display: Contact View */
  $handler = $view->new_display('page', 'Contact View', 'page');
  $handler->display->display_options['path'] = 'dha-manage-contact/%/view';
  return $view;
}


function dh_adminreg_views_contacts() {
  $view = new view();
  $view->name = 'dha_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_adminreg_contact';
  $view->human_name = 'dH Feature Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List - Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'ftype' => 'ftype',
    'name' => 'name',
    'firstname' => 'firstname',
    'lastname' => 'lastname',
    'email' => 'email',
    'contactid' => 'contactid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'ftype' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'firstname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'lastname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contactid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['dh_link_feature_contact_target_id']['id'] = 'dh_link_feature_contact_target_id';
  $handler->display->display_options['relationships']['dh_link_feature_contact_target_id']['table'] = 'field_data_dh_link_feature_contact';
  $handler->display->display_options['relationships']['dh_link_feature_contact_target_id']['field'] = 'dh_link_feature_contact_target_id';
  /* Field: DH AdminReg Contact: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH AdminReg Contact: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: DH AdminReg Contact: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  /* Field: DH AdminReg Contact: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  /* Field: DH AdminReg Contact: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  /* Field: DH AdminReg Contact: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['fields']['contactid']['id'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid']['field'] = 'contactid';
  $handler->display->display_options['fields']['contactid']['label'] = '';
  $handler->display->display_options['fields']['contactid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contactid']['alter']['text'] = 'View Full Contact';
  $handler->display->display_options['fields']['contactid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contactid']['alter']['path'] = 'dha-manage-feature-contact/[contactid]/view';
  $handler->display->display_options['fields']['contactid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contactid']['separator'] = '';
  /* Field: DH AdminReg Contact: Dh adminreg contact ID */
  $handler->display->display_options['fields']['contactid_1']['id'] = 'contactid_1';
  $handler->display->display_options['fields']['contactid_1']['table'] = 'dh_adminreg_contact';
  $handler->display->display_options['fields']['contactid_1']['field'] = 'contactid';
  $handler->display->display_options['fields']['contactid_1']['label'] = '';
  $handler->display->display_options['fields']['contactid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contactid_1']['alter']['text'] = 'Edit Contact';
  $handler->display->display_options['fields']['contactid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contactid_1']['alter']['path'] = 'admin/content/dh_adminreg_contact/manage/[contactid_1]';
  $handler->display->display_options['fields']['contactid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contactid_1']['separator'] = '';
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['relationship'] = 'dh_link_feature_contact_target_id';
  $handler->display->display_options['arguments']['hydroid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'da-feature-contacts';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}