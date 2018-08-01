(module
  (type $type0 (func (result i32)))
  (type $type1 (func (param i32 i32) (result i32)))
  (import "env" "add" (func $add (param i32 i32) (result i32)))
  (memory $mem 1)
  (data (i32.const 0) "\00\05\00\00")
  (func $main (result i32)
    i32.const 0
    i32.load offset=1
    i32.const 2
    call $multiply
  )
  (func $multiply (param $a i32) (param $b i32) (result i32)
    get_local $a
    get_local $b
    i32.mul
  )
  (export "main" (func $main))
  (export "memory" (memory $mem))
)