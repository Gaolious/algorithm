#!/bin/bash

python3 ./gen.py > ./input.txt

./cmake-build-debug/boj < ./input.txt > ./output.txt

python3 ./check.py
