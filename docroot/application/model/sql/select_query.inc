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

	/**
	 *	@var array $order
	 *		Order conditions to apply to the query. Only an array b/c of convenience
	 *		in logic that constructs the prepared query. There is only ever one.
	 */
	protected $order;

	/**
	 *	@var array $limit
	 *		Limit conditions to apply to the query. Only an array b/c of convenience
	 *		in logic that constructs the prepared query. There is only ever one.
	 */
	protected $limit;

	public function __construct($target, $alias = '')	{

		if (!is_string($alias) || empty($alias)) {
			throw new InvalidArgumentException('Invalid alias for query.');
		}

		parent::__construct($target);
		$this->stringBase = "SELECT :fields FROM $target AS $alias :joins :conditions";
		$this->joins = array();
		$this->order = array();
		$this->limit = array();
	}

	/**
	 *	Make the select query a count query.
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function count()	{
		$this->stringBase = preg_replace('/:fields/', 'count(*)', $this->stringBase);
		return $this;
	}

	/**
	 *	Add fields to the select query.
	 *
	 *	@param string $alias
	 *		The alias of the table.
	 *	@param array $fields
	 *		The fields to select.
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function fields($alias, $fields = array('*'))	{

		if (!is_string($alias) || empty($alias)) {
			throw new InvalidArgumentException('Invalid table alias.');
		}
		if (!is_array($fields) || empty($fields)) {
			throw new InvalidArgumentException('Invalid fields list.');
		}

		foreach ($fields as $name) {
			$this->fields[] = "$alias.$name";
		}
		return $this;
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
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
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
		return $this;
	}

	/**
	 *	Add an order by clause to the query.
	 *
	 *	@param string $name
	 *		A column to order the results on.
	 *	@param string $order
	 *		Whether to order the results ASC or DESC. Default is DESC.
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function order($name, $order = 'DESC')	{
		$this->order = array("ORDER BY $name $order");
		return $this;
	}


	/**
	 *	Add a limit clause to the query.
	 *
	 *	@param string $limit
	 *		The limit to apply (e.x LIMIT $limit).
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function limit($limit)	{
		$this->limit = array("LIMIT $limit");
		return $this;
	}

}