

function test<T>(): i32 {
  return (1 << sizeof<T>()) - 1;
}

assert(test<u32>() == u32.MAX_VALUE);
