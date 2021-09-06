(module
  
  (func $fib (param $0 i32) (result i32)
      get_local $0
      i32.const 0
      i32.eq
      if
        i32.const 1
        return
      end

      get_local $0
      i32.const 1
      i32.eq
      if
        i32.const 1
        return
      end

      get_local $0
      i32.const 1
      i32.sub
      call $fib
      get_local $0
      i32.const 2
      i32.sub
      call $fib
      i32.add

  )
  (export "fib" (func $fib))
)