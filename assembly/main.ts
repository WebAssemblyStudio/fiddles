declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function performTest(n: i32): i32{
  let value:i32 = 0;
  for(let i = 0; i < n; i++){
    value = add(i,1);
  }
  return value;
}