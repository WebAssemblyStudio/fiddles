(module
  (import "unity" "read" (func $read (result f32)))
  (import "unity" "write" (func $write (param f32)))
  (func $main
    call $read
    f32.const 0.01
    f32.add
    call $write
  )
  (export "main" (func $main))
)
