(module
  (import "js" "memory" (memory 1))
  (import "gvar" "dir" (global $dir i32))
  (import "gvar" "bitrev_len" (global $bitrev_len i32))
  (import "gvar" "trigtbl_len" (global $trigtbl_len i32))
  (func (export "fft") (param $size i32) (result i32)
    (local $loopcnt i32) (local $tmp0 i32) (local $tmp1 i32) (local $tmp2 i32) (local $tmp3 i32) (local $tmp4 i32)
    (local $reoff i32) (local $imoff i32)
    (local $tmp0re f32) (local $tmp0im f32) (local $tmp1re f32) (local $tmp1im f32)

    (local $flag i32) (set_local $flag (i32.const 0))

    (set_local $reoff (i32.add (get_global $bitrev_len) (get_global $trigtbl_len)))
    (set_local $imoff (i32.add (get_local $reoff) (i32.shl (get_local $size) (i32.const 2))))

    (; Bit-reversed addressing permutation ;)
    (set_local $loopcnt (i32.const 0))
    (loop $bitrevloop
      (set_local $tmp0 (i32.load (i32.shl (get_local $loopcnt) (i32.const 2))))
      (if (i32.gt_u (get_local $loopcnt) (get_local $tmp0)) (block
        (set_local $tmp0re (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $loopcnt) (i32.const 2)))))
        (set_local $tmp0im (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $loopcnt) (i32.const 2)))))
        (set_local $tmp1re (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp0) (i32.const 2)))))
        (set_local $tmp1im (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp0) (i32.const 2)))))
        (f32.store (i32.add (get_local $reoff) (i32.shl (get_local $loopcnt) (i32.const 2))) (get_local $tmp1re))
        (f32.store (i32.add (get_local $imoff) (i32.shl (get_local $loopcnt) (i32.const 2))) (get_local $tmp1im))
        (f32.store (i32.add (get_local $reoff) (i32.shl (get_local $tmp0) (i32.const 2))) (get_local $tmp0re))
        (f32.store (i32.add (get_local $imoff) (i32.shl (get_local $tmp0) (i32.const 2))) (get_local $tmp0im))
      ))
      (set_local $loopcnt (i32.add (get_local $loopcnt) (i32.const 1)))
      (br_if $bitrevloop (i32.gt_u (get_local $size) (get_local $loopcnt)))
    )

    (; Cooley-Tukey decimation-in-time radix-2 FFT ;)
    (set_local $loopcnt (i32.const 1))
    (loop $outerloop
      (set_local $flag (i32.or (i32.lt_u (get_local $size) (get_local $loopcnt)) (get_local $flag)))

      (set_local $tmp1 (i32.div_u (get_local $size) (get_local $loopcnt))) ;; tablestep
      (set_local $tmp0 (i32.const 0))
      (loop $middleloop
        (set_local $tmp2 (get_local $tmp0))
        (set_local $tmp3 (i32.const 0))
        (loop $innerloop
          (set_local $tmp4 (i32.add (get_local $tmp2) (get_local $tmp1)))
          (set_local $tmp1re (f32.add
            (f32.mul
              (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_global $bitrev_len) (i32.shl (get_local $tmp3) (i32.const 2))))
            )
            (f32.mul
              (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_global $bitrev_len) (i32.shl (i32.add (get_local $tmp3) (i32.const 1)) (i32.const 2))))
            )
          ))
          (set_local $tmp1im (f32.sub
            (f32.mul
              (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_global $bitrev_len) (i32.shl (get_local $tmp3) (i32.const 2))))
            )
            (f32.mul
              (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_global $bitrev_len) (i32.shl (i32.add (get_local $tmp3) (i32.const 1)) (i32.const 2))))
            )
          ))
          (f32.store
            (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2)))
            (f32.sub (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp2) (i32.const 2)))) (get_local $tmp1re))
          )
          (f32.store
            (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2)))
            (f32.sub (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp2) (i32.const 2)))) (get_local $tmp1im))
          )
          (f32.store
            (i32.add (get_local $reoff) (i32.shl (get_local $tmp2) (i32.const 2)))
            (f32.add (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp2) (i32.const 2)))) (get_local $tmp1re))
          )
          (f32.store
            (i32.add (get_local $imoff) (i32.shl (get_local $tmp2) (i32.const 2)))
            (f32.add (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp2) (i32.const 2)))) (get_local $tmp1im))
          )
          (set_local $tmp2 (i32.add (get_local $tmp2) (i32.const 1)))
          (set_local $tmp3 (i32.add (get_local $tmp3) (get_local $tmp1)))
          (br_if $innerloop (i32.gt_u (i32.add (get_local $tmp0) (get_local $loopcnt)) (get_local $tmp2)))
        )
        (set_local $tmp0 (i32.add (get_local $tmp0) (get_local $loopcnt)))
        (br_if $middleloop (i32.gt_u (get_local $size) (get_local $tmp0)))
      )
      (set_local $loopcnt (i32.shl (get_local $loopcnt) (i32.const 1)))
      (br_if $outerloop (i32.ge_u (get_local $size) (get_local $loopcnt)))
    )
    (return (get_local $flag))
  )
)
