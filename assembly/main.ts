declare function sayHello(): void;

sayHello();

export function greet(offset: i32): string {
  let str_buffer = String.UTF8.encode("hello world");

  let bytes_subarray = Uint8Array.wrap(str_buffer, offset, str_buffer.byteLength - offset);

  // decode(bytes_subarray) doesn't work because decode expects an ArrayBuffer, but bytes is a view on the buffer
  //return String.UTF8.decode(bytes_subarray);

  // decode(bytes_subarray.buffer) doesn't work because it returns the whole backing buffer, not the subarray
  //return String.UTF8.decode(bytes_subarray.buffer);

  // dataStart currently works, but is an internal pointer and might break without notice
  //return String.UTF8.decodeUnsafe(bytes_subarray.dataStart, bytes_subarray.byteLength);

  // the documented way of accessing the bytes of a view on a buffer
  return String.UTF8.decodeUnsafe((bytes_subarray.buffer as usize) + bytes_subarray.byteOffset, bytes_subarray.byteLength);

  // changetype<usize> is equivalent to `as usize`?
  //return String.UTF8.decodeUnsafe(changetype<usize>(bytes_subarray.buffer) + bytes_subarray.byteOffset, bytes_subarray.byteLength);
}
