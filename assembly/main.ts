declare function sayHello(): void;

sayHello();

declare function changeColor(s: i32): void;

// changeColor("sldkfj");
// changeColor(2);


export function add(x: i32, y: i32): i32 {
  return x + y;
  // changeColor(1);
}

export function setColor(c: i32): void {
  changeColor(c);
}
