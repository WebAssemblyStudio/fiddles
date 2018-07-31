(module
  (func $finish (import "eei" "finish") (param i32))
  (func $main (export "main") (result i32)
    i32.const 42
    call $finish
    i32.const -1)
)