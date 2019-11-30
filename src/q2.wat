(module
  (import "console" "log" (func $log (param i32 i32)))
  (import "js" "mem" (memory 1))  
  (func $checkChar (param $value i32) (result i32)
   (if (result i32)
       (i32.lt_s (get_local $value) (i32.const 97))
    (then (get_local $value))
    (else
      (i32.sub (get_local $value)(i32.const 32))
    )
   )
)
  (func (export "capitalize") (param $offset i32) (param $length i32) (local $index i32)
    
    (set_local $index (get_local $offset))
    (block
      (loop
          (i32.store8 (get_local $index) (call $checkChar (i32.load8_u (get_local $index))))
          (set_local $index (i32.add (get_local $index)(i32.const 1)))
          (br_if 1 (i32.eq (get_local $index) (get_local $length)))
          (br 0)
      )
    )
    get_local $offset
    get_local $length
    call $log)
  )