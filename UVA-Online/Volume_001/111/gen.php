<?php
	$n = rand(2,20);

	for ( $i = 0 ; $i < $n ; $i ++ )
	{
		$cnt = rand(2,20);
		echo "$cnt\n";

		$r = rand(5,10);
		for ( $t=0; $t<$r ; $t++) 
		{
			$arr = array();	
			for ( $j=0 ; $j<$cnt;$j++)
				$arr [] = $j+1;

			shuffle( $arr );
			shuffle( $arr );
			shuffle( $arr );

			for ( $j=0 ; $j<$cnt;$j++)
				echo $arr[ $j ] . " " ;
			echo "\n"; 
		}
	}
