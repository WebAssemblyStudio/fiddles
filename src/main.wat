(module
   
 (import "io" "fd_write" (func $fd_write (param i32) (param i32) (param i32) (result i32)))
  (import "io" "fd_read" (func $fd_read (param i32) (param i32) (param i32) (result i32)))

(import "io" "memory" (memory 1))
 (export "main" (func $main))
  
 (data (i32.const 10) "Hello World")

  (func $main (result i32)
    (call $fd_write
      (i32.const 1)
      (i32.const 0)
      (i32.const 5)
    )
    (call $fd_read
      (i32.const 0)
      (i32.const 0)
      (i32.const 5)
    )
    (call $fd_write
      (i32.const 1)
      (i32.const 0)
      (i32.const 5)
    )

    i32.const 0
    return  
  )
 

)