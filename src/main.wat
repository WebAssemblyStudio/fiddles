(module
  (func $test1 (result i32)
    (i32.reinterpret/f32
      (f32.neg
        (f32.div
          (f32.const -nan:0x7fffb3)
          (f32.const 0x0p+0)
        )
      )
    )
  )
  (func $test2 (result i32)
    (i32.reinterpret/f32
      (f32.div
        (f32.const -nan:0x7fffb3)
        (f32.const -0x0p+0)
      )
    )
  )
  (func $test3 (result i32)
    (i32.reinterpret/f32
      (f32.div
        (f32.const nan:0x7fffb3)
        (f32.const 0x0p+0)
      )
    )
  )
  (export "test1" (func $test1))
  (export "test2" (func $test2))
  (export "test3" (func $test3))
)