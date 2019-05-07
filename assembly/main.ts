declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function gcd(num1: i32, num2: i32): i32 {
  if (num1 === 0 || num2 === 0) {
    return 0;
  }
  if (num1 === num2) {
    return num1;
  }
  if (num1 > num2) {
    return gcd(num1 - num2, num2);
  }
  return gcd(num1, num2 - num1);
};
