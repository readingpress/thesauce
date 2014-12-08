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
	protected $fields;

	/**
	 *	@var array $joins
	 *		An array of joins to apply to the query.
	 */
	protected $joins;

	/**
	 *	@var array $conditions
	 *		An array of conditions to apply to the query.
	 */
	protected $conditions;

	public function __construct($target, $alias)	{
		parent::__construct($target);
		$this->stringBase = "SELECT :fields FROM $target AS $alias :joins :conditions";
		$this->fields = array();
		$this->joins = array();
		$this->conditions = array();
	}

	/**
	 *	Make the query a count query.
	 */
	public function count()	{
		$this->stringBase = preg_replace('/:fields/', 'count(*)', $this->stringBase);
	}

	/**
	 *	Add fields to the query.
	 *
	 *	@param string $alias
	 *		The alias of the table.
	 *	@param array $fields
	 *		The fields to select.
	 */
	public function fields($alias, $fields = array('*'))	{
		foreach ($fields as $name) {
			$this->fields[] = "$alias.$name";
		}
	}

	/**
	 *	Join on a table.
	 *
	 *	@param string $name
	 *		The name of the table to join on.
	 *	@param string $alias
	 *		An alias for the table.
	 *	@param string $condition
	 *		A condition on which to join.
	 */
	public function join($name, $alias, $condition)	{
		$this->joins[] = "INNER JOIN $name AS $alias ON $condition";
	}

	/**
	 *	Add a condition to the query.
	 *
	 *	@param string $a
	 *		The first value.
	 *	@param string $b
	 *		The second value.
	 *	@param string $operator
	 *		A comparison operator.
	 */
	public function condition($a, $b, $operator)	{
		$this->conditions[] = "WHERE $a $operator '$b'";
	}

}