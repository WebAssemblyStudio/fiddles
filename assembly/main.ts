declare function log(v: i32): void;
declare function logf(v: f64): void;

const BUFFER_HEADER_SIZE = 8;

// 999868719476735

const powers10: u32[] = [
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

function decimalCount<T>(value: T): i32 {
  // make value abs
  var sign = value >> (8 * sizeof<T>() - 1);
  var v = (value ^ sign) - sign;
  var l = 8 * sizeof<T>() - <i32>clz<T>(v | 1); // log2
  var t = l * 1233 >>> 12;                      // log10

  var power: T;
  var ptr = changetype<usize>(powers10.buffer_);
  if (sizeof<T>() <= 4) {
    power = <T>load<u32>(ptr + (t << 2), BUFFER_HEADER_SIZE);
    t = t - <i32>(v < power);
  } else { // sizeof<T>() == 8
    let le10   = t <= 10;
    // let offset = (10 & -<i32>le10) ^ 10;          // offset = t <= 10 ? 0 : 10
    let offset = select<i32>(0, 10, le10);
    let factor = select<T>(1, 10000000000, le10); // factor = t <= 10 ? 1 : 10 ^ 10
    power = <T>load<u32>(ptr + ((t - offset) << 2), BUFFER_HEADER_SIZE);
    t = t - <i32>(v < factor * power);
  }

  return t + 1;
}

var t: u64 = -9223372036854775808;
log(decimalCount<u64>(t));

//  (data (i32.const 8) "\10\00\00\00\0a\00\00\00(\00\00\00\00\00\00\00\01\00\00\00\0a\00\00\00d\00\00\00\e8\03\00\00\10'\00\00\a0\86\01\00@B\0f\00\80\96\98\00\00\e1\f5\05\00\ca\9a;"))
//  (data (i32.const 8) "\10\00\00\00\0a\00\00\00(\00\00\00\00\00\00\00\01\ca\9a;\0a\ca\9a;d\ca\9a;\e8\c9\9a;\10\ed\9a;\a0L\9b;@\88\95;\80\5c\02;\00+o>"))
