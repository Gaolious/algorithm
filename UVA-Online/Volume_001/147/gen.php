<?php

srand((float)microtime() * 1000000);

$N = rand(1,5000);

function gen()
{
	$n = rand(1,30000);
	$f = $n % 100;
	$n = (int)( $n/100 );

	printf("%d.%02d\n", $n, $f);
}


for ( $i = 0 ; $i < $N ; $i ++)
{
	gen();
}
