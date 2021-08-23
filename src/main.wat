(module
  (func $foo (result f64)
    f64.const 1
    f64.neg
    f64.const 2
    f64.add
    f64.const 3
    f64.mul
    f64.const 4
    f64.neg
    f64.sub
  )
  (export "foo" (func $foo))
)