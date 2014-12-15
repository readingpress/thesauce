<?php
/**
 *	@file
 *	The InsertQuery class.
 */

/**
 *	An INSERT query.
 */
class InsertQuery extends DatabaseQuery implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "INSERT INTO $target (:fields) VALUES (:values)";
	}

	public function values($values)	{
		parent::values($values);
		$this->fields = array_keys($values);
		// We need to build an array of placeholder question marks matching in 
		// length with our column names ($keys). That way we can replace them later
		// with mysqli_stmt::bind_param().
		$this->values = array_fill(0, count($this->fields), '?');
		return $this;
	}

}