// declare function sayHello(text: string): void;

/** Creates a new array and returns it to JavaScript. */
export function createArray(length: i32): Int32Array {
  return new Int32Array(length)
}

/** Randomizes the specified array's values. */
// export function randomizeArray(arr: Int32Array): void {
//   for (let i = 0, k = arr.length; i < k; ++i) {
//     let value = i32((Math.random() * 2.0 - 1.0) * i32.MAX_VALUE)
//     unchecked(arr[i] = value)
//   }
// }

/** Computes the sum of an array's values and returns the sum to JavaScript. */
export function sumArray(arr: Int32Array): i32 {
  let total = 0
  for (let i = 0, k = arr.length; i < k; ++i) {
    total += unchecked(arr[i])
  }
  return total
}

// We'll need the unique Int32Array id when allocating one in JavaScript
export const Int32Array_ID = idof<Int32Array>()

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function test(): string {
  return "world";
}

