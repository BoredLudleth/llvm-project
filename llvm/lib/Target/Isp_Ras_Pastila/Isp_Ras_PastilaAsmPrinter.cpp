#include "MCTargetDesc/Isp_Ras_PastilaInstPrinter.h"
#include "Isp_Ras_Pastila.h"
#include "Isp_Ras_PastilaSubtarget.h"
#include "Isp_Ras_PastilaTargetMachine.h"
#include "TargetInfo/Isp_Ras_PastilaTargetInfo.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class Isp_Ras_PastilaAsmPrinter : public AsmPrinter {
  const MCSubtargetInfo *STI;

public:
  explicit Isp_Ras_PastilaAsmPrinter(TargetMachine &TM,
                         std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    ISP_RAS_PASTILA_DUMP_GREEN
  }

  void emitInstruction(const MachineInstr *MI) override;

  StringRef getPassName() const override { return "Isp_Ras_Pastila Assembly Printer"; }

  bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);

  // Used in pseudo lowerings
  bool lowerOperand(const MachineOperand &MO, MCOperand &MCOp) const {
    return LowerIsp_Ras_PastilaMachineOperandToMCOperand(MO, MCOp, *this);
  }
};

} // end anonymous namespace

// Isp_Ras_Pastilaple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "Isp_Ras_PastilaGenMCPseudoLowering.inc"

void Isp_Ras_PastilaAsmPrinter::emitInstruction(const MachineInstr *MI) {
  ISP_RAS_PASTILA_DUMP_GREEN
  // Do any auto-generated pseudo lowerings.
  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }

  MCInst TmpInst;
  if (!lowerIsp_Ras_PastilaMachineInstrToMCInst(MI, TmpInst, *this))
    EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIsp_Ras_PastilaAsmPrinter() {
  RegisterAsmPrinter<Isp_Ras_PastilaAsmPrinter> X(getTheIsp_Ras_PastilaTarget());
}
