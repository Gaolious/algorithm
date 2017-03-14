<?php

	$x = 1 ;

	for ( $i = 0 ; $i < 10000; $i ++ )
	{
		$y = rand(0,10000);
		$width = rand(0,100);
		$next_x = $x + rand(0,100);

		if ( $next_x >= 10000 ) break;
		echo "$x $y $next_x\n";
		$x = $next_x ;
	}
