<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

$tail = 0 ;
$head = 0 ;
$arr = array ();

function add_queue( $name )
{
	global $tail, $arr;
	if ( $tail >= 300 ) return false ;
	$arr[ $tail ++ ] = $name ;
	return true ;
}
function pop_queue()
{
	global $head, $tail, $arr ;

	if ( $head < $tail )
	{
		return $arr[ $head ++ ] ;
	}
	return null;
}
function add_child( $depth )
{
	global $arr, $head, $tail;

	if ( $depth >= 20 ) return ;

	$n = rand(1,3);
	if ( ($name = pop_queue() ) == null )
		return false ;

	for ( $i = 0 ; $i < $n ; $i ++ )
	{
		$child_name = $name . "{$i}";

		if ( add_queue( $child_name ) == false )
			return false ;

		echo "$child_name $name\n";

	}
	for ( $i = 0 ; $i < $n ; $i ++ )
		add_child( $depth + 1 ); 

	return true ;
}

$n = rand(2,3);
for ( $i=0 ; $i < $n ; $i ++)
{
	add_queue( chr( ord('a') + $i ) );
}
add_child( 1 );

echo "no.child no.parent\n";

for ( $i = 0 ; $i < $tail ; $i ++ )
{
	for ( $j = $i + 1 ; $j < $tail ; $j ++ )
		echo $arr[ $i ] . " " . $arr[ $j ] . "\n";
}
