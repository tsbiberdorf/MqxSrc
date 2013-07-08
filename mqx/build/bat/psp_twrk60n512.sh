#!/bin/sh

# expect forward slash paths
MQXROOTDIR="${1}"
OUTPUTDIR="${2}"
TOOL="${3}"


# copy common files
mkdir -p "${OUTPUTDIR}"
cp -f "${MQXROOTDIR}/config/common/small_ram_config.h" "${OUTPUTDIR}/small_ram_config.h"
cp -f "${MQXROOTDIR}/mqx/source/include/charq.h" "${OUTPUTDIR}/charq.h"
cp -f "${MQXROOTDIR}/mqx/source/include/eds.h" "${OUTPUTDIR}/eds.h"
cp -f "${MQXROOTDIR}/mqx/source/include/edserial.h" "${OUTPUTDIR}/edserial.h"
cp -f "${MQXROOTDIR}/mqx/source/include/event.h" "${OUTPUTDIR}/event.h"
cp -f "${MQXROOTDIR}/mqx/source/include/fio.h" "${OUTPUTDIR}/fio.h"
cp -f "${MQXROOTDIR}/mqx/source/include/gen_rev.h" "${OUTPUTDIR}/gen_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/include/io.h" "${OUTPUTDIR}/io.h"
cp -f "${MQXROOTDIR}/mqx/source/include/io_rev.h" "${OUTPUTDIR}/io_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/include/ioctl.h" "${OUTPUTDIR}/ioctl.h"
cp -f "${MQXROOTDIR}/mqx/source/include/ipc.h" "${OUTPUTDIR}/ipc.h"
cp -f "${MQXROOTDIR}/mqx/source/include/ipc_pcb.h" "${OUTPUTDIR}/ipc_pcb.h"
cp -f "${MQXROOTDIR}/mqx/source/include/ipc_pcbv.h" "${OUTPUTDIR}/ipc_pcbv.h"
cp -f "${MQXROOTDIR}/mqx/source/include/klog.h" "${OUTPUTDIR}/klog.h"
cp -f "${MQXROOTDIR}/mqx/source/include/log.h" "${OUTPUTDIR}/log.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwevent.h" "${OUTPUTDIR}/lwevent.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwlog.h" "${OUTPUTDIR}/lwlog.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwmem.h" "${OUTPUTDIR}/lwmem.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwmsgq.h" "${OUTPUTDIR}/lwmsgq.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwsem.h" "${OUTPUTDIR}/lwsem.h"
cp -f "${MQXROOTDIR}/mqx/source/include/lwtimer.h" "${OUTPUTDIR}/lwtimer.h"
cp -f "${MQXROOTDIR}/mqx/source/include/message.h" "${OUTPUTDIR}/message.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mmu.h" "${OUTPUTDIR}/mmu.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx.h" "${OUTPUTDIR}/mqx.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_cnfg.h" "${OUTPUTDIR}/mqx_cnfg.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_cpudef.h" "${OUTPUTDIR}/mqx_cpudef.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_inc.h" "${OUTPUTDIR}/mqx_inc.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_ioc.h" "${OUTPUTDIR}/mqx_ioc.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_macros.h" "${OUTPUTDIR}/mqx_macros.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx_str.h" "${OUTPUTDIR}/mqx_str.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mutex.h" "${OUTPUTDIR}/mutex.h"
cp -f "${MQXROOTDIR}/mqx/source/include/name.h" "${OUTPUTDIR}/name.h"
cp -f "${MQXROOTDIR}/mqx/source/include/partition.h" "${OUTPUTDIR}/partition.h"
cp -f "${MQXROOTDIR}/mqx/source/include/pcb.h" "${OUTPUTDIR}/pcb.h"
cp -f "${MQXROOTDIR}/mqx/source/include/posix.h" "${OUTPUTDIR}/posix.h"
cp -f "${MQXROOTDIR}/mqx/source/include/queue.h" "${OUTPUTDIR}/queue.h"
cp -f "${MQXROOTDIR}/mqx/source/include/sem.h" "${OUTPUTDIR}/sem.h"
cp -f "${MQXROOTDIR}/mqx/source/include/timer.h" "${OUTPUTDIR}/timer.h"
cp -f "${MQXROOTDIR}/mqx/source/include/watchdog.h" "${OUTPUTDIR}/watchdog.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/cortex.h" "${OUTPUTDIR}/cortex.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/cpu/kinetis_fcan.h" "${OUTPUTDIR}/kinetis_fcan.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/cpu/MK60DZ10.h" "${OUTPUTDIR}/MK60DZ10.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/kinetis.h" "${OUTPUTDIR}/kinetis.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/kinetis_mpu.h" "${OUTPUTDIR}/kinetis_mpu.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/nvic.h" "${OUTPUTDIR}/nvic.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp.h" "${OUTPUTDIR}/psp.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_abi.h" "${OUTPUTDIR}/psp_abi.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_comp.h" "${OUTPUTDIR}/psp_comp.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_cpu.h" "${OUTPUTDIR}/psp_cpu.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_cpudef.h" "${OUTPUTDIR}/psp_cpudef.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_math.h" "${OUTPUTDIR}/psp_math.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_rev.h" "${OUTPUTDIR}/psp_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_supp.h" "${OUTPUTDIR}/psp_supp.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psp_time.h" "${OUTPUTDIR}/psp_time.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/psptypes.h" "${OUTPUTDIR}/psptypes.h"
cp -f "${MQXROOTDIR}/mqx/source/tad/tad.h" "${OUTPUTDIR}/tad.h"


# cw10 files
if [ "${TOOL}" = "cw10" ]; then
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/cw/asm_mac.h" "${OUTPUTDIR}/asm_mac.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/cw/comp.h" "${OUTPUTDIR}/comp.h"
fi
# iar files
if [ "${TOOL}" = "iar" ]; then
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/iar/asm_mac.h" "${OUTPUTDIR}/asm_mac.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/iar/comp.h" "${OUTPUTDIR}/comp.h"
fi
# cw10gcc files
if [ "${TOOL}" = "cw10gcc" ]; then
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/gcc_cw/asm_mac.h" "${OUTPUTDIR}/asm_mac.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/gcc_cw/comp.h" "${OUTPUTDIR}/comp.h"
fi
# uv4 files
if [ "${TOOL}" = "uv4" ]; then
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/rv/asm_mac.h" "${OUTPUTDIR}/asm_mac.h"
cp -f "${MQXROOTDIR}/mqx/source/psp/cortex_m/compiler/rv/comp.h" "${OUTPUTDIR}/comp.h"
fi

