
@inline
function fselect1(m: i32): f64 {
  if (m & 1) return -Math.PI / 2;
  return Math.PI / 2;
}

@inline
function fselect2(m: i32): f64 {
  return select<f64>(-Math.PI / 2, Math.PI / 2, m & 1);
}

@inline
function fselect3(m: i32): f64 {
  return reinterpret<f64>(select<u64>(reinterpret<u64>(-Math.PI / 2), reinterpret<u64>(Math.PI / 2), m & 1));
}

export function test1(): f64 {
  var acc = 0.0;
  for (let i = 0; i < 10000000; ++i) {
    acc += fselect1(i);
  }
  return acc;
}

export function test2(): f64 {
  var acc = 0.0;
  for (let i = 0; i < 10000000; ++i) {
    acc += fselect2(i);
  }
  return acc;
}

export function test3(): f64 {
  var acc = 0.0;
  for (let i = 0; i < 10000000; ++i) {
    acc += fselect3(i);
  }
  return acc;
}
