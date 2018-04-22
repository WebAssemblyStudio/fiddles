(module
  (type (;0;) (func))
  (type (;1;) (func (result i32)))
  (type (;2;) (func (param i32)))
  (import "env" "memory" (memory (;0;) 2))
  (import "env" "_start" (func $_start (type 0)))
  (func $__wasm_call_ctors (type 0))
  (func $Main (type 1) (result i32)
    (local i32 i32)
    get_global 0
    i32.const 16
    i32.sub
    tee_local 0
    set_global 0
    get_local 0
    i32.const 12
    i32.add
    call $Function$85628
    get_local 0
    i32.load offset=12
    set_local 1
    get_local 0
    i32.const 16
    i32.add
    set_global 0
    get_local 1)
  (func $Function$85628 (type 2) (param i32)
    get_local 0
    i32.const 66
    i32.store)
  (table (;0;) 1 1 anyfunc)
  (global (;0;) (mut i32) (i32.const 66560))
  (global (;1;) i32 (i32.const 66560))
  (global (;2;) i32 (i32.const 1024))
  (export "__heap_base" (global 1))
  (export "__data_end" (global 2))
  (export "Main" (func $Main))
  (export "Function$85628" (func $Function$85628)))
