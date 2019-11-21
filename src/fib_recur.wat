(module
  (memory $mem (data "\00\00\00\00\01\00\00\00"))
  (export "mem" (memory $mem))
  (func $fibonacci (param $n i32) (result i32)
    get_local $n
    i32.const 1
    i32.sub
    call $fib
  )
  (func $fib (param $n i32) (result i32) (local $memSlot i32) (local $temp i32)
    get_local $n
    i32.eqz
    if (result i32)
      i32.const 0
    else
      get_local $n
      i32.const 4
      i32.mul
      tee_local $memSlot
      i32.load
      tee_local $temp
      i32.eqz
      if
        get_local $memSlot
        get_local $n
        i32.const 1
        i32.sub
        call $fib
        get_local $n
        i32.const 2
        i32.sub
        call $fib
        i32.add
        tee_local $temp
        i32.store
      end
      get_local $temp
    end
  )
  (func $run (result i32)
    i32.const 15
    call $fibonacci
    drop
    i32.const 20
    call $fibonacci
    drop
    i32.const 47
    call $fibonacci
  )
  (export "run" (func $run))
  (export "fibonacci" (func $fibonacci))
)