<?php
	$n = 25;

	echo $n . "\n";
	$ar1 = array( "move", "pile" );
	$ar2 = array( "over", "onto" );

	for ( $i = 0 ; $i < 1000 ; $i ++)
	{
		$c1 = $ar1[ rand(0,1) ] ;
		$c2 = $ar2[ rand(0,1) ] ;
		$n1 = rand(0, $n-1);
		$n2 = rand(0, $n-1);

		echo "$c1 $n1 $c2 $n2\n";
	}
	echo "quit";
