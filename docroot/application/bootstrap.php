<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
//
// SQL model
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
// Idea model
require_once APP_ROOT . '/application/model/idea/crud_interface.inc';

// @TODO Server
//	1) Fix server config to use sed on www.conf and php.ini rather than overwriting the files
//	for forward compatibility with updates.
// 
// @TODO SQL Model
//  1) Add alias regex input validation to params which require an alias prefix.
//  2) Fix condition which breaks with more than one condition. Allow both AND and OR.
//  3) Check to see if LIMIT and ORDER BY should be using placeholders.
//  3) Look into Alias mess and see if there is a better way then including it in the
//  interface constructor only so select queries can use it.
//	4) Namespace and code polish entire SQL model according to best practices.
//  5) Review afresh whether we are missing any validation functions or have
//  unneccesary ones.
//  6) Change filenames, classnames, and/or var names in accordance with best practices.
//	7) Full code review, comment cleanup etc.
//  8) Q/A all factory methods.
//	9) Look into the difficulty and complexity introduced by including some of the
//	the missing SQL methods and/or comparisons
