declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export class Animal {
  name: string;

  constructor(name: string) {
    this.name = name;
  }
}

// export class Dog extends Animal {

// }