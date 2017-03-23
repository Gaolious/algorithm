<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function print_str( $a, $b, $len )
{
	echo $a ;
	for ( $j = 0 ; $j < $len ; $j ++ ) echo chr( ord('a') + rand(0,25) );
	echo $b;
	echo "\n";
}
function gen()
{

	$arr = array();
	$n = rand(2,26);

	for ( $i = 0 ; $i < 26 ; $i ++) $arr [] = chr( ord('a') + $i );

	shuffle($arr);

	for ( $i = $n ; $i < 26 ; $i ++) unset( $arr[ $n ] );

	$s = $arr[0];
	$e = $arr[1];

	shuffle($arr);

	$arr [] = $arr[ 0 ];


	for ( $i = 0 ; $i < $n ; $i ++)
	{
		print_str( $arr[$i], $arr[$i+1], rand(2,10) );
	}

	// odd
	if ( rand(0,1) )
	{
		print_str( $s, $e, rand(2,10) );
	}

	echo "deadend\n";
}

$n = rand(2,10);
for ( $i = 0 ; $i < $n ; $i ++)
	gen();
