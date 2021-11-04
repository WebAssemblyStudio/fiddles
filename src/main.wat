(module $hello

    (import "wasi_unstable" "fd_write"
        (func $fd_write (param i32 i32 i32 i32) (result i32))
    )

    (import "env" "memory" (memory 1))

    (data (i32.const 8) "My first WASI module!\n")

    (func $main (export "_start")
        
        (i32.store (i32.const 0) (i32.const 8))  
        (i32.store (i32.const 4) (i32.const 22)) 

        (call $fd_write
            (i32.const 1) 
            (i32.const 0) 
            (i32.const 1) 
            (i32.const 30) 
        )
        drop 
    )
)