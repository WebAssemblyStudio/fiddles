import "allocator/arena";

@external("env", "sayHello")
declare function sayHello(): void;

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}


 function test(amount: i32): void {
        var map: Map<string, i32> = new Map<string, i32>();
        for (let i = 0;  i < amount; i++) {
            map.set("dd", i);
            console.logf(map.get("dd"));
        }

}


test(10);

console.logi(add(1, 2));
