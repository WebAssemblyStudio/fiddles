(module
  (func $add (param i32) (param i32) (result i32)
    get_local 0
    get_local 0
    i32.add 
  )
  (export "add" (func $add))
)