(module
  (func $delta (param f32) (param f32) (param f32) (result f32)
    get_local 1
    get_local 1
    f32.mul       ;;b*b
    get_local 0
    get_local 2
    f32.mul
    f32.const -4
    f32.mul       ;;-4*a*c
    f32.add)   ;;valor delta

  (func $x1 (param $a f32) (param $b f32) (param $c f32) (result f32)
    f32.const 0
    get_local $b
    f32.sub
    get_local $a
    get_local $b
    get_local $c
    call $delta
    f32.sqrt ;;raiz de delta
    f32.add
    f32.const 2
    get_local $a
    f32.mul
    f32.div)
  (export "x1" (func $x1))

  (func (export "x2") (param $a f32) (param $b f32) (param $c f32) (result f32)
    f32.const 0
    get_local $b
    f32.sub
    get_local $a
    get_local $b
    get_local $c
    call $delta
    f32.sqrt ;;raiz de delta
    f32.sub
    f32.const 2
    get_local $a
    f32.mul
    f32.div)
)