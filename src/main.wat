(module
  (func $add (param i32) (param i32) (result i32)
    get_local 0 ;; grab the first item
    get_local 1 ;; grab the second item
    i32.add ;; add them
  )
  (export "add" (func $add))
)