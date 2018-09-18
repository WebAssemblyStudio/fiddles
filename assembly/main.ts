declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
  function log(value: f64[]): void;
}

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function matx(x: f64, y: f64): f64[] {
  return [x + y];
}

console.log(matx(1, 2));
