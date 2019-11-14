(module
  (memory $mem 1)
  (export "mem" (memory $mem))
  (func $fibonacci (param $n i32) (param $offset i32) (result i32) (local $counter i32)
    get_local $n
    i32.const 1
    i32.sub
    set_local $n
    get_local $offset
    i32.const 0
    i32.store8
    get_local $offset
    i32.const 1
    i32.store8 offset=1
    i32.const 1
    set_local $counter
    loop $main
      get_local $counter
      i32.const 1
      i32.add
      get_local $offset
      i32.add
      get_local $counter
      get_local $offset
      i32.add
      i32.load8_u
      get_local $counter
      get_local $offset
      i32.const 1
      i32.sub
      i32.add
      i32.load8_u
      i32.add
      i32.store8
      get_local $counter
      i32.const 1
      i32.add
      tee_local $counter
      get_local $n
      i32.lt_u
      br_if $main
    end
    get_local $counter
    get_local $offset
    i32.add
    i32.load8_u
  )
  (func $run (result i32)
    i32.const 10
    i32.const 0
    call $fibonacci
  )
  (export "run" (func $run))
)