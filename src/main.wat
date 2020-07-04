(module
  (memory $memory (export "memory") 2)

  (func $run (export "run")
    (local $ptr i32)

    ;; Performs the first iteration:
    ;; ptr = 1024
    ;; *ptr = ( (*ptr) << 1 ) | 1;
    (i32.store
      (tee_local $ptr
        (i32.const 1024)
      )
      (i32.or
        (i32.shl
          (i32.load
            (get_local $ptr)
          )
          (i32.const 1)
        )
        (i32.const 1)
      )
    )

    (loop $L0
      ;; Performs:
      ;; ptr++
      ;; *ptr = ( (*ptr) << 1 ) | 1;
      (i32.store
        (tee_local $ptr
          (i32.add
            (get_local $ptr)
            (i32.const 4)
          )
        )
        (i32.or
          (i32.shl
            (i32.load
              (get_local $ptr)
            )
            (i32.const 1)
          )
          (i32.const 1)
        )
      )

      ;; Terminate after traversing all 8 elements
      (br_if $L0
        (i32.lt_u
          (get_local $ptr)
          (i32.const 1052)
        )
      )
    )
  )
)