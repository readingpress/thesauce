<?php
/**
 *	@file
 *	The Query class.
 */

/**
 *	The abstract query object.
 */
abstract class Query extends DatabaseConnection implements QueryInterface
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
	 *		An array of fields to target (e.x. SELECT or INSERT INTO).
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

		if (!is_string($target) || empty($target)) {
			throw new InvalidArgumentException('Invalid target table or database name.');
		}

		parent::__construct();
		$this->target = $target;
		$this->stringBase = '';
		$this->fields = array();
		$this->values = array();
		$this->conditions = array();
		$this->params = array();
	}

	public function condition($a, $b, $op)	{

		if (!is_string($a) || empty($a)) {
			throw new InvalidArgumentException('Invalid left-hand side.');
		}
		if (!is_string($b) || empty($b)) {
			throw new InvalidArgumentException('Invalid right-hand side.');
		}
		if (!is_string($op) || empty($op)) {
			throw new InvalidArgumentException('Invalid operator.');
		}

		$this->conditions[] = "WHERE $a $op ?";
		$this->params[] = $b;
		return $this;
	}

	public function values($values)	{

		if (!is_array($values) || empty($values)) {
			throw new InvalidArgumentException('Invalid values parameter.');
		}

		$this->params += $values;
		return $this;
	}

	/**
	 *	Executes the query against the database.
	 *
	 *	@return object
	 *
	 */
	public function execute()	{
		$stmt = $this->prepare($this->getStatement());
		// The first parameter to bind_param are single chacacters indicating var
		// type.
		$params = array(str_repeat('s', count($this->params)));
		// In order to use call_user_func_array, all of our parameters must be 
		// passed as references within the local scope of this function.
		// @see http://php.net/manual/en/mysqli-stmt.bind-param.php
		foreach ($this->params as $key => $value) {
			$params[] = &$value;
		}
		call_user_func_array(array($stmt, 'bind_param'), $params);
		$stmt->execute();
		$result = $stmt->get_result();
		var_dump($result->fetch_array(MYSQLI_ASSOC));
	}

	private function getStatement()	{
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

}