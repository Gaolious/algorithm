<?php

	for ( $i = 0 ; $i < 10000 ; $i ++ )
	{
		$x = rand(0,10);
		$y = rand(0,15-$x);
		echo pow( $y+1,$x) . " " . pow( $y, $x ) . "\n";
	}
