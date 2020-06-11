(module
  (func $start (param $a i32) (param $b i32) (param $c i32) (result i32)
  ;;a+b/c
  get_local $a
  get_local $b
  i32.add
  get_local $c
  i32.div_u)

  (export "start" (func $start))
)