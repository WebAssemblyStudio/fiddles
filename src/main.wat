(module
  (func $run (export "run") (param $x i32) (result i32)
    (i32.shl
      (get_local $x)
      (i32.lt_s
        (get_local $x)
        (i32.const 0)
      )
    )
  )
)
