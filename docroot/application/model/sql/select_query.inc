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
		parent::__construct($target);
		$this->stringBase = "SELECT :fields FROM $target AS $alias :joins :conditions";
		$this->joins = array();
	}

	/**
	 *	Make the query a count query.
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

		if (!is_string($alias)) {
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
		$this->joins[] = "$type JOIN $name AS $alias ON $condition";
	}

}