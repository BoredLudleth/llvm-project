#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMINFO_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace Isp_Ras_PastilaOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace Isp_Ras_PastilaOp

} // end namespace llvm

#endif
