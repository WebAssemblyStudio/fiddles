(module
 (type $iiiiv (func (param i32 i32 i32 i32)))
 (type $iiiv (func (param i32 i32 i32)))
 (type $iiii (func (param i32 i32 i32) (result i32)))
 (type $ii (func (param i32) (result i32)))
 (type $iiv (func (param i32 i32)))
 (type $iii (func (param i32 i32) (result i32)))
 (type $iv (func (param i32)))
 (type $v (func))
 (type $i (func (result i32)))
 (type $iiiiiv (func (param i32 i32 i32 i32 i32)))
 (import "env" "abort" (func $~lib/env/abort (param i32 i32 i32 i32)))
 (import "env" "log" (func $input/env.log (param i32)))
 (import "env" "get_http_request_method" (func $input/env.get_http_request_method (result i32)))
 (import "env" "set_http_response_status" (func $input/env.set_http_response_status (param i32)))
 (import "env" "put_http_response_header" (func $input/env.put_http_response_header (param i32 i32)))
 (import "env" "set_http_response_body" (func $input/env.set_http_response_body (param i32)))
 (global $~lib/allocator/tlsf/ROOT (mut i32) (i32.const 0))
 (memory $0 1)
 (data (i32.const 8) "\16\00\00\00~\00l\00i\00b\00/\00a\00l\00l\00o\00c\00a\00t\00o\00r\00/\00t\00l\00s\00f\00.\00t\00s")
 (data (i32.const 56) "\14\00\00\00H\00e\00l\00l\00o\00 \00A\00s\00s\00e\00m\00b\00l\00y\00S\00c\00r\00i\00p\00t")
 (data (i32.const 104) "\0c\00\00\00C\00o\00n\00t\00e\00n\00t\00-\00T\00y\00p\00e")
 (data (i32.const 136) "\t\00\00\00t\00e\00x\00t\00/\00h\00t\00m\00l")
 (data (i32.const 160) "\13\00\00\00H\00e\00l\00l\00o\00 \00H\00T\00T\00P\00 \00m\00e\00t\00h\00o\00d\00:\00 ")
 (data (i32.const 208) "\04\00\00\00n\00u\00l\00l")
 (data (i32.const 224) "\0e\00\00\00~\00l\00i\00b\00/\00s\00t\00r\00i\00n\00g\00.\00t\00s")
 (data (i32.const 264) "\17\00\00\00~\00l\00i\00b\00/\00i\00n\00t\00e\00r\00n\00a\00l\00/\00s\00t\00r\00i\00n\00g\00.\00t\00s")
 (export "memory" (memory $0))
 (export "ready" (func $input/ready))
 (export "handle" (func $input/handle))
 (export "memory.fill" (func $~lib/memory/memory.fill))
 (export "memory.copy" (func $~lib/memory/memory.copy))
 (export "memory.compare" (func $~lib/memory/memory.compare))
 (export "memory.allocate" (func $~lib/memory/memory.allocate))
 (export "memory.free" (func $~lib/memory/memory.free))
 (export "memory.reset" (func $~lib/memory/memory.reset))
 (func $~lib/internal/memory/memset (; 6 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i64)
  (local $4 i32)
  (if
   (i32.eqz
    (get_local $2)
   )
   (return)
  )
  (i32.store8
   (get_local $0)
   (get_local $1)
  )
  (i32.store8
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 1)
   )
   (get_local $1)
  )
  (if
   (i32.le_u
    (get_local $2)
    (i32.const 2)
   )
   (return)
  )
  (i32.store8
   (i32.add
    (get_local $0)
    (i32.const 1)
   )
   (get_local $1)
  )
  (i32.store8
   (i32.add
    (get_local $0)
    (i32.const 2)
   )
   (get_local $1)
  )
  (i32.store8
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 2)
   )
   (get_local $1)
  )
  (i32.store8
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 3)
   )
   (get_local $1)
  )
  (if
   (i32.le_u
    (get_local $2)
    (i32.const 6)
   )
   (return)
  )
  (i32.store8
   (i32.add
    (get_local $0)
    (i32.const 3)
   )
   (get_local $1)
  )
  (i32.store8
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 4)
   )
   (get_local $1)
  )
  (if
   (i32.le_u
    (get_local $2)
    (i32.const 8)
   )
   (return)
  )
  (i32.store
   (tee_local $0
    (i32.add
     (get_local $0)
     (tee_local $4
      (i32.and
       (i32.sub
        (i32.const 0)
        (get_local $0)
       )
       (i32.const 3)
      )
     )
    )
   )
   (tee_local $1
    (i32.mul
     (i32.and
      (get_local $1)
      (i32.const 255)
     )
     (i32.const 16843009)
    )
   )
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (tee_local $2
      (i32.and
       (i32.sub
        (get_local $2)
        (get_local $4)
       )
       (i32.const -4)
      )
     )
    )
    (i32.const 4)
   )
   (get_local $1)
  )
  (if
   (i32.le_u
    (get_local $2)
    (i32.const 8)
   )
   (return)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 4)
   )
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 12)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 8)
   )
   (get_local $1)
  )
  (if
   (i32.le_u
    (get_local $2)
    (i32.const 24)
   )
   (return)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 12)
   )
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 20)
   )
   (get_local $1)
  )
  (i32.store
   (i32.add
    (get_local $0)
    (i32.const 24)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 28)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 24)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 20)
   )
   (get_local $1)
  )
  (i32.store
   (i32.sub
    (i32.add
     (get_local $0)
     (get_local $2)
    )
    (i32.const 16)
   )
   (get_local $1)
  )
  (set_local $0
   (i32.add
    (get_local $0)
    (tee_local $4
     (i32.add
      (i32.and
       (get_local $0)
       (i32.const 4)
      )
      (i32.const 24)
     )
    )
   )
  )
  (set_local $2
   (i32.sub
    (get_local $2)
    (get_local $4)
   )
  )
  (set_local $3
   (i64.or
    (i64.extend_u/i32
     (get_local $1)
    )
    (i64.shl
     (i64.extend_u/i32
      (get_local $1)
     )
     (i64.const 32)
    )
   )
  )
  (loop $continue|0
   (if
    (i32.ge_u
     (get_local $2)
     (i32.const 32)
    )
    (block
     (i64.store
      (get_local $0)
      (get_local $3)
     )
     (i64.store
      (i32.add
       (get_local $0)
       (i32.const 8)
      )
      (get_local $3)
     )
     (i64.store
      (i32.add
       (get_local $0)
       (i32.const 16)
      )
      (get_local $3)
     )
     (i64.store
      (i32.add
       (get_local $0)
       (i32.const 24)
      )
      (get_local $3)
     )
     (set_local $2
      (i32.sub
       (get_local $2)
       (i32.const 32)
      )
     )
     (set_local $0
      (i32.add
       (get_local $0)
       (i32.const 32)
      )
     )
     (br $continue|0)
    )
   )
  )
 )
 (func $~lib/memory/memory.fill (; 7 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (call $~lib/internal/memory/memset
   (get_local $0)
   (get_local $1)
   (get_local $2)
  )
 )
 (func $~lib/internal/memory/memcpy (; 8 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (local $4 i32)
  (loop $continue|0
   (if
    (if (result i32)
     (get_local $2)
     (i32.and
      (get_local $1)
      (i32.const 3)
     )
     (get_local $2)
    )
    (block
     (set_local $0
      (i32.add
       (tee_local $3
        (get_local $0)
       )
       (i32.const 1)
      )
     )
     (i32.store8
      (get_local $3)
      (block (result i32)
       (set_local $1
        (i32.add
         (tee_local $3
          (get_local $1)
         )
         (i32.const 1)
        )
       )
       (i32.load8_u
        (get_local $3)
       )
      )
     )
     (set_local $2
      (i32.sub
       (get_local $2)
       (i32.const 1)
      )
     )
     (br $continue|0)
    )
   )
  )
  (if
   (i32.eqz
    (i32.and
     (get_local $0)
     (i32.const 3)
    )
   )
   (block
    (loop $continue|1
     (if
      (i32.ge_u
       (get_local $2)
       (i32.const 16)
      )
      (block
       (i32.store
        (get_local $0)
        (i32.load
         (get_local $1)
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 4)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 8)
        )
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 8)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 12)
        )
        (i32.load
         (i32.add
          (get_local $1)
          (i32.const 12)
         )
        )
       )
       (set_local $1
        (i32.add
         (get_local $1)
         (i32.const 16)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 16)
        )
       )
       (set_local $2
        (i32.sub
         (get_local $2)
         (i32.const 16)
        )
       )
       (br $continue|1)
      )
     )
    )
    (if
     (i32.and
      (get_local $2)
      (i32.const 8)
     )
     (block
      (i32.store
       (get_local $0)
       (i32.load
        (get_local $1)
       )
      )
      (i32.store
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
       (i32.load
        (i32.add
         (get_local $1)
         (i32.const 4)
        )
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 8)
       )
      )
      (set_local $1
       (i32.add
        (get_local $1)
        (i32.const 8)
       )
      )
     )
    )
    (if
     (i32.and
      (get_local $2)
      (i32.const 4)
     )
     (block
      (i32.store
       (get_local $0)
       (i32.load
        (get_local $1)
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 4)
       )
      )
      (set_local $1
       (i32.add
        (get_local $1)
        (i32.const 4)
       )
      )
     )
    )
    (if
     (i32.and
      (get_local $2)
      (i32.const 2)
     )
     (block
      (i32.store16
       (get_local $0)
       (i32.load16_u
        (get_local $1)
       )
      )
      (set_local $0
       (i32.add
        (get_local $0)
        (i32.const 2)
       )
      )
      (set_local $1
       (i32.add
        (get_local $1)
        (i32.const 2)
       )
      )
     )
    )
    (if
     (i32.and
      (get_local $2)
      (i32.const 1)
     )
     (block
      (set_local $3
       (get_local $0)
      )
      (i32.store8
       (get_local $3)
       (block (result i32)
        (set_local $3
         (get_local $1)
        )
        (i32.load8_u
         (get_local $3)
        )
       )
      )
     )
    )
    (return)
   )
  )
  (if
   (i32.ge_u
    (get_local $2)
    (i32.const 32)
   )
   (block $break|2
    (block $case2|2
     (block $case1|2
      (block $case0|2
       (block $tablify|0
        (br_table $case0|2 $case1|2 $case2|2 $tablify|0
         (i32.sub
          (i32.and
           (get_local $0)
           (i32.const 3)
          )
          (i32.const 1)
         )
        )
       )
       (br $break|2)
      )
      (set_local $4
       (i32.load
        (get_local $1)
       )
      )
      (set_local $0
       (i32.add
        (tee_local $3
         (get_local $0)
        )
        (i32.const 1)
       )
      )
      (i32.store8
       (get_local $3)
       (block (result i32)
        (set_local $1
         (i32.add
          (tee_local $3
           (get_local $1)
          )
          (i32.const 1)
         )
        )
        (i32.load8_u
         (get_local $3)
        )
       )
      )
      (set_local $0
       (i32.add
        (tee_local $3
         (get_local $0)
        )
        (i32.const 1)
       )
      )
      (i32.store8
       (get_local $3)
       (block (result i32)
        (set_local $1
         (i32.add
          (tee_local $3
           (get_local $1)
          )
          (i32.const 1)
         )
        )
        (i32.load8_u
         (get_local $3)
        )
       )
      )
      (set_local $0
       (i32.add
        (tee_local $3
         (get_local $0)
        )
        (i32.const 1)
       )
      )
      (i32.store8
       (get_local $3)
       (block (result i32)
        (set_local $1
         (i32.add
          (tee_local $3
           (get_local $1)
          )
          (i32.const 1)
         )
        )
        (i32.load8_u
         (get_local $3)
        )
       )
      )
      (set_local $2
       (i32.sub
        (get_local $2)
        (i32.const 3)
       )
      )
      (loop $continue|3
       (if
        (i32.ge_u
         (get_local $2)
         (i32.const 17)
        )
        (block
         (i32.store
          (get_local $0)
          (i32.or
           (i32.shr_u
            (get_local $4)
            (i32.const 24)
           )
           (i32.shl
            (tee_local $3
             (i32.load
              (i32.add
               (get_local $1)
               (i32.const 1)
              )
             )
            )
            (i32.const 8)
           )
          )
         )
         (i32.store
          (i32.add
           (get_local $0)
           (i32.const 4)
          )
          (i32.or
           (i32.shr_u
            (get_local $3)
            (i32.const 24)
           )
           (i32.shl
            (tee_local $4
             (i32.load
              (i32.add
               (get_local $1)
               (i32.const 5)
              )
             )
            )
            (i32.const 8)
           )
          )
         )
         (i32.store
          (i32.add
           (get_local $0)
           (i32.const 8)
          )
          (i32.or
           (i32.shr_u
            (get_local $4)
            (i32.const 24)
           )
           (i32.shl
            (tee_local $3
             (i32.load
              (i32.add
               (get_local $1)
               (i32.const 9)
              )
             )
            )
            (i32.const 8)
           )
          )
         )
         (i32.store
          (i32.add
           (get_local $0)
           (i32.const 12)
          )
          (i32.or
           (i32.shr_u
            (get_local $3)
            (i32.const 24)
           )
           (i32.shl
            (tee_local $4
             (i32.load
              (i32.add
               (get_local $1)
               (i32.const 13)
              )
             )
            )
            (i32.const 8)
           )
          )
         )
         (set_local $1
          (i32.add
           (get_local $1)
           (i32.const 16)
          )
         )
         (set_local $0
          (i32.add
           (get_local $0)
           (i32.const 16)
          )
         )
         (set_local $2
          (i32.sub
           (get_local $2)
           (i32.const 16)
          )
         )
         (br $continue|3)
        )
       )
      )
      (br $break|2)
     )
     (set_local $4
      (i32.load
       (get_local $1)
      )
     )
     (set_local $0
      (i32.add
       (tee_local $3
        (get_local $0)
       )
       (i32.const 1)
      )
     )
     (i32.store8
      (get_local $3)
      (block (result i32)
       (set_local $1
        (i32.add
         (tee_local $3
          (get_local $1)
         )
         (i32.const 1)
        )
       )
       (i32.load8_u
        (get_local $3)
       )
      )
     )
     (set_local $0
      (i32.add
       (tee_local $3
        (get_local $0)
       )
       (i32.const 1)
      )
     )
     (i32.store8
      (get_local $3)
      (block (result i32)
       (set_local $1
        (i32.add
         (tee_local $3
          (get_local $1)
         )
         (i32.const 1)
        )
       )
       (i32.load8_u
        (get_local $3)
       )
      )
     )
     (set_local $2
      (i32.sub
       (get_local $2)
       (i32.const 2)
      )
     )
     (loop $continue|4
      (if
       (i32.ge_u
        (get_local $2)
        (i32.const 18)
       )
       (block
        (i32.store
         (get_local $0)
         (i32.or
          (i32.shr_u
           (get_local $4)
           (i32.const 16)
          )
          (i32.shl
           (tee_local $3
            (i32.load
             (i32.add
              (get_local $1)
              (i32.const 2)
             )
            )
           )
           (i32.const 16)
          )
         )
        )
        (i32.store
         (i32.add
          (get_local $0)
          (i32.const 4)
         )
         (i32.or
          (i32.shr_u
           (get_local $3)
           (i32.const 16)
          )
          (i32.shl
           (tee_local $4
            (i32.load
             (i32.add
              (get_local $1)
              (i32.const 6)
             )
            )
           )
           (i32.const 16)
          )
         )
        )
        (i32.store
         (i32.add
          (get_local $0)
          (i32.const 8)
         )
         (i32.or
          (i32.shr_u
           (get_local $4)
           (i32.const 16)
          )
          (i32.shl
           (tee_local $3
            (i32.load
             (i32.add
              (get_local $1)
              (i32.const 10)
             )
            )
           )
           (i32.const 16)
          )
         )
        )
        (i32.store
         (i32.add
          (get_local $0)
          (i32.const 12)
         )
         (i32.or
          (i32.shr_u
           (get_local $3)
           (i32.const 16)
          )
          (i32.shl
           (tee_local $4
            (i32.load
             (i32.add
              (get_local $1)
              (i32.const 14)
             )
            )
           )
           (i32.const 16)
          )
         )
        )
        (set_local $1
         (i32.add
          (get_local $1)
          (i32.const 16)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 16)
         )
        )
        (set_local $2
         (i32.sub
          (get_local $2)
          (i32.const 16)
         )
        )
        (br $continue|4)
       )
      )
     )
     (br $break|2)
    )
    (set_local $4
     (i32.load
      (get_local $1)
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $2
     (i32.sub
      (get_local $2)
      (i32.const 1)
     )
    )
    (loop $continue|5
     (if
      (i32.ge_u
       (get_local $2)
       (i32.const 19)
      )
      (block
       (i32.store
        (get_local $0)
        (i32.or
         (i32.shr_u
          (get_local $4)
          (i32.const 8)
         )
         (i32.shl
          (tee_local $3
           (i32.load
            (i32.add
             (get_local $1)
             (i32.const 3)
            )
           )
          )
          (i32.const 24)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 4)
        )
        (i32.or
         (i32.shr_u
          (get_local $3)
          (i32.const 8)
         )
         (i32.shl
          (tee_local $4
           (i32.load
            (i32.add
             (get_local $1)
             (i32.const 7)
            )
           )
          )
          (i32.const 24)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 8)
        )
        (i32.or
         (i32.shr_u
          (get_local $4)
          (i32.const 8)
         )
         (i32.shl
          (tee_local $3
           (i32.load
            (i32.add
             (get_local $1)
             (i32.const 11)
            )
           )
          )
          (i32.const 24)
         )
        )
       )
       (i32.store
        (i32.add
         (get_local $0)
         (i32.const 12)
        )
        (i32.or
         (i32.shr_u
          (get_local $3)
          (i32.const 8)
         )
         (i32.shl
          (tee_local $4
           (i32.load
            (i32.add
             (get_local $1)
             (i32.const 15)
            )
           )
          )
          (i32.const 24)
         )
        )
       )
       (set_local $1
        (i32.add
         (get_local $1)
         (i32.const 16)
        )
       )
       (set_local $0
        (i32.add
         (get_local $0)
         (i32.const 16)
        )
       )
       (set_local $2
        (i32.sub
         (get_local $2)
         (i32.const 16)
        )
       )
       (br $continue|5)
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 16)
   )
   (block
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 8)
   )
   (block
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 4)
   )
   (block
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 2)
   )
   (block
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
    (set_local $0
     (i32.add
      (tee_local $3
       (get_local $0)
      )
      (i32.const 1)
     )
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $1
       (i32.add
        (tee_local $3
         (get_local $1)
        )
        (i32.const 1)
       )
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 1)
   )
   (block
    (set_local $3
     (get_local $0)
    )
    (i32.store8
     (get_local $3)
     (block (result i32)
      (set_local $3
       (get_local $1)
      )
      (i32.load8_u
       (get_local $3)
      )
     )
    )
   )
  )
 )
 (func $~lib/internal/memory/memmove (; 9 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (local $3 i32)
  (if
   (i32.eq
    (get_local $0)
    (get_local $1)
   )
   (return)
  )
  (if
   (if (result i32)
    (tee_local $3
     (i32.le_u
      (i32.add
       (get_local $1)
       (get_local $2)
      )
      (get_local $0)
     )
    )
    (get_local $3)
    (i32.le_u
     (i32.add
      (get_local $0)
      (get_local $2)
     )
     (get_local $1)
    )
   )
   (block
    (call $~lib/internal/memory/memcpy
     (get_local $0)
     (get_local $1)
     (get_local $2)
    )
    (return)
   )
  )
  (if
   (i32.lt_u
    (get_local $0)
    (get_local $1)
   )
   (block
    (if
     (i32.eq
      (i32.and
       (get_local $1)
       (i32.const 7)
      )
      (i32.and
       (get_local $0)
       (i32.const 7)
      )
     )
     (block
      (loop $continue|0
       (if
        (i32.and
         (get_local $0)
         (i32.const 7)
        )
        (block
         (if
          (i32.eqz
           (get_local $2)
          )
          (return)
         )
         (set_local $2
          (i32.sub
           (get_local $2)
           (i32.const 1)
          )
         )
         (set_local $0
          (i32.add
           (tee_local $3
            (get_local $0)
           )
           (i32.const 1)
          )
         )
         (i32.store8
          (get_local $3)
          (block (result i32)
           (set_local $1
            (i32.add
             (tee_local $3
              (get_local $1)
             )
             (i32.const 1)
            )
           )
           (i32.load8_u
            (get_local $3)
           )
          )
         )
         (br $continue|0)
        )
       )
      )
      (loop $continue|1
       (if
        (i32.ge_u
         (get_local $2)
         (i32.const 8)
        )
        (block
         (i64.store
          (get_local $0)
          (i64.load
           (get_local $1)
          )
         )
         (set_local $2
          (i32.sub
           (get_local $2)
           (i32.const 8)
          )
         )
         (set_local $0
          (i32.add
           (get_local $0)
           (i32.const 8)
          )
         )
         (set_local $1
          (i32.add
           (get_local $1)
           (i32.const 8)
          )
         )
         (br $continue|1)
        )
       )
      )
     )
    )
    (loop $continue|2
     (if
      (get_local $2)
      (block
       (set_local $0
        (i32.add
         (tee_local $3
          (get_local $0)
         )
         (i32.const 1)
        )
       )
       (i32.store8
        (get_local $3)
        (block (result i32)
         (set_local $1
          (i32.add
           (tee_local $3
            (get_local $1)
           )
           (i32.const 1)
          )
         )
         (i32.load8_u
          (get_local $3)
         )
        )
       )
       (set_local $2
        (i32.sub
         (get_local $2)
         (i32.const 1)
        )
       )
       (br $continue|2)
      )
     )
    )
   )
   (block
    (if
     (i32.eq
      (i32.and
       (get_local $1)
       (i32.const 7)
      )
      (i32.and
       (get_local $0)
       (i32.const 7)
      )
     )
     (block
      (loop $continue|3
       (if
        (i32.and
         (i32.add
          (get_local $0)
          (get_local $2)
         )
         (i32.const 7)
        )
        (block
         (if
          (i32.eqz
           (get_local $2)
          )
          (return)
         )
         (i32.store8
          (i32.add
           (get_local $0)
           (tee_local $2
            (i32.sub
             (get_local $2)
             (i32.const 1)
            )
           )
          )
          (i32.load8_u
           (i32.add
            (get_local $1)
            (get_local $2)
           )
          )
         )
         (br $continue|3)
        )
       )
      )
      (loop $continue|4
       (if
        (i32.ge_u
         (get_local $2)
         (i32.const 8)
        )
        (block
         (i64.store
          (i32.add
           (get_local $0)
           (tee_local $2
            (i32.sub
             (get_local $2)
             (i32.const 8)
            )
           )
          )
          (i64.load
           (i32.add
            (get_local $1)
            (get_local $2)
           )
          )
         )
         (br $continue|4)
        )
       )
      )
     )
    )
    (loop $continue|5
     (if
      (get_local $2)
      (block
       (i32.store8
        (i32.add
         (get_local $0)
         (tee_local $2
          (i32.sub
           (get_local $2)
           (i32.const 1)
          )
         )
        )
        (i32.load8_u
         (i32.add
          (get_local $1)
          (get_local $2)
         )
        )
       )
       (br $continue|5)
      )
     )
    )
   )
  )
 )
 (func $~lib/memory/memory.copy (; 10 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (call $~lib/internal/memory/memmove
   (get_local $0)
   (get_local $1)
   (get_local $2)
  )
 )
 (func $~lib/internal/memory/memcmp (; 11 ;) (; has Stack IR ;) (type $iiii) (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (if
   (i32.eq
    (get_local $0)
    (get_local $1)
   )
   (return
    (i32.const 0)
   )
  )
  (loop $continue|0
   (if
    (if (result i32)
     (tee_local $3
      (i32.ne
       (get_local $2)
       (i32.const 0)
      )
     )
     (i32.eq
      (i32.load8_u
       (get_local $0)
      )
      (i32.load8_u
       (get_local $1)
      )
     )
     (get_local $3)
    )
    (block
     (set_local $2
      (i32.sub
       (get_local $2)
       (i32.const 1)
      )
     )
     (set_local $0
      (i32.add
       (get_local $0)
       (i32.const 1)
      )
     )
     (set_local $1
      (i32.add
       (get_local $1)
       (i32.const 1)
      )
     )
     (br $continue|0)
    )
   )
  )
  (if (result i32)
   (get_local $2)
   (i32.sub
    (i32.load8_u
     (get_local $0)
    )
    (i32.load8_u
     (get_local $1)
    )
   )
   (i32.const 0)
  )
 )
 (func $~lib/memory/memory.compare (; 12 ;) (; has Stack IR ;) (type $iiii) (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (call $~lib/internal/memory/memcmp
   (get_local $0)
   (get_local $1)
   (get_local $2)
  )
 )
 (func $~lib/allocator/tlsf/Root#set:tailRef (; 13 ;) (; has Stack IR ;) (type $iiv) (param $0 i32) (param $1 i32)
  (i32.store
   (i32.const 2912)
   (get_local $1)
  )
 )
 (func $~lib/allocator/tlsf/Root#setSLMap (; 14 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (if
   (i32.ge_u
    (get_local $1)
    (i32.const 22)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 144)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (i32.store offset=4
   (i32.add
    (get_local $0)
    (i32.shl
     (get_local $1)
     (i32.const 2)
    )
   )
   (get_local $2)
  )
 )
 (func $~lib/allocator/tlsf/Root#setHead (; 15 ;) (; has Stack IR ;) (type $iiiiv) (param $0 i32) (param $1 i32) (param $2 i32) (param $3 i32)
  (if
   (i32.ge_u
    (get_local $1)
    (i32.const 22)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 167)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.ge_u
    (get_local $2)
    (i32.const 32)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 168)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (i32.store offset=96
   (i32.add
    (get_local $0)
    (i32.shl
     (i32.add
      (i32.shl
       (get_local $1)
       (i32.const 5)
      )
      (get_local $2)
     )
     (i32.const 2)
    )
   )
   (get_local $3)
  )
 )
 (func $~lib/allocator/tlsf/Root#get:tailRef (; 16 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (i32.load
   (i32.const 2912)
  )
 )
 (func $~lib/allocator/tlsf/Block#get:right (; 17 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (local $1 i32)
  (if
   (i32.eqz
    (i32.and
     (i32.load
      (get_local $0)
     )
     (i32.const -4)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 89)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if (result i32)
   (tee_local $1
    (i32.add
     (i32.add
      (get_local $0)
      (i32.const 8)
     )
     (i32.and
      (i32.load
       (get_local $0)
      )
      (i32.const -4)
     )
    )
   )
   (get_local $1)
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 90)
     (i32.const 11)
    )
    (unreachable)
   )
  )
 )
 (func $~lib/allocator/tlsf/fls<usize> (; 18 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (if
   (i32.eqz
    (get_local $0)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 428)
     (i32.const 2)
    )
    (unreachable)
   )
  )
  (i32.sub
   (i32.const 31)
   (i32.clz
    (get_local $0)
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#getHead (; 19 ;) (; has Stack IR ;) (type $iiii) (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (if
   (i32.ge_u
    (get_local $1)
    (i32.const 22)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 158)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.ge_u
    (get_local $2)
    (i32.const 32)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 159)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (i32.load offset=96
   (i32.add
    (get_local $0)
    (i32.shl
     (i32.add
      (i32.shl
       (get_local $1)
       (i32.const 5)
      )
      (get_local $2)
     )
     (i32.const 2)
    )
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#getSLMap (; 20 ;) (; has Stack IR ;) (type $iii) (param $0 i32) (param $1 i32) (result i32)
  (if
   (i32.ge_u
    (get_local $1)
    (i32.const 22)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 138)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (i32.load offset=4
   (i32.add
    (get_local $0)
    (i32.shl
     (get_local $1)
     (i32.const 2)
    )
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#remove (; 21 ;) (; has Stack IR ;) (type $iiv) (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (if
   (i32.eqz
    (i32.and
     (tee_local $3
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 1)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 258)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $4
      (i32.ge_u
       (tee_local $2
        (i32.and
         (get_local $3)
         (i32.const -4)
        )
       )
       (i32.const 16)
      )
     )
     (i32.lt_u
      (get_local $2)
      (i32.const 1073741824)
     )
     (get_local $4)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 260)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (set_local $3
   (if (result i32)
    (i32.lt_u
     (get_local $2)
     (i32.const 256)
    )
    (block (result i32)
     (set_local $4
      (i32.div_u
       (get_local $2)
       (i32.const 8)
      )
     )
     (i32.const 0)
    )
    (block (result i32)
     (set_local $4
      (i32.xor
       (i32.shr_u
        (get_local $2)
        (i32.sub
         (tee_local $3
          (call $~lib/allocator/tlsf/fls<usize>
           (get_local $2)
          )
         )
         (i32.const 5)
        )
       )
       (i32.const 32)
      )
     )
     (i32.sub
      (get_local $3)
      (i32.const 7)
     )
    )
   )
  )
  (set_local $2
   (i32.load offset=8
    (get_local $1)
   )
  )
  (if
   (tee_local $5
    (i32.load offset=4
     (get_local $1)
    )
   )
   (i32.store offset=8
    (get_local $5)
    (get_local $2)
   )
  )
  (if
   (get_local $2)
   (i32.store offset=4
    (get_local $2)
    (get_local $5)
   )
  )
  (if
   (i32.eq
    (get_local $1)
    (call $~lib/allocator/tlsf/Root#getHead
     (get_local $0)
     (get_local $3)
     (get_local $4)
    )
   )
   (block
    (call $~lib/allocator/tlsf/Root#setHead
     (get_local $0)
     (get_local $3)
     (get_local $4)
     (get_local $2)
    )
    (if
     (i32.eqz
      (get_local $2)
     )
     (block
      (call $~lib/allocator/tlsf/Root#setSLMap
       (get_local $0)
       (get_local $3)
       (tee_local $4
        (i32.and
         (call $~lib/allocator/tlsf/Root#getSLMap
          (get_local $0)
          (get_local $3)
         )
         (i32.xor
          (i32.shl
           (i32.const 1)
           (get_local $4)
          )
          (i32.const -1)
         )
        )
       )
      )
      (if
       (i32.eqz
        (get_local $4)
       )
       (i32.store
        (get_local $0)
        (i32.and
         (i32.load
          (get_local $0)
         )
         (i32.xor
          (i32.shl
           (i32.const 1)
           (get_local $3)
          )
          (i32.const -1)
         )
        )
       )
      )
     )
    )
   )
  )
 )
 (func $~lib/allocator/tlsf/Block#get:left (; 22 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (local $1 i32)
  (if
   (i32.eqz
    (i32.and
     (i32.load
      (get_local $0)
     )
     (i32.const 2)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 81)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if (result i32)
   (tee_local $1
    (i32.load
     (i32.sub
      (get_local $0)
      (i32.const 4)
     )
    )
   )
   (get_local $1)
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 82)
     (i32.const 11)
    )
    (unreachable)
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#setJump (; 23 ;) (; has Stack IR ;) (type $iiiv) (param $0 i32) (param $1 i32) (param $2 i32)
  (if
   (i32.eqz
    (i32.and
     (i32.load
      (get_local $1)
     )
     (i32.const 1)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 334)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.ne
    (call $~lib/allocator/tlsf/Block#get:right
     (get_local $1)
    )
    (get_local $2)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 335)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (i32.and
     (i32.load
      (get_local $2)
     )
     (i32.const 2)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 336)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (i32.store
   (i32.sub
    (get_local $2)
    (i32.const 4)
   )
   (get_local $1)
  )
 )
 (func $~lib/allocator/tlsf/Root#insert (; 24 ;) (; has Stack IR ;) (type $iiv) (param $0 i32) (param $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (local $6 i32)
  (if
   (i32.eqz
    (get_local $1)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 189)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (i32.and
     (tee_local $4
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 1)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 191)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $2
      (i32.ge_u
       (tee_local $3
        (i32.and
         (i32.load
          (get_local $1)
         )
         (i32.const -4)
        )
       )
       (i32.const 16)
      )
     )
     (i32.lt_u
      (get_local $3)
      (i32.const 1073741824)
     )
     (get_local $2)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 193)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.and
    (tee_local $6
     (i32.load
      (tee_local $3
       (if (result i32)
        (tee_local $2
         (call $~lib/allocator/tlsf/Block#get:right
          (get_local $1)
         )
        )
        (get_local $2)
        (block
         (call $~lib/env/abort
          (i32.const 0)
          (i32.const 8)
          (i32.const 197)
          (i32.const 23)
         )
         (unreachable)
        )
       )
      )
     )
    )
    (i32.const 1)
   )
   (block
    (call $~lib/allocator/tlsf/Root#remove
     (get_local $0)
     (get_local $3)
    )
    (i32.store
     (get_local $1)
     (tee_local $4
      (i32.add
       (get_local $4)
       (i32.add
        (i32.and
         (get_local $6)
         (i32.const -4)
        )
        (i32.const 8)
       )
      )
     )
    )
    (set_local $6
     (i32.load
      (tee_local $3
       (call $~lib/allocator/tlsf/Block#get:right
        (get_local $1)
       )
      )
     )
    )
   )
  )
  (if
   (i32.and
    (get_local $4)
    (i32.const 2)
   )
   (block
    (if
     (i32.eqz
      (i32.and
       (tee_local $5
        (i32.load
         (if (result i32)
          (tee_local $2
           (call $~lib/allocator/tlsf/Block#get:left
            (get_local $1)
           )
          )
          (get_local $2)
          (tee_local $2
           (block
            (call $~lib/env/abort
             (i32.const 0)
             (i32.const 8)
             (i32.const 211)
             (i32.const 24)
            )
            (unreachable)
           )
          )
         )
        )
       )
       (i32.const 1)
      )
     )
     (block
      (call $~lib/env/abort
       (i32.const 0)
       (i32.const 8)
       (i32.const 213)
       (i32.const 6)
      )
      (unreachable)
     )
    )
    (call $~lib/allocator/tlsf/Root#remove
     (get_local $0)
     (get_local $2)
    )
    (i32.store
     (get_local $2)
     (tee_local $5
      (i32.add
       (get_local $5)
       (i32.add
        (i32.and
         (get_local $4)
         (i32.const -4)
        )
        (i32.const 8)
       )
      )
     )
    )
    (set_local $1
     (get_local $2)
    )
    (set_local $4
     (get_local $5)
    )
   )
  )
  (i32.store
   (get_local $3)
   (i32.or
    (get_local $6)
    (i32.const 2)
   )
  )
  (call $~lib/allocator/tlsf/Root#setJump
   (get_local $0)
   (get_local $1)
   (get_local $3)
  )
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $5
      (i32.ge_u
       (tee_local $3
        (i32.and
         (get_local $4)
         (i32.const -4)
        )
       )
       (i32.const 16)
      )
     )
     (i32.lt_u
      (get_local $3)
      (i32.const 1073741824)
     )
     (get_local $5)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 226)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (set_local $5
   (call $~lib/allocator/tlsf/Root#getHead
    (get_local $0)
    (tee_local $2
     (if (result i32)
      (i32.lt_u
       (get_local $3)
       (i32.const 256)
      )
      (block (result i32)
       (set_local $4
        (i32.div_u
         (get_local $3)
         (i32.const 8)
        )
       )
       (i32.const 0)
      )
      (block (result i32)
       (set_local $4
        (i32.xor
         (i32.shr_u
          (get_local $3)
          (i32.sub
           (tee_local $2
            (call $~lib/allocator/tlsf/fls<usize>
             (get_local $3)
            )
           )
           (i32.const 5)
          )
         )
         (i32.const 32)
        )
       )
       (i32.sub
        (get_local $2)
        (i32.const 7)
       )
      )
     )
    )
    (get_local $4)
   )
  )
  (i32.store offset=4
   (get_local $1)
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (get_local $5)
  )
  (if
   (get_local $5)
   (i32.store offset=4
    (get_local $5)
    (get_local $1)
   )
  )
  (call $~lib/allocator/tlsf/Root#setHead
   (get_local $0)
   (get_local $2)
   (get_local $4)
   (get_local $1)
  )
  (i32.store
   (get_local $0)
   (i32.or
    (i32.load
     (get_local $0)
    )
    (i32.shl
     (i32.const 1)
     (get_local $2)
    )
   )
  )
  (call $~lib/allocator/tlsf/Root#setSLMap
   (get_local $0)
   (get_local $2)
   (i32.or
    (call $~lib/allocator/tlsf/Root#getSLMap
     (get_local $0)
     (get_local $2)
    )
    (i32.shl
     (i32.const 1)
     (get_local $4)
    )
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#addMemory (; 25 ;) (; has Stack IR ;) (type $iiii) (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (if
   (i32.gt_u
    (get_local $1)
    (get_local $2)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 377)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.and
    (get_local $1)
    (i32.const 7)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 378)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 7)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 379)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (tee_local $3
    (call $~lib/allocator/tlsf/Root#get:tailRef
     (get_local $0)
    )
   )
   (block
    (if
     (i32.lt_u
      (get_local $1)
      (i32.add
       (get_local $3)
       (i32.const 4)
      )
     )
     (block
      (call $~lib/env/abort
       (i32.const 0)
       (i32.const 8)
       (i32.const 384)
       (i32.const 6)
      )
      (unreachable)
     )
    )
    (if
     (i32.eq
      (i32.sub
       (get_local $1)
       (i32.const 8)
      )
      (get_local $3)
     )
     (block
      (set_local $1
       (i32.sub
        (get_local $1)
        (i32.const 8)
       )
      )
      (set_local $4
       (i32.load
        (get_local $3)
       )
      )
     )
    )
   )
   (if
    (i32.lt_u
     (get_local $1)
     (i32.add
      (get_local $0)
      (i32.const 2916)
     )
    )
    (block
     (call $~lib/env/abort
      (i32.const 0)
      (i32.const 8)
      (i32.const 393)
      (i32.const 6)
     )
     (unreachable)
    )
   )
  )
  (if
   (i32.lt_u
    (tee_local $2
     (i32.sub
      (get_local $2)
      (get_local $1)
     )
    )
    (i32.const 32)
   )
   (return
    (i32.const 0)
   )
  )
  (i32.store
   (get_local $1)
   (i32.or
    (i32.or
     (i32.sub
      (get_local $2)
      (i32.const 16)
     )
     (i32.const 1)
    )
    (i32.and
     (get_local $4)
     (i32.const 2)
    )
   )
  )
  (i32.store offset=4
   (get_local $1)
   (i32.const 0)
  )
  (i32.store offset=8
   (get_local $1)
   (i32.const 0)
  )
  (i32.store
   (tee_local $2
    (i32.sub
     (i32.add
      (get_local $1)
      (get_local $2)
     )
     (i32.const 8)
    )
   )
   (i32.const 2)
  )
  (call $~lib/allocator/tlsf/Root#set:tailRef
   (get_local $0)
   (get_local $2)
  )
  (call $~lib/allocator/tlsf/Root#insert
   (get_local $0)
   (get_local $1)
  )
  (i32.const 1)
 )
 (func $~lib/allocator/tlsf/ffs<usize> (; 26 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (if
   (i32.eqz
    (get_local $0)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 422)
     (i32.const 2)
    )
    (unreachable)
   )
  )
  (i32.ctz
   (get_local $0)
  )
 )
 (func $~lib/allocator/tlsf/Root#search (; 27 ;) (; has Stack IR ;) (type $iii) (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $2
      (i32.ge_u
       (get_local $1)
       (i32.const 16)
      )
     )
     (i32.lt_u
      (get_local $1)
      (i32.const 1073741824)
     )
     (get_local $2)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 296)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (set_local $1
   (if (result i32)
    (i32.lt_u
     (get_local $1)
     (i32.const 256)
    )
    (block (result i32)
     (set_local $2
      (i32.const 0)
     )
     (i32.div_u
      (get_local $1)
      (i32.const 8)
     )
    )
    (block (result i32)
     (set_local $1
      (i32.xor
       (i32.shr_u
        (get_local $1)
        (i32.sub
         (tee_local $2
          (call $~lib/allocator/tlsf/fls<usize>
           (get_local $1)
          )
         )
         (i32.const 5)
        )
       )
       (i32.const 32)
      )
     )
     (set_local $2
      (i32.sub
       (get_local $2)
       (i32.const 7)
      )
     )
     (if (result i32)
      (i32.lt_u
       (get_local $1)
       (i32.const 31)
      )
      (i32.add
       (get_local $1)
       (i32.const 1)
      )
      (block (result i32)
       (set_local $2
        (i32.add
         (get_local $2)
         (i32.const 1)
        )
       )
       (i32.const 0)
      )
     )
    )
   )
  )
  (tee_local $0
   (if (result i32)
    (tee_local $1
     (i32.and
      (call $~lib/allocator/tlsf/Root#getSLMap
       (get_local $0)
       (get_local $2)
      )
      (i32.shl
       (i32.const -1)
       (get_local $1)
      )
     )
    )
    (call $~lib/allocator/tlsf/Root#getHead
     (get_local $0)
     (get_local $2)
     (call $~lib/allocator/tlsf/ffs<usize>
      (get_local $1)
     )
    )
    (if (result i32)
     (tee_local $2
      (i32.and
       (i32.load
        (get_local $0)
       )
       (i32.shl
        (i32.const -1)
        (i32.add
         (get_local $2)
         (i32.const 1)
        )
       )
      )
     )
     (block (result i32)
      (if
       (i32.eqz
        (tee_local $1
         (call $~lib/allocator/tlsf/Root#getSLMap
          (get_local $0)
          (tee_local $2
           (call $~lib/allocator/tlsf/ffs<usize>
            (get_local $2)
           )
          )
         )
        )
       )
       (tee_local $1
        (block
         (call $~lib/env/abort
          (i32.const 0)
          (i32.const 8)
          (i32.const 323)
          (i32.const 16)
         )
         (unreachable)
        )
       )
      )
      (call $~lib/allocator/tlsf/Root#getHead
       (get_local $0)
       (get_local $2)
       (call $~lib/allocator/tlsf/ffs<usize>
        (get_local $1)
       )
      )
     )
     (i32.const 0)
    )
   )
  )
 )
 (func $~lib/allocator/tlsf/Root#use (; 28 ;) (; has Stack IR ;) (type $iiii) (param $0 i32) (param $1 i32) (param $2 i32) (result i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (if
   (i32.eqz
    (i32.and
     (tee_local $4
      (i32.load
       (get_local $1)
      )
     )
     (i32.const 1)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 348)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $3
      (i32.ge_u
       (get_local $2)
       (i32.const 16)
      )
     )
     (i32.lt_u
      (get_local $2)
      (i32.const 1073741824)
     )
     (get_local $3)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 349)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.and
    (get_local $2)
    (i32.const 7)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 350)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (call $~lib/allocator/tlsf/Root#remove
   (get_local $0)
   (get_local $1)
  )
  (if
   (i32.ge_u
    (tee_local $5
     (i32.sub
      (i32.and
       (get_local $4)
       (i32.const -4)
      )
      (get_local $2)
     )
    )
    (i32.const 24)
   )
   (block
    (i32.store
     (get_local $1)
     (i32.or
      (get_local $2)
      (i32.and
       (get_local $4)
       (i32.const 2)
      )
     )
    )
    (i32.store
     (tee_local $3
      (i32.add
       (i32.add
        (get_local $1)
        (i32.const 8)
       )
       (get_local $2)
      )
     )
     (i32.or
      (i32.sub
       (get_local $5)
       (i32.const 8)
      )
      (i32.const 1)
     )
    )
    (call $~lib/allocator/tlsf/Root#insert
     (get_local $0)
     (get_local $3)
    )
   )
   (block
    (i32.store
     (get_local $1)
     (i32.and
      (get_local $4)
      (i32.const -2)
     )
    )
    (i32.store
     (if (result i32)
      (tee_local $3
       (call $~lib/allocator/tlsf/Block#get:right
        (get_local $1)
       )
      )
      (get_local $3)
      (tee_local $3
       (block
        (call $~lib/env/abort
         (i32.const 0)
         (i32.const 8)
         (i32.const 368)
         (i32.const 25)
        )
        (unreachable)
       )
      )
     )
     (i32.and
      (i32.load
       (get_local $3)
      )
      (i32.const -3)
     )
    )
   )
  )
  (i32.add
   (get_local $1)
   (i32.const 8)
  )
 )
 (func $~lib/allocator/tlsf/__memory_allocate (; 29 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (local $5 i32)
  (if
   (i32.eqz
    (tee_local $2
     (get_global $~lib/allocator/tlsf/ROOT)
    )
   )
   (block
    (if
     (if (result i32)
      (tee_local $3
       (i32.gt_s
        (tee_local $1
         (i32.shr_u
          (i32.and
           (i32.add
            (tee_local $5
             (i32.const 320)
            )
            (i32.const 68451)
           )
           (i32.const -65536)
          )
          (i32.const 16)
         )
        )
        (tee_local $4
         (current_memory)
        )
       )
      )
      (i32.lt_s
       (grow_memory
        (i32.sub
         (get_local $1)
         (get_local $4)
        )
       )
       (i32.const 0)
      )
      (get_local $3)
     )
     (unreachable)
    )
    (set_global $~lib/allocator/tlsf/ROOT
     (tee_local $2
      (get_local $5)
     )
    )
    (call $~lib/allocator/tlsf/Root#set:tailRef
     (get_local $2)
     (i32.const 0)
    )
    (i32.store
     (get_local $2)
     (i32.const 0)
    )
    (block $break|0
     (set_local $3
      (i32.const 0)
     )
     (loop $repeat|0
      (br_if $break|0
       (i32.ge_u
        (get_local $3)
        (i32.const 22)
       )
      )
      (call $~lib/allocator/tlsf/Root#setSLMap
       (get_local $2)
       (get_local $3)
       (i32.const 0)
      )
      (block $break|1
       (set_local $1
        (i32.const 0)
       )
       (loop $repeat|1
        (br_if $break|1
         (i32.ge_u
          (get_local $1)
          (i32.const 32)
         )
        )
        (call $~lib/allocator/tlsf/Root#setHead
         (get_local $2)
         (get_local $3)
         (get_local $1)
         (i32.const 0)
        )
        (set_local $1
         (i32.add
          (get_local $1)
          (i32.const 1)
         )
        )
        (br $repeat|1)
       )
      )
      (set_local $3
       (i32.add
        (get_local $3)
        (i32.const 1)
       )
      )
      (br $repeat|0)
     )
    )
    (drop
     (call $~lib/allocator/tlsf/Root#addMemory
      (get_local $2)
      (i32.and
       (i32.add
        (get_local $5)
        (i32.const 2923)
       )
       (i32.const -8)
      )
      (i32.shl
       (current_memory)
       (i32.const 16)
      )
     )
    )
   )
  )
  (if
   (i32.gt_u
    (get_local $0)
    (i32.const 1073741824)
   )
   (unreachable)
  )
  (if
   (i32.eqz
    (tee_local $1
     (call $~lib/allocator/tlsf/Root#search
      (get_local $2)
      (tee_local $0
       (select
        (tee_local $1
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const 7)
          )
          (i32.const -8)
         )
        )
        (tee_local $4
         (i32.const 16)
        )
        (i32.gt_u
         (get_local $1)
         (get_local $4)
        )
       )
      )
     )
    )
   )
   (block
    (if
     (i32.lt_s
      (grow_memory
       (select
        (tee_local $5
         (tee_local $1
          (current_memory)
         )
        )
        (tee_local $3
         (tee_local $4
          (i32.shr_u
           (i32.and
            (i32.add
             (get_local $0)
             (i32.const 65535)
            )
            (i32.const -65536)
           )
           (i32.const 16)
          )
         )
        )
        (i32.gt_s
         (get_local $5)
         (get_local $3)
        )
       )
      )
      (i32.const 0)
     )
     (if
      (i32.lt_s
       (grow_memory
        (get_local $4)
       )
       (i32.const 0)
      )
      (unreachable)
     )
    )
    (drop
     (call $~lib/allocator/tlsf/Root#addMemory
      (get_local $2)
      (i32.shl
       (get_local $1)
       (i32.const 16)
      )
      (i32.shl
       (current_memory)
       (i32.const 16)
      )
     )
    )
    (if
     (i32.eqz
      (tee_local $1
       (call $~lib/allocator/tlsf/Root#search
        (get_local $2)
        (get_local $0)
       )
      )
     )
     (tee_local $1
      (block
       (call $~lib/env/abort
        (i32.const 0)
        (i32.const 8)
        (i32.const 480)
        (i32.const 12)
       )
       (unreachable)
      )
     )
    )
   )
  )
  (if
   (i32.lt_u
    (i32.and
     (i32.load
      (get_local $1)
     )
     (i32.const -4)
    )
    (get_local $0)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 8)
     (i32.const 483)
     (i32.const 2)
    )
    (unreachable)
   )
  )
  (call $~lib/allocator/tlsf/Root#use
   (get_local $2)
   (get_local $1)
   (get_local $0)
  )
 )
 (func $~lib/memory/memory.allocate (; 30 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (call $~lib/allocator/tlsf/__memory_allocate
   (get_local $0)
  )
 )
 (func $~lib/allocator/tlsf/__memory_free (; 31 ;) (; has Stack IR ;) (type $iv) (param $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (if
   (get_local $0)
   (if
    (tee_local $1
     (get_global $~lib/allocator/tlsf/ROOT)
    )
    (block
     (if
      (i32.and
       (tee_local $3
        (i32.load
         (tee_local $2
          (i32.sub
           (get_local $0)
           (i32.const 8)
          )
         )
        )
       )
       (i32.const 1)
      )
      (block
       (call $~lib/env/abort
        (i32.const 0)
        (i32.const 8)
        (i32.const 494)
        (i32.const 6)
       )
       (unreachable)
      )
     )
     (i32.store
      (get_local $2)
      (i32.or
       (get_local $3)
       (i32.const 1)
      )
     )
     (call $~lib/allocator/tlsf/Root#insert
      (get_local $1)
      (i32.sub
       (get_local $0)
       (i32.const 8)
      )
     )
    )
   )
  )
 )
 (func $~lib/memory/memory.free (; 32 ;) (; has Stack IR ;) (type $iv) (param $0 i32)
  (call $~lib/allocator/tlsf/__memory_free
   (get_local $0)
  )
 )
 (func $~lib/allocator/tlsf/__memory_reset (; 33 ;) (; has Stack IR ;) (type $v)
  (unreachable)
 )
 (func $~lib/memory/memory.reset (; 34 ;) (; has Stack IR ;) (type $v)
  (call $~lib/allocator/tlsf/__memory_reset)
 )
 (func $input/ready (; 35 ;) (; has Stack IR ;) (type $v)
  (call $input/env.log
   (i32.const 56)
  )
 )
 (func $~lib/internal/string/allocateUnsafe (; 36 ;) (; has Stack IR ;) (type $ii) (param $0 i32) (result i32)
  (local $1 i32)
  (if
   (i32.eqz
    (if (result i32)
     (tee_local $1
      (i32.gt_s
       (get_local $0)
       (i32.const 0)
      )
     )
     (i32.le_s
      (get_local $0)
      (i32.const 536870910)
     )
     (get_local $1)
    )
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 264)
     (i32.const 14)
     (i32.const 2)
    )
    (unreachable)
   )
  )
  (i32.store
   (tee_local $1
    (call $~lib/allocator/tlsf/__memory_allocate
     (i32.add
      (i32.shl
       (get_local $0)
       (i32.const 1)
      )
      (i32.const 4)
     )
    )
   )
   (get_local $0)
  )
  (get_local $1)
 )
 (func $~lib/internal/string/copyUnsafe (; 37 ;) (; has Stack IR ;) (type $iiiiiv) (param $0 i32) (param $1 i32) (param $2 i32) (param $3 i32) (param $4 i32)
  (call $~lib/internal/memory/memmove
   (i32.add
    (i32.add
     (get_local $0)
     (i32.shl
      (get_local $1)
      (i32.const 1)
     )
    )
    (i32.const 4)
   )
   (i32.add
    (i32.add
     (get_local $2)
     (i32.shl
      (get_local $3)
      (i32.const 1)
     )
    )
    (i32.const 4)
   )
   (i32.shl
    (get_local $4)
    (i32.const 1)
   )
  )
 )
 (func $~lib/string/String#concat (; 38 ;) (; has Stack IR ;) (type $iii) (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (if
   (i32.eqz
    (get_local $0)
   )
   (block
    (call $~lib/env/abort
     (i32.const 0)
     (i32.const 224)
     (i32.const 108)
     (i32.const 4)
    )
    (unreachable)
   )
  )
  (if
   (i32.eqz
    (get_local $1)
   )
   (set_local $1
    (i32.const 208)
   )
  )
  (if
   (i32.eqz
    (tee_local $2
     (i32.add
      (tee_local $3
       (i32.load
        (get_local $0)
       )
      )
      (tee_local $4
       (i32.load
        (get_local $1)
       )
      )
     )
    )
   )
   (return
    (i32.const 256)
   )
  )
  (call $~lib/internal/string/copyUnsafe
   (tee_local $2
    (call $~lib/internal/string/allocateUnsafe
     (get_local $2)
    )
   )
   (i32.const 0)
   (get_local $0)
   (i32.const 0)
   (get_local $3)
  )
  (call $~lib/internal/string/copyUnsafe
   (get_local $2)
   (get_local $3)
   (get_local $1)
   (i32.const 0)
   (get_local $4)
  )
  (get_local $2)
 )
 (func $~lib/string/String.__concat (; 39 ;) (; has Stack IR ;) (type $iii) (param $0 i32) (param $1 i32) (result i32)
  (if
   (i32.eqz
    (get_local $0)
   )
   (set_local $0
    (i32.const 208)
   )
  )
  (call $~lib/string/String#concat
   (get_local $0)
   (get_local $1)
  )
 )
 (func $input/handle (; 40 ;) (; has Stack IR ;) (type $v)
  (local $0 i32)
  (set_local $0
   (call $input/env.get_http_request_method)
  )
  (call $input/env.set_http_response_status
   (i32.const 200)
  )
  (call $input/env.put_http_response_header
   (i32.const 104)
   (i32.const 136)
  )
  (call $input/env.set_http_response_body
   (call $~lib/string/String.__concat
    (i32.const 160)
    (get_local $0)
   )
  )
 )
)
