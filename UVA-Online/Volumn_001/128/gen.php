<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen()
{
	$f = array();

	for ( $i=31 ; $i<127 ; $i ++)
		$f []=  chr($i);
	return $f ;
}

$r = rand(1,100);

for ( $i = 0 ; $i < $r ; $i ++ ) 
{
	$n = rand(10,1000);
	$ret = gen();
	for ( $j = 0 ; $j < $n ; $j ++ ) echo $ret[ rand(0,count($ret)-1) ] ;
	echo "\n";
}
echo "#";
