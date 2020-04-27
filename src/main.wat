(module
  (memory $memory (export "memory") 100 100)

  (func $min (param $x i32) (result i32)
    (i32.shl
      (get_local $x)
      (i32.lt_s
        (get_local $x)
        (i32.const 0)
      )
    )
  )
  (export "run" (func $min))

  (func $runall (param $n i32) (param $src i32) (param $dst i32)
    (loop
      (set_local $n
        (i32.sub
          (get_local $n)
          (i32.const 1)
        )
      )
      (i32.store
        (get_local $dst)
        (call $min
          (i32.load
            (get_local $src)
          )
        )
      )
      (set_local $src
        (i32.add
          (get_local $src)
          (i32.const 4)
        )
      )
      (set_local $dst
        (i32.add
          (get_local $dst)
          (i32.const 4)
        )
      )
      (br_if 0
        (i32.gt_u
          (get_local $n)
          (i32.const 0)
        )
      )
    )
  )
  (export "runall" (func $runall))
)