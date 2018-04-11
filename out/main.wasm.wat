(module
 (type $0 (func (param i32 i32 i32) (result i32)))
 (type $1 (func (param i32) (result i32)))
 (type $2 (func (param i32 i32 i32 i32) (result i32)))
 (type $3 (func (param i32 i32) (result i32)))
 (type $4 (func (param i32 i32 i32 i32 i32 i32) (result i32)))
 (type $5 (func (param i32 i32 i32 i32 i32) (result i32)))
 (type $6 (func))
 (type $7 (func (result i32)))
 (type $8 (func (param i32)))
 (type $9 (func (param i32 i64 i32) (result i64)))
 (type $10 (func (param i32 i32 i32 i32)))
 (import "env" "putc_js" (func $import$0 (param i32) (result i32)))
 (import "env" "__syscall0" (func $import$1 (param i32) (result i32)))
 (import "env" "__syscall3" (func $import$2 (param i32 i32 i32 i32) (result i32)))
 (import "env" "__syscall1" (func $import$3 (param i32 i32) (result i32)))
 (import "env" "__syscall5" (func $import$4 (param i32 i32 i32 i32 i32 i32) (result i32)))
 (import "env" "__syscall4" (func $import$5 (param i32 i32 i32 i32 i32) (result i32)))
 (global $global$0 (mut i32) (i32.const 67776))
 (global $global$1 i32 (i32.const 67776))
 (global $global$2 i32 (i32.const 2232))
 (table 5 5 anyfunc)
 (elem (i32.const 1) $11 $10 $12 $13)
 (memory $0 2)
 (data (i32.const 1024) "Hello Hatem... !")
 (data (i32.const 1048) "\05")
 (data (i32.const 1060) "\02")
 (data (i32.const 1084) "\03\00\00\00\04\00\00\00\b8\04\00\00\00\04")
 (data (i32.const 1108) "\01")
 (data (i32.const 1123) "\n\ff\ff\ff\ff")
 (data (i32.const 1192) "\18\04")
 (export "memory" (memory $0))
 (export "_start" (func $0))
 (export "main" (func $1))
 (export "writev_c" (func $2))
 (export "__heap_base" (global $global$1))
 (export "__data_end" (global $global$2))
 (func $0 (; 6 ;) (type $6)
  (nop)
 )
 (func $1 (; 7 ;) (type $7) (result i32)
  (drop
   (call $9
    (i32.const 1024)
   )
  )
  (i32.const 0)
 )
 (func $2 (; 8 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (if
   (i32.ge_s
    (get_local $var$2)
    (i32.const 1)
   )
   (block
    (set_local $var$0
     (i32.const 0)
    )
    (loop $label$2
     (set_local $var$5
      (i32.const 0)
     )
     (if
      (i32.load offset=4
       (tee_local $var$6
        (i32.add
         (get_local $var$1)
         (i32.shl
          (get_local $var$0)
          (i32.const 3)
         )
        )
       )
      )
      (block
       (set_local $var$7
        (i32.add
         (get_local $var$6)
         (i32.const 4)
        )
       )
       (set_local $var$4
        (i32.const 0)
       )
       (loop $label$4
        (drop
         (call $import$0
          (i32.load8_s
           (i32.add
            (i32.load
             (get_local $var$6)
            )
            (get_local $var$4)
           )
          )
         )
        )
        (br_if $label$4
         (i32.lt_u
          (tee_local $var$4
           (i32.add
            (get_local $var$4)
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
     )
     (set_local $var$3
      (i32.add
       (get_local $var$5)
       (get_local $var$3)
      )
     )
     (br_if $label$2
      (i32.ne
       (tee_local $var$0
        (i32.add
         (get_local $var$0)
         (i32.const 1)
        )
       )
       (get_local $var$2)
      )
     )
    )
    (return
     (get_local $var$3)
    )
   )
  )
  (i32.const 0)
 )
 (func $3 (; 9 ;) (type $1) (param $var$0 i32) (result i32)
  (if
   (i32.ge_u
    (get_local $var$0)
    (i32.const -4095)
   )
   (block
    (i32.store
     (i32.const 39)
     (i32.sub
      (i32.const 0)
      (get_local $var$0)
     )
    )
    (set_local $var$0
     (i32.const -1)
    )
   )
  )
  (get_local $var$0)
 )
 (func $4 (; 10 ;) (type $1) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (if
   (i32.ne
    (tee_local $var$3
     (i32.load
      (i32.const 27)
     )
    )
    (i32.load offset=76
     (get_local $var$0)
    )
   )
   (block
    (if
     (tee_local $var$2
      (i32.load
       (tee_local $var$1
        (i32.add
         (get_local $var$0)
         (i32.const 76)
        )
       )
      )
     )
     (block
      (set_local $var$0
       (i32.add
        (get_local $var$0)
        (i32.const 80)
       )
      )
      (loop $label$3
       (call $16
        (get_local $var$1)
        (get_local $var$0)
        (get_local $var$2)
        (i32.const 1)
       )
       (br_if $label$3
        (tee_local $var$2
         (i32.load
          (get_local $var$1)
         )
        )
       )
      )
     )
    )
    (i32.store
     (get_local $var$1)
     (get_local $var$3)
    )
    (set_local $var$1
     (i32.const 1)
    )
   )
  )
  (get_local $var$1)
 )
 (func $5 (; 11 ;) (type $8) (param $var$0 i32)
  (drop
   (call $3
    (call $import$1
     (i32.const 375)
    )
   )
  )
  (i32.store offset=76
   (get_local $var$0)
   (i32.const 0)
  )
  (drop
   (call $3
    (call $import$1
     (i32.const 375)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eqz
     (i32.load offset=80
      (get_local $var$0)
     )
    )
   )
   (br_if $label$1
    (i32.ne
     (call $import$2
      (i32.const 240)
      (tee_local $var$0
       (i32.add
        (get_local $var$0)
        (i32.const 76)
       )
      )
      (i32.const 129)
      (i32.const 1)
     )
     (i32.const -38)
    )
   )
   (drop
    (call $import$2
     (i32.const 240)
     (get_local $var$0)
     (i32.const 1)
     (i32.const 1)
    )
   )
  )
 )
 (func $6 (; 12 ;) (type $1) (param $var$0 i32) (result i32)
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
  (if
   (i32.eqz
    (i32.and
     (tee_local $var$1
      (i32.load
       (get_local $var$0)
      )
     )
     (i32.const 8)
    )
   )
   (block
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
 (func $7 (; 13 ;) (type $2) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (param $var$3 i32) (result i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (local $var$6 i32)
  (local $var$7 i32)
  (local $var$8 i32)
  (local $var$9 i32)
  (local $var$10 i32)
  (local $var$11 i32)
  (if
   (i32.ge_s
    (i32.load offset=76
     (get_local $var$3)
    )
    (i32.const 0)
   )
   (set_local $var$7
    (i32.ne
     (call $4
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
       (if
        (tee_local $var$4
         (i32.load offset=16
          (get_local $var$3)
         )
        )
        (block
         (br_if $label$6
          (i32.ge_u
           (i32.sub
            (get_local $var$4)
            (tee_local $var$8
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
       )
       (set_local $var$4
        (i32.const 0)
       )
       (br_if $label$3
        (call $6
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
          (tee_local $var$8
           (i32.load offset=20
            (get_local $var$3)
           )
          )
         )
         (get_local $var$5)
        )
       )
      )
      (set_local $var$4
       (block $label$8 (result i32)
        (block $label$9
         (br_if $label$9
          (i32.lt_s
           (i32.load8_s offset=75
            (get_local $var$3)
           )
           (i32.const 0)
          )
         )
         (set_local $var$11
          (i32.add
           (get_local $var$0)
           (get_local $var$5)
          )
         )
         (set_local $var$4
          (i32.const 0)
         )
         (loop $label$10
          (br_if $label$9
           (i32.eqz
            (i32.add
             (get_local $var$5)
             (get_local $var$4)
            )
           )
          )
          (set_local $var$9
           (i32.add
            (get_local $var$11)
            (get_local $var$4)
           )
          )
          (set_local $var$4
           (tee_local $var$10
            (i32.add
             (get_local $var$4)
             (i32.const -1)
            )
           )
          )
          (br_if $label$10
           (i32.ne
            (i32.load8_u
             (i32.add
              (get_local $var$9)
              (i32.const -1)
             )
            )
            (i32.const 10)
           )
          )
         )
         (br_if $label$3
          (i32.lt_u
           (tee_local $var$4
            (call_indirect (type $0)
             (get_local $var$3)
             (get_local $var$0)
             (tee_local $var$6
              (i32.add
               (i32.add
                (get_local $var$5)
                (get_local $var$10)
               )
               (i32.const 1)
              )
             )
             (i32.load offset=36
              (get_local $var$3)
             )
            )
           )
           (get_local $var$6)
          )
         )
         (set_local $var$0
          (i32.add
           (i32.add
            (get_local $var$11)
            (get_local $var$10)
           )
           (i32.const 1)
          )
         )
         (set_local $var$8
          (i32.load
           (i32.add
            (get_local $var$3)
            (i32.const 20)
           )
          )
         )
         (br $label$8
          (i32.xor
           (get_local $var$10)
           (i32.const -1)
          )
         )
        )
        (get_local $var$5)
       )
      )
      (drop
       (call $14
        (get_local $var$8)
        (get_local $var$0)
        (get_local $var$4)
       )
      )
      (i32.store
       (tee_local $var$9
        (i32.add
         (get_local $var$3)
         (i32.const 20)
        )
       )
       (i32.add
        (i32.load
         (get_local $var$9)
        )
        (get_local $var$4)
       )
      )
      (set_local $var$4
       (i32.add
        (get_local $var$6)
        (get_local $var$4)
       )
      )
     )
     (br $label$3)
    )
    (set_local $var$4
     (call_indirect (type $0)
      (get_local $var$3)
      (get_local $var$0)
      (get_local $var$5)
      (i32.load offset=36
       (get_local $var$3)
      )
     )
    )
   )
   (br_if $label$2
    (i32.eqz
     (get_local $var$7)
    )
   )
   (call $5
    (get_local $var$3)
   )
  )
  (if
   (i32.eq
    (get_local $var$4)
    (get_local $var$5)
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
   (get_local $var$4)
   (get_local $var$1)
  )
 )
 (func $8 (; 14 ;) (type $3) (param $var$0 i32) (param $var$1 i32) (result i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (set_global $global$0
   (tee_local $var$3
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (i32.store8 offset=15
   (get_local $var$3)
   (get_local $var$1)
  )
  (set_local $var$2
   (block $label$1 (result i32)
    (block $label$2
     (block $label$3
      (if
       (tee_local $var$2
        (i32.load offset=16
         (get_local $var$0)
        )
       )
       (block
        (br_if $label$2
         (i32.ge_u
          (tee_local $var$4
           (i32.load offset=20
            (get_local $var$0)
           )
          )
          (get_local $var$2)
         )
        )
        (br $label$3)
       )
      )
      (drop
       (br_if $label$1
        (tee_local $var$2
         (i32.const -1)
        )
        (call $6
         (get_local $var$0)
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
       (tee_local $var$2
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
       (get_local $var$3)
       (i32.const 16)
      )
     )
     (return
      (get_local $var$2)
     )
    )
    (drop
     (br_if $label$1
      (tee_local $var$2
       (i32.const -1)
      )
      (i32.ne
       (call_indirect (type $0)
        (get_local $var$0)
        (i32.add
         (get_local $var$3)
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
    )
    (i32.load8_u offset=15
     (get_local $var$3)
    )
   )
  )
  (set_global $global$0
   (i32.add
    (get_local $var$3)
    (i32.const 16)
   )
  )
  (get_local $var$2)
 )
 (func $9 (; 15 ;) (type $1) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (if
   (i32.ge_s
    (i32.load offset=76
     (tee_local $var$1
      (i32.load
       (i32.const 1192)
      )
     )
    )
    (i32.const 0)
   )
   (set_local $var$2
    (call $4
     (get_local $var$1)
    )
   )
  )
  (block $label$2
   (block $label$3
    (if
     (i32.ge_s
      (select
       (i32.const -1)
       (i32.const 0)
       (i32.ne
        (tee_local $var$3
         (call $15
          (get_local $var$0)
         )
        )
        (call $7
         (get_local $var$0)
         (i32.const 1)
         (get_local $var$3)
         (get_local $var$1)
        )
       )
      )
      (i32.const 0)
     )
     (block
      (block $label$5
       (br_if $label$5
        (i32.eq
         (i32.load8_u offset=75
          (get_local $var$1)
         )
         (i32.const 10)
        )
       )
       (br_if $label$5
        (i32.ge_u
         (tee_local $var$0
          (i32.load offset=20
           (get_local $var$1)
          )
         )
         (i32.load offset=16
          (get_local $var$1)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $var$1)
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
        (get_local $var$2)
       )
       (br $label$2)
      )
      (set_local $var$0
       (i32.shr_s
        (call $8
         (get_local $var$1)
         (i32.const 10)
        )
        (i32.const 31)
       )
      )
      (br_if $label$2
       (i32.eqz
        (get_local $var$2)
       )
      )
      (br $label$3)
     )
    )
    (set_local $var$0
     (i32.const -1)
    )
    (br_if $label$2
     (i32.eqz
      (get_local $var$2)
     )
    )
   )
   (call $5
    (get_local $var$1)
   )
  )
  (get_local $var$0)
 )
 (func $10 (; 16 ;) (type $1) (param $var$0 i32) (result i32)
  (call $3
   (call $import$3
    (i32.const 6)
    (i32.load offset=60
     (get_local $var$0)
    )
   )
  )
 )
 (func $11 (; 17 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
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
  (set_local $var$6
   (i32.const 2)
  )
  (block $label$1
   (block $label$2
    (if
     (i32.ne
      (tee_local $var$7
       (i32.add
        (get_local $var$1)
        (get_local $var$2)
       )
      )
      (tee_local $var$4
       (call $3
        (call $import$2
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
     (block
      (set_local $var$1
       (get_local $var$3)
      )
      (set_local $var$9
       (i32.add
        (get_local $var$0)
        (i32.const 60)
       )
      )
      (loop $label$4
       (br_if $label$2
        (i32.le_s
         (get_local $var$4)
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
          (tee_local $var$5
           (i32.gt_u
            (get_local $var$4)
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
           (get_local $var$4)
           (select
            (get_local $var$8)
            (i32.const 0)
            (get_local $var$5)
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
       (set_local $var$7
        (i32.sub
         (get_local $var$7)
         (get_local $var$4)
        )
       )
       (set_local $var$4
        (tee_local $var$5
         (call $3
          (call $import$2
           (i32.const 146)
           (i32.load
            (get_local $var$9)
           )
           (get_local $var$1)
           (tee_local $var$6
            (i32.sub
             (get_local $var$6)
             (get_local $var$5)
            )
           )
          )
         )
        )
       )
       (br_if $label$4
        (i32.ne
         (get_local $var$7)
         (get_local $var$5)
        )
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
    (set_local $var$4
     (get_local $var$2)
    )
    (br $label$1)
   )
   (i64.store offset=16
    (get_local $var$0)
    (i64.const 0)
   )
   (set_local $var$4
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
     (get_local $var$6)
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
  (get_local $var$4)
 )
 (func $12 (; 18 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
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
     (call $import$2
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
   (call $11
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
 (func $13 (; 19 ;) (type $9) (param $var$0 i32) (param $var$1 i64) (param $var$2 i32) (result i64)
  (local $var$3 i32)
  (set_global $global$0
   (tee_local $var$3
    (i32.sub
     (get_global $global$0)
     (i32.const 16)
    )
   )
  )
  (if
   (i32.ge_s
    (call $3
     (call $import$4
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
   (block
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
 (func $14 (; 20 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
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
     (if
      (i32.eqz
       (i32.or
        (i32.eqz
         (get_local $var$2)
        )
        (i32.eqz
         (i32.and
          (get_local $var$1)
          (i32.const 3)
         )
        )
       )
      )
      (block
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
      (if
       (i32.ge_u
        (get_local $var$4)
        (i32.const 16)
       )
       (block
        (set_local $var$5
         (i32.add
          (get_local $var$3)
          (tee_local $var$8
           (i32.add
            (tee_local $var$7
             (i32.and
              (tee_local $var$6
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
          (get_local $var$8)
         )
        )
        (set_local $var$3
         (i32.const 8)
        )
        (br_if $label$8
         (i32.and
          (tee_local $var$4
           (i32.sub
            (get_local $var$6)
            (get_local $var$7)
           )
          )
          (i32.const 8)
         )
        )
        (br $label$7)
       )
      )
      (set_local $var$5
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
      (get_local $var$5)
      (i32.load
       (get_local $var$1)
      )
     )
     (i32.store offset=4
      (get_local $var$5)
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
     (set_local $var$5
      (i32.add
       (get_local $var$5)
       (get_local $var$3)
      )
     )
    )
    (block $label$11
     (block $label$12
      (block $label$13
       (if
        (i32.eqz
         (i32.and
          (get_local $var$4)
          (i32.const 4)
         )
        )
        (block
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
       )
       (i32.store
        (get_local $var$5)
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
       (set_local $var$5
        (i32.add
         (get_local $var$5)
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
       (get_local $var$5)
       (i32.load8_u
        (get_local $var$1)
       )
      )
      (i32.store8 offset=1
       (get_local $var$5)
       (i32.load8_u offset=1
        (get_local $var$1)
       )
      )
      (set_local $var$5
       (i32.add
        (get_local $var$5)
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
     (get_local $var$5)
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
                (tee_local $var$6
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
               (set_local $var$8
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
               (set_local $var$5
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
                 (get_local $var$5)
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
                   (get_local $var$6)
                   (i32.const 24)
                  )
                 )
                )
                (i32.store
                 (i32.add
                  (get_local $var$5)
                  (i32.const 4)
                 )
                 (i32.or
                  (i32.shl
                   (tee_local $var$6
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
                  (get_local $var$5)
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
                   (get_local $var$6)
                   (i32.const 24)
                  )
                 )
                )
                (i32.store
                 (i32.add
                  (get_local $var$5)
                  (i32.const 12)
                 )
                 (i32.or
                  (i32.shl
                   (tee_local $var$6
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
                (set_local $var$5
                 (i32.add
                  (get_local $var$5)
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
                 (get_local $var$8)
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
              (tee_local $var$6
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
             (set_local $var$8
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
             (set_local $var$5
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
               (get_local $var$5)
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
                 (get_local $var$6)
                 (i32.const 8)
                )
               )
              )
              (i32.store
               (i32.add
                (get_local $var$5)
                (i32.const 4)
               )
               (i32.or
                (i32.shl
                 (tee_local $var$6
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
                (get_local $var$5)
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
                 (get_local $var$6)
                 (i32.const 8)
                )
               )
              )
              (i32.store
               (i32.add
                (get_local $var$5)
                (i32.const 12)
               )
               (i32.or
                (i32.shl
                 (tee_local $var$6
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
              (set_local $var$5
               (i32.add
                (get_local $var$5)
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
                  (get_local $var$8)
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
             (tee_local $var$6
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
            (set_local $var$8
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
            (set_local $var$5
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
              (get_local $var$5)
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
                (get_local $var$6)
                (i32.const 16)
               )
              )
             )
             (i32.store
              (i32.add
               (get_local $var$5)
               (i32.const 4)
              )
              (i32.or
               (i32.shl
                (tee_local $var$6
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
               (get_local $var$5)
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
                (get_local $var$6)
                (i32.const 16)
               )
              )
             )
             (i32.store
              (i32.add
               (get_local $var$5)
               (i32.const 12)
              )
              (i32.or
               (i32.shl
                (tee_local $var$6
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
             (set_local $var$5
              (i32.add
               (get_local $var$5)
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
                 (get_local $var$8)
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
 (func $15 (; 21 ;) (type $1) (param $var$0 i32) (result i32)
  (local $var$1 i32)
  (local $var$2 i32)
  (local $var$3 i32)
  (set_local $var$1
   (get_local $var$0)
  )
  (block $label$1
   (block $label$2
    (if
     (i32.and
      (get_local $var$0)
      (i32.const 3)
     )
     (loop $label$4
      (br_if $label$2
       (i32.eqz
        (i32.load8_u
         (get_local $var$1)
        )
       )
      )
      (br_if $label$4
       (i32.and
        (tee_local $var$1
         (i32.add
          (get_local $var$1)
          (i32.const 1)
         )
        )
        (i32.const 3)
       )
      )
     )
    )
    (set_local $var$2
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
          (tee_local $var$1
           (i32.load
            (tee_local $var$2
             (i32.add
              (get_local $var$2)
              (i32.const 4)
             )
            )
           )
          )
          (i32.const -1)
         )
         (i32.add
          (get_local $var$1)
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
       (get_local $var$1)
       (i32.const 255)
      )
     )
    )
    (loop $label$6
     (set_local $var$3
      (i32.load8_u offset=1
       (get_local $var$2)
      )
     )
     (set_local $var$2
      (tee_local $var$1
       (i32.add
        (get_local $var$2)
        (i32.const 1)
       )
      )
     )
     (br_if $label$6
      (get_local $var$3)
     )
    )
   )
   (return
    (i32.sub
     (get_local $var$1)
     (get_local $var$0)
    )
   )
  )
  (i32.sub
   (get_local $var$2)
   (get_local $var$0)
  )
 )
 (func $16 (; 22 ;) (type $10) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (param $var$3 i32)
  (local $var$4 i32)
  (local $var$5 i32)
  (block $label$1
   (block $label$2
    (block $label$3
     (block $label$4
      (block $label$5
       (block $label$6
        (if
         (get_local $var$1)
         (block
          (set_local $var$4
           (i32.const -100)
          )
          (loop $label$8
           (br_if $label$5
            (i32.load
             (get_local $var$1)
            )
           )
           (br_if $label$1
            (i32.ne
             (i32.load
              (get_local $var$0)
             )
             (get_local $var$2)
            )
           )
           (drop
            (call $3
             (call $import$1
              (i32.const 375)
             )
            )
           )
           (br_if $label$8
            (tee_local $var$4
             (i32.add
              (get_local $var$4)
              (i32.const 1)
             )
            )
           )
           (br $label$6)
          )
         )
        )
        (set_local $var$4
         (i32.const -100)
        )
        (loop $label$9
         (br_if $label$1
          (i32.ne
           (i32.load
            (get_local $var$0)
           )
           (get_local $var$2)
          )
         )
         (drop
          (call $3
           (call $import$1
            (i32.const 375)
           )
          )
         )
         (br_if $label$9
          (tee_local $var$4
           (i32.add
            (get_local $var$4)
            (i32.const 1)
           )
          )
         )
        )
       )
       (br_if $label$4
        (i32.eqz
         (get_local $var$1)
        )
       )
      )
      (loop $label$10
       (br_if $label$10
        (i32.ne
         (tee_local $var$4
          (i32.load
           (get_local $var$1)
          )
         )
         (i32.load
          (get_local $var$1)
         )
        )
       )
      )
      (set_local $var$5
       (i32.const 1)
      )
      (i32.store
       (get_local $var$1)
       (i32.add
        (get_local $var$4)
        (i32.const 1)
       )
      )
      (br_if $label$3
       (i32.eq
        (i32.load
         (get_local $var$0)
        )
        (get_local $var$2)
       )
      )
      (br $label$2)
     )
     (br_if $label$2
      (i32.ne
       (i32.load
        (get_local $var$0)
       )
       (get_local $var$2)
      )
     )
    )
    (set_local $var$4
     (select
      (i32.const 128)
      (i32.const 0)
      (get_local $var$3)
     )
    )
    (loop $label$11
     (if
      (i32.eq
       (call $import$5
        (i32.const 240)
        (get_local $var$0)
        (get_local $var$4)
        (get_local $var$2)
        (i32.const 0)
       )
       (i32.const -38)
      )
      (drop
       (call $import$5
        (i32.const 240)
        (get_local $var$0)
        (i32.const 0)
        (get_local $var$2)
        (i32.const 0)
       )
      )
     )
     (br_if $label$11
      (i32.eq
       (i32.load
        (get_local $var$0)
       )
       (get_local $var$2)
      )
     )
    )
   )
   (br_if $label$1
    (i32.eqz
     (get_local $var$5)
    )
   )
   (loop $label$13
    (br_if $label$13
     (i32.ne
      (tee_local $var$2
       (i32.load
        (get_local $var$1)
       )
      )
      (i32.load
       (get_local $var$1)
      )
     )
    )
   )
   (i32.store
    (get_local $var$1)
    (i32.add
     (get_local $var$2)
     (i32.const -1)
    )
   )
  )
 )
)
