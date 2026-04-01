#ifndef LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCASMINFO_H
#define LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class Isp_Ras_PastilaELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit Isp_Ras_PastilaELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISP_RAS_PASTILA_MCTARGETDESC_SIMMCASMINFO_H