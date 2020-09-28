#!/bin/bash


WORK_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
cd "${WORK_PATH}"

CPP_TEMPLATE_PATH="$( cd "${WORK_PATH}"; cd ./code_cpp_template; pwd -P )"
PYTHON_TEMPLATE_PATH="$( cd "${WORK_PATH}"; cd ./code_python_template; pwd -P )"

EXTERNAL_PREFIX="https://www.acmicpc.net/problem"

cd "${HOME_PATH}"

TYPE=$1
PARAM=$2

function gen_python3_readme()
{
    pushd "${WORK_PATH}/${PARAM}" > /dev/null 2>&1 || exit
    echo " 
## BAEJOON - ${PARAM}

### Problem        
    url :  ${EXTERNAL_PREFIX}/${PARAM}/

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
## BAEJOON - ${PARAM}

### Problem        
    url :  ${EXTERNAL_PREFIX}/${PARAM}/

### IDE 
\`\`\`bash
$ code --version
`code --version`
\`\`\`

### Compile
\`\`\`bash
$ gcc --version
`gcc --version`

$ make
\`\`\`

### run
\`\`\`bash
$ ./bin/UVA < ./input/input.txt > ./output/output.txt
\`\`\`

" > ./readme.md

    popd > /dev/null 2>&1
}

if ! [[ "${PARAM}" =~ ^[0-9]+$ ]]; then
    echo "parameter $1 is not digit."
    exit
fi

if [[ -d "${WORK_PATH}/${PARAM}" ]]; then 
    echo "path ${WORK_PATH}/${PARAM} is exist."; 
    exit;
fi

case ${TYPE} in
    [Cc])
        echo "Copy Templates..."
        cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_gcc_readme

        echo "code"
        /usr/bin/code ${WORK_PATH}/${PARAM} ${WORK_PATH}/${PARAM}/src/src.cpp
        ;;

    [Cc][Pp][Pp])
        echo "Copy Templates..."
        cp -rf "${CPP_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_gcc_readme

        echo "code"
        /usr/bin/code ${WORK_PATH}/${PARAM} ${WORK_PATH}/${PARAM}/src/src.cpp
        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]2)
        echo "Copy Templates..."
        cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_python3_readme

        echo "code"
        /usr/bin/code ${WORK_PATH}/${PARAM} ${WORK_PATH}/${PARAM}/src/src.py

        ;;

    [Pp][Yy][Tt][Hh][Oo][Nn]3)
        echo "Copy Templates..."
        cp -rf "${PYTHON_TEMPLATE_PATH}" "${WORK_PATH}/${PARAM}"

        echo "Generate readme.md"
        gen_python3_readme

        echo "code"
        /usr/bin/code ${WORK_PATH}/${PARAM} ${WORK_PATH}/${PARAM}/src/src.py


        ;;
    *)
        echo "unknown type : ${TYPE}"
        ;;
esac

