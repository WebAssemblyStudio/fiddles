(module
  (memory (export "screenbuf") 2)
  (global $bytecolordepth i32 i32.const 4)
  (global $width i32 i32.const 100)
  (global $height i32 i32.const 100)
  (global $shift (mut i32) i32.const 0)
  
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))
  
  (func $increment (param $lhs i32) (result i32)
    get_local $lhs
    i32.const 1
    i32.add
  )

  (func $setpix (param $x i32) (param $y i32) (param $color i32)
    get_global $width
    get_local $y
    i32.mul
    get_local $x
    i32.add
    get_global $bytecolordepth
    i32.mul
    get_local $color
    i32.store
  )

  (func $loopcol (param $y i32)
    (local $x i32)
    (set_local $x (i32.const 0))

    (block 
      (loop
         
        (call $setpix (get_local $x) (get_local $y) (i32.or (i32.shl (i32.xor (get_local $x) (get_local $y)) (get_global $shift)) (i32.const 0xff000000) ))
        (set_local $x (call $increment (get_local $x)))
        (br_if 1 (i32.eq (get_local $x) (i32.const 100)))
        (br 0)
      )
    )
  )

  (func $looprow
    (local $y i32)
    (set_local $y (i32.const 0))

    (block 
      (loop
         
        (call $loopcol (get_local $y))
        (set_local $y (call $increment (get_local $y)))
      
        (br_if 1 (i32.eq (get_local $y) (i32.const 100)))
        (br 0)
      )
    )
  )


  (func $main (result i32)
    (call $looprow)
    
    (set_global $shift (call $increment (get_global $shift)))
    (if 
      (i32.gt_u
        (get_global $shift)
        (i32.const 16)
      )
      (then
        (set_global $shift (i32.const 0))
      )
    ) 
    
    (call $setpix (i32.const 5) (i32.const 0) (i32.const 0xffff0000))
    i32.const 0
    i32.const 0xff0000ff
    i32.store
    i32.const 11
  )
  (export "main" (func $main))

)