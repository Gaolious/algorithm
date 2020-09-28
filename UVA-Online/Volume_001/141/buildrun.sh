#!/bin/bash

GPP="/usr/bin/g++"
OP="-lm -lcrypt -pipe -DONLINE_JUDGE -Wdeprecated-declarations"

rm -rf ./out*

for src in *.cpp
do
	filename=${src%.*}
	${GPP} $src -o $filename ${OP}

	for fin in ./input/*.txt
	do
		fout=$( echo $fin | sed 's/input/output/g' )
		
		[ -d output ] || mkdir output

		s=`date +"%s.%N"`
		./$filename < $fin > $fout
		e=`date +"%s.%N"`
		t=$( echo "$e - $s" | bc )

		echo "[${filename}] => In[${fin}] Out[${fout}] : ${t} seconds."
	done
	mv output "out_${filename}"
done
