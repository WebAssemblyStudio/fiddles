declare function sayHello(): void;

sayHello();

function fibonacci(num: i32): i32 {
  var a:i32 = 1;
  var b:i32 = 0;
  var temp:i32 = 0;

  while (num >= 0){
    temp = a;
    a = a + b;
    b = temp;
    num--;
  }

  return b;
}

export function add(x: i32, y: i32): i32 {
  return fibonacci(9999);
}
