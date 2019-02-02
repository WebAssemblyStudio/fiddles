(module
  (func (export "greater") (param i32 i32) (result i32)
    (select
      (get_local 0)
      (get_local 1)
      (i32.gt_s
        (get_local 0)
        (get_local 1)
      )
    )
  )

  (func (export "greater2") (param i32 i32) (result i32)
    (if (i32.gt_s (get_local 0) (get_local 1))
      (return (i32.add (get_local 0) (i32.const 1)))
    )
    
    (return (get_local 1))
  )
)