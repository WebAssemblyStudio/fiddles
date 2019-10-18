(module
  (import "f" "x" (global $a (mut i32)))
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add
    get_global $a
    i32.add
  )
  (export "add" (func $add))
)