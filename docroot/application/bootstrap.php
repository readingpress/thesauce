<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/error/error.php';
require_once APP_ROOT . '/application/model/sql/query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';
set_error_handler ('catch_php_errors');
