#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createIsp_Ras_PastilaMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createIsp_Ras_PastilaAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                              const MCRegisterInfo &MRI,
                                              const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createIsp_Ras_PastilaELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for Isp_Ras_Pastila registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "Isp_Ras_PastilaGenRegisterInfo.inc"

// Defines symbolic names for the Isp_Ras_Pastila instructions.
#define GET_INSTRINFO_ENUM
#include "Isp_Ras_PastilaGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCTARGETDESC_H
