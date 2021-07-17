(module
  (global $globalVar (mut i32) (i32.const 99))

  (func $add (param $n1 i32) (param $n2 i32) (result i32)
    get_local $n1
    get_local $n2
    i32.add
  )
  (export "add" (func $add))


  (func $getGlobal (export "getGlobal") (result i32)
    get_global $globalVar
  )

  (func $setGlobal (export "setGlobal") (param $n1 i32)
    get_local $n1
    set_global $globalVar
  )
)
