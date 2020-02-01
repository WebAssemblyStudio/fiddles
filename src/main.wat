(module
  (memory 1)

  (func $offsetFromCoordinate (param $x i32) (param $y i32) (result i32)
    get_local $y
    i32.const 50
    i32.mul
    get_local $x
    i32.add
    i32.const 4
    i32.mul
  )

  (func $setCell (param $x i32) (param $y i32) (param $value i32)
    get_local $x
    get_local $y
    call $offsetFromCoordinate
    get_local $value
    i32.store
  )

  (func $getCell (param $x i32) (param $y i32) (result i32)
    get_local $x
    get_local $y
    call $offsetFromCoordinate
    i32.load
  )

  (export "setCell" (func $setCell))
  (export "getCell"(func $getCell))
  (export "offsetFromCoordinate" (func $offsetFromCoordinate))
)