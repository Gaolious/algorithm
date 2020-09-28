<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

function gen_ignore_word()
{
	// gen ignore word
	$ignore_str_array = array();
	$n = rand( 1, 50 );
	for ( $i = 0 ; $i < $n ; $i ++)
	{
		$t = $i ;
		$str = '';
		while ( true )
		{
			$str .= chr( ord('a')+ $t % 26 ) ;
			$t = (int)( $t / 26 ) ;
			if ( $t == 0 ) break;
		}

		$ignore_str_array [] = $str ;
	}

	for ( $i = 0 ; $i < $n ; $i ++ )
	{
		$len = rand(1,10);
		if ( strlen( $ignore_str_array[ $i ] ) < $len )
		{
			for ( $j = 0 ; $j < $len - strlen($ignore_str_array[ $i ] ) ; $j ++)
				$ignore_str_array[ $i ] .= chr( ord('a') + rand(0,25) );
		}
	}
	return $ignore_str_array;
}

function gen_word_list()
{
	$ret = array();
	
	for ( $i = 0 ; $i < 1000 ; $i ++ )
	{

		$len = rand(1,20);
		$str = '';

		for ( $j = 0 ; $j < $len ; $j ++ )
		{
			if ( rand(0,1) )
				$ch = chr( ord('a') + rand(0,25) );
			else
				$ch = chr( ord('A') + rand(0,25) );
			$str .= $ch ;
		}

		$ret [] = $str ;
	}

	return $ret;
}
function get_rand_ignore()
{
	global $ignore_str_array;
	$len = count($ignore_str_array);
	return $ignore_str_array[ rand(0,$len-1) ] ;
}
function get_rand_word()
{
	global $word_array ;
	$len = count($word_array);
	return $word_array[ rand(0,$len-1) ] ;
}

function gen_title()
{

	$w = rand(1,15);

	$str = '';

	for ( $i = 0 ; $i < $w ; $i ++)
	{
		$str .= rand(0,1) ? get_rand_word() : get_Rand_ignore(); 
		$str .= ' ';
	}
	return trim( $str );
}

$ignore_str_array = gen_ignore_word();
$word_array = gen_word_list();

for( $i=0 ; $i<count($ignore_str_array) ; $i++)
	echo $ignore_str_array[ $i ] . "\n";
echo "::\n";

$title_cnt = rand(1,200);
for ( $i = 0 ; $i < $title_cnt ; $i ++)
	echo gen_title() . "\n";
