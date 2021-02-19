(module
(func $subtract (param $num1 i32) (result i32)
  get_local $num1 
  i32.const 1
  i32.sub
)
(export "subtract" (func $subtract))
)