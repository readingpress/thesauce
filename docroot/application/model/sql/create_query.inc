<?php
/**
 *	The CreateQuery class.
 */

/**
 *	A CREATE query.
 */
class CreateQuery extends DatabaseQuery implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "CREATE $target IF NOT EXISTS $alias (:values)";
	}
	
}