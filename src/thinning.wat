;;"========================================================";;
;;"     SKELETONIZATION WITH HANDWRITTEN WEBASSEMBLY       ";;
;;" `thinning.wat`   Lingdong Huang 2020     Public Domain ";;
;;"========================================================";;
;;" Binary image thinning (skeletonization) in-place.      ";;
;;" Implements Zhang-Suen algorithm.                       ";;
;;" http://agcggs680.pbworks.com/f/Zhan-Suen_algorithm.pdf ";;
;;"-------------------------------------------------------=";;

(module
  ;; "16 pages = 16 x 64kb = max dimension 1024x1024 (pixel=1 byte)"
  (memory $mem 16)

  ;; "pixels are stored as 8-bit row-major array in memory"
  ;; "reading a pixel: mem[i=y*w+x]"
  (func $get_pixel (param $w i32) (param $x i32) (param $y i32) (result i32)
    (i32.load8_u (i32.add
      (i32.mul (get_local $w) (get_local $y))
      (get_local $x)
    ))
  )

  ;; "writing a pixel: mem[i=y*w+x]=v"
  (func $set_pixel (param $w i32) (param $x i32) (param $y i32) (param $v i32)
    (i32.store8 (i32.add
      (i32.mul (get_local $w) (get_local $y))
      (get_local $x)
    ) (get_local $v))
  )

  ;; "one iteration of the thinning algorithm"
  ;; "w: width, h: height, iter: 0=even-subiteration, 1=odd-subiteration"
  ;; "returns 0 if no further thinning possible (finished), 1 otherwise"
  (func $thinning_zs_iteration (param $w i32) (param $h i32) (param $iter i32) (result i32)
    ;; "local variable declarations"
    ;; "iterators"
    (local $i  i32) (local $j  i32)
    ;; "pixel Moore neighborhood"
    (local $p2 i32) (local $p3 i32) (local $p4 i32) (local $p5 i32) 
    (local $p6 i32) (local $p7 i32) (local $p8 i32) (local $p9 i32)
    ;; "temporary computation results"
    (local $A  i32) (local $B  i32)
    (local $m1 i32) (local $m2 i32)
    ;; "bools for updating image and determining stop condition"
    (local $diff  i32)
    (local $mark  i32)
    (local $neu   i32)
    (local $old   i32)

    (set_local $diff (i32.const 0))
    
    ;; "raster scan the image (loop over every pixel)"

    ;; "for (i = 1; i < h-1; i++)"
    (set_local $i (i32.const 1))
    loop $loop_i

      ;; "for (j = 1; j < w-1; j++)"
      (set_local $j (i32.const 1))
      loop $loop_j
      
        ;; "pixel's Moore (8-connected) neighborhood:"

        ;; "p9 p2 p3"
        ;; "p8    p4"
        ;; "p7 p6 p5"

        (set_local $p2 (i32.and (call $get_pixel (get_local $w)
                   (get_local $j)
          (i32.sub (get_local $i) (i32.const 1))
        ) (i32.const 1) ))
        
        (set_local $p3 (i32.and (call $get_pixel (get_local $w)
          (i32.add (get_local $j) (i32.const 1))
          (i32.sub (get_local $i) (i32.const 1))
        ) (i32.const 1) ))

        (set_local $p4 (i32.and (call $get_pixel (get_local $w)
          (i32.add (get_local $j) (i32.const 1))
                   (get_local $i)
        ) (i32.const 1) ))

        (set_local $p5 (i32.and (call $get_pixel (get_local $w)
          (i32.add (get_local $j) (i32.const 1))
          (i32.add (get_local $i) (i32.const 1))
        ) (i32.const 1) ))

        (set_local $p6 (i32.and (call $get_pixel (get_local $w)
                   (get_local $j)
          (i32.add (get_local $i) (i32.const 1))
        ) (i32.const 1) ))

        (set_local $p7 (i32.and (call $get_pixel (get_local $w)
          (i32.sub (get_local $j) (i32.const 1))
          (i32.add (get_local $i) (i32.const 1))
        ) (i32.const 1) ))

        (set_local $p8 (i32.and (call $get_pixel (get_local $w)
          (i32.sub (get_local $j) (i32.const 1))
                   (get_local $i)
        ) (i32.const 1) ))

        (set_local $p9 (i32.and (call $get_pixel (get_local $w)
          (i32.sub (get_local $j) (i32.const 1))
          (i32.sub (get_local $i) (i32.const 1))
        ) (i32.const 1) ))

        ;; "A is the number of 01 patterns in the ordered set p2,p3,p4,...p8,p9"
        (set_local $A (i32.add (i32.add( i32.add (i32.add( i32.add( i32.add( i32.add
          (i32.and (i32.eqz (get_local $p2)) (i32.eq (get_local $p3) (i32.const 1)))
          (i32.and (i32.eqz (get_local $p3)) (i32.eq (get_local $p4) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p4)) (i32.eq (get_local $p5) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p5)) (i32.eq (get_local $p6) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p6)) (i32.eq (get_local $p7) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p7)) (i32.eq (get_local $p8) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p8)) (i32.eq (get_local $p9) (i32.const 1))))
          (i32.and (i32.eqz (get_local $p9)) (i32.eq (get_local $p2) (i32.const 1))))
        )
        ;; "B = p2 + p3 + p4 + ... + p8 + p9"
        (set_local $B (i32.add (i32.add( i32.add
          (i32.add (get_local $p2) (get_local $p3))
          (i32.add (get_local $p4) (get_local $p5)))
          (i32.add (get_local $p6) (get_local $p7)))
          (i32.add (get_local $p8) (get_local $p9)))
        )

        (if (i32.eqz (get_local $iter)) (then
          ;; "first subiteration,  m1 = p2*p4*p6, m2 = p4*p6*p8"
          (set_local $m1 (i32.mul(i32.mul (get_local $p2) (get_local $p4)) (get_local $p6)))
          (set_local $m2 (i32.mul(i32.mul (get_local $p4) (get_local $p6)) (get_local $p8)))
        )(else
          ;; "second subiteration, m1 = p2*p4*p8, m2 = p2*p6*p8"
          (set_local $m1 (i32.mul(i32.mul (get_local $p2) (get_local $p4)) (get_local $p8)))
          (set_local $m2 (i32.mul(i32.mul (get_local $p2) (get_local $p6)) (get_local $p8)))
        ))

        ;; "the contour point is deleted if it satisfies the following conditions:"
        ;; "A == 1 && 2 <= B <= 6 && m1 == 0 && m2 == 0"
        (if (i32.and(i32.and(i32.and(i32.and
          (i32.eq   (get_local $A) (i32.const  1))
          (i32.lt_u (i32.const  1) (get_local $B)))
          (i32.lt_u (get_local $B) (i32.const  7)))
          (i32.eqz  (get_local $m1)))
          (i32.eqz  (get_local $m2)))
        (then
          ;; "we cannot erase the pixel directly because computation for neighboring pixels"
          ;; "depends on the current state of this pixel. And instead of using 2 matrices,"
          ;; "we do a |= 2 to set the second LSB to denote a to-be-erased pixel"
          (call $set_pixel (get_local $w) (get_local $j) (get_local $i)
            (i32.or
              (call $get_pixel (get_local $w) (get_local $j) (get_local $i))
              (i32.const 2)
            )
          )
        )(else))
        
        ;; "increment loopers"
        (set_local $j (i32.add (get_local $j) (i32.const 1)))
        (br_if $loop_j (i32.lt_u (get_local $j) (i32.sub (get_local $w) (i32.const 1))) )
      end
      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (br_if $loop_i (i32.lt_u (get_local $i) (i32.sub (get_local $h) (i32.const 1))))
    end

    ;; "for (i = 1; i < h; i++)"
    (set_local $i (i32.const 0))
    loop $loop_i2

      ;; "for (j = 0; j < w; j++)"
      (set_local $j (i32.const 0))
      loop $loop_j2
        ;; "bit-twiddling to retrive the new image stored in the second LSB"
        ;; "and check if the image has changed"
        ;; "mark = mem[i,j] >> 1"
        ;; "old  = mem[i,j] &  1"
        ;; "mem[i,j] = old & (!marker)"
        (set_local $neu (call $get_pixel (get_local $w) (get_local $j) (get_local $i)))
        (set_local $mark (i32.shr_u (get_local $neu) (i32.const 1)))
        (set_local $old  (i32.and   (get_local $neu) (i32.const 1)))
        (set_local $neu  (i32.and   (get_local $old) (i32.eqz (get_local $mark))))

        (call $set_pixel (get_local $w) (get_local $j) (get_local $i) (get_local $neu))

        ;; "image has changed, tell caller function that we will need more iterations"
        (if (i32.ne (get_local $neu) (get_local $old)) (then
          (set_local $diff (i32.const 1))
        ))

        ;; "increment loopers"
        (set_local $j (i32.add (get_local $j) (i32.const 1)))
        (br_if $loop_j2 (i32.lt_u (get_local $j) (get_local $w)))
      end
      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (br_if $loop_i2 (i32.lt_u (get_local $i) (get_local $h)))
    end

    ;; "return"
    (get_local $diff)
  )

  ;; "main thinning routine"
  ;; "run thinning iteration until done"
  ;; "w: width, h:height"
  (func $thinning_zs (param $w i32) (param $h i32)
    (local $diff i32)
    (set_local $diff (i32.const 1))
    loop $l0
      ;; "even subiteration"
      (set_local $diff (i32.and 
        (get_local $diff) 
        (call $thinning_zs_iteration (get_local $w) (get_local $h) (i32.const 0))
      ))
      ;; "odd subiteration"
      (set_local $diff (i32.and 
        (get_local $diff) 
        (call $thinning_zs_iteration (get_local $w) (get_local $h) (i32.const 1))
      ))
      ;; "no change -> done!"
      (br_if $l0 (i32.eq (get_local $diff) (i32.const 1)))
    end
  )

  ;; "exported API's"
  (export "thinning_zs_iteration" (func $thinning_zs_iteration))
  (export "thinning_zs" (func $thinning_zs))
  (export "get_pixel"   (func $get_pixel))
  (export "set_pixel"   (func $set_pixel))
  (export "mem"         (memory $mem))
)

