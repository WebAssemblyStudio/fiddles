(module
  (import "utils" "toString" (func $toString (param i32 i32) (result i32)))
  (import "console" "log" (func $log (param i32)))
  (import "core" "memory" (memory 1))
  (data (i32.const 0) "Hi")
  (func (export "writeHi")
    i32.const 0  ;; pass offset 0 to log
    i32.const 2  ;; pass length 2 to log
    call $toString
    call $log))