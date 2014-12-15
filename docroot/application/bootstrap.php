<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/model/sql/database_connection.inc';
require_once APP_ROOT . '/application/model/sql/query_interface.inc';
require_once APP_ROOT . '/application/model/sql/query.inc';
require_once APP_ROOT . '/application/model/sql/create_query.inc';
require_once APP_ROOT . '/application/model/sql/drop_query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';
require_once APP_ROOT . '/application/model/sql/query_factory.inc';

// @TODO
//  Add alias regex input validation to params which require an alias prefix.
//  Fix condition which breaks with more than one condition. Allow both AND and OR.
//  Devise a way to include CREATE/DROP DATABASE and CREATE/DROP TABLE.

$a = QueryFactory::createQuery('select', 'Persons', 'p')
			->fields('p')
			->condition('p.LastName', 'Curlin', '=')
			->execute();