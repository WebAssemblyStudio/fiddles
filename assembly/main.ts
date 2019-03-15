declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function pi(n: f64): f64 {
  let a: f64 = 1.0;
  let b: f64 = Math.SQRT1_2;
  let t: f64 = 1.0 / 4.0;
  let p: f64 = 1.0;

  for(let i: f64 = 0; i < n; i++) {
    let _a: f64 = (a + b) / 2.0;
    let _b: f64 = Math.sqrt(a * b);
    let _t: f64 = t - (p * Math.pow(a - _a, 2.0));
    let _p: f64 = 2.0 * p;

    a = _a;
    b = _b;
    t = _t;
    p = _p;
  }

  return Math.pow(a + b, 2.0) / (4.0 * t);
}