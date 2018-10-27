(module
  (func (result i32)
    (i32.const 8)
    (call 1))

  (func (param i32) (result i32)
    (block
      (get_local 0)
      (i32.const 0)
      (i32.eq)
      (br_if 0)

      (get_local 0)
      (i32.const 1)
      (i32.sub)
      (call 1)

      (get_local 0)
      (i32.mul)
      (return)
    )

    (i32.const 1)
    (return)
  )

  (export "main" (func 0))
)
