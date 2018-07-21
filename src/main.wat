(module $Quick

  (global $res (i32) 10)

  (func $add ( i32 i32) (result i32)
    ( i32.add
        get_local 0
        get_global $res
    )
  )
  (export "add" (func $add))
)