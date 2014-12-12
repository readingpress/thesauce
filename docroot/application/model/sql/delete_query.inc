<?php
/**
 *	@file
 *	The DeleteQuery class.
 */

/**
 *	An Update query.
 *
 *	@param string $target
 *		The table to select.
 */
class DeleteQuery extends Query {

	public function __construct($target)	{
		parent::__construct($target);
		$this->stringBase = "DELETE FROM $target :conditions";
		$this->prepare("DELETE FROM $target :conditions");
	}

}