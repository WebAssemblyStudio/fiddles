(module
  (memory (import "imports" "memory") 1)
  (func $sumAll (param $len i32) (result i32)
    (local $sum i32) ;; sum so far
    (local $i i32)   ;; counter

    (block $block
      (loop $loop
          ;; jump to $block, if i == $len
          (br_if $block
            (i32.eq (get_local $i) (get_local $len))
          )

          ;; sum <- sum + memory[i]
          (i32.add
            (get_local $sum)
            (i32.load8_s (get_local $i))   ;; i32.load8_s: load 1 byte and sign-extend i8 to i32
          )
          set_local $sum

          ;; i <- i + 1
          (i32.add
            (get_local $i)
            (i32.const 1)
          )
          set_local $i

          ;; jump to $loop
          br $loop
      )
    )

    get_local $sum
  )
  (export "sumAll" (func $sumAll))
)