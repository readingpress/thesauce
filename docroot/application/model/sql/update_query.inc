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
		$this->stringBase = "UPDATE $target SET :values :conditions";
	}

	/**
	 *	Add values to to insert.
	 *	@override Query::values().
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 */
	public function values($values)	{
		foreach ($values as $key => $value) {
			$this->values[] = "$key = $value";
		}
	}

}