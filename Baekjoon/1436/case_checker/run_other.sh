#!/bin/bash
export PATH="/usr/local/opt/coreutils/libexec/gnubin:$PATH"
OPT="-O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ"

g++ -o boj ../main.cpp ${OPT} 1>/dev/null 2>/dev/null

for i in `seq 1 1000`
do
    python3 gen.py > ./input.txt
    s=`date "+%s.%N"`
    ./boj < ./input.txt > out_boj.txt
    e=`date "+%s.%N"`
    t1=$( echo "$e - $s" | bc -l )

    s=`date "+%s.%N"`
    python3 ./other.py < ./input.txt > out_other.txt
    e=`date "+%s.%N"`
    t2=$( echo "$e - $s" | bc -l )

    if diff -u  ./out_boj.txt ./out_other.txt; then
        echo "Test ${i} Identical Output. BOJ[$t1 s] / OTHER[$t2 s]"
    else
        echo "Test ${i} Different Output. BOJ[$t1 s] / OTHER[$t2 s]"
        exit -1
    fi
done
