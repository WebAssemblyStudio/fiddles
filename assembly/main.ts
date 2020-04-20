export function main() : void {
  const resAdd = add(10, 20);
  const resSub = sub(resAdd, 20);
}

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function sub(x: i32, y: i32) : i32 {
  return x - y;
}
