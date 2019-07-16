(module
  (memory (export "screenbuf") 2)

  (table 6 anyfunc)
  (elem (i32.const 0)
    $solidcolorred
    $solidcolorblue
    $mapcolorXOR
    $mapcolorRND
    $mapnoiseredshift
    $mapsmoothnoisecolorX
  )

  (global $bytecolordepth i32 i32.const 4)
  (global $width i32 i32.const 100)
  (global $height i32 i32.const 100)
  (global $step (mut i32) i32.const 0)
  (global $xorshiftstate (mut i32) i32.const 0xFA1922DC)
  
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (export "add" (func $add))
  
  (func $increment (param $lhs i32) (result i32)
    get_local $lhs
    i32.const 1
    i32.add
  )

;;  uint32_t xorshift32(struct xorshift32_state *state)
;;{
;;	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
;;	uint32_t x = state->a;
;;	x ^= x << 13;
;;	x ^= x >> 17;
;;	x ^= x << 5;
;;	return state->a = x;
;;}

(func $xorshift32 (result i32)
  get_global $xorshiftstate
  get_global $xorshiftstate
  i32.const 13
  i32.shl
  i32.xor
  set_global $xorshiftstate
  
  get_global $xorshiftstate
  get_global $xorshiftstate
  i32.const 17
  i32.shr_u
  i32.xor
  set_global $xorshiftstate

  get_global $xorshiftstate
  get_global $xorshiftstate
  i32.const 5
  i32.shl
  i32.xor
  set_global $xorshiftstate

  get_global $xorshiftstate
)


  (func $setpix (param $x i32) (param $y i32) (param $color i32)
    get_global $width
    get_local $y
    i32.mul
    get_local $x
    i32.add
    get_global $bytecolordepth
    i32.mul
    get_local $color
    i32.store
  )

  (func $getpix (param $x i32) (param $y i32) (result i32)
    get_global $width
    get_local $y
    i32.mul
    get_local $x
    i32.add
    get_global $bytecolordepth
    i32.mul
    i32.load
  )

  (func $mapcolorXOR (param $x i32) (param $y i32) (result i32)
    (i32.or (i32.shl (i32.xor (get_local $x) (get_local $y)) (get_global $step)) (i32.const 0xff000000))
  )

  (func $mapcolorRND (param $x i32) (param $y i32) (result i32)
    (i32.or (call $xorshift32) (i32.const 0xff000000))
    ;;(call $xorshift32)
  )


  (func $mapnoiseredshift (param $x i32) (param $y i32) (result i32)
    (call $xorshift32)
    i32.const 14
    i32.shr_u
    i32.const 0x00000088
    i32.add
    i32.const 0xff000000
    i32.or
  )

  (func $mapsmoothnoisecolorX (param $x i32) (param $y i32) (result i32)
    (call $xorshift32)
    i32.const 27
    i32.shr_u
  
    (if (result i32)(i32.gt_s (get_local $x) (i32.const 0)) 
      (then 
        get_local $x
        i32.const 1
        i32.sub
        get_local $y
        (call $getpix)
        ;;i32.const 1
        ;;i32.shr_u
      )
      (else i32.const 0)
    )

    i32.add
    i32.const 0xff000000
    i32.or
  )


  (func $solidcolorred  (param $x i32) (param $y i32) (result i32)
    i32.const 0xFF0000FF
  )

  (func $solidcolorblue  (param $x i32) (param $y i32) (result i32)
    i32.const 0xFFFF0000
  )

 
  (func $loopcol (param $y i32)
    (local $x i32)
    (set_local $x (i32.const 0))

    
    (block 
      (loop
         
        (call $setpix (get_local $x) (get_local $y) (call_indirect (param i32) (param i32) (result i32) (get_local $x) (get_local $y) (i32.const 4)))

        (set_local $x (call $increment (get_local $x)))
        (br_if 1 (i32.eq (get_local $x) (i32.const 100)))
        (br 0)
      )
    )
  )

  (func $looprow
    (local $y i32)
    (set_local $y (i32.const 0))

    (block 
      (loop
         
        (call $loopcol (get_local $y))
        (set_local $y (call $increment (get_local $y)))
      
        (br_if 1 (i32.eq (get_local $y) (i32.const 100)))
        (br 0)
      )
    )
  )


  (func $main (result i32)
    
    ;;get_global $step
    ;;set_global $xorshiftstate

    (call $looprow)
    
    (set_global $step (call $increment (get_global $step)))
    (if 
      (i32.gt_u
        (get_global $step)
        (i32.const 16)
      )
      (then
        (set_global $step (i32.const 0))
      )
    ) 
    
    (call $setpix (i32.const 5) (i32.const 0) (i32.const 0xffff0000))
    i32.const 0
    i32.const 0xff0000ff
    i32.store
    i32.const 0
    i32.load
  )
  (export "main" (func $main))

)