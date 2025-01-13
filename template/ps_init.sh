#!/bin/bash

HOME_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
WORK_PATH="/work/github/gaolious/algorithm/Baekjoon"

# CLION="/usr/local/bin/clion"
#CLION='/home/ajava/.local/share/JetBrains/Toolbox/scripts/clion1'
CLION="/home/ajava/.local/share/JetBrains/Toolbox/scripts/clion"
CPP_TEMPLATE_PATH="/work/github/gaolious/algorithm/template/clion_cpp_template"
NO=$1

function check_param()
{
    if ! [[ "${NO}" =~ ^[0-9]+$ ]]; then
        echo "parameter ${NO} is not digit."
		exit -1
    fi
}
check_param

RANGE_S=`echo "${NO}/1000*1000" | bc`
RANGE_E=`echo "${RANGE_S} + 999" | bc`
RANGE=`printf "%06d_%06d" ${RANGE_S} ${RANGE_E}`


echo "Copy Templates..."
VENV="/work/github/gaolious/algorithm/template/acmicpc/pythonProject/.venv/bin/python"
PYTHON_SCRIPT="/work/github/gaolious/algorithm/template/acmicpc/pythonProject/acmicpc_samples.py"

pushd /work/github/gaolious/algorithm/Baekjoon/clion 
rm -rf cmake-build*
rm -rf ./main.cpp
rm -rf ./checker

[ -d "${WORK_PATH}/${RANGE}/${NO}" ] || mkdir -p "${WORK_PATH}/${RANGE}/${NO}"
[ -f "${WORK_PATH}/${RANGE}/${NO}/${NO}.cpp" ] || cp -rf "${CPP_TEMPLATE_PATH}/main.cpp" "${WORK_PATH}/${RANGE}/${NO}/${NO}.cpp"
[ -d "${WORK_PATH}/${RANGE}/${NO}/checker" ] || cp -rf "${CPP_TEMPLATE_PATH}/checker" "${WORK_PATH}/${RANGE}/${NO}"

ln -fn "${WORK_PATH}/${RANGE}/${NO}/${NO}.cpp" ./main.cpp
ln -sfn "${WORK_PATH}/${RANGE}/${NO}/checker" ./checker
echo "${CLION} . >/dev/null 2>&1"
${CLION} . >/dev/null 2>&1
# code .

popd

