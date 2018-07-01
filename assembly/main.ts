
@external("env", "log")
declare function logf64(v: f64): f64;

const ITERS: i32 = 1000000;

export function nativeLogTestf64(): void {
  let acc: f64 = 0;
  for (let i = 0; i < ITERS; i++) {
    acc += Math.log(<f64>i);
  }
}

export function nativeLogTestf32(): void {
  let acc: f32 = 0;
  for (let i = 0; i < ITERS; i++) {
    acc += Mathf.log(<f32>i);
  }
}

export function jsLogTest(): void {
  let acc: f64 = 0;
  for (let i = 0; i < ITERS; i++) {
    acc += logf64(<f64>i);
  }
}