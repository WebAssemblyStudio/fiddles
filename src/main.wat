(module
  (func $add (param $x i32) (result i32) (local $y i32) (local $z i32)
    (set_local $y
      (i32.const 3)
    )

    (set_local $z
      (i32.add
        (get_local $x)
        (get_local $y)
      )
    )

    (i32.le_u
      (get_local $z)
      (i32.const 5)
    )
    if
      (set_local $y
        (i32.sub
          (get_local $z)
          (get_local $x)
        )
      )
    else
      (set_local $x
        (i32.sub
          (get_local $z)
          (i32.const 3)
        )
      )
    end

    (tee_local $y
      (i32.sub
        (get_local $z)
        (get_local $x)
      )
    )
  )
  (export "add" (func $add))
)