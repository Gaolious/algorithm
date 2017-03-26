<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$r = rand(1,1);
for ( $repeat = 0 ; $repeat < $r ; $repeat ++ ) 
{

	$arr = array();
	$order = array();

	$n = rand( 2, 15 );
	for ($i=0 ; $i<$n ; $i ++) $arr []= chr( ord('a') + $i ) ;
	for ($i=0 ; $i<$n ; $i ++) $order []= chr( ord('a') + $i ) ;

	echo join(" ", $arr ) . "\n";

	for ( $i = 0 ; $i < $n && count($order) > 2 ; $i ++)
	{
		$idx = rand(0, count($order)-1 ) ;
		$a = $order[ $idx ] ;
		unset($order[ $idx ] );
		$order = array_values($order);

		$idx2 = rand(0, count($order)-1 ) ;
		$b = $order[ $idx2 ];

		echo "$a $b ";
	}
	echo "\n";
}
