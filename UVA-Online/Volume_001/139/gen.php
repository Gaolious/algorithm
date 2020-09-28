<?php

function gen( $list, $n )
{
	$cnt = count($list);
	$ret = '';
	for ( $i = 0 ; $i < $n ; $i ++)
		$ret .= $list[ rand( 0, $cnt-1) ];

	return $ret;
}
function gen_number($n)
{
	$ret = '';

	$arr = array();
	for ( $i = ord('0') ; $i <= ord('9') ; $i ++)
		$arr []= chr ($i);
	return gen( $arr , $n );
}
function gen_name( $n )
{
	$ret = '';

	$arr = array();
	for ( $i = ord('0') ; $i <= ord('9') ; $i ++)
		$arr []= chr ($i);
	for ( $i = ord('a') ; $i <= ord('z') ; $i ++)
		$arr []= chr ($i);
	for ( $i = ord('A') ; $i <= ord('Z') ; $i ++)
		$arr []= chr ($i);
	$arr [] = ' ';
	return gen( $arr , $n );
}

$n = rand(0,100);
for ( $i = 0 ; $i < $n ; $i ++)
{
	switch ( rand(0,1) )
	{
		case 0 : echo "00"; break;
		case 1 : echo "0"; break;
	}
	echo gen_number( rand(1,15 ) ) . " " . gen_name( rand(0,25 ) ) . "$" . rand(0,100) . "\n"; 
}

echo "000000\n";

$n = rand(0,100);
for ( $i = 0 ; $i < $n ; $i ++)
{
	switch ( rand(0,2) )
	{
		case 0 : echo "00"; break;
		case 1 : echo "0"; break;
		case 2 : echo "" ; break;
	}
	echo gen_number( rand(1,15 ) ) . " " . rand(0,100) . "\n";
}
echo "#";
