<?php
/**
 *	@file
 *	Handles all incoming http requests that are not for a file in a public 
 *	directory or a public directory itself..
 */

/**
 * Root directory of the application.
 */
define('APP_ROOT', getcwd());
// Let's make the magic happen.
require_once APP_ROOT . '/application/bootstrap.php';