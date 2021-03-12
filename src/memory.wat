(module
    (import "console" "log" (func $log (param i32) (param i32)))
    (import "js" "mem" (memory 1))
    (data (i32.const 0) "Hi")
    (func $main (result i32)
      (i32.store (i32.const 2) (i32.const 70)) ;; store 'F' at the end
      (call $log (i32.const 0) (i32.const 2))
      (i32.load (i32.const 2))
    )
    (export "main" (func $main))
)