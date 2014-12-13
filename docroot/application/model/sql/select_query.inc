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
	 *	@var array $joins
	 *		An array of joins to apply to the query.
	 */
	protected $joins;

	public function __construct($target, $alias)	{
		TypeValidator::strings('You need to specify an alias for the target table in order to build the query.', $alias);
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
	public function addFields($alias, array $fields = array('*'))	{
		TypeValidator::strings('You need to specify an alias for the target table in order to add fields.', $alias);
		TypeValidator::arrays('You need to to provide an array of fields in order to add fields.', $fields);
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
		TypeValidator::strings('SelectQuery::join() needs all of its parameters to be strings in order to construct the query.', $name, $alias, $condition, $type);
		$this->joins[] = "$type JOIN $name AS $alias ON $condition";
	}

}