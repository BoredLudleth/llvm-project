#include "TargetInfo/Isp_Ras_PastilaTargetInfo.h"
#include "Isp_Ras_Pastila.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheIsp_Ras_PastilaTarget() {
  ISP_RAS_PASTILA_DUMP_YELLOW
  static Target TheIsp_Ras_PastilaTarget;
  return TheIsp_Ras_PastilaTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIsp_Ras_PastilaTargetInfo() {
  ISP_RAS_PASTILA_DUMP_YELLOW
  RegisterTarget<Triple::isp_ras_pastila> X(getTheIsp_Ras_PastilaTarget(), "isp_ras_pastila",
                                "Simulator target for LLVM course", "isp_ras_pastila");
}
