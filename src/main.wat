(module
  (func (result i32) (local i32)
    (i32.const 3)
    (i32.const 7)
    (call 1))

  (func (param i32) (param i32) (result i32)
    (get_local 0)
    (get_local 1)
    (i32.sub))

  (export "main" (func 0))
)
