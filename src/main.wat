(module
 (type $FUNCSIG$iijj (func (param i32 i32 i32) (result i32)))
 (import "env" "binary_plus_Integer32_Integer32" (func $binary_plus_Integer32_Integer32 (param i32 i32 i32) (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (export "memory" (memory $0))
 (export "Main" (func $Main))
 (export "_System__Plus_Integer32_Integer32_Integer32" (func $_System__Plus_Integer32_Integer32_Integer32))
 (func $Main (; 1 ;) (param $0 i32) (result i32)
  (call $_System__Plus_Integer32_Integer32_Integer32
   (get_local $0)
   (i32.const 1)
  )
 )
 (func $_System__Plus_Integer32_Integer32_Integer32 (; 2 ;) (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (set_local $2
   (i32.sub
    (i32.load offset=4
     (i32.const 0)
    )
    (i32.const 16)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (get_local $2)
  )
  (drop
   (call $binary_plus_Integer32_Integer32
    (i32.add
     (get_local $2)
     (i32.const 8)
    )
    (get_local $0)
    (get_local $1)
   )
  )
  (set_local $0
   (i32.load offset=8
    (get_local $2)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 16)
   )
  )
  (get_local $0)
 )
)