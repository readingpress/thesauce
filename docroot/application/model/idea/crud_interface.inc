<?php
/**
 *	@file
 *	The CrudInterface.
 */

interface CrudInterface 
{

	/**
	 *	Create.
	 */
	public function create();

	/**
	 *	Retrieve.
	 */
	public function retrieve();

	/**
	 *	Update.
	 */
	public function update();

	/**
	 *	Delete.
	 */
	public function delete();

}