(module
 (type $FUNCSIG$dd (func (param f64) (result f64)))
 (import "env" "sin" (func $sin (param f64) (result f64)))
 (table 0 anyfunc)
 (memory $0 1)
 (export "memory" (memory $0))
 (export "rt_add" (func $rt_add))
 (export "rt_sin" (func $rt_sin))
 (func $rt_add (; 1 ;) (param $0 i32) (param $1 i32) (result i32)
  (i32.add
   (get_local $1)
   (get_local $0)
  )
 )
 (func $rt_sin (; 2 ;) (param $0 f32) (result i32)
  (i32.trunc_s/f64
   (call $sin
    (f64.promote/f32
     (get_local $0)
    )
   )
  )
 )
)