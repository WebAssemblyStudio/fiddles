(module
  (import "js" "memory" (memory 1))
  (import "js" "log" (func $log (param i32 i32)))

  ;; Subtract 1 from value
  (func $decrement (param $value i32) (result i32)
    i32.const 1
    i32.sub
  )

  ;; Add one to value
  (func $increment (param $value i32) (result i32)
    i32.const 1
    i32.add
  )


  (func $helloWorld (export "helloWorld") (param $count i32) (local $address i32)

    (loop
      
      get_local $count ;; get local variable count
      i32.eqz ;; if it is equal to zero,
      br_if 1 ;; exit the loop

      get_local $address ;; get the local variable addresss
      call $decrement ;; Decrement it,
      tee_local $address ;; And set it (while keeping the value in the stack.)
      i32.const "h"
      i32.store8

      get_local $address ;; get the local variable addresss
      call $decrement ;; Decrement it,
      tee_local $address ;; And set it (while keeping the value in the stack.)
      i32.const "h"
      i32.store8


      i32.const "h"


      get_local $count ;; get local variable count
      call $decrement ;; subtract 1
      set_local $count ;; set count to this value
    )
    i32.const 0
    i32.const 13
    call $log
  )
)