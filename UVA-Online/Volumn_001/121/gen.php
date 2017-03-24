<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$r = rand(10,1000);

for ( $i = 0 ; $i < $r ; $i ++)
{
	$x = rand(0, 12800) / 100.0;
	$y = rand(0, 12800) / 100.0;
	echo "$x $y\n";
}

