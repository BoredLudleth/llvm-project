#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H

// Defines symbolic names for Isp_Ras_Pastila registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "Isp_Ras_PastilaGenRegisterInfo.inc"

// Defines symbolic names for the Isp_Ras_Pastila instructions.
#define GET_INSTRINFO_ENUM
#include "Isp_Ras_PastilaGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H
