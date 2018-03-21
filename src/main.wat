(module
  (func $sumOfMultiplesUntil (param $limit i32) (result i32) (local $i i32) (local $counter i32)  (local $sum i32)
    i32.const 0
    set_local $i
    i32.const 0
    set_local $sum
 
    (block $stop
      (loop $loop
            get_local $i
            get_local $limit
            i32.ge_s
            br_if $stop

            get_local $i
            i32.const 1
            i32.add
            set_local $i


            i32.const 0
            set_local $counter

            get_local $i
            i32.const 3
            i32.rem_s
            i32.eqz
            get_local $counter
            i32.add
            set_local $counter

            
            get_local $i
            i32.const 5
            i32.rem_s
            i32.eqz
            get_local $counter
            i32.add
            set_local $counter

            get_local $counter
            i32.eqz
            br_if $loop

            get_local $i
            get_local $sum
            i32.add
            set_local $sum

            br $loop
        )
    )
    get_local $sum
  )
(export "sumOfMultiplesUntil" (func $sumOfMultiplesUntil)))