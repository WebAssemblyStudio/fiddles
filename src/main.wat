(module
  (memory (import "imports" "memory") 1)
  (func $sumAll (param $len i32) (result i32)
    (local $sum i32) ;; sum so far
    (local $i i32)   ;; counter

    (block $block
      (loop $loop
          (br_if $block
            (i32.eq (get_local $i) (get_local $len))
          )

          (i32.add (get_local $sum) (i32.load (get_local $i)))
          set_local $sum

          (i32.add (get_local $i) (i32.const 1))
          set_local $i

          br $loop
      )
    )

    get_local $sum
  )
  (export "sumAll" (func $sumAll))
)