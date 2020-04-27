(module
  (func $min (param $x i32) (result i32)
    (select
      (i32.shl
        (get_local $x)
        (i32.const 1)
      )
      (get_local $x)
      (i32.lt_s
        (get_local $x)
        (i32.const 0)
      )
    )
  )
  (export "run" (func $min))
)