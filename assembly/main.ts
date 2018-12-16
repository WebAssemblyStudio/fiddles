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

