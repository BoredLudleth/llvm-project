add_llvm_component_library(LLVMIsp_Ras_PastilaDesc
  Isp_Ras_PastilaMCTargetDesc.cpp
  Isp_Ras_PastilaMCAsmInfo.cpp
  Isp_Ras_PastilaInstPrinter.cpp
  Isp_Ras_PastilaMCCodeEmitter.cpp
  Isp_Ras_PastilaAsmBackend.cpp
  Isp_Ras_PastilaELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  Isp_Ras_PastilaInfo

  ADD_TO_COMPONENT
  Isp_Ras_Pastila
 )
