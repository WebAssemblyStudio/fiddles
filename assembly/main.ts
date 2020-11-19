

function test<T>(): u32 {
  return (1 << (sizeof<T>() * 8)) - 1;
}

assert(test<u32>() == u32.MAX_VALUE);
