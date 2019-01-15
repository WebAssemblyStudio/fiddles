import "allocator/tlsf";

//@ts-ignore
export { memory };

declare function sayHello(str: string): void;
declare function sayHello1(str: i32): void;

class A {
  public c: i32;
}

export function add(x: i32, y: i32): void {
  //字符串八字节对齐
  let str = '1';
  sayHello(str); //指针地址56
  let ptr = changetype<usize>(str);
  sayHello1(<i32>ptr); //指针地址56
  memory.free(ptr); //回收。导致指针地址56空闲，所以下一个分配一定是指针地址56
  let str1 = '2'; 
  sayHello(str);//指针地址56

  let str3 = '2'
  sayHello(str3); //指针地址64

  let str4 = '2';
  sayHello(str4); //指针地址72

  str3 = '222';
  sayHello(str3); //指针地址？？
  sayHello(str4); //指针地址？？

  str = '3'; //72 这里应该是出错了。str已经被回收,不允许使用已经free的指针地址进行赋值.已经出现野指针情况
  sayHello(str);
  str = '4'; //80
  sayHello(str);
}
