export const Float64Array_ID = idof<Float64Array>();

export function sum(arr: Float64Array): f64 {
  let sum = 0.0;
  for(let i = 0, l = arr.length; i < l; i++) {
    sum += unchecked(arr[i]);
  }
  return sum;
}

export function reduce(arr: Float64Array): f64 {
  return arr.reduce((a, b) => a + b, 0.0);
}

export function emptyFunc(arr: Float64Array): f64 {
  return 0.0;
}


