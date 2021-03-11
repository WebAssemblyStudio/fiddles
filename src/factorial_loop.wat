(module
  (func $add (result i32)
    (local $n i32)
    (local $i i32)
    (set_local $i (i32.const 1))
    (set_local $n (i32.const 1))
    (block
      (loop
        (set_local $n (i32.mul (get_local $n) (get_local $i)))
        (if
          (i32.eq (get_local $i) (i32.const 5))
          (then (br 2)) ;; takes us to the end of the block
        )
        (set_local $i (i32.add (get_local $i) (i32.const 1)))
        (br 0) ;; takes us to the start of the loop
      )
    )
    (get_local $n) 
  )
  (export "add" (func $add))
)