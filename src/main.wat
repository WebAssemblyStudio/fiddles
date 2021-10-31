(module
   
 (import "io" "fd_write" (func $fd_write (param i32) (param i32) (param i32) (result i32)))
 (import "io" "fd_read" (func $fd_read (param i32) (param i32) (param i32) (result i32)))
 (import "io" "open_path" (func $open_path (param i32) (param i32) (param i32) (result i32)))
 (import "io" "proc_exit" (func $proc_exit (param i32)))

 (import "io" "memory" (memory 1))
 (export "main" (func $main))
  
 (data (i32.const 0) "/dev/input/dev/output")

  (func $main (result i32)
      (call $open_path 
        (i32.const 100)
        (i32.const 0)
        (i32.const 10)
      )
      (i32.const 150)
      (i32.const 5)

    (call $fd_read)

    (call $open_path 
        (i32.const 100)
        (i32.const 10)
        (i32.const 11)
      )
    
    (i32.const 100)
    (i32.load8_s)
    (i32.const 150)
    (i32.const 10)
    (call $fd_write)

    (call $proc_exit (i32.const 2))

    i32.const 1
    return  
  )
 

)