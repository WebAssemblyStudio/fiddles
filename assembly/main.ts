import "allocator/arena";

const ITERS: i32 = 10000000;

var values = new Array<i32>(ITERS);

Math.seedRandom(117);

export function setup(): void {
  for (let i = 0; i < ITERS; i++) {
    values[i] = <i32>(Math.random() * ITERS);
  }
}

export function baseline(): void {
  let acc = 0;
  for (let i = 0; i < ITERS; i++) {
    let r = (unchecked(values[i]) + 1) * 2 + 1;
    acc += r;
  }
}

export function stream(): void {
  let acc = values
    .map<i32>((x: i32, index: i32, arr: i32[]): i32 => x + 1)
    .map<i32>((x: i32, index: i32, arr: i32[]): i32 => x * 2)
    .map<i32>((x: i32, index: i32, arr: i32[]): i32 => x + 2)
    .reduce<i32>(((a: i32, b: i32, index: i32, arr: i32[]): i32 => a + b), 0);
}