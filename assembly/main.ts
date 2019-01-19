
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
  var sign = e < 0;
  e = abs(e);
  var out = 1.0;
  while (e) {
    if (e & 1) out *= x;
    e >>= 1;
    x *= x;
  }
  return sign ? 1.0 / out : out;
}

export function test1(): f64 {
  let acc = 0.0;
  for (let i = 0; i < 100000; i++) {
    acc += ipow64f(10.0, i);
  }
  return acc;
}

export function test2(): f64 {
  let acc = 0.0;
  for (let i = 0; i < 100000; i++) {
    acc += ipow64f_2(10.0, i);
  }
  return acc;
}

export function test3(): f64 {
  let acc = 0.0;
  for (let i = 0; i < 100000; i++) {
    acc += Math.pow(10.0, <f64>i);
  }
  return acc;
}