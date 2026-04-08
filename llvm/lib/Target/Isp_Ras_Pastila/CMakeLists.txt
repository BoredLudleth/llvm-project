add_llvm_component_group(Isp_Ras_Pastila)

set(LLVM_TARGET_DEFINITIONS Isp_Ras_Pastila.td)

tablegen(LLVM Isp_Ras_PastilaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM Isp_Ras_PastilaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM Isp_Ras_PastilaGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM Isp_Ras_PastilaGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM Isp_Ras_PastilaGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM Isp_Ras_PastilaGenCallingConv.inc -gen-callingconv)
tablegen(LLVM Isp_Ras_PastilaGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM Isp_Ras_PastilaGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(Isp_Ras_PastilaCommonTableGen)

add_llvm_target(Isp_Ras_PastilaCodeGen
  Isp_Ras_PastilaTargetMachine.cpp
  Isp_Ras_PastilaRegisterInfo.cpp
  Isp_Ras_PastilaInstrInfo.cpp
  Isp_Ras_PastilaSubtarget.cpp
  Isp_Ras_PastilaAsmPrinter.cpp
  Isp_Ras_PastilaISelDagToDag.cpp
  Isp_Ras_PastilaISelLowering.cpp
  Isp_Ras_PastilaMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  Isp_Ras_PastilaInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Isp_Ras_Pastila
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
