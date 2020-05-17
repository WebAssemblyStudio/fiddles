
export function add(n: i32): i32 {
  let s = 0;
  for (let i = n; i > 0; i -= 1) {
    s = (s + i) % 1000007;
  }
  return s;
}
