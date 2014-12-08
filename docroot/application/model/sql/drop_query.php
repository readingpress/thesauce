<?php
/**
 *	@file
 *	The DropQuery class.
 */

/**
 *	A DROP query.
 */
class DropQuery extends Query {

	public function __construct($type, $name)	{
		parent::__construct($type, $name);
		$this->operation = 'DROP %type %name';
	}

}