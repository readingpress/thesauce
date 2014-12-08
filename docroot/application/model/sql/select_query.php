<?php
/**
 *	@file
 *	The SelectQuery class.
 */

/**
 *	A SELECT query.
 *
 *	@param string $target
 *		The table to select.
 *	@param string $alias
 *		An alias to give to $target.
 */
class SelectQuery extends Query {

	/**
	 *	@var array $fields
	 *		An array of fields to select.
	 */
	private $fields;

	public function __construct($target, $alias)	{
		parent::__construct($target);
		$this->stringBase = "SELECT :fields FROM $target AS $alias";
	}

	/**
	 *	Make the query a count query.
	 */
	public function count()	{
		$this->stringBase = preg_replace('/%fields/', 'count(*)', $this->operation);
	}

	/**
	 *	Add fields to the query.
	 *
	 *	@param string $alias
	 *		The alias of the table.
	 *	@param array $fields
	 *		The fields to select.
	 */
	public function fields($alias, $fields = array())	{
		foreach ($fields as $name) {
			$this->fields[] = "$alias.$name";
		}
	}

	/**
	 *	Returns $fields as a query string parameter.
	 *
	 *	@return string
	 *		The columns in a form suitable to be placed in a query.
	 */
	protected function fieldsToString()	{
		return implode(', ', $this->fields);
	}

}