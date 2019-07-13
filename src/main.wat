(module
  (memory (export "screenbuf") 2)

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))
  
  (func $loopRow

    (set_local $x (i32.const 0))

    (block 
      (loop 

        (set_local $x (call $increment (get_local $x)))
        (br_if 1 (i32.eq (get_local $x) (i32.const 0)))
        (br 0)
      )
    )
  )

  (func $main (result i32)
    (call $loopRow)
    i32.const 0
    i32.const 0xff0000ff
    i32.store
    i32.const 10
  )
  (export "main" (func $main))

)