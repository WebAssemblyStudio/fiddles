(module
  (import "js" "mem" (memory 1))
  (import "console" "log" (func $log (param i32 i32)))
  (data (i32.const 0) "Hello World")
  (func $writeHi
    i32.const 0  ;; pass offset 0 to log
    i32.const 11  ;; pass length 11 to log
    call $log
  )
  (export "writeHi" (func $writeHi))
)
