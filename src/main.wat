(module
  (memory $mem (data "\00\00\00\00\01\00\00\00"))
  (export "mem" (memory $mem))
  (func $fibonacciV2 (param $n i32) (result i32)
    get_local $n
    i32.const 1
    i32.sub
    call $fib
  )
  (func $fib (param $n i32) (result i32)
    get_local $n
    i32.eqz
    if (result i32)
      i32.const 0
    else
      get_local $n
      i32.const 1
      i32.eq
      if (result i32)
        i32.const 1
      else
        get_local $n
        i32.const 4
        i32.mul
        i32.load
        i32.eqz
        if (result i32)
          get_local $n
          i32.const 4
          i32.mul
          get_local $n
          i32.const 1
          i32.sub
          call $fib
          get_local $n
          i32.const 2
          i32.sub
          call $fib
          i32.add
          i32.store
          get_local $n
          i32.const 4
          i32.mul
          i32.load
        else
          get_local $n
          i32.const 4
          i32.mul
          i32.load
        end
      end
    end
  )
  (func $run (result i32)
    i32.const 15
    call $fibonacciV2
    drop
    i32.const 20
    call $fibonacciV2
    drop
    i32.const 50
    call $fibonacciV2
  )
  (export "run" (func $run))
)