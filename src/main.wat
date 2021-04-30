(module
  (func $hello_world (param $num1 i32) (result i32)
    get_local $num1
  )
  (export "hello_world"  (func $hello_world))
)