<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/


$x = rand(0,50);
$y = rand(0,50);

$arr = array ( 'E', 'S', 'W', 'N' );
$C = array('R','L','F');

echo "$x $y\n";

$repeat = rand(1,10);

for ( $r=0 ; $r < $repeat ;$r++) 
{
	$commands = rand(1,100);

	$sx = rand(0,$x);
	$sy = rand(0,$y);
	$sd = $arr[ rand(0,3) ] ;

	echo "$sx $sy $sd\n";

	for ($i = 0 ; $i < $commands ; $i ++)
	{
		echo $C[ rand(0,2) ];
	}
	echo "\n";
}
