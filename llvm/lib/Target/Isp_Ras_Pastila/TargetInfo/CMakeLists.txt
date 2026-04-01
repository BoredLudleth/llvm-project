add_llvm_component_library(LLVMIsp_Ras_PastilaInfo
  Isp_Ras_PastilaTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Isp_Ras_Pastila
  )
