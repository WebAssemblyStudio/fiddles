declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function fib(n:i32):i32{
  if(n <=1){
    return n;
  }else{
    return fib(n-1)+fib(n-2);
  }
}