declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32, times:i16): i32 {
  
  let res = 0;

  for (let i = 0; i < times; i++){
    res +=  x + y;
  }

  return res;
}
