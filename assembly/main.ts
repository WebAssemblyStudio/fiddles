// import { CharCode } from "util/string";

// 73
// export function isHex1(ch: u32): bool {
//   // @ts-ignore
//   return (ch - CharCode._0 < 10) | ((ch | 32) - CharCode.a < 6);
// }

// 78
// export function isHex2(ch: u32): bool {
//   return (ch - CharCode._0 < 10) || ((ch | 32) - CharCode.a < 6);
// }

export function test1(ch: i32): i32 {
  return ch == 0 ? 2 : 3;
}

export function test2(ch: i32): i32 {
  return i32(ch == 0) + 2;
}