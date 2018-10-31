declare function sayHello(): void;
declare function my_random(): f64;


export function add(x: i32, y: i32): i32 {

  return x + y;
}

export function random(): f64 {
  return my_random() + 1.1;
}