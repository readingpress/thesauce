<?php
/**
 *	@file
 *	The UseQuery class.
 */

/**
 *	A USE query.
 */
class UseQuery extends Query {

	public function __construct()	{
		$this->operation = 'USE %name';
	}

}