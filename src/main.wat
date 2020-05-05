(module
  (import "io" "print" (func $print (param i32)))
  (func $run
    i32.const 0
    call $print)
  (export "run" (func $run))
)