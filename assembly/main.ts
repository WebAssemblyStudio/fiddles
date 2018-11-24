
declare function logf(v: f64): void;

@inline
function isOddInteger<T>(x: T): bool {
  var ix = trunc(x);
  return <bool>(<i32>(ix == x) & (<i32>ix & 1));
}

@inline
function isInfinity<T>(value: T): bool { 
  return value == value && (value - value !== 0);
}

var _frexp_exponent: i32 = 0;

function frexp(x: f64): f64 {
  const Ox1p64 = reinterpret<f64>(0x43F0000000000000);

  var y = reinterpret<u64>(x);
  var e = <i32>(y >> 52) & 0x7FF;

  if (e == 0) {
    let significand: f64;
    if (x != 0) {
      // subnormal
      significand = frexp(x * Ox1p64);
      _frexp_exponent -= 64;
    } else {
      // frexp(+-0)
      significand = x;
      _frexp_exponent = 0;
    }
    return significand;
  } else if (e == 0x7FF) {
    // frexp(NaN)
    let significand = x;
    // frexp(+-Infinity) = (+-Infinity, 0)
    if (x == Infinity || x == -Infinity) _frexp_exponent = 0;
    return significand;
  }

  _frexp_exponent = e - 0x3FE;
  y &= 0x800FFFFFFFFFFFFF;
  y |= 0x3FE0000000000000;
  var significand = reinterpret<f64>(y);
  return significand;
}

export function pow(x: f64, y: f64): f64 {
  if (x == 1 || y == 0) return 1;
  if (isNaN(x) || isNaN(y)) return NaN;
  if (y == 1) return x;
  if (y == 0.5) return sqrt(x);
  if (y == -0.5) return 1.0 / sqrt(x);
  if (x == 0) {
    let oddInt = isOddInteger(y);
    return select<f64>(
      select<f64>(copysign(Infinity, x), Infinity, oddInt),
      select<f64>(x, 0, oddInt),
      y < 0
    );
  }
  if (y == Infinity || y == -Infinity) {
    if (x == -1) return 1;
    else if ((abs(x) < 1) == (y == Infinity)) return 0;
    else return Infinity;
  }
  if (x == Infinity || x == -Infinity) {
    if (x == -Infinity) return pow(1.0 / x, -y);
    else if (y < 0) return 0;
    else if (y > 0) return Infinity;
  }
  var ay = y;
  var flip = false;
  if (ay < 0) {
    ay = -ay;
    flip = true;
  }

  var yi = trunc(ay);
  var yf = ay - yi;
  if (yf != 0 && x < 0) return NaN;
  if (yi >= <f64>(<u64>1 << 63)) return Math.exp(y * Math.log(x));
  var a1: f64 = 1.0;
  var ae = 0;

  // a *= x ** yf
  if (yf != 0) {
    if (yf > 0.5) {
      yf -= 1.0;
      yi += 1;
    }
    a1 = Math.exp(yf * Math.log(x));
  }
  // a *= x ** yi
  var x1 = frexp(x);
  var xe = _frexp_exponent;

  var i = <i32>yi;
  while (i != 0) {
    if (i & 1) {
      a1 *= x1;
      ae += xe;
    }
    x1 *= x1;
    xe <<= 1;
    if (x1 < 0.5) {
      x1 += x1;
      --xe;
    }
    i >>= 1;
  }

  // a *= a1 * 2^ae
  if (flip) {
    a1 = 1 / a1;
    ae = -ae;
  }

  return Math.scalbn(a1, ae);
}

/*
logf(Math.pow(0.0, 0.0));
logf(pow(0.0, 0.0));

logf(Math.pow(2.0, 0.5));
logf(pow(2.0, 0.5));

logf(Math.pow(2.0, -0.5));
logf(pow(2.0, -0.5));

logf(Math.pow(-8.06684839057968084, 4.53566256067686879));
logf(pow(-8.06684839057968084, 4.53566256067686879));

logf(Math.pow(9.26705696697258574, 4.81139208435979615));
logf(pow(9.26705696697258574, 4.81139208435979615));

logf(Math.pow(7.85889025304169664, 0.0521545267500622481));
logf(pow(7.85889025304169664, 0.0521545267500622481));
*/

export function test1(): f64 {
  let acc = 0.0;
  let y = 1.0;
  for (let x = f64.MIN_VALUE; x < 1000000.0; x += 10.3333) {
    acc += Math.pow(x, y);
    y = x * 2.5;
  }
  return acc;
}

export function test2(): f64 {
  let acc = 0.0;
  let y = 1.0;
  for (let x = f64.MIN_VALUE; x < 1000000.0; x += 10.3333) {
    acc += pow(x, y);
    y = x * 2.5;
  }
  return acc;
}