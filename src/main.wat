(module
  (func $add (param $a i32) (result i32)
    (i32.div_s
      (get_local $a)
      (i32.const 0)
    )
  )
  (export "add" (func $add))
)