

function test<T>(): u32 {
  return (1 << (sizeof<T>() * 8)) - 1;
}

function test2<T>(): u64 {
  return ((<u64>2) ** (sizeof<T>() * 8)) - 1;
}

//assert(test<u32>() == u32.MAX_VALUE);
assert(test2<u32>() == u32.MAX_VALUE);
assert(test2<u64>() == u64.MAX_VALUE);
