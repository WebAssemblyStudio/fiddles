(module
  (func $collatz (param $n i32) (param $s i32) (result i32)

    get_local $n
    i32.const 1
    i32.eq

    if (result i32)
      get_local $s
      return
    else
      get_local $n
      i32.const 2
      i32.rem_u
      i32.eqz
      if (result i32)
        get_local $n
        i32.const 2
        i32.div_u
        get_local $s
        i32.const 1
        i32.add
        call $collatz
        return
      else
        i32.const 3
        get_local $n
        i32.mul
        i32.const 1
        i32.add
        get_local $s
        i32.const 1
        i32.add
        call $collatz
        return      
      end
    end



    )
  (export "collatz" (func $collatz))
)