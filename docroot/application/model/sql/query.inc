<?php
/**
 *	@file
 *	The Query class.
 */

/**
 *	The abstract query object.
 */
abstract class Query implements QueryInterface
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

	public function __construct($target, $alias = '')	{

		if (!is_string($target) || !$this->isClean($target)) {
			throw new InvalidArgumentException('Invalid target table or database name.');
		}

		$this->target = $target;
		$this->stringBase = '';
		$this->fields = array();
		$this->values = array();
		$this->conditions = array();
		$this->params = array();
	}

	public function condition($a, $b, $operator)	{

		if (!is_string($a) || !$this->isClean($a)) {
			throw new InvalidArgumentException('Invalid left-hand side.');
		}
		if (!is_string($b)) {
			throw new InvalidArgumentException('Invalid right-hand side.');
		}
		if (!in_array($operator, array('=', '<>', '>', '<', '>=', '<=', 'BETWEEN', 'LIKE', 'IN'))) {
			throw new InvalidArgumentException('Invalid operator.');
		}

		$this->conditions[] = "WHERE $a $operator ?";
		$params[] = $b;
	}

	public function valueMap($values)	{

		if (!is_array($values) || !$this->isClean(array_keys($values))) {
			throw new InvalidArgumentException('Invalid values parameter.');
		}

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
	 *	Checks a string for characters that are not allowed in schema names.
	 *
	 *	@param mixed $schema_name
	 *		The schema name string to check, or an array of schema names to check.
	 *
	 *	@return boolean
	 *		TRUE if the schema name is clean, FALSE if not.
	 */
	private function isClean($schema_name)	{
		// Schema names are not empty, can only contain alphanumeric characters, 
		// underscores and the $ character and cannot be all numbers. There may be a 
		// dot in the string but the dot cannot be the first or last character.
		$bad_patterns = '/^$|^[[:alnum:]_\$\.]$|^[^0-9]+$|^\.|\.$/';
		foreach ((array) $schema_name as $name) {
			if (preg_match($bad_patterns, $schema_name, $placeholders)) {
				return FALSE;
			}
		}
		return TRUE;
	}

}