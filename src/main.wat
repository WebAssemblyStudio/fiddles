(module
  (func $add (param $firstnum i32) (param $secondnum i32) (result i32)
    get_local $firstnum
    get_local $secondnum
    i32.add)
  (export "add" (func 0))
)