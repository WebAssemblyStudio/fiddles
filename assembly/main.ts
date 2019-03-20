declare function sayHello(): void;

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function wasmLoop(width: u32, height: u32): void {
  let offset = width * height * 4;
  let heightSize = height * 4;
  let widthSize = width * 4;
  for (let y: u32 = 0; y < heightSize; y += 4) {
    for (let x: u32 = 0; x < widthSize; x += 4) {
      store<u32>(offset + y + x * height, load<u32>(x + y * width))
    }
  }
}