#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMINSTRINFO_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMINSTRINFO_H

#include "Isp_Ras_PastilaRegisterInfo.h"
#include "MCTargetDesc/Isp_Ras_PastilaInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "Isp_Ras_PastilaGenInstrInfo.inc"

namespace llvm {

class Isp_Ras_PastilaSubtarget;

class Isp_Ras_PastilaInstrInfo : public Isp_Ras_PastilaGenInstrInfo {
public:
  Isp_Ras_PastilaInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMINSTRINFO_H
