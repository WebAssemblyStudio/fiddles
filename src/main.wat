(module
  (type $t0 (func (param i32 i32) (result i32)))
  (type $t1 (func))
  (type $t2 (func (param i32) (result i32)))
  (import "env" "rt_add" (func $rt_add (type $t0)))
  (func $_start (export "_start") (type $t1))
  (func $add_two (export "add_two") (type $t2) (param $p0 i32) (result i32)
    get_local $p0
    i32.const 2
    call $rt_add)
  (func $__wasm_call_ctors (type $t1))
  (table $T0 1 1 anyfunc)
  (memory $memory (export "memory") 2)
  (global $g0 (mut i32) (i32.const 66560))
  (global $__heap_base (export "__heap_base") i32 (i32.const 66560))
  (global $__data_end (export "__data_end") i32 (i32.const 1024)))
