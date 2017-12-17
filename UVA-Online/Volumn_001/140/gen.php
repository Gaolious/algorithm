<?php
function gen()
{
	srand((float)microtime() * 1000000);

	$arr = array();
	for( $i = 0 ; $i < 26 ; $i ++) $arr[] = chr( $i + ord('A') );

	shuffle($arr);

	$N = rand(2,8);

	$ret = array();
	for ( $i = 0 ; $i < $N ; $i ++)
	{
		$ret[] = array();

		$possibles = array();
		for ( $j = 0 ; $j < $N ; $j ++ )
			$possibles[] = $arr[ $j ] ;
		shuffle($possibles);


		$cnt = rand(2, $N);

		for ( $j = 0 ; $j < $cnt  ; $j ++ )
		{
			if ( $possibles[ $j ] == $arr[$i] ) continue;
			else $ret[$i][] = $possibles[ $j ] ;
		}
	}

	for ( $i = 0 ; $i < count($ret) ; $i ++ )
	{
		if ( $i != 0 ) echo ";";
		echo $arr[$i] . ":";
		for ( $j = 0 ; $j < count($ret[$i]) ; $j ++ )
			echo $ret[$i][$j];
	}
}

$N = rand(5,10);

for ( $i = 0 ; $i < $N ; $i ++ )
{
	gen();
	echo "\n";
}	
echo "#";
