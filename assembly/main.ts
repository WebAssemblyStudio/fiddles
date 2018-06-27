declare function log(val: i32): void;

const BUFFER_HEADER_SIZE = 8;

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
  var l = 8 * sizeof<T>() - <u32>clz<T>(v | 10); // log2
  var t = l * 1233 >>> 12;                      // log10
  var power: T;
  var ptr = changetype<usize>(powers10.buffer_);
  if (sizeof<T>() <= 4) {
    power = <T>load<u32>(ptr + (t << 2), BUFFER_HEADER_SIZE);
    t = t - <i32>(v < power);
  } else { // sizeof<T>() == 8
    let le10   = t <= 10;
    let offset = select<i32>(0, 10, le10);        // offset = t <= 10 ? 0 : 10
    let factor = select<T>(1, 10000000000, le10); // factor = t <= 10 ? 1 : 10 ^ 10
    power = <T>load<u32>(ptr + ((t - offset) << 2), BUFFER_HEADER_SIZE);
    t = t - <i32>(v < factor * power);
  }

  return <i32>(t + 1);
}

log(decimalCount<i32>(-9999));