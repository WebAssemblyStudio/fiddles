(module 
  (func $print (import "imports" "print") (param i32))
  (func $helloworld (param $num i32)
   get_local $num
   call $print
  )
  (func $minus1 (param $num i32) (result i32)
    get_local $num
    i32.const 1
    i32.sub
  )
  (export "helloworld" (func $helloworld))
  (export "minus1" (func $minus1))
)