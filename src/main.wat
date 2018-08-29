(module
  (func $sum_bad (param $n i32) (result i32)  (local $i i32) (local $sum i32)
    (loop $loop
      (br_if $loop (i32.le_s (get_local $n) (get_local $i)))
      (set_local $sum (i32.add (get_local $sum) (get_local $i)))
      (set_local $i (i32.add (get_local $i) (i32.const 1))))
    (return (get_local $sum)))

  (func $sum_good (param $n i32) (result i32)  (local $i i32) (local $sum i32)
    (block $exit 
      (loop $loop
        (br_if $exit (i32.le_s (get_local $n) (get_local $i)))
        (set_local $sum (i32.add (get_local $sum) (get_local $i)))
        (set_local $i (i32.add (get_local $i) (i32.const 1)))
        (br $loop)))
    (return (get_local $sum)))


  (export "sum_bad" (func $sum_bad))
  (export "sum_good" (func $sum_good)))