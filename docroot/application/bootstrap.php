<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/model/sql/query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';

$a = new InsertQuery('Persons');
$a->values(array(
	'ID' => 11,
	'FirstName' => 'Walter',
	'LastName' => 'White',
	'Address' => 'Albuquerque',
	'City' => 'New Mexico',
));

var_dump($a->toString());