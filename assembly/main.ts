

export function castOrig(x: f64): bool {
  // @ts-ignore: cast
  return (x != 0) & (x == x);
}
 
export function castNext(x: f64): bool {
  let u = reinterpret<u64>(x) & 0x7FFFFFFFFFFFFFFF;
  return u - 1 <= 0x7FF0000000000000 - 1;
}

export function benchOrig(n: f64): i32 {
  let it = 0;
  for (let f: f64 = -n; f <= n; f++) {
    it += i32(castOrig(f));
  }
  return it;
}

export function benchNext(n: f64): i32 {
  let it = 0;
  for (let f: f64 = -n; f <= n; f++) {
    it += i32(castNext(f));
  }
  return it;
}
