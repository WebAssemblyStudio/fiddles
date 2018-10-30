(module
 (type $v (func))
 (type $iiiiv (func (param i32 i32 i32 i32)))
 (import "env" "abort" (func $~lib/env/abort (param i32 i32 i32 i32)))
 (memory $0 1 65535)
 (data (i32.const 8) "\07\00\00\00m\00a\00i\00n\00.\00t\00s")
 (table 1 anyfunc)
 (elem (i32.const 0) $null)
 (export "memory" (memory $0))
 (export "table" (table $0))
 (export "testBreak" (func $main/testBreak))
 (start $start)
 (func $main/testBreak (; 1 ;) (; has Stack IR ;) (type $v)
  (local $0 i32)
  (local $1 i32)
  ;;@ main.ts:4:8
  (block $break|0
   (loop $repeat|0
    (br_if $break|0
     ;;@ main.ts:4:28
     (i32.ge_s
      (get_local $0)
      ;;@ main.ts:4:34
      (i32.const 32)
     )
    )
    (set_local $1
     ;;@ main.ts:5:12
     (if (result i32)
      ;;@ main.ts:5:16
      (i32.eq
       (get_local $0)
       ;;@ main.ts:5:23
       (i32.const 12)
      )
      ;;@ main.ts:6:23
      (i32.add
       (get_local $0)
       ;;@ main.ts:6:29
       (i32.const 32)
      )
      (block
       ;;@ main.ts:4:38
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 1)
        )
       )
       (br $repeat|0)
      )
     )
    )
   )
  )
  ;;@ main.ts:10:8
  (if
   ;;@ main.ts:10:15
   (i32.ne
    (get_local $1)
    ;;@ main.ts:10:23
    (i32.const 44)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 10)
     (i32.const 8)
    )
    (unreachable)
   )
  )
 )
 (func $start (; 2 ;) (; has Stack IR ;) (type $v)
  ;;@ main.ts:13:4
  (call $main/testBreak)
 )
 (func $null (; 3 ;) (; has Stack IR ;) (type $v)
  (nop)
 )
)
