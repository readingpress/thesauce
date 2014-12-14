<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/model/sql/query_interface.inc';
require_once APP_ROOT . '/application/model/sql/query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';
require_once APP_ROOT . '/application/model/sql/query_factory.inc';

$a = QueryFactory::createQuery('select', 'Persons', 'p')
			->condition('p.LastName', 'DeWolf', '=')
			->fields('p', array('FirstName', 'LastName'));
var_dump($a->getStatement());
var_dump($a->getParams());