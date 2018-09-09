declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

export function isMultipleOf (value: f64, multipleOf: f64): bool {
  if (Math.trunc(multipleOf) === multipleOf) {
    return (value % multipleOf) === 0
  }

  return false
}

console.logi(isMultipleOf(4, 2) ? 1 : 0);
console.logi(isMultipleOf(2.3, 0.01) ? 1 : 0);
