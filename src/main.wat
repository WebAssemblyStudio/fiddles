(module
  (import "console" "log" (func $log (param i32)))
  (import "cakeml" "argc" (global $argc i32))

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  
  (func $main
    (i32.const 1)
    (i32.const 1)
    (call $add)
    (i32.const 1)
    (call $add)
    (call $log)
  )

  (export "add" (func $add))
  (export "main" (func $main))
)