
export function rev8(x: u32): u32 {
  return (<u32>(((<u64>(x & 0xFF) * 0x80200802) & 0x0884422110) * 0x0101010101 >> 32)) & 0xFF;
}

// // fastest!
// export function rev8a(x: u32): u32 {
//   x &= 0xFF;
//   return (((x * 0x0802 & 0x22110) | (x * 0x8020 & 0x88440)) * 0x10101 >> 16) & 0xFF;
// }

// export function rev8b(b: u32): u32 {
//   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
//   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
//   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
//   return b;
// }
