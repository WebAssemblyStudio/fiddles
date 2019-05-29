(module
  (import "i" "seed" (global $initSeed i32))
  (import "i" "detail" (global $detail i32))
  (memory (export "memory") 0)
  
  (func (export "initMem")
    i32.const 1
    get_global $detail
    i32.const 2
    i32.mul
    i32.const 14
    i32.sub
    i32.shl
    grow_memory
    drop
  )
  (func $seed (export "seed") (param $x i32) (param $y i32)
    (local $size i32) (local $step i32) (local $step2 i32) (local $i i32) (local $s i32)
    get_global $initSeed
    
    (i32.and (i32.const 255) (get_local $x))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.and (i32.const 255) (i32.shr_u (get_local $x) (i32.const 8)))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.and (i32.const 255) (i32.shr_u (get_local $x) (i32.const 16)))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.shr_u (get_local $x) (i32.const 24))
    i32.xor
    i32.const 16777619
    i32.mul

    (i32.and (i32.const 255) (get_local $y))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.and (i32.const 255) (i32.shr_u (get_local $y) (i32.const 8)))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.and (i32.const 255) (i32.shr_u (get_local $y) (i32.const 16)))
    i32.xor
    i32.const 16777619
    i32.mul
    
    (i32.shr_u (get_local $y) (i32.const 24))
    i32.xor
    i32.const 16777619
    i32.mul
    
    i32.const 1597334677
    i32.mul
    set_local $s
    
    (f32.store
      (i32.const 0)
      (f32.div
        (f32.convert_u/i32 (get_local $s))
        (f32.const 4294967296)
      )
    )
    
    (set_local $size (i32.shl (i32.const 1) (get_global $detail)))
    (set_local $step (get_local $size))
    (block $break0
      (loop $continue0
        (set_local $step2 (get_local $step))
        (set_local $step (i32.shr_u (get_local $step) (i32.const 1)))
        (br_if $break0 (i32.eqz (get_local $step)))
        (set_local $y (i32.const 0))
        (block $break1
          (loop $continue1
            (set_local $i (i32.mul (get_local $y) (get_local $size)))
            (set_local $x (get_local $step))
            (block $break2
              (loop $continue2
                (set_local $s (i32.mul (get_local $s) (i32.const 1597334677)))
                (f32.store
                  (i32.mul
                    (i32.const 4)
                    (i32.add (get_local $i) (get_local $x))
                  )
                  (f32.div
                    (f32.convert_u/i32
                      (get_local $s)
                    )
                    (f32.const 4294967296)
                  )
                )
                (set_local $x (i32.add (get_local $x) (get_local $step2)))
                (br_if $break2 (i32.ge_u (get_local $x) (get_local $size)))
                (br $continue2)
              )
            )
            (set_local $x (i32.const 0))
            (set_local $y (i32.add (get_local $y) (get_local $step)))
            (set_local $i (i32.mul (get_local $y) (get_local $size)))
            (block $break2
              (loop $continue2
                (set_local $s (i32.mul (get_local $s) (i32.const 1597334677)))
                (f32.store
                  (i32.mul
                    (i32.const 4)
                    (i32.add (get_local $i) (get_local $x))
                  )
                  (f32.div
                    (f32.convert_u/i32 (get_local $s))
                    (f32.const 4294967296)
                  )
                )
                (set_local $x (i32.add (get_local $x) (get_local $step)))
                (br_if $break2 (i32.ge_u (get_local $x) (get_local $size)))
                (br $continue2)
              )
            )
            (set_local $y (i32.add (get_local $y) (get_local $step)))
            (br_if $break1 (i32.eq (get_local $y) (get_local $size)))
            (br $continue1)
          )
        )
        (br $continue0)
      )
    )
  )
)