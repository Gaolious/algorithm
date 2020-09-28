<?php

define( 'MAX_DEPTH', 10 );

$sum_array = array ();

class btree
{
	public $num = 0 ;
	public $left = null;
	public $right = null ;
	public $curr_depth;

	function __construct ( $curr)
	{
		$this->curr_depth = $curr ;
		$this->num = rand(-1000,1000) ;

		if ( $this->curr_depth < MAX_DEPTH )
		{
			if ( rand(0,3) ) $this->create_left();
			if ( rand(0,3) ) $this->create_right();
		}
	}
	public function create_left()
	{
		$this->left = new btree( $this->curr_depth + 1 );
	}
	public function create_right()
	{
		$this->right = new btree( $this->curr_depth + 1 );
	}
	public function sum( $cumulative = 0)
	{
		global $sum_array ;

		if ( $this->left == null && $this->right == null )
		{
			$sum_array[] = $this->num + $cumulative ;
		}
		else
		{
			if ( $this->left != null ) $this->left->sum( $cumulative + $this->num);
			if ( $this->right != null ) $this->right->sum( $cumulative + $this->num );
		}
	}

	public function print_node()
	{
		echo "( {$this->num} ";

		if ( $this->left == null ) 
			echo "()";
		else
			$this->left->print_node();

		if ( $this->right == null ) 
			echo "()";
		else
			$this->right->print_node();
		echo ")";
	}
}

$b = new btree(0);

$sum_array = array();

$b->sum(  0 );
if ( count($sum_array) > 0 )
{
	$idx = rand( 0, count($sum_array) -1 );
	echo $sum_array[ $idx ] . " " ;
	$b->print_node();
	echo "\n";

	echo rand(-100000,100000) . " " ;
	$b->print_node();
	echo "\n";
}
