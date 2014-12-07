<?php
/**
 *	@file
 *	Create database query object.
 */

/**
 *	A create database query object.
 */
class CreateDBQuery extends Query {

	public function __construct($db_connection)	{
		parent::__construct($db_connection, "CREATE DATABASE %s");
	}

}