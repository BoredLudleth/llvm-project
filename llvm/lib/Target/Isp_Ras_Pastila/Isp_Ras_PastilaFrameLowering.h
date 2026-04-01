#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMFRAMELOWERING_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMFRAMELOWERING_H

#include "Isp_Ras_Pastila.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class Isp_Ras_PastilaSubtarget;

class Isp_Ras_PastilaFrameLowering : public TargetFrameLowering {
public:
  Isp_Ras_PastilaFrameLowering(const Isp_Ras_PastilaSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
    ISP_RAS_PASTILA_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const Isp_Ras_PastilaSubtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMFRAMELOWERING_H