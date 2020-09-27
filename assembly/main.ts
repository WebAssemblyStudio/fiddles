const byte_rev_table = memory.data<u8>([
  0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
  0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
  0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
  0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
  0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
  0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
  0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
  0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
  0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
  0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
  0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
  0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
  0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
  0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
  0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
  0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff
]);

@inline
function bitrev8(val: u8): u8 {
  return load<u8>(byte_rev_table + val);
}

@inline
function bitrev16(val: u16): u16 {
  return (
    (<u16>load<u8>(byte_rev_table + (val & 0xFF)) << 8) |
     <u16>load<u8>(byte_rev_table + (val >> 8))
  );
}

@inline
function bitrev32(val: u32): u32 {
  return (
    (<u32>bitrev16(u16(val >>  0)) << 16) | 
     <u32>bitrev16(u16(val >> 16))
  );
}

@inline
function rev64(v: u64): u64 {
  v = ((v >>> 1) & 0x5555555555555555) | ((v & 0x5555555555555555) << 1);
  v = ((v >>> 2) & 0x3333333333333333) | ((v & 0x3333333333333333) << 2);
  v = ((v >>> 4) & 0x0F0F0F0F0F0F0F0F) | ((v & 0x0F0F0F0F0F0F0F0F) << 4);
  v = ((v >>> 8) & 0x00FF00FF00FF00FF) | ((v & 0x00FF00FF00FF00FF) << 8);
  v = ((v >>> 16) & 0x0000FFFF0000FFFF) | ((v & 0x0000FFFF0000FFFF) << 16);
  v = rotr<u64>(v, 32);
  return v;
}

// fastest
function rev64a(n: u64): u64 {
  let t: u64;
  n = rotr<u64>(n, 32);
  n = (n & 0x0001FFFF0001FFFF) << 15 |
      (n & 0xFFFE0000FFFE0000) >> 17;
  t = (n ^ (n >> 10)) & 0x003F801F003F801F;
  n = (t | (t << 10)) ^ n;
  t = (n ^ (n >>  4)) & 0x0E0384210E038421;
  n = (t | (t <<  4)) ^ n;
  t = (n ^ (n >>  2)) & 0x2248884222488842;
  n = (t | (t <<  2)) ^ n;
  return n;
}

function bitrev64(n: u64): u64 {
  return (
    (<u64>load<u8>(byte_rev_table + <usize>(n        & 0xFF)) << 56) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>>  8 & 0xFF)) << 48) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 16 & 0xFF)) << 40) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 24 & 0xFF)) << 32) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 32 & 0xFF)) << 24) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 40 & 0xFF)) << 16) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 48 & 0xFF)) <<  8) |
    (<u64>load<u8>(byte_rev_table + <usize>(n >>> 56)))
  );
}

// fastest!
// 187 bytes
@inline
function rev32(x: u32): u32 {
   x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
   x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
   x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
   x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
   x = rotl(x, 16);
   return x;
}

// 193 bytes
@inline
function rev32a(x: u32): u32 {
   x = (x & 0x55555555) << 1 | (x >> 1) & 0x55555555;
   x = (x & 0x33333333) << 2 | (x >> 2) & 0x33333333;
   x = (x & 0x0F0F0F0F) << 4 | (x >> 4) & 0x0F0F0F0F;
   x = (x << 24) | ((x & 0xFF00) << 8) |
       ((x >> 8) & 0xFF00) | (x >> 24);
   return x;
}

@inline
function rev16(x: u32): u32 {
   x = x | ((x & 0x000000FF) << 16);
   x = (x & 0xF0F0F0F0) | ((x & 0x0F0F0F0F) << 8);
   x = (x & 0xCCCCCCCC) | ((x & 0x33333333) << 4);
   x = (x & 0xAAAAAAAA) | ((x & 0x55555555) << 2);
   x = x >> 15;
   return x;
}

// 164 bytes
// fastest!
@inline
function rev16a(x: u32): u32 {
   let t: u32;
   x = x | ((x & 0x000000FF) << 16);
   t = x & 0x0F0F0F0F; x = (t << 8) | (t ^ x);
   t = x & 0x33333333; x = (t << 4) | (t ^ x);
   t = x & 0x55555555; x = (t << 2) | (t ^ x);
   x = x >> 15;
   return x;
}

@inline
function rev8(x: u32): u32 {
  return (<u32>(((<u64>(x & 0xFF) * 0x80200802) & 0x0884422110) * 0x0101010101 >> 32)) & 0xFF;
}

// fastest!
@inline
function rev8a(x: u32): u32 {
  x &= 0xFF;
  return (((x * 0x0802 & 0x22110) | (x * 0x8020 & 0x88440)) * 0x10101 >> 16) & 0xFF;
}

@inline
function rev8b(b: u32): u32 {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}

const ITER: u32 = 20_000_022;

export function bench_rev64(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += <u32>rev64(<u64>i);
  }
  return acc;
}

export function bench_rev64a(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += <u32>rev64a(<u64>i);
  }
  return acc;
}

export function bench_rev32(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev32(i);
  }
  return acc;
}

export function bench_rev32a(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev32a(i);
  }
  return acc;
}

export function bench_rev16(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev16(i & 0xFFFF);
  }
  return acc;
}

export function bench_rev16a(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev16a(i & 0xFFFF);
  }
  return acc;
}

export function bench_rev8(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev8(i);
  }
  return acc;
}

export function bench_rev8a(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev8a(i);
  }
  return acc;
}

export function bench_rev8b(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev8b(i);
  }
  return acc;
}

export function bench_rev8_table(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += bitrev8(<u8>i);
  }
  return acc;
}

export function bench_rev16_table(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += bitrev16(<u16>i);
  }
  return acc;
}

export function bench_rev32_table(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += bitrev32(i);
  }
  return acc;
}

export function bench_rev64_table(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += <u32>bitrev64(<u64>i);
  }
  return acc;
}
