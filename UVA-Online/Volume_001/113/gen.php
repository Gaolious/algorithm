<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/
	$r = rand(10,20);

	for ( $i = 0 ; $i < $r ; $i ++)
	{
		$k = rand(1, 100000000);
		$n = rand(1, 200 );

		$p = gmp_pow($k, $n);

		echo $n . "\n" ;
		echo  gmp_strval($p) . "\n";
	}

