(module 
(func (export "main") (result i32) (local $var i32)
(set_local $var (i32.const 2)) ;; should be local.set for wat2wasm support
get_local $var ;; should be local.get for wat2wasm support
i32.const 6
i32.add
))