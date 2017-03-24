<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen($n)
{
	$arr = array();

	for ( $i = 1 ; $i <= $n ; $i ++)
		$arr[] = $i ;

	shuffle( $arr);
	return $arr;
}

$r = rand(10,100);
for ( $i = 0 ; $i < $r ; $i ++)
{
	$n = rand(1,30);
	$arr = gen( $n );

	for ( $j=0 ; $j < $n ; $j ++)
		echo $arr[ $j ] . " " ;
	echo"\n";
}
