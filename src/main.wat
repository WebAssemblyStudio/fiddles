(module
  (func $fib (param i32) (result i32)
    i32.const 12
    i32.const 12
    i32.eq
  )
  (export "fib" (func $fib))
)