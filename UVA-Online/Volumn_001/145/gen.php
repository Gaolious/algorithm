<?php

srand((float)microtime() * 1000000);

$N = rand(1,5000);

function gen()
{
	$c = chr( rand( ord('A'), ord('E') ) );
	for ( $i=0, $phoneNum= '' ; $i < 8 ; $i ++)
		$phoneNum .= "" . rand(0,9);
	$phoneNum[3]='-';

	$s = rand( 0, 23*60+59 );
	$e = $s + rand(1, 24*60);

	$sh = (int)($s/60);
	$sm = $s % 60;
	$eh = (int)($e/60) % 24;
	$em = $e % 60;

	printf( "$c %s %02d %02d %02d %02d\n", $phoneNum, $sh, $sm, $eh, $em);

}


for ( $i = 0 ; $i < $N ; $i ++)
{
	gen();
}
