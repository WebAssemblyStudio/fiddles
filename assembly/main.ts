declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): u8 {
  let buffer = new Uint8Array(1);
  buffer[0] = 42;

  //for (let index = 1; index < 2; index++) {
  const oldBuffer = buffer;
  buffer = new Uint8Array(2);
  buffer.set(oldBuffer);
  buffer[1] = 1;
  return buffer[0];
}
