(module
  (memory (export "mem") 5)
  (table 4 anyfunc)
  (elem (i32.const 0) $f0 $f1 $f2 $f3)
  (func (export "sqrt") (param $exp f32) (result f32)
    get_local $exp
    f32.sqrt)
  (func (export "add") (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)
  (func (export "sub") (param $ls i32) (param $rs i32) (result i32)
    get_local $ls
    get_local $rs
    i32.sub)
  (func (export "div") (param $ls i32) (param $rs i32) (result i32)
    get_local $ls
    get_local $rs
    i32.div_u)
)
