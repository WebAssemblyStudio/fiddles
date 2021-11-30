(module
  (type $t0 (func (param i32)))
  (type $t1 (func))
  (type $t2 (func (result i32)))
  (type $t3 (func (param i32 i32 i32) (result i32)))
  (import "env" "putc_js" (func $putc_js (type $t0)))
  (func $__wasm_call_ctors (type $t1))
  (func $main (export "main") (type $t2) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    get_global $g0
    i32.const 96
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 82
    i32.add
    i32.const 0
    i32.load8_u offset=1058
    i32.store8
    get_local $l0
    i32.const 80
    i32.add
    i32.const 0
    i32.load16_u offset=1056
    i32.store16
    get_local $l0
    i32.const 48
    i32.add
    i32.const 24
    i32.add
    i32.const 0
    i64.load offset=1048
    i64.store
    get_local $l0
    i32.const 64
    i32.add
    i32.const 0
    i64.load offset=1040
    i64.store
    get_local $l0
    i32.const 0
    i64.load offset=1032
    i64.store offset=56
    get_local $l0
    i32.const 0
    i64.load offset=1024
    i64.store offset=48
    block $B0
      get_local $l0
      get_local $l0
      i32.const 48
      i32.add
      i32.const 39
      call $strncpy
      tee_local $l1
      i32.load8_u
      tee_local $l2
      i32.eqz
      br_if $B0
      get_local $l1
      set_local $l3
      loop $L1
        block $B2
          block $B3
            block $B4
              block $B5
                get_local $l2
                i32.const -97
                i32.add
                i32.const 255
                i32.and
                i32.const 26
                i32.ge_u
                br_if $B5
                i32.const 243
                set_local $l4
                get_local $l2
                i32.const 24
                i32.shl
                i32.const 24
                i32.shr_s
                i32.const 109
                i32.gt_s
                br_if $B3
                br $B4
              end
              get_local $l2
              i32.const -65
              i32.add
              i32.const 255
              i32.and
              i32.const 26
              i32.ge_u
              br_if $B2
              i32.const 243
              set_local $l4
              get_local $l2
              i32.const 24
              i32.shl
              i32.const 24
              i32.shr_s
              i32.const 77
              i32.gt_s
              br_if $B3
            end
            i32.const 13
            set_local $l4
          end
          get_local $l3
          get_local $l2
          get_local $l4
          i32.add
          i32.store8
        end
        get_local $l3
        i32.load8_u offset=1
        set_local $l2
        get_local $l3
        i32.const 1
        i32.add
        set_local $l3
        get_local $l2
        br_if $L1
      end
      get_local $l1
      i32.load8_u
      tee_local $l2
      i32.eqz
      br_if $B0
      get_local $l0
      i32.const 1
      i32.or
      set_local $l3
      loop $L6
        get_local $l2
        i32.const 24
        i32.shl
        i32.const 24
        i32.shr_s
        call $putc_js
        get_local $l3
        i32.load8_u
        set_local $l2
        get_local $l3
        i32.const 1
        i32.add
        set_local $l3
        get_local $l2
        br_if $L6
      end
    end
    i32.const 10
    call $putc_js
    get_local $l0
    i32.const 96
    i32.add
    set_global $g0
    i32.const 0)
  (func $memset (type $t3) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i64)
    block $B0
      get_local $p2
      i32.eqz
      br_if $B0
      get_local $p0
      get_local $p1
      i32.store8
      get_local $p0
      get_local $p2
      i32.add
      tee_local $l0
      i32.const -1
      i32.add
      get_local $p1
      i32.store8
      get_local $p2
      i32.const 3
      i32.lt_u
      br_if $B0
      get_local $p0
      get_local $p1
      i32.store8 offset=2
      get_local $p0
      get_local $p1
      i32.store8 offset=1
      get_local $l0
      i32.const -3
      i32.add
      get_local $p1
      i32.store8
      get_local $l0
      i32.const -2
      i32.add
      get_local $p1
      i32.store8
      get_local $p2
      i32.const 7
      i32.lt_u
      br_if $B0
      get_local $p0
      get_local $p1
      i32.store8 offset=3
      get_local $l0
      i32.const -4
      i32.add
      get_local $p1
      i32.store8
      get_local $p2
      i32.const 9
      i32.lt_u
      br_if $B0
      get_local $p0
      i32.const 0
      get_local $p0
      i32.sub
      i32.const 3
      i32.and
      tee_local $l1
      i32.add
      tee_local $l0
      get_local $p1
      i32.const 255
      i32.and
      i32.const 16843009
      i32.mul
      tee_local $p1
      i32.store
      get_local $l0
      get_local $p2
      get_local $l1
      i32.sub
      i32.const -4
      i32.and
      tee_local $l1
      i32.add
      tee_local $p2
      i32.const -4
      i32.add
      get_local $p1
      i32.store
      get_local $l1
      i32.const 9
      i32.lt_u
      br_if $B0
      get_local $l0
      get_local $p1
      i32.store offset=8
      get_local $l0
      get_local $p1
      i32.store offset=4
      get_local $p2
      i32.const -8
      i32.add
      get_local $p1
      i32.store
      get_local $p2
      i32.const -12
      i32.add
      get_local $p1
      i32.store
      get_local $l1
      i32.const 25
      i32.lt_u
      br_if $B0
      get_local $l0
      get_local $p1
      i32.store offset=16
      get_local $l0
      get_local $p1
      i32.store offset=12
      get_local $l0
      get_local $p1
      i32.store offset=20
      get_local $l0
      get_local $p1
      i32.store offset=24
      get_local $p2
      i32.const -24
      i32.add
      get_local $p1
      i32.store
      get_local $p2
      i32.const -28
      i32.add
      get_local $p1
      i32.store
      get_local $p2
      i32.const -20
      i32.add
      get_local $p1
      i32.store
      get_local $p2
      i32.const -16
      i32.add
      get_local $p1
      i32.store
      get_local $l1
      get_local $l0
      i32.const 4
      i32.and
      i32.const 24
      i32.or
      tee_local $l2
      i32.sub
      tee_local $p2
      i32.const 32
      i32.lt_u
      br_if $B0
      get_local $p1
      i64.extend_u/i32
      tee_local $l3
      i64.const 32
      i64.shl
      get_local $l3
      i64.or
      set_local $l3
      get_local $l0
      get_local $l2
      i32.add
      set_local $p1
      loop $L1
        get_local $p1
        get_local $l3
        i64.store
        get_local $p1
        i32.const 8
        i32.add
        get_local $l3
        i64.store
        get_local $p1
        i32.const 16
        i32.add
        get_local $l3
        i64.store
        get_local $p1
        i32.const 24
        i32.add
        get_local $l3
        i64.store
        get_local $p1
        i32.const 32
        i32.add
        set_local $p1
        get_local $p2
        i32.const -32
        i32.add
        tee_local $p2
        i32.const 31
        i32.gt_u
        br_if $L1
      end
    end
    get_local $p0)
  (func $__stpncpy (type $t3) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    block $B0
      block $B1
        block $B2
          get_local $p1
          get_local $p0
          i32.xor
          i32.const 3
          i32.and
          i32.eqz
          br_if $B2
          get_local $p2
          set_local $l0
          br $B1
        end
        get_local $p2
        i32.const 0
        i32.ne
        set_local $l1
        block $B3
          block $B4
            block $B5
              get_local $p2
              i32.eqz
              br_if $B5
              get_local $p1
              i32.const 3
              i32.and
              i32.eqz
              br_if $B5
              loop $L6
                get_local $p0
                get_local $p1
                i32.load8_u
                tee_local $l0
                i32.store8
                get_local $l0
                i32.eqz
                br_if $B0
                get_local $p2
                i32.const 1
                i32.ne
                set_local $l1
                get_local $p0
                i32.const 1
                i32.add
                set_local $p0
                get_local $p2
                i32.const -1
                i32.add
                set_local $l0
                get_local $p1
                i32.const 1
                i32.add
                set_local $p1
                block $B7
                  get_local $p2
                  i32.const 1
                  i32.eq
                  br_if $B7
                  get_local $l0
                  set_local $p2
                  get_local $p1
                  i32.const 3
                  i32.and
                  br_if $L6
                end
              end
              get_local $l1
              i32.eqz
              br_if $B4
              br $B3
            end
            get_local $p2
            set_local $l0
            get_local $l1
            br_if $B3
          end
          get_local $p0
          i32.const 0
          i32.const 0
          call $memset
          return
        end
        block $B8
          get_local $p1
          i32.load8_u
          i32.eqz
          br_if $B8
          get_local $l0
          i32.const 4
          i32.lt_u
          br_if $B1
          loop $L9
            get_local $p1
            i32.load
            tee_local $p2
            i32.const -1
            i32.xor
            get_local $p2
            i32.const -16843009
            i32.add
            i32.and
            i32.const -2139062144
            i32.and
            br_if $B1
            get_local $p0
            get_local $p2
            i32.store
            get_local $p0
            i32.const 4
            i32.add
            set_local $p0
            get_local $p1
            i32.const 4
            i32.add
            set_local $p1
            get_local $l0
            i32.const -4
            i32.add
            tee_local $l0
            i32.const 3
            i32.gt_u
            br_if $L9
            br $B1
          end
        end
        get_local $p0
        i32.const 0
        get_local $l0
        call $memset
        return
      end
      i32.const 0
      set_local $p2
      get_local $l0
      i32.eqz
      br_if $B0
      block $B10
        loop $L11
          get_local $p0
          get_local $p1
          i32.load8_u
          tee_local $l1
          i32.store8
          get_local $l1
          i32.eqz
          br_if $B10
          get_local $p0
          i32.const 1
          i32.add
          set_local $p0
          get_local $p1
          i32.const 1
          i32.add
          set_local $p1
          get_local $l0
          i32.const -1
          i32.add
          tee_local $l0
          br_if $L11
          br $B0
        end
      end
      get_local $l0
      set_local $p2
    end
    get_local $p0
    i32.const 0
    get_local $p2
    call $memset)
  (func $strncpy (type $t3) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    get_local $p0
    get_local $p1
    get_local $p2
    call $__stpncpy
    drop
    get_local $p0)
  (table $T0 1 1 anyfunc)
  (memory $memory (export "memory") 2)
  (global $g0 (mut i32) (i32.const 66608))
  (global $__heap_base (export "__heap_base") i32 (i32.const 66608))
  (global $__data_end (export "__data_end") i32 (i32.const 1059))
  (data (i32.const 1024) "Guvf vf zl fhcre frperg cnffcuenfr\00"))
