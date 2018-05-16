(module
  (func $fib (param i32) (result i32)
    get_local 0
    i32.const 2
    i32.le_s
    if (result i32)
      i32.const 1
    else
      get_local 0
      i32.const 1
      i32.sub
      call $fib
      get_local 0
      i32.const 2
      i32.sub
      call $fib
      i32.add
    end
  )
  (export "fib" (func $fib))
)
