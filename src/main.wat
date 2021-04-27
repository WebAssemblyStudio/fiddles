(module
  (import "eval" "(function(a,b){console.log(`${a} holy shit i can actually get away with this ${b}`);})" (func $wtf (param i32) (param i32)))
  (func $main
    i32.const 123
    i32.const 456
    call $wtf
  )
  (export "main" (func $main))
)
