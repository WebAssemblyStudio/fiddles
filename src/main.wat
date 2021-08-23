(module
  (func $stuff (result i32)
    (if (result i32)
      (i32.const 0)   ;; condition 
      (then           ;; true branch
        i32.const 10
      )
      (else           ;; false branch
        i32.const 12
      )
    )
    i32.const 20
    i32.add
  )
  (export "stuff" (func $stuff))
)