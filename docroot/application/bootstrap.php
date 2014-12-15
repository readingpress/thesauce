<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/model/sql/database_connection.inc';
require_once APP_ROOT . '/application/model/sql/query_interface.inc';
require_once APP_ROOT . '/application/model/sql/database_query.inc';
require_once APP_ROOT . '/application/model/sql/create_query.inc';
require_once APP_ROOT . '/application/model/sql/drop_query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';
require_once APP_ROOT . '/application/model/sql/query_factory.inc';

// @TODO SQL Model
//  Add alias regex input validation to params which require an alias prefix.
//  Fix condition which breaks with more than one condition. Allow both AND and OR.
//  Check to see if LIMIT and ORDER BY should be using palceholders.
//  Look into Alias mess and see if there is a better way then including it in the
//  interface constructor only so select queries can use it.
//	Namespace and code polish entire SQL model according to best practices.
//  Review afresh whether we are missing any validation functions or have
//  unneccesary ones.
//  Change filenames, classnames, and/or var names in accordance with best practices.
//	Full code review, comment cleanup etc.
//  Q/A all factory methods.
//
// @TODO Other
//	Fix server config to use sed on www.conf and php.ini rather than overwriting the files
//	for forward compatibility with updates.