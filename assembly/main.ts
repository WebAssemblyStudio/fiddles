import "allocator/arena";
declare function sayHello(): void;
declare function logi(i: i32): void;
declare function logArray(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}


var arr = new Array<i32>();
for(let i=0 ;i < 5; i++) {
  arr.push(i);
}

arr.forEach((value: i32, index: i32,array: Array<i32>): void => {
  if (index == 0){
    for (let i=0; i <3 ; i ++) {
      array.pop();
    }

    for (let i =0;i < 100; i++){
      array.push(i + 100);
    }

     for (let i = 0; i < 100; i++){
      array.pop();
    }

     for (let i = 0; i < 100; i++){
      array.push(i + 333);
    }
  }
  logi(value);
});
logArray();

for (let i = 0; i< 10; i++){
  logi(arr[i]);
}