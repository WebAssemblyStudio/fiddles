(module
  (func $add (param $a f32) (param $b f32) (param $c f32) (result f32)
    f32.const 0
    get_local $b
    f32.sub
    get_local $a
    get_local $c
    f32.mul
    f32.const -4
    f32.mul
    get_local $b
    get_local $b
    f32.mul
    f32.add
    f32.sqrt ;;raiz de delta
    f32.sub
    f32.const 2
    get_local $a
    f32.mul
    f32.div)
  (export "add" (func $add))
)