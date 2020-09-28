<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen()
{
	$face = array('A', '2','3','4','5','6','7','8','9','T','J','Q','K');
	$suit = array('C','D','H','S');
	
	$ret = array();
	foreach( $face as $f )
		foreach ( $suit as $s )
			$ret []= "{$f}{$s}";

	shuffle( $ret);
	
	return $ret ;
}

$r = rand(1,100);

for ( $i = 0 ; $i < $r ; $i ++ ) 
{
	$ret = gen();
	for ( $j=0  ; $j<26 ; $j ++) echo $ret[ $j ] . " ";
	for ( $j=26 ; $j<52 ; $j ++) echo $ret[ $j ] . " ";
	echo "\n";
}
echo "#";
