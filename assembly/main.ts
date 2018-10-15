import "allocator/tlsf";
import {
  HEADER_SIZE,
  MAX_LENGTH,
  allocateUnsafe,
  compareUnsafe,
  repeatUnsafe,
  copyUnsafe,
  isWhiteSpaceOrLineTerminator,
  CharCode,
  parse
} from "internal/string";

import {
  storeUnsafe as storeUnsafeArray
} from "internal/arraybuffer";

declare function logi(value: i32): void;

function split(str: String, separator: String = null, limit: i32 = i32.MAX_VALUE): String[] {
  assert(str !== null);
  if (!limit) return new Array<String>();
  if (separator === null) return <String[]>[str];
  var length: isize = str.length;
  var sepLen: isize = separator.length;
  if (limit < 0) limit = i32.MAX_VALUE;
  if (!sepLen) {
    if (!length) return new Array<String>();
    // split by chars
    length = min<isize>(length, <isize>limit);
    let result = new Array<String>(length);
    let buffer = <ArrayBuffer>result.buffer_;
    for (let i: isize = 0; i < length; ++i) {
      let char = allocateUnsafe(1);
      store<u16>(
        changetype<usize>(char),
        load<u16>(
          changetype<usize>(str) + (<usize>i << 1),
          HEADER_SIZE
        ),
        HEADER_SIZE
      );
      storeUnsafeArray<String,String>(buffer, i, char);
    }
    return result;
  } else if (!length) {
    return <String[]>[changetype<String>("")];
  }
  var result = new Array<String>();
  var end = 0, start = 0, i = 0;
  while ((end = str.indexOf(separator, start)) != -1) {
    let len = end - start;
    if (len > 0) {
      let out = allocateUnsafe(len);
      copyUnsafe(out, 0, str, start, len);
      result.push(out);
    } else {
      result.push(changetype<String>(""));
    }
    if (++i == limit) return result;
    start = end + sepLen;
  }
  if (!start) return <String[]>[str];
  var len = length - start;
  if (len > 0) {
    let out = allocateUnsafe(len);
    copyUnsafe(out, 0, str, start, len);
    result.push(out);
  } else {
    result.push(changetype<String>(""));
  }
  return result;
}

/*
const str = "a,b,c,"
var res = split(str, ",");
logi(<i32>(res.length == 4));
logi(<i32>(res[0] == "a"));
logi(<i32>(res[1] == "b"));
logi(<i32>(res[2] == "c"));
logi(<i32>(res[3] == ""));

var sa = split("a,b,c,", ",");
assert(sa.length == 4 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c" && sa[3] == "");
*/

var str: string = "hi, I'm a string";
var nullStr: string;

// exactly once in static memory
assert(changetype<usize>(str) == changetype<usize>("hi, I'm a string"));

assert(str.length == 16);
assert(str.charCodeAt(0) == 0x68);

assert(String.fromCharCode(0) == "\0");
assert(String.fromCharCode(54) == "6");
assert(String.fromCharCode(0x10000 + 54) == "6");

assert(String.fromCodePoint(0) == "\0");
assert(String.fromCodePoint(54) == "6");
assert(String.fromCodePoint(0x1D306), "\uD834\uDF06");

assert(str.startsWith("hi"));
assert(str.endsWith("string"));
assert(str.includes("I'm"));

assert(str.padStart(0) == str);
assert(str.padStart(15) == str);
assert("".padStart(3) == "   ");
assert("".padStart(10, "") == "");
assert("a".padStart(100, "") == "a");
assert("abc".padStart(5) == "  abc");
assert("abc".padStart(6, "123") == "123abc");
assert("abc".padStart(8, "123") == "12312abc");

assert(str.padEnd(0) == str);
assert(str.padEnd(15) == str);
assert("".padEnd(3) == "   ");
assert("".padEnd(10, "") == "");
assert("a".padEnd(100, "") == "a");
assert("abc".padEnd(5) == "abc  ");
assert("abc".padEnd(6, "abc") == "abcabc");
assert("abc".padEnd(8, "abc") == "abcabcab");

assert("".indexOf("") == 0);
assert("".indexOf("hi") == -1);
assert(str.indexOf("") == 0);
assert(str.indexOf(",") == 2);
assert(str.indexOf("x") == -1);
assert(str.indexOf(",", 2) == 2);
assert(str.indexOf(",", 3) == -1);
assert(str.indexOf(", I", -1) == 2);

assert("".lastIndexOf("") == 0);
assert("".lastIndexOf("hi") == -1);
assert(str.lastIndexOf("") == str.length);
assert(str.lastIndexOf(",") == 2);
assert(str.lastIndexOf("x") == -1);
assert(str.lastIndexOf("g") == 15);
assert(str.lastIndexOf(",", 2) == 2);
assert(str.lastIndexOf(",", 3) == 2);
assert(str.lastIndexOf(", I", -1) == -1);
assert(str.lastIndexOf("i", 0) == -1);
assert(str.lastIndexOf("hi", 0) == 0);

export function getString(): string {
  return str;
}

assert(parseInt("0") == 0);
assert(parseInt("1") == 1);
assert(parseInt("0b101") == 0b101);
assert(parseInt("0o707") == 0o707);
assert(parseInt("0xf0f") == 0xf0f);
assert(parseInt("0xF0F") == 0xf0f);
assert(parseInt("011") == 11); // not octal
assert(parseInt("0x1g") == 1); // not valid

assert(parseFloat("0") == 0);
assert(parseFloat("1") == 1);
assert(parseFloat("0.1") == 0.1);
assert(parseFloat(".25") == 0.25);
assert(parseFloat(".1foobar") == 0.1);

var c = "a" + "b";
assert(c == "ab");
assert(c != "a");
assert("" == "");
assert("" != nullStr);

assert("b" > "a");
assert("ba" > "a");
assert("ba" >= "aa");
assert("ba" > "ab");
assert(!("ba" < "ab"));

assert(!("b" < nullStr));
assert(!(nullStr < "b"));

assert("abc" > "");
assert("" < "abc");
assert("abc" >= "");
assert("" <= "abc");
assert(!("abc" < ""));
assert(!("" > "abc"));
assert(!("" < ""));
assert(!("" > ""));
assert("" >= "");
assert("" <= "");

var a = String.fromCodePoint(0xFF61);
var b = String.fromCodePoint(0xD800) + String.fromCodePoint(0xDC02);
assert(a > b);

assert("123".length == 3);

assert("".repeat(100) == "");
assert("a".repeat() == "");
assert("a".repeat(1) == "a");
assert("a".repeat(2) == "aa");
assert("a".repeat(3) == "aaa");
assert("ab".repeat(4) == "abababab");
assert("a".repeat(5) == "aaaaa");
assert("a".repeat(6) == "aaaaaa");
assert("a".repeat(7) == "aaaaaaa");

var sa = split("");
assert(sa.length == 1 && sa[0] == "");
sa = split("", "");
assert(sa.length == 0);
sa = split("", ",");
assert(sa.length == 1 && sa[0] == "");
sa = split("a,b,c", ".");
assert(sa.length == 1 && sa[0] == "a,b,c");
sa = split("a,b,c", ",");
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");
sa = split("a, b, c", ", ");
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");
sa = split("a,b,,c", ",");
assert(sa.length == 4 && sa[0] == "a" && sa[1] == "b" && sa[2] == "" && sa[3] == "c");
sa = split(",a,b,c", ",");
assert(sa.length == 4 && sa[0] == "" && sa[1] == "a" && sa[2] == "b" && sa[3] == "c");
sa = split("a,b,c,", ",");
assert(sa.length == 4 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c" && sa[3] == "");
sa = split("abc", "");
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");
sa = split("abc", "", 0);
assert(sa.length == 0);
sa = split("abc", "", 1);
assert(sa.length == 1 && sa[0] == "a");
sa = split("a,b,c", ",", 1);
assert(sa.length == 1 && sa[0] == "a");
sa = split("abc", "", 4);
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");
sa = split("abc", "", -1);
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");
sa = split("a,b,c", ",", -1);
assert(sa.length == 3 && sa[0] == "a" && sa[1] == "b" && sa[2] == "c");