(module
  (import "interop" "print" (func $print (param i32)))
  (import "interop" "strToUpper" (func $slowToUpper (param i32) (param i32)))
  (import "interop" "mem" (memory 1))
  (func $debug (param $arg i32) (result i32)
    get_local $arg
    call $print
    get_local $arg
  )
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add
  )
  (func $stringToUpper (param $offset i32) (param $length i32)
    (block
      (loop
        (call $charToUpper (get_local $offset))
        (set_local $offset (call $add (get_local $offset) (i32.const 1)))
        (br_if 1 (i32.eq (get_local $offset) (get_local $length)))
        (br 0)
      )
    )
  )
  (func $charToUpper (param $offset i32)
    (get_local $offset)
    (i32.const 1)
    call $slowToUpper
  )
  (export "add" (func $add))
  (export "stringToUpper" (func $stringToUpper))
)