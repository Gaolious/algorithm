#!/bin/bash
export PATH="/usr/local/opt/coreutils/libexec/gnubin:$PATH"
OPT="-O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ"

g++ -o boj ../main.cpp ${OPT} 1>/dev/null 2>/dev/null
g++ -o other ./other.cpp ${OPT} 1>/dev/null 2>/dev/null
function run() {
    s=`date "+%s.%N"`
    ./boj < ./input.txt > out_boj.txt
    e=`date "+%s.%N"`
    t1=$( echo "$e - $s" | bc -l )

    s=`date "+%s.%N"`
    ./other < ./input.txt > out_other.txt
    e=`date "+%s.%N"`
    t2=$( echo "$e - $s" | bc -l )

    if diff -u  ./out_boj.txt ./out_other.txt; then
        echo "Test ${i} Identical Output. BOJ[$t1 s] / OTHER[$t2 s]"
    else
        echo "Test ${i} Different Output. BOJ[$t1 s] / OTHER[$t2 s]"
        exit -1
    fi
}
function run2() {
for X in `seq 1 100`
do
    for A in `seq 1 100`
    do
        for B in `seq $A 100`
        do
            echo "$X $A $B" > ./input.txt
            echo "0123578" >> ./input.txt
            run
        done
    done
done
}

for i in `seq 1 1000`
do
    echo "iter ${i}"
    python3 gen.py > ./input.txt
    run
done
