<?php
function gen()
{
	srand((float)microtime() * 1000000);
	
	$N = rand(2,50);
	
	$map = array($N); 
	for ( $i = 0 ; $i <= $N ; $i ++)
	{
		$map[ $i ] = array($N);
		for ( $j = 0 ; $j <= $N ; $j ++) $map[$i][$j] = 0;
	}
	
	echo "$N\n";
	for ( $i = 0 ; $i < 2 * $N ; $i ++ )
	{
		$x = rand( 1, $N );
		$y = rand( 1, $N );
		
		$c = $map[ $y ][ $x ] == 0 ? '+' : '-';

		$map [ $y ][ $x ] = 1 - $map[ $y ][ $x ] ;

		echo "$x $y $c\n";
	}
}

$N = rand(10,100);

for ( $i = 0 ; $i < $N ; $i ++ )
{
	gen();
}	
echo "#";
