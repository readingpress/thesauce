<?php
/**
 *	@file
 *	Handles all incoming http requests that are not for a file in a public 
 *	directory or a public directory itself..
 */

try {
	// Turn on errors.
	// @TODO Remove before launching.
	ini_set('display_errors',1);  
	error_reporting(E_ALL);

	/**
	 * Root directory of the application.
	 */
	define('APP_ROOT', getcwd());

	// Let's make the magic happen.
	require_once APP_ROOT . '/application/bootstrap.php';
}
catch(Exception $e)	{
	print 'Whoops! ' . $e->getMessage();
}