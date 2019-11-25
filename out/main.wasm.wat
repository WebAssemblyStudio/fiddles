(module
 (type $0 (func (param i32) (result i32)))
 (table 1 1 anyfunc)
 (memory $0 17)
 (export "memory" (memory $0))
 (export "add_one" (func $add_one))
 (func $add_one (; 0 ;) (type $0) (param $var$0 i32) (result i32)
  (get_local $var$0)
 )
 ;; custom section "linking", size 3
)
