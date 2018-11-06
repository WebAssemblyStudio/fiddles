declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}


export class Environment {
  reset() {
    var r : f32 = 10.0     
    var s = [1,2,3,4]
    return [s,r]
  }
}