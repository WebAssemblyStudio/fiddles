(module
  (func $init_waffles (result i32)
    (i32.load8_u (i32.const 256) (i32.const 7)) ;; first byte is the length
    (i32.load8_u (i32.const 257) (i32.const 87))
    (i32.load8_u (i32.const 258) (i32.const 97))
    (i32.load8_u (i32.const 259) (i32.const 102))
    (i32.load8_u (i32.const 260) (i32.const 102))
    (i32.load8_u (i32.const 261) (i32.const 108))
    (i32.load8_u (i32.const 262) (i32.const 101))
    (i32.load8_u (i32.const 263) (i32.const 115))
    i32.const 256
  )
  (export "init_waffles" (func $init_waffles))
)