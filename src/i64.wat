(module
  (func $plus1 (param $i i64) (result i64)
    get_local $i
    i64.const 1
    i64.add)
  (export "plus1" (func $plus1))
)