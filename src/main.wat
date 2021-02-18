(module
  (func $add (param $lh i32) (param $rh i32) (result i32)
    get_local $lh
    get_local $rh
    i32.add)
  (export "add" (func $add))
)