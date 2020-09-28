<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen($_arr)
{
	$arr = array_merge($_arr, array());

	shuffle($arr);

	for ( $i = 0 ; $i < 10 ; $i ++)
	{
		echo $arr[ $i ] ;
		if ( $i < 9 ) echo " ";
	}
	echo "\n";
}

$face = "A23456789TJQK";
$suit = "CDHS";

$arr = array();
for ( $i = 0 ; $i < strlen($face) ; $i ++)
for ( $j = 0 ; $j < strlen($suit) ; $j++)
	$arr [] = "{$face[$i]}{$suit[$j]}";


$n = rand(10,100);

for ( $i = 0 ; $i < $n ; $i ++)
	gen($arr);
