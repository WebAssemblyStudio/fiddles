(module
  (import "console" "log" (func $log (param i32)))
  (memory 1)
  (func $addTwo (export "addTwo") (param $n1 i32) (param $n2 i32) (result i32)
    i32.const 64

    get_local $n1
    get_local $n2
    i32.add

    i32.store

    i32.const 64
    i32.load
  )
  (func (export "logIt")
    i32.const 16
    i32.const 8
    call $addTwo
    call $log
    
    i32.const 64
    i32.load
    call $log
    
    )
)