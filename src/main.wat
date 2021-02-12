(module
  (func $mul4 (export "mul4") (param $cond i32) (param $z i32) (result i32)
    (local $x i32) (local $y i32)

    get_local $cond
    if
      (set_local $x
        (i32.mul
          (i32.const 3)
          (get_local $z)
        )
      )
      (set_local $y
        (get_local $z)
      )
    else
      (set_local $x
        (i32.mul
          (i32.const 2)
          (get_local $z)
        )
      )
      (set_local $y
        (i32.mul
          (i32.const 2)
          (get_local $z)
        )
      )
    end

    (i32.add
      (get_local $x)
      (get_local $y)
    )
  )
)
