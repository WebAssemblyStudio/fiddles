export function NOP(opcode: u32): u8 {
  switch (opcode) {
    case 0x1C:
    case 0x3C:
    case 0x5C:
    case 0x7C:
    case 0xDC:
    case 0xFC:
      return 1;
  }
  return 0;
}

export function NOP2(opcode: u32): u8 {
  let t = rotr<u32>(opcode - 28, 32 - 28 + 1);
  if (t > 7) return 0;
  let res = <u64>72339069031481601 >> (<u64>t << 3);
  return <u8><u32>res;
}
