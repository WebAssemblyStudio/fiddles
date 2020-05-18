declare function log(x: f64): void;

const HEX_DIGITS =
"000102030405060708090a0b0c0d0e0f\
101112131415161718191a1b1c1d1e1f\
202122232425262728292a2b2c2d2e2f\
303132333435363738393a3b3c3d3e3f\
404142434445464748494a4b4c4d4e4f\
505152535455565758595a5b5c5d5e5f\
606162636465666768696a6b6c6d6e6f\
707172737475767778797a7b7c7d7e7f\
808182838485868788898a8b8c8d8e8f\
909192939495969798999a9b9c9d9e9f\
a0a1a2a3a4a5a6a7a8a9aaabacadaeaf\
b0b1b2b3b4b5b6b7b8b9babbbcbdbebf\
c0c1c2c3c4c5c6c7c8c9cacbcccdcecf\
d0d1d2d3d4d5d6d7d8d9dadbdcdddedf\
e0e1e2e3e4e5e6e7e8e9eaebecedeeef\
f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff";

@lazy @inline
const RAD_DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";

export function utoa64hex_lut(num: f64): string {
	let x = u64(num);
	let lut = changetype<usize>(HEX_DIGITS);
  let offset = (63 - u32(clz(x)) >> 2) + 1;
  let res = __alloc(offset << 1, idof<string>());
  while (offset >= 2) {
    offset -= 2;
    store<u32>(res + (offset << 1), load<u32>(lut + ((u32(x) & 0xFF) << 2)));
    x >>= 8;
  }
  if (offset & 1) {
    store<u16>(res, load<u16>(lut + (x as i32 << 6)));
  }
  return changetype<string>(res); // retain
}


export function utoa64hex_simple(num: f64): string {
  let x = u64(num);
	let offset = (63 - i32(clz(x)) >> 2) + 1;
  let res = __alloc(offset << 1, idof<string>());
	do {
    offset--;
		let d = u32(x) & 0x0F | 0x30;
    d += select(0x27, 0, d > 0x39);
    store<u16>(res + (offset << 1), d);
		x >>= 4;
	} while (x);
	return changetype<string>(res); // retain
}


export function utoa64_general(num: f64, radix: i32): string {
  let x = u64(num);
  let isPowOf2 = (radix & (radix - 1)) == 0;
  let lut = changetype<usize>(RAD_DIGITS);

  let offset =
  let res = __alloc(offset << 1, idof<string>());
  let shift = u64(ctz(radix) & 7);
  let base = u64(radix);
	let mask = base - 1;
  if (isPowOf2) {
    do {
      offset--;
      store<u16>(res + (offset << 1), RAD_DIGITS.charCodeAt(x & mask));
      x >>= shift;
    } while (x);
  } else {
    do {
      offset--;
      let q = x / base;
      store<u16>(res + (offset << 1), RAD_DIGITS.charCodeAt(i32(x - q * base)));
      x = q;
    } while (x);
  }
  return changetype<string>(res); // retain
}