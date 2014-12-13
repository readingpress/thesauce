<?php
/**
 *	@file
 *	Custom error handler for PHP exceptions.
 */

/**
 *	Bypasses core php errors, instead throwing them as exceptions that can be 
 *	caught.
 *		
 *	@param integer $errno
 *		The first parameter, errno, contains the level of the error raised, as an 
 *		integer.
 *	@param string $errstr
 *		The second parameter, errstr, contains the error message, as a string.
 *	@param string $errfile
 *		The third parameter is optional, errfile, which contains the filename that 
 *		the error was raised in, as a string.
 *	@param integer $errline
 *		The fourth parameter is optional, errline, which contains the line number 
 *		the error was raised at, as an integer.
 *	@param array $errcontext
 *		The fifth parameter is optional, errcontext, which is an array that points 
 *		to the active symbol table at the point the error occurred. In other 
 *		words, errcontext will contain an array of every variable that existed in 
 *		the scope the error was triggered in. User error handler must not modify 
 *		error context.
 *
 *	@return boolean
 *		If the function returns FALSE then the normal error handler continues.
 */
function catch_php_errors($errno, $errstr, $errfile, $errline, array $errcontext = array())	{
	throw new Exception($errstr);
	return TRUE;
}