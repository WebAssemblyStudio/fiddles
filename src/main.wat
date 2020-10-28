(module
  (func $test_opt (result i32)
    (return
      (i32.wrap/i64 (i64.popcnt (i64.const 9222978042324851921)))
    )
  )
  (func $test_orig (result i32)
    (return
      (i32.wrap/i64
        (i64.popcnt
          (i64.sub
            (i64.shl
              (i64.const 4294783828)
              (i64.const 17179869183)
            )
            (i64.const -7377)
          )
        )
      )
    )
  )
  (export "test_opt" (func $test_opt))
  (export "test_orig" (func $test_orig))
)