<?php
/**
 *	@file
 *	Handles all incoming http requests that are not for a file in a public 
 *	directory.
 */


/**
 * Root directory of the application.
 */
define('APP_ROOT', getcwd());

require_once APP_ROOT . '/application/bootstrap.php';