<?php
/**
 *	@file
 *	Exception class to handle variable type validation.
 */

/**
 *	Class to handle type validation of variables.
 */
class typeException extends Exception 
{
    // Redefine the exception so message isn't optional
    public function __construct($message, $code = 0, Exception $previous = null) {
        // some code
    
        // make sure everything is assigned properly
        parent::__construct($message, $code, $previous);
    }
}