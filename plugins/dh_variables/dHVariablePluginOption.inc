<?php

$plugin = array(
  'label' => t('dH Option Property'),
  'handler' =>  array(
    'class' => 'dHVariablePluginOption',
    'file' => 'dHOMObjectClasses.class.php',
  ),
  'variable' =>  array(
    'varname' => 'dH Option Property',
    'vardesc' => 'Adding this to a variable will cause form rendering to be with a select box.',
    'vocabulary' => 'dh',
    'varunits' => 'n/a',
    'varkey' => 'dh_option_prop',
    'datatype' => 'interface',
    'varcode' => 'dh_option_prop',
    'isregular' => 0,
    'timestep' => 0,
    'timeunits' => 'n/a',
    'nodataval' => 0,
    'data_entry' => '',
    'plugin' => 'dHVariablePluginOption',
    'options' => '',
    'varabbrev' => 'Option',
  ),
);

?>