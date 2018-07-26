(module
  (type $t0 (func))
  (type $t1 (func (param i32 i32 i32 i32)))
  (type $t2 (func (param i32 i32 i32 i32)))
  (import "env" "abort" (func $env.abort (type $t2)))
  (func $f1 (type $t0)
    (local $l0 i32) (local $l1 i32)
    block $B0
      loop $L1
        get_local $l0
        i32.const 32
        i32.ge_s
        br_if $B0
        get_local $l0
        i32.const 12
        i32.eq
        if $I2 (result i32)
          get_local $l0
          i32.const 32
          i32.add
        else
          get_local $l0
          i32.const 1
          i32.add
          set_local $l0
          br $L1
        end
        set_local $l1
      end
    end
    get_local $l1
    i32.const 44
    i32.ne
    if $I3
      i32.const 0
      i32.const 8
      i32.const 33
      i32.const 4
      call $env.abort
      unreachable
    end)
  (func $f2 (type $t0)
    i32.const 32
    set_global $g0
    get_global $g0
    set_global $g1
    call $f1)
  (memory $memory (export "memory") 1)
  (global $g0 (mut i32) (i32.const 0))
  (global $g1 (mut i32) (i32.const 0))
  (start 2)
  (data (i32.const 8) "\08\00\00\00b\00r\00e\00a\00k\00.\00t\00s"))
