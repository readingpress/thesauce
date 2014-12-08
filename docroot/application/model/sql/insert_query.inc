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

	/**
	 *	@param array $keys
	 *		An array of fields to insert into.
	 */
	protected $keys;

	public function __construct($target)	{
		parent::__construct($target);
		$this->stringBase = "INSERT INTO $target (:keys) VALUES (:values)";
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
		$this->keys = array_keys($values);
	}

}