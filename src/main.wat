(module
  (type $main (func (result i32)))
  (memory $0 1 1)
  (export "main" (func $main))
  (func $main (; 0 ;) (type $main) (result i32)
    (block $loopend
      (i32.store (i32.const 0) (i32.const 32))
      (loop $loopstart
        (br_if $loopend (i32.eqz (i32.load (i32.const 0))))
        (i32.store (i32.const 0)
          (i32.sub
            (i32.load (i32.const 0) )
            (i32.const 1)
          )
        )
        (return (i32.load (i32.const 0)))
      (br $loopstart)
      )
    )
   (i32.load (i32.const 0))
  )
)