<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen($n)
{
	$arr_co = array();
	$arr_x = array();
	$arr_y = array();

	for ( $i = 0 ; $i < $n ; $i ++)
	{
		$arr_co []= rand(-9,9);
		$arr_x []= rand(0,10);
		$arr_y []= rand(0,10);
	}

	for ( $i = 0 ; $i < $n ; $i ++ )
	{
		if ( ($arr_x[ $i ] == 0 && $arr_y[ $i ] == 0 ) )
		{
			if ( $i == 0 && $arr_co[ $i ] > 0 ) {}
			else if ( $arr_co[ $i ] > 0 ) echo "+";
			else { echo "-"; $arr_co[$i]*=-1;}

			echo $arr_co[$i];
		}
		else if ( abs($arr_co[$i]) >= 1 )
		{
			if ( $i == 0 && $arr_co[ $i ] > 0 ) {}
			else if ( $arr_co[ $i ] > 0 ) echo "+";
			else { echo "-"; $arr_co[$i]*=-1;}

			if ( abs($arr_co[$i]) > 1 ) echo $arr_co[$i];

		}
		else
		{
			echo "-0";
			continue;
		}

		if ( $arr_x[ $i ] > 0 )
		{
			echo "x";
			if ( $arr_x[ $i ] > 1 ) echo $arr_x[ $i ] ;
		}
		if ( $arr_y[ $i ] > 0 )
		{
			echo "y";
			if ( $arr_y[ $i ] > 1 ) echo $arr_y[ $i ] ;
		}
	}
	echo"\n";
}

$r = rand(1,10);

for ( $i = 0 ; $i < $r ; $i ++ ) 
{
	gen(rand(1,5));
	gen(rand(1,5));
}
echo "#";
