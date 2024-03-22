#include "Isp_Ras_PastilaTargetMachine.h"
#include "Isp_Ras_Pastila.h"
#include "TargetInfo/Isp_Ras_PastilaTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIsp_Ras_PastilaTarget() {
  // Register the target.
  ISP_RAS_PASTILA_DUMP_CYAN
  RegisterTargetMachine<Isp_Ras_PastilaTargetMachine> A(getTheIsp_Ras_PastilaTarget());
}

Isp_Ras_PastilaTargetMachine::Isp_Ras_PastilaTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  ISP_RAS_PASTILA_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Isp_Ras_Pastila Code Generator Pass Configuration Options.
class Isp_Ras_PastilaPassConfig : public TargetPassConfig {
public:
  Isp_Ras_PastilaPassConfig(Isp_Ras_PastilaTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  Isp_Ras_PastilaTargetMachine &getIsp_Ras_PastilaTargetMachine() const {
    return getTM<Isp_Ras_PastilaTargetMachine>();
  }

  bool addInstSelector() override {
    ISP_RAS_PASTILA_DUMP_CYAN
    addPass(createIsp_Ras_PastilaISelDag(getIsp_Ras_PastilaTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *Isp_Ras_PastilaTargetMachine::createPassConfig(PassManagerBase &PM) {
  ISP_RAS_PASTILA_DUMP_CYAN
  return new Isp_Ras_PastilaPassConfig(*this, PM);
}

TargetLoweringObjectFile *Isp_Ras_PastilaTargetMachine::getObjFileLowering() const {
  ISP_RAS_PASTILA_DUMP_CYAN
  return TLOF.get();
}
