declare function sayHello(): void;
declare function log(x: u32): void;
import 'allocator/arena';

sayHello();
let arr: u32[] = [1,2,4,5];

function foo(x: u32): u32[] {
  let res: u32[] = [];
  for (let i= 0; i< arr.length; i++){
    if (arr[i]<x){
      res.push(arr[i]);
    }
  }
  return res;
}

let arr2 = foo(3);
log(arr2.length);


let arr3 = foo(2);
log(arr3.length);

function foo2(x: u32): u32[] {
  let res: u32[] = new Array<u32>();
  for (let i= 0; i< arr.length; i++){
    if (arr[i]<x){
      res.push(arr[i]);
    }
  }
  return res;
}

let arr_2 = foo2(3);
log(arr_2.length);


let arr_3 = foo2(2);
log(arr_3.length);

export function add(x: i32, y: i32): i32 {
  return x + y;
}

