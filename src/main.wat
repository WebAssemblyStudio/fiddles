(module
  (func $orig (result i32)
    (i32.reinterpret/f32
      (f32.neg
        (f32.mul
          (f32.const nan:0x7fff82)
          (f32.const 1.0)
        )
      )
    )
  )
  (func $opt (result i32)
    (i32.reinterpret/f32
      (f32.mul
        (f32.const nan:0x7fff82)
        (f32.const -1.0)
      )
    )
  )
  (export "orig" (func $orig))
  (export "opt" (func $opt))
)