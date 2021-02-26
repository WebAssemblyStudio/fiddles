(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs

    call $func22
    i32.add)

  (func $func22 (param $a1 i32) (param $a2 i32) (result i32 i32)
  (get_local $a1)
  (get_local $a2)
  )
  (export "add" (func $add))
)