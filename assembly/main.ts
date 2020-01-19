class Size {
  width: f64 = 0
  height: f64 = 0
}

export function test(): string {
  let size = { width: 10.0, height: 2.0 } as Size;
  return size.width.toString();
}
