(module
  (type $t0 (func))
  (type $t1 (func (param i32) (result i32)))
  (type $t2 (func (param i32 i32 i32) (result i32)))
  (import "main" "sayHello" (func $main.sayHello (type $t0)))
  (func $TestContract#add (export "TestContract#add") (type $t2) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    get_local $p1
    get_local $p2
    i32.add)
  (func $TestContract#getString (export "TestContract#getString") (type $t1) (param $p0 i32) (result i32)
    i32.const 32)
  (func $f3 (type $t0)
    call $main.sayHello)
  (memory $memory (export "memory") 1)
  (global $TestContract (export "TestContract") i32 (i32.const 3))
  (start 3)
  (data (i32.const 16) "\16\00\00\00\01\00\00\00\01\00\00\00\16\00\00\00h\00e\00l\00l\00o\00 \00w\00o\00r\00l\00d"))
