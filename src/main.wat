(module
	(export "fib" (func $fib))
	(func $fib (param $n i32) (result i32)
    (local $i i32) (local $p1 i32) (local $p2 i32) (local $temp i32)
		(if
			(i32.lt_s
				(get_local $n)
				(i32.const 2)
			)
			(return
				(i32.const 1)
			)
		)
    
    (set_local $i
      (i32.sub
        (get_local $n)
        (i32.const 2)
      )
    )
    (set_local $p1 (i32.const 1))
    (set_local $p2 (i32.const 1))
		(block $block
      (loop $loop
        (br_if $block
          (i32.ge_u
            (get_local $i)
            (get_local $n)
          )
        )
        (set_local $temp
          (i32.add
            (get_local $p1)
            (get_local $p2)
          )
        )
        (set_local $p1
          (get_local $p2)
        )
        (set_local $p2
          (get_local $temp)
        )
        (set_local $i
          (i32.add
            (get_local $i)
            (i32.const 1)
          )
        )
        (br $loop)
      )
		)
    (return (get_local $p1))
	)
)
