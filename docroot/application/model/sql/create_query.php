<?php
/**
 *	@file
 *	The CreateQuery class.
 */

/**
 *	A CREATE query.
 */
class CreateQuery extends Query {

	/**
	 *	@var array $columns
	 *		An array of column data. Each of the items in this array takes the form
	 *		'column_name' => 'column_type'.
	 */
	protected $columns;

	public function __construct($type, $name)	{
		parent::__construct($type, $name);
		$this->operation = 'CREATE %type %name %columns';
		$this->columns = array();
	}

	/**
	 *	Returns columns as a string, in a form suitable to be placed in a query.
	 *
	 *	@return string
	 *		The columns in a form suitable to be placed in a query.
	 */
	protected function columnsToQueryString()	{
		if (empty($this->columns)) {
			return NULL;
		}
		$cols = array();
		foreach ($this->columns as $key => $value) {
			$cols[] = $key . ' ' . $value;
		}
		return '(' . implode(', ', $cols) . ')';
	}

}