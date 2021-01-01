(module
  (import "some" "thing" (func $thing))
  (func $main (result i32)
    i32.const 1
    i32.const 1
    i32.add
    i32.const 2
    i32.add
    call $thing)
  (export "main" (func $main))
)