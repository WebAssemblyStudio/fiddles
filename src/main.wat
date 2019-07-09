(module
  (import "interop" "print" (func $print (param i32)))
  (import "interop" "mem" (memory 1))
  (import "interop" "slowCharToUpper" (func $slowCharToUpper (param i32)))
  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add
  )
  (func $stringToUpper (param $offset i32) (param $length i32)
    (block
      (loop
        (get_local $offset)
        (call $charToUpper)
        (set_local $offset (call $add (get_local $offset) (i32.const 1)))
        (br_if 1 (i32.ge_s (get_local $offset) (get_local $length)))
        (br 0)
      )
    )
  )
  (func $charToUpper (param $offset i32)
    get_local $offset
    call $slowCharToUpper
  )
  (export "add" (func $add))
  (export "stringToUpper" (func $stringToUpper))
)