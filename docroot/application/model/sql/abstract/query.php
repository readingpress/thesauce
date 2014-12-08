<?php
/**
 *	@file
 *	The Query class.
 */

/**
 *	The abstract query object.
 */
abstract class Query {

	/**
	 *	@var string $operation.
	 *		The operation to be performed. This amounts to the beginning of the
	 *		final query and may named placeholders.
	 */
	protected $operation;

	/**
	 *	@var string $type
	 *		What to operate on. This doesn't apply to all queries. Examples include 
	 *		DATABASE or TABLE.
	 */
	protected $type;

	/**
	 *	@var string $name
	 *		A generic name for what is being created, dumped, inserted, selected, 
	 *		updated, or deleted.
	 */
	protected $name;

	/**
	 *	Build the query by calling all defined replacement methods.
	 */
	public function buildQuery()	{
		$query = $this->operation;
		preg_match_all('/%([[:alnum:]_]+)/', $query, $replacements, PREG_SET_ORDER);
		foreach ($replacements as $replace) {
			$replacement = method_exists($this, "$replace[1]ToQueryString") ? $this->{"$replace[1]ToQueryString"}() : $this->{$replace[1]};
			$query = preg_replace("/$replace[0]/", $replacement, $query);
		}
		return $query;
	}

}