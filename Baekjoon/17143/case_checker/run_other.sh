#!/bin/bash

OPT="-O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ"

g++ -o boj ../main.cpp ${OPT} 1>/dev/null 2>/dev/null
g++ -o other ./other.cpp ${OPT} 1>/dev/null 2>/dev/null

for i in `seq 1 1000`
do
    python3 gen.py > ./input.txt
    ./boj < ./input.txt > out_boj.txt

    ./other < ./input.txt > out_other.txt
    
    if diff -u  ./out_boj.txt ./out_other.txt; then
        echo "Test ${i} Identical Output boj[$t1], other[$t2]"
    else
        echo "Test ${i} Different Output"
        exit -1
    fi
done
