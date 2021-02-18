(module
  (func $helloWorld (param $num1 i32) (result i32)
    get_local $num1
  )
  (export "helloWorld" (func $helloWorld))
)