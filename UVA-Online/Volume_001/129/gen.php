<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$r = rand(1,100);

for ( $i = 0 ; $i < $r ; $i ++ ) 
{
	$L = rand(1,26);
	$n = ( 
		( $L == 1)  ? 
			(1) : 
			($L == 2 ? 1 : rand(1,80)) );
	echo "{$n} {$L}\n";
}
echo "0 0";
