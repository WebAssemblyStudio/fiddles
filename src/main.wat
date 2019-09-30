(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    (local $i i32)
    (local $max i32)
    (local $s i32)
    (set_local $i (i32.const 0))
    (set_local $s (i32.const 0))
    (set_local $max (i32.const 100000))
    (block $block (loop $loop
      (br_if $block (i32.gt_u (get_local $i) (get_local $max)))
      (set_local $s (i32.add (get_local $s) (get_local $i)))
      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (br $loop)
    ))
    ;;get_local $lhs
    ;;get_local $rhs
    ;;i32.add
    (get_local $s)
  )
  (export "add" (func $add))
)