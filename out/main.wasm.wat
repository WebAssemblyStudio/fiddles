(module
 (type $0 (func (param i32 i32) (result i32)))
 (export "add" (func $0))
 (func $0 (; 0 ;) (type $0) (param $var$0 i32) (param $var$1 i32) (result i32)
  (i32.add
   (get_local $var$0)
   (get_local $var$1)
  )
 )
)
