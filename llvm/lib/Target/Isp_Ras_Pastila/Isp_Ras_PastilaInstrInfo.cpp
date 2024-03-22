#include "Isp_Ras_PastilaInstrInfo.h"
#include "Isp_Ras_Pastila.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "Isp_Ras_PastilaGenInstrInfo.inc"

#define DEBUG_TYPE "Isp_Ras_Pastila-inst-info"

Isp_Ras_PastilaInstrInfo::Isp_Ras_PastilaInstrInfo() : Isp_Ras_PastilaGenInstrInfo() { ISP_RAS_PASTILA_DUMP_GREEN }
