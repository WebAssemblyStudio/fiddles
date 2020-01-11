declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function comparisons(): string {
  let outcomes = "";

  let a: i32 = 1;
  let b: i32 = 2;
  
  if(a > b) {
    outcomes += "a > b<br>";    
  }

  let aa: u32 = 11;
  let bb: u32 = 11;

  if(aa > bb) {
    outcomes += "aa > bb<br>";
  }

  return outcomes
}