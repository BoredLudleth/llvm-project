#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMTARGETMACHINE_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMTARGETMACHINE_H

#include "Isp_Ras_PastilaSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheIsp_Ras_PastilaTarget;

class Isp_Ras_PastilaTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  Isp_Ras_PastilaSubtarget Subtarget;

public:
  Isp_Ras_PastilaTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const Isp_Ras_PastilaSubtarget *getSubtargetImpl(const Function &) const override {
    ISP_RAS_PASTILA_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMTARGETMACHINE_H
