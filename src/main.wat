(module
  (import "js" "mem" (memory 1))
  (import "console" "log" (func $log (param i32 i32)))
  (data (i32.const 0) "Hi")
  (func $writeHi
    i32.const 0  ;; pass offset 0 to log
    i32.const 2  ;; pass length 2 to log
    call $log
  )
  (export "writeHi" (func $writeHi))
)
