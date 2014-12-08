<?php
/**
 *	@file
 *	The SelectQuery class.
 */

/**
 *	A SELECT query.
 *
 *	@param string $name
 *		The name of the table to start the select statement with.
 *	@param string $alias
 *		A string alias to reference the table given in the first parameter.
 */
class SelectQuery extends Query {

	/**
	 *	@var array $fields
	 *		An array field arrays keyed by table alias.
	 */
	protected $fields;

	/**
	 *	@var string $alias
	 *		A string to use as table alias.
	 */
	protected $alias;

	public function __construct($name, $alias)	{
		parent::__construct(NULL, $name);
		$this->operation = 'SELECT %fields FROM %name AS %alias';
		$this->alias = $alias;
	}

	/**
	 *	Make this query a count query.
	 */
	public function count()	{
		$this->operation = preg_replace('/%fields/', 'count(*)', $this->operation);
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