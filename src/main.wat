(module
  ;; add n to val
  (func $addN (param $val i32) (param $n i32) (result i32)
    loop 
      ;; increment val
      get_local $val
      i32.const 1
      i32.add
      set_local $val

      ;; decrement and maybe loop
      get_local $n
      i32.const 1
      i32.sub
      tee_local $n
      br_if 0
    end
    get_local $val
  )

  (export "addN" (func $addN))
)