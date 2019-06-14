// AssemblyScript
declare function sayHello(): void;

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function getGreeting(name: string): string { 
  load<u16>(0);
  sayHello();
  const hello = "hello "
  return hello + name;
  const buf = new ArrayBuffer(100);
}
