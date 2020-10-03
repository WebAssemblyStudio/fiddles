export function sum(n: i32): i32 {
  let sum = 0
  let i = 0
  while (i < n) {
    sum += i
    i++
  }
  return sum
}
