(module
  (memory (import "imports" "memory") 1)
  (func $sumAll (param $len i32) (result i32)
    (local $sum i32) ;; sum so far
    (local $i i32)   ;; pointer
    (local $end i32) ;; end pointer

    ;; end <- $len * 4; because 4 byte per 1 element in Int32Array
    (set_local $end
      (i32.mul
        (get_local $len)
        (i32.const 4)
      )
    )

    (block $block
      (loop $loop
          ;; jump to $block, if $i == $end
          (br_if $block
            (i32.eq (get_local $i) (get_local $end))
          )

          ;; sum <- sum + memory[i]
          (set_local
            $sum
            (i32.add
              (get_local $sum)
              (i32.load8_s (get_local $i))
            )
          )

          ;; i <- i + 1
          ;; "stack" <- i + 1
          (i32.add
            (get_local $i)
            (i32.const 1)
          )
          ;; i <- "stack"
          set_local $i

          ;; jump to $loop
          br $loop
      )
    )

    get_local $sum
  )
  (export "sumAll" (func $sumAll))
)