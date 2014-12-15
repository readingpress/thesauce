<?php
/**
 *	@file
 *	The QueryFactory class.
 */

class QueryFactory 
{

	/**
	 *	Create a CREATE query.
	 *
	 *	@param string $target
	 *		What to create. Either TABLE or DATABASE;
	 *	@param string $alias
	 *		The name to give to what is being created (i.e the name of the table or 
	 *		database).
	 *
	 *	@return object
	 *		A CreateQuery object.
	 */
	public static function createQuery($target, $alias)	{
		return new CreateQuery($target, $alias);
	}

	/**
	 *	Create a DROP query.
	 *
	 *	@param string $target
	 *		What to drop. Either TABLE or DATABASE;
	 *
	 *	@return object
	 *		A CreateQuery object.
	 */
	public static function dropQuery($target)	{
		return new DropQuery($target);
	}

	/**
	 *	Create an INSERT query.
	 *
	 *	@param string $target
	 *		The tablename to insert into.
	 *
	 *	@return object
	 *		An InsertQuery object.
	 */
	public static function insertQuery($target)	{
		return new InsertQuery($target);
	}

	/**
	 *	Create a SELECT query.
	 *
	 *	@param string $target
	 *		The tablename to start the select query from.
	 *	@param string $alias
	 *		An alias for the target table.
	 *
	 *	@return object
	 *		A SelectQuery object.
	 */
	public static function selectQuery($target, $alias)	{
		return new SelectQuery($target, $alias);
	}

	/**
	 *	Create an UPDATE query.
	 *
	 *	@param string $target
	 *		The tablename to update.
	 *
	 *	@return object
	 *		An UpdateQuery object.
	 */
	public static function updateQuery($target)	{
		return new UpdateQuery($target);
	}

	/**
	 *	Create a DELETE query.
	 *
	 *	@param string $target
	 *		The tablename to delete from.
	 *
	 *	@return object
	 *		A DeleteQuery object.
	 */
	public static function deleteQuery($target)	{
		return new DeleteQuery($target);
	}

}