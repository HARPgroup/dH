<?php

$plugin = array(
  'label' => t('Image URL Property'),
  'handler' =>  array(
    'class' => 'dHVarImage',
    'file' => 'dHVarImage.class.php',
  ),
  'variable' =>  array(
    'varname' => 'Image URL',
    'vardesc' => 'Property to hold link to renderable image file (http only for now).',
    'vocabulary' => 'image',
    'varunits' => 'n/a',
    'varkey' => 'dh_image_file',
    'datatype' => 'component',
    'varcode' => 'dh_image_file',
    'isregular' => 0,
    'timestep' => 0,
    'timeunits' => 'n/a',
    'nodataval' => 0,
    'data_entry' => '',
    'plugin' => 'dHVarImage',
    'options' => '',
    'varabbrev' => 'img',
  ),
);

?>