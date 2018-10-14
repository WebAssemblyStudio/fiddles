import "allocator/arena";
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

const str = "a,b,c,"
var res = split(str, ",");
logi(<i32>(res.length == 4));
logi(<i32>(res[0] == "a"));
logi(<i32>(res[1] == "b"));
logi(<i32>(res[2] == "c"));
logi(<i32>(res[3] == ""));