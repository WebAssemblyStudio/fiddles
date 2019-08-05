declare function sayHello(): void;

sayHello();

export function greet(offset: i32): string {
  let str_buffer = String.UTF8.encode("hello world");
  // make Uint8array wrap on str_bytes
  let bytes = Uint8Array.wrap(str_buffer, 0, str_buffer.byteLength);

  //String.UTF8.decodeUnsafe(bytes.dataStart, bytes.byteLength);
  return String.UTF8.decodeUnsafe((bytes.buffer as usize) + bytes.byteOffset, bytes.byteLength);
}
