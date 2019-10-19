(module

  ;; Create 32 Bytes of memory
  (memory 32)

  ;; Store and Load
  (func $myFunction (result i32)

    ;; Store in memory starting from location 0
    (i32.store
      (i32.const 0)
      (i32.const 0xABCDEF) 
      ;; 0xABCDEF takes 3 bytes in the memory
      ;; loc 0 => EF
      ;; loc 1 => CD
      ;; loc 2 => AB
    )

    ;; Store in memory starting from location 3
    (i32.store
      (i32.const 3)
      (i32.const 0x89) 
      ;; 0xEF takes 1 byte in the memory
      ;; loc 3 => 89
    )

    ;; Load 2 bytes starting from location 2
    (i32.load16_u
      (i32.const 2)
    )
  )

  ;; Export function
  (export "myFunction" (func $myFunction))

)