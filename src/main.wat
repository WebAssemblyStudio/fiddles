(module
  (func $fact (param $n i32) (result i32)
    get_local $n
    (if (result i32) (i32.eqz)
      (then
        i32.const 1)
      (else
        get_local $n
        i32.const 1
        i32.sub
        call $fact
        get_local $n
        i32.mul)
      ))
  (export "fact" (func $fact))
)