<?php
/**
 *	@file
 *	Core query object.
 */

/**
 *	Core query object. Exists to be extended.
 */
abstract class Query {

	/**
	 *	Constructor.
	 *
	 *	@param mysqli $db_connection
	 *		A php mysqli object.
	 */
	protected function __construct(mysqli $db_connection)	{
		$this->db_connection = $db_connection;
		$this->construct = $construct;
	}

	/**
	 *	@var object $dbConnection
	 *		A mysqli database connection object.
	 */
	private $db_connection;


	/**
	 *	@var string $construct
	 *		A basic query containing placeholders for values, before any 
	 *		substitution has been done to it.
	 */
	protected $construct;

}