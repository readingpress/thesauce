<?php
/**
 *	@file
 *	The CreateQuery class.
 */

/**
 *	An admin query. Can be used to create and drop tables or databases, set 
 *	database etc.
 *
 *	@param string $target
 *		The name of the table or database to operate on.
 *	@param string $op
 *		The command to run on the target (e.x. 'CREATE DATABASE', 'DROP TABLE').
 */
class AdminQuery extends Query {

	/**
	 *	@var array $columns
	 *		An array of column data. Each of the items in this array takes the form
	 *		'column_name' => 'column_type'.
	 */
	protected $columns;

	public function __construct($target, $op)	{
		parent::__construct($target);
		$this->stringBase = "$op $target :columns";
		$this->columns = array();
	}

	/**
	 *	Returns columns as a string, in a form suitable to be placed in a query.
	 *
	 *	@return string
	 *		The columns in a form suitable to be placed in a query.
	 */
	protected function columnsToQueryString()	{
		$cols = array();
		foreach ($this->columns as $key => $value) {
			$cols[] = $key . ' ' . $value;
		}
		return '(' . implode(', ', $cols) . ')';
	}
		
}