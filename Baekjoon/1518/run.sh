#!/bin/bash

g++ ./main.cpp -std=c++17

for i in `seq 1 100`
do
    python3 ./gen.py > input_${i}.txt && ./a.out < ./input_${i}.txt > ./output_${i}.txt && python3 ./checker.py < ./output_${i}.txt && echo "$i : Success" || echo "$i : Fail"
done

