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
	 *	Get the query statement.
	 *
	 *	@return string
	 *		The query string.
	 */
	public function getStatement();

	/**
	 *	Gets the values for the placeholders in the statement.
	 *
	 *	@return array
	 *		An array of values for the placeholders in the statement.
	 */
	public function getParams();
	
}