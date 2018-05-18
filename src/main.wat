(module
  (func $answer (result i32)
    i32.const 42
  )
  (func $add (param $a i32) (param $b i32) (result i32)
    get_local $a
    get_local $b
    i32.add
    call $answer
    i32.add
  )
  (export "add" (func $add))
)