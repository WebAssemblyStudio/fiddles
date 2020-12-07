(module
  (func $add (param $l1 i32) (param $l2 i32) (param $l3 i32) (param $l4 i32) (param $l5 i32) (result i32)
    get_local $l1
    get_local $l2
    i32.add
    get_global $l3
    i32.add
    get_global $l4
    i32.add
    get_global $l5
    i32.add
    )
  (export "add" (func $add))
)