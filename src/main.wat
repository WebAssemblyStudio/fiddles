(module
  (import "env" "draw" (func $draw (param i32) (param i32) (param i32) (param i32) (param i32) (param i32) (param i32)))
  (func $run (export "run")
    (call $draw
      (i32.const 10)
      (i32.const 10)
      (i32.const 10)
      (i32.const 10)
      (i32.const 255)
      (i32.const 0)
      (i32.const 0)
    )
  )
)