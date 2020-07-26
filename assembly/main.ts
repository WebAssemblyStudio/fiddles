class Type {
  rd: u32
  rs1: u32
  imm: u32
}

export function extractIType(instruction: u32): Type {
  const rd = 1;
  const rs1 = 2;
  const imm = 3;
  return { rd, rs1, imm } as Type;
}
