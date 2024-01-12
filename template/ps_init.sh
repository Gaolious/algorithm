#!/bin/bash

HOME_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
WORK_PATH=`pwd -P`
# CLION="/usr/local/bin/clion"
CLION='/home/ajava/.local/share/JetBrains/Toolbox/scripts/clion1'
# /Users/ajava/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.7172.20/CLion.app/Contents/MacOS/clion"

CPP_TEMPLATE_PATH="$( cd "${HOME_PATH}"; cd ./clion_cpp_template; pwd -P )"
PYTHON_TEMPLATE_PATH="$( cd "${HOME_PATH}"; cd ./code_python_template; pwd -P )"
TYPE=$1
PARAM=$2

function usage()
{
    echo "
Usages :         
    $ $0 (c|cpp|python2|python3) [problem no]
"
    exit
}

function check_param()
{
    if ! [[ "${PARAM}" =~ ^[0-9]+$ ]]; then
        echo "parameter $1 is not digit."
        usage
    fi
}
RANGE_S=`echo "${PARAM}/1000*1000" | bc`
RANGE_E=`echo "${RANGE_S} + 999" | bc`
RANGE=`printf "%06d_%06d" ${RANGE_S} ${RANGE_E}`

[ -d "${WORK_PATH}/${RANGE}" ] || mkdir -p "${WORK_PATH}/${RANGE}"

case ${TYPE} in
    [Cc])
		echo "Copy Templates..."
		[ -d "${WORK_PATH}/${RANGE}/${PARAM}" ] || cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${RANGE}/${PARAM}"

        echo "code"
	/home/ajava/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.5744.254/bin/clion.sh "${WORK_PATH}/${RANGE}/${PARAM}"
        ;;

    [Cc][Pp][Pp])

		echo "Copy Templates..."
		VENV="/work/github/gaolious/algorithm/template/acmicpc/pythonProject/.venv/bin/python"
		PYTHON_SCRIPT="/work/github/gaolious/algorithm/template/acmicpc/pythonProject/acmicpc_samples.py"

		if [[ ! -d "${WORK_PATH}/${RANGE}/${PARAM}" ]]; then
			cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${RANGE}/${PARAM}"
			${VENV} ${PYTHON_SCRIPT} ${PARAM} ${WORK_PATH}/${RANGE}/${PARAM}/input.txt
		fi

        if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	        ${CLION} "${WORK_PATH}/${RANGE}/${PARAM}"
            
        elif [[ "$OSTYPE" == "darwin"* ]]; then
            # open -na "CLion.app" --args "${WORK_PATH}/${RANGE}/${PARAM}"
            
            "${CLION}" "${WORK_PATH}/${RANGE}/${PARAM}" &
 
        fi

        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]2)

		echo "Copy Templates..."
		[ -d "${WORK_PATH}/${RANGE}/${PARAM}" ] || cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${RANGE}/${PARAM}"

        echo "code"
        /snap/bin/code "${WORK_PATH}/${RANGE}/${PARAM}_py2" "${WORK_PATH}/${RANGE}/${PARAM}/src/src.py"

        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]3)
		[ -d "${WORK_PATH}/${RANGE}/${PARAM}" ] || cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${RANGE}/${PARAM}"
		echo "Copy Templates..."

        echo "Generate readme.md"
        gen_python3_readme

        echo "code"
        /snap/bin/code "${WORK_PATH}/${RANGE}/${PARAM}_py3" "${WORK_PATH}/${RANGE}/${PARAM}/src/src.py"


        ;;
    *)
        echo "unknown type : ${TYPE}"
        exit
        ;;
esac

