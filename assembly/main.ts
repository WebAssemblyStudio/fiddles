declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): f64 {
  return Math.pow(x,y);
}

export function getRand(seed: i64, howmany: i32): Array<i64>{
  let z:i64 = seed;
  let result = []
  for (let i:i8 = 0; i < howmany; i++) {
    let m = 25, a = 11, c = 17;
    z = (a * z + c) % m;
  }
  return result.push(z);
}

