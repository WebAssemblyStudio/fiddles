(module
  (memory $mem 1)
  (func $test (result i32)
    i32.const -1
    i32.load
    return)
  (export "test" (func $test))
  (export "memory" (memory $mem))
)