(module
  (type $t0 (func (param i32 i32) (result i32)))
  (func $add (export "add") (type $t0) (param $p0 i32) (param $p1 i32) (result i32)
    (i32.store offset=42
      (i32.const 0)
      (tee_local $p1
        (i32.add
          (get_local $p1)
          (get_local $p0))))
    (get_local $p1))
  (memory $memory (export "memory") 16))