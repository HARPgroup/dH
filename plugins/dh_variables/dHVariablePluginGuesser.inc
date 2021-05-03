<?php

$plugin = array(
  'label' => t('Deprecated methd for guessing labels for variable display and edit'),
  'handler' =>  array(
    'class' => 'dHVariablePluginGuesser',
    'file' => 'dHVariablePluginGuesser.class.php',
  ),
);

?>