<?php
/**
 *	@file
 *	Contains the TypeValidator class.
 */

/**
 *	The type validator. Used to check function input and throw exceptions if the
 *	rules of the code are not being followed.
 */
class TypeValidator
{

	/**
	 *	Verify that all the parameters passed to this are a string. We use 
	 *	func_get_args() to get all the variables after $message. An exception is
	 *	thrown if the criteria is not met.
	 *
	 *	@param string $message
	 *		A custom message to pass to the exception to help the user find out what
	 *		is wrong with their input.
	 */
	static function strings($message = '')	{
		if (gettype($message) !== 'string') {
			throw new Exception('TypeValidator method strings expects parameter 1 to be a string');
		}

		$args = func_get_args();
		foreach ($args as $param) {
			if (gettype($param) !== 'string') {
				throw new Exception($message);
			}
		}
	}

	/**
	 *	Verify that all the parameters passed to this are a string. We use 
	 *	func_get_args() to get all the variables after $message. An exception is
	 *	thrown if the criteria is not met.
	 *
	 *	@param string $message
	 *		A custom message to pass to the exception to help the user find out what
	 *		is wrong with their input.
	 */
	static function arrays($message = '')	{
		if (gettype($message) !== 'string') {
			throw new Exception('TypeValidator method strings expects parameter 1 to be a string');
		}

		$args = func_get_args();
		array_slice($args);
		foreach ($args as $param) {
			if (gettype($param) !== 'array') {
				throw new Exception($message);
			}
		}
	}

}