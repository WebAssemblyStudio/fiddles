(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add
    i32.const 12
    i32.mul
    i32.div)
  (export "add" (func $add))
)