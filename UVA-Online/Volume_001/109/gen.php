<?php
	$nKingdoms = rand(1, 20 );
	for ( $i = 0 ; $i<$nKingdoms ; $i ++)
	{
		$nCoords = rand( 3, 100 );
		echo $nCoords . "\n";

		for ( $j =0 ; $j < $nCoords ; $j ++)
			echo rand( 0, 500 ) . " " . rand(0, 500 ) . "\n";	
	}

	echo "-1\n";

	$nElec = rand(0, 100 );
	for ( $j =0 ; $j < $nElec ; $j ++)
		echo rand( 0, 500 ) . " " . rand(0, 500 ) . "\n";	

