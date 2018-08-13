(module
  (type $t0 (func))
  (type $t1 (func (param i32 i32) (result i32)))
  (type $t2 (func (param i32)))
  (import "env" "sayHello" (func $env.sayHello (type $t0)))
  (import "console" "logi" (func $console.logi (type $t2)))
  (func $add (export "add") (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    get_local $p1
    i32.add)
  (func $f3 (type $t0)
    call $env.sayHello
    i32.const 1
    i32.const 2
    call $add
    call $console.logi)
  (memory $memory (export "memory") 0)
  (start 3))
