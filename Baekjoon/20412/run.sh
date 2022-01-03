#!/bin/bash

for i in `seq 1 100`
do
    echo "test case #${i}"
python3 ./gen.py > input.txt
./cmake-build-debug/boj < input.txt > output.txt
python3 ./checker.py
done
