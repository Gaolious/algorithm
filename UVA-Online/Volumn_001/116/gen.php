<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$n = rand( 10,20);

for ( $r = 0 ; $r < $n ; $r ++) 
{
	$y = rand(1,10);
	$x = rand(1,100);

	echo "$y $x\n";

	for ( $i = 0 ; $i < $y ; $i ++)
	{
		for ( $j = 0 ; $j < $x ; $j ++)
			echo rand(-10,10) . " ";
		echo "\n";
	}
}
