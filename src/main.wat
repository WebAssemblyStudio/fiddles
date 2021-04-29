(module
  (import "console" "log" (func $print (param i32 i32 )))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "hello, sparkles")
  (data (i32.const 15) "you are looking cute today :)")
  (func (export "main")
    i32.const 0
    i32.const 15
    call $print
    i32.const 15
    i32.const 29
    call $print
  )
)
