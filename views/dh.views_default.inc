<?php

/**
 * Implements hook_views_default_views().
 */
function dh_views_default_views() {
	// List dH Well Features
  $view = new view();
  $view->name = 'dh_well_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - List Wells';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - List Wells';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'hydroid' => 'hydroid',
    'aquiferid' => 'aquiferid',
    'ftype' => 'ftype',
    'hydrocode' => 'hydrocode',
    'dh_landelev' => 'dh_landelev',
    'dh_welldepth' => 'dh_welldepth',
    'hguid' => 'hguid',
    'propname' => 'propname',
  );
  $handler->display->display_options['style_options']['default'] = 'propname';
  $handler->display->display_options['style_options']['info'] = array(
    'hydroid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'aquiferid' => array(
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
    'hydrocode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dh_landelev' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dh_welldepth' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hguid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'propname' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: dH Feature: Aquifer */
  $handler->display->display_options['fields']['aquiferid']['id'] = 'aquiferid';
  $handler->display->display_options['fields']['aquiferid']['table'] = 'field_data_aquiferid';
  $handler->display->display_options['fields']['aquiferid']['field'] = 'aquiferid';
  $handler->display->display_options['fields']['aquiferid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['aquiferid']['alter']['path'] = 'dh-aquifer-detail/[aquiferid-target_id]';
  $handler->display->display_options['fields']['aquiferid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['aquiferid']['delta_offset'] = '0';
  /* Field: DH Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydrocode']['alter']['path'] = 'dh-well-detail/[hydroid]/info';
  /* Field: dH Feature: Land Surface Elevation */
  $handler->display->display_options['fields']['dh_landelev']['id'] = 'dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['table'] = 'field_data_dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['field'] = 'dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: dH Feature: Well Depth */
  $handler->display->display_options['fields']['dh_welldepth']['id'] = 'dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['table'] = 'field_data_dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['field'] = 'dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Hydrogeologic Unit */
  $handler->display->display_options['fields']['hguid']['id'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['table'] = 'field_data_hguid';
  $handler->display->display_options['fields']['hguid']['field'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['hguid']['delta_offset'] = '0';
  /* Field: COUNT(DH Properties: Property Name) */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  $handler->display->display_options['fields']['propname']['group_type'] = 'count';
  $handler->display->display_options['fields']['propname']['label'] = '# of Properties';
  /* Contextual filter: Min Depth */
  $handler->display->display_options['arguments']['dh_welldepth_value']['id'] = 'dh_welldepth_value';
  $handler->display->display_options['arguments']['dh_welldepth_value']['table'] = 'field_data_dh_welldepth';
  $handler->display->display_options['arguments']['dh_welldepth_value']['field'] = 'dh_welldepth_value';
  $handler->display->display_options['arguments']['dh_welldepth_value']['ui_name'] = 'Min Depth';
  $handler->display->display_options['arguments']['dh_welldepth_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dh_welldepth_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dh_welldepth_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dh_welldepth_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['dh_welldepth_value']['comparator'] = TRUE;
  /* Contextual filter: Max Depth */
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['id'] = 'dh_welldepth_value_1';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['table'] = 'field_data_dh_welldepth';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['field'] = 'dh_welldepth_value';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['ui_name'] = 'Max Depth';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['dh_welldepth_value_1']['comparator'] = TRUE;
  /* Filter criterion: DH Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'well' => 'well',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-list-wells';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Wells';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Depth Range */
  $handler = $view->new_display('page', 'Depth Range', 'page_1');
  $handler->display->display_options['path'] = 'well-by-depth';

  $views['dh_well_list'] = $view;
	
  $view = new view();
  $view->name = 'dh_well_edit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Edit Well';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - Edit Well';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  /* Field: dH Feature: Aquifer (editable) */
  $handler->display->display_options['fields']['aquiferid_editable']['id'] = 'aquiferid_editable';
  $handler->display->display_options['fields']['aquiferid_editable']['table'] = 'field_data_aquiferid';
  $handler->display->display_options['fields']['aquiferid_editable']['field'] = 'aquiferid_editable';
  $handler->display->display_options['fields']['aquiferid_editable']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['aquiferid_editable']['delta_offset'] = '0';
  $handler->display->display_options['fields']['aquiferid_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['aquiferid_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['aquiferid_editable']['suppress_description'] = 0;
  /* Field: dH Feature: Geometry (editable) */
  $handler->display->display_options['fields']['dh_geofield_editable']['id'] = 'dh_geofield_editable';
  $handler->display->display_options['fields']['dh_geofield_editable']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield_editable']['field'] = 'dh_geofield_editable';
  $handler->display->display_options['fields']['dh_geofield_editable']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['dh_geofield_editable']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['dh_geofield_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['dh_geofield_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['dh_geofield_editable']['suppress_description'] = 0;
  /* Field: dH Feature: Land Surface Elevation (editable) */
  $handler->display->display_options['fields']['dh_landelev_editable']['id'] = 'dh_landelev_editable';
  $handler->display->display_options['fields']['dh_landelev_editable']['table'] = 'field_data_dh_landelev';
  $handler->display->display_options['fields']['dh_landelev_editable']['field'] = 'dh_landelev_editable';
  $handler->display->display_options['fields']['dh_landelev_editable']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['dh_landelev_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['dh_landelev_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['dh_landelev_editable']['suppress_description'] = 0;
  /* Field: Field: Hydrogeologic Unit (editable) */
  $handler->display->display_options['fields']['hguid_editable']['id'] = 'hguid_editable';
  $handler->display->display_options['fields']['hguid_editable']['table'] = 'field_data_hguid';
  $handler->display->display_options['fields']['hguid_editable']['field'] = 'hguid_editable';
  $handler->display->display_options['fields']['hguid_editable']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['hguid_editable']['delta_offset'] = '0';
  $handler->display->display_options['fields']['hguid_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['hguid_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['hguid_editable']['suppress_description'] = 0;
  /* Field: DH Feature: Hydrocode (editable) */
  $handler->display->display_options['fields']['editable_hydrocode']['id'] = 'editable_hydrocode';
  $handler->display->display_options['fields']['editable_hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['editable_hydrocode']['field'] = 'editable_hydrocode';
  $handler->display->display_options['fields']['editable_hydrocode']['textfield_size'] = '32';
  /* Field: DH Feature: Ftype (editable) */
  $handler->display->display_options['fields']['editable_ftype']['id'] = 'editable_ftype';
  $handler->display->display_options['fields']['editable_ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['editable_ftype']['field'] = 'editable_ftype';
  $handler->display->display_options['fields']['editable_ftype']['textfield_size'] = '';
  /* Contextual filter: DH Feature: Hydrocode */
  $handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydrocode']['limit'] = '0';
  /* Filter criterion: DH Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'well' => 'well',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-edit-well';
  $views['dh_well_edit'] = $view;

	
	// Well detail
  $view = new view();
  $view->name = 'dh_well_detail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Well Detail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - Well Detail';
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
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_mp';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!hydroid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = '';
  $handler->display->display_options['footer']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['footer']['view_field']['view'] = 'dha_add_list_mp';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!hydroid]';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Well Name';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'Dh feature ID';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydrocode']['alter']['path'] = 'admin/content/dh_features/manage/[hydroid]';
  /* Field: dH Feature: Aquifer */
  $handler->display->display_options['fields']['aquiferid']['id'] = 'aquiferid';
  $handler->display->display_options['fields']['aquiferid']['table'] = 'field_data_aquiferid';
  $handler->display->display_options['fields']['aquiferid']['field'] = 'aquiferid';
  $handler->display->display_options['fields']['aquiferid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['aquiferid']['alter']['path'] = 'dh-aquifer-detail/[aquiferid-target_id]';
  $handler->display->display_options['fields']['aquiferid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['aquiferid']['delta_offset'] = '0';
  /* Field: DH Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['dh_geofield']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_zoom' => '8',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'standard',
    'geofield_map_pancontrol' => 1,
    'geofield_map_maptype' => 'physical',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 1,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 1,
    'geofield_map_draggable' => 1,
    'geofield_map_streetview_show' => 0,
  );
  /* Field: dH Feature: Land Surface Elevation */
  $handler->display->display_options['fields']['dh_landelev']['id'] = 'dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['table'] = 'field_data_dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['field'] = 'dh_landelev';
  $handler->display->display_options['fields']['dh_landelev']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: dH Feature: Well Depth */
  $handler->display->display_options['fields']['dh_welldepth']['id'] = 'dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['table'] = 'field_data_dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['field'] = 'dh_welldepth';
  $handler->display->display_options['fields']['dh_welldepth']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Hydrogeologic Unit */
  $handler->display->display_options['fields']['hguid']['id'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['table'] = 'field_data_hguid';
  $handler->display->display_options['fields']['hguid']['field'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['hguid']['delta_offset'] = '0';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = 'Withdrawal Data';
  $handler->display->display_options['fields']['view_1']['view'] = 'dh_list_timeseries_data';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!hydroid]/6';
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;
  /* Filter criterion: DH Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'well' => 'well',
  );

  /* Display: By HydroID */
  $handler = $view->new_display('page', 'By HydroID', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-well-detail/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: WMS Demo */
  $handler = $view->new_display('page', 'WMS Demo', 'page_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'dh_geofield';
  $handler->display->display_options['style_options']['name_field'] = 'hydrocode';
  $handler->display->display_options['style_options']['description_field'] = 'hydrocode';
  $handler->display->display_options['style_options']['map'] = 'vadeq-wells';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '8';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'dh-well-detail/%/wms';
  $handler->display->display_options['menu']['title'] = 'Weather';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

	$views['dh_well_detail'] = $view;

	// Aquifer Detail
	$view = new view();
	$view->name = 'dh_aquifer_detail';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - Aquifer Detail';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - Aquifer Detail';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
	/* Field: DH Feature: Label */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['label'] = 'Aquifer Name';
	/* Field: Global: View */
	$handler->display->display_options['fields']['view']['id'] = 'view';
	$handler->display->display_options['fields']['view']['table'] = 'views';
	$handler->display->display_options['fields']['view']['field'] = 'view';
	$handler->display->display_options['fields']['view']['label'] = 'Wells in this Aquifer';
	$handler->display->display_options['fields']['view']['view'] = 'dh_aquifer_wells';
	$handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
	/* Contextual filter: DH Feature: Dh feature ID */
	$handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
	/* Filter criterion: DH Feature: Bundle */
	$handler->display->display_options['filters']['bundle']['id'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
	$handler->display->display_options['filters']['bundle']['field'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['value'] = array(
	  'aquifer' => 'aquifer',
	);

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-aquifer-detail';
	$view = new view();
	$view->name = 'dh_aquifer_detail';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - Aquifer Detail';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - Aquifer Detail';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
	/* Field: DH Feature: Label */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['label'] = 'Aquifer Name';
	/* Field: Global: View */
	$handler->display->display_options['fields']['view']['id'] = 'view';
	$handler->display->display_options['fields']['view']['table'] = 'views';
	$handler->display->display_options['fields']['view']['field'] = 'view';
	$handler->display->display_options['fields']['view']['label'] = 'Wells in this Aquifer';
	$handler->display->display_options['fields']['view']['view'] = 'dh_aquifer_wells_list';
	$handler->display->display_options['fields']['view']['display'] = 'page';
	$handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
	/* Contextual filter: DH Feature: Dh feature ID */
	$handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
	/* Filter criterion: DH Feature: Bundle */
	$handler->display->display_options['filters']['bundle']['id'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
	$handler->display->display_options['filters']['bundle']['field'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['value'] = array(
	  'aquifer' => 'aquifer',
	);

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-aquifer-detail';

	$views['dh_aquifer_detail'] = $view;
	
	// Aquifer List
	$view = new view();
	$view->name = 'dh_aquifer_list';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - List Aquifers';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - List Aquifers';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	/* Field: DH Feature: Label */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['name']['alter']['path'] = 'dh-aquifer-detail/[hydroid]';
	/* Filter criterion: DH Feature: Bundle */
	$handler->display->display_options['filters']['bundle']['id'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
	$handler->display->display_options['filters']['bundle']['field'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['value'] = array(
	  'aquifer' => 'aquifer',
	);

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-list-aquifers';
	$handler->display->display_options['menu']['type'] = 'normal';
	$handler->display->display_options['menu']['title'] = 'Aquifers';
	$handler->display->display_options['menu']['weight'] = '10';
	$handler->display->display_options['menu']['context'] = 0;
	$views['dh_aquifer_list'] = $view;
	
	// Aquifer Edit
	$view = new view();
	$view->name = 'dh_aquifer_edit';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - Edit Aquifer';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - Edit Aquifer';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'editableviews_table';
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	/* Field: DH Feature: Label (editable) */
	$handler->display->display_options['fields']['editable_name']['id'] = 'editable_name';
	$handler->display->display_options['fields']['editable_name']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['editable_name']['field'] = 'editable_name';
	$handler->display->display_options['fields']['editable_name']['textfield_size'] = '';
	/* Field: dH Feature: Geometry (editable) */
	$handler->display->display_options['fields']['dh_geofield_editable']['id'] = 'dh_geofield_editable';
	$handler->display->display_options['fields']['dh_geofield_editable']['table'] = 'field_data_dh_geofield';
	$handler->display->display_options['fields']['dh_geofield_editable']['field'] = 'dh_geofield_editable';
	$handler->display->display_options['fields']['dh_geofield_editable']['click_sort_column'] = 'wkt';
	$handler->display->display_options['fields']['dh_geofield_editable']['settings'] = array(
	  'data' => 'full',
	);
	$handler->display->display_options['fields']['dh_geofield_editable']['widget_type'] = '0';
	$handler->display->display_options['fields']['dh_geofield_editable']['suppress_label'] = 0;
	$handler->display->display_options['fields']['dh_geofield_editable']['suppress_description'] = 0;
	/* Contextual filter: DH Feature: Hydrocode */
	$handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
	$handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['arguments']['hydrocode']['limit'] = '0';
	/* Filter criterion: DH Feature: Bundle */
	$handler->display->display_options['filters']['bundle']['id'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
	$handler->display->display_options['filters']['bundle']['field'] = 'bundle';
	$handler->display->display_options['filters']['bundle']['value'] = array(
	  'aquifer' => 'aquifer',
	);

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-edit-aquifer';
	$views['dh_aquifer_edit'] = $view;

	// Aquifer - list wells
	$view = new view();
	$view->name = 'dh_aquifer_wells_list';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - Aquifer Wells';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - Aquifer Wells';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	/* Relationship: Entity Reference: Referencing entity */
	$handler->display->display_options['relationships']['reverse_aquiferid_dh_feature']['id'] = 'reverse_aquiferid_dh_feature';
	$handler->display->display_options['relationships']['reverse_aquiferid_dh_feature']['table'] = 'dh_feature';
	$handler->display->display_options['relationships']['reverse_aquiferid_dh_feature']['field'] = 'reverse_aquiferid_dh_feature';
	$handler->display->display_options['relationships']['reverse_aquiferid_dh_feature']['required'] = TRUE;
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['label'] = 'Aquifer HydroID';
	$handler->display->display_options['fields']['hydroid']['separator'] = '';
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
	$handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid_1']['relationship'] = 'reverse_aquiferid_dh_feature';
	$handler->display->display_options['fields']['hydroid_1']['label'] = 'Well HydroID';
	$handler->display->display_options['fields']['hydroid_1']['separator'] = '';
	/* Field: DH Feature: Hydrocode */
	$handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
	$handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
	$handler->display->display_options['fields']['hydrocode']['relationship'] = 'reverse_aquiferid_dh_feature';
	$handler->display->display_options['fields']['hydrocode']['label'] = 'Well MPID';
	$handler->display->display_options['fields']['hydrocode']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['hydrocode']['alter']['path'] = 'dh-well-detail/[hydrocode]';
	/* Contextual filter: DH Feature: Dh feature ID */
	$handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-aquifer-wells';

	$views['dh_aquifer_wells_list'] = $view;
	
	// Hydro mappings for Feeds Importers
	$view = new view();
	$view->name = 'dh_hgucode_to_entityid';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_hydrogeologicunit';
	$view->human_name = 'dH - HGUCode to EntityID';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - HHGUCode to EntityID';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	/* Field: DH Hydrogeologic Unit: Internal, numeric dh hydrogeologic unit ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_hydrogeologicunit';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	/* Contextual filter: DH Hydrogeologic Unit: Label */
	$handler->display->display_options['arguments']['hgucode']['id'] = 'hgucode';
	$handler->display->display_options['arguments']['hgucode']['table'] = 'dh_hydrogeologicunit';
	$handler->display->display_options['arguments']['hgucode']['field'] = 'hgucode';
	$handler->display->display_options['arguments']['hgucode']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hgucode']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hgucode']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hgucode']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['arguments']['hgucode']['limit'] = '0';

	/* Display: HGUCode to HydroID */
	$handler = $view->new_display('page', 'HGUCode to HydroID', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-hhgucode-to-entityid';
	$views['dh_hgucode_to_entityid'] = $view;
		
	$view = new view();
	$view->name = 'dh_hydrocode_to_entityid';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_feature';
	$view->human_name = 'dH - Hydrocode to EntityID';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - Hydrocode to EntityID';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
	/* Field: DH Feature: Dh feature ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['label'] = '';
	$handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
	/* Contextual filter: DH Feature: Hydrocode */
	$handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
	$handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydrocode']['default_argument_options']['argument'] = 'null';
	$handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['arguments']['hydrocode']['limit'] = '0';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-hydrocode2entityid';
	$views['dh_hydrocode2entityid'] = $view;

	$view = new view();
  $view->name = 'dh_geoview_wells';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Map Wells';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'GeoFields - Test';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'geofield_map_map';
  $handler->display->display_options['style_options']['data_source'] = 'dh_geofield';
  $handler->display->display_options['style_options']['popup_source'] = 'hydroid';
  $handler->display->display_options['style_options']['geofield_map_zoom'] = '11';
  $handler->display->display_options['style_options']['geofield_map_min_zoom'] = '0';
  $handler->display->display_options['style_options']['geofield_map_max_zoom'] = '0';
  $handler->display->display_options['style_options']['geofield_map_center'] = array(
    'lat' => '37.553799',
    'lon' => '-77.460297',
    'geocode' => 'Find my location',
  );
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'HydroID: [hydroid] 
  <br>DEQ MPID: [hydrocode]';
  $handler->display->display_options['fields']['hydroid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'dh-well-detail/[hydrocode]/info';
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Filter criterion: DH Feature: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'well' => 'well',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'geofields-test';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Well Map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
	$views['dh_geoview_wells'] = $view;

  $view = new view();
  $view->name = 'dh_variabledefinition_vocabularies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_variabledefinition';
  $view->human_name = 'dH - VariableDefinition Vocabularies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - VariableDefinition Vocabularies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['vocabulary']['alter']['path'] = 'dh-list-variabledefinition/all/[vocabulary]';
  /* Field: COUNT(DH VariableDefinition: Internal, numeric dh variabledefinition ID) */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['group_type'] = 'count';
  $handler->display->display_options['fields']['hydroid']['label'] = '# of Variables';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-variabledefinition-vocabularies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Vocabularies';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $views['dh_variabledefinition_vocabularies'] = $view;

	$view = new view();
	$view->name = 'dh_hgu_hydrocode_to_hydroid';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'dh_hydrogeologicunit';
	$view->human_name = 'dH - HGU Hydrocode to HydroID';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'dH - HGU Hydrocode to HydroID';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: DH Hydrogeologic Unit: Internal, numeric dh hydrogeologic unit ID */
	$handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['table'] = 'dh_hydrogeologicunit';
	$handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
	$handler->display->display_options['fields']['hydroid']['label'] = '';
	$handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['hydroid']['separator'] = '';
	/* Contextual filter: DH Hydrogeologic Unit: Hydrocode */
	$handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_hydrogeologicunit';
	$handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
	$handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['arguments']['hydrocode']['limit'] = '0';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['path'] = 'dh-hgu-hydrocode2hydroid';
	$views['dh_hgu_hydrocode_to_hydroid'] = $view;

  $view = new view();
  $view->name = 'dh_list_timeseries_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_timeseries';
  $view->human_name = 'dH - List TimeSeries Data';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'featureid' => 'featureid',
    'tstime' => 'tstime',
    'tid' => 'tid',
    'varname' => 'varname',
    'vardesc' => 'vardesc',
    'varid' => 'varid',
    'tsvalue' => 'tsvalue',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'featureid' => array(
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
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vardesc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tsvalue' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: DH TimeSeries: Featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = 'Feature HydroID';
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['date_format'] = 'custom';
  $handler->display->display_options['fields']['tstime']['custom_date_format'] = 'Y/m/d';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'VarName';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['label'] = 'Description';
  /* Field: DH TimeSeries: Varid */
  $handler->display->display_options['fields']['varid']['id'] = 'varid';
  $handler->display->display_options['fields']['varid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['varid']['field'] = 'varid';
  $handler->display->display_options['fields']['varid']['label'] = 'VarID';
  /* Field: DH TimeSeries: tsvalue */
  $handler->display->display_options['fields']['tsvalue']['id'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsvalue']['field'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['group_type'] = 'sum';
  $handler->display->display_options['fields']['tsvalue']['precision'] = '0';
  $handler->display->display_options['fields']['tsvalue']['separator'] = '';
  /* Sort criterion: DH TimeSeries: tstime */
  $handler->display->display_options['sorts']['tstime']['id'] = 'tstime';
  $handler->display->display_options['sorts']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['sorts']['tstime']['field'] = 'tstime';
  /* Contextual filter: DH TimeSeries: Featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = TRUE;
  /* Contextual filter: DH VariableDefinition: Label */
  $handler->display->display_options['arguments']['varname']['id'] = 'varname';
  $handler->display->display_options['arguments']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varname']['field'] = 'varname';
  $handler->display->display_options['arguments']['varname']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varname']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['varname']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['varname']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['varname']['limit'] = '0';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = '-99999999999999999999';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['argument'] = '999999999999999999';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH TimeSeries: Featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = 'Feature HydroID';
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['date_format'] = 'custom';
  $handler->display->display_options['fields']['tstime']['custom_date_format'] = 'Y/m/d';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'VarName';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['label'] = 'Description';
  /* Field: DH TimeSeries: Varid */
  $handler->display->display_options['fields']['varid']['id'] = 'varid';
  $handler->display->display_options['fields']['varid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['varid']['field'] = 'varid';
  $handler->display->display_options['fields']['varid']['label'] = 'VarID';
  /* Field: DH TimeSeries: tsvalue */
  $handler->display->display_options['fields']['tsvalue']['id'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsvalue']['field'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['group_type'] = 'sum';
  $handler->display->display_options['fields']['tsvalue']['precision'] = '0';
  $handler->display->display_options['fields']['tsvalue']['separator'] = '';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['alter']['text'] = 'Edit Record';
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['alter']['path'] = 'admin/content/dh_timeseries/manage/[tid_1]';
  $handler->display->display_options['path'] = 'dh-list-timeseries-data';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Time Series Data';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Hcode & Varname */
  $handler = $view->new_display('page', 'Hcode & Varname', 'page_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'featureid' => 'featureid',
    'tstime' => 'tstime',
    'tid' => 'tid',
    'varname' => 'varname',
    'vardesc' => 'vardesc',
    'varid' => 'varid',
    'tsvalue' => 'tsvalue',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'featureid' => array(
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
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vardesc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tsvalue' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH TimeSeries: Featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = 'Feature HydroID';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['date_format'] = 'custom';
  $handler->display->display_options['fields']['tstime']['custom_date_format'] = 'Y/m/d';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'VarName';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['label'] = 'Description';
  $handler->display->display_options['fields']['vardesc']['exclude'] = TRUE;
  /* Field: DH TimeSeries: Varid */
  $handler->display->display_options['fields']['varid']['id'] = 'varid';
  $handler->display->display_options['fields']['varid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['varid']['field'] = 'varid';
  $handler->display->display_options['fields']['varid']['label'] = 'VarID';
  $handler->display->display_options['fields']['varid']['exclude'] = TRUE;
  /* Field: DH TimeSeries: tsvalue */
  $handler->display->display_options['fields']['tsvalue']['id'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsvalue']['field'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['group_type'] = 'sum';
  $handler->display->display_options['fields']['tsvalue']['precision'] = '0';
  $handler->display->display_options['fields']['tsvalue']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Feature: Hydrocode */
  $handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydrocode']['limit'] = '0';
  /* Contextual filter: DH VariableDefinition: Varcode */
  $handler->display->display_options['arguments']['varcode']['id'] = 'varcode';
  $handler->display->display_options['arguments']['varcode']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varcode']['field'] = 'varcode';
  $handler->display->display_options['arguments']['varcode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varcode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['varcode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['varcode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['varcode']['limit'] = '0';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = '-99999999999999999999';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['argument'] = '999999999999999999';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'dh-tsdata-hr';

  /* Display: Water Quality */
  $handler = $view->new_display('page', 'Water Quality', 'page_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'featureid' => 'featureid',
    'tstime' => 'tstime',
    'tid' => 'tid',
    'varname' => 'varname',
    'vardesc' => 'vardesc',
    'varid' => 'varid',
    'tsvalue' => 'tsvalue',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'featureid' => array(
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
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vardesc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tsvalue' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH TimeSeries: Featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = 'Feature HydroID';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['date_format'] = 'custom';
  $handler->display->display_options['fields']['tstime']['custom_date_format'] = 'Y/m/d';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'VarName';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['label'] = 'Description';
  $handler->display->display_options['fields']['vardesc']['exclude'] = TRUE;
  /* Field: DH TimeSeries: Varid */
  $handler->display->display_options['fields']['varid']['id'] = 'varid';
  $handler->display->display_options['fields']['varid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['varid']['field'] = 'varid';
  $handler->display->display_options['fields']['varid']['label'] = 'VarID';
  $handler->display->display_options['fields']['varid']['exclude'] = TRUE;
  /* Field: DH TimeSeries: tsvalue */
  $handler->display->display_options['fields']['tsvalue']['id'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsvalue']['field'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['group_type'] = 'sum';
  $handler->display->display_options['fields']['tsvalue']['precision'] = '0';
  $handler->display->display_options['fields']['tsvalue']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Feature: Hydrocode */
  $handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydrocode']['limit'] = '0';
  /* Contextual filter: DH VariableDefinition: Varcode */
  $handler->display->display_options['arguments']['varcode']['id'] = 'varcode';
  $handler->display->display_options['arguments']['varcode']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varcode']['field'] = 'varcode';
  $handler->display->display_options['arguments']['varcode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varcode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['varcode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['varcode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['varcode']['limit'] = '0';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = '-99999999999999999999';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['argument'] = '999999999999999999';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: DH VariableDefinition: Varcode */
  $handler->display->display_options['filters']['varcode']['id'] = 'varcode';
  $handler->display->display_options['filters']['varcode']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['filters']['varcode']['field'] = 'varcode';
  $handler->display->display_options['filters']['varcode']['operator'] = 'ends';
  $handler->display->display_options['filters']['varcode']['value'] = '_mgl';
  $handler->display->display_options['path'] = 'wq';
  $handler->display->display_options['menu']['title'] = 'Water Quality';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Custom Embed */
  $handler = $view->new_display('page', 'Custom Embed', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'featureid' => 'featureid',
    'tstime' => 'tstime',
    'tid' => 'tid',
    'varname' => 'varname',
    'vardesc' => 'vardesc',
    'varid' => 'varid',
    'tsvalue' => 'tsvalue',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'featureid' => array(
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
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vardesc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'varid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tsvalue' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'dh-ts-embed';

  /* Display: System Embed */
  $handler = $view->new_display('embed', 'System Embed', 'embed_1');

	$views['dh_list_timeseries_data'] = $view;
	
  $view = new view();
  $view->name = 'dh_list_variabledefinition';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_variabledefinition';
  $view->human_name = 'dH - List VariableDefinition';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - List VariableDefinition';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: DH VariableDefinition: Internal, numeric dh variabledefinition ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_variabledefinition/manage/[hydroid]';
  /* Field: DH VariableDefinition: Datatype */
  $handler->display->display_options['fields']['datatype']['id'] = 'datatype';
  $handler->display->display_options['fields']['datatype']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['datatype']['field'] = 'datatype';
  /* Field: DH VariableDefinition: Varkey */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['label'] = 'Label';
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'Machine-readable name';
  /* Field: DH VariableDefinition: Nodataval */
  $handler->display->display_options['fields']['nodataval']['id'] = 'nodataval';
  $handler->display->display_options['fields']['nodataval']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['nodataval']['field'] = 'nodataval';
  /* Field: DH VariableDefinition: Timeunits */
  $handler->display->display_options['fields']['timeunits']['id'] = 'timeunits';
  $handler->display->display_options['fields']['timeunits']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['timeunits']['field'] = 'timeunits';
  /* Field: DH VariableDefinition: Varcode */
  $handler->display->display_options['fields']['varcode']['id'] = 'varcode';
  $handler->display->display_options['fields']['varcode']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varcode']['field'] = 'varcode';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  /* Field: DH VariableDefinition: Varunits */
  $handler->display->display_options['fields']['varunits']['id'] = 'varunits';
  $handler->display->display_options['fields']['varunits']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varunits']['field'] = 'varunits';
  /* Field: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  /* Contextual filter: DH VariableDefinition: Varkey */
  $handler->display->display_options['arguments']['varkey']['id'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varkey']['field'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varkey']['summary']['format'] = 'default_summary';
  /* Contextual filter: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['arguments']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vocabulary']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vocabulary']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vocabulary']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vocabulary']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-list-variabledefinition';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'TimeSeries Variables';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '\\t';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH VariableDefinition: Internal, numeric dh variabledefinition ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = 'dataid';
  $handler->display->display_options['fields']['hydroid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_variabledefinition/manage/[hydroid]';
  /* Field: DH VariableDefinition: Datatype */
  $handler->display->display_options['fields']['datatype']['id'] = 'datatype';
  $handler->display->display_options['fields']['datatype']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['datatype']['field'] = 'datatype';
  $handler->display->display_options['fields']['datatype']['label'] = 'datatype';
  /* Field: DH VariableDefinition: Varkey */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['label'] = 'varkey';
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = 'label';
  $handler->display->display_options['fields']['varname']['exclude'] = TRUE;
  /* Field: DH VariableDefinition: Nodataval */
  $handler->display->display_options['fields']['nodataval']['id'] = 'nodataval';
  $handler->display->display_options['fields']['nodataval']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['nodataval']['field'] = 'nodataval';
  $handler->display->display_options['fields']['nodataval']['label'] = 'nodataval';
  $handler->display->display_options['fields']['nodataval']['separator'] = '';
  /* Field: DH VariableDefinition: Timeunits */
  $handler->display->display_options['fields']['timeunits']['id'] = 'timeunits';
  $handler->display->display_options['fields']['timeunits']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['timeunits']['field'] = 'timeunits';
  $handler->display->display_options['fields']['timeunits']['label'] = 'timeunits';
  /* Field: DH VariableDefinition: Varcode */
  $handler->display->display_options['fields']['varcode']['id'] = 'varcode';
  $handler->display->display_options['fields']['varcode']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varcode']['field'] = 'varcode';
  $handler->display->display_options['fields']['varcode']['label'] = 'varcode';
  /* Field: DH VariableDefinition: Vardesc */
  $handler->display->display_options['fields']['vardesc']['id'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vardesc']['field'] = 'vardesc';
  $handler->display->display_options['fields']['vardesc']['label'] = 'vardesc';
  /* Field: DH VariableDefinition: Varunits */
  $handler->display->display_options['fields']['varunits']['id'] = 'varunits';
  $handler->display->display_options['fields']['varunits']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varunits']['field'] = 'varunits';
  $handler->display->display_options['fields']['varunits']['label'] = 'varunits';
  /* Field: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['label'] = 'vocabulary';
  /* Field: DH VariableDefinition: Label */
  $handler->display->display_options['fields']['varname_1']['id'] = 'varname_1';
  $handler->display->display_options['fields']['varname_1']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname_1']['field'] = 'varname';
  $handler->display->display_options['fields']['varname_1']['label'] = 'varname';
  $handler->display->display_options['path'] = 'vardefs.tsv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

	$views['dh_list_variabledefinition'] = $view;
	
	
	$feeds_importer = new stdClass();
	$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
	$feeds_importer->api_version = 1;
	$feeds_importer->id = 'dh_import_generic_feature';
	$feeds_importer->config = array(
	  'name' => 'dH - Import Generic Feature',
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
				 'source' => 'hydrocode',
				 'target' => 'hydrocode',
				 'unique' => FALSE,
			  ),
			  1 => array(
				 'source' => 'wkt_geom',
				 'target' => 'dh_geofield:wkt',
				 'unique' => FALSE,
			  ),
			  2 => array(
				 'source' => 'hydrocode',
				 'target' => 'guid',
				 'unique' => 1,
			  ),
			),
			'update_existing' => '2',
			'input_format' => 'plain_text',
			'skip_hash_check' => 0,
			'bundle' => 'watershed',
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
	$views['dh_import_generic_feature'] = $view;
  
  $view = new view();
  $view->name = 'dh_list_properties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_properties';
  $view->human_name = 'dH - List Properties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - List Properties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: DH Properties: Property Name */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  /* Field: DH Properties: Propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['propvalue']['precision'] = '3';
  $handler->display->display_options['fields']['propvalue']['separator'] = '';
  /* Field: dH Properties: Storage for text properties value */
  $handler->display->display_options['fields']['proptext']['id'] = 'proptext';
  $handler->display->display_options['fields']['proptext']['table'] = 'field_data_proptext';
  $handler->display->display_options['fields']['proptext']['field'] = 'proptext';
  /* Field: DH Properties: Varid */
  $handler->display->display_options['fields']['varid']['id'] = 'varid';
  $handler->display->display_options['fields']['varid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['varid']['field'] = 'varid';
  $handler->display->display_options['fields']['varid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['varid']['separator'] = '';
  /* Field: DH VariableDefinition: Varkey */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  /* Field: DH Properties: Featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['exclude'] = TRUE;
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  $handler->display->display_options['fields']['pid_1']['label'] = '';
  $handler->display->display_options['fields']['pid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['text'] = 'Edit Property';
  $handler->display->display_options['fields']['pid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['path'] = 'admin/content/dh_properties/manage/[pid_1]';
  /* Contextual filter: DH Properties: Featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = TRUE;
  /* Contextual filter: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['arguments']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vocabulary']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vocabulary']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vocabulary']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vocabulary']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dh-list-properties';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'cova-usgs-gage/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Properties';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Well Construction */
  $handler = $view->new_display('page', 'Well Construction', 'page_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Properties: Featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = TRUE;
  /* Contextual filter: DH VariableDefinition: Vocabulary */
  $handler->display->display_options['arguments']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['default_action'] = 'default';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_options']['argument'] = 'well_construction_log';
  $handler->display->display_options['arguments']['vocabulary']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vocabulary']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vocabulary']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vocabulary']['limit'] = '0';
  $handler->display->display_options['path'] = 'dh-props-wcl';

  /* Display: Value Only */
  $handler = $view->new_display('page', 'Value Only', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Properties: Propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['label'] = '';
  $handler->display->display_options['fields']['propvalue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['propvalue']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['propvalue']['precision'] = '3';
  $handler->display->display_options['fields']['propvalue']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Properties: Featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = TRUE;
  /* Contextual filter: DH VariableDefinition: Varkey */
  $handler->display->display_options['arguments']['varkey']['id'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varkey']['field'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varkey']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['varkey']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['varkey']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['varkey']['limit'] = '0';
  $handler->display->display_options['path'] = 'dhprop-value';

  /* Display: Text Only */
  $handler = $view->new_display('page', 'Text Only', 'page_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: dH Properties: Storage for text properties value */
  $handler->display->display_options['fields']['proptext']['id'] = 'proptext';
  $handler->display->display_options['fields']['proptext']['table'] = 'field_data_proptext';
  $handler->display->display_options['fields']['proptext']['field'] = 'proptext';
  $handler->display->display_options['fields']['proptext']['label'] = '';
  $handler->display->display_options['fields']['proptext']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['proptext']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Properties: Featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = TRUE;
  /* Contextual filter: DH VariableDefinition: Varkey */
  $handler->display->display_options['arguments']['varkey']['id'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['varkey']['field'] = 'varkey';
  $handler->display->display_options['arguments']['varkey']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['varkey']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['varkey']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['varkey']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['varkey']['limit'] = '0';
  $handler->display->display_options['path'] = 'dhprop-text';

	$views['dh_list_properties'] = $view;

  $view = new view();
  $view->name = 'dh_feature_tabbed_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Feature Tabbed View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - Feature Tabbed View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] (click to Edit)';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_features/manage/[hydroid]';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = 'destination=dh-feature-detail/[hydroid]';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  /* Field: DH Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['label'] = 'Bundle: Type';
  $handler->display->display_options['fields']['ftype']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ftype']['alter']['text'] = '[bundle]: [ftype]';
  /* Contextual filter: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['arguments']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['arguments']['hydroid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-feature-detail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Info';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Time Series Data */
  $handler = $view->new_display('page', 'Time Series Data', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add New Water Withdrawal Record';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_timeseries/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'add&edit[varid]=[hydroid_1]&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wl';
  $handler->display->display_options['fields']['hydroid']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Data';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_timeseries_data';
  $handler->display->display_options['fields']['view']['display'] = 'page_4';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydrocode]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'dh-feature-detail/%/ts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'TimeSeries Data';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Properties */
  $handler = $view->new_display('page', 'Properties', 'page_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Add New Water Quality Record';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dh_water_quality/form';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = '&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wq';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Attached Properties';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dh-feature-detail/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Properties';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: GeoJoins */
  $handler = $view->new_display('page', 'GeoJoins', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
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
    'hydroid' => 'hydroid',
    'name' => 'name',
    'hydrocode' => 'hydrocode',
    'bundle' => 'bundle',
    'ftype' => 'ftype',
    'name_1' => 'name_1',
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hydrocode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'bundle' => array(
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
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: GeoJoin - Within */
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['id'] = 'dh_feature_dh_geofield';
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['table'] = 'geojoin';
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['field'] = 'dh_feature_dh_geofield';
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['ui_name'] = 'GeoJoin - Within';
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['label'] = 'GeoJoin - Contains';
  $handler->display->display_options['relationships']['dh_feature_dh_geofield']['relation_operator'] = 'contains';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'dh_feature_dh_geofield';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] (click to Edit)';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_features/manage/[hydroid]';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = 'destination=dh-feature-detail/[hydroid]';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['relationship'] = 'dh_feature_dh_geofield';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['relationship'] = 'dh_feature_dh_geofield';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  /* Field: DH Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['relationship'] = 'dh_feature_dh_geofield';
  $handler->display->display_options['fields']['ftype']['label'] = 'Bundle: Type';
  $handler->display->display_options['fields']['ftype']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ftype']['alter']['text'] = '[bundle]: [ftype]';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['path'] = 'dh-feature-detail/%/geojoin';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'GeoJoins';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-feature-detail/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Info';
  $handler->display->display_options['tab_options']['weight'] = '0';

	$views['dh_feature_tabbed_view'] = $view;
  
  $view = new view();
  $view->name = 'dh_well_tabbed_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Well Tabbed View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - Well Tabbed View';
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
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_mp';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!hydroid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = '';
  $handler->display->display_options['footer']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['footer']['view_field']['view'] = 'dha_add_list_mp';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!hydroid]';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_center' => array(
      'lat' => '37.6188121',
      'lon' => '-77.47389810000001',
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
    'geofield_map_scrollwheel' => 0,
    'geofield_map_draggable' => 0,
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-well-detail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Info';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Interval Data */
  $handler = $view->new_display('page', 'Interval Data', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add New Interval Record';
  $handler->display->display_options['fields']['hydroid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_boreholelog/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'wellid=[hydroid]&destination=dh-well-detail/[hydrocode]/bhl';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Interval Data';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_borehole_data';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dh-well-detail/%/bhl';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Interval Data';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Withdrawals */
  $handler = $view->new_display('page', 'Withdrawals', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add New Water Withdrawal Record';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_timeseries/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'add&edit[varid]=[hydroid_1]&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wl';
  $handler->display->display_options['fields']['hydroid']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = 'Add New Withdrawal Record';
  $handler->display->display_options['fields']['view_1']['view'] = 'xct_water_withdrawal_form';
  $handler->display->display_options['fields']['view_1']['display'] = 'page';
  $handler->display->display_options['fields']['view_1']['arguments'] = 'wlg/[%hydroid]';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Withdrawal Data';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_timeseries_data';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]/wlg';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'dh-well-detail/%/wl';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Withdrawals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Water Quality */
  $handler = $view->new_display('page', 'Water Quality', 'page_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Add New Water Quality Record';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dh_water_quality/form';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = '&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wq';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Water Quality Data';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_timeseries_data';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]/all/water_quality';
  $handler->display->display_options['path'] = 'dh-well-detail/%/wq';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Water Quality';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Well Data */
  $handler = $view->new_display('page', 'Well Data', 'page_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Attached Properties';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dh-well-detail/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Well Data';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

	$views['dh_well_tabbed_view'] = $view;

  $view = new view();
  $view->name = 'dh_intake_tabbed_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_feature';
  $view->human_name = 'dH - Intake Tabbed View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - Intake Tabbed View';
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
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'dha_breadcrumb_mp';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '[!hydroid]';
  /* Footer: Global: View (Views field view) */
  $handler->display->display_options['footer']['view_field']['id'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['table'] = 'views';
  $handler->display->display_options['footer']['view_field']['field'] = 'view_field';
  $handler->display->display_options['footer']['view_field']['label'] = '';
  $handler->display->display_options['footer']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['footer']['view_field']['view'] = 'dha_add_list_mp';
  $handler->display->display_options['footer']['view_field']['display'] = 'page';
  $handler->display->display_options['footer']['view_field']['arguments'] = '[!hydroid]/[!adminid]';
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
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] (click to Edit)';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'admin/content/dh_features/manage/[hydroid]';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = 'destination=dh-feature-detail/[hydroid]';
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  /* Field: DH Feature: Bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  /* Field: DH Feature: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid_1']['id'] = 'hydroid_1';
  $handler->display->display_options['fields']['hydroid_1']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid_1']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid_1']['relationship'] = 'dh_link_facility_mps_target_id';
  $handler->display->display_options['fields']['hydroid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid_1']['separator'] = '';
  /* Field: DH AdminReg Feature: Dh adminreg feature ID */
  $handler->display->display_options['fields']['adminid']['id'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['table'] = 'dh_adminreg_feature';
  $handler->display->display_options['fields']['adminid']['field'] = 'adminid';
  $handler->display->display_options['fields']['adminid']['relationship'] = 'dh_link_admin_location_target_id';
  $handler->display->display_options['fields']['adminid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['adminid']['separator'] = '';
  /* Field: dH Feature: Geometry */
  $handler->display->display_options['fields']['dh_geofield']['id'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['table'] = 'field_data_dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['field'] = 'dh_geofield';
  $handler->display->display_options['fields']['dh_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['dh_geofield']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['dh_geofield']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_center' => array(
      'lat' => '37.618817',
      'lon' => '-77.4739061',
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
    'geofield_map_baselayers_physical' => 1,
    'geofield_map_scale' => 1,
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
  $handler->display->display_options['arguments']['hydroid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['hydroid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydroid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydroid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydroid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydroid']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dh-intake-detail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Info';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Time Series Data */
  $handler = $view->new_display('page', 'Time Series Data', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'Add New Water Withdrawal Record';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_timeseries/add';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'add&edit[varid]=[hydroid_1]&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wl';
  $handler->display->display_options['fields']['hydroid']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Data';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_timeseries_data';
  $handler->display->display_options['fields']['view']['display'] = 'page_4';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydrocode]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'dh-intake-detail/%/ts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'TimeSeries Data';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Properties */
  $handler = $view->new_display('page', 'Properties', 'page_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Feature: Hydrocode */
  $handler->display->display_options['fields']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['fields']['hydrocode']['exclude'] = TRUE;
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Feature: Feature Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Add New Water Quality Record';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'dh_water_quality/form';
  $handler->display->display_options['fields']['name']['alter']['path_query_parameters'] = '&edit[featureid]=[hydroid]&destination=dh-well-detail/[hydrocode]/wq';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Attached Properties';
  $handler->display->display_options['fields']['view']['view'] = 'dh_list_properties';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[!hydroid]';
  $handler->display->display_options['path'] = 'dh-intake-detail/%/props';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Properties';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Info */
  $handler = $view->new_display('page', 'Info', 'page_1');
  $handler->display->display_options['path'] = 'dh-intake-detail/%/info';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $views['dh_intake_tabbed_view'] = $view;

  $view = new view();
  $view->name = 'dh_list_borehole_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_boreholelog';
  $view->human_name = 'dH - List Borehole Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH - List Well Interval Data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['wellid_target_id']['id'] = 'wellid_target_id';
  $handler->display->display_options['relationships']['wellid_target_id']['table'] = 'field_data_wellid';
  $handler->display->display_options['relationships']['wellid_target_id']['field'] = 'wellid_target_id';
  $handler->display->display_options['relationships']['wellid_target_id']['label'] = 'dH Feature Well';
  /* Field: DH Borehole Log: Label */
  $handler->display->display_options['fields']['bhlid']['id'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['bhlid']['field'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['label'] = 'Internal, numeric dh borehole log ID';
  $handler->display->display_options['fields']['bhlid']['exclude'] = TRUE;
  /* Field: DH Borehole Log: Diameter */
  $handler->display->display_options['fields']['diameter']['id'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['diameter']['field'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['precision'] = '0';
  /* Field: DH Borehole Log: Fromdepth */
  $handler->display->display_options['fields']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['fromdepth']['field'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['precision'] = '0';
  /* Field: DH Borehole Log: Todepth */
  $handler->display->display_options['fields']['todepth']['id'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['todepth']['field'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['precision'] = '0';
  /* Field: DH Borehole Log: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH Borehole Log: Hgucode */
  $handler->display->display_options['fields']['hgucode']['id'] = 'hgucode';
  $handler->display->display_options['fields']['hgucode']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['hgucode']['field'] = 'hgucode';
  /* Field: DH Borehole Log: Logtype */
  $handler->display->display_options['fields']['logtype']['id'] = 'logtype';
  $handler->display->display_options['fields']['logtype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['logtype']['field'] = 'logtype';
  /* Field: Field: Hydrogeologic Unit */
  $handler->display->display_options['fields']['hguid']['id'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['table'] = 'field_data_hguid';
  $handler->display->display_options['fields']['hguid']['field'] = 'hguid';
  $handler->display->display_options['fields']['hguid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['hguid']['delta_offset'] = '0';
  /* Sort criterion: DH Borehole Log: Fromdepth */
  $handler->display->display_options['sorts']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['sorts']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['fromdepth']['field'] = 'fromdepth';
  /* Sort criterion: DH Borehole Log: Todepth */
  $handler->display->display_options['sorts']['todepth']['id'] = 'todepth';
  $handler->display->display_options['sorts']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['todepth']['field'] = 'todepth';
  /* Contextual filter: dH Borehole Log: Well ID (wellid) */
  $handler->display->display_options['arguments']['wellid_target_id']['id'] = 'wellid_target_id';
  $handler->display->display_options['arguments']['wellid_target_id']['table'] = 'field_data_wellid';
  $handler->display->display_options['arguments']['wellid_target_id']['field'] = 'wellid_target_id';
  $handler->display->display_options['arguments']['wellid_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['wellid_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['wellid_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['wellid_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['wellid_target_id']['comparator'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Borehole Log: Label */
  $handler->display->display_options['fields']['bhlid']['id'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['bhlid']['field'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['label'] = 'Internal, numeric dh borehole log ID';
  $handler->display->display_options['fields']['bhlid']['exclude'] = TRUE;
  /* Field: DH Borehole Log: Diameter */
  $handler->display->display_options['fields']['diameter']['id'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['diameter']['field'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['precision'] = '0';
  /* Field: DH Borehole Log: Fromdepth */
  $handler->display->display_options['fields']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['fromdepth']['field'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['precision'] = '0';
  /* Field: DH Borehole Log: Todepth */
  $handler->display->display_options['fields']['todepth']['id'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['todepth']['field'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['precision'] = '0';
  /* Field: DH Borehole Log: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH Borehole Log: Hgucode */
  $handler->display->display_options['fields']['hgucode']['id'] = 'hgucode';
  $handler->display->display_options['fields']['hgucode']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['hgucode']['field'] = 'hgucode';
  /* Field: DH Borehole Log: Logtype */
  $handler->display->display_options['fields']['logtype']['id'] = 'logtype';
  $handler->display->display_options['fields']['logtype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['logtype']['field'] = 'logtype';
  /* Field: dH Borehole Log: Well ID */
  $handler->display->display_options['fields']['wellid']['id'] = 'wellid';
  $handler->display->display_options['fields']['wellid']['table'] = 'field_data_wellid';
  $handler->display->display_options['fields']['wellid']['field'] = 'wellid';
  $handler->display->display_options['fields']['wellid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['wellid']['delta_offset'] = '0';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['relationship'] = 'wellid_target_id';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Hydrogeologic Unit: Label */
  $handler->display->display_options['fields']['hguname']['id'] = 'hguname';
  $handler->display->display_options['fields']['hguname']['table'] = 'dh_hydrogeologicunit';
  $handler->display->display_options['fields']['hguname']['field'] = 'hguname';
  $handler->display->display_options['fields']['hguname']['label'] = 'Hydrogeologic Unit';
  /* Field: DH Borehole Log: Label */
  $handler->display->display_options['fields']['bhlid_1']['id'] = 'bhlid_1';
  $handler->display->display_options['fields']['bhlid_1']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['bhlid_1']['field'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid_1']['label'] = '';
  $handler->display->display_options['fields']['bhlid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['bhlid_1']['alter']['text'] = 'Edit Interval';
  $handler->display->display_options['fields']['bhlid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['bhlid_1']['alter']['path'] = 'admin/content/dh_boreholelog/manage/[bhlid_1]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['sorts']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['sorts']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['sorts']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['sorts']['hydroid']['relationship'] = 'wellid_target_id';
  $handler->display->display_options['sorts']['hydroid']['order'] = 'DESC';
  /* Sort criterion: DH Borehole Log: Fromdepth */
  $handler->display->display_options['sorts']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['sorts']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['fromdepth']['field'] = 'fromdepth';
  /* Sort criterion: DH Borehole Log: Todepth */
  $handler->display->display_options['sorts']['todepth']['id'] = 'todepth';
  $handler->display->display_options['sorts']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['todepth']['field'] = 'todepth';
  $handler->display->display_options['path'] = 'dh-list-borehole-data';

  /* Display: By Hydrocode */
  $handler = $view->new_display('page', 'By Hydrocode', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH Feature: Hydrocode */
  $handler->display->display_options['arguments']['hydrocode']['id'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['table'] = 'dh_feature';
  $handler->display->display_options['arguments']['hydrocode']['field'] = 'hydrocode';
  $handler->display->display_options['arguments']['hydrocode']['relationship'] = 'wellid_target_id';
  $handler->display->display_options['arguments']['hydrocode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['hydrocode']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['hydrocode']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['hydrocode']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['hydrocode']['limit'] = '0';
  $handler->display->display_options['path'] = 'dh-bhl-hcode';
  $handler->display->display_options['menu']['title'] = 'Borehole Data';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Tiny */
  $handler = $view->new_display('page', 'Tiny', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Borehole Log: Ftype */
  $handler->display->display_options['fields']['ftype']['id'] = 'ftype';
  $handler->display->display_options['fields']['ftype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['ftype']['field'] = 'ftype';
  /* Field: DH Borehole Log: Label */
  $handler->display->display_options['fields']['bhlid']['id'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['bhlid']['field'] = 'bhlid';
  $handler->display->display_options['fields']['bhlid']['label'] = 'Internal, numeric dh borehole log ID';
  $handler->display->display_options['fields']['bhlid']['exclude'] = TRUE;
  /* Field: DH Borehole Log: Diameter */
  $handler->display->display_options['fields']['diameter']['id'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['diameter']['field'] = 'diameter';
  $handler->display->display_options['fields']['diameter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['diameter']['precision'] = '0';
  /* Field: DH Borehole Log: Fromdepth */
  $handler->display->display_options['fields']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['fromdepth']['field'] = 'fromdepth';
  $handler->display->display_options['fields']['fromdepth']['precision'] = '0';
  /* Field: DH Borehole Log: Todepth */
  $handler->display->display_options['fields']['todepth']['id'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['todepth']['field'] = 'todepth';
  $handler->display->display_options['fields']['todepth']['precision'] = '0';
  /* Field: DH Borehole Log: Hgucode */
  $handler->display->display_options['fields']['hgucode']['id'] = 'hgucode';
  $handler->display->display_options['fields']['hgucode']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['hgucode']['field'] = 'hgucode';
  $handler->display->display_options['fields']['hgucode']['exclude'] = TRUE;
  /* Field: DH Borehole Log: Logtype */
  $handler->display->display_options['fields']['logtype']['id'] = 'logtype';
  $handler->display->display_options['fields']['logtype']['table'] = 'dh_boreholelog';
  $handler->display->display_options['fields']['logtype']['field'] = 'logtype';
  $handler->display->display_options['fields']['logtype']['exclude'] = TRUE;
  $handler->display->display_options['fields']['logtype']['separator'] = '';
  /* Field: dH Borehole Log: Well ID */
  $handler->display->display_options['fields']['wellid']['id'] = 'wellid';
  $handler->display->display_options['fields']['wellid']['table'] = 'field_data_wellid';
  $handler->display->display_options['fields']['wellid']['field'] = 'wellid';
  $handler->display->display_options['fields']['wellid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['wellid']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['wellid']['delta_offset'] = '0';
  /* Field: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['relationship'] = 'wellid_target_id';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH Hydrogeologic Unit: Label */
  $handler->display->display_options['fields']['hguname']['id'] = 'hguname';
  $handler->display->display_options['fields']['hguname']['table'] = 'dh_hydrogeologicunit';
  $handler->display->display_options['fields']['hguname']['field'] = 'hguname';
  $handler->display->display_options['fields']['hguname']['label'] = 'Hydrogeologic Unit';
  $handler->display->display_options['fields']['hguname']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: DH Feature: HydroID - Unique Feature ID */
  $handler->display->display_options['sorts']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['sorts']['hydroid']['table'] = 'dh_feature';
  $handler->display->display_options['sorts']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['sorts']['hydroid']['relationship'] = 'wellid_target_id';
  $handler->display->display_options['sorts']['hydroid']['order'] = 'DESC';
  /* Sort criterion: DH Borehole Log: Fromdepth */
  $handler->display->display_options['sorts']['fromdepth']['id'] = 'fromdepth';
  $handler->display->display_options['sorts']['fromdepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['fromdepth']['field'] = 'fromdepth';
  /* Sort criterion: DH Borehole Log: Todepth */
  $handler->display->display_options['sorts']['todepth']['id'] = 'todepth';
  $handler->display->display_options['sorts']['todepth']['table'] = 'dh_boreholelog';
  $handler->display->display_options['sorts']['todepth']['field'] = 'todepth';
  $handler->display->display_options['path'] = 'dh-list-borehole-tiny';

  $views['dh_list_borehole_data'] = $view;
  
  $view = new view();
  $view->name = 'add_dh_properties_jump_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_variabledefinition';
  $view->human_name = 'Add dH Properties Jump List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Add dH Properties Jump List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'vocabulary',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['path'] = 'hydroid';
  $handler->display->display_options['style_options']['text'] = 'Add';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: DH VariableDefinition: HydroID - Unique Feature ID (VarID in Time Series) */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'admin/content/dh_properties/add/dh_properties?varid=[hydroid]&featureid=!1&entity_type=dh_properties&destination=admin/content/dh_properties/manage/!1/dh_properties';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_properties/manage/!1/dh_properties/add/dh_properties';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'varid=[hydroid]&featureid=!1&entity_type=dh_properties';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = '';
  $handler->display->display_options['fields']['varname']['element_label_colon'] = FALSE;
  /* Field: DH VariableDefinition: vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['label'] = '';
  $handler->display->display_options['fields']['vocabulary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vocabulary']['element_label_colon'] = FALSE;
  /* Sort criterion: DH VariableDefinition: vocabulary */
  $handler->display->display_options['sorts']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['sorts']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['sorts']['vocabulary']['field'] = 'vocabulary';
  /* Sort criterion: DH VariableDefinition: Variable Name */
  $handler->display->display_options['sorts']['varname']['id'] = 'varname';
  $handler->display->display_options['sorts']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['sorts']['varname']['field'] = 'varname';
  /* Contextual filter: featureid */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'featureid';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';

  /* Display: Entity Type dh_properties */
  $handler = $view->new_display('page', 'Entity Type dh_properties', 'page');
  $handler->display->display_options['path'] = 'add-dh-properties-jump-list';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Type dh_feature */
  $handler = $view->new_display('page', 'Entity Type dh_feature', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH VariableDefinition: HydroID - Unique Feature ID (VarID in Time Series) */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'admin/content/dh_properties/add/dh_properties?varid=[hydroid]&featureid=!1&entity_type=dh_feature&destination=admin/content/dh_features/manage/!1/dh_properties';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_properties/manage/!1/dh_properties/add/dh_properties';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'varid=[hydroid]&featureid=!1&entity_type=dh_properties';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = '';
  $handler->display->display_options['fields']['varname']['element_label_colon'] = FALSE;
  /* Field: DH VariableDefinition: vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['label'] = '';
  $handler->display->display_options['fields']['vocabulary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vocabulary']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'add-dh-properties-jump-list';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: dh_timeseries to dh_feature */
  $handler = $view->new_display('page', 'dh_timeseries to dh_feature', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH VariableDefinition: HydroID - Unique Feature ID (VarID in Time Series) */
  $handler->display->display_options['fields']['hydroid']['id'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['hydroid']['field'] = 'hydroid';
  $handler->display->display_options['fields']['hydroid']['label'] = '';
  $handler->display->display_options['fields']['hydroid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hydroid']['alter']['text'] = 'admin/content/dh_timeseries/add/?varid=[hydroid]&featureid=!1&entity_type=dh_feature&destination=admin/content/dh_features/manage/!1/dh_timeseries';
  $handler->display->display_options['fields']['hydroid']['alter']['path'] = 'admin/content/dh_properties/manage/!1/dh_properties/add/dh_properties';
  $handler->display->display_options['fields']['hydroid']['alter']['path_query_parameters'] = 'varid=[hydroid]&featureid=!1&entity_type=dh_properties';
  $handler->display->display_options['fields']['hydroid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hydroid']['separator'] = '';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  $handler->display->display_options['fields']['varname']['label'] = '';
  $handler->display->display_options['fields']['varname']['element_label_colon'] = FALSE;
  /* Field: DH VariableDefinition: vocabulary */
  $handler->display->display_options['fields']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['fields']['vocabulary']['label'] = '';
  $handler->display->display_options['fields']['vocabulary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vocabulary']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'add-dh-properties-jump-list';
  $handler->display->display_options['menu']['title'] = 'dH Timeseries';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['add_dh_properties_jump_list'] = $view;
  
  $view = new view();
  $view->name = 'dh_admin_content_properties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_properties';
  $view->human_name = 'dH Admin Content Properties';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH Admin Content Properties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page_3';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_properties/dh_properties';
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = 'Pid';
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['path'] = 'admin/content/dh_properties/manage/[pid]';
  $handler->display->display_options['fields']['pid']['alter']['path_query_parameters'] = 'destination=admin/content/dh_features/manage/!1/dh_properties';
  $handler->display->display_options['fields']['pid']['separator'] = '';
  /* Field: DH Properties: Property Name */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  /* Field: DH Properties: propcode */
  $handler->display->display_options['fields']['propcode']['id'] = 'propcode';
  $handler->display->display_options['fields']['propcode']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propcode']['field'] = 'propcode';
  /* Field: DH Properties: propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['precision'] = '0';
  /* Field: DH Properties: Startdate */
  $handler->display->display_options['fields']['startdate']['id'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['startdate']['field'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['date_format'] = 'short';
  $handler->display->display_options['fields']['startdate']['second_date_format'] = 'long';
  /* Field: DH Properties: Enddate */
  $handler->display->display_options['fields']['enddate']['id'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['enddate']['field'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['date_format'] = 'short';
  $handler->display->display_options['fields']['enddate']['second_date_format'] = 'long';
  /* Field: DH VariableDefinition: Variable Key (may be short name or = varname) */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  /* Field: DH Properties: entity_type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['label'] = '';
  $handler->display->display_options['fields']['entity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_type']['element_label_colon'] = FALSE;
  /* Field: DH Properties: featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: Rewrite return link if dh_feature */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['ui_name'] = 'Rewrite return link if dh_feature';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'entity_type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'dh_feature';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'dh_features';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[entity_type]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  $handler->display->display_options['fields']['pid_1']['label'] = '';
  $handler->display->display_options['fields']['pid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['text'] = 'x';
  $handler->display->display_options['fields']['pid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['path'] = 'admin/content/dh_properties/manage/[pid_1]/delete';
  $handler->display->display_options['fields']['pid_1']['alter']['path_query_parameters'] = 'destination=admin/content/[views_conditional]/manage/[featureid]/dh_properties';
  $handler->display->display_options['fields']['pid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid_1']['separator'] = '';
  /* Contextual filter: DH Properties: featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = 'eq';
  $handler->display->display_options['arguments']['featureid']['op_location'] = 'where';
  /* Contextual filter: DH VariableDefinition: vocabulary */
  $handler->display->display_options['arguments']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['arguments']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['arguments']['vocabulary']['default_action'] = 'default';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vocabulary']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['vocabulary']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vocabulary']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vocabulary']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vocabulary']['limit'] = '0';
  /* Filter criterion: DH Properties: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'dh_adminreg_feature';
  $handler->display->display_options['filters']['entity_type']['op_location'] = 'where';

  /* Display: Feature Properties */
  $handler = $view->new_display('page', 'Feature Properties', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1/!2';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_features/dh_properties';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: DH Properties: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'dh_feature';
  $handler->display->display_options['filters']['entity_type']['op_location'] = 'where';
  $handler->display->display_options['path'] = 'admin/content/dh_features/manage/%/dh_properties';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Timeseries Properties */
  $handler = $view->new_display('page', 'Timeseries Properties', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page_3';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1/!2';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_timeseries/dh_properties';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: DH Properties: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'dh_timeseries';
  $handler->display->display_options['filters']['entity_type']['op_location'] = 'where';
  $handler->display->display_options['path'] = 'admin/content/dh_timeseries/manage/%/dh_properties';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Properties Properties */
  $handler = $view->new_display('page', 'Properties Properties', 'page_2');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1/!2';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_properties/dh_properties';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = 'Pid';
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['path'] = 'admin/content/dh_properties/manage/[pid]';
  $handler->display->display_options['fields']['pid']['alter']['path_query_parameters'] = 'destination=admin/content/dh_properties/manage/!1/dh_properties';
  $handler->display->display_options['fields']['pid']['separator'] = '';
  /* Field: DH Properties: Property Name */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  /* Field: DH Properties: propcode */
  $handler->display->display_options['fields']['propcode']['id'] = 'propcode';
  $handler->display->display_options['fields']['propcode']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propcode']['field'] = 'propcode';
  /* Field: DH Properties: propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['precision'] = '0';
  /* Field: DH Properties: Startdate */
  $handler->display->display_options['fields']['startdate']['id'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['startdate']['field'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['date_format'] = 'short';
  $handler->display->display_options['fields']['startdate']['second_date_format'] = 'long';
  /* Field: DH Properties: Enddate */
  $handler->display->display_options['fields']['enddate']['id'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['enddate']['field'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['date_format'] = 'short';
  $handler->display->display_options['fields']['enddate']['second_date_format'] = 'long';
  /* Field: DH VariableDefinition: Variable Key (may be short name or = varname) */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  /* Field: DH Properties: featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = '';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  $handler->display->display_options['fields']['pid_1']['label'] = '';
  $handler->display->display_options['fields']['pid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['text'] = 'x';
  $handler->display->display_options['fields']['pid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['path'] = 'admin/content/dh_properties/manage/[pid_1]/delete';
  $handler->display->display_options['fields']['pid_1']['alter']['path_query_parameters'] = 'destination=admin/content/dh_properties/manage/[featureid]/dh_properties';
  $handler->display->display_options['fields']['pid_1']['alter']['link_class'] = 'subtractlink';
  $handler->display->display_options['fields']['pid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid_1']['separator'] = '';
  /* Field: Bulk operations: DH Properties */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_dh_properties';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '40';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: DH Properties: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['op_location'] = 'where';
  $handler->display->display_options['path'] = 'admin/content/dh_properties/manage/%/dh_properties';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Adminreg Feature Properties */
  $handler = $view->new_display('page', 'Adminreg Feature Properties', 'page_3');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page_4';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1/!2';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_adminreg_feature/dh_properties';
  $handler->display->display_options['path'] = 'admin/content/dh_adminreg_feature/manage/%/dh_properties';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/content/dh_timeseries/manage/*/dh_properties/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
    'page_2' => 0,
    'page_3' => 0,
  );

  /* Display: VarDef Properties */
  $handler = $view->new_display('page', 'VarDef Properties', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Attached Properties';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field']['id'] = 'view_field';
  $handler->display->display_options['header']['view_field']['table'] = 'views';
  $handler->display->display_options['header']['view_field']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field']['label'] = '';
  $handler->display->display_options['header']['view_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['header']['view_field']['view'] = 'add_dh_properties_jump_list';
  $handler->display->display_options['header']['view_field']['display'] = 'page';
  $handler->display->display_options['header']['view_field']['arguments'] = '!1/!2';
  /* Header: Global: View (Views field view) */
  $handler->display->display_options['header']['view_field_1']['id'] = 'view_field_1';
  $handler->display->display_options['header']['view_field_1']['table'] = 'views';
  $handler->display->display_options['header']['view_field_1']['field'] = 'view_field';
  $handler->display->display_options['header']['view_field_1']['view'] = 'dh_variabledefinition_vocabularies';
  $handler->display->display_options['header']['view_field_1']['display'] = 'page_1';
  $handler->display->display_options['header']['view_field_1']['arguments'] = '!1/!2/dh_variabledefinition/dh_properties';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = 'Pid';
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['path'] = 'admin/content/dh_properties/manage/[pid]';
  $handler->display->display_options['fields']['pid']['alter']['path_query_parameters'] = 'destination=admin/content/dh_variabledefinition/manage/!1/dh_properties';
  $handler->display->display_options['fields']['pid']['separator'] = '';
  /* Field: DH Properties: Property Name */
  $handler->display->display_options['fields']['propname']['id'] = 'propname';
  $handler->display->display_options['fields']['propname']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propname']['field'] = 'propname';
  /* Field: DH Properties: propcode */
  $handler->display->display_options['fields']['propcode']['id'] = 'propcode';
  $handler->display->display_options['fields']['propcode']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propcode']['field'] = 'propcode';
  /* Field: DH Properties: propvalue */
  $handler->display->display_options['fields']['propvalue']['id'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['propvalue']['field'] = 'propvalue';
  $handler->display->display_options['fields']['propvalue']['precision'] = '0';
  /* Field: DH Properties: Startdate */
  $handler->display->display_options['fields']['startdate']['id'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['startdate']['field'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['date_format'] = 'short';
  $handler->display->display_options['fields']['startdate']['second_date_format'] = 'long';
  /* Field: DH Properties: Enddate */
  $handler->display->display_options['fields']['enddate']['id'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['enddate']['field'] = 'enddate';
  $handler->display->display_options['fields']['enddate']['date_format'] = 'short';
  $handler->display->display_options['fields']['enddate']['second_date_format'] = 'long';
  /* Field: DH VariableDefinition: Variable Key (may be short name or = varname) */
  $handler->display->display_options['fields']['varkey']['id'] = 'varkey';
  $handler->display->display_options['fields']['varkey']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varkey']['field'] = 'varkey';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  /* Field: DH Properties: featureid */
  $handler->display->display_options['fields']['featureid']['id'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['featureid']['field'] = 'featureid';
  $handler->display->display_options['fields']['featureid']['label'] = '';
  $handler->display->display_options['fields']['featureid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['featureid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['featureid']['separator'] = '';
  /* Field: DH Properties: Label */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'dh_properties';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  $handler->display->display_options['fields']['pid_1']['label'] = '';
  $handler->display->display_options['fields']['pid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['text'] = 'x';
  $handler->display->display_options['fields']['pid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid_1']['alter']['path'] = 'admin/content/dh_properties/manage/[pid_1]/delete';
  $handler->display->display_options['fields']['pid_1']['alter']['path_query_parameters'] = 'destination=admin/content/dh_variabledefinition/manage/[featureid]/dh_properties';
  $handler->display->display_options['fields']['pid_1']['alter']['link_class'] = 'subtractlink';
  $handler->display->display_options['fields']['pid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid_1']['separator'] = '';
  /* Field: Bulk operations: DH Properties */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_dh_properties';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '40';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: DH Properties: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'dh_properties';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'dh_variabledefinition';
  $handler->display->display_options['filters']['entity_type']['op_location'] = 'where';
  $handler->display->display_options['path'] = 'admin/content/dh_variabledefinition/manage/%/dh_properties';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH Properties';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;


  $views['dh_admin_content_properties'] = $view;
  
  $view = new view();
  $view->name = 'dh_admin_content_timeseries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dh_timeseries';
  $view->human_name = 'dH Admin Content TimeSeries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dH Admin Content TimeSeries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: DH TimeSeries: Label */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Tid';
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['path'] = 'admin/content/dh_timeseries/manage/[tid]';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: DH TimeSeries: tscode */
  $handler->display->display_options['fields']['tscode']['id'] = 'tscode';
  $handler->display->display_options['fields']['tscode']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tscode']['field'] = 'tscode';
  /* Field: DH TimeSeries: tstime */
  $handler->display->display_options['fields']['tstime']['id'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tstime']['field'] = 'tstime';
  $handler->display->display_options['fields']['tstime']['date_format'] = 'short';
  $handler->display->display_options['fields']['tstime']['second_date_format'] = 'long';
  /* Field: DH TimeSeries: tsendtime */
  $handler->display->display_options['fields']['tsendtime']['id'] = 'tsendtime';
  $handler->display->display_options['fields']['tsendtime']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsendtime']['field'] = 'tsendtime';
  $handler->display->display_options['fields']['tsendtime']['date_format'] = 'short';
  $handler->display->display_options['fields']['tsendtime']['second_date_format'] = 'long';
  /* Field: DH TimeSeries: tsvalue */
  $handler->display->display_options['fields']['tsvalue']['id'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['table'] = 'dh_timeseries';
  $handler->display->display_options['fields']['tsvalue']['field'] = 'tsvalue';
  $handler->display->display_options['fields']['tsvalue']['precision'] = '0';
  /* Field: DH VariableDefinition: Variable Name */
  $handler->display->display_options['fields']['varname']['id'] = 'varname';
  $handler->display->display_options['fields']['varname']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varname']['field'] = 'varname';
  /* Field: DH VariableDefinition: varunits */
  $handler->display->display_options['fields']['varunits']['id'] = 'varunits';
  $handler->display->display_options['fields']['varunits']['table'] = 'dh_variabledefinition';
  $handler->display->display_options['fields']['varunits']['field'] = 'varunits';
  /* Sort criterion: DH TimeSeries: tstime */
  $handler->display->display_options['sorts']['tstime']['id'] = 'tstime';
  $handler->display->display_options['sorts']['tstime']['table'] = 'dh_timeseries';
  $handler->display->display_options['sorts']['tstime']['field'] = 'tstime';
  /* Contextual filter: DH TimeSeries: featureid */
  $handler->display->display_options['arguments']['featureid']['id'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['table'] = 'dh_timeseries';
  $handler->display->display_options['arguments']['featureid']['field'] = 'featureid';
  $handler->display->display_options['arguments']['featureid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['featureid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['featureid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['featureid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['featureid']['comparator'] = 'eq';
  $handler->display->display_options['arguments']['featureid']['op_location'] = 'where';
  /* Filter criterion: DH TimeSeries: varid (selector) */
  $handler->display->display_options['filters']['varidid']['id'] = 'varidid';
  $handler->display->display_options['filters']['varidid']['table'] = 'dh_timeseries';
  $handler->display->display_options['filters']['varidid']['field'] = 'varidid';
  $handler->display->display_options['filters']['varidid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['varidid']['expose']['operator_id'] = 'varidid_op';
  $handler->display->display_options['filters']['varidid']['expose']['label'] = 'varid (selector)';
  $handler->display->display_options['filters']['varidid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['varidid']['expose']['operator'] = 'varidid_op';
  $handler->display->display_options['filters']['varidid']['expose']['identifier'] = 'varidid';
  $handler->display->display_options['filters']['varidid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['varidid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['varidid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
  );

  /* Display: dh_feature */
  $handler = $view->new_display('page', 'dh_feature', 'page');
  $handler->display->display_options['path'] = 'admin/content/dh_features/manage/%/dh_timeseries';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'dH TimeSeries';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Full dH TimeSeries */
  $handler = $view->new_display('page', 'Full dH TimeSeries', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: DH TimeSeries: Rendered dH TimeSeries */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_dh_timeseries';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'plugin';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: DH TimeSeries: Label */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'dh_timeseries';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['comparator'] = 'eq';
  $handler->display->display_options['arguments']['tid']['op_location'] = 'where';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/dh_timeseries/manage/%/full';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'View';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['dh_admin_content_timeseries'] = $view;
  
  
  
  return $views;
}