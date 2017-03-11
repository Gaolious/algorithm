<?php

	for ( $i = 0 ; $i < 1000 ; $i ++ )
	{
		for ( $j = 0 ; $j < 9 ; $j ++ )
			echo rand(0,10000) . " ";
		echo "\n";
	}

