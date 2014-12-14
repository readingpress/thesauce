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
	 *		prefixed with the table alias in the form th.index.
	 *	@param string $b
	 *		The second value.
	 *	@param string $operator
	 *		A comparison operator.
	 */
	public function condition($a, $b, $operator);

	/**
	 *	Add values to to insert or update.
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 */
	public function valueMap($values);
}