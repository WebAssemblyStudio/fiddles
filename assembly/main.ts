import "allocator/tlsf";
export { memory };

declare function sayHello(): void;

sayHello();

export function add(): i32 {
  var returnVal: i32 = 1;
  for (var i: i32 = 0; i < 100000000; i++) {
    returnVal += i;
  }
  return returnVal;
}
