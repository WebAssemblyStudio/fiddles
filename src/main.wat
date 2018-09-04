(module
  (memory (export "memory") 1)
  (func $getPosition (param $x i32) (param $y i32) (result i32)
    (i32.add
        (get_local $x)
        (i32.mul
          (get_local $y)
          (i32.const 2)
        )
      )
  )
  (func $getByteOffset (param $x i32) (param $y i32) (result i32)
    (i32.div_u
      (call $getPosition
        (get_local $x)
        (get_local $y)
      )
      (i32.const 32)
    )
  )
  (func $getBitOffset (param $x i32) (param $y i32) (result i32)
    (i32.rem_u
      (call $getPosition
        (get_local $x)
        (get_local $y)
      )
      (i32.const 32)
    )
  )
  (func $setValue (param $x i32) (param $y i32) (param $val i32)
    (i32.store
      (call $getByteOffset
        (get_local $x)
        (get_local $y)
      )
      (i32.and
        (i32.mul
          (i32.const 4294967295)
          (get_local $val)
        )
        (i32.shr_u
          (i32.const 2147483648)
          (call $getBitOffset
            (get_local $x)
            (get_local $y)
          )
        )
      )
    )
  )
  (export "setValue" (func $setValue))
  (func $getValue (param $x i32) (param $y i32) (result i32)
    (i32.gt_u
    (i32.and
      (i32.load
        (call $getByteOffset
          (get_local $x)
          (get_local $y)
        )
      )
      (i32.shr_u
        (i32.const 2147483648)
        (call $getBitOffset
          (get_local $x)
          (get_local $y)
        )
      )
    )
  )
  (export "getValue" (func $getValue))

)