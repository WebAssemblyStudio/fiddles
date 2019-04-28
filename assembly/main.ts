import "allocator/arena";

export function createTypedArray<TArray>(
  buffer: ArrayBuffer, 
  byteOffset: usize = 0, 
  byteLength: usize = 0
): TArray {
  var arr = memory.allocate(offsetof<TArray>());
  store<ArrayBuffer>(arr, buffer, offsetof<TArray>("buffer"));
  store<i32>(arr, byteOffset, offsetof<TArray>("byteOffset"));
  store<i32>(arr, byteLength, offsetof<TArray>("byteLength"));
  return changetype<TArray>(arr);
}

export function go(): i32 {
  let buf = new ArrayBuffer(1024);

  let indices = createTypedArray<Float32Array>(buf, 0, 20);

  return indices.length;
}



