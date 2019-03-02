(module
  (func $testSIMD_int_max
    (local $0 v128)
    (local $1 v128)
    v128.const i32 0x01000100 0x01000100 0x01000100 0x01000100
    local.tee $0
    v128.const i32 0x00020002 0x00020002 0x00020002 0x00020002
    local.tee $1
    local.get $0
    local.get $1
    i8x16.gt_u
    v128.bitselect
    v128.const i32 0x01020102 0x01020102 0x01020102 0x01020102
    i8x16.eq
    i8x16.all_true
    i32.const 0
    i32.ne
    i32.eqz
    if
     unreachable
    end
  )
  (export "testSIMD_int_max" (func $testSIMD_int_max)))