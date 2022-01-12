(module
  (import "env" "memory" (memory 1))
  (func $main (result i32)
    i32.const 0
    i32.const 104
    i32.store
    i32.const 1
    i32.const 101
    i32.store 
    i32.const 2
    i32.const 108
    i32.store
    i32.const 3
    i32.const 108
    i32.store
    i32.const 4
    i32.const 111
    i32.store
    i32.const 5
    i32.const 33
    i32.store
    i32.const 0
  )
  (export "main" (func $main))
)
