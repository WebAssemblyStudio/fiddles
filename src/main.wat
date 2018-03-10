(module
  (func $add32 (param $a i32) (result f32)
    get_local $a
    i32.const 42
    i32.add
    f32.convert_s/i32
    f32.const 41.1337
    f32.add)

  (func (export "mul") (param $a i32) (param $b i32) (result f32)
    get_local $a
    get_local $b
    i32.mul
    call $add32)
)
