(module
  ;; Function table that holds two function with any signature
  (table 2 anyfunc)

  ;; First function is at index 0
  (elem (i32.const 0) 
    $f1 
    $f2
  )

  (func $f1 (result i32)
    i32.const 42
  )

  (func $f2 (result i32)
    i32.const 13
  )

  (func $call_by_index (param $i i32) (result i32)
    (call_indirect (result i32) 
      (get_local $i)
    )
  )

  (export "call_by_index" (func $call_by_index))
)