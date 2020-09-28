<?php
function gen()
{
	srand((float)microtime() * 1000000);
	
	$nRect = rand(1, 25);
	$nPoint = rand(1, 50);

	while ( $nRect > 0 || $nPoint > 0 )
	{
		$choice = rand( 1, $nRect + $nPoint );

		if ( $choice <= $nRect )
		{
			$sx = rand(0, 499);
			$sy = rand(0, 499);
			$ex = rand(0, 499);
			$ey = rand(0, 499);

			if ( $sx > $ex ) { $t = $sx ; $sx = $ex ; $ex = $t ; }
			if ( $sy > $ey ) { $t = $sy ; $sy = $ey ; $ey = $t ; }

			echo "R $sx $sy $ex $ey\n";
			$nRect--;
		}
		else
		{
			$sx = rand(0, 499);
			$sy = rand(0, 499);

			echo "I $sx $sy\n";
			$nPoint--;
		}
	}
}

gen();

$N = rand(100,1000);

for ( $i = 0 ; $i < $N ; $i ++ )
{
	$sx = rand(0, 499);
	$sy = rand(0, 499);
	echo "M $sx $sy\n";
}	
echo "#";
