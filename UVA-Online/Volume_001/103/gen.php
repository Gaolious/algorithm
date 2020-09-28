<?php

	for ( $i = 0 ; $i < 100 ; $i ++ )
	{
		$box = rand(1,30);
		$dimension = rand(1,10);

		echo "$box $dimension\n";

		for ( $b = 0 ; $b < $box ; $b ++ )
		{
			for ( $d = 0 ; $d < $dimension ; $d ++ )
				echo  rand(1,10000) . " " ;
			echo "\n";
		}
	}
