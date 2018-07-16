
import "allocator/arena";

Math.seedRandom(117);

const ITERS = 1000000;
var array: i32[];

for (let i = 0; i < ITERS; ++i) {
  array[i] = <i32>(Math.random() * ITERS);
}

export function test(): void {
  array.sort((a: i32, b: i32): i32 => a - b);
}
