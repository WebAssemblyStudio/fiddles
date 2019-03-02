(module
  (type $t0 (func))
  (type $t1 (func (param i32) (result i32)))
  (func $__wasm_call_ctors (type $t0))
  (func $fib (export "fib") (type $t1) (param $p0 i32) (result i32)
    block $B0
      get_local $p0
      i32.const 2
      i32.ge_s
      br_if $B0
      get_local $p0
      return
    end
    get_local $p0
    i32.const -1
    i32.add
    call $fib
    get_local $p0
    i32.const -2
    i32.add
    call $fib
    i32.add)
  (table $T0 1 1 anyfunc)
  (memory $memory (export "memory") 2)
  (global $g0 (mut i32) (i32.const 66560))
  (global $__heap_base (export "__heap_base") i32 (i32.const 66560))
  (global $__data_end (export "__data_end") i32 (i32.const 1024)))
