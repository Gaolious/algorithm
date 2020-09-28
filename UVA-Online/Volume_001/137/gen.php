<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

class Point
{
	public $x, $y;
	public function Point($_x, $_y)
	{
		$this->x = $_x;
		$this->y = $_y;
	}
	public function cross( $o)
	{
		return $this->x * $o->y - $this->y * $o->x ;
	}
	public function dist( $o)
	{
		return sqrt( pow( $this->x - $o->x , 2) + pow($this->y - $o->y , 2) );
	}
}
function cross2( $a, $b)
{
	return $a->cross($b);
}
function cross3( $a, $b, $c)
{
	$p1 = new Point( $b->x - $a->x, $b->y - $a->y );
	$p2 = new Point( $c->x - $a->x, $c->y - $a->y );

	return cross2( $p1, $p2 );
}
function ccw( $a, $b, $c )
{
	$r = cross3($a,$b,$c);
	if ( $r < 0 ) return -1; // r
	if ( $r > 0 ) return 1 ; // l
	return 0;
}
function genPoint()
{
	$x = rand(0, 100);
	$y = rand(0, 100);
	return new Point($x, $y);
}
function cmp( $p1, $p2 )
{
	if ( $p1->y < $p2->y ) return -1;
	if ( $p1->y > $p2->y ) return 1;

	if ( $p1->x < $p2->x ) return -1;
	if ( $p1->x > $p2->x ) return 1;
	return 0;
}
function swap( &$a, &$b)
{
	$c = $a; $a = $b; $b = $c;
}
function sort_points( $arr, $nPoints)
{
	for ( $i = 0 ; $i < $nPoints-1 ; $i ++ )
	{
		$min_idx = $i;
		for ( $j = $i +1 ; $j < $nPoints ; $j ++ )
		{
			if ( cmp( $arr[ $min_idx ], $arr[ $j ] ) > 0 )
				$min_idx = $j ;
		}
		if ( $min_idx != $i )
			swap( $arr[ $min_idx ], $arr[ $i ] );
	}
	return $arr;
}

function convex( &$arr, $nPoints )
{
	for ( $i = 1 ; $i < $nPoints ; $i ++)
	{
		for ( $j = $i + 1 ; $j < $nPoints ; $j ++ )
		{
			$dir = ccw( $arr[ $i - 1 ], $arr[ $i ], $arr[ $j ] );

			if ( $dir < 0 ) 
				continue;
			else if ( $dir > 0 )
				swap( $arr[ $i ], $arr[ $j ] );
			else
			{
				if ( $arr[ $i-1 ]->dist( $arr[ $i ] ) > $arr[ $i - 1 ]->dist( $arr[ $j ] ) )
					swap( $arr[ $i], $arr[ $j ] );
			}
		}
		if ( ccw( $arr[ $i - 1 ] , $arr[ $i ], $arr[ 0 ] ) > 0 ) return $i;
	}
	return $nPoints;
}

$n = rand(10,100);

for ( $r = 0 ; $r < $n ; $r ++ )
{
	$nPoint1 = rand(3,1000);
	$nPoint2 = rand(3,1000);
	$p1 = array();
	$p2 = array();

	for ( $i =0 ; $i < $nPoint1 ; $i ++) $p1 [] = genPoint();
	for ( $i =0 ; $i < $nPoint2 ; $i ++) $p2 [] = genPoint();

	$p1 = sort_points($p1, $nPoint1);
	$p2 = sort_points($p2, $nPoint2);

	$nPoint1 = convex( $p1, $nPoint1);
	$nPoint2 = convex( $p2, $nPoint2);

	echo "$nPoint1 ";
	for ( $i =0 ; $i < $nPoint1 ; $i ++) echo "{$p1[$i]->x} {$p1[$i]->y} ";
	echo "\n$nPoint2 ";
	for ( $i =0 ; $i < $nPoint2 ; $i ++) echo "{$p2[$i]->x} {$p2[$i]->y} ";
	echo "\n";
}
echo "0";
