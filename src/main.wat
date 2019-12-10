(module


  (func $test (param f64 f64) (result f64) (local f64)
    get_local 0
    get_local 1
    f64.sub
    set_local 2
    get_local 2
    f64.const 1
    f64.eq
    if
      get_local 0
      f64.const 3.0
      f64.add
      return
    end
    get_local 0
    f64.const 1.0
    f64.sub
    return
  )
  (export "test" (func $test))

  (func $test2 (param f64 f64) (result f64) (local f64)
    f64.const 80
    f64.const 12
    f64.sub
    return
  )
  (export "test2" (func $test2))


)