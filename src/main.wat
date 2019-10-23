(module
  (import "env" "native" (func $native))
  (func $test (param $count i32) (result i32)
    (local $iter i32)
    (set_local $iter (i32.const 0))
    (block $label$0
      (loop $label$1
        (call $native)
        (set_local $iter (i32.add (get_local $iter) (i32.const 1)))
        (br_if $label$1 (i32.lt_s (get_local $iter) (get_local $count)))
      )
    )
    (i32.const 0)
  )
  (export "test" (func $test))
)