
(module
  (func $sumOfEvenFiboUntil
    (param $limit i32)
    (result i32)
    (local $prev2 i32)
    (local $prev1 i32)
    (local $cur i32)
    (local $ans i32)

    i32.const 0
    set_local $prev2
    i32.const 1
    set_local $prev1
    i32.const 0
    set_local $cur
  
    i32.const 0
    set_local $ans
 
    (block $stop
      (loop $loop
            ;; if $cur >= $limit, break
            get_local $cur
            get_local $limit
            i32.ge_s
            br_if $stop

            ;; $cur = $prev2 + $prev1
            get_local $prev2
            get_local $prev1
            i32.add
            set_local $cur

            ;; $prev2 <- $prev1
            get_local $prev1
            set_local $prev2
  
            ;; $prev1 <- $cur
            get_local $cur
            set_local $prev1

            ;; If even, add to ans
            get_local $cur
            i32.const 1
            i32.and
            br_if $loop


            get_local $cur
            get_local $ans
            i32.add
            set_local $ans

            br $loop
        )
    )
    get_local $ans
  )
(export "sumOfEvenFiboUntil" (func $sumOfEvenFiboUntil)))
