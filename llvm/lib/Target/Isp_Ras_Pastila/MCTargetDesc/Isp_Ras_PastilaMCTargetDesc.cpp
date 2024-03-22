#include "MCTargetDesc/Isp_Ras_PastilaInfo.h"
#include "Isp_Ras_Pastila.h"
#include "Isp_Ras_PastilaInstPrinter.h"
#include "Isp_Ras_PastilaMCAsmInfo.h"
#include "TargetInfo/Isp_Ras_PastilaTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "Isp_Ras_PastilaGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "Isp_Ras_PastilaGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "Isp_Ras_PastilaGenSubtargetInfo.inc"

static MCRegisterInfo *createIsp_Ras_PastilaMCRegisterInfo(const Triple &TT) {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitIsp_Ras_PastilaMCRegisterInfo(X, Isp_Ras_Pastila::R0);
  return X;
}

static MCInstrInfo *createIsp_Ras_PastilaMCInstrInfo() {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitIsp_Ras_PastilaMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createIsp_Ras_PastilaMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  return createIsp_Ras_PastilaMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createIsp_Ras_PastilaMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  MCAsmInfo *MAI = new Isp_Ras_PastilaELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Isp_Ras_Pastila::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createIsp_Ras_PastilaMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  return new Isp_Ras_PastilaInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIsp_Ras_PastilaTargetMC() {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  Target &TheIsp_Ras_PastilaTarget = getTheIsp_Ras_PastilaTarget();
  RegisterMCAsmInfoFn X(TheIsp_Ras_PastilaTarget, createIsp_Ras_PastilaMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheIsp_Ras_PastilaTarget, createIsp_Ras_PastilaMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheIsp_Ras_PastilaTarget, createIsp_Ras_PastilaMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheIsp_Ras_PastilaTarget,
                                          createIsp_Ras_PastilaMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheIsp_Ras_PastilaTarget, createIsp_Ras_PastilaMCInstPrinter);
}
