(module
  (import "env" "memory" (memory 1))
  (func $main (param $n i32) (result i32)
    get_local $n
    i32.const 42
    i32.store8 
    i32.const 1)
  (export "main" (func $main))
)