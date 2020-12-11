(module
  (func $main
    (result i32)
    (local $out i32)
    (local $loop_counter i32)
    (set_local $out (i32.const 0))
    (set_local $loop_counter (i32.const 3))
    (block $loop_wrapper
      (loop $loop
        (set_local $out
          (i32.add
            (get_local $out)
            (i32.const 2)
          )
        )
        (set_local $loop_counter
          (i32.sub
            (get_local $loop_counter)
            (i32.const 1)
          )
        )
        (br_if $loop_wrapper (i32.eq (get_local $loop_counter) (i32.const 0)))
        (br $loop)
      )
    )
    (get_local $out)
  )
  (export "main" (func $main))
)