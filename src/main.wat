(module
  ;; 2 * parent + 1
  (func $left_child (param $parent i32) (result i32)
    get_local $parent
    i32.const 2
    i32.mul
    i32.const 1
    i32.add
  )


  (export "left_child" (func $left_child))
)