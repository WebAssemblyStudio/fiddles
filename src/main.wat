(module
  (type $t0 (func (result i32)))

  (func $what (type $t0) (result i32) i32.const 0)
  (export "what" (func $what))

  (func $main (type $t0) (result i32) call $what)
  (export "main" (func $main))

  (table $T0 1 1 anyfunc)
  (memory $memory (export "memory") 2)
  (global $g0 (mut i32) (i32.const 66576))
  (global $__heap_base (export "__heap_base") i32 (i32.const 66576))
  (global $__data_end (export "__data_end") i32 (i32.const 1027))

  (data (i32.const 0) "hm\00")
  (data (i32.const 3) "lol\00")
)