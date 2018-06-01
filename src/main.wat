(module
  (table 2 anyfunc)
  (elem (i32.const 0) $f1 $f2)
  (type $return_i32 (func (result i32)))

  (func $f1 (result i32)
    i32.const 42)
  (func $f2 (result i32)
    i32.const 13)

  (func $callIndirect (param $i i32) (result i32)
    (call_indirect (type $return_i32) (get_local $i))
  )
  (export "callIndirect" (func $callIndirect))
)