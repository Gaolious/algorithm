<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function to26($n)
{
	$arr = array();
	for ( $i = ord('A') ; $i <= ord('Z') ; $i ++)
		$arr [] = chr($i);

	$str = '';
	while ( $n > 0 )
	{
		$str = $arr[  ($n-1)%26 ] . $str ;
		$n = (int)( ($n - 1 ) / 26 );
	}

	return $str;
}

$n = rand(100,10000);
echo "$n\n";
for ( $i = 0 ; $i < $n ; $i ++)
{
	$row = rand(1,1000000);
	$col = rand(1,1000000);
	$strCol =  to26( $col );

	echo "R{$row}C{$col}\n";
	echo "{$strCol}{$row}\n";
}
