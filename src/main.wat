(module
  (func $add (param i32) (param i32) (result i32)
    get_local 0
    get_local 1
    i32.add)
  (export "add" (func $add))
  (func $sub (param i32) (param i32) (result i32)
  get_local 0
  get_local 1
  i32.sub)
  (export "sub" (func $sub))
  (func $mul (param i32) (param i32) (result i32)
  get_local 0
  get_local 1
  i32.mul)
  (export "mul" (func $mul))
  (func $div (param i32) (param i32) (result i32)
  get_local 0
  get_local 1
  i32.div_s)
  (export "div" (func $div))
)