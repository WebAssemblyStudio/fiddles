(module
  (import "context" "fillRect" (func $fillRect (param i32) (param i32) (param i32) (param i32)))

  (func $draw (param $x i32) (param $y i32) (param $width i32) (param $level i32)
    (local $by3 i32)
    (local $xx i32)
    (local $yy i32)

    (set_local $by3 (i32.div_u (get_local $width) (i32.const 3)))

    (call $fillRect 
      (i32.add (get_local $x) (get_local $by3)) 
      (i32.add (get_local $y) (get_local $by3)) 
      (get_local $by3) 
      (get_local $by3))

    (if 
      (i32.gt_u (get_local $level) (i32.const 0) ) 
      (then
        (set_local $level (i32.add (get_local $level) (i32.const -1)))

        (set_local $xx (i32.const 0))
        (block
          (loop
            (set_local $xx (i32.const 0))
            (block
              (loop
                (call $draw 
                  (i32.add (get_local $x) (i32.mul (get_local $by3) (get_local $xx))) 
                  (i32.add (get_local $y) (i32.mul (get_local $by3) (get_local $yy))) 
                  (get_local $by3) 
                  (get_local $level))
                (br_if 1 (i32.eq (get_local $xx) (i32.const 2)) )
                (set_local $xx (i32.add (get_local $xx) (i32.const 1)))
                (br 0)
              )
            )
            (br_if 1 (i32.eq (get_local $yy) (i32.const 2)) )
            (set_local $yy (i32.add (get_local $yy) (i32.const 1)))
            (br 0)
          )
        )
      )
    )
  )

  (export "draw" (func $draw))
)