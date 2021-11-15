#!/bin/bash

HOME_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
WORK_PATH=`pwd -P`

CPP_TEMPLATE_PATH="$( cd "${HOME_PATH}"; cd ./clion_cpp_template; pwd -P )"
PYTHON_TEMPLATE_PATH="$( cd "${HOME_PATH}"; cd ./code_python_template; pwd -P )"

#SITE=$1
TYPE=$1
PARAM=$2

README_TITLE="BAEKJOON - {$PARAM}"
PROBLEM_URL="https://www.acmicpc.net/problem/${PARAM}"

function usage()
{
    echo "
Usages :         
    $ $0 (c|cpp|python2|python3) [problem no]
"
    exit
}

function gen_python2_readme()
{
    pushd "${WORK_PATH}/${PARAM}" > /dev/null 2>&1 || exit
    echo " 
## ${README_TITLE}

### Problem        
    url :  ${PROBLEM_URL}

### IDE 
\`\`\`bash
$ code --version
`code --version`
\`\`\`

### Compile
\`\`\`bash
$ python3 --version
`python3 --version`

$ make
\`\`\`

### run
\`\`\`bash
$ python 3 ./src/src.py < ./input/input.txt > ./output/output.txt
\`\`\`

" > ./readme.md

    popd > /dev/null 2>&1
}


function gen_python3_readme()
{
    pushd "${WORK_PATH}/${PARAM}" > /dev/null 2>&1 || exit
    echo " 
## ${README_TITLE}

### Problem        
    url :  ${PROBLEM_URL}

### IDE 
\`\`\`bash
$ code --version
`code --version`
\`\`\`

### Compile
\`\`\`bash
$ python3 --version
`python3 --version`

$ make
\`\`\`

### run
\`\`\`bash
$ python 3 ./src/src.py < ./input/input.txt > ./output/output.txt
\`\`\`

" > ./readme.md

    popd > /dev/null 2>&1
}


function gen_gcc_readme()
{
    pushd "${WORK_PATH}/${PARAM}" > /dev/null 2>&1 || exit
    echo " 
## ${README_TITLE}

### Problem        
    ${PROBLEM_URL}

### IDE 
\`\`\`bash
$ code --version
`code --version`
\`\`\`

### Compile
\`\`\`bash
$ g++ --version
`g++ --version`

$ make
\`\`\`

### run
\`\`\`bash
$ ./bin/UVA < ./input/input.txt > ./output/output.txt
\`\`\`

" > ./readme.md

    popd > /dev/null 2>&1
}

function check_param()
{
    if ! [[ "${PARAM}" =~ ^[0-9]+$ ]]; then
        echo "parameter $1 is not digit."
        usage
    fi
}

if [[ "${WORK_PATH}" == *"Baekjoon"* ]]; then
    README_TITLE="BAEJOON - ${PARAM}"
    PROBLEM_URL="url : https://www.acmicpc.net/problem/${PARAM}"
    check_param

elif [[ "${WORK_PATH}" == *"UVA"* ]]; then

    README_TITLE="UVA - ${PARAM}"
    SUBPATH=`echo "${PARAM}/100" | bc`
    SUBPATH=`printf "%03d" ${SUBPATH}`

    WORK_PATH="${HOME_PATH}/../UVA-Online/Volume_${SUBPATH}"
    [ -d "${WORK_PATH}" ] || mkdir -p "${WORK_PATH}"

    PROBLEM_URL="
- Problem PDF : https://onlinejudge.org/external/${SUBPATH}/${PARAM}.pdf
- udebug : https://www.udebug.com/UVa/${PARAM}
- vjudge : https://vjudge.net/problem/UVA-${PARAM}
"

    check_param
else
        README_TITLE="${PARAM}"
        PROBLEM_URL=""
fi

if [[ -d "${WORK_PATH}/${PARAM}" ]]; then 
    echo "path ${WORK_PATH}/${PARAM} is exist."; 
    usage
fi



case ${TYPE} in
    [Cc])
        echo "Copy Templates..."
        cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_gcc_readme

        echo "code"
        /usr/bin/code "${WORK_PATH}/${PARAM}" "${WORK_PATH}/${PARAM}/src/src.cpp"
        ;;

    [Cc][Pp][Pp])
        echo "Copy Templates..."
        cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_gcc_readme

        open -na "CLion.app" --args "${WORK_PATH}/${PARAM}"
        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]2)
        echo "Copy Templates..."
        cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_python3_readme

        echo "code"
        /usr/bin/code "${WORK_PATH}/${PARAM}" "${WORK_PATH}/${PARAM}/src/src.py"

        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]3)
        echo "Copy Templates..."
        cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_python3_readme

        echo "code"
        /usr/bin/code "${WORK_PATH}/${PARAM}" "${WORK_PATH}/${PARAM}/src/src.py"


        ;;
    *)
        echo "unknown type : ${TYPE}"
        exit
        ;;
esac

