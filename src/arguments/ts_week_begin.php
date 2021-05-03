// // take supplied date and find the first day of the week
$ts = strtotime($argument);
$day = date('w', $ts);
$tsdate = new DateTime;
$tsdate->setTimestamp($ts);
$week_start = date('m-d', $ts - $day * 86400);
$handler->argument = $week_start;
return TRUE;