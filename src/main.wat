;;(module 
;;(func (export "main") (result i32) (local $var i32)
;;(set_local $var (i32.const 2)) ;; should be local.set for wat2wasm support
;;get_local $var ;; should be local.get for wat2wasm support
;;i32.const 6
;;i32.const 2
;;(set_local $var (i32.add))
;;get_local $var
;;))

(module 
(func (export "main") (param $x i32) (result i32) (local $y i32) 
i32.const 5
i32.const 6
(set_local $y (i32.add))
get_local $x
get_local $y
i32.add
))