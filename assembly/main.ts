@lazy const URI_SAFE_PACKED = memory.data<u32>([
  ~0x00000000, // 0b00000000000000000000000000000000
  ~0x5BFFFFF5, // 0b01011011111111111111111111110101
  ~0xFFFFFFE1, // 0b11111111111111111111111111100001
  ~0x7FFFFFE2, // 0b01111111111111111111111111100010
]);

// @ts-ignore: decorator
@lazy const URI_SAFE_OPT = memory.data<u8>([
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0
]);

// @ts-ignore: decorator
@lazy const URI_SAFE_OPT_2 = memory.data<u8>([
     0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0
]);

// @ts-ignore: decorator
@lazy export const URI_SAFE = memory.data<u8>([
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1
]);

// 207 bytes (with URI_SAFE table)
// export function checkFullCurrent(ch: u32): bool {
//   if (ch < 0x7F) {
//     return !load<u8>(URI_SAFE + ch);
//   }
//   return false
// }

// 158 bytes (with URI_SAFE_OPT table)
// export function checkFullOpt(ch: u32): bool {
//   if (ch < 0x7F) {
//     return <bool>load<u8>(URI_SAFE_OPT + ch);
//   }
//   return false
// }

// 126 bytes (with URI_SAFE_OPT_2 table)
export function checkFullOpt2(ch: u32): bool {
  if ((ch - 33) < 0x7F) {
    return <bool>load<u8>(URI_SAFE_OPT_2 + (ch - 33));
  }
  return false
}

// 118 bytes (with URI_SAFE_PACKED table)
// export function checkPached(ch: u32): bool {
//   if (ch < 0x7F) {
//     return <bool>((load<u32>(URI_SAFE_PACKED + (((ch >>> 5) >>> ~ch)) << 2)) & 1);
//   }
//   return false
// }
