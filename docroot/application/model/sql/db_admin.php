<?php
/**
 *	@file
 *	The DBAdmin class.
 */

/**
 *	Admin query object. Can be used to create and drop tables or databases, set 
 *	active database etc.
 *
 *	@param string $target
 *		The table or database to act on.
 *	@param string $op
 *		The command to run (e.x. 'CREATE DATABASE', 'DROP TABLE').
 */
class DBAdmin extends Query {

	/**
	 *	@var array $columns
	 *		An array of column data. Each of the items in this array takes the form
	 *		'column_name' => 'column_type'.
	 */
	protected $columns;

	public function __construct($target, $op)	{
		parent::__construct($target);
		$this->stringBase = "$op $target :columns";
	}

	/**
	 *	Returns columns as a string, in a form suitable to be placed in a query.
	 *
	 *	@return string
	 *		The columns in a form suitable to be placed in a query.
	 */
	protected function columnsToString()	{
		$cols = array();
		foreach ($this->columns as $key => $value) {
			$cols[] = $key . ' ' . $value;
		}
		return '(' . implode(', ', $cols) . ')';
	}
		
}