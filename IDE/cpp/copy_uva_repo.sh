#!/bin/bash

UVA=/home/ajava/ProblemSolving/UVA-Online/Volumn_001/166

[ -d "${UVA}" ] && { echo "path is exist"; exit; }

mkdir -p ${UVA} 

cd /home/ajava/ProblemSolving/IDE/cpp

cp -rf Makefile input/ output/ src/ "${UVA}"
