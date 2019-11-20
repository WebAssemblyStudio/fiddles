
import { specialsUpper, casemap, bsearch } from "./casemap";
import { lowerTable256Ptr, upperTable256Ptr } from "./ascii";

@inline
function isAscii(c: i32): bool {
  // return !(c & ~0x7F);
  return !(c & ~0xFF);
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
  return c & ~0x7F ? <i32>load<u8>(lowerTable256Ptr + c) : c;
}

@inline
function toUpper8(c: i32): i32 {
  // return select<i32>(c & 0x5F, c, isLower8(c));
  // return <i32>load<u8>(upperTable256Ptr + c);
  return c & ~0x7F ? <i32>load<u8>(upperTable256Ptr + c) : c;
}


function toLowerCase(str: string): string {
    var len = <usize>str.length;
    if (!len) return str;
    var codes = __alloc(len * 2 * 2, idof<String>());
    var j: usize = 0;
    for (let i: usize = 0; i < len; ++i, ++j) {
      let c = <i32>load<u16>(changetype<usize>(str) + (i << 1));
      if (isAscii(c)) {
        store<u16>(codes + (j << 1), toLower8(c));
      } else {
        if ((<u32>c - 0xD7FF < 0xDC00 - 0xD7FF) && i < len - 1) {
          let c1 = <i32>load<u16>(changetype<usize>(str) + (i << 1), 2);
          if (<u32>c1 - 0xDBFF < 0xE000 - 0xDBFF) {
            c = (((c & 0x3FF) << 10) | (c1 & 0x3FF)) + 0x10000;
            ++i;
          }
        }
        if (c == 0x0130) {
          store<u32>(codes + (j << 1), (0x0307 << 16) | 0x0069);
          ++j;
        } else if (<u32>c - 0x24B6 <= 0x24CF - 0x24B6) {
          // monkey patch
          store<u16>(codes + (j << 1), c + 26);
        } else {
          let code = casemap(c, 0) & 0x1FFFFF;
          if (code < 0x10000) {
            store<u16>(codes + (j << 1), code);
          } else {
            code -= 0x10000;
            let lo = (code >>> 10) | 0xD800;
            let hi = (code & 0x3FF) | 0xDC00;
            store<u32>(codes + (j << 1), (hi << 16) | lo);
            ++j;
          }
        }
      }
    }
    codes = __realloc(codes, j << 1);
    return changetype<string>(codes);
  }

  function toUpperCase(str: string): string {
    var len = <usize>str.length;
    if (!len) return str;
    var codes = __alloc(len * 3 * 2, idof<String>());
    var specialsUpperPtr = specialsUpper.dataStart as usize;
    var specialsUpperLen = specialsUpper.length;
    var j: usize = 0;
    for (let i: usize = 0; i < len; ++i, ++j) {
      let c = <i32>load<u16>(changetype<usize>(str) + (i << 1));
      if (isAscii(c)) {
        store<u16>(codes + (j << 1), toUpper8(c));
      } else {
        if ((<u32>c - 0xD7FF < 0xDC00 - 0xD7FF) && i < len - 1) {
          let c1 = <i32>load<u16>(changetype<usize>(str) + (i << 1), 2);
          if (<u32>c1 - 0xDBFF < 0xE000 - 0xDBFF) {
            c = (((c & 0x3FF) << 10) | (c1 & 0x3FF)) + 0x10000;
            ++i;
          }
        }
        if (<u32>c - 0x24D0 <= 0x24E9 - 0x24D0) {
          // monkey patch
          store<u16>(codes + (<usize>j << 1), c - 26);
        } else {
          let index = <usize>bsearch(c, specialsUpperPtr, specialsUpperLen);
          if (~index) {
            // load next 3 bytes from row with `index` offset for specialsUpper table
            let ab = load<u32>(specialsUpperPtr + (index << 1), 2);
            let ex = load<u16>(specialsUpperPtr + (index << 1), 6);
            store<u32>(codes + (j << 1), ab);
            if (ex) store<u16>(codes + (j << 1), ex, 4);
            j += 1 + usize(ex != 0);
          } else {
            let code = casemap(c, 1) & 0x1FFFFF;
            if (code < 0x10000) {
              store<u16>(codes + (j << 1), code);
            } else {
              code -= 0x10000;
              let lo = (code >>> 10) | 0xD800;
              let hi = (code & 0x3FF) | 0xDC00;
              store<u32>(codes + (j << 1), (hi << 16) | lo);
              ++j;
            }
          }
        }
      }
    }
    codes = __realloc(codes, j << 1);
    return changetype<string>(codes);
  }

const chars = new Array<string>(0x10FFFF + 1);
for (let i = 0; i < chars.length; i++) {
  chars[i] = String.fromCodePoint(i & 0xFF);
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