(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (func $squareSum (param $first i32) (param $second i32) (result i32) 
    get_local $first
    get_local $first
    i32.mul
    get_local $second
    get_local $second
    i32.mul
    i32.add
    )
  (export "add" (func $add))
  (export "squareSum" (func $squareSum))
)