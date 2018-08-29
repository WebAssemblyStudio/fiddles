(module
  (func $sum (param $n i32) (result i32)  (local $i i32) (local $sum i32)
    (block $exit 
      (loop $loop
        (br_if $exit (i32.le_s (get_local $i) (get_local $n)))
        (set_local $sum (i32.add (get_local $sum) (get_local $i)))
        (set_local $i (i32.add (get_local $i) (i32.const 1)))))
    (return (get_local $sum)))
  (export "sum" (func $sum)))