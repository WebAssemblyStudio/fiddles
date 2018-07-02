(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.shl)

;;  (func $something (param $a f64) (param $b f64) (param $c f64) (result f64)
;;    (f64.add 
;;      (f64.add
;;        (get_local $a)
;;        (get_local $b)
;;      )
;;      (get_local $c)
;;    )
;;  )

(func $something (param $a f64) (param $b f64) (param $c f64) (result f64)
    get_local $a
    get_local $b
    f64.add
    get_local $c
    f64.add
 )

 ;;(func $slope (param $x1 f64) (param $y1 f64) (param $x2 f64) (param $y2 f64) (result f64)
 ;;   (f64.sub 
 ;;      (get_local $y2)
 ;;      (get_local $y1)
 ;;  )
;;    (f64.sub
 ;;      (get_local $x2) 
 ;;      (get_local $x1)
 ;;   )
 ;;   f64.div
 ;;)

 (func $slope (param $x1 f64) (param $y1 f64) (param $x2 f64) (param $y2 f64) (result f64)
    get_local $y2
    get_local $y1
    f64.sub
    get_local $x2
    get_local $x1
    f64.sub
    f64.div
 )

 ;;(func $max (param $a f64) (param $b f64) (result f64)
 ;;   (if (result f64)
 ;;     (f64.gt
 ;;       (get_local $a)
 ;;       (get_local $b)
 ;;     )
 ;;     (then
 ;;       (get_local $a)
 ;;     )
  ;;    (else 
 ;;       (get_local $b)
 ;;     )
 ;;   )    
;; )

 (func $max (param $a f64) (param $b f64) (result f64)
    get_local $a
    get_local $b
    f64.gt
    if (result f64)
      get_local $a
    else
      get_local $b
    end
 )  

 (func $addAllTo (param $num i32) (result i32)
    (local $total i32)
    (local $i i32)
    i32.const 0
    set_local $total
    i32.const 0
    set_local $i
    loop $label
      get_local $total
      get_local $i
      i32.add
      set_local $total
      i32.const 1
      get_local $i
      i32.add
      set_local $i
      get_local $i
      get_local $num
      i32.lt_s
      br_if $label
    end
    get_local $total
 )
  
 (func $fibonacci (param $n i32) (result i32) 
   (local $currentValue i32)
   (local $previousValue i32)
   (local $iterations i32)
   i32.const 1
   set_local $currentValue
   block $block
    i32.const 1
    get_local $n
    i32.eq
    br_if $block
    get_local $n
    i32.const 1
    i32.sub
    tee_local $iterations
    i32.const 1
    i32.lt_s
    br_if $block
    loop $while
      get_local $currentValue
      get_local $previousValue
      i32.add
      tee_local $currentValue
      get_local $previousValue
      i32.sub
      set_local $previousValue
      get_local $iterations
      i32.const 1
      i32.sub
      tee_local $iterations
      i32.const 0
      i32.gt_s
      br_if $while
    end
   end
   get_local $currentValue
 )

  (export "add" (func $add))
  (export "something" (func $something))
  (export "slope" (func $slope))
  (export "max" (func $max))
  (export "addAllTo" (func $addAllTo))
  (export "fibonacci" (func $fibonacci))
)