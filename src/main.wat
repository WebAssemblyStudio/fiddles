(module
  (type (;0;) (func (param i64) (result i64)))
  (func (;0;) (type 0) (param i64) (result i64)
    local.get 0
    i64.const 2
    i64.eq
    if (result i64)  ;; label = @1
      i64.const 5
      return
    else
      i64.const 10
      return
    end)
  (export "main" (func 0)))