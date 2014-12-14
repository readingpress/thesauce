<?php
/**
 *	@file
 *	The DeleteQuery class.
 */

/**
 *	A DELETE query.
 */
class DeleteQuery extends Query implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "DELETE FROM $target :conditions";
	}

}