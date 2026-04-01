include "llvm/Target/Target.td"
include "Isp_Ras_PastilaRegisterInfo.td"
include "Isp_Ras_PastilaInstrInfo.td"
include "Isp_Ras_PastilaCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def Isp_Ras_PastilaInstrInfo : InstrInfo;
def Isp_Ras_Pastila : Target {
  let InstructionSet = Isp_Ras_PastilaInstrInfo;
}
