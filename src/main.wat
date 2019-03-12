(module
  (import "refs" "deref" (func $deref (param i32) (result i32)))
  (import "refs" "write" (func $write (param i32 i32)))
  (import "refs" "alloc" (func $alloc (result i32)))
  (memory 1)

  (func $bench_ref
    (local $i i32)
    (local $r i32)
    (set_local $r (call $alloc))
    (loop $l
      (if (i32.le_u  (get_local $i) (i32.const 100000000))
        (then
          (set_local $i (i32.add (get_local $i) (i32.const 1)))
          (call $write (get_local $r) (i32.add (i32.const 1) (call $deref (get_local $r))))
          (br $l)
        )
      )
    )
  )

  (func $bench_mem
    (local $i i32)
    (local $r i32)
    (set_local $r (call $alloc))
    (loop $l
      (if (i32.le_u  (get_local $i) (i32.const 100000000))
        (then
          (set_local $i (i32.add (get_local $i) (i32.const 1)))
          (i32.store (get_local $r) (i32.add (i32.const 1) (i32.load (get_local $r))))
          (br $l)
        )
      )
    )
  )
  (export "bench_ref" (func $bench_ref))
  (export "bench_mem" (func $bench_mem))

)