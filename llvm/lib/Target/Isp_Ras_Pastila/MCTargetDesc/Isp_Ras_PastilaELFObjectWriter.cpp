#include "MCTargetDesc/Isp_Ras_PastilaMCTargetDesc.h"
#include "Isp_Ras_Pastila.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class Isp_Ras_PastilaELFObjectWriter : public MCELFObjectTargetWriter {
public:
  Isp_Ras_PastilaELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_ISP_RAS_PASTILA,
                                /*HasRelocationAddend*/ true) {}

  ~Isp_Ras_PastilaELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned Isp_Ras_PastilaELFObjectWriter::getRelocType(MCContext &Ctx, const MCValue &Target,
                                          const MCFixup &Fixup,
                                          bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool Isp_Ras_PastilaELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                 const MCSymbol &,
                                                 unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createIsp_Ras_PastilaELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<Isp_Ras_PastilaELFObjectWriter>(Is64Bit, OSABI);
}