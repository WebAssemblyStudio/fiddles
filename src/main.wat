(module
  (memory $mem 1)
  (export "memory" (memory $mem))

  (func $tringle_area 
  (param f64) (param f64) (param f64) (param f64) (param f64) (param f64) 
  (result f64)
    
    (f64.abs
      (f64.div
        (f64.add
          (f64.add
            (f64.mul
              (get_local 0)
              (f64.sub
                (get_local 3)
                (get_local 5)
              )
            )
            (f64.mul
              (get_local 2)
              (f64.sub
                (get_local 5)
                (get_local 1)
              )
            )
          )
          (f64.mul
            (get_local 4)
            (f64.sub
              (get_local 1)
              (get_local 3)
            )
          )
        )
        (f64.const 2)
      )
    )
  )

  (func $triangle_area_for_coords
    (param $coord_a i32) (param $coord_b i32) (param $coord_c i32)
    (result f64)

    (call $tringle_area 
      (f64.load (get_local $coord_a))
      (f64.load (i32.add (get_local $coord_a) (i32.const 8)))
      (f64.load (get_local $coord_b))
      (f64.load (i32.add (get_local $coord_b) (i32.const 8)))
      (f64.load (get_local $coord_c))
      (f64.load (i32.add (get_local $coord_c) (i32.const 8)))
    )
  )

  (func $array_copy
    (param $src i32) (param $src_end i32) (param $dest i32)

    (block
      (loop
        (br_if 1
          (i32.gt_u
            (get_local $src)
            (get_local $src_end)
          )
        )

        (i32.store
          (get_local $dest)
          (i32.load
            (get_local $src)
          )
        )

        (set_local $src (i32.add (get_local $src) (i32.const 4)))
        (set_local $dest (i32.add (get_local $dest) (i32.const 4)))
        (br 0)
      )
    )
  )

  (func $prev_index_circular 
    (param $i i32) (param $arr_len i32) 
    (result i32)
    
    (if (result i32)
      (i32.eq
        (get_local $i)
        (i32.const 0)
      )
      (then
        (i32.sub
          (get_local $arr_len)
          (i32.const 1)
        )
      )
      (else
        (i32.sub
          (get_local $i)
          (i32.const 1)
        )
      )
    )
  )

  (func $f64_get 
    (param $byte_offset i32)
    (result f64)

    (f64.load (get_local $byte_offset))
  )

  (export "triangle_area_for_coords" (func $triangle_area_for_coords))
  (export "array_copy" (func $array_copy))
  (export "f64_get" (func $f64_get))
  (export "prev_index_circular" (func $prev_index_circular))
)