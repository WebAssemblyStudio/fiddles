declare function sayHello(): void;


export function add(x: i32, y: i32): i32 {
  return x + y;
}

const c:i32 = 0;

if(!c){
  sayHello();
}

if(c){
  sayHello();
}