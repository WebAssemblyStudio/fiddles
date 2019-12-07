(module
  (func $fma (param $a f64) (param $b f64) (param $c f64) (result f64)
    (f64.add
      (f64.mul (get_local $a) (get_local $b))
      (get_local $c)
    )
  (export "fma" (func $fma))
)