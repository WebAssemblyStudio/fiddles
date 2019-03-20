declare function sayHello(): void;

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function wasmLoop(width: u32, height: u32): void {
  for (let y: u32 = 0; y < height; y += 1) {
    for (let x: u32 = 0; x < width; x += 1) {
      store<u32>(y + x * height, load<u32>(x + y * width))
    }
  }
}
