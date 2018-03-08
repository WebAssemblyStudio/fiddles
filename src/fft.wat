(module
  (import "js" "memory" (memory 1))
  (func (export "fft") (param $size i32) (param $dir f32)
    (local $loopcnt i32) (local $tmp0 i32) (local $tmp1 i32) (local $tmp2 i32) (local $tmp3 i32) (local $tmp4 i32)
    (local $reoff i32) (local $imoff i32) (local $tbl_len i32)
    (local $tmp0re f32) (local $tmp0im f32) (local $tmp1re f32) (local $tmp1im f32)

    (set_local $tbl_len (i32.shl (get_local $size) (i32.const 2)))
    (set_local $reoff (i32.shl (get_local $tbl_len) (i32.const 1)))
    (set_local $imoff (i32.add (get_local $reoff) (get_local $tbl_len)))

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
    (set_local $loopcnt (i32.const 1)) ;; s
    (loop $outerloop
      (set_local $tmp1 (i32.div_u (get_local $size) (get_local $loopcnt))) ;; step ($size := n)
      (set_local $tmp0 (i32.const 0)) ;; i
      (loop $middleloop
        (set_local $tmp2 (get_local $tmp0)) ;; j
        (set_local $tmp3 (i32.const 0)) ;; k
        (loop $innerloop
          (set_local $tmp4 (i32.add (get_local $tmp2) (get_local $loopcnt))) ;; l
          (set_local $tmp1re (f32.add ;; tmp
            (f32.mul
              (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_local $tbl_len) (i32.shl (get_local $tmp3) (i32.const 2))))
            )
            (f32.mul (get_local $dir) (f32.mul
              (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_local $tbl_len) (i32.shl (i32.add (get_local $tmp3) (i32.const 1)) (i32.const 2))))
            ))
          ))
          (set_local $tmp1im (f32.sub ;; tmp2
            (f32.mul
              (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_local $tbl_len) (i32.shl (get_local $tmp3) (i32.const 2))))
            )
            (f32.mul (get_local $dir) (f32.mul
              (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2))))
              (f32.load (i32.add (get_local $tbl_len) (i32.shl (i32.add (get_local $tmp3) (i32.const 1)) (i32.const 2))))
            ))
          ))
          (set_local $tmp0re (f32.load (i32.add (get_local $reoff) (i32.shl (get_local $tmp2) (i32.const 2)))))
          (set_local $tmp0im (f32.load (i32.add (get_local $imoff) (i32.shl (get_local $tmp2) (i32.const 2)))))
          (f32.store
            (i32.add (get_local $reoff) (i32.shl (get_local $tmp4) (i32.const 2)))
            (f32.sub (get_local $tmp0re) (get_local $tmp1re))
          )
          (f32.store
            (i32.add (get_local $imoff) (i32.shl (get_local $tmp4) (i32.const 2)))
            (f32.sub (get_local $tmp0im) (get_local $tmp1im))
          )
          (f32.store
            (i32.add (get_local $reoff) (i32.shl (get_local $tmp2) (i32.const 2)))
            (f32.add (get_local $tmp0re) (get_local $tmp1re))
          )
          (f32.store
            (i32.add (get_local $imoff) (i32.shl (get_local $tmp2) (i32.const 2)))
            (f32.add (get_local $tmp0im) (get_local $tmp1im))
          )
          (set_local $tmp2 (i32.add (get_local $tmp2) (i32.const 1)))
          (set_local $tmp3 (i32.add (get_local $tmp3) (get_local $tmp1)))
          (br_if $innerloop (i32.gt_u (i32.add (get_local $tmp0) (get_local $loopcnt)) (get_local $tmp2)))
        )
        (set_local $tmp0 (i32.add (get_local $tmp0) (i32.shl (get_local $loopcnt) (i32.const 1))))
        (br_if $middleloop (i32.gt_u (get_local $size) (get_local $tmp0)))
      )
      (set_local $loopcnt (i32.shl (get_local $loopcnt) (i32.const 1)))
      (br_if $outerloop (i32.gt_u (get_local $size) (get_local $loopcnt)))
    )

    (; Scaling for forward transform ;)
    (set_local $loopcnt (get_local $size))
    (if (f32.eq (get_local $dir) (f32.const -1)) (loop $scaleloop
      (set_local $loopcnt (i32.sub (get_local $loopcnt) (i32.const 1)))
      (set_local $tmp0 (i32.add (get_local $reoff) (i32.shl (get_local $loopcnt) (i32.const 2))))
      (set_local $tmp1 (i32.add (get_local $imoff) (i32.shl (get_local $loopcnt) (i32.const 2))))
      (f32.store (get_local $tmp0) (f32.div (f32.load (get_local $tmp0)) (f32.convert_u/i32 (get_local $size))))
      (f32.store (get_local $tmp1) (f32.div (f32.load (get_local $tmp1)) (f32.convert_u/i32 (get_local $size))))
      (br_if $scaleloop (get_local $loopcnt))
    ))
  )
)
