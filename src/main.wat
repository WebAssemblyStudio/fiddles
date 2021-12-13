(module
  (func (export "f") (param $x i64) (result i64)
    get_local $x
    (i64.const 42)
    i64.add))