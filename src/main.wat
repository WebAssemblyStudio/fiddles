(module
  (import "std" "log" (func $log (param i32)))
  (import "std" "sleep" (func $sleep (param i32)))
  (import "js" "fnt" (table 10 anyfunc))

  (main $main_0)

  (func $main_0
    (local $x i32)

    (set_local $x (i32.const 100))
    (call $log (i32.const 0))
    (call $sleep (get_local $x) (i32.const 1))
  )
  (elem (i32.const 0) $main_0)

  (func $main_1
    (call $log (i32.const 1))
  )
  (elem (i32.const 1) $main_1)

  (func $fib (param $n i32) (result i32)
    (call $log (get_local $n))
    (if (result i32)
      (block (result i32)
        (i32.le_s
          (get_local $n)
          (i32.const 1)
        )
      )
      (then
        (get_local $n)
      )
      (else
        (i32.add
          (call $fib
            (i32.sub
              (get_local $n)
              (i32.const 1)
            )
          )
          (call $fib
            (i32.sub
              (get_local $n)
              (i32.const 2)
            )
          )
        )
      )
    )  
  )
  (export "fib" (func $fib))
)