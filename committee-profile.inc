<?php

// filter only subfields to be in subfield box:
$topicAR = array_intersect($topicAR,
	array('syntax','semantics','phonology','sociolinguistics','historical','morphology','psycholinguistics','phonetics'));

// var_dump($OC_reviewerFieldAR['topics']);
$OC_reviewerFieldAR['topics']['display'] = 'sameline';

$OC_reviewerFieldSetAR['fs_topics']['note'] = 'To help match submissions to reviewers, please select your subfields and topics of expertise.';

$OC_reviewerFieldAR['keywords'] = array(
	'name' => oc_('Keywords'),
	'short' => oc_('Keywords'),
	'note' => 'Keywords can be as specific as, for example, "reduplication," "relative clauses," and "Malagasy." Keywords which are not included in the dropdown can also be added.',
	'type' => 'select',
	'usekey' => true,
// 	'values' => array(),
	'closeedit' => false,
	'required' => false,
	'multiple' => true
);
$OC_reviewerFieldSetAR['fs_topics']['fields'][] = 'keywords';

// rename Topic Areas box to be Abstract:
$OC_reviewerFieldSetAR['fs_topics']['fieldset'] = 'Subfield and keywords';

$OC_reviewerFieldAR['topics']['name'] = 'Subfield';

// var_dump($OC_reviewerFieldAR);
// var_dump($OC_reviewerFieldSetAR);

?>

<script src="https://code.jquery.com/jquery-1.11.1.min.js"></script>
<script src="<?php echo $GLOBALS['pfx']; ?>modules/lingconf_dynamictopics/selectize/selectize-standalone.js"></script>
<link rel="stylesheet" type="text/css" href="<?php echo $GLOBALS['pfx']; ?>modules/lingconf_dynamictopics/selectize/selectize.css" />
<style>
.selectize-input { display: block !important; }
</style>
<script>
<?php
	$topicq = "SELECT topicid, topicname FROM `" . OCC_TABLE_TOPIC . "` where topicid > 8 order by topicname asc";

	$res = ocsql_query($topicq) or err('unable to retrieve topics');
	$topics = array();
	while ($topic = ocsql_fetch_assoc($res)) {
		$topics[] = '{id: ' . $topic['topicid'] . ', title: "' . htmlspecialchars($topic['topicname']) . '"}';
	}
	echo 'var topics = [';
	echo implode(',', $topics);
	echo '];';
?>

jQuery(function ($) {
	$('#keywords')
		.prop('multiple', true)
		.css('width', '350px')
		.selectize(	{maxItems: null,
			valueField: 'title',
			labelField: 'title',
			searchField: 'title',
			options: topics,
			create: true});
		});
</script>
