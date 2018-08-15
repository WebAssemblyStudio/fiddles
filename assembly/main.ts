declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

export function overload<T, R>(value: T): R {
  if (value instanceof i32) {
    return <R>(value + 1);
  } else if (value instanceof f64[]) {
    return <R>value[0];
  }
  return <R>0;
}

console.logi(overload<i32, i32>(1));
console.logf(overload<f64[], f64>(<f64[]>[5, 6]));
