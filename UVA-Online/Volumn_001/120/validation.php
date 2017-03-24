<?php

function flip( $arr, $idx )
{
	$a = array();

	for ( $i = count($arr)-$idx ; $i >= 0 ; $i -- )
		$a [] = $arr[ $i ] ;

	for ( $i = count($arr)-$idx + 1 ; $i < count($arr) ; $i++)
		$a [] = $arr[ $i ] ; 

	return $a ;
}

function checker($arr, $seq )
{

}
	$data = stream_get_contents(STDIN);

	$lines = explode("\n", trim( $data ) ) ;
	for ( $i = 0 ; $i < count($lines) ; $i += 2 )
	{
		$original = array_merge( array(), explode(" ", trim($lines[$i]) ) ) ;
		$seq = array_merge( array(), explode(" ", trim($lines[$i+1]) ) ) ;

		for ( $j = 0 ; $j < count($seq) ; $j ++ )
		if ( $seq[ $j ] > 0 )
		{
			printf("%3d : ", $j );
			for ( $t=0 ; $t < count($original) ; $t ++ ) printf("%3d",$original[$t]);
			printf( " => (%3d) => ", $seq[$j] );

			$original = flip($original, $seq[$j]);
			for ( $t=0 ; $t < count($original) ; $t ++ )printf("%3d", $original[$t]);
			printf("\n");
		}
		echo "-----------------------------------------------------------------------------------------\n";
	}
	
