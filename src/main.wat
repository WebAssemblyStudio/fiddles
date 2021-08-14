(module
  (func $random (import "imports" "random") (result f32))
  (func $throwNeedle (param $rep i32) (result i32)
    (local $c i32)
    (local $i i32)
    (local $x f32)
    (local $y f32)
    (local $d f32)
    (block $block
      (loop $loop
        (set_local $x (call $random))
        (set_local $y (call $random))
        (set_local $d
          (f32.add 
            (f32.mul (get_local $x) (get_local $x))
            (f32.mul (get_local $y) (get_local $y))
          )
        )
        (if
          (f32.le (get_local $d) (f32.const 1))
          (set_local $c (i32.add (get_local $c) (i32.const 1)))
        )
        (set_local $i (i32.add (get_local $i) (i32.const 1)))
        (br_if $block (i32.ge_u (get_local $i) (get_local $rep)))
        (br $loop)
      )
    )
    (return (get_local $c))
  )
  (export "throwNeedle" (func $throwNeedle))
)