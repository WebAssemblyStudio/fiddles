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
(;
(module 
(func (export "main") (result i32) (local $x i32) (local $b i32) 
(set_local $x (i32.const 0))
(set_local $b (i32.const 0))
(block
(loop
(br_if 1 (i32.eq (get_local $b ) (i32.const 10)))
get_local $x
i32.const 1
(set_local $x (i32.add))
get_local $b
i32.const 2
(set_local $b (i32.add))
(br 0)
)
)
get_local $x
)) ;)



;; (i32.trunc_s/f64 (f64.const 5.67)) ;; f64 to i32
;; (f64.convert_s/i32 (f64.const 5)) ;; i32 to f64
(;
(module 
(func (export "main") (param $in f64) (result f64) (local $ceil f64) (local $nearest f64) (local $floor f64) 
(set_local $nearest (f64.nearest (get_local $in)))
(set_local $ceil (f64.ceil (get_local $in)))
(set_local $floor (f64.floor (get_local $in)))
get_local $floor
)) ;)

(module 
(func (export "main") (param $in f64) (result f64) (local $num i32) (local $dec f64) 
(set_local $num (i32.trunc_s/f64 (f64.nearest (get_local $in) )))
(set_local $dec (f64.convert_s/i32 (get_local $num) ))
get_local $dec
f64.const 0.6
(set_local $dec (f64.add))
(set_local $dec (f64.nearest (get_local $dec )))
get_local $dec
))


(;
(module 
(func (export "main") (param $in i32) (result i32) (local $out i32) 
(set_local $out (get_local $in))
(if
 (i32.eqz
  (i32.rem_s
   (get_local $in)
   (i32.const 3)
 ))
 (then
(set_local $out (i32.const 3))
 )
)
(if
(i32.and
 (i32.ne
   (get_local $out)
   (i32.const 3)
)
 (i32.eqz
  (i32.rem_s
   (get_local $in)
   (i32.const 5)
 )))
 (then
(set_local $out (i32.const 5))
 )
 (else
(if
(i32.and
 (i32.eq
   (get_local $out)
   (i32.const 3)
)
 (i32.eqz
  (i32.rem_s
   (get_local $in)
   (i32.const 5)
 )))
 (then
(set_local $out (i32.const 8))
 )
)
 )
)
get_local $out
)) ;)