#!/bin/bash

g++ -o boj main.cpp -O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ
g++ -o other other.cpp -O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ

for i in `seq 1 100`
do
  echo " Testcase #${i}"
  python3 ./gen.py > input.txt
  ./boj < ./input.txt > out_boj.txt
  ./other < ./input.txt > out_other.txt

  if diff -u ./out_boj.txt ./out_other.txt; then
    echo "Identical Output"
  else
    echo "Different Output"
    exit -1
  fi
done
