(module
 (type $0 (func))
 (type $1 (func (result i32)))
 (global $global$0 (mut i32) (i32.const 66560))
 (global $global$1 i32 (i32.const 66560))
 (global $global$2 i32 (i32.const 1024))
 (table 1 1 anyfunc)
 (memory $0 2)
 (export "memory" (memory $0))
 (export "__heap_base" (global $global$1))
 (export "__data_end" (global $global$2))
 (export "main" (func $main))
 (func $__wasm_call_ctors (; 0 ;) (type $0)
 )
 (func $main (; 1 ;) (type $1) (result i32)
  (i32.const 42)
 )
 ;; custom section ".debug_info", size 65
 ;; custom section ".debug_macinfo", size 1
 ;; custom section ".debug_abbrev", size 50
 ;; custom section ".debug_line", size 82
 ;; custom section ".debug_str", size 101
)
