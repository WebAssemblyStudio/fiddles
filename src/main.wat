(module
  (type $func_sig (func (param i32 i32) (result i32)) )
  (import "console" "log" (func $log (param i32)))
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (func $main
    i32.const 42
    call $log)
  (global $g01 (mut i32) (i32.const 0))
  (data (i32.const 1024) "hello world")
  (export "add" (func $add))
  (memory $mem 256 256)
  (start $main)
)