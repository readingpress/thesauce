<?php
/**
 *	@file
 *	The SelectQuery class.
 */

/**
 *	A SELECT query.
 */
class SelectQuery extends Query {

	/**
	 *	@var array $fields
	 *		An array field arrays keyed by table alias.
	 */
	public $fields;

	/**
	 *	@var string $alias
	 *		A string to use as table alias.
	 */
	public $alias;

	public function __construct()	{
		$this->operation = 'SELECT %fields FROM %name AS %alias';
	}

	/**
	 *	Returns columns as a string, in a form suitable to be placed in a query.
	 *
	 *	@return string
	 *		The columns in a form suitable to be placed in a query.
	 */
	protected function fieldsToQueryString()	{
		$fieldlist = array();
		foreach ($this->fields as $key => $value) {
			$fieldlist += $this->applyTablePrefix($key, $value);	
		}
		return implode(', ', $fieldlist);
	}

	/**
	 *	Helper function to add table prefixes to a field array. This function
	 *	returns the modified array.
	 *
	 *	@param string $prefix
	 *		The prefix to apply.
	 *	@param array $fieldnames
	 *		An array of fieldnames.
	 */
	private function applyTablePrefix($prefix, $fieldnames)	{
		foreach ($fieldnames as $key => &$value) {
			$value = "$prefix.$value";
		}
		return $fieldnames;
	}

}