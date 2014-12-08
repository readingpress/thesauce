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
	 *	@var string $queryStringBase.
	 *		The beginning of the query string, with named placeholders for the
	 *		dynamic values.
	 */
	protected $stringBase;

	/**
	 *	@var string $queryTarget
	 *		The name of the table or database on which the operation is being 
	 *		performed.
	 */
	protected $target;

	public function __construct($target)	{
		$this->target = $target;
	}

	/**
	 *	Build the query string.
	 */
	public function queryString()	{
		$str = $this->stringBase;
		// Placeholders are always a string of alphanumeric characters and 
		// underscores that ends in a space and begins with a colon (e.x. ':type').
		$regex = '/:([[:alnum:]_]+)/';
		preg_match_all($regex, $str, $placeholders);
		// We call end() on $placeholders because this gives us the part of our
		// regex that is in the parenthesis, i.e. without the leading colon.
		foreach (end($placeholders) as $ph) {
			$str = preg_replace("/:$ph/", implode(', ', $this->{$ph}),$str);
		}
		return $str;
	}

}