<?php
/**
 *	@file
 *	The Query class.
 */

/**
 *	The abstract query object.
 *
 *	@param string $target
 *		The name of the item that is the target of the query.
 */
abstract class Query {

	/**
	 *	@var string $stringBase.
	 *		The beginning of the query string, with named placeholders for the
	 *		dynamic values.
	 */
	protected $stringBase = NULL;

	/**
	 *	@var string $target
	 *		The name of the table or database on which the operation is being 
	 *		performed.
	 */
	protected $target = NULL;

	/**
	 *	@var array $conditions
	 *		An array of conditions to apply to the query.
	 */
	protected $conditions = array();

	/**
	 *	@param array $values
	 *		An array of key => value pairs to insert or update.
	 */
	protected $values = array();

	public function __construct($target)	{
		$this->target = $target;
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

	/**
	 *	Add values to to insert or update.
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 */
	public function values($values)	{
		foreach ($values as $key => $value) {
			$this->values[$key] = "'$value'";
		}
	}

	/**
	 *	Return the query as a string.
	 *
	 *	@return string
	 *		The query string.
	 */
	public function toString()	{
		$str = $this->stringBase;
		// Placeholders are always a string of alphanumeric characters and 
		// underscores that ends in a space and begins with a colon (e.x. ':type').
		$regex = '/:([[:alnum:]_]+)/';
		preg_match_all($regex, $str, $placeholders);
		// We call end() on $placeholders because this gives us the part of our
		// regex that is in the parenthesis, i.e. without the leading colon.
		foreach (end($placeholders) as $ph) {
			$str = preg_replace("/:$ph/", implode(', ', $this->{$ph}), $str);
		}
		return $str;
	}

}