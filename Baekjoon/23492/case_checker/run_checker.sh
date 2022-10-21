#!/bin/bash

OPT="-O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ"

g++ -o boj ../main.cpp ${OPT} 1>/dev/null 2>/dev/null

for i in `seq 1 1000`
do
    echo "Test #${i}"
    time python3 gen.py > ./input.txt
    time ./boj < ./input.txt > output.txt

    if python3 checker.py; then
        echo "Test ${i} Identical Output"
    else
        echo "Test ${i} Different Output"
        exit -1
    fi
done
