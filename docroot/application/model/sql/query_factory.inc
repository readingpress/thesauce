<?php
/**
 *	@file
 *	The QueryFactory class.
 */

class QueryFactory 
{

	/**
	 *	Create a query.
	 *
	 *	@param string $type
	 *		The type of query to instantiate. Possible values include 'create', 
	 *		'retrieve', 'update' and 'delete').
	 *	@param string $target
	 *		The target table name or database name of the query.
	 *	@param string $alias
	 *		An alias for the table if this is a select query. Defaults to a empty 
	 *		string.
	 *
	 *	@return object
	 *		An instantiated query object for the requested operation.
	 */
	public static function createQuery($type, $target, $alias = '')	{
		switch ($type) {
			case 'create':
				return new InsertQuery($target, $alias);
				break;
			case 'retrieve':
				return new SelectQuery($target, $alias);
				break;
			case 'update':
				return new UpdateQuery($target, $alias);
				break;
			case 'delete':
				return new DeleteQuery($target, $alias);
				break;
		}
	}
}