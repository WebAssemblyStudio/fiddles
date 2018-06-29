(module
  (type $t0 (func (param i32 i32) (result i32)))
  (type $t1 (func (param f64 f64 f64) (result f64)))
  (type $t2 (func (param f64 f64 f64 f64) (result f64)))
  (type $t3 (func (param f64 f64) (result f64)))
  (func $add (export "add") (type $t0) (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.shl)
  (func $something (export "something") (type $t1) (param $a f64) (param $b f64) (param $c f64) (result f64)
    get_local $a
    get_local $b
    f64.add
    get_local $c
    f64.add)
  (func $slope (export "slope") (type $t2) (param $x1 f64) (param $y1 f64) (param $x2 f64) (param $y2 f64) (result f64)
    get_local $y2
    get_local $y1
    f64.sub
    get_local $x2
    get_local $x1
    f64.sub
    f64.div)
  (func $max (export "max") (type $t3) (param $a f64) (param $b f64) (result f64)
    get_local $a
    get_local $b
    f64.gt
    if $I0 (result f64)
      get_local $a
    else
      get_local $b
    end))
