<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$n = rand(10,100);
for ( $i = 0 ; $i < $n ; $i ++)
{
	echo "Input{$n}\n";

	$cnt = rand(10,100);
	$x = array();
	$y = array() ;
	$avg_x = 0 ;
	$avg_y = 0 ;
	for ( $j = 0 ; $j < $cnt ; $j ++ )
	{
		$x [] = rand(0,1000);
		$y [] = rand(0,1000);
	}
	for ( $j = 0 ; $j < $cnt ; $j ++ )
	{
		$rate = (float)$j / (float)($j+1) ;
		$avg_x = $avg_x * $rate + $x[ $j ] / (float)($j+1) ;
		$avg_y = $avg_y * $rate + $y[ $j ] / (float)($j+1) ;
	}

	$cx = (int)( $avg_x );
	$cy = (int)( $avg_y );

	echo "{$cx} {$cy}\n";
	for ( $j = 0 ; $j < $cnt ; $j ++ )
		echo "{$x[$j]} {$y[$j]} ";
	echo "0 0\n";
}
echo "#";
