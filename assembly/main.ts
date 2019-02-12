declare function logf(val: f64): void;
declare function logi(val: i32): void;

var _segment_hi: u64 = 0;
var _rempio2f_y: f64 = 0;

/*
@inline
function rint(x: f64): f64 {
  const Ox1_8p52 = reinterpret<f64>(0x4338000000000000); // 0x1.8p52
  return copysign<f64>(abs<f64>(x) + Ox1_8p52 - Ox1_8p52, x);
  //return nearest<f64>(x);
  // return x + Ox1_8p52 - Ox1_8p52;
}
*/

@inline
function segment(offset: i32): u64 {
  const bits: u64[] = [
    0xA2F9836E4E441529,
    0xFC2757D1F534DDC0,
    0xDB6295993C439041,
    0xFE5163ABDEBBC561
  ];

  var index = offset >> 6;
  var shift = offset & 63;

  var lo: u64, hi: u64;

  var b0 = bits[index + 0];
  var b1 = bits[index + 1];

  if (shift > 32) {
    let b2 = bits[index + 2];
    lo  = b2 >> (96 - shift);
    lo |= b1 << (shift - 32);
  } else {
    lo = b1 >> (32 - shift);
  }

  hi  = b1 >> (64 - shift);
  hi |= b0 << shift;

  _segment_hi = hi;
  return lo;
}

export function rempio2f(x: f32): i32 {
  const pi2hi = reinterpret<f64>(0x3FF921FB50000000); // 1.57079631090164184570
  const pi2lo = reinterpret<f64>(0x3E5110B4611A6263); // 1.58932547735281966916e-8

  const _2_pi   = reinterpret<f64>(0x3FE45F306DC9C883); // 0.63661977236758134308
  const pi_2_65 = reinterpret<f64>(0x3BF921FB54442D18); // 8.51530395021638647334e-20

  const Ox1_8p52 = reinterpret<f64>(0x4338000000000000); // 0x1.8p52

  var i = reinterpret<i32>(x) & 0x7FFFFFFF;

  if (i < 0x4DC90FDB) {
    // logi(11111);
    let q = x * _2_pi + Ox1_8p52 - Ox1_8p52;
    _rempio2f_y = x - q * pi2hi - q * pi2lo;
    return <i32>q;
  }

  if (i >= 0x7F800000) {
    _rempio2f_y = x - x;
    return 0;
  }

  var slo = segment((i >> 23) - 152);
  var shi = _segment_hi;

  var mantissa: u64 = (i & 0x007FFFFF) | 0x00800000;
  var product: u64 = mantissa * shi + ((mantissa * slo) >> 32);
  var r: i64 = product << 2;
  var q: i32 = <i32>(product >> 62) + <i32>(r < 0);

  _rempio2f_y = copysign<f64>(pi_2_65, x) * <f64>r;
  return select(-q, q, i < 0);
}

const val: f32 = 5687.01;
logf(val % (Math.PI / 2.0));
logi(rempio2f(val));
logf(_rempio2f_y);
