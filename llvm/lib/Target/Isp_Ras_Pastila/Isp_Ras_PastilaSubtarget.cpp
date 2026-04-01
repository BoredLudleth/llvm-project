#include "Isp_Ras_PastilaSubtarget.h"
#include "Isp_Ras_Pastila.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "isp_Ras_Pastila-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "Isp_Ras_PastilaGenSubtargetInfo.inc"

Isp_Ras_PastilaSubtarget::Isp_Ras_PastilaSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : Isp_Ras_PastilaGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {
  ISP_RAS_PASTILA_DUMP_CYAN
}