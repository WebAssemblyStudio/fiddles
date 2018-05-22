(module
  (import "console" "log" (func $log (param i32)))
  (func $addTwo (export "addTwo") (param $n1 i32) (param $n2 i32) (result i32)
    get_local $n1
    get_local $n2
    i32.add
  )
  (func (export "logIt")
    i32.const 16
    i32.const 8
    call $addTwo
    call $log)
)