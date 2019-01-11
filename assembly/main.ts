import "allocator/tlsf";

export function getBuffer(): ArrayBuffer {
  var array: Uint8ClampedArray = new Uint8ClampedArray(3);
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  return array.buffer;
}

// @ts-ignore
export { memory }