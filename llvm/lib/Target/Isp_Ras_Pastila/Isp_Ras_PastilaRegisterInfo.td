// Isp_Ras_Pastila Register file declaration
class Isp_Ras_PastilaReg<bits<16> Enc, string n> : Register<n>{
    let HWEncoding = Enc;
    let Namespace = "Isp_Ras_Pastila";
}

// Registers
foreach I = 0-15 in {
    def R#I : Isp_Ras_PastilaReg<I, "r"#I>;
}

// Classes
def GPR : RegisterClass<"Isp_Ras_Pastila", [i32], 32, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15)>;
  