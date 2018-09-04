(module
  (memory (export "memory") 1)
  (func $getByteOffset (param $x i32) (param $y i32) (result i32)
    (i32.div_u
      (i32.add
        (get_local $x)
        (i32.mul
          (get_local $y)
          (i32.const 2)
        )
      )
      (i32.const 4)
    )
  )
  (func $storeValue (param $x i32) (param $y i32) (param $val i32)
    (i32.store
      (call $getOffset
        (get_local $x)
        (get_local $y)
      )
      (get_local $val)
    )
  )
  (export "storeValue" $storeValue)
  (func $getValue (param $x i32) (param $y i32) (result i32)
    (i32.load
      (call $getOffset
        (get_local $x)
        (get_local $y)
      )
    )
  )
  (export "getValue" $getValue)

)