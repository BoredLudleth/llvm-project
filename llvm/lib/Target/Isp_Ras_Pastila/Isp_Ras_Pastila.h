#ifndef LLVM_LIB_TARGET_Isp_Ras_Pastila_Isp_Ras_Pastila_H
#define LLVM_LIB_TARGET_Isp_Ras_Pastila_Isp_Ras_Pastila_H

#include "MCTargetDesc/Isp_Ras_PastilaMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define ISP_RAS_PASTILA_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ISP_RAS_PASTILA_DUMP(Color) {}

#define ISP_RAS_PASTILA_DUMP_RED ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::RED)
#define ISP_RAS_PASTILA_DUMP_GREEN ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::GREEN)
#define ISP_RAS_PASTILA_DUMP_YELLOW ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::YELLOW)
#define ISP_RAS_PASTILA_DUMP_CYAN ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::CYAN)
#define ISP_RAS_PASTILA_DUMP_MAGENTA ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::MAGENTA)
#define ISP_RAS_PASTILA_DUMP_WHITE ISP_RAS_PASTILA_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class Isp_Ras_PastilaTargetMachine;
class FunctionPass;
class Isp_Ras_PastilaSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerIsp_Ras_PastilaMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerIsp_Ras_PastilaMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createIsp_Ras_PastilaISelDag(Isp_Ras_PastilaTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Isp_Ras_Pastila_Isp_Ras_Pastila_H