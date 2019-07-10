(module
  (import "interop" "print" (func $print (param i32))) ;; Import the interop function for console.log
  (import "interop" "mem" (memory 1)) ;; Include the shared memory for the string casing excercise
  (import "interop" "slowCharToUpper" (func $slowCharToUpper (param i32))) ;; Import the javascript casing function

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add
  )

  (func $charToUpper (param $offset i32)
    get_local $offset
    ;; Calls into javascript to read from the shared memory and perform the uppercase operation
    ;; You want to replace this code with Webassembly operations 
    call $slowCharToUpper 
  )

  ;; This function loops over the (ASCII) string and uppercases every lowercase character
  ;; You do not have to modify this function
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
  (export "add" (func $add))
  (export "stringToUpper" (func $stringToUpper))
)