(module
  (memory (export "memory") 1)
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (func $fill
    
  )
  (export "add" (func $add))
)