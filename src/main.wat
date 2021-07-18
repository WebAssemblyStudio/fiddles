(module
  (import "console" "log" (func $log (param $message i32)))

  (global $globalVar (mut i32) (i32.const 99))

  (func $add (param $n1 i32) (param $n2 i32) (result i32)
    (i32.add (get_local $n1) (get_local $n2))
  )
  (export "add" (func $add))


  (func $getGlobal (export "getGlobal") (result i32)
    get_global $globalVar
  )

  (func $setGlobal (export "setGlobal") (param $n1 i32)
    (set_global $globalVar (get_local $n1))
  )

  (func $testIF (export "testIf") (param $n i32) (result i32)
    
    (i32.gt_s (get_local $n) (i32.const 0))

    if (result i32)
        i32.const 100
    else
        i32.const -100
    end

  )

  (func $log13
    (call $log (i32.const 13))
  )

  (start $log13)
)
