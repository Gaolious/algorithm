<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen($n)
{
	$ret = array();
	for ( $i = 0 ; $i < $n ; $i ++)
	{
		$c = chr( ord('a') + $i );
		$len = rand(2,12);
		$str = '';
		for ( $j = 0 ; $j < $len ; $j ++)
			$str .= $c ;
		$ret [] = $str;
	}

	shuffle($ret);
	return $ret;
}
function pr()
{
	$n = rand( 1, 10 );

	$name = gen($n);


	echo $n . "\n";

	for ($i = 0 ; $i < $n ; $i ++)
		echo $name[ $i ] . " " ;
	echo "\n";

	for ($i = 0 ; $i < $n ; $i ++)
	{
		$amount = rand(0,2000);
		$targets = rand(0,$n-1);
		$arr_target = array_merge( array(), $name );
		unset( $arr_target[ $i ] );

		echo "{$name[ $i ]} $amount $targets";

		shuffle( $arr_target );

		for ( $j = 0 ; $j < $targets ; $j ++)
			echo " {$arr_target[$j]}";
		echo "\n";
	}
}

$r = rand(10,200);

for ( $i = 0 ; $i < $r ; $i ++)
	pr();
