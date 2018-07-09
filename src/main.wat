(module
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
      (block $B2 (result i32)
        (block $B3 (result i32)
          (block $B4 (result i32)
            (block $B5 (result i32)    
              i32.const 8
              i32.const 2 
              br_table $B2 $B3 $B4
            )
            i32.const 7
            br $B2
          )
          i32.const 6
          br $B2
        )
        i32.const 5
        br $B2
      )
  )
  (export "add" (func $add))
)