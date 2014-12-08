<?php
/**
 *	@file
 *	The DropQuery class.
 */

/**
 *	A DROP query.
 */
class DropQuery extends Query {

	public function __construct()	{
		$this->operation = 'DROP %type %name';
	}

}