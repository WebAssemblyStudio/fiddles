(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)

  (func $fib (param $n i32) (result i32)
    (local $a i32)
    (local $b i32)
    i32.const 1
    set_local $a
    i32.const 2
    set_local $b
    get_local $a
    get_local $b
    i32.add
    get_local $n
    i32.add
  )

  (export "fib" (func $fib))
)