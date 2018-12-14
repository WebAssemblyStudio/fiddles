(module
  (import "i64" "plus1" (func $plus1 (param i64) (result i64)))
  (func $addsome (param $i i32) (result i32)
    get_local $i
    i64.extend_s/i32
    call $plus1
    i32.wrap/i64)
  (export "addsome" (func $addsome))
)