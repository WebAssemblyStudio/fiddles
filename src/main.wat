(module
  (func (export "test") (param $i i32) (result i32)
    (block (result i32)
      i32.const 1
      br 0
      i32.const 2
    )
  )
)