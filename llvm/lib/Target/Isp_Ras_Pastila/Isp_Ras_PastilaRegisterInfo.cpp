#include "Isp_Ras_PastilaRegisterInfo.h"
#include "Isp_Ras_Pastila.h"
#include "Isp_Ras_PastilaFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "Isp_Ras_PastilaGenRegisterInfo.inc"

Isp_Ras_PastilaRegisterInfo::Isp_Ras_PastilaRegisterInfo() : Isp_Ras_PastilaGenRegisterInfo(Isp_Ras_Pastila::R0) {
  ISP_RAS_PASTILA_DUMP_GREEN
}
const MCPhysReg *
Isp_Ras_PastilaRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ISP_RAS_PASTILA_DUMP_GREEN
  return CSR_Isp_Ras_Pastila_SaveList;
}

BitVector Isp_Ras_PastilaRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ISP_RAS_PASTILA_DUMP_GREEN
  Isp_Ras_PastilaFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Isp_Ras_Pastila::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Isp_Ras_Pastila::R2);
  }
  return Reserved;
}

bool Isp_Ras_PastilaRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool Isp_Ras_PastilaRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  ISP_RAS_PASTILA_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register Isp_Ras_PastilaRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ISP_RAS_PASTILA_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Isp_Ras_Pastila::R2 : Isp_Ras_Pastila::R1;
}

const uint32_t *
Isp_Ras_PastilaRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  ISP_RAS_PASTILA_DUMP_GREEN
  return CSR_Isp_Ras_Pastila_RegMask;
}
