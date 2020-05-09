;;(module 
;;(func (export "main") (result i32) (local $var i32)
;;(set_local $var (i32.const 2)) ;; should be local.set for wat2wasm support
;;get_local $var ;; should be local.get for wat2wasm support
;;i32.const 6
;;i32.const 2
;;(set_local $var (i32.add))
;;get_local $var
;;))

(; (module 
(func (export "main") (param $x i32) (result i32)
  (if (result i32)
    (i32.lt_s
      (get_local $x)
      (i32.const 10)
    )
    (then
     (i32.const 1)
     (i32.const 1)
     (i32.add)
    )
  (else
    (i32.const 0)
  )
  )
)) ;)
(;
(module 
(func (export "main") (param $x i32) (result i32) (local $y i32)
  (if
    (i32.lt_s
      (get_local $x)
      (i32.const 10)
    )
    (then
     (set_local $y (i32.const 6))
    )
  
  )
  get_local $y
)) ;)

(module 
(func (export "main") (result i32) (local $x i32) 
(set_local $x (i32.const 5))
(if
 (i32.eq
   (i32.const 5)
   (i32.const 5)
 )
 (then
i32.const 7
i32.const 8
(set_local $x (i32.add))
 )
)
get_local $x
))
