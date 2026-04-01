#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMISELLOWERING_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMISELLOWERING_H

#include "Isp_Ras_Pastila.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class Isp_Ras_PastilaSubtarget;
class Isp_Ras_PastilaTargetMachine;

namespace Isp_Ras_PastilaISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace Isp_Ras_PastilaISD

class Isp_Ras_PastilaTargetLowering : public TargetLowering {
public:
  explicit Isp_Ras_PastilaTargetLowering(const TargetMachine &TM, const Isp_Ras_PastilaSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  /// Return true if the addressing mode represented by AM is legal for this
  /// target, for a load/store of the specified type.
  bool isLegalAddressingMode(const DataLayout &DL, const AddrMode &AM, Type *Ty,
                             unsigned AS,
                             Instruction *I = nullptr) const override;

  Isp_Ras_PastilaSubtarget const &getSubtarget() const { return STI; }

private:
  const Isp_Ras_PastilaSubtarget &STI;

  void ReplaceNodeResults(SDNode *N, SmallVectorImpl<SDValue> &Results,
                          SelectionDAG &DAG) const override;

  SDValue PerformDAGCombine(SDNode *N, DAGCombinerInfo &DCI) const override;

  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               const SmallVectorImpl<ISD::InputArg> &Ins,
                               const SDLoc &DL, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerCall(TargetLowering::CallLoweringInfo &CLI,
                    SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
                      SelectionDAG &DAG) const override;

  bool CanLowerReturn(CallingConv::ID CallConv, MachineFunction &MF,
                      bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &ArgsFlags,
                      LLVMContext &Context, const Type *RetTy) const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_SIMISELLOWERING_H