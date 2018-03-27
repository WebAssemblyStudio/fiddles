(module
  (memory (import "imports" "memory") 1)
  (func $add (param $len i32) (result f64)
    (local $sum f64)
    (local $i i32)

    (block $block
      (loop $loop
         (br_if $block (i32.eq (get_local $i) (get_local $len)))
         (f64.add (get_local $sum) (f64.load (get_local $i)))
         set_local $sum

         (i32.add (get_local $i) (i32.const 1))
         set_local $i

         br $loop
      )
    )

    get_local $sum
  )
  (export "add" (func $add))
)