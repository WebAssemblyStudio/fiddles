(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (func $fact (param $x i32) (result i32)
    (if (result i32)
      (i32.eqz (get_local $x))
      (i32.const 1)
      (i32.mul 
        (call $fact
          (i32.sub 
            (get_local $x) 
            (i32.const 1)
          )
        )
        (get_local $x)
      )
    )
  )
  (export "add" (func $add))
  (export "fact" (func $fact))
)