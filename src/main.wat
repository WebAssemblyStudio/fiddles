(module
  (import "console" "log" (func $log (param i32 i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Yooo")
  (func (export "writeYo")
    i32.const 0
    i32.const 4
    call $log)
)