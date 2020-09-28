#!/bin/bash


UVA_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
TEMPLATE_PATH="$( cd "${UVA_PATH}"; cd ../template; pwd -P )"

cd "${HOME_PATH}"

PARAM=$1

function clean()
{
    PATHS=(bin obj input output src)
    pushd "${HOME_PATH}" > /dev/null 2>&1 || exit
        for p in "${PATHS[@]}"
        do
            rm -rf ${p}
        done
        rm -rf ./Makefile
    popd > /dev/null 2>&1 
}

function copy_template()
{
    PATHS=(bin obj input output src)

    pushd "${UVA_PATH}" > /dev/null 2>&1 || exit
        mkdir "${PARAM}"
        pushd "${PARAM}" > /dev/null 2>&1 || exit
        
            for p in "${PATHS[@]}"
            do
                mkdir ${p}
            done

            cp -rf "${HOME_PATH}/template/Makefile.uva" "${UVA_PATH}/${PARAM}/Makefile"
            cp -rf "${HOME_PATH}/template/src.cpp.uva" "${UVA_PATH}/${PARAM}/src/${PARAM}.cpp"
            cp -rf "${HOME_PATH}/template/vscode" "${UVA_PATH}/${PARAM}/.vscode"
        popd > /dev/null 2>&1
    popd > /dev/null 2>&1
}
function gen_uva_readme()
{
    pushd "${UVA_PATH}/${PARAM}" > /dev/null 2>&1 || exit
        echo """
## UVA - ${PARAM}

### Problem        
    PDF :  https://onlinejudge.org/external/1/${PARAM}.pdf       

### Compile
""" > ./readme.md
    popd > /dev/null 2>&1
}

if ! [[ "${PARAM}" =~ ^[0-9]+$ ]]; then
    echo "parameter $1 is not digit."
    exit
fi

if [[ -d "${UVA_PATH}/${PARAM}" ]]; then 
    echo "path ${UVA_PATH}/${PARAM} is exist."; 
    exit;
fi

echo "Copy Templates..."
copy_template

echo "Generate readme.md"
gen_uva_readme

echo "code"
/usr/bin/code ${UVA_PATH}/${PARAM}
