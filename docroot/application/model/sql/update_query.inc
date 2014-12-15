<?php
/**
 *	@file
 *	The UpdateQuery class.
 */

/**
 *	An UPDATE query.
 */
class UpdateQuery extends DatabaseQuery implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "UPDATE $target SET :values :joins :conditions";
	}

	public function values($values)	{
		parent::values($values);
		foreach ($values as $key => $value) {
			$this->values[] = "$key = ?";
		}
		return $this;
	}

}