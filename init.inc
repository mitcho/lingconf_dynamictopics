<?php

if (!isset($GLOBALS['OC_hooksAR']['author-submission-inc']))
	$GLOBALS['OC_hooksAR']['author-submission-inc'] = array();
$GLOBALS['OC_hooksAR']['author-submission-inc'][] = dirname(__FILE__) . '/submission.inc';

if (!isset($GLOBALS['OC_hooksAR']['author-submission-validate']))
	$GLOBALS['OC_hooksAR']['author-submission-validate'] = array();
$GLOBALS['OC_hooksAR']['author-submission-validate'][] = dirname(__FILE__) . '/submission-validate.inc';


if (!isset($GLOBALS['OC_hooksAR']['committee-profile-inc']))
	$GLOBALS['OC_hooksAR']['committee-profile-inc'] = array();
$GLOBALS['OC_hooksAR']['committee-profile-inc'][] = dirname(__FILE__) . '/committee-profile.inc';

if (!isset($GLOBALS['OC_hooksAR']['committee-profile-validate']))
	$GLOBALS['OC_hooksAR']['committee-profile-validate'] = array();
$GLOBALS['OC_hooksAR']['committee-profile-validate'][] = dirname(__FILE__) . '/committee-validate.inc';
