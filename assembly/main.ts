declare namespace console {
  function log(v: i32): void;
}


function fib(num: i32): i32 {
  if (num <= 1) return num;
  return fib(num - 1) + fib(num - 2);
}

function fibTail(num: i32, a: i32 = 0, b: i32 = 1): i32 {
  if (num == 0) return a;
  if (num == 1) return b;
  return fibTail(num - 1, b, a + b);
}

export function fibTest(): void {
  for (let i = 0; i < 5; i++) {
    fib(34);
  }
}

export function fibTailTest(): void {
  for (let i = 0; i < 5; i++) {
    fibTail(34);
  }
}

console.log(fib(34));
console.log(fibTail(34));

