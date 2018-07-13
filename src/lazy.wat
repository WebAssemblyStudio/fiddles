(module
  (memory $memory (import "main" "memory") 16)
  (type $t0 (func (result i32)))
  (func $add (export "get_add_result") (type $t0) (result i32)
    (i32.load offset=42
      (i32.const 0))))