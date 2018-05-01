(module
  (type $t0 (func))
  (type $t1 (func (param i32 i32) (result i32)))
  (type $t2 (func (param i32 i32)))
  (type $t3 (func (result f64)))
  (type $t4 (func (result i32)))
  (type $t5 (func (param i32 i32 i32 i32)))
  (type $t6 (func (param i32 i32 f64)))
  (import "env" "sayHello" (func $main/sayHello (type $t0)))
  (import "env" "BGR_ALIVE" (global $env.BGR_ALIVE i32))
  (import "env" "BGR_DEAD" (global $env.BGR_DEAD i32))
  (import "env" "BIT_ROT" (global $env.BIT_ROT i32))
  (import "env" "abort" (func $abort (type $t5)))
  (func $main/add (export "add") (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    get_local $p1
    i32.add
    return)
  (func $~lib/math/NativeMath.random (type $t3) (result f64)
    (local $l0 i64) (local $l1 i64) (local $l2 i64)
    get_global $g6
    i32.eqz
    if $I0
      i32.const 0
      i32.const 4
      i32.const 1007
      i32.const 24
      call $abort
      unreachable
    end
    get_global $g7
    set_local $l0
    get_global $g8
    set_local $l1
    get_local $l1
    set_global $g7
    get_local $l0
    get_local $l0
    i64.const 23
    i64.shl
    i64.xor
    set_local $l0
    get_local $l0
    get_local $l0
    i64.const 17
    i64.shr_u
    i64.xor
    set_local $l0
    get_local $l0
    get_local $l1
    i64.xor
    set_local $l0
    get_local $l0
    get_local $l1
    i64.const 26
    i64.shr_u
    i64.xor
    set_local $l0
    get_local $l0
    set_global $g8
    get_local $l1
    get_local $l0
    i64.add
    i64.const 4503599627370495
    i64.and
    i64.const 4607182418800017408
    i64.or
    set_local $l2
    get_local $l2
    f64.reinterpret/i64
    f64.const 0x1p+0 (;=1;)
    f64.sub
    return)
  (func $main/init (export "init") (type $t2) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_local $p0
    set_global $g3
    get_local $p1
    set_global $g4
    get_local $p0
    get_local $p1
    i32.mul
    set_global $g5
    block $B0
      i32.const 0
      set_local $l0
      loop $L1
        get_local $l0
        get_global $g4
        i32.lt_s
        if $I2
          block $B3
            block $B4
              i32.const 0
              set_local $l1
              loop $L5
                get_local $l1
                get_global $g3
                i32.lt_s
                if $I6
                  block $B7
                    block $B8
                      call $~lib/math/NativeMath.random
                      f64.const 0x1.999999999999ap-4 (;=0.1;)
                      f64.gt
                      if $I9 (result i32)
                        get_global $env.BGR_DEAD
                        i32.const 16777215
                        i32.and
                      else
                        get_global $env.BGR_ALIVE
                        i32.const -16777216
                        i32.or
                      end
                      set_local $l2
                      get_global $g5
                      get_local $l0
                      get_global $g3
                      i32.mul
                      i32.add
                      get_local $l1
                      i32.add
                      i32.const 2
                      i32.shl
                      get_local $l2
                      i32.store
                    end
                  end
                  get_local $l1
                  i32.const 1
                  i32.add
                  set_local $l1
                  br $L5
                end
              end
            end
          end
          get_local $l0
          i32.const 1
          i32.add
          set_local $l0
          br $L1
        end
      end
    end)
  (func $main/step (export "step") (type $t0)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i32) (local $l9 i32) (local $l10 i32) (local $l11 i32) (local $l12 i32) (local $l13 i32) (local $l14 i32) (local $l15 i32)
    block $B0
      get_global $g4
      i32.const 1
      i32.sub
      set_local $l0
      get_global $g3
      i32.const 1
      i32.sub
      set_local $l1
    end
    block $B1
      i32.const 0
      set_local $l2
      loop $L2
        get_local $l2
        get_global $g4
        i32.lt_s
        if $I3
          block $B4
            block $B5
              get_local $l2
              i32.const 0
              i32.eq
              if $I6 (result i32)
                get_local $l0
              else
                get_local $l2
                i32.const 1
                i32.sub
              end
              set_local $l3
              get_local $l2
              get_local $l0
              i32.eq
              if $I7 (result i32)
                i32.const 0
              else
                get_local $l2
                i32.const 1
                i32.add
              end
              set_local $l4
            end
            block $B8
              i32.const 0
              set_local $l5
              loop $L9
                get_local $l5
                get_global $g3
                i32.lt_s
                if $I10
                  block $B11
                    block $B12
                      get_local $l5
                      i32.const 0
                      i32.eq
                      if $I13 (result i32)
                        get_local $l1
                      else
                        get_local $l5
                        i32.const 1
                        i32.sub
                      end
                      set_local $l6
                      get_local $l5
                      get_local $l1
                      i32.eq
                      if $I14 (result i32)
                        i32.const 0
                      else
                        get_local $l5
                        i32.const 1
                        i32.add
                      end
                      set_local $l7
                    end
                    block $B15 (result i32)
                      get_local $l3
                      get_global $g3
                      i32.mul
                      get_local $l6
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B15
                    end
                    i32.const 1
                    i32.and
                    block $B16 (result i32)
                      get_local $l3
                      get_global $g3
                      i32.mul
                      get_local $l5
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B16
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B17 (result i32)
                      get_local $l3
                      get_global $g3
                      i32.mul
                      get_local $l7
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B17
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B18 (result i32)
                      get_local $l2
                      get_global $g3
                      i32.mul
                      get_local $l6
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B18
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B19 (result i32)
                      get_local $l2
                      get_global $g3
                      i32.mul
                      get_local $l7
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B19
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B20 (result i32)
                      get_local $l4
                      get_global $g3
                      i32.mul
                      get_local $l6
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B20
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B21 (result i32)
                      get_local $l4
                      get_global $g3
                      i32.mul
                      get_local $l5
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B21
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    block $B22 (result i32)
                      get_local $l4
                      get_global $g3
                      i32.mul
                      get_local $l7
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B22
                    end
                    i32.const 1
                    i32.and
                    i32.add
                    set_local $l8
                    block $B23 (result i32)
                      get_local $l2
                      get_global $g3
                      i32.mul
                      get_local $l5
                      i32.add
                      i32.const 2
                      i32.shl
                      i32.load
                      br $B23
                    end
                    set_local $l9
                    get_local $l9
                    i32.const 1
                    i32.and
                    if $I24
                      get_local $l8
                      i32.const 14
                      i32.and
                      i32.const 2
                      i32.eq
                      if $I25
                        get_local $l9
                        i32.const 24
                        i32.shr_u
                        get_global $env.BIT_ROT
                        i32.sub
                        tee_local $l10
                        i32.const 0
                        tee_local $l11
                        get_local $l10
                        get_local $l11
                        i32.gt_s
                        select
                        set_local $l10
                        block $B26
                          get_local $l10
                          i32.const 24
                          i32.shl
                          get_local $l9
                          i32.const 16777215
                          i32.and
                          i32.or
                          set_local $l11
                          get_global $g5
                          get_local $l2
                          get_global $g3
                          i32.mul
                          i32.add
                          get_local $l5
                          i32.add
                          i32.const 2
                          i32.shl
                          get_local $l11
                          i32.store
                        end
                      else
                        get_global $env.BGR_DEAD
                        i32.const -16777216
                        i32.or
                        set_local $l12
                        get_global $g5
                        get_local $l2
                        get_global $g3
                        i32.mul
                        i32.add
                        get_local $l5
                        i32.add
                        i32.const 2
                        i32.shl
                        get_local $l12
                        i32.store
                      end
                    else
                      get_local $l8
                      i32.const 3
                      i32.eq
                      if $I27
                        get_global $env.BGR_ALIVE
                        i32.const -16777216
                        i32.or
                        set_local $l13
                        get_global $g5
                        get_local $l2
                        get_global $g3
                        i32.mul
                        i32.add
                        get_local $l5
                        i32.add
                        i32.const 2
                        i32.shl
                        get_local $l13
                        i32.store
                      else
                        get_local $l9
                        i32.const 24
                        i32.shr_u
                        get_global $env.BIT_ROT
                        i32.sub
                        tee_local $l14
                        i32.const 0
                        tee_local $l15
                        get_local $l14
                        get_local $l15
                        i32.gt_s
                        select
                        set_local $l14
                        block $B28
                          get_local $l14
                          i32.const 24
                          i32.shl
                          get_local $l9
                          i32.const 16777215
                          i32.and
                          i32.or
                          set_local $l15
                          get_global $g5
                          get_local $l2
                          get_global $g3
                          i32.mul
                          i32.add
                          get_local $l5
                          i32.add
                          i32.const 2
                          i32.shl
                          get_local $l15
                          i32.store
                        end
                      end
                    end
                  end
                  get_local $l5
                  i32.const 1
                  i32.add
                  set_local $l5
                  br $L9
                end
              end
            end
          end
          get_local $l2
          i32.const 1
          i32.add
          set_local $l2
          br $L2
        end
      end
    end)
  (func $main/fill (export "fill") (type $t6) (param $p0 i32) (param $p1 i32) (param $p2 f64)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    block $B0
      i32.const 0
      set_local $l0
      loop $L1
        get_local $l0
        get_global $g3
        i32.lt_s
        if $I2
          block $B3
            call $~lib/math/NativeMath.random
            get_local $p2
            f64.lt
            if $I4
              get_global $env.BGR_ALIVE
              i32.const -16777216
              i32.or
              set_local $l1
              get_global $g5
              get_local $p1
              get_global $g3
              i32.mul
              i32.add
              get_local $l0
              i32.add
              i32.const 2
              i32.shl
              get_local $l1
              i32.store
            end
          end
          get_local $l0
          i32.const 1
          i32.add
          set_local $l0
          br $L1
        end
      end
    end
    block $B5
      i32.const 0
      set_local $l2
      loop $L6
        get_local $l2
        get_global $g4
        i32.lt_s
        if $I7
          block $B8
            call $~lib/math/NativeMath.random
            get_local $p2
            f64.lt
            if $I9
              get_global $env.BGR_ALIVE
              i32.const -16777216
              i32.or
              set_local $l3
              get_global $g5
              get_local $l2
              get_global $g3
              i32.mul
              i32.add
              get_local $p0
              i32.add
              i32.const 2
              i32.shl
              get_local $l3
              i32.store
            end
          end
          get_local $l2
          i32.const 1
          i32.add
          set_local $l2
          br $L6
        end
      end
    end)
  (func $start (type $t0)
    call $main/sayHello)
  (memory $memory (export "memory") 1)
  (global $g3 (mut i32) (i32.const 0))
  (global $g4 (mut i32) (i32.const 0))
  (global $g5 (mut i32) (i32.const 0))
  (global $g6 (mut i32) (i32.const 0))
  (global $g7 (mut i64) (i64.const 0))
  (global $g8 (mut i64) (i64.const 0))
  (global $g9 i32 (i32.const 32))
  (start 7)
  (data (i32.const 4) "\0c\00\00\00~\00l\00i\00b\00/\00m\00a\00t\00h\00.\00t\00s\00"))
