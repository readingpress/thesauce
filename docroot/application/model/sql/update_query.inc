<?php
/**
 *	@file
 *	The UpdateQuery class.
 */

/**
 *	An UPDATE query.
 */
class UpdateQuery extends Query implements QueryInterface 
{

	public function __construct($target, $alias = '')	{
		parent::__construct($target);
		$this->stringBase = "UPDATE $target SET :values :conditions";
	}

	public function valueMap($values)	{
		parent::valueMap($values);
		foreach ($values as $key => $value) {
			$this->values[] = "$key = ?";
		}
	}

}