(module
  (import "func" "log" (func $log (param i32)))
  (func $add (param $a i32) (param $b i32) (result i32) (local $c i32)
    get_local $a
    get_local $b
    i32.add
    tee_local $c
    call $log
    get_local $c
  )
  (export "add" (func $add))
)