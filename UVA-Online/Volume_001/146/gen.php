<?php

srand((float)microtime() * 1000000);

$N = rand(1,5000);

function gen()
{
	$n = rand(1,50);
	$s = '';

	for ( $i=0 ; $i<$n ; $i ++)
		$s .= chr( ord('a') + rand(0,25) );
	echo "$s\n";
}


for ( $i = 0 ; $i < $N ; $i ++)
{
	gen();
}
