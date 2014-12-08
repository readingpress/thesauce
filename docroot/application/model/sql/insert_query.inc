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
 *	@param string $alias
 *		An alias to give to $target.
 */
class InsertQuery extends Query {

	public function __construct($target)	{
		parent::__construct($target);
		$this->stringBase = "INSERT INTO $target (:keys) VALUES (:values)";
	}

}