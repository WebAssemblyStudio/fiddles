(module
  (type $t0 (func (param i32) (result i32)))
  (func $add_one (export "add_one") (type $t0) (param $p0 i32) (result i32)
    get_local $p0
    i32.const 1
    i32.add)
  (func $mod_fortytwo (export "mod_fortytwo") (type $t0) (param $p0 i32) (result i32)
    get_local $p0
    i32.const 42
    i32.rem_s)
  (func $wiggle (export "wiggle") (type $t0) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_local $p0
    i32.const 5286852
    i32.xor
    set_local $l0
    i32.const 99
    set_local $l1
    loop $L0
      get_local $l0
      get_local $p0
      i32.xor
      set_local $l2
      get_local $p0
      set_local $l0
      get_local $l2
      set_local $p0
      get_local $l1
      i32.const -1
      i32.add
      tee_local $l1
      br_if $L0
    end
    get_local $l2)
  (table $T0 1 1 anyfunc)
  (memory $memory (export "memory") 17))
