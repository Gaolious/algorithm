#!/bin/bash

GPP="/usr/bin/g++"
OP="-lm -lcrypt -O2 -pipe -DONLINE_JUDGE"

for src in *.cpp
do
	filename=${src%.*}
	${GPP} $src -o $filename ${OP}
	[ -d output ] || mkdir output

	for fin in ./input/*.txt
	do
		fout=$( echo $fin | sed 's/input/output/g' )

		s=`date +"%s.%N"`
		./$filename < $fin > $fout
		e=`date +"%s.%N"`
		t=$( echo "$e - $s" | bc )

		echo "In[${fin}] Out[${fout}] : ${t} seconds."
	done
	mv output "out_${filename}"
done
