
function ipow64f(x: f64, e: i32): f64 {
  if (ASC_SHRINK_LEVEL < 1) {
    switch (e) {
      case -2: return 1.0 / (x * x);
      case -1: return 1.0 / x;
      case 0:  return 1.0;
      case 1:  return x;
      case 2:  return x * x;
    }
  }
  var sign = e < 0;
  var out = 1.0;
  while (e) {
    if (e & 1) out *= x;
    e /= 2;
    x *= x;
  }
  return sign ? 1.0 / out : out;
}

function ipow64f_2(x: f64, e: i32): f64 {
  if (ASC_SHRINK_LEVEL < 1) {
    switch (e) {
      case -2: return 1.0 / (x * x);
      case -1: return 1.0 / x;
      case 0:  return 1.0;
      case 1:  return x;
      case 2:  return x * x;
    }
  }
  var sign = e >> 31;
  e = (e + sign) ^ sign; // abs(e)
  var out = 1.0;
  while (e) {
    // if (e & 1) out *= x;
    out *= select(x, 1.0, e & 1);
    e >>= 1;
    x *= x;
  }
  return sign ? 1.0 / out : out;
}

export function test1(x: f64): f64 {
  let acc = 0.0;
  for (let i = -100000; i < 100000; i++) {
    acc += ipow64f(x, i & 127) * 1e-127;
  }
  return acc;
}

export function test2(x: f64): f64 {
  let acc = 0.0;
  for (let i = -100000; i < 100000; i++) {
    acc += ipow64f_2(x, i & 127) * 1e-127;
  }
  return acc;
}

export function test3(x: f64): f64 {
  let acc = 0.0;
  for (let i = -100000; i < 100000; i++) {
    acc += Math.pow(x, <f64>(i & 127)) * 1e-127;
  }
  return acc;
}