#!/bin/bash

OPT="-O2 -std=gnu++17 -DONLINE_JUDGE -DBOJ"

g++ -o boj ../main.cpp ${OPT} 1>/dev/null 2>/dev/null
#g++ -o other ./other.cpp ${OPT} 1>/dev/null 2>/dev/null

function T() {
    t="${1}_${2}"
    for a2 in `seq ${1} ${2}`
    do
        for a1 in `seq -100 100`
        do
            for a0 in `seq -100 100`
            do
                for c in `seq 1 100`
                do
                    for n0 in `seq 1 100`
                    do
                        echo "${a2} ${a1} ${a0}" > ./input_${t}.txt
                        echo "${c}" >> ./input_${t}.txt
                        echo "${n0}" >> ./input_${t}.txt

                        ./boj < ./input_${t}.txt > out_boj_${t}.txt
                        python3 main.py < ./input_${t}.txt > out_other_${t}.txt

                        if diff -u  ./out_boj_${t}.txt ./out_other_${t}.txt; then
                            echo "Test ${a2} ${a1} ${a0} ${c} ${n0} Equal"
                        else
                            echo "Test ${a2} ${a1} ${a0} ${c} ${n0} Different Output"
                            exit -1
                        fi
                    done
                done
            done
        done
    done
}
T 0 10 > ./0.txt &
T 11 20 > ./11.txt &
T 21 30 > ./21.txt &
T 31 40 > ./31.txt &
T 41 50 > ./41.txt &
T 51 60 > ./51.txt &
T 61 70 > ./61.txt &
T 71 80 > ./71.txt &
T 81 90 > ./81.txt &
T 91 100 > ./91.txt &

for p in `jobs -p`
do
    echo "wait for ${p}"
    wait $p
done
