(module
 (type $0 (func))
 (type $1 (func (result i32)))
 (type $2 (func (param i32) (result i32)))
 (global $global$0 (mut i32) (i32.const 66560))
 (global $global$1 i32 (i32.const 66560))
 (global $global$2 i32 (i32.const 1024))
 (table 1 1 anyfunc)
 (memory $0 2)
 (export "memory" (memory $0))
 (export "__heap_base" (global $global$1))
 (export "__data_end" (global $global$2))
 (export "main" (func $main))
 (export "fibonacci" (func $fibonacci))
 (func $__wasm_call_ctors (; 0 ;) (type $0)
 )
 (func $main (; 1 ;) (type $1) (result i32)
  (i32.const 42)
 )
 (func $fibonacci (; 2 ;) (type $2) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (set_local $var$1
   (i32.const 1)
  )
  (block $label$1
   (br_if $label$1
    (i32.lt_s
     (get_local $var$0)
     (i32.const 1)
    )
   )
   (set_local $var$2
    (i32.const 0)
   )
   (loop $label$2
    (set_local $var$1
     (i32.add
      (tee_local $var$3
       (get_local $var$1)
      )
      (get_local $var$2)
     )
    )
    (set_local $var$2
     (get_local $var$3)
    )
    (br_if $label$2
     (tee_local $var$0
      (i32.add
       (get_local $var$0)
       (i32.const -1)
      )
     )
    )
   )
   (return
    (get_local $var$3)
   )
  )
  (i32.const 0)
 )
 ;; custom section ".debug_info", size 152
 ;; custom section ".debug_macinfo", size 1
 ;; custom section ".debug_loc", size 63
 ;; custom section ".debug_ranges", size 24
 ;; custom section ".debug_abbrev", size 112
 ;; custom section ".debug_line", size 135
 ;; custom section ".debug_str", size 121
)
