<?php

$plugin = array(
  'label' => t('Attached Image Field Property'),
  'handler' =>  array(
    'class' => 'dHVarImageField',
    'file' => 'dHVarImage.class.php',
  ),
  'variable' =>  array(
    'varname' => 'Image URL',
    'vardesc' => 'Property to hold link Drupal image field.',
    'vocabulary' => 'image',
    'varunits' => 'n/a',
    'varkey' => 'dh_image_field',
    'datatype' => 'component',
    'varcode' => 'dh_image_field',
    'isregular' => 0,
    'timestep' => 0,
    'timeunits' => 'n/a',
    'nodataval' => 0,
    'data_entry' => '',
    'plugin' => 'dHVarImageField',
    'options' => '',
    'varabbrev' => 'imgf',
  ),
);

?>