<?php
/**
 *	@file
 *	The SelectQuery class.
 */

/**
 *	A SELECT query.
 */
class SelectQuery extends Query implements QueryInterface 
{

	/**
	 *	@var array $joins
	 *		An array of joins to apply to the query.
	 */
	protected $joins;

	public function __construct($target, $alias = '')	{

		if (!is_string($alias) || empty($alias)) {
			throw new InvalidArgumentException('Invalid alias for query.');
		}

		parent::__construct($target);
		$this->stringBase = "SELECT :fields FROM $target AS $alias :joins :conditions";
		$this->joins = array();
	}

	/**
	 *	Make the select query a count query.
	 */
	public function count()	{
		$this->stringBase = preg_replace('/:fields/', 'count(*)', $this->stringBase);
	}

	/**
	 *	Add fields to the select query.
	 *
	 *	@param string $alias
	 *		The alias of the table.
	 *	@param array $fields
	 *		The fields to select.
	 */
	public function addFields($alias, $fields = array('*'))	{

		if (!is_string($alias) || empty($alias)) {
			throw new InvalidArgumentException('Invalid table alias.');
		}
		if (!is_array($fields) || empty($fields)) {
			throw new InvalidArgumentException('Invalid fields list.');
		}

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
	 *		An string describing the condition on which to join.
	 *	@param string $type
	 *		The type of join (e.x 'INNER', 'LEFT', 'RIGHT', 'FULL'). Default is 
	 *		'INNER'.
	 */
	public function join($name, $alias, $condition, $type = 'INNER')	{

		if (!is_string($name) || empty($name)) {
			throw new InvalidArgumentException('Invalid tablename.');
		}
		if (!is_string($alias) || empty($alias)) {
			throw new InvalidArgumentException('Invalid alias.');
		}
		if (!is_string($condition) || empty($condition)) {
			throw new InvalidArgumentException('Invalid condition.');
		}
		if (!is_string($type) || empty($type)) {
			throw new InvalidArgumentException('Invalid alias.');
		}

		$this->joins[] = "$type JOIN $name AS $alias ON $condition";
	}

}