<?php

	for ( $i = 0 ; $i < 100 ; $i ++ )
	{
		$n = rand(2,20);

		echo "$n\n";
		for ( $s = 0 ; $s < $n ; $s ++ )
		{
			for ( $e = 0 ; $e < $n ; $e ++ )
			if ( $s != $e )
			{
				$v = rand(1, 10) ;
				if ( rand(0,1) ) $v = (double)$v / 100.0 ;
				echo "$v ";
			}
			echo "\n";
		}
	}
