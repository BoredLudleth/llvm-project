#include "Isp_Ras_PastilaMCAsmInfo.h"
#include "Isp_Ras_Pastila.h"

using namespace llvm;

Isp_Ras_PastilaELFMCAsmInfo::Isp_Ras_PastilaELFMCAsmInfo(const Triple &TT) {
  ISP_RAS_PASTILA_DUMP_MAGENTA
  SupportsDebugInformation = false;
  Data16bitsDirective = "\t.short\t";
  Data32bitsDirective = "\t.word\t";
  Data64bitsDirective = nullptr;
  ZeroDirective = "\t.space\t";
  CommentString = ";";

  UsesELFSectionDirectiveForBSS = false;
  AllowAtInName = true;
  HiddenVisibilityAttr = MCSA_Invalid;
  HiddenDeclarationVisibilityAttr = MCSA_Invalid;
  ProtectedVisibilityAttr = MCSA_Invalid;

  ExceptionsType = ExceptionHandling::None;
}