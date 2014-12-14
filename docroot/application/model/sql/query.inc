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
abstract class Query 
{

	/**
	 *	@var string $target
	 *		The name of the table or database on which the operation is being 
	 *		performed.
	 */
	protected $target;

	/**
	 *	@var string $stringBase.
	 *		The beginning of the query string, with named placeholders for the
	 *		dynamic values.
	 */
	protected $stringBase;

	/**
	 *	@var array $fields
	 *		An array of fields to affect (e.x. SELECT or INSERT INTO).
	 */
	protected $fields;

	/**
	 *	@param array $values
	 *		An array of key => value pairs to insert or update.
	 */
	protected $values;

	/**
	 *	@var array $conditions
	 *		An array of conditions to apply to the query.
	 */
	protected $conditions;

	/**
	 *	@var array $params
	 *		The parameters to pass to the query using mysqli_stmt::bind_param().
	 */
	protected $params;

	public function __construct($target)	{

		if (!is_string($target) || empty($target) ||  !$this->isClean($target)) {
			throw new InvalidArgumentException('Invalid target table or database name.');
		}

		$this->target = $target;
		$this->stringBase = '';
		$this->fields = array();
		$this->values = array();
		$this->conditions = array();
		$this->params = array();
	}


	/**
	 *	Add a condition to the query.
	 *
	 *	@param string $a
	 *		The column name whose value should be checked.
	 *	@param string $b
	 *		The second value.
	 *	@param string $operator
	 *		A comparison operator.
	 */
	public function condition($a, $b, $operator)	{
		$this->conditions[] = "WHERE $a $operator ?";
		$params[] = $b;
	}

	/**
	 *	Add values to to insert or update.
	 *
	 *	@param array $values;
	 *		An array of key => value pairs to insert.
	 */
	public function valueMap(array $values)	{
		$this->params += $values;
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
		// @see http://php.net/manual/en/function.preg-match-all.php
		foreach (end($placeholders) as $ph) {
			$str = preg_replace("/:$ph/", implode(', ', $this->{$ph}), $str);
		}
		return $str;
	}

	/**
	 *	Checks a string for characters that are not allodwe in schema names.
	 *
	 *	@param string $schema_name
	 *		The schema name string to check.
	 *
	 *	@return boolean
	 *		TRUE if the schema name is clean, FALSE if not.
	 */
	private function isClean($schema_name)	{
		// Schema names can only contain alphanumeric characters, underscores and 
		// the $ character.
		$regex = '/^[[:alnum:]_\$]+$/';
		return preg_match($regex, $schema_name, $placeholders);
	}

}