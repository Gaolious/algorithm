#!/bin/bash

BIN=./bin/UVA
IN=./input/input.txt
REPEAT=100

[ -d ./output ] || mkdir -p ./output 

for idx in `seq 0 12`
do
	[ -f ./output/output_${idx}.txt ] && rm -rf ./output/output_${idx}.txt
done

for r in `seq 0 $REPEAT`
do	
	for idx in `seq 0 12`
	do	
		echo ""
		echo "[`date`] idx=$idx / Repeat : $r "

		s=`/bin/date +"%s.%N"`
		$BIN $idx < $IN
		e=`/bin/date +"%s.%N"`
		t=$( echo "$e - $s" | bc )
		echo "$t" >> ./output/output_${idx}.txt
	done
done
