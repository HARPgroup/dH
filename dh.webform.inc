<?php

// Webform hooks


function xxdh_webform_submission_insert($node, $submission) {
  // Insert a record into a 3rd-party module table when a submission is added.
  /*
  db_insert('mymodule_table')
    ->fields(array(
      'nid' => $node->nid,
      'sid' => $submission->sid,
      'foo' => 'foo_data',
    ))
    ->execute();
  */
  drupal_set_message("dH Webform Hook dh_webform_submission_insert loaded.");
  error_log("dH Webform Hook dh_webform_submission_insert loaded.");
}

?>