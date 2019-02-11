(module
 (memory $0 2)
  (data (i32.const 65536) "\00\00\01\00")
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    ;;get_local $lhs
    ;;get_local $rhs
    ;;i32.add
    i32.const 65536
    i32.load
  )
  (func $allocate (param $size i32) (result i32) (local $ptr i32)
    ;; store ptr on stack
    (set_local $ptr (i32.load (i32.const 65536)))

    ;; update ptr in heap
    (i32.store
      (i32.const 65536)
      (i32.add
        (get_local $size)
        (i32.load (i32.const 65536))
      )
    )

    ;; return ptr
    get_local $ptr
  )
  (func $reset
    (i32.store (i32.const 65536) (i32.const 65536))
  )
  (export "memory" (memory $0))
  (export "add" (func $add))
  (export "allocate" (func $allocate))
  (export "reset" (func $allocate))
)