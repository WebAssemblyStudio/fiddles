(module
  (memory (export "memory") 4)

  (func $render (result)
    (i32.store (i32.const 0) (i32.const 255)))
    
  (export "render" (func $render))
)