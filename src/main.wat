(module
  (func $i (import "imports" "i") (param i32))
  (memory (export "mem") 1)
  (func (export "e") 
    i32.const 57
    call $i)
  (func (export "add") (param $x i32) (param $y i32) (result i32)
     get_local $x 
     get_local $y 
     i32.add)
)