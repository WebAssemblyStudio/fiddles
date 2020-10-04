export function sum1(n: i32): i32 {
  let sum = 0
  let i = 0
  while (i < n) {
    sum += i
    i++
  }
  return sum
}

export function sum2(n: i32): i32 {
  let sum = 0
  let i = n - 1
  while (i >= 0) {
    sum += i
    i--
  }
  return sum
}
