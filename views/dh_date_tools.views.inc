<?php

/**
 * Implements hook_views_data_alter().
 */
function date_tools_views_data() {
  $data = array();
  $data['date_tools_calendar'] = array(
    'table' => array(
      'group' => t('DTC'),
      'base' => array(
        'field' => 'ts',
        'title' => t('Date Tools Calendar'),
        'help' => t('A comprehensive date calendar for flexible joining to any date field or entity property.'),
      ),
    ),
  );
  // configure the base timestamp field
	$data['date_tools_calendar']['ts'] = array(
    'title' => 'Timestamp',
    'help' => t('Raw Unix Timestamp with date formatting options.'),
		'field' => array(
	  	'handler' => 'views_handler_field_date',
		  'click sortable' => TRUE,
		  'is date' => TRUE,
		),
		'sort' => array(
	  	'handler' => 'views_handler_sort_date',
		  'is date' => TRUE,
		),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
		'filter' => array(
		  'handler' => 'views_handler_filter_date',
      // in order to use this we have to apply patch: https://www.drupal.org/node/2100851
		  //'handler' => 'date_views_filter_handler',
		  'is date' => TRUE,
		),
  );
  // now configure the other descriptive fields
  
  $defaults_numeric = array(
    'title' => t('Numeric Field'),
    'help' => t('Numeric Field.'), // The help that appears on the UI,
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
      'float' => FALSE, // enables advanced formatting options
      'separator' => '', // thousands separator
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    )
  );
  // because the module may not be loaded when saving a view we need to do this
  $schema = date_tools_schema_views_hack();
  foreach ($schema['date_tools_calendar']['fields'] as $id => $field) {
    if ($id <> 'ts') {
      $data['date_tools_calendar'][$id] = $defaults_numeric;
      $data['date_tools_calendar'][$id]['title'] = $field['description'];
    }
  }
  // custom handler for the week
  $data['date_tools_calendar']['yrwk']['field']['handler'] = 'views_handler_field_week_numeric';
  // add relationshipos to calendar table
  date_tools_views_data_alter($data);
  return $data;
}

function date_tools_views_data_alter(&$data) {
  foreach ($data as $base_table => &$table) {
    foreach ($table as $id => &$field) {
      //dpm($field,"$base_table $id");
      if (isset($field['field']) && isset($field['field']['handler']) && (($field['field']['handler'] == 'views_handler_field_date') or is_subclass_of($field['field']['handler'], 'views_handler_field_date')) ) {
        // should go through and add a relationship for all entity types
        $data['date_tools_calendar']['date_link_' . $base_table . '_' . $id] = array(
          'real field' => 'adminid',
          'relationship' => array(
            'title' => 'All Dates Link to ' . $base_table . ' ' . $id,
            'help' => 'Will join ' . $base_table . ':' . $id . ' to date_tools_calendar:ts',
            'handler' => 'views_handler_relationship',
            'join_handler' => 'date_views_join',
            'label' => t('Date: Link ' . $base_table . ' to date table.'),
            'left_table' => 'date_tools_calendar',
            'field' => 'ts',
            'base' => $base_table,
            'base field' => $id,
          )
        );
      }
    }
  }
}

function date_tools_schema_views_hack() {
  
  $schema['date_tools_calendar'] = array (
    'description' => 'Base Calendar of dates',
    'fields' => array(
      'datid' => array(
        'description' => 'Primary key for Date Record',
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'ts' => array(
        'description' => 'Unix Timestamp',
        'type' => 'int',
        'not null' => TRUE,
        'default' => 1,
        'size' => 'big',
      ),
      'yr' => array(
        'description' => 'Year',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'qtr' => array(
        'description' => 'Quarter (1-4)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'tiny',
      ),
      'mon' => array(
        'description' => 'Month (1-12)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'tiny',
      ),
      'moday' => array(
        'description' => 'Day of Month (1-31)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'tiny',
      ),
      'yrday' => array(
        'description' => 'Day of year (0-365)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'small',
      ),
      'wkday' => array(
        'description' => 'Day of Week (0-6)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'tiny',
      ),
      'yrwk' => array(
        'description' => 'Week of Year (1-52)',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'size' => 'tiny',
      ),
    )
  );
  return $schema;
}