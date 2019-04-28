import "allocator/arena";

export function createTypedArray<TArray, T>(
  buffer: ArrayBuffer, 
  byteOffset: usize = 0, 
  length: usize = 0
): TArray {
  var arr = memory.allocate(offsetof<TArray>());
  var byteLength = length << alignof<T>();
  store<ArrayBuffer>(arr, buffer, offsetof<TArray>("buffer"));
  store<i32>(arr, byteOffset, offsetof<TArray>("byteOffset"));
  store<i32>(arr, byteLength, offsetof<TArray>("byteLength"));
  return changetype<TArray>(arr);
}

export function go(): i32 {
  let buf = new ArrayBuffer(1024);

  let indices = createTypedArray<Int32Array, i32>(buf, 0, 8);

  return indices.length;
}

export function go2(): i32 {
  let buf = new ArrayBuffer(1024);

  let indices = createTypedArray<Float64Array, f64>(buf, 0, 16);

  return indices.length;
}



