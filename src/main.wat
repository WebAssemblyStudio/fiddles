(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    if (result i32)
      i32.const 11
    else
      i32.const 9
    end
    get_local $rhs
    i32.add)
  (export "add" (func $add))
)