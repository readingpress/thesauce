<?php
/**
 *	@file
 *	The UpdateQuery class.
 */

/**
 *	An Update query.
 *
 *	@param string $target
 *		The table to select.
 */
class UpdateQuery extends Query {

	public function __construct($target)	{
		parent::__construct($target);
		$this->stringBase = "UPDATE $target SET :values :condition";
	}

}