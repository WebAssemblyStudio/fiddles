declare function sayHello(): void;

sayHello();

export function apply(f: () => i32): i32 {	return f(); }
// export function apply0<T>(f: () => T): T {	return f(); }
// export function apply1<T>(f: (x: T) => T, x: T): T { return f(x); }
// export function apply2<T>(f: (x: T, y: T) => T, x: T, y: T): T { return f(x, y); }
// export function apply3<T>(f: (x: T, y: T, z: T) => T, x: T, y: T, z: T): T { return f(x, y, z); }

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function sub(x: i32, y: i32): i32 {
  return x - y;
}

var b = 10;
var a = (b: i32): i32 => b;

export function foo(): () => i32 {
  //var a = 12;
  const bar = (): i32 => {
    return a(b) + 13;
  }
  // return (): i32 => {
  //   return a + 1;
  // };
  return bar;
}
