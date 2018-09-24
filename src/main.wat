(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))
  (func $fac (param $n i32) (result i32)
    (if (result i32)
      (i32.eq
        (get_local $n)
        (i32.const 1)
      )
      (then
        i32.const 1
      )
      (else
        (get_local $n)
        (i32.const 1)
        (i32.sub)
        (call $fac)
        (get_local $n)
        (i32.mul)
      )
    )
  )
  (export "fac" (func $fac))
  (func $decrement (param $x i32) (result i32)
    get_local $x
    i32.const 1
    i32.sub
  )
  (func $faciter (param $n i32) (result i32)
    (local $x i32)
    (set_local $x (i32.const 1))
    (block
      (loop
        (set_local $x (i32.mul (get_local $x) (get_local $n)))
        (set_local $n (call $decrement (get_local $n)))
        (br_if 1 (i32.eq (get_local $n) (i32.const 1)))
        (br 0)
      )
    )
    (get_local $x)
  )
  (export "faciter" (func $faciter))
)