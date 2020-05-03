(module 
(func (export "main") (result i32) (local $var i32)
set_local $var 2
get_local $var ;; should be local.get for wat2wasm support
i32.const 6
i32.add
))