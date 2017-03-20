<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/
	$m = rand( 3, 50 );
	$n = rand( 3, 50 );
	$cost = rand(0,10);

	$grid = array();
	$p = 0 ;

	for ( $y = 0 ; $y < $n ; $y ++ )
	{
		$grid [] = array();
		for ( $x = 0 ; $x < $m ; $x ++)
		{
			if ( $y < 3 || $x < 3 ) 
			{
				$grid[ $y ][ $x ] = 0 ;
				continue ;
			}

			$grid[ $y ][ $x ] = ( rand(0,10 ) < 2 ) ? 1 : 0 ; 
			if ( $grid [ $y ][ $x ] > 0 ) $p ++;
		}
	}

	echo "$m $n\n";
	echo "$cost\n";
	echo "$p\n";
	
	for ( $y = 3 ; $y < $n ; $y ++ )
		for ( $x = 3 ; $x < $m ; $x ++)
		if ( $grid[ $y ][ $x ] > 0 )
		{
			$v = rand(-10,10);
			$c = rand(0,3);

			echo "$x $y $v $c\n";
		}

	for ( $y=2 ; $y < $n ; $y ++ )
		for ( $x=2 ; $x < $m ; $x ++)
			if ( $grid[ $y ][ $x ] == 0 && rand(0,1) )
			{
				$d = rand(0,3);
				$t = rand(-5,5);
				echo "$x $y $d $t\n";
			}
