(module
  (type $ffiFunc (func (param i32 i32 i32 i32)))

  (import "console" "log" (func $log (param i32)))
  (import "cake" "argc" (global $argc i32))

  (import "basis" "get_arg_count" (func $getArgCount (type $ffiFunc)))
  (import "basis" "get_arg_length" (func $getArgLength (type $ffiFunc)))

  (memory $0 1)
  (export "memory" (memory $0))

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  
  (func $main
    (i32.const 1)
    (i32.const 1)
    (call $add)
    (i32.const 1)
    (call $add)
    (call $log)
    (i32.const 0)
    (i32.const 0)
    (i32.const 0)
    (i32.const 2)
    (call $getArgCount)
    (i32.const 0)
    (i32.load offset=0 align=2)
    call $log
    (i32.const 0)
    (i32.const 0)
    (i32.const 4)
    (i32.const 0)
    (call $getArgLength)
    (i32.const 4)
    (i32.load offset=0 align=2)
    call $log
  )

  (export "add" (func $add))
  (export "main" (func $main))
)