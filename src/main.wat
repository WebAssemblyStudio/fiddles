(module
 (import "js" "memory" (memory 1))
 (table 0 anyfunc)
 (export "greyscale" (func $greyscale))
 (func $getOffset (result i32)
  i32.const 0
 )
 (func $calculateGreyscale (param $r f32) (param $g f32) (param $b f32) (result f32)
 get_local $r
  f32.const 0.299
  f32.mul
  get_local $g
  f32.const 0.587
  f32.mul
  f32.add
  get_local $b
  f32.const 0.114
  f32.mul
  f32.add
 )

 (func $greyscale (param $ptr i32) (param $len i32) (result i32)
  (local $end i32)
  (local $sum i32)
  (set_local $end (i32.add (get_local $ptr) (i32.mul (get_local $len) (i32.const 4))))
  (get_local $end)
)
)