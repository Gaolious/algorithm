<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/


function gen($n)
{
	$arr = array();
	for ( $i = 0 ; $i < $n ; $i ++ )
		for ( $j = 0 ; $j < $n ; $j ++)
			if ( $i != $j )
				$arr [] = "$i $j";

	shuffle($arr);
	return $arr;
}

$r = rand(10,50); // repeat

for ( $i = 0 ; $i < $r ; $i ++)
{
	$n = rand(2,29); // size
	$arr = gen($n);
	$pr_arr = array_slice( $arr, rand(0, count($arr)/2 ) );
	echo count($pr_arr) . "\n";
	for ( $j = 0 ; $j < count($pr_arr)  ; $j ++)
		echo "{$arr[$j]}\n";
}

