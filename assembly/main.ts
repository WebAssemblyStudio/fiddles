@inline
function isInteger1(value: f64): boolean {
  return isFinite<f64>(value) && trunc<f64>(value) == value;
}


@inline
function isInteger2(value: f64): boolean {
  var u = reinterpret<u64>(value);
  var e = <i32>((u >> 52) & 0x7FF) - 1023;
  var b = 52 - e;
  var mask: u64 = 
    select(0x7FFFFFFFFFFFFFFF, 
      select<u64>(0, (<u64>1 << b) - 1, e > 52), 
      e < 0
    );
  return !(u & mask);
}

@inline
function isInteger3(value: f64): boolean {
  var u = reinterpret<u64>(value);
  var e = ((u >> 52) & 0x7FF) as i64;
  var b = 1023 + 52 - e;
  var mask: u64 = 
    select<u64>(0x7FFFFFFFFFFFFFFF, 
      select<u64>(0, (<u64>1 << b) - 1, e > 52 + 1023),
      e < 1023
    );
  return !(u & mask);
}


export function test1(): boolean {
  var res = false;
  for (let f = 0.0; f < 10000000.0; f += 0.5) {
    res = isInteger1(f);
  }
  return res;
}

export function test2(): boolean {
  var res = false;
  for (let f = 0.0; f < 10000000.0; f += 0.5) {
    res = isInteger2(f);
  }
  return res;
}


export function test3(): boolean {
  var res = false;
  for (let f = 0.0; f < 10000000.0; f += 0.5) {
    res = isInteger3(f);
  }
  return res;
}

