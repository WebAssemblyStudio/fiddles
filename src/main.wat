(module
  (type $type0 (func (result i32)))
  (type $type1 (func (param i32) (result i32)))
  (import $import0 "env" "printf"  (param i32) (result i32))
  (table 0 anyfunc)
  (memory 1)
  (export "memory" memory)
  (export "main" $func1)
  (func $func1 (result i32)
    i32.const 16
    call $import0
    drop
    i32.const 0
  )
  (data (i32.const 16)
    "Hello World\n\00"
  )
)