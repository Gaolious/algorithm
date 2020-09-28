<?php

srand((float)microtime() * 1000000);

function gen()
{
	$p = array();

	for ( $i = 0 ; $i < 6 ; $i ++ )
		$p[$i] = (double)(rand(0, 10000) / 100.0) ;

	for ( $i = 0 ; $i < 6 ; $i ++)
	{
		if ( $i != 0 ) echo " ";
		echo $p[$i];
	}
	echo "\n";
}

gen();

$N = rand(100,10000);

for ( $i = 0 ; $i < $N ; $i ++ )
{
	gen();
}	
echo "0 0 0 0 0 0";
