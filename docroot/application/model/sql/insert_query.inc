<?php
/**
 *	@file
 *	The InsertQuery class.
 */

/**
 *	An INSERT query.
 *
 *	@param string $target
 *		The table to select.
 */
class InsertQuery extends Query {

	public function __construct($target)	{
		parent::__construct($target);
		$this->stringBase = "INSERT INTO $target (:fields) VALUES (:values)";
	}

	/**
	 *	Add values to to insert.
	 *	@override Query::values().
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 */
	public function values($values)	{
		parent::values($values);
		$this->fields = array_keys($values);
		// We need to build an array of placeholder question marks matching in 
		// length with our column names ($keys). That way we can replace them later
		// with mysqli_stmt::bind_param().
		$this->values = array_fill(0, count($this->keys), '?');
	}

}