<?php

unset($qfields['keywords']);

if (isset($_POST['keywords'])) {
	foreach ($_POST['keywords'] as $keyword) {
		$keywordq = "SELECT topicid FROM `" . OCC_TABLE_TOPIC . "` where `topicname` = '" . safeSQLstr($keyword) . "'";

		$res = ocsql_query($keywordq) or err('unable to retrieve topic');
		if (ocsql_num_rows($res) < 1) {
			// NOTE: I had to manually make the topicid auto_increment!
			ocsql_query("INSERT INTO `" . OCC_TABLE_TOPIC . "` SET `topicname` = '" . safeSQLstr($keyword) . "'");
			$tid = ocsql_insert_id() or err(oc_('unable to get submission ID'));
		} else {
			$topl = ocsql_fetch_assoc($res);
			$tid = $topl['topicid'];
		}
		$tfields[] = $tid;
	}
}
