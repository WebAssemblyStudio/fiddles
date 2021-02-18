(module
  (func $add (param $num1 i32) (param $num2 i32) (result i32)
    get_local $num1
    get_local $num2
    i32.add
  )
  (export "add" (func $add))
)