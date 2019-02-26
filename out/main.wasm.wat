(module
  (type $t0 (func (param i32 i32 i32) (result i32)))
  (type $t1 (func (param i32)))
  (type $t2 (func (param i32 i32 i32 i32) (result i32)))
  (type $t3 (func (param i32 i32) (result i32)))
  (type $t4 (func (param i32 i32 i32 i32 i32 i32) (result i32)))
  (type $t5 (func))
  (type $t6 (func (result i32)))
  (type $t7 (func (param i32) (result i32)))
  (type $t8 (func (param i32 i64 i32) (result i64)))
  (import "env" "putc_js" (func $putc_js (type $t1)))
  (import "env" "__syscall3" (func $__syscall3 (type $t2)))
  (import "env" "__syscall1" (func $__syscall1 (type $t3)))
  (import "env" "__syscall5" (func $__syscall5 (type $t4)))
  (func $__wasm_call_ctors (type $t5))
  (func $main (export "main") (type $t6) (result i32)
    i32.const 1024
    call $puts
    drop
    i32.const 0)
  (func $writev_c (export "writev_c") (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32)
    block $B0
      get_local $p2
      i32.const 1
      i32.lt_s
      br_if $B0
      i32.const 0
      set_local $l0
      i32.const 0
      set_local $l1
      loop $L1
        i32.const 0
        set_local $l2
        block $B2
          get_local $p1
          get_local $l0
          i32.const 3
          i32.shl
          i32.add
          tee_local $l3
          i32.load offset=4
          i32.eqz
          br_if $B2
          get_local $l3
          i32.const 4
          i32.add
          set_local $l4
          i32.const 0
          set_local $l5
          loop $L3
            get_local $l3
            i32.load
            get_local $l5
            i32.add
            i32.load8_s
            call $putc_js
            get_local $l5
            i32.const 1
            i32.add
            tee_local $l5
            get_local $l4
            i32.load
            tee_local $l2
            i32.lt_u
            br_if $L3
          end
        end
        get_local $l2
        get_local $l1
        i32.add
        set_local $l1
        get_local $l0
        i32.const 1
        i32.add
        tee_local $l0
        get_local $p2
        i32.ne
        br_if $L1
      end
      get_local $l1
      return
    end
    i32.const 0)
  (func $__lockfile (type $t7) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    i32.const 0
    set_local $l0
    block $B0
      get_local $p0
      i32.load offset=76
      i32.const -1073741825
      i32.and
      i32.const 0
      i32.load offset=27
      tee_local $l1
      i32.eq
      br_if $B0
      get_local $p0
      i32.const 76
      i32.add
      set_local $p0
      block $B1
        loop $L2
          get_local $p0
          i32.load
          tee_local $l0
          i32.eqz
          br_if $B1
          get_local $p0
          i32.load
          get_local $l0
          i32.ne
          br_if $L2
        end
        get_local $p0
        get_local $l0
        i32.const 1073741824
        i32.or
        i32.store
        block $B3
          get_local $p0
          i32.load
          tee_local $l0
          i32.eqz
          br_if $B3
          loop $L4
            block $B5
              i32.const 240
              get_local $p0
              i32.const 128
              get_local $l0
              call $__syscall3
              i32.const -38
              i32.ne
              br_if $B5
              i32.const 240
              get_local $p0
              i32.const 0
              get_local $l0
              call $__syscall3
              drop
            end
            get_local $p0
            i32.load
            tee_local $l0
            br_if $L4
          end
        end
        get_local $l1
        i32.const 1073741824
        i32.or
        set_local $l1
      end
      get_local $p0
      get_local $l1
      i32.store
      i32.const 1
      set_local $l0
    end
    get_local $l0)
  (func $__unlockfile (type $t1) (param $p0 i32)
    (local $l0 i32)
    get_local $p0
    i32.const 76
    i32.add
    set_local $p0
    loop $L0
      get_local $p0
      i32.load
      tee_local $l0
      get_local $p0
      i32.load
      i32.ne
      br_if $L0
    end
    get_local $p0
    i32.const 0
    i32.store
    block $B1
      get_local $l0
      i32.const 1073741824
      i32.and
      i32.eqz
      br_if $B1
      i32.const 240
      get_local $p0
      i32.const 129
      i32.const 1
      call $__syscall3
      i32.const -38
      i32.ne
      br_if $B1
      i32.const 240
      get_local $p0
      i32.const 1
      i32.const 1
      call $__syscall3
      drop
    end)
  (func $__towrite (type $t7) (param $p0 i32) (result i32)
    (local $l0 i32)
    get_local $p0
    get_local $p0
    i32.load8_u offset=74
    tee_local $l0
    i32.const -1
    i32.add
    get_local $l0
    i32.or
    i32.store8 offset=74
    block $B0
      get_local $p0
      i32.load
      tee_local $l0
      i32.const 8
      i32.and
      br_if $B0
      get_local $p0
      i64.const 0
      i64.store offset=4 align=4
      get_local $p0
      get_local $p0
      i32.load offset=44
      tee_local $l0
      i32.store offset=28
      get_local $p0
      get_local $l0
      i32.store offset=20
      get_local $p0
      get_local $l0
      get_local $p0
      i32.load offset=48
      i32.add
      i32.store offset=16
      i32.const 0
      return
    end
    get_local $p0
    get_local $l0
    i32.const 32
    i32.or
    i32.store
    i32.const -1)
  (func $fwrite (type $t2) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32)
    i32.const 0
    set_local $l0
    block $B0
      get_local $p3
      i32.load offset=76
      i32.const 0
      i32.lt_s
      br_if $B0
      get_local $p3
      call $__lockfile
      i32.const 0
      i32.ne
      set_local $l0
    end
    get_local $p2
    get_local $p1
    i32.mul
    set_local $l1
    block $B1
      block $B2
        block $B3
          block $B4
            block $B5
              block $B6
                get_local $p3
                i32.load offset=16
                tee_local $l2
                i32.eqz
                br_if $B6
                get_local $l2
                get_local $p3
                i32.load offset=20
                tee_local $l3
                i32.sub
                get_local $l1
                i32.ge_u
                br_if $B5
                br $B3
              end
              i32.const 0
              set_local $l2
              get_local $p3
              call $__towrite
              br_if $B4
              get_local $p3
              i32.const 16
              i32.add
              i32.load
              get_local $p3
              i32.load offset=20
              tee_local $l3
              i32.sub
              get_local $l1
              i32.lt_u
              br_if $B3
            end
            i32.const 0
            set_local $l4
            block $B7
              block $B8
                get_local $p3
                i32.load8_s offset=75
                i32.const 0
                i32.lt_s
                br_if $B8
                get_local $p0
                get_local $l1
                i32.add
                set_local $l5
                i32.const 0
                set_local $l4
                i32.const 0
                set_local $l2
                loop $L9
                  get_local $l1
                  get_local $l2
                  i32.add
                  i32.eqz
                  br_if $B8
                  get_local $l5
                  get_local $l2
                  i32.add
                  set_local $l6
                  get_local $l2
                  i32.const -1
                  i32.add
                  tee_local $l7
                  set_local $l2
                  get_local $l6
                  i32.const -1
                  i32.add
                  i32.load8_u
                  i32.const 10
                  i32.ne
                  br_if $L9
                end
                get_local $p3
                get_local $p0
                get_local $l1
                get_local $l7
                i32.add
                i32.const 1
                i32.add
                tee_local $l4
                get_local $p3
                i32.load offset=36
                call_indirect (type $t0)
                tee_local $l2
                get_local $l4
                i32.lt_u
                br_if $B4
                get_local $l7
                i32.const -1
                i32.xor
                set_local $l2
                get_local $l5
                get_local $l7
                i32.add
                i32.const 1
                i32.add
                set_local $p0
                get_local $p3
                i32.const 20
                i32.add
                i32.load
                set_local $l3
                br $B7
              end
              get_local $l1
              set_local $l2
            end
            get_local $l3
            get_local $p0
            get_local $l2
            call $memcpy
            drop
            get_local $p3
            i32.const 20
            i32.add
            tee_local $l6
            get_local $l6
            i32.load
            get_local $l2
            i32.add
            i32.store
            get_local $l4
            get_local $l2
            i32.add
            set_local $l2
          end
          get_local $l0
          i32.eqz
          br_if $B1
          br $B2
        end
        get_local $p3
        get_local $p0
        get_local $l1
        get_local $p3
        i32.load offset=36
        call_indirect (type $t0)
        set_local $l2
        get_local $l0
        i32.eqz
        br_if $B1
      end
      get_local $p3
      call $__unlockfile
    end
    block $B10
      get_local $l2
      get_local $l1
      i32.ne
      br_if $B10
      get_local $p2
      i32.const 0
      get_local $p1
      select
      return
    end
    get_local $l2
    get_local $p1
    i32.div_u)
  (func $fputs (type $t3) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32)
    i32.const -1
    i32.const 0
    get_local $p0
    call $strlen
    tee_local $l0
    get_local $p0
    i32.const 1
    get_local $l0
    get_local $p1
    call $fwrite
    i32.ne
    select)
  (func $__overflow (type $t3) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store8 offset=15
    block $B0
      block $B1
        block $B2
          block $B3
            get_local $p0
            i32.load offset=16
            tee_local $l1
            i32.eqz
            br_if $B3
            get_local $p0
            i32.load offset=20
            tee_local $l2
            get_local $l1
            i32.ge_u
            br_if $B1
            br $B2
          end
          i32.const -1
          set_local $l1
          get_local $p0
          call $__towrite
          br_if $B0
          get_local $p0
          i32.load offset=20
          tee_local $l2
          get_local $p0
          i32.const 16
          i32.add
          i32.load
          i32.ge_u
          br_if $B1
        end
        get_local $p1
        i32.const 255
        i32.and
        tee_local $l1
        get_local $p0
        i32.load8_s offset=75
        i32.eq
        br_if $B1
        get_local $p0
        i32.const 20
        i32.add
        get_local $l2
        i32.const 1
        i32.add
        i32.store
        get_local $l2
        get_local $p1
        i32.store8
        get_local $l0
        i32.const 16
        i32.add
        set_global $g0
        get_local $l1
        return
      end
      i32.const -1
      set_local $l1
      get_local $p0
      get_local $l0
      i32.const 15
      i32.add
      i32.const 1
      get_local $p0
      i32.load offset=36
      call_indirect (type $t0)
      i32.const 1
      i32.ne
      br_if $B0
      get_local $l0
      i32.load8_u offset=15
      set_local $l1
    end
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    get_local $l1)
  (func $puts (type $t7) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    i32.const 0
    set_local $l0
    block $B0
      i32.const 0
      i32.load offset=1036
      tee_local $l1
      i32.load offset=76
      i32.const 0
      i32.lt_s
      br_if $B0
      get_local $l1
      call $__lockfile
      set_local $l0
    end
    block $B1
      block $B2
        block $B3
          get_local $p0
          get_local $l1
          call $fputs
          i32.const 0
          i32.lt_s
          br_if $B3
          block $B4
            get_local $l1
            i32.load8_u offset=75
            i32.const 10
            i32.eq
            br_if $B4
            get_local $l1
            i32.load offset=20
            tee_local $p0
            get_local $l1
            i32.load offset=16
            i32.ge_u
            br_if $B4
            get_local $l1
            i32.const 20
            i32.add
            get_local $p0
            i32.const 1
            i32.add
            i32.store
            get_local $p0
            i32.const 10
            i32.store8
            i32.const 0
            set_local $p0
            get_local $l0
            br_if $B2
            br $B1
          end
          get_local $l1
          i32.const 10
          call $__overflow
          i32.const 31
          i32.shr_s
          set_local $p0
          get_local $l0
          i32.eqz
          br_if $B1
          br $B2
        end
        i32.const -1
        set_local $p0
        get_local $l0
        i32.eqz
        br_if $B1
      end
      get_local $l1
      call $__unlockfile
    end
    get_local $p0)
  (func $__errno_location (type $t6) (result i32)
    i32.const 31)
  (func $__syscall_ret (type $t7) (param $p0 i32) (result i32)
    block $B0
      get_local $p0
      i32.const -4095
      i32.lt_u
      br_if $B0
      call $__errno_location
      i32.const 0
      get_local $p0
      i32.sub
      i32.store
      i32.const -1
      set_local $p0
    end
    get_local $p0)
  (func $dummy (type $t7) (param $p0 i32) (result i32)
    get_local $p0)
  (func $__stdio_close (type $t7) (param $p0 i32) (result i32)
    i32.const 6
    get_local $p0
    i32.load offset=60
    call $dummy
    call $__syscall1
    call $__syscall_ret)
  (func $__stdio_write (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store offset=8
    get_local $l0
    get_local $p2
    i32.store offset=12
    get_local $l0
    get_local $p0
    i32.load offset=28
    tee_local $p1
    i32.store
    get_local $l0
    get_local $p0
    i32.load offset=20
    get_local $p1
    i32.sub
    tee_local $p1
    i32.store offset=4
    i32.const 2
    set_local $l1
    block $B0
      block $B1
        block $B2
          get_local $p1
          get_local $p2
          i32.add
          tee_local $l2
          i32.const 146
          get_local $p0
          i32.load offset=60
          get_local $l0
          i32.const 2
          call $__syscall3
          call $__syscall_ret
          tee_local $l3
          i32.eq
          br_if $B2
          get_local $l0
          set_local $p1
          get_local $p0
          i32.const 60
          i32.add
          set_local $l4
          loop $L3
            get_local $l3
            i32.const -1
            i32.le_s
            br_if $B1
            get_local $p1
            i32.const 8
            i32.add
            get_local $p1
            get_local $l3
            get_local $p1
            i32.load offset=4
            tee_local $l5
            i32.gt_u
            tee_local $l6
            select
            tee_local $p1
            get_local $p1
            i32.load
            get_local $l3
            get_local $l5
            i32.const 0
            get_local $l6
            select
            i32.sub
            tee_local $l5
            i32.add
            i32.store
            get_local $p1
            get_local $p1
            i32.load offset=4
            get_local $l5
            i32.sub
            i32.store offset=4
            get_local $l2
            get_local $l3
            i32.sub
            set_local $l2
            i32.const 146
            get_local $l4
            i32.load
            get_local $p1
            get_local $l1
            get_local $l6
            i32.sub
            tee_local $l1
            call $__syscall3
            call $__syscall_ret
            tee_local $l6
            set_local $l3
            get_local $l2
            get_local $l6
            i32.ne
            br_if $L3
          end
        end
        get_local $p0
        i32.const 28
        i32.add
        get_local $p0
        i32.load offset=44
        tee_local $p1
        i32.store
        get_local $p0
        i32.const 20
        i32.add
        get_local $p1
        i32.store
        get_local $p0
        get_local $p1
        get_local $p0
        i32.load offset=48
        i32.add
        i32.store offset=16
        get_local $p2
        set_local $l3
        br $B0
      end
      get_local $p0
      i64.const 0
      i64.store offset=16
      i32.const 0
      set_local $l3
      get_local $p0
      i32.const 28
      i32.add
      i32.const 0
      i32.store
      get_local $p0
      get_local $p0
      i32.load
      i32.const 32
      i32.or
      i32.store
      get_local $l1
      i32.const 2
      i32.eq
      br_if $B0
      get_local $p1
      i32.load offset=4
      set_local $p1
      get_local $l0
      i32.const 16
      i32.add
      set_global $g0
      get_local $p2
      get_local $p1
      i32.sub
      return
    end
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    get_local $l3)
  (func $__stdout_write (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.const 1
    i32.store offset=36
    block $B0
      get_local $p0
      i32.load8_u
      i32.const 64
      i32.and
      br_if $B0
      i32.const 54
      get_local $p0
      i32.load offset=60
      i32.const 21523
      get_local $l0
      i32.const 8
      i32.add
      call $__syscall3
      i32.eqz
      br_if $B0
      get_local $p0
      i32.const 255
      i32.store8 offset=75
    end
    get_local $p0
    get_local $p1
    get_local $p2
    call $__stdio_write
    set_local $p0
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    get_local $p0)
  (func $__stdio_seek (type $t8) (param $p0 i32) (param $p1 i64) (param $p2 i32) (result i64)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      i32.const 140
      get_local $p0
      i32.load offset=60
      get_local $p1
      i64.const 32
      i64.shr_u
      i32.wrap/i64
      get_local $p1
      i32.wrap/i64
      get_local $l0
      i32.const 8
      i32.add
      get_local $p2
      call $__syscall5
      call $__syscall_ret
      i32.const 0
      i32.lt_s
      br_if $B0
      get_local $l0
      i64.load offset=8
      set_local $p1
      get_local $l0
      i32.const 16
      i32.add
      set_global $g0
      get_local $p1
      return
    end
    get_local $l0
    i64.const -1
    i64.store offset=8
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    i64.const -1)
  (func $memcpy (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32)
    block $B0
      block $B1
        block $B2
          block $B3
            get_local $p2
            i32.eqz
            br_if $B3
            get_local $p1
            i32.const 3
            i32.and
            i32.eqz
            br_if $B3
            get_local $p0
            set_local $l0
            block $B4
              loop $L5
                get_local $l0
                get_local $p1
                i32.load8_u
                i32.store8
                get_local $p2
                i32.const -1
                i32.add
                set_local $l1
                get_local $l0
                i32.const 1
                i32.add
                set_local $l0
                get_local $p1
                i32.const 1
                i32.add
                set_local $p1
                get_local $p2
                i32.const 1
                i32.eq
                br_if $B4
                get_local $l1
                set_local $p2
                get_local $p1
                i32.const 3
                i32.and
                br_if $L5
              end
            end
            get_local $l0
            i32.const 3
            i32.and
            i32.eqz
            br_if $B2
            br $B1
          end
          get_local $p2
          set_local $l1
          get_local $p0
          tee_local $l0
          i32.const 3
          i32.and
          br_if $B1
        end
        block $B6
          block $B7
            block $B8
              get_local $l1
              i32.const 16
              i32.lt_u
              br_if $B8
              get_local $l0
              get_local $l1
              i32.const -16
              i32.add
              tee_local $l2
              i32.const -16
              i32.and
              tee_local $l4
              i32.const 16
              i32.add
              tee_local $l3
              i32.add
              set_local $l5
              get_local $p1
              set_local $p2
              loop $L9
                get_local $l0
                get_local $p2
                i32.load
                i32.store
                get_local $l0
                i32.const 4
                i32.add
                get_local $p2
                i32.const 4
                i32.add
                i32.load
                i32.store
                get_local $l0
                i32.const 8
                i32.add
                get_local $p2
                i32.const 8
                i32.add
                i32.load
                i32.store
                get_local $l0
                i32.const 12
                i32.add
                get_local $p2
                i32.const 12
                i32.add
                i32.load
                i32.store
                get_local $l0
                i32.const 16
                i32.add
                set_local $l0
                get_local $p2
                i32.const 16
                i32.add
                set_local $p2
                get_local $l1
                i32.const -16
                i32.add
                tee_local $l1
                i32.const 15
                i32.gt_u
                br_if $L9
              end
              get_local $p1
              get_local $l3
              i32.add
              set_local $p1
              i32.const 8
              set_local $l0
              get_local $l2
              get_local $l4
              i32.sub
              tee_local $l1
              i32.const 8
              i32.and
              br_if $B7
              br $B6
            end
            get_local $l0
            set_local $l5
            i32.const 8
            set_local $l0
            get_local $l1
            i32.const 8
            i32.and
            i32.eqz
            br_if $B6
          end
          get_local $l5
          get_local $p1
          i32.load
          i32.store
          get_local $l5
          get_local $p1
          i32.load offset=4
          i32.store offset=4
          get_local $p1
          get_local $l0
          i32.add
          set_local $p1
          get_local $l5
          get_local $l0
          i32.add
          set_local $l5
        end
        block $B10
          block $B11
            block $B12
              block $B13
                get_local $l1
                i32.const 4
                i32.and
                br_if $B13
                i32.const 2
                set_local $l0
                get_local $l1
                i32.const 2
                i32.and
                br_if $B12
                br $B11
              end
              get_local $l5
              get_local $p1
              i32.load
              i32.store
              get_local $p1
              i32.const 4
              i32.add
              set_local $p1
              get_local $l5
              i32.const 4
              i32.add
              set_local $l5
              i32.const 2
              set_local $l0
              get_local $l1
              i32.const 2
              i32.and
              i32.eqz
              br_if $B11
            end
            get_local $l5
            get_local $p1
            i32.load8_u
            i32.store8
            get_local $l5
            get_local $p1
            i32.load8_u offset=1
            i32.store8 offset=1
            get_local $l5
            get_local $l0
            i32.add
            set_local $l5
            get_local $p1
            get_local $l0
            i32.add
            set_local $p1
            get_local $l1
            i32.const 1
            i32.and
            br_if $B10
            br $B0
          end
          get_local $l1
          i32.const 1
          i32.and
          i32.eqz
          br_if $B0
        end
        get_local $l5
        get_local $p1
        i32.load8_u
        i32.store8
        get_local $p0
        return
      end
      block $B14
        block $B15
          block $B16
            block $B17
              block $B18
                block $B19
                  block $B20
                    block $B21
                      block $B22
                        block $B23
                          block $B24
                            block $B25
                              get_local $l1
                              i32.const 32
                              i32.lt_u
                              br_if $B25
                              get_local $l0
                              i32.const 3
                              i32.and
                              tee_local $p2
                              i32.const 3
                              i32.eq
                              br_if $B24
                              get_local $p2
                              i32.const 2
                              i32.eq
                              br_if $B23
                              get_local $p2
                              i32.const 1
                              i32.ne
                              br_if $B25
                              get_local $l0
                              get_local $p1
                              i32.load8_u offset=1
                              i32.store8 offset=1
                              get_local $l0
                              get_local $p1
                              i32.load
                              tee_local $l2
                              i32.store8
                              get_local $l0
                              get_local $p1
                              i32.load8_u offset=2
                              i32.store8 offset=2
                              get_local $p1
                              i32.const 16
                              i32.add
                              set_local $p2
                              get_local $l1
                              i32.const -19
                              i32.add
                              set_local $l3
                              get_local $l1
                              i32.const -3
                              i32.add
                              set_local $l4
                              get_local $l0
                              i32.const 3
                              i32.add
                              set_local $l5
                              get_local $p1
                              get_local $l1
                              i32.const -20
                              i32.add
                              i32.const -16
                              i32.and
                              tee_local $l6
                              i32.const 19
                              i32.add
                              tee_local $l7
                              i32.add
                              set_local $p1
                              loop $L26
                                get_local $l5
                                get_local $p2
                                i32.const -12
                                i32.add
                                i32.load
                                tee_local $l1
                                i32.const 8
                                i32.shl
                                get_local $l2
                                i32.const 24
                                i32.shr_u
                                i32.or
                                i32.store
                                get_local $l5
                                i32.const 4
                                i32.add
                                get_local $p2
                                i32.const -8
                                i32.add
                                i32.load
                                tee_local $l2
                                i32.const 8
                                i32.shl
                                get_local $l1
                                i32.const 24
                                i32.shr_u
                                i32.or
                                i32.store
                                get_local $l5
                                i32.const 8
                                i32.add
                                get_local $p2
                                i32.const -4
                                i32.add
                                i32.load
                                tee_local $l1
                                i32.const 8
                                i32.shl
                                get_local $l2
                                i32.const 24
                                i32.shr_u
                                i32.or
                                i32.store
                                get_local $l5
                                i32.const 12
                                i32.add
                                get_local $p2
                                i32.load
                                tee_local $l2
                                i32.const 8
                                i32.shl
                                get_local $l1
                                i32.const 24
                                i32.shr_u
                                i32.or
                                i32.store
                                get_local $l5
                                i32.const 16
                                i32.add
                                set_local $l5
                                get_local $p2
                                i32.const 16
                                i32.add
                                set_local $p2
                                get_local $l4
                                i32.const -16
                                i32.add
                                tee_local $l4
                                i32.const 16
                                i32.gt_u
                                br_if $L26
                              end
                              get_local $l3
                              get_local $l6
                              i32.sub
                              set_local $l1
                              get_local $l0
                              get_local $l7
                              i32.add
                              set_local $l0
                            end
                            i32.const 16
                            set_local $p2
                            get_local $l1
                            i32.const 16
                            i32.and
                            br_if $B22
                            br $B21
                          end
                          get_local $l0
                          get_local $p1
                          i32.load
                          tee_local $l2
                          i32.store8
                          get_local $p1
                          i32.const 16
                          i32.add
                          set_local $p2
                          get_local $l1
                          i32.const -17
                          i32.add
                          set_local $l3
                          get_local $l1
                          i32.const -1
                          i32.add
                          set_local $l4
                          get_local $l0
                          i32.const 1
                          i32.add
                          set_local $l5
                          get_local $p1
                          get_local $l1
                          i32.const -20
                          i32.add
                          i32.const -16
                          i32.and
                          tee_local $l6
                          i32.const 17
                          i32.add
                          tee_local $l7
                          i32.add
                          set_local $p1
                          loop $L27
                            get_local $l5
                            get_local $p2
                            i32.const -12
                            i32.add
                            i32.load
                            tee_local $l1
                            i32.const 24
                            i32.shl
                            get_local $l2
                            i32.const 8
                            i32.shr_u
                            i32.or
                            i32.store
                            get_local $l5
                            i32.const 4
                            i32.add
                            get_local $p2
                            i32.const -8
                            i32.add
                            i32.load
                            tee_local $l2
                            i32.const 24
                            i32.shl
                            get_local $l1
                            i32.const 8
                            i32.shr_u
                            i32.or
                            i32.store
                            get_local $l5
                            i32.const 8
                            i32.add
                            get_local $p2
                            i32.const -4
                            i32.add
                            i32.load
                            tee_local $l1
                            i32.const 24
                            i32.shl
                            get_local $l2
                            i32.const 8
                            i32.shr_u
                            i32.or
                            i32.store
                            get_local $l5
                            i32.const 12
                            i32.add
                            get_local $p2
                            i32.load
                            tee_local $l2
                            i32.const 24
                            i32.shl
                            get_local $l1
                            i32.const 8
                            i32.shr_u
                            i32.or
                            i32.store
                            get_local $l5
                            i32.const 16
                            i32.add
                            set_local $l5
                            get_local $p2
                            i32.const 16
                            i32.add
                            set_local $p2
                            get_local $l4
                            i32.const -16
                            i32.add
                            tee_local $l4
                            i32.const 18
                            i32.gt_u
                            br_if $L27
                          end
                          get_local $l0
                          get_local $l7
                          i32.add
                          set_local $l0
                          i32.const 16
                          set_local $p2
                          get_local $l3
                          get_local $l6
                          i32.sub
                          tee_local $l1
                          i32.const 16
                          i32.and
                          i32.eqz
                          br_if $B21
                          br $B22
                        end
                        get_local $l0
                        get_local $p1
                        i32.load
                        tee_local $l2
                        i32.store8
                        get_local $l0
                        get_local $p1
                        i32.load8_u offset=1
                        i32.store8 offset=1
                        get_local $p1
                        i32.const 16
                        i32.add
                        set_local $p2
                        get_local $l1
                        i32.const -18
                        i32.add
                        set_local $l3
                        get_local $l1
                        i32.const -2
                        i32.add
                        set_local $l4
                        get_local $l0
                        i32.const 2
                        i32.add
                        set_local $l5
                        get_local $p1
                        get_local $l1
                        i32.const -20
                        i32.add
                        i32.const -16
                        i32.and
                        tee_local $l6
                        i32.const 18
                        i32.add
                        tee_local $l7
                        i32.add
                        set_local $p1
                        loop $L28
                          get_local $l5
                          get_local $p2
                          i32.const -12
                          i32.add
                          i32.load
                          tee_local $l1
                          i32.const 16
                          i32.shl
                          get_local $l2
                          i32.const 16
                          i32.shr_u
                          i32.or
                          i32.store
                          get_local $l5
                          i32.const 4
                          i32.add
                          get_local $p2
                          i32.const -8
                          i32.add
                          i32.load
                          tee_local $l2
                          i32.const 16
                          i32.shl
                          get_local $l1
                          i32.const 16
                          i32.shr_u
                          i32.or
                          i32.store
                          get_local $l5
                          i32.const 8
                          i32.add
                          get_local $p2
                          i32.const -4
                          i32.add
                          i32.load
                          tee_local $l1
                          i32.const 16
                          i32.shl
                          get_local $l2
                          i32.const 16
                          i32.shr_u
                          i32.or
                          i32.store
                          get_local $l5
                          i32.const 12
                          i32.add
                          get_local $p2
                          i32.load
                          tee_local $l2
                          i32.const 16
                          i32.shl
                          get_local $l1
                          i32.const 16
                          i32.shr_u
                          i32.or
                          i32.store
                          get_local $l5
                          i32.const 16
                          i32.add
                          set_local $l5
                          get_local $p2
                          i32.const 16
                          i32.add
                          set_local $p2
                          get_local $l4
                          i32.const -16
                          i32.add
                          tee_local $l4
                          i32.const 17
                          i32.gt_u
                          br_if $L28
                        end
                        get_local $l0
                        get_local $l7
                        i32.add
                        set_local $l0
                        i32.const 16
                        set_local $p2
                        get_local $l3
                        get_local $l6
                        i32.sub
                        tee_local $l1
                        i32.const 16
                        i32.and
                        i32.eqz
                        br_if $B21
                      end
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=1
                      i32.store8 offset=1
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=2
                      i32.store8 offset=2
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=3
                      i32.store8 offset=3
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=4
                      i32.store8 offset=4
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=5
                      i32.store8 offset=5
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=6
                      i32.store8 offset=6
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=7
                      i32.store8 offset=7
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=8
                      i32.store8 offset=8
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=9
                      i32.store8 offset=9
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=10
                      i32.store8 offset=10
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=11
                      i32.store8 offset=11
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=12
                      i32.store8 offset=12
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=13
                      i32.store8 offset=13
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=14
                      i32.store8 offset=14
                      get_local $l0
                      get_local $p1
                      i32.load8_u
                      i32.store8
                      get_local $l0
                      get_local $p1
                      i32.load8_u offset=15
                      i32.store8 offset=15
                      get_local $l0
                      get_local $p2
                      i32.add
                      set_local $l0
                      get_local $p1
                      get_local $p2
                      i32.add
                      set_local $p1
                      i32.const 8
                      set_local $p2
                      get_local $l1
                      i32.const 8
                      i32.and
                      i32.eqz
                      br_if $B20
                      br $B19
                    end
                    i32.const 8
                    set_local $p2
                    get_local $l1
                    i32.const 8
                    i32.and
                    br_if $B19
                  end
                  i32.const 4
                  set_local $p2
                  get_local $l1
                  i32.const 4
                  i32.and
                  br_if $B18
                  br $B17
                end
                get_local $l0
                get_local $p1
                i32.load8_u
                i32.store8
                get_local $l0
                get_local $p1
                i32.load8_u offset=1
                i32.store8 offset=1
                get_local $l0
                get_local $p1
                i32.load8_u offset=2
                i32.store8 offset=2
                get_local $l0
                get_local $p1
                i32.load8_u offset=3
                i32.store8 offset=3
                get_local $l0
                get_local $p1
                i32.load8_u offset=4
                i32.store8 offset=4
                get_local $l0
                get_local $p1
                i32.load8_u offset=5
                i32.store8 offset=5
                get_local $l0
                get_local $p1
                i32.load8_u offset=6
                i32.store8 offset=6
                get_local $l0
                get_local $p1
                i32.load8_u offset=7
                i32.store8 offset=7
                get_local $l0
                get_local $p2
                i32.add
                set_local $l0
                get_local $p1
                get_local $p2
                i32.add
                set_local $p1
                i32.const 4
                set_local $p2
                get_local $l1
                i32.const 4
                i32.and
                i32.eqz
                br_if $B17
              end
              get_local $l0
              get_local $p1
              i32.load8_u
              i32.store8
              get_local $l0
              get_local $p1
              i32.load8_u offset=1
              i32.store8 offset=1
              get_local $l0
              get_local $p1
              i32.load8_u offset=2
              i32.store8 offset=2
              get_local $l0
              get_local $p1
              i32.load8_u offset=3
              i32.store8 offset=3
              get_local $l0
              get_local $p2
              i32.add
              set_local $l0
              get_local $p1
              get_local $p2
              i32.add
              set_local $p1
              i32.const 2
              set_local $p2
              get_local $l1
              i32.const 2
              i32.and
              i32.eqz
              br_if $B16
              br $B15
            end
            i32.const 2
            set_local $p2
            get_local $l1
            i32.const 2
            i32.and
            br_if $B15
          end
          get_local $l1
          i32.const 1
          i32.and
          br_if $B14
          br $B0
        end
        get_local $l0
        get_local $p1
        i32.load8_u
        i32.store8
        get_local $l0
        get_local $p1
        i32.load8_u offset=1
        i32.store8 offset=1
        get_local $l0
        get_local $p2
        i32.add
        set_local $l0
        get_local $p1
        get_local $p2
        i32.add
        set_local $p1
        get_local $l1
        i32.const 1
        i32.and
        i32.eqz
        br_if $B0
      end
      get_local $l0
      get_local $p1
      i32.load8_u
      i32.store8
    end
    get_local $p0)
  (func $strlen (type $t7) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_local $p0
    set_local $l0
    block $B0
      block $B1
        block $B2
          get_local $p0
          i32.const 3
          i32.and
          i32.eqz
          br_if $B2
          get_local $p0
          i32.load8_u
          i32.eqz
          br_if $B1
          get_local $p0
          i32.const 1
          i32.add
          set_local $l0
          loop $L3
            get_local $l0
            i32.const 3
            i32.and
            i32.eqz
            br_if $B2
            get_local $l0
            i32.load8_u
            set_local $l1
            get_local $l0
            i32.const 1
            i32.add
            tee_local $l2
            set_local $l0
            get_local $l1
            br_if $L3
          end
          get_local $l2
          i32.const -1
          i32.add
          get_local $p0
          i32.sub
          return
        end
        get_local $l0
        i32.const -4
        i32.add
        set_local $l0
        loop $L4
          get_local $l0
          i32.const 4
          i32.add
          tee_local $l0
          i32.load
          tee_local $l1
          i32.const -1
          i32.xor
          get_local $l1
          i32.const -16843009
          i32.add
          i32.and
          i32.const -2139062144
          i32.and
          i32.eqz
          br_if $L4
        end
        get_local $l1
        i32.const 255
        i32.and
        i32.eqz
        br_if $B0
        loop $L5
          get_local $l0
          i32.load8_u offset=1
          set_local $l1
          get_local $l0
          i32.const 1
          i32.add
          tee_local $l2
          set_local $l0
          get_local $l1
          br_if $L5
        end
        get_local $l2
        get_local $p0
        i32.sub
        return
      end
      get_local $p0
      get_local $p0
      i32.sub
      return
    end
    get_local $l0
    get_local $p0
    i32.sub)
  (table $T0 5 5 anyfunc)
  (memory $memory (export "memory") 2)
  (global $g0 (mut i32) (i32.const 67760))
  (global $__heap_base (export "__heap_base") i32 (i32.const 67760))
  (global $__data_end (export "__data_end") i32 (i32.const 2216))
  (elem (i32.const 1) $__stdio_write $__stdio_close $__stdout_write $__stdio_seek)
  (data (i32.const 1024) "Hello World\00\10\04\00\00")
  (data (i32.const 1040) "\05\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\04\00\00\00\a8\04\00\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0a\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00")
  (data (i32.const 1184) "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"))
