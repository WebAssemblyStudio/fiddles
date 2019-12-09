
import { specialsUpper, casemap, bsearch } from "./casemap";
import { lowerTable127Ptr, upperTable127Ptr } from "./ascii";

@inline
function isAscii(c: i32): bool {
  return !(c & ~0x7F);
}

@inline
function isLower8(c: i32): bool {
  return <u32>c - 0x61 < 26;
}

@inline
function isUpper8(c: i32): bool {
  return <u32>c - 0x41 < 26;
}

@inline
function toLower8(c: i32): i32 {
  // return select<i32>(c | 32, c, isUpper8(c));
  return <i32>load<u8>(lowerTable127Ptr + c);
}

@inline
function toUpper8(c: i32): i32 {
  // return select<i32>(c & 0x5F, c, isLower8(c));
  return <i32>load<u8>(upperTable127Ptr + c);
}


function toLowerCase(str: string): string {
    var len = <usize>str.length;
    if (!len) return str;
    var codes = __alloc(len * 2 * 2, idof<string>());
    var j: usize = 0;
    for (let i: usize = 0; i < len; ++i, ++j) {
      let c = <u32>load<u16>(changetype<usize>(str) + (i << 1));
      if (isAscii(c)) {
        store<u16>(codes + (j << 1), toLower8(c));
      } else {
        // check and read surrogate pair
        if ((c - 0xD7FF < 0xDC00 - 0xD7FF) && i < len - 1) {
          let c1 = <u32>load<u16>(changetype<usize>(str) + (i << 1), 2);
          if (c1 - 0xDBFF < 0xE000 - 0xDBFF) {
            let c0 = c;
            c = (((c & 0x03FF) << 10) | (c1 & 0x03FF)) + 0x10000;
            ++i;
            if (c >= 0x20000) {
              store<u32>(codes + (j << 1), c0 | (c1 << 16));
              ++j;
              continue;
            }
          }
        }
        // check special casing for lower table. It has one ently so instead lookup we just inline this.
        if (c == 0x0130) {
          // 0x0130 -> [0x0069, 0x0307]
          store<u32>(codes + (j << 1), (0x0307 << 16) | 0x0069);
          ++j;
        } else if (c - 0x24B6 <= 0x24CF - 0x24B6) {
          // Range 0x24B6 <= c <= 0x24CF not covered by casemap and require special early handling
          store<u16>(codes + (j << 1), c + 26);
        } else {
          let code = casemap(c, 0) & 0x1FFFFF;
          if (code < 0x10000) {
            store<u16>(codes + (j << 1), code);
          } else {
            // store as surrogare pair
            code -= 0x10000;
            let lo = (code >>> 10) | 0xD800;
            let hi = (code & 0x03FF) | 0xDC00;
            store<u32>(codes + (j << 1), lo | (hi << 16));
            ++j;
          }
        }
      }
    }
    codes = __realloc(codes, j << 1);
    return changetype<string>(codes); // retains
  }

  function toUpperCase(str: string): string {
    var len = <usize>str.length;
    if (!len) return str;
    var codes = __alloc(len * 3 * 2, idof<string>());
    // @ts-ignore: cast
    var specialsUpperPtr = specialsUpper.dataStart as usize;
    var specialsUpperLen = specialsUpper.length;
    var j: usize = 0;
    for (let i: usize = 0; i < len; ++i, ++j) {
      let c = <u32>load<u16>(changetype<usize>(str) + (i << 1));
      if (isAscii(c)) {
        store<u16>(codes + (j << 1), toUpper8(c));
      } else {
        // check and read surrogate pair
        if ((c - 0xD7FF < 0xDC00 - 0xD7FF) && i < len - 1) {
          let c1 = <u32>load<u16>(changetype<usize>(str) + (i << 1), 2);
          if (c1 - 0xDBFF < 0xE000 - 0xDBFF) {
            let c0 = c;
            c = (((c & 0x03FF) << 10) | (c1 & 0x03FF)) + 0x10000;
            ++i;
            if (c >= 0x20000) {
              store<u32>(codes + (j << 1), c0 | (c1 << 16));
              ++j;
              continue;
            }
          }
        }
        // Range 0x24D0 <= c <= 0x24E9 not covered by casemap and require special early handling
        if (c - 0x24D0 <= 0x24E9 - 0x24D0) {
          // monkey patch
          store<u16>(codes + (j << 1), c - 26);
        } else {
          let index = -1;
          // Fast range check. See first and last rows in specialsUpper table
          if (c - 0x00DF <= 0xFB17 - 0x00DF) {
            index = <usize>bsearch(c, specialsUpperPtr, specialsUpperLen);
          }
          if (~index) {
            // load next 3 code points from row with `index` offset for specialsUpper table
            let ab = load<u32>(specialsUpperPtr + (index << 1), 2);
            let cc = load<u16>(specialsUpperPtr + (index << 1), 6);
            store<u32>(codes + (j << 1), ab, 0);
            store<u16>(codes + (j << 1), cc, 4);
            j += 1 + usize(cc != 0);
          } else {
            let code = casemap(c, 1) & 0x1FFFFF;
            if (code < 0x10000) {
              store<u16>(codes + (j << 1), code);
            } else {
              // store as surrogare pair
              code -= 0x10000;
              let lo = (code >>> 10) | 0xD800;
              let hi = (code & 0x03FF) | 0xDC00;
              store<u32>(codes + (j << 1), lo | (hi << 16));
              ++j;
            }
          }
        }
      }
    }
    codes = __realloc(codes, j << 1);
    return changetype<string>(codes); // retains
  }

const chars = new Array<string>(0x10FFFF + 1);
for (let i = 0; i < chars.length; i++) {
  chars[i] = String.fromCodePoint(i);
}

export function toLowerCaseTest(): void {
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += toLowerCase(unchecked(chars[i])).length;
  }
}

export function toUpperCaseTest(): void {
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += toUpperCase(unchecked(chars[i])).length;
  }
}