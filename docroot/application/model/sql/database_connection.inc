<?php
/**
 *	@file	
 *	The DatabaseConnection class.
 */

abstract class DatabaseConnection extends mysqli
{

	public function __construct()	{
		// @TODO move this into it's own config files.
		$host = '127.0.0.1';
		$user = 'root';
		$password = '';
		$db = 'thesauce';
		
		parent::__construct($host, $user, $password, $db);
		if ($this->connect_error) {
			throw new Exception('SQL connection failed.');
		}
	}

}