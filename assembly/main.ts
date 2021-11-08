declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function compute() : u32{
  const opcode = 63457
  //return 65 + (((opcode & 0x1f8) >> 3) - (opcode & 0x200 ? 0x40 : 0));
  //return ((opcode & 0x1f8) >> 3);
  return (opcode & 0x200 ? 0x40 : 0);
}
