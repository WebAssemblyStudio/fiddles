

export function __retainedAlloc(size: usize, id: i32): usize {
  return __retain(__alloc(size, id));
} 
