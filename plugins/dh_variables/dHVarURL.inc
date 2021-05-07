<?php

$plugin = array(
  'label' => t('External File'),
  'handler' =>  array(
    'class' => 'dHVarURL',
    'file' => 'dHVarImage.class.php',
  ),
  'variable' =>  array(
    'varname' => 'External File',
    'vardesc' => 'A URL of a useful externally-stored file.',
    'vocabulary' => 'image',
    'varunits' => 'n/a',
    'varkey' => 'external_file',
    'datatype' => 'component',
    'varcode' => 'external_file',
    'isregular' => 0,
    'timestep' => 0,
    'timeunits' => 'n/a',
    'nodataval' => 0,
    'data_entry' => '',
    'plugin' => 'dHVarURL',
    'options' => '',
    'varabbrev' => 'img',
  ),
);

?>