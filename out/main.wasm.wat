(module
 (type $0 (func (param i32 i32 i32) (result i32)))
 (type $1 (func))
 (import "env" "memory" (memory $0 0))
 (export "memory" (memory $0))
 (export "sigmoidApproxPtr" (func $0))
 (export "sigmoidDerivApproxPtr" (func $1))
 (func $0 (; 0 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 f64)
  (set_local $var$3
   (get_local $var$0)
  )
  (loop $label$1
   (set_local $var$2
    (i32.sub
     (tee_local $var$4
      (get_local $var$2)
     )
     (i32.const 1)
    )
   )
   (if
    (i32.eqz
     (i32.le_u
      (get_local $var$4)
      (i32.const 0)
     )
    )
    (block
     (f64.store
      (get_local $var$0)
      (f64.div
       (f64.const 1)
       (f64.add
        (f64.const 1)
        (f64.mul
         (f64.add
          (f64.const 362880)
          (f64.mul
           (tee_local $var$5
            (f64.neg
             (f64.load
              (get_local $var$1)
             )
            )
           )
           (f64.add
            (f64.const 362880)
            (f64.mul
             (get_local $var$5)
             (f64.add
              (f64.const 181440)
              (f64.mul
               (get_local $var$5)
               (f64.add
                (f64.const 60480)
                (f64.mul
                 (get_local $var$5)
                 (f64.add
                  (f64.const 15120)
                  (f64.mul
                   (get_local $var$5)
                   (f64.add
                    (f64.const 3024)
                    (f64.mul
                     (get_local $var$5)
                     (f64.add
                      (f64.const 504)
                      (f64.mul
                       (get_local $var$5)
                       (f64.add
                        (f64.const 72)
                        (f64.mul
                         (get_local $var$5)
                         (f64.add
                          (f64.const 9)
                          (get_local $var$5)
                         )
                        )
                       )
                      )
                     )
                    )
                   )
                  )
                 )
                )
               )
              )
             )
            )
           )
          )
         )
         (f64.const 2.75573192e-06)
        )
       )
      )
     )
     (set_local $var$0
      (i32.add
       (get_local $var$0)
       (i32.const 8)
      )
     )
     (set_local $var$1
      (i32.add
       (get_local $var$1)
       (i32.const 8)
      )
     )
     (br $label$1)
    )
   )
  )
  (get_local $var$3)
 )
 (func $1 (; 1 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (param $var$2 i32) (result i32)
  (local $var$3 i32)
  (local $var$4 i32)
  (local $var$5 f64)
  (local $var$6 f64)
  (set_local $var$3
   (get_local $var$0)
  )
  (loop $label$1
   (set_local $var$2
    (i32.sub
     (tee_local $var$4
      (get_local $var$2)
     )
     (i32.const 1)
    )
   )
   (if
    (i32.eqz
     (i32.le_u
      (get_local $var$4)
      (i32.const 0)
     )
    )
    (block
     (set_local $var$5
      (f64.add
       (f64.const 1)
       (tee_local $var$6
        (f64.mul
         (f64.add
          (f64.const 362880)
          (f64.mul
           (tee_local $var$5
            (f64.neg
             (f64.load
              (get_local $var$1)
             )
            )
           )
           (f64.add
            (f64.const 362880)
            (f64.mul
             (get_local $var$5)
             (f64.add
              (f64.const 181440)
              (f64.mul
               (get_local $var$5)
               (f64.add
                (f64.const 60480)
                (f64.mul
                 (get_local $var$5)
                 (f64.add
                  (f64.const 15120)
                  (f64.mul
                   (get_local $var$5)
                   (f64.add
                    (f64.const 3024)
                    (f64.mul
                     (get_local $var$5)
                     (f64.add
                      (f64.const 504)
                      (f64.mul
                       (get_local $var$5)
                       (f64.add
                        (f64.const 72)
                        (f64.mul
                         (get_local $var$5)
                         (f64.add
                          (f64.const 9)
                          (get_local $var$5)
                         )
                        )
                       )
                      )
                     )
                    )
                   )
                  )
                 )
                )
               )
              )
             )
            )
           )
          )
         )
         (f64.const 2.75573192e-06)
        )
       )
      )
     )
     (f64.store
      (get_local $var$0)
      (f64.div
       (get_local $var$6)
       (f64.mul
        (get_local $var$5)
        (get_local $var$5)
       )
      )
     )
     (set_local $var$0
      (i32.add
       (get_local $var$0)
       (i32.const 8)
      )
     )
     (set_local $var$1
      (i32.add
       (get_local $var$1)
       (i32.const 8)
      )
     )
     (br $label$1)
    )
   )
  )
  (get_local $var$3)
 )
 (func $2 (; 2 ;) (type $1)
  (nop)
 )
 ;; custom section "sourceMappingURL", size 14
)
