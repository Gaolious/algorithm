<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/


$n = rand(10,1000);

for ( $i = 0 ; $i<$n ; $i ++)
{
	$N = rand(1,20);
	$k = rand( 1, 100000);
	$m = rand( 1, 100000);

	echo "$N $k $m\n";
}
echo "0 0 0";
