(module
  (func $log (import "imports" "i") (param i32))
  (memory (import "mem" "m") 1)
  (func (export "schleife")
    (local $zaehler i32)
    (set_local $zaehler (i32.const 0))
    (loop $cont
      (set_local $zaehler (i32.add (get_local $zaehler)(i32.const 1)))
      (call $log (get_local $zaehler))
      (br_if $cont (i32.lt_u (get_local $zaehler)(i32.const 10)))
    )
    (call $log (i32.const 5))
  )

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))
)