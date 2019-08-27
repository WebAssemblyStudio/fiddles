declare function sayHello(): void;

class Str {
  str: string;
}

sayHello();

export function add(x: i32, y: i32): boolean {
  let str = new Str();
  
  return genericIsNull<string | null>(stringFunc("hello"));
}

function stringFunc(str: string): string | null {
  return str
}

function genericIsNull<T>(value: T): boolean {
  if (value == <T> null) {
    return true;
  } else if (isString<T>()){
    //@ts-ignore
    stringFunc(value);
  }
  return false;
}
