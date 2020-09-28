#!/bin/bash


UVA_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
cd "${UVA_PATH}"

TEMPLATE_PATH="$( cd "${UVA_PATH}"; cd ../code_template; pwd -P )"

UVA_EXTERNAL_PREFIX="https://onlinejudge.org/external/1"

cd "${HOME_PATH}"

PARAM=$1

function gen_uva_readme()
{
    pushd "${UVA_PATH}/${PARAM}" > /dev/null 2>&1 || exit
    echo " 
## UVA - ${PARAM}

### Problem        
    PDF :  ${UVA_EXTERNAL_PREFIX}/1/${PARAM}.pdf       

### Compile
\`\`\`bash
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

if [[ -d "${UVA_PATH}/${PARAM}" ]]; then 
    echo "path ${UVA_PATH}/${PARAM} is exist."; 
    exit;
fi

echo "Copy Templates..."
cp -rf "${TEMPLATE_PATH}" "${UVA_PATH}/${PARAM}"

echo "Generate readme.md"
gen_uva_readme

echo "code"
/usr/bin/code ${UVA_PATH}/${PARAM}
