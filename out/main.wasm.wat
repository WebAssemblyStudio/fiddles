(module
 (type $0 (func (param i32 i32 i32) (result i32)))
 (type $1 (func (param i32)))
 (type $2 (func (param i32 i32 i32 i32) (result i32)))
 (type $3 (func (param i32 i32) (result i32)))
 (type $4 (func (param i32 i32 i32 i32 i32 i32) (result i32)))
 (type $5 (func))
 (type $6 (func (result i32)))
 (type $7 (func (param i32) (result i32)))
 (type $8 (func (param i32 i64 i32) (result i64)))
 (import "env" "putc_js" (func $putc_js (param i32)))
 (import "env" "__syscall3" (func $__syscall3 (param i32 i32 i32 i32) (result i32)))
 (import "env" "__syscall1" (func $__syscall1 (param i32 i32) (result i32)))
 (import "env" "__syscall5" (func $__syscall5 (param i32 i32 i32 i32 i32 i32) (result i32)))
 (global $global$0 (mut i32) (i32.const 67760))
 (global $global$1 i32 (i32.const 67760))
 (global $global$2 i32 (i32.const 2216))
 (table 5 5 anyfunc)
 (elem (i32.const 1) $__stdio_write $__stdio_close $__stdout_write $__stdio_seek)
 (memory $0 2)
 (data (i32.const 1024) "Hello World\00\10\04\00\00")
 (data (i32.const 1040) "\05\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\04\00\00\00\a8\04\00\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\n\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00")
 (data (i32.const 1184) "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00")
 (export "memory" (memory $0))
 (export "__heap_base" (global $global$1))
 (export "__data_end" (global $global$2))
 (export "main" (func $main))
 (export "writev_c" (func $writev_c))
 (func $__wasm_call_ctors (; 4 ;) (type $5)
 )
 (func $main (; 5 ;) (type $6) (result i32)
  (drop
   (call $puts
    (i32.const 1024)
   )
  )
  (i32.const 0)
 )
 (func $writev_c (; 6 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (local $var$8 i32)
  (block $label$1
   (br_if $label$1
    (i32.lt_s
     (get_local $var$2)
     (i32.const 1)
    )
   )
   (set_local $var$3
    (i32.const 0)
   )
   (set_local $var$4
    (i32.const 0)
   )
   (loop $label$2
    (set_local $var$5
     (i32.const 0)
    )
    (block $label$3
     (br_if $label$3
      (i32.eqz
       (i32.load offset=4
        (tee_local $var$6
         (i32.add
          (get_local $var$1)
          (i32.shl
           (get_local $var$3)
           (i32.const 3)
          )
         )
        )
       )
      )
     )
     (set_local $var$7
      (i32.add
       (get_local $var$6)
       (i32.const 4)
      )
     )
     (set_local $var$8
      (i32.const 0)
     )
     (loop $label$4
      (call $putc_js
       (i32.load8_s
        (i32.add
         (i32.load
          (get_local $var$6)
         )
         (get_local $var$8)
        )
       )
      )
      (br_if $label$4
       (i32.lt_u
        (tee_local $var$8
         (i32.add
          (get_local $var$8)
          (i32.const 1)
         )
        )
        (tee_local $var$5
         (i32.load
          (get_local $var$7)
         )
        )
       )
      )
     )
    )
    (set_local $var$4
     (i32.add
      (get_local $var$5)
      (get_local $var$4)
     )
    )
    (br_if $label$2
     (i32.ne
      (tee_local $var$3
       (i32.add
        (get_local $var$3)
        (i32.const 1)
       )
      )
      (get_local $var$2)
     )
    )
   )
   (return
    (get_local $var$4)
   )
  )
  (i32.const 0)
 )
 (func $__lockfile (; 7 ;) (type $7) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (set_local $var$1
   (i32.const 0)
  )
  (block $label$1
   (br_if $label$1
    (i32.eq
     (i32.and
      (i32.load offset=76
       (get_local $var$0)
      )
      (i32.const -1073741825)
     )
     (tee_local $var$2
      (i32.load offset=27
       (i32.const 0)
      )
     )
    )
   )
   (set_local $var$0
    (i32.add
     (get_local $var$0)
     (i32.const 76)
    )
   )
   (block $label$2
    (loop $label$3
     (br_if $label$2
      (i32.eqz
       (tee_local $var$1
        (i32.load
         (get_local $var$0)
        )
       )
      )
     )
     (br_if $label$3
      (i32.ne
       (i32.load
        (get_local $var$0)
       )
       (get_local $var$1)
      )
     )
    )
    (i32.store
     (get_local $var$0)
     (i32.or
      (get_local $var$1)
      (i32.const 1073741824)
     )
    )
    (block $label$4
     (br_if $label$4
      (i32.eqz
       (tee_local $var$1
        (i32.load
         (get_local $var$0)
        )
       )
      )
     )
     (loop $label$5
      (block $label$6
       (br_if $label$6
        (i32.ne
         (call $__syscall3
          (i32.const 240)
          (get_local $var$0)
          (i32.const 128)
          (get_local $var$1)
         )
         (i32.const -38)
        )
       )
       (drop
        (call $__syscall3
         (i32.const 240)
         (get_local $var$0)
         (i32.const 0)
         (get_local $var$1)
        )
       )
      )
      (br_if $label$5
       (tee_local $var$1
        (i32.load
         (get_local $var$0)
        )
       )
      )
     )
    )
    (set_local $var$2
     (i32.or
      (get_local $var$2)
      (i32.const 1073741824)
     )
    )
   )
   (i32.store
    (get_local $var$0)
    (get_local $var$2)
   )
   (set_local $var$1
    (i32.const 1)
   )
  )
  (get_local $var$1)
 )
 (func $__unlockfile (; 8 ;) (type $1) (param $var$0 i32)
  (local $var$1 i32)
  (set_local $var$0
   (i32.add
    (get_local $var$0)
    (i32.const 76)
   )
  )
  (loop $label$1
   (br_if $label$1
    (i32.ne
     (tee_local $var$1
      (i32.load
       (get_local $var$0)
      )
     )
     (i32.load
      (get_local $var$0)
     )
    )
   )
  )
  (i32.store
   (get_local $var$0)
   (i32.const 0)
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (i32.and
      (get_local $var$1)
      (i32.const 1073741824)
     )
    )
   )
   (br_if $label$2
    (i32.ne
     (call $__syscall3
      (i32.const 240)
      (get_local $var$0)
      (i32.const 129)
      (i32.const 1)
     )
     (i32.const -38)
    )
   )
   (drop
    (call $__syscall3
     (i32.const 240)
     (get_local $var$0)
     (i32.const 1)
     (i32.const 1)
    )
   )
  )
 )
 (func $__towrite (; 9 ;) (type $7) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (i32.store8 offset=74
   (get_local $var$0)
   (i32.or
    (i32.add
     (tee_local $var$1
      (i32.load8_u offset=74
       (get_local $var$0)
      )
     )
     (i32.const -1)
    )
    (get_local $var$1)
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.and
     (tee_local $var$1
      (i32.load
       (get_local $var$0)
      )
     )
     (i32.const 8)
    )
   )
   (i64.store offset=4 align=4
    (get_local $var$0)
    (i64.const 0)
   )
   (i32.store offset=28
    (get_local $var$0)
    (tee_local $var$1
     (i32.load offset=44
      (get_local $var$0)
     )
    )
   )
   (i32.store offset=20
    (get_local $var$0)
    (get_local $var$1)
   )
   (i32.store offset=16
    (get_local $var$0)
    (i32.add
     (get_local $var$1)
     (i32.load offset=48
      (get_local $var$0)
     )
    )
   )
   (return
    (i32.const 0)
   )
  )
  (i32.store
   (get_local $var$0)
   (i32.or
    (get_local $var$1)
    (i32.const 32)
   )
  )
  (i32.const -1)
 )
 (func $fwrite (; 10 ;) (type $2) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (param $var$3 i32) (result i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (local $var$8 i32)
  (local $var$9 i32)
  (local $var$10 i32)
  (local $var$11 i32)
  (set_local $var$4
   (i32.const 0)
  )
  (block $label$1
   (br_if $label$1
    (i32.lt_s
     (i32.load offset=76
      (get_local $var$3)
     )
     (i32.const 0)
    )
   )
   (set_local $var$4
    (i32.ne
     (call $__lockfile
      (get_local $var$3)
     )
     (i32.const 0)
    )
   )
  )
  (set_local $var$5
   (i32.mul
    (get_local $var$2)
    (get_local $var$1)
   )
  )
  (block $label$2
   (block $label$3
    (block $label$4
     (block $label$5
      (block $label$6
       (block $label$7
        (br_if $label$7
         (i32.eqz
          (tee_local $var$6
           (i32.load offset=16
            (get_local $var$3)
           )
          )
         )
        )
        (br_if $label$6
         (i32.ge_u
          (i32.sub
           (get_local $var$6)
           (tee_local $var$7
            (i32.load offset=20
             (get_local $var$3)
            )
           )
          )
          (get_local $var$5)
         )
        )
        (br $label$4)
       )
       (set_local $var$6
        (i32.const 0)
       )
       (br_if $label$5
        (call $__towrite
         (get_local $var$3)
        )
       )
       (br_if $label$4
        (i32.lt_u
         (i32.sub
          (i32.load
           (i32.add
            (get_local $var$3)
            (i32.const 16)
           )
          )
          (tee_local $var$7
           (i32.load offset=20
            (get_local $var$3)
           )
          )
         )
         (get_local $var$5)
        )
       )
      )
      (set_local $var$8
       (i32.const 0)
      )
      (block $label$8
       (block $label$9
        (br_if $label$9
         (i32.lt_s
          (i32.load8_s offset=75
           (get_local $var$3)
          )
          (i32.const 0)
         )
        )
        (set_local $var$9
         (i32.add
          (get_local $var$0)
          (get_local $var$5)
         )
        )
        (set_local $var$8
         (i32.const 0)
        )
        (set_local $var$6
         (i32.const 0)
        )
        (loop $label$10
         (br_if $label$9
          (i32.eqz
           (i32.add
            (get_local $var$5)
            (get_local $var$6)
           )
          )
         )
         (set_local $var$10
          (i32.add
           (get_local $var$9)
           (get_local $var$6)
          )
         )
         (set_local $var$6
          (tee_local $var$11
           (i32.add
            (get_local $var$6)
            (i32.const -1)
           )
          )
         )
         (br_if $label$10
          (i32.ne
           (i32.load8_u
            (i32.add
             (get_local $var$10)
             (i32.const -1)
            )
           )
           (i32.const 10)
          )
         )
        )
        (br_if $label$5
         (i32.lt_u
          (tee_local $var$6
           (call_indirect (type $0)
            (get_local $var$3)
            (get_local $var$0)
            (tee_local $var$8
             (i32.add
              (i32.add
               (get_local $var$5)
               (get_local $var$11)
              )
              (i32.const 1)
             )
            )
            (i32.load offset=36
             (get_local $var$3)
            )
           )
          )
          (get_local $var$8)
         )
        )
        (set_local $var$6
         (i32.xor
          (get_local $var$11)
          (i32.const -1)
         )
        )
        (set_local $var$0
         (i32.add
          (i32.add
           (get_local $var$9)
           (get_local $var$11)
          )
          (i32.const 1)
         )
        )
        (set_local $var$7
         (i32.load
          (i32.add
           (get_local $var$3)
           (i32.const 20)
          )
         )
        )
        (br $label$8)
       )
       (set_local $var$6
        (get_local $var$5)
       )
      )
      (drop
       (call $memcpy
        (get_local $var$7)
        (get_local $var$0)
        (get_local $var$6)
       )
      )
      (i32.store
       (tee_local $var$10
        (i32.add
         (get_local $var$3)
         (i32.const 20)
        )
       )
       (i32.add
        (i32.load
         (get_local $var$10)
        )
        (get_local $var$6)
       )
      )
      (set_local $var$6
       (i32.add
        (get_local $var$8)
        (get_local $var$6)
       )
      )
     )
     (br_if $label$2
      (i32.eqz
       (get_local $var$4)
      )
     )
     (br $label$3)
    )
    (set_local $var$6
     (call_indirect (type $0)
      (get_local $var$3)
      (get_local $var$0)
      (get_local $var$5)
      (i32.load offset=36
       (get_local $var$3)
      )
     )
    )
    (br_if $label$2
     (i32.eqz
      (get_local $var$4)
     )
    )
   )
   (call $__unlockfile
    (get_local $var$3)
   )
  )
  (block $label$11
   (br_if $label$11
    (i32.ne
     (get_local $var$6)
     (get_local $var$5)
    )
   )
   (return
    (select
     (get_local $var$2)
     (i32.const 0)
     (get_local $var$1)
    )
   )
  )
  (i32.div_u
   (get_local $var$6)
   (get_local $var$1)
  )
 )
 (func $fputs (; 11 ;) (type $3) (param $var$0 i32) (param $var$1 i32) (result i32)
  (local $var$2 i32)
  (select
   (i32.const -1)
   (i32.const 0)
   (i32.ne
    (tee_local $var$2
     (call $strlen
      (get_local $var$0)
     )
    )
    (call $fwrite
     (get_local $var$0)
     (i32.const 1)
     (get_local $var$2)
     (get_local $var$1)
    )
   )
  )
 )
 (func $__overflow (; 12 ;) (type $3) (param $var$0 i32) (param $var$1 i32) (result i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (set_global $global$0
   (tee_local $var$2
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (i32.store8 offset=15
   (get_local $var$2)
   (get_local $var$1)
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (block $label$4
      (br_if $label$4
       (i32.eqz
        (tee_local $var$3
         (i32.load offset=16
          (get_local $var$0)
         )
        )
       )
      )
      (br_if $label$2
       (i32.ge_u
        (tee_local $var$4
         (i32.load offset=20
          (get_local $var$0)
         )
        )
        (get_local $var$3)
       )
      )
      (br $label$3)
     )
     (set_local $var$3
      (i32.const -1)
     )
     (br_if $label$1
      (call $__towrite
       (get_local $var$0)
      )
     )
     (br_if $label$2
      (i32.ge_u
       (tee_local $var$4
        (i32.load offset=20
         (get_local $var$0)
        )
       )
       (i32.load
        (i32.add
         (get_local $var$0)
         (i32.const 16)
        )
       )
      )
     )
    )
    (br_if $label$2
     (i32.eq
      (tee_local $var$3
       (i32.and
        (get_local $var$1)
        (i32.const 255)
       )
      )
      (i32.load8_s offset=75
       (get_local $var$0)
      )
     )
    )
    (i32.store
     (i32.add
      (get_local $var$0)
      (i32.const 20)
     )
     (i32.add
      (get_local $var$4)
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $var$4)
     (get_local $var$1)
    )
    (set_global $global$0
     (i32.add
      (get_local $var$2)
      (i32.const 16)
     )
    )
    (return
     (get_local $var$3)
    )
   )
   (set_local $var$3
    (i32.const -1)
   )
   (br_if $label$1
    (i32.ne
     (call_indirect (type $0)
      (get_local $var$0)
      (i32.add
       (get_local $var$2)
       (i32.const 15)
      )
      (i32.const 1)
      (i32.load offset=36
       (get_local $var$0)
      )
     )
     (i32.const 1)
    )
   )
   (set_local $var$3
    (i32.load8_u offset=15
     (get_local $var$2)
    )
   )
  )
  (set_global $global$0
   (i32.add
    (get_local $var$2)
    (i32.const 16)
   )
  )
  (get_local $var$3)
 )
 (func $puts (; 13 ;) (type $7) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (set_local $var$1
   (i32.const 0)
  )
  (block $label$1
   (br_if $label$1
    (i32.lt_s
     (i32.load offset=76
      (tee_local $var$2
       (i32.load offset=1036
        (i32.const 0)
       )
      )
     )
     (i32.const 0)
    )
   )
   (set_local $var$1
    (call $__lockfile
     (get_local $var$2)
    )
   )
  )
  (block $label$2
   (block $label$3
    (block $label$4
     (br_if $label$4
      (i32.lt_s
       (call $fputs
        (get_local $var$0)
        (get_local $var$2)
       )
       (i32.const 0)
      )
     )
     (block $label$5
      (br_if $label$5
       (i32.eq
        (i32.load8_u offset=75
         (get_local $var$2)
        )
        (i32.const 10)
       )
      )
      (br_if $label$5
       (i32.ge_u
        (tee_local $var$0
         (i32.load offset=20
          (get_local $var$2)
         )
        )
        (i32.load offset=16
         (get_local $var$2)
        )
       )
      )
      (i32.store
       (i32.add
        (get_local $var$2)
        (i32.const 20)
       )
       (i32.add
        (get_local $var$0)
        (i32.const 1)
       )
      )
      (i32.store8
       (get_local $var$0)
       (i32.const 10)
      )
      (set_local $var$0
       (i32.const 0)
      )
      (br_if $label$3
       (get_local $var$1)
      )
      (br $label$2)
     )
     (set_local $var$0
      (i32.shr_s
       (call $__overflow
        (get_local $var$2)
        (i32.const 10)
       )
       (i32.const 31)
      )
     )
     (br_if $label$2
      (i32.eqz
       (get_local $var$1)
      )
     )
     (br $label$3)
    )
    (set_local $var$0
     (i32.const -1)
    )
    (br_if $label$2
     (i32.eqz
      (get_local $var$1)
     )
    )
   )
   (call $__unlockfile
    (get_local $var$2)
   )
  )
  (get_local $var$0)
 )
 (func $__errno_location (; 14 ;) (type $6) (result i32)
  (i32.const 31)
 )
 (func $__syscall_ret (; 15 ;) (type $7) (param $var$0 i32) (result i32)
  (block $label$1
   (br_if $label$1
    (i32.lt_u
     (get_local $var$0)
     (i32.const -4095)
    )
   )
   (i32.store
    (call $__errno_location)
    (i32.sub
     (i32.const 0)
     (get_local $var$0)
    )
   )
   (set_local $var$0
    (i32.const -1)
   )
  )
  (get_local $var$0)
 )
 (func $dummy (; 16 ;) (type $7) (param $var$0 i32) (result i32)
  (get_local $var$0)
 )
 (func $__stdio_close (; 17 ;) (type $7) (param $var$0 i32) (result i32)
  (call $__syscall_ret
   (call $__syscall1
    (i32.const 6)
    (call $dummy
     (i32.load offset=60
      (get_local $var$0)
     )
    )
   )
  )
 )
 (func $__stdio_write (; 18 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (local $var$8 i32)
  (local $var$9 i32)
  (set_global $global$0
   (tee_local $var$3
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (i32.store offset=8
   (get_local $var$3)
   (get_local $var$1)
  )
  (i32.store offset=12
   (get_local $var$3)
   (get_local $var$2)
  )
  (i32.store
   (get_local $var$3)
   (tee_local $var$1
    (i32.load offset=28
     (get_local $var$0)
    )
   )
  )
  (i32.store offset=4
   (get_local $var$3)
   (tee_local $var$1
    (i32.sub
     (i32.load offset=20
      (get_local $var$0)
     )
     (get_local $var$1)
    )
   )
  )
  (set_local $var$4
   (i32.const 2)
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.eq
       (tee_local $var$5
        (i32.add
         (get_local $var$1)
         (get_local $var$2)
        )
       )
       (tee_local $var$6
        (call $__syscall_ret
         (call $__syscall3
          (i32.const 146)
          (i32.load offset=60
           (get_local $var$0)
          )
          (get_local $var$3)
          (i32.const 2)
         )
        )
       )
      )
     )
     (set_local $var$1
      (get_local $var$3)
     )
     (set_local $var$7
      (i32.add
       (get_local $var$0)
       (i32.const 60)
      )
     )
     (loop $label$4
      (br_if $label$2
       (i32.le_s
        (get_local $var$6)
        (i32.const -1)
       )
      )
      (i32.store
       (tee_local $var$1
        (select
         (i32.add
          (get_local $var$1)
          (i32.const 8)
         )
         (get_local $var$1)
         (tee_local $var$9
          (i32.gt_u
           (get_local $var$6)
           (tee_local $var$8
            (i32.load offset=4
             (get_local $var$1)
            )
           )
          )
         )
        )
       )
       (i32.add
        (i32.load
         (get_local $var$1)
        )
        (tee_local $var$8
         (i32.sub
          (get_local $var$6)
          (select
           (get_local $var$8)
           (i32.const 0)
           (get_local $var$9)
          )
         )
        )
       )
      )
      (i32.store offset=4
       (get_local $var$1)
       (i32.sub
        (i32.load offset=4
         (get_local $var$1)
        )
        (get_local $var$8)
       )
      )
      (set_local $var$5
       (i32.sub
        (get_local $var$5)
        (get_local $var$6)
       )
      )
      (set_local $var$6
       (tee_local $var$9
        (call $__syscall_ret
         (call $__syscall3
          (i32.const 146)
          (i32.load
           (get_local $var$7)
          )
          (get_local $var$1)
          (tee_local $var$4
           (i32.sub
            (get_local $var$4)
            (get_local $var$9)
           )
          )
         )
        )
       )
      )
      (br_if $label$4
       (i32.ne
        (get_local $var$5)
        (get_local $var$9)
       )
      )
     )
    )
    (i32.store
     (i32.add
      (get_local $var$0)
      (i32.const 28)
     )
     (tee_local $var$1
      (i32.load offset=44
       (get_local $var$0)
      )
     )
    )
    (i32.store
     (i32.add
      (get_local $var$0)
      (i32.const 20)
     )
     (get_local $var$1)
    )
    (i32.store offset=16
     (get_local $var$0)
     (i32.add
      (get_local $var$1)
      (i32.load offset=48
       (get_local $var$0)
      )
     )
    )
    (set_local $var$6
     (get_local $var$2)
    )
    (br $label$1)
   )
   (i64.store offset=16
    (get_local $var$0)
    (i64.const 0)
   )
   (set_local $var$6
    (i32.const 0)
   )
   (i32.store
    (i32.add
     (get_local $var$0)
     (i32.const 28)
    )
    (i32.const 0)
   )
   (i32.store
    (get_local $var$0)
    (i32.or
     (i32.load
      (get_local $var$0)
     )
     (i32.const 32)
    )
   )
   (br_if $label$1
    (i32.eq
     (get_local $var$4)
     (i32.const 2)
    )
   )
   (set_local $var$1
    (i32.load offset=4
     (get_local $var$1)
    )
   )
   (set_global $global$0
    (i32.add
     (get_local $var$3)
     (i32.const 16)
    )
   )
   (return
    (i32.sub
     (get_local $var$2)
     (get_local $var$1)
    )
   )
  )
  (set_global $global$0
   (i32.add
    (get_local $var$3)
    (i32.const 16)
   )
  )
  (get_local $var$6)
 )
 (func $__stdout_write (; 19 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (set_global $global$0
   (tee_local $var$3
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (i32.store offset=36
   (get_local $var$0)
   (i32.const 1)
  )
  (block $label$1
   (br_if $label$1
    (i32.and
     (i32.load8_u
      (get_local $var$0)
     )
     (i32.const 64)
    )
   )
   (br_if $label$1
    (i32.eqz
     (call $__syscall3
      (i32.const 54)
      (i32.load offset=60
       (get_local $var$0)
      )
      (i32.const 21523)
      (i32.add
       (get_local $var$3)
       (i32.const 8)
      )
     )
    )
   )
   (i32.store8 offset=75
    (get_local $var$0)
    (i32.const 255)
   )
  )
  (set_local $var$0
   (call $__stdio_write
    (get_local $var$0)
    (get_local $var$1)
    (get_local $var$2)
   )
  )
  (set_global $global$0
   (i32.add
    (get_local $var$3)
    (i32.const 16)
   )
  )
  (get_local $var$0)
 )
 (func $__stdio_seek (; 20 ;) (type $8) (param $var$0 i32) (param $var$1 i64) (param $var$2 i32) (result i64)
  (local $var$3 i32)
  (set_global $global$0
   (tee_local $var$3
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.lt_s
     (call $__syscall_ret
      (call $__syscall5
       (i32.const 140)
       (i32.load offset=60
        (get_local $var$0)
       )
       (i32.wrap/i64
        (i64.shr_u
         (get_local $var$1)
         (i64.const 32)
        )
       )
       (i32.wrap/i64
        (get_local $var$1)
       )
       (i32.add
        (get_local $var$3)
        (i32.const 8)
       )
       (get_local $var$2)
      )
     )
     (i32.const 0)
    )
   )
   (set_local $var$1
    (i64.load offset=8
     (get_local $var$3)
    )
   )
   (set_global $global$0
    (i32.add
     (get_local $var$3)
     (i32.const 16)
    )
   )
   (return
    (get_local $var$1)
   )
  )
  (i64.store offset=8
   (get_local $var$3)
   (i64.const -1)
  )
  (set_global $global$0
   (i32.add
    (get_local $var$3)
    (i32.const 16)
   )
  )
  (i64.const -1)
 )
 (func $memcpy (; 21 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (local $var$8 i32)
  (local $var$9 i32)
  (local $var$10 i32)
  (block $label$1
   (block $label$2
    (block $label$3
     (block $label$4
      (br_if $label$4
       (i32.eqz
        (get_local $var$2)
       )
      )
      (br_if $label$4
       (i32.eqz
        (i32.and
         (get_local $var$1)
         (i32.const 3)
        )
       )
      )
      (set_local $var$3
       (get_local $var$0)
      )
      (block $label$5
       (loop $label$6
        (i32.store8
         (get_local $var$3)
         (i32.load8_u
          (get_local $var$1)
         )
        )
        (set_local $var$4
         (i32.add
          (get_local $var$2)
          (i32.const -1)
         )
        )
        (set_local $var$3
         (i32.add
          (get_local $var$3)
          (i32.const 1)
         )
        )
        (set_local $var$1
         (i32.add
          (get_local $var$1)
          (i32.const 1)
         )
        )
        (br_if $label$5
         (i32.eq
          (get_local $var$2)
          (i32.const 1)
         )
        )
        (set_local $var$2
         (get_local $var$4)
        )
        (br_if $label$6
         (i32.and
          (get_local $var$1)
          (i32.const 3)
         )
        )
       )
      )
      (br_if $label$3
       (i32.eqz
        (i32.and
         (get_local $var$3)
         (i32.const 3)
        )
       )
      )
      (br $label$2)
     )
     (set_local $var$4
      (get_local $var$2)
     )
     (br_if $label$2
      (i32.and
       (tee_local $var$3
        (get_local $var$0)
       )
       (i32.const 3)
      )
     )
    )
    (block $label$7
     (block $label$8
      (block $label$9
       (br_if $label$9
        (i32.lt_u
         (get_local $var$4)
         (i32.const 16)
        )
       )
       (set_local $var$8
        (i32.add
         (get_local $var$3)
         (tee_local $var$6
          (i32.add
           (tee_local $var$7
            (i32.and
             (tee_local $var$5
              (i32.add
               (get_local $var$4)
               (i32.const -16)
              )
             )
             (i32.const -16)
            )
           )
           (i32.const 16)
          )
         )
        )
       )
       (set_local $var$2
        (get_local $var$1)
       )
       (loop $label$10
        (i32.store
         (get_local $var$3)
         (i32.load
          (get_local $var$2)
         )
        )
        (i32.store
         (i32.add
          (get_local $var$3)
          (i32.const 4)
         )
         (i32.load
          (i32.add
           (get_local $var$2)
           (i32.const 4)
          )
         )
        )
        (i32.store
         (i32.add
          (get_local $var$3)
          (i32.const 8)
         )
         (i32.load
          (i32.add
           (get_local $var$2)
           (i32.const 8)
          )
         )
        )
        (i32.store
         (i32.add
          (get_local $var$3)
          (i32.const 12)
         )
         (i32.load
          (i32.add
           (get_local $var$2)
           (i32.const 12)
          )
         )
        )
        (set_local $var$3
         (i32.add
          (get_local $var$3)
          (i32.const 16)
         )
        )
        (set_local $var$2
         (i32.add
          (get_local $var$2)
          (i32.const 16)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (tee_local $var$4
           (i32.add
            (get_local $var$4)
            (i32.const -16)
           )
          )
          (i32.const 15)
         )
        )
       )
       (set_local $var$1
        (i32.add
         (get_local $var$1)
         (get_local $var$6)
        )
       )
       (set_local $var$3
        (i32.const 8)
       )
       (br_if $label$8
        (i32.and
         (tee_local $var$4
          (i32.sub
           (get_local $var$5)
           (get_local $var$7)
          )
         )
         (i32.const 8)
        )
       )
       (br $label$7)
      )
      (set_local $var$8
       (get_local $var$3)
      )
      (set_local $var$3
       (i32.const 8)
      )
      (br_if $label$7
       (i32.eqz
        (i32.and
         (get_local $var$4)
         (i32.const 8)
        )
       )
      )
     )
     (i32.store
      (get_local $var$8)
      (i32.load
       (get_local $var$1)
      )
     )
     (i32.store offset=4
      (get_local $var$8)
      (i32.load offset=4
       (get_local $var$1)
      )
     )
     (set_local $var$1
      (i32.add
       (get_local $var$1)
       (get_local $var$3)
      )
     )
     (set_local $var$8
      (i32.add
       (get_local $var$8)
       (get_local $var$3)
      )
     )
    )
    (block $label$11
     (block $label$12
      (block $label$13
       (block $label$14
        (br_if $label$14
         (i32.and
          (get_local $var$4)
          (i32.const 4)
         )
        )
        (set_local $var$3
         (i32.const 2)
        )
        (br_if $label$13
         (i32.and
          (get_local $var$4)
          (i32.const 2)
         )
        )
        (br $label$12)
       )
       (i32.store
        (get_local $var$8)
        (i32.load
         (get_local $var$1)
        )
       )
       (set_local $var$1
        (i32.add
         (get_local $var$1)
         (i32.const 4)
        )
       )
       (set_local $var$8
        (i32.add
         (get_local $var$8)
         (i32.const 4)
        )
       )
       (set_local $var$3
        (i32.const 2)
       )
       (br_if $label$12
        (i32.eqz
         (i32.and
          (get_local $var$4)
          (i32.const 2)
         )
        )
       )
      )
      (i32.store8
       (get_local $var$8)
       (i32.load8_u
        (get_local $var$1)
       )
      )
      (i32.store8 offset=1
       (get_local $var$8)
       (i32.load8_u offset=1
        (get_local $var$1)
       )
      )
      (set_local $var$8
       (i32.add
        (get_local $var$8)
        (get_local $var$3)
       )
      )
      (set_local $var$1
       (i32.add
        (get_local $var$1)
        (get_local $var$3)
       )
      )
      (br_if $label$11
       (i32.and
        (get_local $var$4)
        (i32.const 1)
       )
      )
      (br $label$1)
     )
     (br_if $label$1
      (i32.eqz
       (i32.and
        (get_local $var$4)
        (i32.const 1)
       )
      )
     )
    )
    (i32.store8
     (get_local $var$8)
     (i32.load8_u
      (get_local $var$1)
     )
    )
    (return
     (get_local $var$0)
    )
   )
   (block $label$15
    (block $label$16
     (block $label$17
      (block $label$18
       (block $label$19
        (block $label$20
         (block $label$21
          (block $label$22
           (block $label$23
            (block $label$24
             (block $label$25
              (block $label$26
               (br_if $label$26
                (i32.lt_u
                 (get_local $var$4)
                 (i32.const 32)
                )
               )
               (br_if $label$25
                (i32.eq
                 (tee_local $var$2
                  (i32.and
                   (get_local $var$3)
                   (i32.const 3)
                  )
                 )
                 (i32.const 3)
                )
               )
               (br_if $label$24
                (i32.eq
                 (get_local $var$2)
                 (i32.const 2)
                )
               )
               (br_if $label$26
                (i32.ne
                 (get_local $var$2)
                 (i32.const 1)
                )
               )
               (i32.store8 offset=1
                (get_local $var$3)
                (i32.load8_u offset=1
                 (get_local $var$1)
                )
               )
               (i32.store8
                (get_local $var$3)
                (tee_local $var$5
                 (i32.load
                  (get_local $var$1)
                 )
                )
               )
               (i32.store8 offset=2
                (get_local $var$3)
                (i32.load8_u offset=2
                 (get_local $var$1)
                )
               )
               (set_local $var$2
                (i32.add
                 (get_local $var$1)
                 (i32.const 16)
                )
               )
               (set_local $var$6
                (i32.add
                 (get_local $var$4)
                 (i32.const -19)
                )
               )
               (set_local $var$7
                (i32.add
                 (get_local $var$4)
                 (i32.const -3)
                )
               )
               (set_local $var$8
                (i32.add
                 (get_local $var$3)
                 (i32.const 3)
                )
               )
               (set_local $var$1
                (i32.add
                 (get_local $var$1)
                 (tee_local $var$10
                  (i32.add
                   (tee_local $var$9
                    (i32.and
                     (i32.add
                      (get_local $var$4)
                      (i32.const -20)
                     )
                     (i32.const -16)
                    )
                   )
                   (i32.const 19)
                  )
                 )
                )
               )
               (loop $label$27
                (i32.store
                 (get_local $var$8)
                 (i32.or
                  (i32.shl
                   (tee_local $var$4
                    (i32.load
                     (i32.add
                      (get_local $var$2)
                      (i32.const -12)
                     )
                    )
                   )
                   (i32.const 8)
                  )
                  (i32.shr_u
                   (get_local $var$5)
                   (i32.const 24)
                  )
                 )
                )
                (i32.store
                 (i32.add
                  (get_local $var$8)
                  (i32.const 4)
                 )
                 (i32.or
                  (i32.shl
                   (tee_local $var$5
                    (i32.load
                     (i32.add
                      (get_local $var$2)
                      (i32.const -8)
                     )
                    )
                   )
                   (i32.const 8)
                  )
                  (i32.shr_u
                   (get_local $var$4)
                   (i32.const 24)
                  )
                 )
                )
                (i32.store
                 (i32.add
                  (get_local $var$8)
                  (i32.const 8)
                 )
                 (i32.or
                  (i32.shl
                   (tee_local $var$4
                    (i32.load
                     (i32.add
                      (get_local $var$2)
                      (i32.const -4)
                     )
                    )
                   )
                   (i32.const 8)
                  )
                  (i32.shr_u
                   (get_local $var$5)
                   (i32.const 24)
                  )
                 )
                )
                (i32.store
                 (i32.add
                  (get_local $var$8)
                  (i32.const 12)
                 )
                 (i32.or
                  (i32.shl
                   (tee_local $var$5
                    (i32.load
                     (get_local $var$2)
                    )
                   )
                   (i32.const 8)
                  )
                  (i32.shr_u
                   (get_local $var$4)
                   (i32.const 24)
                  )
                 )
                )
                (set_local $var$8
                 (i32.add
                  (get_local $var$8)
                  (i32.const 16)
                 )
                )
                (set_local $var$2
                 (i32.add
                  (get_local $var$2)
                  (i32.const 16)
                 )
                )
                (br_if $label$27
                 (i32.gt_u
                  (tee_local $var$7
                   (i32.add
                    (get_local $var$7)
                    (i32.const -16)
                   )
                  )
                  (i32.const 16)
                 )
                )
               )
               (set_local $var$4
                (i32.sub
                 (get_local $var$6)
                 (get_local $var$9)
                )
               )
               (set_local $var$3
                (i32.add
                 (get_local $var$3)
                 (get_local $var$10)
                )
               )
              )
              (set_local $var$2
               (i32.const 16)
              )
              (br_if $label$23
               (i32.and
                (get_local $var$4)
                (i32.const 16)
               )
              )
              (br $label$22)
             )
             (i32.store8
              (get_local $var$3)
              (tee_local $var$5
               (i32.load
                (get_local $var$1)
               )
              )
             )
             (set_local $var$2
              (i32.add
               (get_local $var$1)
               (i32.const 16)
              )
             )
             (set_local $var$6
              (i32.add
               (get_local $var$4)
               (i32.const -17)
              )
             )
             (set_local $var$7
              (i32.add
               (get_local $var$4)
               (i32.const -1)
              )
             )
             (set_local $var$8
              (i32.add
               (get_local $var$3)
               (i32.const 1)
              )
             )
             (set_local $var$1
              (i32.add
               (get_local $var$1)
               (tee_local $var$10
                (i32.add
                 (tee_local $var$9
                  (i32.and
                   (i32.add
                    (get_local $var$4)
                    (i32.const -20)
                   )
                   (i32.const -16)
                  )
                 )
                 (i32.const 17)
                )
               )
              )
             )
             (loop $label$28
              (i32.store
               (get_local $var$8)
               (i32.or
                (i32.shl
                 (tee_local $var$4
                  (i32.load
                   (i32.add
                    (get_local $var$2)
                    (i32.const -12)
                   )
                  )
                 )
                 (i32.const 24)
                )
                (i32.shr_u
                 (get_local $var$5)
                 (i32.const 8)
                )
               )
              )
              (i32.store
               (i32.add
                (get_local $var$8)
                (i32.const 4)
               )
               (i32.or
                (i32.shl
                 (tee_local $var$5
                  (i32.load
                   (i32.add
                    (get_local $var$2)
                    (i32.const -8)
                   )
                  )
                 )
                 (i32.const 24)
                )
                (i32.shr_u
                 (get_local $var$4)
                 (i32.const 8)
                )
               )
              )
              (i32.store
               (i32.add
                (get_local $var$8)
                (i32.const 8)
               )
               (i32.or
                (i32.shl
                 (tee_local $var$4
                  (i32.load
                   (i32.add
                    (get_local $var$2)
                    (i32.const -4)
                   )
                  )
                 )
                 (i32.const 24)
                )
                (i32.shr_u
                 (get_local $var$5)
                 (i32.const 8)
                )
               )
              )
              (i32.store
               (i32.add
                (get_local $var$8)
                (i32.const 12)
               )
               (i32.or
                (i32.shl
                 (tee_local $var$5
                  (i32.load
                   (get_local $var$2)
                  )
                 )
                 (i32.const 24)
                )
                (i32.shr_u
                 (get_local $var$4)
                 (i32.const 8)
                )
               )
              )
              (set_local $var$8
               (i32.add
                (get_local $var$8)
                (i32.const 16)
               )
              )
              (set_local $var$2
               (i32.add
                (get_local $var$2)
                (i32.const 16)
               )
              )
              (br_if $label$28
               (i32.gt_u
                (tee_local $var$7
                 (i32.add
                  (get_local $var$7)
                  (i32.const -16)
                 )
                )
                (i32.const 18)
               )
              )
             )
             (set_local $var$3
              (i32.add
               (get_local $var$3)
               (get_local $var$10)
              )
             )
             (set_local $var$2
              (i32.const 16)
             )
             (br_if $label$22
              (i32.eqz
               (i32.and
                (tee_local $var$4
                 (i32.sub
                  (get_local $var$6)
                  (get_local $var$9)
                 )
                )
                (i32.const 16)
               )
              )
             )
             (br $label$23)
            )
            (i32.store8
             (get_local $var$3)
             (tee_local $var$5
              (i32.load
               (get_local $var$1)
              )
             )
            )
            (i32.store8 offset=1
             (get_local $var$3)
             (i32.load8_u offset=1
              (get_local $var$1)
             )
            )
            (set_local $var$2
             (i32.add
              (get_local $var$1)
              (i32.const 16)
             )
            )
            (set_local $var$6
             (i32.add
              (get_local $var$4)
              (i32.const -18)
             )
            )
            (set_local $var$7
             (i32.add
              (get_local $var$4)
              (i32.const -2)
             )
            )
            (set_local $var$8
             (i32.add
              (get_local $var$3)
              (i32.const 2)
             )
            )
            (set_local $var$1
             (i32.add
              (get_local $var$1)
              (tee_local $var$10
               (i32.add
                (tee_local $var$9
                 (i32.and
                  (i32.add
                   (get_local $var$4)
                   (i32.const -20)
                  )
                  (i32.const -16)
                 )
                )
                (i32.const 18)
               )
              )
             )
            )
            (loop $label$29
             (i32.store
              (get_local $var$8)
              (i32.or
               (i32.shl
                (tee_local $var$4
                 (i32.load
                  (i32.add
                   (get_local $var$2)
                   (i32.const -12)
                  )
                 )
                )
                (i32.const 16)
               )
               (i32.shr_u
                (get_local $var$5)
                (i32.const 16)
               )
              )
             )
             (i32.store
              (i32.add
               (get_local $var$8)
               (i32.const 4)
              )
              (i32.or
               (i32.shl
                (tee_local $var$5
                 (i32.load
                  (i32.add
                   (get_local $var$2)
                   (i32.const -8)
                  )
                 )
                )
                (i32.const 16)
               )
               (i32.shr_u
                (get_local $var$4)
                (i32.const 16)
               )
              )
             )
             (i32.store
              (i32.add
               (get_local $var$8)
               (i32.const 8)
              )
              (i32.or
               (i32.shl
                (tee_local $var$4
                 (i32.load
                  (i32.add
                   (get_local $var$2)
                   (i32.const -4)
                  )
                 )
                )
                (i32.const 16)
               )
               (i32.shr_u
                (get_local $var$5)
                (i32.const 16)
               )
              )
             )
             (i32.store
              (i32.add
               (get_local $var$8)
               (i32.const 12)
              )
              (i32.or
               (i32.shl
                (tee_local $var$5
                 (i32.load
                  (get_local $var$2)
                 )
                )
                (i32.const 16)
               )
               (i32.shr_u
                (get_local $var$4)
                (i32.const 16)
               )
              )
             )
             (set_local $var$8
              (i32.add
               (get_local $var$8)
               (i32.const 16)
              )
             )
             (set_local $var$2
              (i32.add
               (get_local $var$2)
               (i32.const 16)
              )
             )
             (br_if $label$29
              (i32.gt_u
               (tee_local $var$7
                (i32.add
                 (get_local $var$7)
                 (i32.const -16)
                )
               )
               (i32.const 17)
              )
             )
            )
            (set_local $var$3
             (i32.add
              (get_local $var$3)
              (get_local $var$10)
             )
            )
            (set_local $var$2
             (i32.const 16)
            )
            (br_if $label$22
             (i32.eqz
              (i32.and
               (tee_local $var$4
                (i32.sub
                 (get_local $var$6)
                 (get_local $var$9)
                )
               )
               (i32.const 16)
              )
             )
            )
           )
           (i32.store8 offset=1
            (get_local $var$3)
            (i32.load8_u offset=1
             (get_local $var$1)
            )
           )
           (i32.store8 offset=2
            (get_local $var$3)
            (i32.load8_u offset=2
             (get_local $var$1)
            )
           )
           (i32.store8 offset=3
            (get_local $var$3)
            (i32.load8_u offset=3
             (get_local $var$1)
            )
           )
           (i32.store8 offset=4
            (get_local $var$3)
            (i32.load8_u offset=4
             (get_local $var$1)
            )
           )
           (i32.store8 offset=5
            (get_local $var$3)
            (i32.load8_u offset=5
             (get_local $var$1)
            )
           )
           (i32.store8 offset=6
            (get_local $var$3)
            (i32.load8_u offset=6
             (get_local $var$1)
            )
           )
           (i32.store8 offset=7
            (get_local $var$3)
            (i32.load8_u offset=7
             (get_local $var$1)
            )
           )
           (i32.store8 offset=8
            (get_local $var$3)
            (i32.load8_u offset=8
             (get_local $var$1)
            )
           )
           (i32.store8 offset=9
            (get_local $var$3)
            (i32.load8_u offset=9
             (get_local $var$1)
            )
           )
           (i32.store8 offset=10
            (get_local $var$3)
            (i32.load8_u offset=10
             (get_local $var$1)
            )
           )
           (i32.store8 offset=11
            (get_local $var$3)
            (i32.load8_u offset=11
             (get_local $var$1)
            )
           )
           (i32.store8 offset=12
            (get_local $var$3)
            (i32.load8_u offset=12
             (get_local $var$1)
            )
           )
           (i32.store8 offset=13
            (get_local $var$3)
            (i32.load8_u offset=13
             (get_local $var$1)
            )
           )
           (i32.store8 offset=14
            (get_local $var$3)
            (i32.load8_u offset=14
             (get_local $var$1)
            )
           )
           (i32.store8
            (get_local $var$3)
            (i32.load8_u
             (get_local $var$1)
            )
           )
           (i32.store8 offset=15
            (get_local $var$3)
            (i32.load8_u offset=15
             (get_local $var$1)
            )
           )
           (set_local $var$3
            (i32.add
             (get_local $var$3)
             (get_local $var$2)
            )
           )
           (set_local $var$1
            (i32.add
             (get_local $var$1)
             (get_local $var$2)
            )
           )
           (set_local $var$2
            (i32.const 8)
           )
           (br_if $label$21
            (i32.eqz
             (i32.and
              (get_local $var$4)
              (i32.const 8)
             )
            )
           )
           (br $label$20)
          )
          (set_local $var$2
           (i32.const 8)
          )
          (br_if $label$20
           (i32.and
            (get_local $var$4)
            (i32.const 8)
           )
          )
         )
         (set_local $var$2
          (i32.const 4)
         )
         (br_if $label$19
          (i32.and
           (get_local $var$4)
           (i32.const 4)
          )
         )
         (br $label$18)
        )
        (i32.store8
         (get_local $var$3)
         (i32.load8_u
          (get_local $var$1)
         )
        )
        (i32.store8 offset=1
         (get_local $var$3)
         (i32.load8_u offset=1
          (get_local $var$1)
         )
        )
        (i32.store8 offset=2
         (get_local $var$3)
         (i32.load8_u offset=2
          (get_local $var$1)
         )
        )
        (i32.store8 offset=3
         (get_local $var$3)
         (i32.load8_u offset=3
          (get_local $var$1)
         )
        )
        (i32.store8 offset=4
         (get_local $var$3)
         (i32.load8_u offset=4
          (get_local $var$1)
         )
        )
        (i32.store8 offset=5
         (get_local $var$3)
         (i32.load8_u offset=5
          (get_local $var$1)
         )
        )
        (i32.store8 offset=6
         (get_local $var$3)
         (i32.load8_u offset=6
          (get_local $var$1)
         )
        )
        (i32.store8 offset=7
         (get_local $var$3)
         (i32.load8_u offset=7
          (get_local $var$1)
         )
        )
        (set_local $var$3
         (i32.add
          (get_local $var$3)
          (get_local $var$2)
         )
        )
        (set_local $var$1
         (i32.add
          (get_local $var$1)
          (get_local $var$2)
         )
        )
        (set_local $var$2
         (i32.const 4)
        )
        (br_if $label$18
         (i32.eqz
          (i32.and
           (get_local $var$4)
           (i32.const 4)
          )
         )
        )
       )
       (i32.store8
        (get_local $var$3)
        (i32.load8_u
         (get_local $var$1)
        )
       )
       (i32.store8 offset=1
        (get_local $var$3)
        (i32.load8_u offset=1
         (get_local $var$1)
        )
       )
       (i32.store8 offset=2
        (get_local $var$3)
        (i32.load8_u offset=2
         (get_local $var$1)
        )
       )
       (i32.store8 offset=3
        (get_local $var$3)
        (i32.load8_u offset=3
         (get_local $var$1)
        )
       )
       (set_local $var$3
        (i32.add
         (get_local $var$3)
         (get_local $var$2)
        )
       )
       (set_local $var$1
        (i32.add
         (get_local $var$1)
         (get_local $var$2)
        )
       )
       (set_local $var$2
        (i32.const 2)
       )
       (br_if $label$17
        (i32.eqz
         (i32.and
          (get_local $var$4)
          (i32.const 2)
         )
        )
       )
       (br $label$16)
      )
      (set_local $var$2
       (i32.const 2)
      )
      (br_if $label$16
       (i32.and
        (get_local $var$4)
        (i32.const 2)
       )
      )
     )
     (br_if $label$15
      (i32.and
       (get_local $var$4)
       (i32.const 1)
      )
     )
     (br $label$1)
    )
    (i32.store8
     (get_local $var$3)
     (i32.load8_u
      (get_local $var$1)
     )
    )
    (i32.store8 offset=1
     (get_local $var$3)
     (i32.load8_u offset=1
      (get_local $var$1)
     )
    )
    (set_local $var$3
     (i32.add
      (get_local $var$3)
      (get_local $var$2)
     )
    )
    (set_local $var$1
     (i32.add
      (get_local $var$1)
      (get_local $var$2)
     )
    )
    (br_if $label$1
     (i32.eqz
      (i32.and
       (get_local $var$4)
       (i32.const 1)
      )
     )
    )
   )
   (i32.store8
    (get_local $var$3)
    (i32.load8_u
     (get_local $var$1)
    )
   )
  )
  (get_local $var$0)
 )
 (func $strlen (; 22 ;) (type $7) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (set_local $var$1
   (get_local $var$0)
  )
  (block $label$1
   (block $label$2
    (block $label$3
     (br_if $label$3
      (i32.eqz
       (i32.and
        (get_local $var$0)
        (i32.const 3)
       )
      )
     )
     (br_if $label$2
      (i32.eqz
       (i32.load8_u
        (get_local $var$0)
       )
      )
     )
     (set_local $var$1
      (i32.add
       (get_local $var$0)
       (i32.const 1)
      )
     )
     (loop $label$4
      (br_if $label$3
       (i32.eqz
        (i32.and
         (get_local $var$1)
         (i32.const 3)
        )
       )
      )
      (set_local $var$2
       (i32.load8_u
        (get_local $var$1)
       )
      )
      (set_local $var$1
       (tee_local $var$3
        (i32.add
         (get_local $var$1)
         (i32.const 1)
        )
       )
      )
      (br_if $label$4
       (get_local $var$2)
      )
     )
     (return
      (i32.sub
       (i32.add
        (get_local $var$3)
        (i32.const -1)
       )
       (get_local $var$0)
      )
     )
    )
    (set_local $var$1
     (i32.add
      (get_local $var$1)
      (i32.const -4)
     )
    )
    (loop $label$5
     (br_if $label$5
      (i32.eqz
       (i32.and
        (i32.and
         (i32.xor
          (tee_local $var$2
           (i32.load
            (tee_local $var$1
             (i32.add
              (get_local $var$1)
              (i32.const 4)
             )
            )
           )
          )
          (i32.const -1)
         )
         (i32.add
          (get_local $var$2)
          (i32.const -16843009)
         )
        )
        (i32.const -2139062144)
       )
      )
     )
    )
    (br_if $label$1
     (i32.eqz
      (i32.and
       (get_local $var$2)
       (i32.const 255)
      )
     )
    )
    (loop $label$6
     (set_local $var$2
      (i32.load8_u offset=1
       (get_local $var$1)
      )
     )
     (set_local $var$1
      (tee_local $var$3
       (i32.add
        (get_local $var$1)
        (i32.const 1)
       )
      )
     )
     (br_if $label$6
      (get_local $var$2)
     )
    )
    (return
     (i32.sub
      (get_local $var$3)
      (get_local $var$0)
     )
    )
   )
   (return
    (i32.sub
     (get_local $var$0)
     (get_local $var$0)
    )
   )
  )
  (i32.sub
   (get_local $var$1)
   (get_local $var$0)
  )
 )
 ;; custom section ".debug_info", size 13874
 ;; custom section ".debug_macinfo", size 20
 ;; custom section ".debug_loc", size 487
 ;; custom section ".debug_ranges", size 480
 ;; custom section ".debug_abbrev", size 4064
 ;; custom section ".debug_line", size 7741
 ;; custom section ".debug_str", size 9567
)
