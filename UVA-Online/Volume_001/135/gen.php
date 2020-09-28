<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gcd( $p, $q )
{
	if ( $q == 0 ) return $p;
	return gcd( $q, $p % $q );
}

function is_possible( $n )
{
	if ( $n - 1 == 0 ) return true ;
	if ( $n - 1 == 1 ) return true ;
	
	for ( $i = 2 ; $i * $i <= $n ; $i ++ )
	if ( gcd( $n-1, $i ) != 1 ) 
		return false;

	return true;
}

for ( $i = 1 ; $i <= 32 ; $i ++)
if ( is_possible( $i ) )
	echo "$i\n";
