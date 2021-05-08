(module
  (func $helloworld (param $num1 i32) (result i32) 
    get_local $num1
  )
  (export "helloworld" (func $helloworld))
)