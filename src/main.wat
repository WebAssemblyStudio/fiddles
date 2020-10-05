(module
  (func $pos_aNaN_sub_neg_0 (result i32)
    f32.const nan:0x400000
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $neg_aNaN_sub_neg_0 (result i32)
    f32.const -nan:0x400000
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $pos_aNaN_sub_neg_0_opt (result i32)
    f32.const nan:0x400000
    f32.const 0
    f32.add
    i32.reinterpret/f32)
  (func $neg_aNaN_sub_neg_0_opt (result i32)
    f32.const -nan:0x400000
    f32.const 0
    f32.add
    i32.reinterpret/f32)

  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (func $pos_NaN_sub_neg_0 (result i32)
    f32.const nan
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $neg_NaN_sub_neg_0 (result i32)
    f32.const -nan
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $pos_NaN_sub_neg_0_opt (result i32)
    f32.const nan
    f32.const 0
    f32.add
    i32.reinterpret/f32)
  (func $neg_NaN_sub_neg_0_opt (result i32)
    f32.const -nan
    f32.const 0
    f32.add
    i32.reinterpret/f32)

  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (func $pos_sNaN_sub_neg_0 (result i32)
    f32.const nan:0x200000
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $neg_sNaN_sub_neg_0 (result i32)
    f32.const -nan:0x200000
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $pos_sNaN_sub_neg_0_opt (result i32)
    f32.const nan:0x200000
    f32.const 0
    f32.add
    i32.reinterpret/f32)
  (func $neg_sNaN_sub_neg_0_opt (result i32)
    f32.const -nan:0x200000
    f32.const 0
    f32.add
    i32.reinterpret/f32)

  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (func $pos_ncNaN_sub_neg_0 (result i32)
    f32.const nan:0x356216
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $neg_ncNaN_sub_neg_0 (result i32)
    f32.const -nan:0x356216
    f32.const -0
    f32.sub
    i32.reinterpret/f32)
  (func $pos_ncNaN_sub_neg_0_opt (result i32)
    f32.const nan:0x356216
    f32.const 0
    f32.add
    i32.reinterpret/f32)
  (func $neg_ncNaN_sub_neg_0_opt (result i32)
    f32.const -nan:0x356216
    f32.const 0
    f32.add
    i32.reinterpret/f32)

  (export "pos_aNaN_sub_neg_0" (func $pos_aNaN_sub_neg_0))
  (export "neg_aNaN_sub_neg_0" (func $neg_aNaN_sub_neg_0))
  (export "pos_aNaN_sub_neg_0_opt" (func $pos_aNaN_sub_neg_0_opt))
  (export "neg_aNaN_sub_neg_0_opt" (func $neg_aNaN_sub_neg_0_opt))

  (export "pos_NaN_sub_neg_0" (func $pos_NaN_sub_neg_0))
  (export "neg_NaN_sub_neg_0" (func $neg_NaN_sub_neg_0))
  (export "pos_NaN_sub_neg_0_opt" (func $pos_NaN_sub_neg_0_opt))
  (export "neg_NaN_sub_neg_0_opt" (func $neg_NaN_sub_neg_0_opt))

  (export "pos_sNaN_sub_neg_0" (func $pos_sNaN_sub_neg_0))
  (export "neg_sNaN_sub_neg_0" (func $neg_sNaN_sub_neg_0))
  (export "pos_sNaN_sub_neg_0_opt" (func $pos_sNaN_sub_neg_0_opt))
  (export "neg_sNaN_sub_neg_0_opt" (func $neg_sNaN_sub_neg_0_opt))

  (export "pos_ncNaN_sub_neg_0" (func $pos_ncNaN_sub_neg_0))
  (export "neg_ncNaN_sub_neg_0" (func $neg_ncNaN_sub_neg_0))
  (export "pos_ncNaN_sub_neg_0_opt" (func $pos_ncNaN_sub_neg_0_opt))
  (export "neg_ncNaN_sub_neg_0_opt" (func $neg_ncNaN_sub_neg_0_opt))
)