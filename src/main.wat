 (module
   (memory (export "memory") 1)
   (data (i32.const 0) "yooo")

   (func (export "add") (param $x i32) (param $y i32) (result i32)
     get_local $x 
     get_local $y 
     i32.add)
   (func (export "mul") (param i32 i32) (result i32)
     get_local 0 
     get_local 1 
     i32.mul)
 )