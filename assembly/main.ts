import { loadUnsafe } from "internal/arraybuffer";

declare function log(value: i32): void;

@inline
function getPowers10Table(): u32[] {
  return <u32[]>[
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
  ];
}

function decimalCount<T>(value: T): i32 {
  // make value abs
  var sign = value >> (8 * sizeof<T>() - 1);
  var v = (value ^ sign) - sign;

  if (ASC_SHRINK_LEVEL >= 1) {
    if (sizeof<T>() <= 4) {
      if (v < 100000) {
        return select<T>(
          v < 10   ? 1 : 2,
          v < 1000 ? 3 : (v < 10000 ? 4 : 5),
          v < 100
        );
      } else {
        return select<T>(
          v < 1000000   ? 6 : 7,
          v < 100000000 ? 8 : (v < 1000000000 ? 9 : 10),
          v < 10000000
        );
      }
    } else {
      let t = 1;
      if (v >= 10000000000000000) {
        t += 16;
        v /= 10000000000000000;
      }
      if (v >= 100000000) {
        t += 8;
        v /= 100000000;
      }
      if (v >= 10000) {
        t += 4;
        v /= 10000;
      }
      if (v >= 100) {
        t += 2;
        v /= 100;
      }
      if (v >= 10) t++;
      return t;
    }
  } else {

    var l = 8 * sizeof<T>() - <i32>clz<T>(v | 10); // log2
    var t = l * 1233 >>> 12;                       // log10

    var lutbuf = changetype<ArrayBuffer>(getPowers10Table().buffer_);
    if (sizeof<T>() <= 4) {
      let power  = loadUnsafe<u32,T>(lutbuf, t);
      t -= <i32>(v < power);
    } else { // sizeof<T>() == 8
      let le10   = t <= 10;
      let offset = select<i32>(0,          10, le10); // offset = t <= 10 ? 0 : 10
      let factor = select< T >(1, 10000000000, le10); // factor = t <= 10 ? 1 : 10 ^ 10
      let power  = loadUnsafe<u32,T>(lutbuf, t - offset);
      t -= <i32>(v < factor * power);
    }

    return t + 1;
  }
}

log(decimalCount<u32>(10000));
