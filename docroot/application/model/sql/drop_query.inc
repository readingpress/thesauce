<?php
/**
 *	@file
 *	The DropQuery class.
 */

/**
 *	A DROP query.
 */
class DropQuery extends DatabaseQuery implements QueryInterface
{
	
	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "DROP $target IF EXISTS :values";
	}

}