<?php
/**
 *	@file
 *	The QueryInterface.
 */

/**
 *	Interface for query classes.
 */
interface QueryInterface 
{

	/**
	 *	Constructor for the class. Required because a target must be passed to the
	 *	query.
	 *
	 *	@param string $target
	 *		The name of the item that is the target of the query.
	 *	@param string $alias
	 *		An alias to give to $target.
	 */
	public function __construct($target, $alias = '');

	/**
	 *	Add a condition to the query.
	 *
	 *	@param string $a
	 *		The column name which is the left side of the condition. It should be 
	 *		prefixed with the table alias in the form alias.index.
	 *	@param string $b
	 *		The second value.
	 *	@param string $op
	 *		A comparison operator.
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function condition($a, $b, $op);

	/**
	 *	Add values to to insert or update.
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 *
	 *	@return object
	 *		The up to date instance of the class that called this method.
	 */
	public function values($values);

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
	public function join($name, $alias, $condition, $type = 'INNER');

	/**
	 *	Executes the query against the database.
	 *
	 *	@return object
	 *		A mysqli_result object.
	 */
	public function execute();
	
}