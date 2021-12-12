#!/bin/bash

for i in `seq 1 100`
do
    echo "${i}"
    python3 gen.py > ./input_${i}.txt
    ./cmake-build-release/boj < ./input_${i}.txt
done
