(module
  (func $add (export "fib") (param $n i32) (result i32) (local $n1 i32) (local $n2 i32)
    i32.const 1 ;;1
    i32.const 1 ;;1
    loop
      get_local $n2 ;;2
      set_local $n1 ;;1
      get_local $n1 ;;2
      i32.add ;;1
      tee_local $n2 ;;1
      get_local $n ;;2
      if ;;1
        i32.const 1
        i32.sub
        set_local $n
      else
        return (get_local $n1)
      end
    end
  )
)