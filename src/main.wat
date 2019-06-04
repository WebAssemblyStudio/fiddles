(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))

   (func $get (param $0 i32) (result i32)
    local.get $0
    i32.load8_u
   )
(export "get" (func $get))
)