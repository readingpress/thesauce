<?php
/**
 *	@file
 *	Boot the application.
 */

// Load dependencies.
require_once APP_ROOT . '/application/model/type/type_validator.inc';
require_once APP_ROOT . '/application/model/sql/query.inc';
require_once APP_ROOT . '/application/model/sql/insert_query.inc';
require_once APP_ROOT . '/application/model/sql/select_query.inc';
require_once APP_ROOT . '/application/model/sql/update_query.inc';
require_once APP_ROOT . '/application/model/sql/delete_query.inc';

TypeValidator::strings('POW', 'sista', 'brothas');