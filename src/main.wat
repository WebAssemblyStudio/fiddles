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
)) 

 ;)
(;
(module 
(func (export "main") (param $x i32) (result i32)
(block
(loop
(br_if 1 (i32.eqz (i32.and (i32.lt_s(get_local $x)(i32.const 5))
(i32.gt_s(get_local $x)(i32.const 2)))))
(set_local $x (i32.add (i32.const 1)(get_local $x)))
(br 0)
)
)
get_local $x
)) ;)

(module 
(func (export "main") (param $x i32) (result i32) (local $times i32) 
(set_local $times (i32.const 0))
(block
(loop
(br_if 1 (i32.eqz (i32.and (i32.lt_s (get_local $x)(i32.const 5)) (i32.gt_s (get_local $x)(i32.const 2)))))

i32.const 1
get_local $times
(set_local $times (i32.add))
i32.const 1
get_local $x
(set_local $x (i32.add))
(br 0)
)
)
get_local $times
))