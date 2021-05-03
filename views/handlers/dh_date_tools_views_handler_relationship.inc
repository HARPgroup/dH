<?php

/**
 * @file
 * Permit relating of time/date type fields to date_tools_calendar table of dates
 */

class dh_date_views_join extends views_join {
  
  /**
   * Build the SQL for the join this object represents.
   * This is only necessary because the standard views_join 
   * does not support the 'operator' in the definition forcing all joins to be '='
   * These issues track this for D7:  and D8: 
   */
  function build_join($select_query, $table, $view_query) {
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }
    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something. It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    $operator = !empty($this->definition['operator']) ? $this->definition['operator'] : '=';
    $condition = "$left_field $operator $table[alias].$this->field";
    $arguments = array();

    // Tack on the extra.
    if (isset($this->extra)) {
      if (is_array($this->extra)) {
        $extras = array();
        foreach ($this->extra as $info) {
          // Figure out the table name. Remember, only use aliases provided
          // if at all possible.
          $join_table = '';
          if (!array_key_exists('table', $info)) {
            $join_table = $table['alias'] . '.';
          }
          elseif (isset($info['table'])) {
            // If we're aware of a table alias for this table, use the table
            // alias instead of the table name.
            if (isset($left) && $left['table'] == $info['table']) {
              $join_table = $left['alias'] . '.';
            }
            else {
              $join_table = $info['table'] . '.';
            }
          }

          // If left_field is set use it for a field-to-field condition.
          if (!empty($info['left_field'])) {
            $operator = !empty($info['operator']) ? $info['operator'] : '=';
            $left_table = (isset($info['left_table'])) ? $info['left_table'] : $left['alias'];
            $extras[] = "$join_table$info[field] $operator $left_table.$info[left_field]";
          }
          // Else if formula is set, us it for a flexible on clause.
          elseif (!empty($info['formula'])) {
            // If a field is given, we build a "$field $op $formula".
            // Without it would only be "$formula".
            $extra = '';
            if (isset($info['field'])) {
              // With a single value, the '=' operator is implicit.
              $operator = !empty($info['operator']) ? $info['operator'] : '=';
              $extra .= "$join_table$info[field] $operator ";
            }
            $extra .= $info['formula'];
            // Add placeholder arguments.
            if (isset($info['formula_arguments']) && is_array($info['formula_arguments'])) {
              $arguments = array_merge($arguments, $info['formula_arguments']);
            }
            $extras[] = $extra;
          }
          // Otherwise - and if we have a value - use it for a field-to-value condition.
          elseif (!empty($info['value'])) {
            // Convert a single-valued array of values to the single-value case,
            // and transform from IN() notation to = notation
            if (is_array($info['value']) && count($info['value']) == 1) {
              if (empty($info['operator'])) {
                $operator = '=';
              }
              else {
                $operator = $info['operator'] == 'NOT IN' ? '!=' : '=';
              }
              $info['value'] = array_shift($info['value']);
              $info['operator'] = $operator;
            }

            if (is_array($info['value'])) {
              // With an array of values, we need multiple placeholders and the
              // 'IN' operator is implicit.
              $local_placeholders = array();
              foreach ($info['value'] as $value) {
                $placeholder_i = ':views_join_condition_' . $select_query->nextPlaceholder();
                $local_placeholders[] = $placeholder_i;
                $arguments[$placeholder_i] = $value;
              }

              $operator = !empty($info['operator']) ? $info['operator'] : 'IN';
              $placeholder = '( ' . implode(', ', $local_placeholders) . ' )';
            }
            else {
              // With a single value, the '=' operator is implicit.
              $operator = !empty($info['operator']) ? $info['operator'] : '=';
              $placeholder = ':views_join_condition_' . $select_query->nextPlaceholder();
              $arguments[$placeholder] = $info['value'];
            }

            $extras[] = "$join_table$info[field] $operator $placeholder";
          }
        }

        if ($extras) {
          if (count($extras) == 1) {
            $condition .= ' AND ' . array_shift($extras);
          }
          else {
            $condition .= ' AND (' . implode(' ' . $this->extra_type . ' ', $extras) . ')';
          }
        }
      }
      elseif ($this->extra && is_string($this->extra)) {
        $condition .= " AND ($this->extra)";
      }
    }

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);
  }
}
 
class dh_date_tools_calendar_views_handler_relationship extends views_handler_relationship {
  /**
   * Currently un-used and un-defined.  This may be used to allow flexible selection of join criteria
   * which currently default to a date joining on single day (>= ts and < ts + 86400)
   */
}
