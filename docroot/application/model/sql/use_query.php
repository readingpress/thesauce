<?php
/**
 *	@file
 *	The UseQuery class.
 */

/**
 *	A USE query.
 */
class UseQuery extends Query {

	public function __construct($name)	{
		parent::__construct(NULL, $name);
		$this->operation = 'USE %name';
	}

}