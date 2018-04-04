const sayHello = (): void => {
  logLn("Hello web assembly", "info");
}

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}
