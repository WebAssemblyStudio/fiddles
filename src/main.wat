(module
  (func $fibo (param $n i32) (result i32)

    get_local $n
    i32.const 0
    i32.eq
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
        i32.const 1
        i32.sub
        call $fibo
        get_local $n
        i32.const 2
        i32.sub
        call $fibo
        i32.add
      end
    end

  )  
  (export "fibo" (func $fibo))
)