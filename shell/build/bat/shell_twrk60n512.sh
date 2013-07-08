#!/bin/sh

# expect forward slash paths
MQXROOTDIR="${1}"
OUTPUTDIR="${2}"
TOOL="${3}"


# copy common files
mkdir -p "${OUTPUTDIR}"
cp -f "${MQXROOTDIR}/shell/source/include/sh_enet.h" "${OUTPUTDIR}/sh_enet.h"
cp -f "${MQXROOTDIR}/shell/source/include/sh_mfs.h" "${OUTPUTDIR}/sh_mfs.h"
cp -f "${MQXROOTDIR}/shell/source/include/sh_rtcs.h" "${OUTPUTDIR}/sh_rtcs.h"
cp -f "${MQXROOTDIR}/shell/source/include/shell.h" "${OUTPUTDIR}/shell.h"


# cw10 files
if [ "${TOOL}" = "cw10" ]; then
:
fi
# iar files
if [ "${TOOL}" = "iar" ]; then
:
fi
# cw10gcc files
if [ "${TOOL}" = "cw10gcc" ]; then
:
fi
# uv4 files
if [ "${TOOL}" = "uv4" ]; then
:
fi

