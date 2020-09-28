<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

class btree
{
	public $num = 0 ;
	public $left = null;
	public $right = null ;

	public function __construct( $num )
	{
		$this->num = $num ;
		$this->left = $this->right = null;
	}
	
	public function create_child( $remain_node )
	{
		if ( $remain_node <= 0 ) return ;

		$mode = rand(1,3);//left only, right only, both

		$for_left = $for_right = 0 ;
		if ( $mode == 3 ) 
		{
			$for_left = $remain_node / 2 ;
			$for_right = $remain_node - $for_left ;
		}
		else if ( $mode == 2 ) $for_right = $remain_node;
		else if ( $mode == 1 ) $for_left = $remain_node ;

		if ( $for_left > 0 )
		{
			$this->left = new btree( rand(0,1000) );
			$this->left->create_child( $for_left - 1 ) ;
		}
		if ( $for_right > 0 )
		{
			$this->right = new btree( rand(0,1000 ) );
			$this->right->create_child( $for_right - 1 ) ;
		}
	}
	public function print_node( $curr_str, &$ret )
	{
		$ret [] = sprintf("(%d,%s)", $this->num, $curr_str );

		if ( $this->left != null ) $this->left->print_node( $curr_str . "L" , $ret );
		if ( $this->right != null ) $this->right->print_node( $curr_str . "R" , $ret );
	}
}

function gen()
{
	$nodes = rand(0,250 );

	if ( $nodes > 0 )
	{
		$t = new btree( rand(0,1000) );

		$t->create_child( $nodes - 1 ) ;

		$input_strings = array();

		$t->print_node( "", $input_strings ) ;


		shuffle( $input_strings );

		if ( rand(0,4) == -1 )
			array_shift( $input_strings );

		for ( $i = 0 ; $i < count($input_strings) ; $i ++)
			echo $input_strings[ $i ] . " " ;
	}



	echo "()\n";
}

$r = rand(10,100);

for ( $i = 0 ; $i < $r ; $i ++)
	gen();
