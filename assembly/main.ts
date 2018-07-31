declare namespace console {
  function logLowHi(lo: f64, hi: f64): void;
  function logByte(index: i32, value: u32): void;
}

const array: u8[] = [
  0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
  0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x12,
];

console.logByte(0, array[0]);
console.logByte(1, array[1]);
console.logByte(2, array[2]);
console.logByte(3, array[3]);
console.logByte(4, array[4]);
console.logByte(5, array[5]);
console.logByte(6, array[6]);
console.logByte(7, array[7]);

console.logByte(8,  array[8]);
console.logByte(9,  array[9]);
console.logByte(10, array[10]);
console.logByte(11, array[11]);
console.logByte(12, array[12]);
console.logByte(13, array[13]);
console.logByte(14, array[14]);
console.logByte(15, array[15]);

var lo: u64 = (
  <u64>array[0] <<  0 |
  <u64>array[1] <<  8 |
  <u64>array[2] << 16 |
  <u64>array[3] << 24 |
  <u64>array[4] << 32 |
  <u64>array[5] << 40 |
  <u64>array[6] << 48 |
  <u64>array[7] << 56
);

var hi: u64 = (
  <u64>array[8]  <<  0 |
  <u64>array[9]  <<  8 |
  <u64>array[10] << 16 |
  <u64>array[11] << 24 |
  <u64>array[12] << 32 |
  <u64>array[13] << 40 |
  <u64>array[14] << 48 |
  <u64>array[15] << 56
);

console.logLowHi(reinterpret<f64>(lo), reinterpret<f64>(hi));
