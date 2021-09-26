(module
  (func $minusone (param $in i32) (result i32)
    get_local $in
    i32.const 1
    i32.sub
  )
  (export "minusOne" (func $minusone))
)