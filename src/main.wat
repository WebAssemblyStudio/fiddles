(module
  (func $add (param $a i32) (param $b i32) (result i32)
    (block $B0
      (br_if $B0
        (get_local $a)
      )
      (set_local $a
        (i32.add
          (get_local $a)
          (i32.const 1)
        )
      )
    )

    (i32.ge_u
      (get_local $a)
      (i32.const 1)
    )
    if (result i32)
      (i32.const 2)
    else
      (i32.const 3)
    end
  )
  (export "add" (func $add))
)
