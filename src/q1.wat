(module
  (import "console" "log" (func $log (param i32)(result i32)))
  (func $add (param $number1 i32) (param $number2 i32) (result i32)
    get_local $number1
    get_local $number2
    i32.add
    call $log)
  (export "add" (func $add))
)