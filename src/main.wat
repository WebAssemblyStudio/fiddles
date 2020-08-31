(module
  (func $add (param $left i32) (param $right i32) (result i32)
    i32.const 15
    get_local $left
    i32.add
    get_local $right
    i32.const 69
    i32.add
    i32.add)
    (func $add2 (param $left i32) (param $middle i32 ) (param $right i32) (result i32)
    i32.const 4
    get_local $left
    i32.add
    ;; Stack now contains `4 + left`.
    i32.const 94
    get_local $middle
    i32.add
    ;; Stack now contains `94 + middle` then `4 + left`
    i32.const 741
    get_local $right
    i32.add 
    i32.add
    i32.add 

    )
    (func $add3 (param $a i32) (param $b i32)   (result i32) (local $s1 i32) (local $s2 i32)
      i32.const 148
      set_local $s1
      i32.const 175
      set_local $s2

      get_local $s1
      get_local $s2
      i32.add
      

    )
    (func $gt (param $left i32) (param $right i32) (result i32)
      (
      i32.le_s
        (get_local $left)
        (get_local $right) 
      )
      (if (result i32)
        (then
          (i32.const 2)
      )
        (else
          (i32.const 1)
      )
      )
      i32.const 14
      i32.mul
    )
    (export "gt" (func $gt))
    (export "add3" (func $add3))
    (export "add2" (func $add2))
  (export "add" (func $add))
)