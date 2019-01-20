
function ipow64(x: i64, e: i32): i64 {
  var out: i64 = 1;
  if (ASC_SHRINK_LEVEL < 1) {
    if (e < 0) return 0;
    switch (e) {
      case 0: return 1;
      case 1: return x;
      case 2: return x * x;
    }

    let log = 32 - clz(e);
    if (log <= 6) {
      // 64 = 2 ^ 6, so need only six cases.
      // But some extra cases needs for properly overflowing
      switch (log) {
        case 6: {
          if (e & 1) out *= x;
          e >>= 1;
          x *= x;
        }
        case 5: {
          if (e & 1) out *= x;
          e >>= 1;
          x *= x;
        }
        case 4: {
          if (e & 1) out *= x;
          e >>= 1;
          x *= x;
        }
        case 3: {
          if (e & 1) out *= x;
          e >>= 1;
          x *= x;
        }
        case 2: {
          if (e & 1) out *= x;
          e >>= 1;
          x *= x;
        }
        case 1: {
          if (e & 1) out *= x;
        }
      }
      return out;
    }
  }

  while (e > 0) {
    if (e & 1) out *= x;
    e >>= 1;
    x *= x;
  }
  return out;
}


function ipow64_2(x: i64, e: i32): i64 {
  var out: i64 = 1;
  if (ASC_SHRINK_LEVEL < 1) {
    if (e < 0) return 0;
    switch (e) {
      case 0: return 1;
      case 1: return x;
      case 2: return x * x;
    }

    let log = 32 - clz(e);
    if (log <= 6) {
      // 64 = 2 ^ 6, so need only six cases.
      // But some extra cases needs for properly overflowing
      switch (log) {
        case 6: {
          out *= select(x, 1, e & 1);
          e >>= 1;
          x *= x;
        }
        case 5: {
          out *= select(x, 1, e & 1);
          e >>= 1;
          x *= x;
        }
        case 4: {
          out *= select(x, 1, e & 1);
          e >>= 1;
          x *= x;
        }
        case 3: {
          out *= select(x, 1, e & 1);
          e >>= 1;
          x *= x;
        }
        case 2: {
          out *= select(x, 1, e & 1);
          e >>= 1;
          x *= x;
        }
        case 1: {
          out *= select(x, 1, e & 1);
        }
      }
      return out;
    }
  }

  while (e > 0) {
    out *= select(x, 1, e & 1);
    e >>= 1;
    x *= x;
  }
  return out;
}



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
    if (e & 1) out *= x;
    // out *= select(x, 1.0, e & 1);
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


export function test_i1(x: i32): f64 {
  let acc: i64 = 0;
  let a: i64 = x;
  for (let i = 0; i < 1000000; i++) {
    acc += ipow64(a, i & 127) / (<i64>1 << 32);
  }
  return <f64>acc;
}

export function test_i2(x: i32): f64 {
  let acc: i64 = 0;
  let a: i64 = x;
  for (let i = 0; i < 1000000; i++) {
    acc += ipow64_2(a, i & 127) / (<i64>1 << 32);
  }
  return <f64>acc;
}