
export const some_data = memory.data<u8>([1,2,3]);

export function memoryBase(): i32 {
  return __heap_base;
}
