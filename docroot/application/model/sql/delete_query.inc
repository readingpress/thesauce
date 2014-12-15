<?php
/**
 *	@file
 *	The DeleteQuery class.
 */

/**
 *	A DELETE query.
 */
class DeleteQuery extends DatabaseQuery implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "DELETE FROM $target :joins :conditions";
	}

}