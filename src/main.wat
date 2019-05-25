(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))

  (func $addf (param $lhs f32) (param $rhs f32) (result f32)
    get_local $lhs
    get_local $rhs
    f32.add)
  (export "addf" (func $addf))

  (func $addcf (result f32)
    f32.const 0.1
    f32.const 0.2
    f32.add)
  (export "addcf" (func $addcf))

  (func $addcd (result f64)
    f64.const 0.1
    f64.const 0.2
    f64.add)
  (export "addcd" (func $addcd))
)
