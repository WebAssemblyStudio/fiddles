(module
  (type $t0 (func (param i32 i32 i32) (result i32)))
  (type $t1 (func (param i32 i32) (result i32)))
  (type $t2 (func (param i32)))
  (type $t3 (func (param i32) (result i32)))
  (type $t4 (func (param i32 i32)))
  (type $t5 (func (result i32)))
  (type $t6 (func (param i32 i32 i32)))
  (type $t7 (func (param i32 i32 i32 i32)))
  (type $t8 (func))
  (type $t9 (func (param i32 i32 i64)))
  (type $t10 (func (param i32 i32 i32 i32 i32)))
  (type $t11 (func (param i32 i32 i32 i32 i32) (result i32)))
  (type $t12 (func (param i32) (result i64)))
  (type $t13 (func (param i32 i32 i32 i32 i32 i32 i32) (result i32)))
  (type $t14 (func (param i64 i32) (result i32)))
  (type $t15 (func (param i32 i32 i32 i32) (result i32)))
  (import "env" "memory" (memory $env.memory 2))
  (import "env" "ext_println" (func $ext_println (type $t4)))
  (import "env" "ext_scratch_size" (func $ext_scratch_size (type $t5)))
  (import "env" "ext_scratch_copy" (func $ext_scratch_copy (type $t6)))
  (import "env" "ext_get_storage" (func $ext_get_storage (type $t3)))
  (import "env" "ext_set_storage" (func $ext_set_storage (type $t7)))
  (import "env" "ext_return" (func $ext_return (type $t4)))
  (func $__wasm_call_ctors (type $t8))
  (func $_ZN41_$LT$bool$u20$as$u20$core..fmt..Debug$GT$3fmt17h6e76691aa32b4959E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    i32.const 71653
    i32.const 71648
    get_local $p0
    i32.load8_u
    tee_local $p0
    select
    i32.const 4
    i32.const 5
    get_local $p0
    select
    call $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE)
  (func $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i32) (local $l9 i32) (local $l10 i32) (local $l11 i32)
    get_local $p0
    i32.load offset=16
    set_local $l0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                block $B6
                  block $B7
                    block $B8
                      get_local $p0
                      i32.load offset=8
                      tee_local $l1
                      i32.const 1
                      i32.ne
                      br_if $B8
                      get_local $l0
                      br_if $B7
                      br $B2
                    end
                    get_local $l0
                    i32.eqz
                    br_if $B6
                  end
                  get_local $p2
                  i32.eqz
                  br_if $B5
                  get_local $p1
                  get_local $p2
                  i32.add
                  set_local $l2
                  get_local $p0
                  i32.const 20
                  i32.add
                  i32.load
                  i32.const -1
                  i32.xor
                  set_local $l3
                  i32.const 0
                  set_local $l4
                  get_local $p1
                  set_local $l0
                  get_local $p1
                  set_local $l5
                  loop $L9
                    get_local $l0
                    i32.const 1
                    i32.add
                    set_local $l6
                    block $B10
                      block $B11
                        block $B12
                          block $B13
                            block $B14
                              get_local $l0
                              i32.load8_s
                              tee_local $l7
                              i32.const 0
                              i32.lt_s
                              br_if $B14
                              get_local $l7
                              i32.const 255
                              i32.and
                              set_local $l7
                              br $B13
                            end
                            block $B15
                              block $B16
                                get_local $l6
                                get_local $l2
                                i32.eq
                                br_if $B16
                                get_local $l6
                                i32.load8_u
                                i32.const 63
                                i32.and
                                set_local $l8
                                get_local $l0
                                i32.const 2
                                i32.add
                                tee_local $l0
                                set_local $l6
                                br $B15
                              end
                              i32.const 0
                              set_local $l8
                              get_local $l2
                              set_local $l0
                            end
                            get_local $l7
                            i32.const 31
                            i32.and
                            set_local $l9
                            block $B17
                              block $B18
                                block $B19
                                  get_local $l7
                                  i32.const 255
                                  i32.and
                                  tee_local $l7
                                  i32.const 224
                                  i32.lt_u
                                  br_if $B19
                                  get_local $l0
                                  get_local $l2
                                  i32.eq
                                  br_if $B18
                                  get_local $l0
                                  i32.load8_u
                                  i32.const 63
                                  i32.and
                                  set_local $l10
                                  get_local $l0
                                  i32.const 1
                                  i32.add
                                  tee_local $l6
                                  set_local $l11
                                  br $B17
                                end
                                get_local $l8
                                get_local $l9
                                i32.const 6
                                i32.shl
                                i32.or
                                set_local $l7
                                br $B13
                              end
                              i32.const 0
                              set_local $l10
                              get_local $l2
                              set_local $l11
                            end
                            get_local $l10
                            get_local $l8
                            i32.const 6
                            i32.shl
                            i32.or
                            set_local $l8
                            block $B20
                              get_local $l7
                              i32.const 240
                              i32.lt_u
                              br_if $B20
                              get_local $l11
                              get_local $l2
                              i32.eq
                              br_if $B12
                              get_local $l11
                              i32.const 1
                              i32.add
                              set_local $l0
                              get_local $l11
                              i32.load8_u
                              i32.const 63
                              i32.and
                              set_local $l7
                              br $B11
                            end
                            get_local $l8
                            get_local $l9
                            i32.const 12
                            i32.shl
                            i32.or
                            set_local $l7
                          end
                          get_local $l6
                          set_local $l0
                          get_local $l3
                          i32.const 1
                          i32.add
                          tee_local $l3
                          br_if $B10
                          br $B4
                        end
                        i32.const 0
                        set_local $l7
                        get_local $l6
                        set_local $l0
                      end
                      get_local $l8
                      i32.const 6
                      i32.shl
                      get_local $l9
                      i32.const 18
                      i32.shl
                      i32.const 1835008
                      i32.and
                      i32.or
                      get_local $l7
                      i32.or
                      tee_local $l7
                      i32.const 1114112
                      i32.eq
                      br_if $B3
                      get_local $l3
                      i32.const 1
                      i32.add
                      tee_local $l3
                      i32.eqz
                      br_if $B4
                    end
                    get_local $l4
                    get_local $l5
                    i32.sub
                    get_local $l0
                    i32.add
                    set_local $l4
                    get_local $l0
                    set_local $l5
                    get_local $l2
                    get_local $l0
                    i32.ne
                    br_if $L9
                    br $B3
                  end
                end
                get_local $p0
                i32.load offset=24
                get_local $p1
                get_local $p2
                get_local $p0
                i32.const 28
                i32.add
                i32.load
                i32.load offset=12
                call_indirect (type $t0)
                set_local $l0
                br $B0
              end
              i32.const 0
              set_local $p2
              get_local $l1
              br_if $B2
              br $B1
            end
            get_local $l7
            i32.const 1114112
            i32.eq
            br_if $B3
            block $B21
              block $B22
                get_local $l4
                i32.eqz
                br_if $B22
                get_local $l4
                get_local $p2
                i32.eq
                br_if $B22
                i32.const 0
                set_local $l0
                get_local $l4
                get_local $p2
                i32.ge_u
                br_if $B21
                get_local $p1
                get_local $l4
                i32.add
                i32.load8_s
                i32.const -64
                i32.lt_s
                br_if $B21
              end
              get_local $p1
              set_local $l0
            end
            get_local $l4
            get_local $p2
            get_local $l0
            select
            set_local $p2
            get_local $l0
            get_local $p1
            get_local $l0
            select
            set_local $p1
          end
          get_local $l1
          i32.eqz
          br_if $B1
        end
        i32.const 0
        set_local $l6
        block $B23
          get_local $p2
          i32.eqz
          br_if $B23
          get_local $p2
          set_local $l7
          get_local $p1
          set_local $l0
          loop $L24
            get_local $l6
            get_local $l0
            i32.load8_u
            i32.const 192
            i32.and
            i32.const 128
            i32.eq
            i32.add
            set_local $l6
            get_local $l0
            i32.const 1
            i32.add
            set_local $l0
            get_local $l7
            i32.const -1
            i32.add
            tee_local $l7
            br_if $L24
          end
        end
        block $B25
          block $B26
            block $B27
              block $B28
                get_local $p2
                get_local $l6
                i32.sub
                get_local $p0
                i32.const 12
                i32.add
                i32.load
                tee_local $l3
                i32.ge_u
                br_if $B28
                i32.const 0
                set_local $l6
                block $B29
                  get_local $p2
                  i32.eqz
                  br_if $B29
                  i32.const 0
                  set_local $l6
                  get_local $p2
                  set_local $l7
                  get_local $p1
                  set_local $l0
                  loop $L30
                    get_local $l6
                    get_local $l0
                    i32.load8_u
                    i32.const 192
                    i32.and
                    i32.const 128
                    i32.eq
                    i32.add
                    set_local $l6
                    get_local $l0
                    i32.const 1
                    i32.add
                    set_local $l0
                    get_local $l7
                    i32.const -1
                    i32.add
                    tee_local $l7
                    br_if $L30
                  end
                end
                get_local $l6
                get_local $p2
                i32.sub
                get_local $l3
                i32.add
                set_local $l6
                i32.const 0
                get_local $p0
                i32.load8_u offset=48
                tee_local $l0
                get_local $l0
                i32.const 3
                i32.eq
                select
                tee_local $l0
                i32.const 3
                i32.and
                i32.eqz
                br_if $B27
                get_local $l0
                i32.const 2
                i32.eq
                br_if $B26
                i32.const 0
                set_local $l5
                br $B25
              end
              get_local $p0
              i32.load offset=24
              get_local $p1
              get_local $p2
              get_local $p0
              i32.const 28
              i32.add
              i32.load
              i32.load offset=12
              call_indirect (type $t0)
              return
            end
            get_local $l6
            set_local $l5
            i32.const 0
            set_local $l6
            br $B25
          end
          get_local $l6
          i32.const 1
          i32.add
          i32.const 1
          i32.shr_u
          set_local $l5
          get_local $l6
          i32.const 1
          i32.shr_u
          set_local $l6
        end
        i32.const -1
        set_local $l0
        get_local $p0
        i32.const 4
        i32.add
        set_local $l7
        get_local $p0
        i32.const 24
        i32.add
        set_local $l3
        get_local $p0
        i32.const 28
        i32.add
        set_local $l4
        block $B31
          loop $L32
            get_local $l0
            i32.const 1
            i32.add
            tee_local $l0
            get_local $l6
            i32.ge_u
            br_if $B31
            get_local $l3
            i32.load
            get_local $l7
            i32.load
            get_local $l4
            i32.load
            i32.load offset=16
            call_indirect (type $t1)
            i32.eqz
            br_if $L32
          end
          i32.const 1
          return
        end
        get_local $p0
        i32.const 4
        i32.add
        i32.load
        set_local $l6
        i32.const 1
        set_local $l0
        get_local $p0
        i32.const 24
        i32.add
        tee_local $l7
        i32.load
        get_local $p1
        get_local $p2
        get_local $p0
        i32.const 28
        i32.add
        tee_local $l3
        i32.load
        i32.load offset=12
        call_indirect (type $t0)
        br_if $B0
        get_local $l7
        i32.load
        set_local $l7
        i32.const -1
        set_local $l0
        get_local $l3
        i32.load
        i32.const 16
        i32.add
        set_local $l3
        block $B33
          loop $L34
            get_local $l0
            i32.const 1
            i32.add
            tee_local $l0
            get_local $l5
            i32.ge_u
            br_if $B33
            get_local $l7
            get_local $l6
            get_local $l3
            i32.load
            call_indirect (type $t1)
            i32.eqz
            br_if $L34
          end
          i32.const 1
          return
        end
        i32.const 0
        return
      end
      get_local $p0
      i32.load offset=24
      get_local $p1
      get_local $p2
      get_local $p0
      i32.const 28
      i32.add
      i32.load
      i32.load offset=12
      call_indirect (type $t0)
      return
    end
    get_local $l0)
  (func $_ZN4core3ops8function6FnOnce9call_once17h37b6823600c7a586E (type $t2) (param $p0 i32)
    get_local $p0
    i32.const 248
    i32.add
    tee_local $p0
    i32.const 0
    call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$6update17hb32ac69eded81739E
    get_local $p0
    call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$10mark_dirty17h7b287827a02caaefE)
  (func $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$6update17hb32ac69eded81739E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h8c7fc7631aa63753E
    get_local $l0
    i32.load offset=12
    set_local $p0
    block $B0
      block $B1
        block $B2
          get_local $l0
          i32.load offset=8
          tee_local $l1
          i32.load8_u offset=4
          i32.const 2
          i32.ne
          br_if $B2
          i32.const 1
          i32.const 1
          call $__rust_alloc
          tee_local $l2
          i32.eqz
          br_if $B0
          get_local $l2
          get_local $p1
          i32.store8
          get_local $l1
          i32.const 4
          i32.add
          i32.const 0
          i32.store8
          get_local $l1
          get_local $l2
          i32.store
          br $B1
        end
        get_local $l1
        i32.load
        get_local $p1
        i32.store8
      end
      get_local $p0
      get_local $p0
      i32.load
      i32.const 1
      i32.add
      i32.store
      get_local $l0
      i32.const 16
      i32.add
      set_global $g0
      return
    end
    unreachable
    unreachable)
  (func $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$10mark_dirty17h7b287827a02caaefE (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h8c7fc7631aa63753E
    get_local $l0
    i32.load offset=12
    set_local $p0
    block $B0
      get_local $l0
      i32.load offset=8
      tee_local $l1
      i32.load8_u offset=4
      i32.const 2
      i32.eq
      br_if $B0
      get_local $l1
      i32.const 4
      i32.add
      i32.const 1
      i32.store8
    end
    get_local $p0
    get_local $p0
    i32.load
    i32.const 1
    i32.add
    i32.store
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $_ZN4core3ops8function6FnOnce9call_once17h7e1ab6538c08cd8dE (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32)
    get_local $p0
    i32.const 248
    i32.add
    tee_local $l0
    call $_ZN84_$LT$ink_core..storage..value..Value$LT$T$GT$$u20$as$u20$core..ops..deref..Deref$GT$5deref17hf987e48061096926E
    i32.load8_u
    set_local $l1
    block $B0
      get_local $l0
      call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$9is_synced17h5ab65817635a69f0E
      br_if $B0
      get_local $l0
      get_local $p0
      i32.const 260
      i32.add
      call $_ZN8ink_core7storage4cell10typed_cell18TypedCell$LT$T$GT$4load17h12f7f7b4815424c2E
      i32.const 255
      i32.and
      call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$6update17hb32ac69eded81739E
    end
    get_local $l0
    call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$10mark_dirty17h7b287827a02caaefE
    block $B1
      get_local $l0
      call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$7get_mut17h39b18010dee025e7E
      tee_local $l0
      i32.eqz
      br_if $B1
      get_local $l0
      get_local $l1
      i32.const 1
      i32.xor
      i32.store8
      return
    end
    i32.const 72220
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $_ZN84_$LT$ink_core..storage..value..Value$LT$T$GT$$u20$as$u20$core..ops..deref..Deref$GT$5deref17hf987e48061096926E (type $t3) (param $p0 i32) (result i32)
    block $B0
      get_local $p0
      call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$9is_synced17h5ab65817635a69f0E
      br_if $B0
      get_local $p0
      get_local $p0
      i32.const 12
      i32.add
      call $_ZN8ink_core7storage4cell10typed_cell18TypedCell$LT$T$GT$4load17h12f7f7b4815424c2E
      i32.const 255
      i32.and
      call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$6update17hb32ac69eded81739E
    end
    block $B1
      block $B2
        get_local $p0
        i32.const 8
        i32.add
        i32.load8_u
        i32.const 2
        i32.eq
        br_if $B2
        get_local $p0
        i32.load offset=4
        tee_local $p0
        i32.load8_u
        i32.const 2
        i32.eq
        br_if $B1
        get_local $p0
        return
      end
      i32.const 72005
      i32.const 88
      i32.const 72096
      call $_ZN3std9panicking11begin_panic17h59137bcd87980b1bE
      unreachable
    end
    i32.const 72220
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$9is_synced17h5ab65817635a69f0E (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core4cell16RefCell$LT$T$GT$6borrow17h3e3607e87caa3ca8E
    get_local $l0
    i32.load offset=8
    i32.load8_u offset=4
    set_local $p0
    get_local $l0
    i32.load offset=12
    tee_local $l1
    get_local $l1
    i32.load
    i32.const -1
    i32.add
    i32.store
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    get_local $p0
    i32.const 2
    i32.ne)
  (func $_ZN8ink_core7storage4cell10typed_cell18TypedCell$LT$T$GT$4load17h12f7f7b4815424c2E (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    call $_ZN8ink_core7storage4cell8raw_cell7RawCell4load17hf9358592e2a91478E
    block $B0
      block $B1
        block $B2
          block $B3
            get_local $l0
            i32.load
            i32.eqz
            br_if $B3
            get_local $l0
            i32.const 16
            i32.add
            i32.const 8
            i32.add
            tee_local $p0
            get_local $l0
            i32.const 8
            i32.add
            i32.load
            i32.store
            get_local $l0
            get_local $l0
            i64.load
            i64.store offset=16
            get_local $l0
            get_local $p0
            i32.load
            i32.store offset=36
            get_local $l0
            get_local $l0
            i32.load offset=16
            i32.store offset=32
            get_local $l0
            i32.const 0
            i32.store8 offset=47
            get_local $l0
            i32.const 32
            i32.add
            get_local $l0
            i32.const 47
            i32.add
            i32.const 1
            call $_ZN48_$LT$R$u20$as$u20$parity_codec..codec..Input$GT$4read17h27a72c68ffbec25dE
            i32.const 1
            i32.ne
            br_if $B2
            get_local $l0
            i32.load8_u offset=47
            set_local $p0
            br $B1
          end
          i32.const 2
          set_local $p0
          br $B0
        end
        i32.const 2
        set_local $p0
      end
      get_local $l0
      i32.const 16
      i32.add
      call $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE.651
    end
    get_local $l0
    i32.const 48
    i32.add
    set_global $g0
    get_local $p0)
  (func $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$7get_mut17h39b18010dee025e7E (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32)
    block $B0
      get_local $p0
      i32.const 8
      i32.add
      tee_local $l0
      i32.load8_u
      i32.const 2
      i32.eq
      br_if $B0
      get_local $l0
      i32.const 1
      i32.store8
      i32.const 0
      get_local $p0
      i32.load offset=4
      tee_local $p0
      get_local $p0
      i32.load8_u
      i32.const 2
      i32.eq
      select
      return
    end
    i32.const 71765
    i32.const 92
    i32.const 71860
    call $_ZN3std9panicking11begin_panic17h59137bcd87980b1bE
    unreachable)
  (func $_ZN4core9panicking5panic17ha366c5556fbdacabE (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i64) (local $l2 i64) (local $l3 i64)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i64.load offset=8 align=4
    set_local $l1
    get_local $p0
    i64.load offset=16 align=4
    set_local $l2
    get_local $p0
    i64.load align=4
    set_local $l3
    get_local $l0
    i32.const 20
    i32.add
    i32.const 0
    i32.store
    get_local $l0
    get_local $l3
    i64.store offset=24
    get_local $l0
    i32.const 66356
    i32.store offset=16
    get_local $l0
    i64.const 1
    i64.store offset=4 align=4
    get_local $l0
    get_local $l0
    i32.const 24
    i32.add
    i32.store
    get_local $l0
    get_local $l2
    i64.store offset=40
    get_local $l0
    get_local $l1
    i64.store offset=32
    get_local $l0
    get_local $l0
    i32.const 32
    i32.add
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN4core3ops8function6FnOnce9call_once17he980da835ebbfea8E (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.const 248
    i32.add
    tee_local $p0
    call $_ZN84_$LT$ink_core..storage..value..Value$LT$T$GT$$u20$as$u20$core..ops..deref..Deref$GT$5deref17hf987e48061096926E
    set_local $l1
    get_local $l0
    i32.const 1
    i32.store offset=4
    get_local $l0
    get_local $l1
    i32.store
    block $B0
      block $B1
        i32.const 30
        i32.const 1
        call $__rust_alloc
        tee_local $l1
        i32.eqz
        br_if $B1
        get_local $l0
        i64.const 30
        i64.store offset=12 align=4
        get_local $l0
        get_local $l1
        i32.store offset=8
        get_local $l0
        get_local $l0
        i32.const 8
        i32.add
        i32.store offset=20
        get_local $l0
        i32.const 44
        i32.add
        i32.const 1
        i32.store
        get_local $l0
        i64.const 1
        i64.store offset=28 align=4
        get_local $l0
        i32.const 65552
        i32.store offset=24
        get_local $l0
        get_local $l0
        i32.store offset=40
        get_local $l0
        i32.const 20
        i32.add
        i32.const 66208
        get_local $l0
        i32.const 24
        i32.add
        call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
        br_if $B0
        get_local $l0
        i32.load offset=12
        set_local $l1
        get_local $l0
        i32.load offset=8
        tee_local $l2
        get_local $l0
        i32.load offset=16
        call $ext_println
        get_local $l2
        get_local $l1
        call $_ZN77_$LT$alloc..raw_vec..RawVec$LT$T$C$A$GT$$u20$as$u20$core..ops..drop..Drop$GT$4drop17h6fdbf669a9da6c0eE
        get_local $p0
        call $_ZN84_$LT$ink_core..storage..value..Value$LT$T$GT$$u20$as$u20$core..ops..deref..Deref$GT$5deref17hf987e48061096926E
        i32.load8_u
        set_local $p0
        get_local $l0
        i32.const 48
        i32.add
        set_global $g0
        get_local $p0
        return
      end
      unreachable
      unreachable
    end
    call $_ZN4core6result13unwrap_failed17hc1c6234df9a85c7bE
    unreachable)
  (func $__rust_alloc (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    get_local $p1
    call $__rdl_alloc)
  (func $_ZN4core3fmt5write17h169d0abdd64fe5b9E (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i32) (local $l9 i32)
    get_global $g0
    i32.const 64
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 36
    i32.add
    get_local $p1
    i32.store
    get_local $l0
    i32.const 52
    i32.add
    get_local $p2
    i32.const 20
    i32.add
    i32.load
    tee_local $l1
    i32.store
    get_local $l0
    i32.const 3
    i32.store8 offset=56
    get_local $l0
    i32.const 44
    i32.add
    get_local $p2
    i32.load offset=16
    tee_local $l2
    get_local $l1
    i32.const 3
    i32.shl
    i32.add
    i32.store
    get_local $l0
    i64.const 137438953472
    i64.store offset=8
    get_local $l0
    get_local $p0
    i32.store offset=32
    i32.const 0
    set_local $l3
    get_local $l0
    i32.const 0
    i32.store offset=24
    get_local $l0
    i32.const 0
    i32.store offset=16
    get_local $l0
    get_local $l2
    i32.store offset=48
    get_local $l0
    get_local $l2
    i32.store offset=40
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p2
              i32.load offset=8
              tee_local $l4
              i32.eqz
              br_if $B4
              get_local $p2
              i32.load
              set_local $l5
              get_local $p2
              i32.load offset=4
              tee_local $l6
              get_local $p2
              i32.const 12
              i32.add
              i32.load
              tee_local $l2
              get_local $l2
              get_local $l6
              i32.gt_u
              select
              tee_local $l7
              i32.eqz
              br_if $B3
              get_local $p0
              get_local $l5
              i32.load
              get_local $l5
              i32.load offset=4
              get_local $p1
              i32.load offset=12
              call_indirect (type $t0)
              br_if $B2
              get_local $l5
              i32.const 8
              i32.add
              set_local $l2
              get_local $l0
              i32.const 56
              i32.add
              set_local $p1
              get_local $l0
              i32.const 52
              i32.add
              set_local $l8
              get_local $l0
              i32.const 48
              i32.add
              set_local $l9
              i32.const 1
              set_local $l3
              block $B5
                loop $L6
                  get_local $p1
                  get_local $l4
                  i32.const 32
                  i32.add
                  i32.load8_u
                  i32.store8
                  get_local $l0
                  get_local $l4
                  i32.const 8
                  i32.add
                  i32.load
                  i32.store offset=12
                  get_local $l0
                  get_local $l4
                  i32.const 12
                  i32.add
                  i32.load
                  i32.store offset=8
                  i32.const 0
                  set_local $p2
                  block $B7
                    block $B8
                      block $B9
                        block $B10
                          block $B11
                            get_local $l4
                            i32.const 24
                            i32.add
                            i32.load
                            tee_local $p0
                            i32.const 1
                            i32.eq
                            br_if $B11
                            block $B12
                              get_local $p0
                              i32.const 2
                              i32.eq
                              br_if $B12
                              get_local $p0
                              i32.const 3
                              i32.eq
                              br_if $B7
                              get_local $l4
                              i32.const 28
                              i32.add
                              i32.load
                              set_local $l1
                              br $B10
                            end
                            get_local $l0
                            i32.const 8
                            i32.add
                            i32.const 32
                            i32.add
                            tee_local $l1
                            i32.load
                            tee_local $p0
                            get_local $l0
                            i32.const 8
                            i32.add
                            i32.const 36
                            i32.add
                            i32.load
                            i32.eq
                            br_if $B9
                            get_local $l1
                            get_local $p0
                            i32.const 8
                            i32.add
                            i32.store
                            get_local $p0
                            i32.load offset=4
                            i32.const 2
                            i32.ne
                            br_if $B7
                            get_local $p0
                            i32.load
                            i32.load
                            set_local $l1
                            br $B10
                          end
                          get_local $l4
                          i32.const 28
                          i32.add
                          i32.load
                          tee_local $p0
                          get_local $l8
                          i32.load
                          tee_local $l1
                          i32.ge_u
                          br_if $B8
                          get_local $l9
                          i32.load
                          get_local $p0
                          i32.const 3
                          i32.shl
                          i32.add
                          tee_local $p0
                          i32.load offset=4
                          i32.const 2
                          i32.ne
                          br_if $B7
                          get_local $p0
                          i32.load
                          i32.load
                          set_local $l1
                        end
                        i32.const 1
                        set_local $p2
                        br $B7
                      end
                      br $B7
                    end
                    i32.const 67036
                    get_local $p0
                    get_local $l1
                    call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
                    unreachable
                  end
                  get_local $l0
                  i32.const 8
                  i32.add
                  i32.const 12
                  i32.add
                  get_local $l1
                  i32.store
                  get_local $l0
                  i32.const 8
                  i32.add
                  i32.const 8
                  i32.add
                  get_local $p2
                  i32.store
                  i32.const 0
                  set_local $p2
                  block $B13
                    block $B14
                      block $B15
                        block $B16
                          block $B17
                            get_local $l4
                            i32.const 16
                            i32.add
                            i32.load
                            tee_local $p0
                            i32.const 1
                            i32.eq
                            br_if $B17
                            block $B18
                              get_local $p0
                              i32.const 2
                              i32.eq
                              br_if $B18
                              get_local $p0
                              i32.const 3
                              i32.eq
                              br_if $B13
                              get_local $l4
                              i32.const 20
                              i32.add
                              i32.load
                              set_local $l1
                              br $B16
                            end
                            get_local $l0
                            i32.const 8
                            i32.add
                            i32.const 32
                            i32.add
                            tee_local $l1
                            i32.load
                            tee_local $p0
                            get_local $l0
                            i32.const 8
                            i32.add
                            i32.const 36
                            i32.add
                            i32.load
                            i32.eq
                            br_if $B15
                            get_local $l1
                            get_local $p0
                            i32.const 8
                            i32.add
                            i32.store
                            get_local $p0
                            i32.load offset=4
                            i32.const 2
                            i32.ne
                            br_if $B13
                            get_local $p0
                            i32.load
                            i32.load
                            set_local $l1
                            br $B16
                          end
                          get_local $l4
                          i32.const 20
                          i32.add
                          i32.load
                          tee_local $p0
                          get_local $l8
                          i32.load
                          tee_local $l1
                          i32.ge_u
                          br_if $B14
                          get_local $l9
                          i32.load
                          get_local $p0
                          i32.const 3
                          i32.shl
                          i32.add
                          tee_local $p0
                          i32.load offset=4
                          i32.const 2
                          i32.ne
                          br_if $B13
                          get_local $p0
                          i32.load
                          i32.load
                          set_local $l1
                        end
                        i32.const 1
                        set_local $p2
                        br $B13
                      end
                      br $B13
                    end
                    i32.const 67036
                    get_local $p0
                    get_local $l1
                    call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
                    unreachable
                  end
                  get_local $l0
                  i32.const 8
                  i32.add
                  i32.const 20
                  i32.add
                  get_local $l1
                  i32.store
                  get_local $l0
                  i32.const 8
                  i32.add
                  i32.const 16
                  i32.add
                  get_local $p2
                  i32.store
                  block $B19
                    block $B20
                      block $B21
                        get_local $l4
                        i32.load
                        i32.const 1
                        i32.ne
                        br_if $B21
                        get_local $l4
                        i32.const 4
                        i32.add
                        i32.load
                        tee_local $p2
                        get_local $l8
                        i32.load
                        tee_local $l1
                        i32.ge_u
                        br_if $B19
                        get_local $l9
                        i32.load
                        get_local $p2
                        i32.const 3
                        i32.shl
                        i32.add
                        set_local $p2
                        br $B20
                      end
                      get_local $l0
                      i32.const 8
                      i32.add
                      i32.const 32
                      i32.add
                      tee_local $l1
                      i32.load
                      tee_local $p2
                      get_local $l0
                      i32.const 8
                      i32.add
                      i32.const 36
                      i32.add
                      i32.load
                      i32.eq
                      br_if $B5
                      get_local $l1
                      get_local $p2
                      i32.const 8
                      i32.add
                      i32.store
                    end
                    get_local $p2
                    i32.load
                    get_local $l0
                    i32.const 8
                    i32.add
                    get_local $p2
                    i32.const 4
                    i32.add
                    i32.load
                    call_indirect (type $t1)
                    br_if $B2
                    get_local $l3
                    get_local $l7
                    i32.ge_u
                    br_if $B3
                    get_local $l2
                    i32.const 4
                    i32.add
                    set_local $p2
                    get_local $l2
                    i32.load
                    set_local $l1
                    get_local $l2
                    i32.const 8
                    i32.add
                    set_local $l2
                    get_local $l4
                    i32.const 36
                    i32.add
                    set_local $l4
                    get_local $l3
                    i32.const 1
                    i32.add
                    set_local $l3
                    get_local $l0
                    i32.const 8
                    i32.add
                    i32.const 24
                    i32.add
                    i32.load
                    get_local $l1
                    get_local $p2
                    i32.load
                    get_local $l0
                    i32.const 8
                    i32.add
                    i32.const 28
                    i32.add
                    i32.load
                    i32.load offset=12
                    call_indirect (type $t0)
                    i32.eqz
                    br_if $L6
                    br $B2
                  end
                end
                i32.const 67052
                get_local $p2
                get_local $l1
                call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
                unreachable
              end
              i32.const 72220
              call $_ZN4core9panicking5panic17ha366c5556fbdacabE
              unreachable
            end
            get_local $p2
            i32.load
            set_local $l5
            get_local $p2
            i32.load offset=4
            tee_local $l6
            get_local $l1
            get_local $l1
            get_local $l6
            i32.gt_u
            select
            tee_local $l7
            i32.eqz
            br_if $B3
            get_local $p0
            get_local $l5
            i32.load
            get_local $l5
            i32.load offset=4
            get_local $p1
            i32.load offset=12
            call_indirect (type $t0)
            br_if $B2
            get_local $l5
            i32.const 8
            i32.add
            set_local $l4
            get_local $l0
            i32.const 32
            i32.add
            set_local $p0
            get_local $l0
            i32.const 36
            i32.add
            set_local $p1
            i32.const 1
            set_local $l3
            loop $L22
              get_local $l2
              i32.load
              get_local $l0
              i32.const 8
              i32.add
              get_local $l2
              i32.const 4
              i32.add
              i32.load
              call_indirect (type $t1)
              br_if $B2
              get_local $l3
              get_local $l7
              i32.ge_u
              br_if $B3
              get_local $l4
              i32.const 4
              i32.add
              set_local $p2
              get_local $l4
              i32.load
              set_local $l1
              get_local $l2
              i32.const 8
              i32.add
              set_local $l2
              get_local $l4
              i32.const 8
              i32.add
              set_local $l4
              get_local $l3
              i32.const 1
              i32.add
              set_local $l3
              get_local $p0
              i32.load
              get_local $l1
              get_local $p2
              i32.load
              get_local $p1
              i32.load
              i32.load offset=12
              call_indirect (type $t0)
              i32.eqz
              br_if $L22
              br $B2
            end
          end
          get_local $l6
          get_local $l3
          i32.le_u
          br_if $B1
          get_local $l0
          i32.const 32
          i32.add
          i32.load
          get_local $l5
          get_local $l3
          i32.const 3
          i32.shl
          i32.add
          tee_local $l4
          i32.load
          get_local $l4
          i32.load offset=4
          get_local $l0
          i32.const 36
          i32.add
          i32.load
          i32.load offset=12
          call_indirect (type $t0)
          i32.eqz
          br_if $B1
        end
        i32.const 1
        set_local $l4
        br $B0
      end
      i32.const 0
      set_local $l4
    end
    get_local $l0
    i32.const 64
    i32.add
    set_global $g0
    get_local $l4)
  (func $_ZN77_$LT$alloc..raw_vec..RawVec$LT$T$C$A$GT$$u20$as$u20$core..ops..drop..Drop$GT$4drop17h6fdbf669a9da6c0eE (type $t4) (param $p0 i32) (param $p1 i32)
    block $B0
      get_local $p1
      i32.eqz
      br_if $B0
      get_local $p0
      call $__rust_dealloc
    end)
  (func $_ZN4core6result13unwrap_failed17hc1c6234df9a85c7bE (type $t8)
    (local $l0 i32)
    get_global $g0
    i32.const 64
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 51
    i32.store offset=12
    get_local $l0
    i32.const 66232
    i32.store offset=8
    get_local $l0
    i32.const 52
    i32.add
    i32.const 3
    i32.store
    get_local $l0
    i32.const 36
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 4
    i32.store offset=44
    get_local $l0
    i64.const 2
    i64.store offset=20 align=4
    get_local $l0
    i32.const 66284
    i32.store offset=16
    get_local $l0
    get_local $l0
    i32.const 56
    i32.add
    i32.store offset=48
    get_local $l0
    get_local $l0
    i32.const 8
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.const 40
    i32.add
    i32.store offset=32
    get_local $l0
    i32.const 16
    i32.add
    i32.const 66300
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN7flipper7Flipper11instantiate17hd130ac1ff94dabe1E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    get_global $g0
    i32.const 448
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    i32.const 24
    i32.add
    i64.const 0
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 16
    i32.add
    i64.const 0
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 8
    i32.add
    i64.const 0
    i64.store
    get_local $l0
    i64.const 0
    i64.store offset=8
    get_local $l0
    i32.const 40
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN128_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hd3b8aaf0dbecc3d7E
    get_local $l0
    i32.const 288
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN128_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hd3b8aaf0dbecc3d7E
    get_local $l0
    i32.const 384
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    i64.const 4294967295
    call $_ZN110_$LT$ink_core..storage..alloc..bump_alloc..BumpAlloc$u20$as$u20$ink_core..storage..alloc..traits..Allocate$GT$5alloc17h4497b6fb796ce12bE
    get_local $l0
    i32.const 416
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    i64.const 4294967295
    call $_ZN110_$LT$ink_core..storage..alloc..bump_alloc..BumpAlloc$u20$as$u20$ink_core..storage..alloc..traits..Allocate$GT$5alloc17h4497b6fb796ce12bE
    get_local $l0
    i32.const 40
    i32.add
    i32.const 92
    i32.add
    get_local $l0
    i32.const 288
    i32.add
    i32.const 92
    call $memcpy
    drop
    get_local $l0
    i32.const 248
    i32.add
    get_local $l0
    i32.const 384
    i32.add
    i32.const 24
    i32.add
    i64.load
    i64.store
    get_local $l0
    i32.const 240
    i32.add
    get_local $l0
    i32.const 384
    i32.add
    i32.const 16
    i32.add
    i64.load
    i64.store
    get_local $l0
    i32.const 232
    i32.add
    get_local $l0
    i32.const 384
    i32.add
    i32.const 8
    i32.add
    i64.load
    i64.store
    get_local $l0
    i32.const 264
    i32.add
    get_local $l0
    i32.const 416
    i32.add
    i32.const 8
    i32.add
    tee_local $l1
    i64.load
    i64.store
    get_local $l0
    i32.const 272
    i32.add
    get_local $l0
    i32.const 416
    i32.add
    i32.const 16
    i32.add
    tee_local $l2
    i64.load
    i64.store
    get_local $l0
    i32.const 280
    i32.add
    get_local $l0
    i32.const 416
    i32.add
    i32.const 24
    i32.add
    tee_local $l3
    i64.load
    i64.store
    get_local $l0
    get_local $l0
    i64.load offset=384
    i64.store offset=224
    get_local $l0
    get_local $l0
    i64.load offset=416
    i64.store offset=256
    get_local $l0
    i32.const 416
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN110_$LT$ink_core..storage..cell..raw_cell..RawCell$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hfd6dd993fdac8296E
    get_local $l0
    i32.const 315
    i32.add
    get_local $l3
    i64.load
    i64.store align=1
    get_local $l0
    i32.const 307
    i32.add
    get_local $l2
    i64.load
    i64.store align=1
    get_local $l0
    i32.const 299
    i32.add
    get_local $l1
    i64.load
    i64.store align=1
    get_local $l0
    get_local $l0
    i64.load offset=416
    i64.store offset=291 align=1
    get_local $p0
    get_local $l0
    i32.const 40
    i32.add
    i32.const 248
    call $memcpy
    tee_local $p0
    i32.const 256
    i32.add
    i32.const 2
    i32.store8
    get_local $p0
    i32.const 0
    i32.store offset=248
    get_local $p0
    i32.const 257
    i32.add
    get_local $l0
    i32.const 288
    i32.add
    i32.const 35
    call $memcpy
    drop
    get_local $p0
    i32.const 300
    i32.add
    i32.const 5
    i32.store
    get_local $p0
    i32.const 6
    i32.store offset=296
    get_local $p0
    i32.const 7
    i32.store offset=292
    get_local $l0
    i32.const 448
    i32.add
    set_global $g0)
  (func $_ZN128_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hd3b8aaf0dbecc3d7E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    call $_ZN110_$LT$ink_core..storage..cell..raw_cell..RawCell$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hfd6dd993fdac8296E
    get_local $p0
    i32.const 8
    i32.add
    i32.const 2
    i32.store8
    get_local $p0
    i32.const 0
    i32.store
    get_local $p0
    i32.const 36
    i32.add
    get_local $l0
    i32.const 24
    i32.add
    tee_local $l1
    i64.load
    i64.store align=1
    get_local $p0
    i32.const 28
    i32.add
    get_local $l0
    i32.const 16
    i32.add
    tee_local $l2
    i64.load
    i64.store align=1
    get_local $p0
    i32.const 20
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    tee_local $l3
    i64.load
    i64.store align=1
    get_local $p0
    get_local $l0
    i64.load
    i64.store offset=12 align=1
    get_local $l0
    get_local $p1
    i64.const 4294967295
    call $_ZN110_$LT$ink_core..storage..alloc..bump_alloc..BumpAlloc$u20$as$u20$ink_core..storage..alloc..traits..Allocate$GT$5alloc17h4497b6fb796ce12bE
    get_local $p0
    i32.const 52
    i32.add
    i64.const 0
    i64.store align=4
    get_local $p0
    i32.const 48
    i32.add
    i32.const 66088
    i32.store
    get_local $p0
    i32.const 0
    i32.store offset=44
    get_local $p0
    i32.const 60
    i32.add
    get_local $l0
    i64.load align=4
    i64.store align=4
    get_local $p0
    i32.const 68
    i32.add
    get_local $l3
    i64.load align=4
    i64.store align=4
    get_local $p0
    i32.const 76
    i32.add
    get_local $l2
    i64.load align=4
    i64.store align=4
    get_local $p0
    i32.const 84
    i32.add
    get_local $l1
    i64.load align=4
    i64.store align=4
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0)
  (func $_ZN110_$LT$ink_core..storage..alloc..bump_alloc..BumpAlloc$u20$as$u20$ink_core..storage..alloc..traits..Allocate$GT$5alloc17h4497b6fb796ce12bE (type $t9) (param $p0 i32) (param $p1 i32) (param $p2 i64)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    get_global $g0
    set_local $l0
    get_local $p0
    get_local $p1
    i64.load align=1
    i64.store align=1
    get_local $p0
    i32.const 24
    i32.add
    get_local $p1
    i32.const 24
    i32.add
    i64.load align=1
    i64.store align=1
    get_local $p0
    i32.const 16
    i32.add
    get_local $p1
    i32.const 16
    i32.add
    i64.load align=1
    i64.store align=1
    get_local $p0
    i32.const 8
    i32.add
    get_local $p1
    i32.const 8
    i32.add
    i64.load align=1
    i64.store align=1
    get_local $l0
    i32.const 16
    i32.sub
    tee_local $p0
    get_local $p2
    i64.const 56
    i64.shl
    get_local $p2
    i64.const 40
    i64.shl
    i64.const 71776119061217280
    i64.and
    i64.or
    get_local $p2
    i64.const 24
    i64.shl
    i64.const 280375465082880
    i64.and
    get_local $p2
    i64.const 8
    i64.shl
    i64.const 1095216660480
    i64.and
    i64.or
    i64.or
    get_local $p2
    i64.const 8
    i64.shr_u
    i64.const 4278190080
    i64.and
    get_local $p2
    i64.const 24
    i64.shr_u
    i64.const 16711680
    i64.and
    i64.or
    get_local $p2
    i64.const 40
    i64.shr_u
    i64.const 65280
    i64.and
    get_local $p2
    i64.const 56
    i64.shr_u
    i64.or
    i64.or
    i64.or
    i64.store offset=8
    get_local $p1
    i32.const 31
    i32.add
    set_local $l1
    get_local $p0
    i32.const 8
    i32.add
    i32.const 7
    i32.or
    set_local $l2
    i32.const 0
    set_local $p0
    i32.const 0
    set_local $l0
    block $B0
      loop $L1
        get_local $p0
        i32.const -8
        i32.eq
        br_if $B0
        get_local $l1
        get_local $p0
        i32.add
        tee_local $l3
        get_local $l3
        i32.load8_u
        get_local $l0
        i32.const 255
        i32.and
        i32.add
        tee_local $l3
        i32.const 255
        i32.and
        tee_local $l4
        get_local $l2
        get_local $p0
        i32.add
        i32.load8_u
        i32.add
        tee_local $l0
        i32.store8
        get_local $l4
        get_local $l3
        i32.ne
        get_local $l0
        i32.const 255
        i32.and
        get_local $l0
        i32.ne
        i32.or
        set_local $l0
        get_local $p0
        i32.const -1
        i32.add
        set_local $p0
        br $L1
      end
    end
    block $B2
      get_local $l0
      i32.const 255
      i32.and
      i32.eqz
      br_if $B2
      i32.const 1
      set_local $l0
      i32.const 23
      set_local $p0
      loop $L3
        get_local $p0
        i32.const -1
        i32.eq
        br_if $B2
        get_local $l0
        i32.const 255
        i32.and
        tee_local $l0
        i32.eqz
        br_if $B2
        get_local $p1
        get_local $p0
        i32.add
        tee_local $l3
        get_local $l3
        i32.load8_u
        get_local $l0
        i32.add
        tee_local $l0
        i32.store8
        get_local $l0
        i32.const 255
        i32.and
        get_local $l0
        i32.ne
        set_local $l0
        get_local $p0
        i32.const -1
        i32.add
        set_local $p0
        br $L3
      end
    end)
  (func $_ZN110_$LT$ink_core..storage..cell..raw_cell..RawCell$u20$as$u20$ink_core..storage..alloc..traits..AllocateUsing$GT$14allocate_using17hfd6dd993fdac8296E (type $t4) (param $p0 i32) (param $p1 i32)
    get_local $p0
    get_local $p1
    i64.const 1
    call $_ZN110_$LT$ink_core..storage..alloc..bump_alloc..BumpAlloc$u20$as$u20$ink_core..storage..alloc..traits..Allocate$GT$5alloc17h4497b6fb796ce12bE)
  (func $deploy (type $t8)
    (local $l0 i32)
    get_global $g0
    i32.const 624
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    call $_ZN7flipper7Flipper11instantiate17hd130ac1ff94dabe1E
    get_local $l0
    i32.const 304
    i32.add
    call $_ZN8ink_core3env4srml9srml_only5impls19read_scratch_buffer17h42b5b1e5e4e6d152E
    get_local $l0
    i32.const 320
    i32.add
    get_local $l0
    i32.const 304
    call $memcpy
    drop
    get_local $l0
    i32.const 320
    i32.add
    call $_ZN115_$LT$ink_core..storage..alloc..cc_alloc..CellChunkAlloc$u20$as$u20$ink_core..storage..alloc..traits..Initialize$GT$10initialize17h93bc13a40c962f0eE
    get_local $l0
    i32.const 320
    i32.add
    get_local $l0
    i32.load offset=612
    call_indirect (type $t2)
    get_local $l0
    i32.const 568
    i32.add
    call $_ZN68_$LT$flipper..Flipper$u20$as$u20$ink_core..storage..flush..Flush$GT$5flush17h3a332e9e570596bfE
    get_local $l0
    i32.const 304
    i32.add
    call $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE
    get_local $l0
    i32.const 624
    i32.add
    set_global $g0)
  (func $_ZN8ink_core3env4srml9srml_only5impls19read_scratch_buffer17h42b5b1e5e4e6d152E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    call $ext_scratch_size
    set_local $l1
    get_local $l0
    i32.const 0
    i32.store offset=8
    get_local $l0
    i64.const 1
    i64.store
    block $B0
      get_local $l1
      i32.eqz
      br_if $B0
      get_local $l0
      get_local $l1
      call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9791fa6aa14cc882E
      get_local $l0
      i32.load
      get_local $l0
      i32.const 8
      i32.add
      i32.load
      tee_local $l2
      i32.add
      set_local $l3
      i32.const 0
      set_local $l4
      block $B1
        loop $L2
          get_local $l3
          get_local $l4
          i32.add
          set_local $l6
          get_local $l4
          i32.const 1
          i32.add
          tee_local $l5
          get_local $l1
          i32.ge_u
          br_if $B1
          get_local $l5
          i32.const 1
          i32.add
          get_local $l5
          i32.lt_u
          br_if $B1
          get_local $l6
          i32.const 0
          i32.store8
          get_local $l5
          set_local $l4
          br $L2
        end
      end
      get_local $l0
      i32.const 8
      i32.add
      get_local $l2
      get_local $l4
      i32.add
      i32.const 1
      i32.add
      i32.store
      get_local $l6
      i32.const 0
      i32.store8
      get_local $l0
      i32.load
      i32.const 0
      get_local $l1
      call $ext_scratch_copy
    end
    get_local $p0
    get_local $l0
    i64.load
    i64.store align=4
    get_local $p0
    i32.const 8
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    i32.load
    i32.store
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $_ZN115_$LT$ink_core..storage..alloc..cc_alloc..CellChunkAlloc$u20$as$u20$ink_core..storage..alloc..traits..Initialize$GT$10initialize17h93bc13a40c962f0eE (type $t2) (param $p0 i32)
    get_local $p0
    call $_ZN125_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..Initialize$GT$10initialize17h49a8ebb65671af06E
    get_local $p0
    i32.const 92
    i32.add
    call $_ZN125_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..Initialize$GT$10initialize17h49a8ebb65671af06E)
  (func $_ZN68_$LT$flipper..Flipper$u20$as$u20$ink_core..storage..flush..Flush$GT$5flush17h3a332e9e570596bfE (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core4cell16RefCell$LT$T$GT$6borrow17h3e3607e87caa3ca8E
    get_local $l0
    i32.load offset=8
    i32.load8_u offset=4
    set_local $l1
    get_local $l0
    i32.load offset=12
    tee_local $l2
    get_local $l2
    i32.load
    i32.const -1
    i32.add
    i32.store
    block $B0
      get_local $l1
      i32.const 2
      i32.or
      i32.const 2
      i32.eq
      br_if $B0
      get_local $p0
      i32.const 12
      i32.add
      set_local $l1
      block $B1
        block $B2
          get_local $p0
          call $_ZN8ink_core7storage4cell9sync_cell14Cache$LT$T$GT$7get_mut17h39b18010dee025e7E
          tee_local $l2
          i32.eqz
          br_if $B2
          get_local $l0
          i32.const 16
          i32.add
          get_local $l2
          call $_ZN12parity_codec5codec6Encode6encode17he6dea045983d4bccE
          get_local $l1
          get_local $l0
          i32.load offset=16
          get_local $l0
          i32.load offset=24
          call $_ZN8ink_core7storage4cell8raw_cell7RawCell5store17h6706473e45aec6ccE
          get_local $l0
          i32.const 16
          i32.add
          call $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE.651
          br $B1
        end
        get_local $l1
        call $_ZN8ink_core7storage4cell8raw_cell7RawCell5clear17h9b4491c2daa14a08E
      end
      get_local $l0
      get_local $p0
      call $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h8c7fc7631aa63753E
      get_local $l0
      i32.load offset=4
      set_local $p0
      block $B3
        get_local $l0
        i32.load
        tee_local $l1
        i32.load8_u offset=4
        i32.const 2
        i32.eq
        br_if $B3
        get_local $l1
        i32.const 4
        i32.add
        i32.const 0
        i32.store8
      end
      get_local $p0
      get_local $p0
      i32.load
      i32.const 1
      i32.add
      i32.store
    end
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0)
  (func $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE (type $t2) (param $p0 i32)
    get_local $p0
    i32.load
    get_local $p0
    i32.const 4
    i32.add
    i32.load
    call $_ZN77_$LT$alloc..raw_vec..RawVec$LT$T$C$A$GT$$u20$as$u20$core..ops..drop..Drop$GT$4drop17h6fdbf669a9da6c0eE)
  (func $call (type $t8)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i64)
    get_global $g0
    i32.const 672
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    call $_ZN7flipper7Flipper11instantiate17hd130ac1ff94dabe1E
    get_local $l0
    i32.const 304
    i32.add
    call $_ZN8ink_core3env4srml9srml_only5impls19read_scratch_buffer17h42b5b1e5e4e6d152E
    get_local $l0
    get_local $l0
    i32.load offset=312
    i32.store offset=660
    get_local $l0
    get_local $l0
    i32.load offset=304
    i32.store offset=656
    get_local $l0
    i32.const 0
    i32.store offset=320
    block $B0
      block $B1
        block $B2
          get_local $l0
          i32.const 656
          i32.add
          get_local $l0
          i32.const 320
          i32.add
          i32.const 4
          call $_ZN48_$LT$R$u20$as$u20$parity_codec..codec..Input$GT$4read17h27a72c68ffbec25dE
          i32.const 4
          i32.ne
          br_if $B2
          get_local $l0
          i32.load offset=320
          set_local $l1
          get_local $l0
          i64.const 1
          i64.store offset=320
          get_local $l0
          i32.const 328
          i32.add
          set_local $l2
          i32.const 1
          set_local $l3
          i32.const 0
          set_local $l4
          block $B3
            block $B4
              loop $L5
                get_local $l2
                get_local $l4
                i32.store
                get_local $l0
                i32.const 0
                i32.store8 offset=640
                get_local $l0
                i32.const 656
                i32.add
                get_local $l0
                i32.const 640
                i32.add
                i32.const 1
                call $_ZN48_$LT$R$u20$as$u20$parity_codec..codec..Input$GT$4read17h27a72c68ffbec25dE
                tee_local $l5
                i32.eqz
                br_if $B4
                get_local $l5
                i32.const 1
                i32.ne
                br_if $B3
                get_local $l0
                i32.load8_u offset=640
                set_local $l5
                block $B6
                  get_local $l4
                  get_local $l0
                  i32.load offset=324
                  i32.ne
                  br_if $B6
                  get_local $l0
                  i32.const 320
                  i32.add
                  i32.const 1
                  call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9791fa6aa14cc882E
                  get_local $l2
                  i32.load
                  set_local $l4
                  get_local $l0
                  i32.load offset=320
                  set_local $l3
                end
                get_local $l3
                get_local $l4
                i32.add
                get_local $l5
                i32.store8
                get_local $l4
                i32.const 1
                i32.add
                set_local $l4
                br $L5
              end
            end
            get_local $l3
            i32.eqz
            br_if $B2
            get_local $l0
            i64.load offset=324 align=4
            set_local $l6
            get_local $l0
            i32.const 320
            i32.add
            get_local $l0
            i32.const 304
            call $memcpy
            drop
            get_local $l0
            i32.const 656
            i32.add
            i32.const 8
            i32.add
            get_local $l6
            i64.store
            get_local $l0
            get_local $l3
            i32.store offset=660
            get_local $l0
            get_local $l1
            i32.store offset=656
            get_local $l0
            i32.const 640
            i32.add
            get_local $l0
            i32.const 616
            i32.add
            get_local $l0
            i32.const 320
            i32.add
            get_local $l0
            i32.const 656
            i32.add
            call $_ZN157_$LT$$LP$ink_model..msg_handler..MessageHandler$LT$Msg$C$State$C$Env$GT$$C$$u20$Rest$RP$$u20$as$u20$ink_model..msg_handler..HandleCall$LT$State$C$Env$GT$$GT$11handle_call17h4e0d4a95f8a525ceE
            get_local $l0
            i32.load8_u offset=640
            i32.const 1
            i32.eq
            br_if $B1
            get_local $l0
            i32.const 624
            i32.add
            i32.const 8
            i32.add
            tee_local $l4
            get_local $l0
            i32.const 652
            i32.add
            i32.load
            i32.store
            get_local $l0
            get_local $l0
            i64.load offset=644 align=4
            i64.store offset=624
            get_local $l4
            i32.load
            br_if $B0
            get_local $l0
            i32.const 624
            i32.add
            call $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE
            get_local $l0
            i32.const 304
            i32.add
            call $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE
            get_local $l0
            i32.const 672
            i32.add
            set_global $g0
            return
          end
          i32.const 65764
          i32.const 40
          i32.const 65648
          call $_ZN3std9panicking11begin_panic17h59137bcd87980b1bE
          unreachable
        end
        i32.const 72220
        call $_ZN4core9panicking5panic17ha366c5556fbdacabE
        unreachable
      end
      i32.const 65560
      i32.const 65610
      get_local $l0
      i32.load8_u offset=641
      i32.const 1
      i32.eq
      tee_local $l0
      select
      i32.const 50
      i32.const 36
      get_local $l0
      select
      i32.const 72112
      call $_ZN3std9panicking11begin_panic17h59137bcd87980b1bE
      unreachable
    end
    get_local $l0
    i32.const 656
    i32.add
    i32.const 8
    i32.add
    get_local $l0
    i32.const 624
    i32.add
    i32.const 8
    i32.add
    i32.load
    i32.store
    get_local $l0
    get_local $l0
    i64.load offset=624
    i64.store offset=656
    get_local $l0
    i32.const 656
    i32.add
    call $_ZN9ink_model8exec_env19EnvHandler$LT$T$GT$6return17hf4dc448dd16492d9E
    unreachable)
  (func $_ZN48_$LT$R$u20$as$u20$parity_codec..codec..Input$GT$4read17h27a72c68ffbec25dE (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      block $B1
        block $B2
          block $B3
            get_local $p0
            i32.load offset=4
            tee_local $l1
            get_local $p2
            i32.ge_u
            br_if $B3
            i32.const 27
            i32.const 1
            call $__rust_alloc
            tee_local $p2
            i32.eqz
            br_if $B1
            get_local $p2
            i32.const 23
            i32.add
            i32.const 0
            i32.load offset=65827 align=1
            i32.store align=1
            get_local $p2
            i32.const 16
            i32.add
            i32.const 0
            i64.load offset=65820 align=1
            i64.store align=1
            get_local $p2
            i32.const 8
            i32.add
            i32.const 0
            i64.load offset=65812 align=1
            i64.store align=1
            get_local $p2
            i32.const 0
            i64.load offset=65804 align=1
            i64.store align=1
            i32.const 12
            i32.const 4
            call $__rust_alloc
            tee_local $p0
            i32.eqz
            br_if $B1
            get_local $p0
            i64.const 115964117019
            i64.store offset=4 align=4
            get_local $p0
            get_local $p2
            i32.store
            i32.const 12
            i32.const 4
            call $__rust_alloc
            tee_local $p2
            i32.eqz
            br_if $B1
            get_local $p2
            i32.const 17
            i32.store8 offset=8
            get_local $p2
            i32.const 66096
            i32.store offset=4
            get_local $p2
            get_local $p0
            i32.store
            get_local $p2
            get_local $l0
            i32.load16_u offset=29 align=1
            i32.store16 offset=9 align=1
            get_local $p2
            i32.const 11
            i32.add
            get_local $l0
            i32.const 31
            i32.add
            i32.load8_u
            i32.store8
            get_local $p2
            i32.load
            get_local $p2
            i32.load offset=4
            i32.load
            call_indirect (type $t2)
            block $B4
              get_local $p2
              i32.load offset=4
              i32.load offset=4
              i32.eqz
              br_if $B4
              get_local $p2
              i32.load
              call $__rust_dealloc
            end
            get_local $p2
            call $__rust_dealloc
            i32.const 0
            set_local $p2
            br $B2
          end
          get_local $l0
          i32.const 16
          i32.add
          i32.const 0
          get_local $p2
          get_local $p0
          i32.load
          tee_local $l2
          get_local $l1
          call $_ZN99_$LT$core..ops..range..Range$LT$usize$GT$$u20$as$u20$core..slice..SliceIndex$LT$$u5b$T$u5d$$GT$$GT$5index17h8d60d25c17fa37c3E.48
          get_local $l0
          i32.load offset=20
          set_local $l3
          get_local $l0
          i32.load offset=16
          set_local $l4
          get_local $l0
          i32.const 8
          i32.add
          get_local $p2
          get_local $l1
          get_local $l2
          get_local $l1
          call $_ZN99_$LT$core..ops..range..Range$LT$usize$GT$$u20$as$u20$core..slice..SliceIndex$LT$$u5b$T$u5d$$GT$$GT$5index17h8d60d25c17fa37c3E.48
          get_local $l0
          i32.load offset=12
          set_local $l1
          get_local $l0
          i32.load offset=8
          set_local $l2
          block $B5
            block $B6
              get_local $p2
              i32.const 1
              i32.ne
              br_if $B6
              get_local $l3
              i32.eqz
              br_if $B0
              get_local $p1
              get_local $l4
              i32.load8_u
              i32.store8
              br $B5
            end
            get_local $p1
            get_local $p2
            get_local $l4
            get_local $l3
            call $_ZN4core5slice29_$LT$impl$u20$$u5b$T$u5d$$GT$15copy_from_slice17hef922ab2ce44584bE
          end
          get_local $p0
          get_local $l2
          i32.store
          get_local $p0
          i32.const 4
          i32.add
          get_local $l1
          i32.store
        end
        get_local $l0
        i32.const 32
        i32.add
        set_global $g0
        get_local $p2
        return
      end
      unreachable
      unreachable
    end
    i32.const 65832
    i32.const 0
    i32.const 0
    call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
    unreachable)
  (func $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9791fa6aa14cc882E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32)
    block $B0
      get_local $p0
      i32.load offset=4
      tee_local $l0
      get_local $p0
      i32.load offset=8
      tee_local $l1
      i32.sub
      get_local $p1
      i32.ge_u
      br_if $B0
      block $B1
        block $B2
          get_local $l1
          get_local $p1
          i32.add
          tee_local $p1
          get_local $l1
          i32.lt_u
          br_if $B2
          get_local $l0
          i32.const 1
          i32.shl
          tee_local $l1
          get_local $p1
          get_local $p1
          get_local $l1
          i32.lt_u
          select
          tee_local $p1
          i32.const 0
          i32.lt_s
          br_if $B2
          block $B3
            block $B4
              get_local $l0
              i32.eqz
              br_if $B4
              get_local $p0
              i32.load
              get_local $p1
              call $__rust_realloc
              tee_local $l0
              i32.eqz
              br_if $B3
              br $B1
            end
            get_local $p1
            i32.const 1
            call $__rust_alloc
            tee_local $l0
            br_if $B1
          end
          unreachable
          unreachable
        end
        call $_ZN5alloc7raw_vec17capacity_overflow17hc18be88cbff328c0E
        unreachable
      end
      get_local $p0
      get_local $l0
      i32.store
      get_local $p0
      i32.const 4
      i32.add
      get_local $p1
      i32.store
    end)
  (func $_ZN157_$LT$$LP$ink_model..msg_handler..MessageHandler$LT$Msg$C$State$C$Env$GT$$C$$u20$Rest$RP$$u20$as$u20$ink_model..msg_handler..HandleCall$LT$State$C$Env$GT$$GT$11handle_call17h4e0d4a95f8a525ceE (type $t7) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      block $B1
        get_local $p3
        i32.load
        tee_local $l1
        i32.const -28687323
        i32.ne
        br_if $B1
        get_local $l0
        i32.const 8
        i32.add
        i32.const 8
        i32.add
        get_local $p3
        i32.const 8
        i32.add
        i64.load align=4
        i64.store
        get_local $l0
        get_local $p3
        i64.load align=4
        i64.store offset=8
        get_local $l0
        get_local $p2
        get_local $p1
        i32.load
        call_indirect (type $t3)
        i32.store8 offset=31
        get_local $l0
        i32.const 32
        i32.add
        get_local $l0
        i32.const 31
        i32.add
        call $_ZN12parity_codec5codec6Encode6encode17he6dea045983d4bccE
        get_local $p0
        i32.const 12
        i32.add
        get_local $l0
        i32.const 32
        i32.add
        i32.const 8
        i32.add
        i32.load
        i32.store
        get_local $p0
        i32.const 4
        i32.add
        get_local $l0
        i64.load offset=32
        i64.store align=4
        get_local $l0
        i32.const 8
        i32.add
        call $_ZN4core3ptr18real_drop_in_place17h31b6e3a475bfede3E
        get_local $p0
        i32.const 0
        i32.store8
        br $B0
      end
      get_local $l0
      i32.const 40
      i32.add
      tee_local $l2
      get_local $p3
      i32.const 12
      i32.add
      i32.load
      i32.store
      get_local $l0
      get_local $p3
      i64.load offset=4 align=4
      i64.store offset=32
      block $B2
        block $B3
          get_local $l1
          i32.const 970692492
          i32.ne
          br_if $B3
          get_local $l0
          i32.const 8
          i32.add
          i32.const 12
          i32.add
          get_local $l2
          i32.load
          i32.store
          get_local $l0
          i32.const 970692492
          i32.store offset=8
          get_local $l0
          get_local $l0
          i64.load offset=32
          i64.store offset=12 align=4
          get_local $p2
          get_local $p1
          i32.load offset=4
          call_indirect (type $t2)
          get_local $p2
          i32.const 248
          i32.add
          call $_ZN68_$LT$flipper..Flipper$u20$as$u20$ink_core..storage..flush..Flush$GT$5flush17h3a332e9e570596bfE
          i32.const 0
          set_local $p3
          get_local $p0
          i32.const 12
          i32.add
          i32.const 0
          i32.store
          get_local $p0
          i32.const 4
          i32.add
          i64.const 1
          i64.store align=4
          get_local $l0
          i32.const 8
          i32.add
          call $_ZN4core3ptr18real_drop_in_place17h31b6e3a475bfede3E
          br $B2
        end
        get_local $p0
        i32.const 0
        i32.store8 offset=1
        get_local $l0
        i32.const 8
        i32.add
        i32.const 12
        i32.add
        get_local $l2
        i32.load
        i32.store
        get_local $l0
        get_local $l1
        i32.store offset=8
        get_local $l0
        get_local $l0
        i64.load offset=32
        i64.store offset=12 align=4
        get_local $l0
        i32.const 8
        i32.add
        call $_ZN4core3ptr18real_drop_in_place17h31b6e3a475bfede3E
        i32.const 1
        set_local $p3
      end
      get_local $p0
      get_local $p3
      i32.store8
    end
    get_local $l0
    i32.const 48
    i32.add
    set_global $g0)
  (func $_ZN3std9panicking11begin_panic17h59137bcd87980b1bE (type $t6) (param $p0 i32) (param $p1 i32) (param $p2 i32)
    get_local $p2
    call $_ZN3std9panicking20rust_panic_with_hook17hefd1961cb73ff006E
    unreachable)
  (func $_ZN9ink_model8exec_env19EnvHandler$LT$T$GT$6return17hf4dc448dd16492d9E (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    i32.const 8
    i32.add
    i32.load
    i32.store
    get_local $l0
    get_local $p0
    i64.load align=4
    i64.store
    get_local $l0
    call $_ZN8ink_core3env3api6return17h4c7486d53da12064E
    unreachable)
  (func $_ZN4core4cell16RefCell$LT$T$GT$6borrow17h3e3607e87caa3ca8E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    block $B0
      get_local $p1
      i32.load
      tee_local $l0
      i32.const 0
      i32.lt_s
      br_if $B0
      get_local $l0
      i32.const 2147483647
      i32.eq
      br_if $B0
      get_local $p1
      get_local $l0
      i32.const 1
      i32.add
      i32.store
      get_local $p0
      get_local $p1
      i32.store offset=4
      get_local $p0
      get_local $p1
      i32.const 4
      i32.add
      i32.store
      return
    end
    call $_ZN4core6result13unwrap_failed17h925080ed079c8a30E
    unreachable)
  (func $_ZN12parity_codec5codec6Encode6encode17he6dea045983d4bccE (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 0
    i32.store offset=8
    get_local $l0
    i64.const 1
    i64.store
    get_local $l0
    get_local $p1
    get_local $p1
    i32.const 1
    i32.add
    call $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE
    get_local $p0
    i32.const 8
    i32.add
    get_local $l0
    i32.load offset=8
    i32.store
    get_local $p0
    get_local $l0
    i64.load
    i64.store align=4
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $_ZN8ink_core7storage4cell8raw_cell7RawCell5store17h6706473e45aec6ccE (type $t6) (param $p0 i32) (param $p1 i32) (param $p2 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 24
    i32.add
    get_local $p0
    i32.const 24
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 16
    i32.add
    get_local $p0
    i32.const 16
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    i32.const 8
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    get_local $p0
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 1
    get_local $p1
    get_local $p2
    call $ext_set_storage
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0)
  (func $_ZN4core3ptr18real_drop_in_place17habb7d5260249c1ceE.651 (type $t2) (param $p0 i32)
    get_local $p0
    i32.load
    get_local $p0
    i32.const 4
    i32.add
    i32.load
    call $_ZN77_$LT$alloc..raw_vec..RawVec$LT$T$C$A$GT$$u20$as$u20$core..ops..drop..Drop$GT$4drop17h6fdbf669a9da6c0eE)
  (func $_ZN8ink_core7storage4cell8raw_cell7RawCell5clear17h9b4491c2daa14a08E (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 24
    i32.add
    get_local $p0
    i32.const 24
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 16
    i32.add
    get_local $p0
    i32.const 16
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    i32.const 8
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    get_local $p0
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 0
    i32.const 0
    i32.const 0
    call $ext_set_storage
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0)
  (func $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h8c7fc7631aa63753E (type $t4) (param $p0 i32) (param $p1 i32)
    block $B0
      get_local $p1
      i32.load
      br_if $B0
      get_local $p1
      i32.const -1
      i32.store
      get_local $p0
      get_local $p1
      i32.store offset=4
      get_local $p0
      get_local $p1
      i32.const 4
      i32.add
      i32.store
      return
    end
    i32.const 71749
    call $_ZN4core6result13unwrap_failed17h810a9bf1a81f2cf1E
    unreachable)
  (func $_ZN125_$LT$ink_core..storage..collections..stash..impls..Stash$LT$T$GT$$u20$as$u20$ink_core..storage..alloc..traits..Initialize$GT$10initialize17h49a8ebb65671af06E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h31d85faac53eb2b4E.llvm.7530963317839412752
    get_local $l0
    i32.load offset=12
    set_local $l1
    block $B0
      block $B1
        block $B2
          get_local $l0
          i32.load offset=8
          tee_local $l2
          i32.load8_u offset=4
          i32.const 2
          i32.ne
          br_if $B2
          i32.const 16
          i32.const 4
          call $__rust_alloc
          tee_local $l3
          i32.eqz
          br_if $B0
          get_local $l3
          i64.const 0
          i64.store offset=8 align=4
          get_local $l3
          i64.const 1
          i64.store align=4
          block $B3
            get_local $l2
            i32.const 4
            i32.add
            i32.load8_u
            i32.const 2
            i32.eq
            br_if $B3
            get_local $l2
            i32.load
            call $__rust_dealloc
          end
          get_local $l2
          get_local $l3
          i32.store
          get_local $l2
          i32.const 4
          i32.add
          i32.const 0
          i32.store8
          br $B1
        end
        get_local $l2
        i32.load
        tee_local $l2
        i64.const 0
        i64.store offset=8 align=4
        get_local $l2
        i64.const 1
        i64.store align=4
      end
      get_local $l1
      get_local $l1
      i32.load
      i32.const 1
      i32.add
      i32.store
      get_local $l0
      get_local $p0
      call $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h31d85faac53eb2b4E.llvm.7530963317839412752
      get_local $l0
      i32.load offset=4
      set_local $l2
      block $B4
        get_local $l0
        i32.load
        tee_local $p0
        i32.load8_u offset=4
        i32.const 2
        i32.eq
        br_if $B4
        get_local $p0
        i32.const 4
        i32.add
        i32.const 1
        i32.store8
      end
      get_local $l2
      get_local $l2
      i32.load
      i32.const 1
      i32.add
      i32.store
      get_local $l0
      i32.const 16
      i32.add
      set_global $g0
      return
    end
    unreachable
    unreachable)
  (func $_ZN4core4cell16RefCell$LT$T$GT$10borrow_mut17h31d85faac53eb2b4E.llvm.7530963317839412752 (type $t4) (param $p0 i32) (param $p1 i32)
    block $B0
      get_local $p1
      i32.load
      br_if $B0
      get_local $p1
      i32.const -1
      i32.store
      get_local $p0
      get_local $p1
      i32.store offset=4
      get_local $p0
      get_local $p1
      i32.const 4
      i32.add
      i32.store
      return
    end
    i32.const 71749
    call $_ZN4core6result13unwrap_failed17h810a9bf1a81f2cf1E
    unreachable)
  (func $__rust_dealloc (type $t2) (param $p0 i32)
    get_local $p0
    call $__rdl_dealloc)
  (func $_ZN8ink_core7storage4cell8raw_cell7RawCell4load17hf9358592e2a91478E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 24
    i32.add
    get_local $p1
    i32.const 24
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 16
    i32.add
    get_local $p1
    i32.const 16
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    get_local $p1
    i32.const 8
    i32.add
    i64.load align=1
    i64.store
    get_local $l0
    get_local $p1
    i64.load align=1
    i64.store
    block $B0
      block $B1
        get_local $l0
        call $ext_get_storage
        i32.eqz
        br_if $B1
        get_local $p0
        i32.const 0
        i32.store
        br $B0
      end
      get_local $p0
      call $_ZN8ink_core3env4srml9srml_only5impls19read_scratch_buffer17h42b5b1e5e4e6d152E
    end
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0)
  (func $_ZN99_$LT$core..ops..range..Range$LT$usize$GT$$u20$as$u20$core..slice..SliceIndex$LT$$u5b$T$u5d$$GT$$GT$5index17h8d60d25c17fa37c3E.48 (type $t10) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32) (param $p4 i32)
    block $B0
      block $B1
        get_local $p2
        get_local $p1
        i32.lt_u
        br_if $B1
        get_local $p4
        get_local $p2
        i32.lt_u
        br_if $B0
        get_local $p0
        get_local $p2
        get_local $p1
        i32.sub
        i32.store offset=4
        get_local $p0
        get_local $p3
        get_local $p1
        i32.add
        i32.store
        return
      end
      get_local $p1
      get_local $p2
      call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
      unreachable
    end
    get_local $p2
    get_local $p4
    call $_ZN4core5slice20slice_index_len_fail17h00bfcf67cecaf929E
    unreachable)
  (func $_ZN4core5slice29_$LT$impl$u20$$u5b$T$u5d$$GT$15copy_from_slice17hef922ab2ce44584bE (type $t7) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 96
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store offset=8
    get_local $l0
    get_local $p3
    i32.store offset=12
    block $B0
      get_local $p1
      get_local $p3
      i32.ne
      br_if $B0
      get_local $p0
      get_local $p2
      get_local $p1
      call $memcpy
      drop
      get_local $l0
      i32.const 96
      i32.add
      set_global $g0
      return
    end
    get_local $l0
    get_local $l0
    i32.const 8
    i32.add
    i32.store offset=64
    get_local $l0
    get_local $l0
    i32.const 12
    i32.add
    i32.store offset=68
    get_local $l0
    i32.const 72
    i32.add
    i32.const 20
    i32.add
    i32.const 0
    i32.store
    get_local $l0
    i32.const 40
    i32.add
    i32.const 20
    i32.add
    i32.const 8
    i32.store
    get_local $l0
    i32.const 52
    i32.add
    i32.const 9
    i32.store
    get_local $l0
    i32.const 16
    i32.add
    i32.const 20
    i32.add
    i32.const 3
    i32.store
    get_local $l0
    i32.const 66356
    i32.store offset=88
    get_local $l0
    i64.const 1
    i64.store offset=76 align=4
    get_local $l0
    i32.const 66012
    i32.store offset=72
    get_local $l0
    i32.const 9
    i32.store offset=44
    get_local $l0
    i64.const 3
    i64.store offset=20 align=4
    get_local $l0
    i32.const 65928
    i32.store offset=16
    get_local $l0
    get_local $l0
    i32.const 72
    i32.add
    i32.store offset=56
    get_local $l0
    get_local $l0
    i32.const 68
    i32.add
    i32.store offset=48
    get_local $l0
    get_local $l0
    i32.const 64
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.const 40
    i32.add
    i32.store offset=32
    get_local $l0
    i32.const 16
    i32.add
    i32.const 66072
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E (type $t6) (param $p0 i32) (param $p1 i32) (param $p2 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p2
    i32.store offset=4
    get_local $l0
    get_local $p1
    i32.store
    get_local $l0
    i32.const 44
    i32.add
    i32.const 10
    i32.store
    get_local $l0
    i32.const 28
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 10
    i32.store offset=36
    get_local $l0
    i64.const 2
    i64.store offset=12 align=4
    get_local $l0
    i32.const 66340
    i32.store offset=8
    get_local $l0
    get_local $l0
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.const 4
    i32.add
    i32.store offset=32
    get_local $l0
    get_local $l0
    i32.const 32
    i32.add
    i32.store offset=24
    get_local $l0
    i32.const 8
    i32.add
    get_local $p0
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store offset=4
    get_local $l0
    get_local $p0
    i32.store
    get_local $l0
    i32.const 44
    i32.add
    i32.const 10
    i32.store
    get_local $l0
    i32.const 28
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 10
    i32.store offset=36
    get_local $l0
    i64.const 2
    i64.store offset=12 align=4
    get_local $l0
    i32.const 66720
    i32.store offset=8
    get_local $l0
    get_local $l0
    i32.const 4
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.store offset=32
    get_local $l0
    get_local $l0
    i32.const 32
    i32.add
    i32.store offset=24
    get_local $l0
    i32.const 8
    i32.add
    i32.const 66736
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN4core5slice20slice_index_len_fail17h00bfcf67cecaf929E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store offset=4
    get_local $l0
    get_local $p0
    i32.store
    get_local $l0
    i32.const 44
    i32.add
    i32.const 10
    i32.store
    get_local $l0
    i32.const 28
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 10
    i32.store offset=36
    get_local $l0
    i64.const 2
    i64.store offset=12 align=4
    get_local $l0
    i32.const 66624
    i32.store offset=8
    get_local $l0
    get_local $l0
    i32.const 4
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.store offset=32
    get_local $l0
    get_local $l0
    i32.const 32
    i32.add
    i32.store offset=24
    get_local $l0
    i32.const 8
    i32.add
    i32.const 66640
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN12parity_codec5codec6Encode9encode_to17h73a00f1df427205aE (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    i32.store offset=12
    get_local $p1
    get_local $l0
    i32.const 12
    i32.add
    get_local $l0
    i32.const 16
    i32.add
    call $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE (type $t6) (param $p0 i32) (param $p1 i32) (param $p2 i32)
    (local $l0 i32)
    get_local $p0
    get_local $p2
    get_local $p1
    i32.sub
    tee_local $p2
    call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9791fa6aa14cc882E
    get_local $p0
    get_local $p0
    i32.load offset=8
    tee_local $l0
    get_local $p2
    i32.add
    i32.store offset=8
    get_local $l0
    get_local $p0
    i32.load
    i32.add
    get_local $p2
    get_local $p1
    get_local $p2
    call $_ZN4core5slice29_$LT$impl$u20$$u5b$T$u5d$$GT$15copy_from_slice17hef922ab2ce44584bE)
  (func $_ZN4core6result13unwrap_failed17h810a9bf1a81f2cf1E (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 64
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 16
    i32.store offset=12
    get_local $l0
    get_local $p0
    i32.store offset=8
    get_local $l0
    i32.const 52
    i32.add
    i32.const 11
    i32.store
    get_local $l0
    i32.const 36
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 12
    i32.store offset=44
    get_local $l0
    i64.const 2
    i64.store offset=20 align=4
    get_local $l0
    i32.const 66284
    i32.store offset=16
    get_local $l0
    get_local $l0
    i32.const 56
    i32.add
    i32.store offset=48
    get_local $l0
    get_local $l0
    i32.const 8
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.const 40
    i32.add
    i32.store offset=32
    get_local $l0
    i32.const 16
    i32.add
    i32.const 66300
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN63_$LT$core..cell..BorrowMutError$u20$as$u20$core..fmt..Debug$GT$3fmt17h83f9fd6e715251a1E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    i32.load offset=24
    i32.const 71668
    i32.const 14
    get_local $p1
    i32.const 28
    i32.add
    i32.load
    i32.load offset=12
    call_indirect (type $t0))
  (func $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17h0cbe85a258a2765aE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    get_local $p0
    i32.load
    get_local $p0
    i32.load offset=4
    call $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE)
  (func $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i64)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p1
    i64.load align=4
    set_local $l1
    get_local $l0
    i32.const 20
    i32.add
    get_local $p1
    i64.load offset=8 align=4
    i64.store align=4
    get_local $l0
    get_local $l1
    i64.store offset=12 align=4
    get_local $l0
    get_local $p0
    i32.store offset=8
    get_local $l0
    i32.const 66356
    i32.store offset=4
    get_local $l0
    i32.const 66356
    i32.store
    get_local $l0
    call $rust_begin_unwind
    unreachable)
  (func $_ZN4core6result13unwrap_failed17h925080ed079c8a30E (type $t8)
    (local $l0 i32)
    get_global $g0
    i32.const 64
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 24
    i32.store offset=12
    get_local $l0
    i32.const 71981
    i32.store offset=8
    get_local $l0
    i32.const 52
    i32.add
    i32.const 13
    i32.store
    get_local $l0
    i32.const 36
    i32.add
    i32.const 2
    i32.store
    get_local $l0
    i32.const 12
    i32.store offset=44
    get_local $l0
    i64.const 2
    i64.store offset=20 align=4
    get_local $l0
    i32.const 66284
    i32.store offset=16
    get_local $l0
    get_local $l0
    i32.const 56
    i32.add
    i32.store offset=48
    get_local $l0
    get_local $l0
    i32.const 8
    i32.add
    i32.store offset=40
    get_local $l0
    get_local $l0
    i32.const 40
    i32.add
    i32.store offset=32
    get_local $l0
    i32.const 16
    i32.add
    i32.const 66300
    call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
    unreachable)
  (func $_ZN60_$LT$core..cell..BorrowError$u20$as$u20$core..fmt..Debug$GT$3fmt17hdc09f16504a2fabcE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    i32.load offset=24
    i32.const 71657
    i32.const 11
    get_local $p1
    i32.const 28
    i32.add
    i32.load
    i32.load offset=12
    call_indirect (type $t0))
  (func $__rust_realloc (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    get_local $p1
    call $__rdl_realloc)
  (func $_ZN5alloc7raw_vec17capacity_overflow17hc18be88cbff328c0E (type $t8)
    i32.const 66144
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $_ZN12parity_codec5codec6Output9push_byte17h60c47774d3e8492eE (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p1
    i32.store8 offset=15
    get_local $p0
    get_local $l0
    i32.const 15
    i32.add
    get_local $l0
    i32.const 16
    i32.add
    call $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $_ZN59_$LT$core..fmt..Arguments$u20$as$u20$core..fmt..Display$GT$3fmt17h8bde5d3365f3f301E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p1
    i32.const 28
    i32.add
    i32.load
    set_local $l1
    get_local $p1
    i32.load offset=24
    set_local $p1
    get_local $l0
    i32.const 8
    i32.add
    i32.const 16
    i32.add
    get_local $p0
    i32.const 16
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 8
    i32.add
    get_local $p0
    i32.const 8
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    get_local $p0
    i64.load align=4
    i64.store offset=8
    get_local $p1
    get_local $l1
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
    set_local $p0
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $p0)
  (func $_ZN42_$LT$$RF$T$u20$as$u20$core..fmt..Debug$GT$3fmt17h935f3c1118c8b920E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 128
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.load
    set_local $p0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p1
              i32.load
              tee_local $l1
              i32.const 16
              i32.and
              br_if $B4
              get_local $l1
              i32.const 32
              i32.and
              br_if $B3
              get_local $p0
              get_local $p1
              call $_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u32$GT$3fmt17hcc01d718c23da93bE
              set_local $p0
              br $B2
            end
            get_local $p0
            i32.load
            set_local $l1
            i32.const 0
            set_local $p0
            loop $L5
              get_local $l0
              get_local $p0
              i32.add
              i32.const 127
              i32.add
              get_local $l1
              i32.const 15
              i32.and
              tee_local $l2
              i32.const 48
              i32.or
              get_local $l2
              i32.const 87
              i32.add
              get_local $l2
              i32.const 10
              i32.lt_u
              select
              i32.store8
              get_local $p0
              i32.const -1
              i32.add
              set_local $p0
              get_local $l1
              i32.const 4
              i32.shr_u
              tee_local $l1
              br_if $L5
            end
            get_local $p0
            i32.const 128
            i32.add
            tee_local $l1
            i32.const 129
            i32.ge_u
            br_if $B1
            get_local $p1
            i32.const 66788
            i32.const 2
            get_local $l0
            get_local $p0
            i32.add
            i32.const 128
            i32.add
            i32.const 0
            get_local $p0
            i32.sub
            call $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE
            set_local $p0
            br $B2
          end
          get_local $p0
          i32.load
          set_local $l1
          i32.const 0
          set_local $p0
          loop $L6
            get_local $l0
            get_local $p0
            i32.add
            i32.const 127
            i32.add
            get_local $l1
            i32.const 15
            i32.and
            tee_local $l2
            i32.const 48
            i32.or
            get_local $l2
            i32.const 55
            i32.add
            get_local $l2
            i32.const 10
            i32.lt_u
            select
            i32.store8
            get_local $p0
            i32.const -1
            i32.add
            set_local $p0
            get_local $l1
            i32.const 4
            i32.shr_u
            tee_local $l1
            br_if $L6
          end
          get_local $p0
          i32.const 128
          i32.add
          tee_local $l1
          i32.const 129
          i32.ge_u
          br_if $B0
          get_local $p1
          i32.const 66788
          i32.const 2
          get_local $l0
          get_local $p0
          i32.add
          i32.const 128
          i32.add
          i32.const 0
          get_local $p0
          i32.sub
          call $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE
          set_local $p0
        end
        get_local $l0
        i32.const 128
        i32.add
        set_global $g0
        get_local $p0
        return
      end
      get_local $l1
      i32.const 128
      call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
      unreachable
    end
    get_local $l1
    i32.const 128
    call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
    unreachable)
  (func $_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u32$GT$3fmt17hcc01d718c23da93bE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    i64.load32_u
    get_local $p1
    call $_ZN4core3fmt3num3imp7fmt_u6417hbdd21d5900fb3af9E)
  (func $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE (type $t11) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32) (param $p4 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32)
    get_local $p0
    i32.load
    tee_local $l0
    i32.const 1
    i32.and
    tee_local $l1
    get_local $p4
    i32.add
    set_local $l2
    block $B0
      block $B1
        get_local $l0
        i32.const 4
        i32.and
        br_if $B1
        i32.const 0
        set_local $p1
        br $B0
      end
      i32.const 0
      set_local $l3
      block $B2
        get_local $p2
        i32.eqz
        br_if $B2
        get_local $p2
        set_local $l4
        get_local $p1
        set_local $l5
        loop $L3
          get_local $l3
          get_local $l5
          i32.load8_u
          i32.const 192
          i32.and
          i32.const 128
          i32.eq
          i32.add
          set_local $l3
          get_local $l5
          i32.const 1
          i32.add
          set_local $l5
          get_local $l4
          i32.const -1
          i32.add
          tee_local $l4
          br_if $L3
        end
      end
      get_local $l2
      get_local $p2
      i32.add
      get_local $l3
      i32.sub
      set_local $l2
    end
    i32.const 43
    i32.const 1114112
    get_local $l1
    select
    set_local $l1
    block $B4
      block $B5
        block $B6
          block $B7
            block $B8
              block $B9
                block $B10
                  block $B11
                    block $B12
                      block $B13
                        block $B14
                          block $B15
                            block $B16
                              block $B17
                                get_local $p0
                                i32.load offset=8
                                i32.const 1
                                i32.ne
                                br_if $B17
                                get_local $p0
                                i32.const 12
                                i32.add
                                i32.load
                                tee_local $l3
                                get_local $l2
                                i32.le_u
                                br_if $B16
                                get_local $l0
                                i32.const 8
                                i32.and
                                br_if $B15
                                get_local $l3
                                get_local $l2
                                i32.sub
                                set_local $l5
                                i32.const 1
                                get_local $p0
                                i32.load8_u offset=48
                                tee_local $l3
                                get_local $l3
                                i32.const 3
                                i32.eq
                                select
                                tee_local $l3
                                i32.const 3
                                i32.and
                                i32.eqz
                                br_if $B14
                                get_local $l3
                                i32.const 2
                                i32.eq
                                br_if $B13
                                i32.const 0
                                set_local $l6
                                get_local $l5
                                set_local $l3
                                br $B12
                              end
                              i32.const 1
                              set_local $l5
                              get_local $p0
                              get_local $l1
                              get_local $p1
                              get_local $p2
                              call $_ZN4core3fmt9Formatter12pad_integral12write_prefix17h233a3de9c8db3d12E
                              br_if $B4
                              get_local $p0
                              i32.load offset=24
                              get_local $p3
                              get_local $p4
                              get_local $p0
                              i32.const 28
                              i32.add
                              i32.load
                              i32.load offset=12
                              call_indirect (type $t0)
                              return
                            end
                            i32.const 1
                            set_local $l5
                            get_local $p0
                            get_local $l1
                            get_local $p1
                            get_local $p2
                            call $_ZN4core3fmt9Formatter12pad_integral12write_prefix17h233a3de9c8db3d12E
                            br_if $B4
                            get_local $p0
                            i32.load offset=24
                            get_local $p3
                            get_local $p4
                            get_local $p0
                            i32.const 28
                            i32.add
                            i32.load
                            i32.load offset=12
                            call_indirect (type $t0)
                            return
                          end
                          i32.const 1
                          set_local $l5
                          get_local $p0
                          i32.const 1
                          i32.store8 offset=48
                          get_local $p0
                          i32.const 48
                          i32.store offset=4
                          get_local $p0
                          get_local $l1
                          get_local $p1
                          get_local $p2
                          call $_ZN4core3fmt9Formatter12pad_integral12write_prefix17h233a3de9c8db3d12E
                          br_if $B4
                          get_local $l3
                          get_local $l2
                          i32.sub
                          set_local $l5
                          i32.const 1
                          get_local $p0
                          i32.const 48
                          i32.add
                          i32.load8_u
                          tee_local $l3
                          get_local $l3
                          i32.const 3
                          i32.eq
                          select
                          tee_local $l3
                          i32.const 3
                          i32.and
                          i32.eqz
                          br_if $B11
                          get_local $l3
                          i32.const 2
                          i32.eq
                          br_if $B10
                          i32.const 0
                          set_local $l2
                          get_local $l5
                          set_local $l3
                          br $B9
                        end
                        i32.const 0
                        set_local $l3
                        get_local $l5
                        set_local $l6
                        br $B12
                      end
                      get_local $l5
                      i32.const 1
                      i32.shr_u
                      set_local $l3
                      get_local $l5
                      i32.const 1
                      i32.add
                      i32.const 1
                      i32.shr_u
                      set_local $l6
                    end
                    i32.const -1
                    set_local $l5
                    get_local $p0
                    i32.const 4
                    i32.add
                    set_local $l4
                    get_local $p0
                    i32.const 24
                    i32.add
                    set_local $l2
                    get_local $p0
                    i32.const 28
                    i32.add
                    set_local $l0
                    block $B18
                      loop $L19
                        get_local $l5
                        i32.const 1
                        i32.add
                        tee_local $l5
                        get_local $l3
                        i32.ge_u
                        br_if $B18
                        get_local $l2
                        i32.load
                        get_local $l4
                        i32.load
                        get_local $l0
                        i32.load
                        i32.load offset=16
                        call_indirect (type $t1)
                        i32.eqz
                        br_if $L19
                        br $B8
                      end
                    end
                    get_local $p0
                    i32.const 4
                    i32.add
                    i32.load
                    set_local $l4
                    i32.const 1
                    set_local $l5
                    get_local $p0
                    get_local $l1
                    get_local $p1
                    get_local $p2
                    call $_ZN4core3fmt9Formatter12pad_integral12write_prefix17h233a3de9c8db3d12E
                    br_if $B4
                    get_local $p0
                    i32.const 24
                    i32.add
                    tee_local $l3
                    i32.load
                    get_local $p3
                    get_local $p4
                    get_local $p0
                    i32.const 28
                    i32.add
                    tee_local $p2
                    i32.load
                    i32.load offset=12
                    call_indirect (type $t0)
                    br_if $B4
                    get_local $l3
                    i32.load
                    set_local $p0
                    i32.const -1
                    set_local $l3
                    get_local $p2
                    i32.load
                    i32.const 16
                    i32.add
                    set_local $p2
                    loop $L20
                      get_local $l3
                      i32.const 1
                      i32.add
                      tee_local $l3
                      get_local $l6
                      i32.ge_u
                      br_if $B6
                      i32.const 1
                      set_local $l5
                      get_local $p0
                      get_local $l4
                      get_local $p2
                      i32.load
                      call_indirect (type $t1)
                      i32.eqz
                      br_if $L20
                      br $B4
                    end
                  end
                  i32.const 0
                  set_local $l3
                  get_local $l5
                  set_local $l2
                  br $B9
                end
                get_local $l5
                i32.const 1
                i32.shr_u
                set_local $l3
                get_local $l5
                i32.const 1
                i32.add
                i32.const 1
                i32.shr_u
                set_local $l2
              end
              i32.const -1
              set_local $l5
              get_local $p0
              i32.const 4
              i32.add
              set_local $l4
              get_local $p0
              i32.const 24
              i32.add
              set_local $p2
              get_local $p0
              i32.const 28
              i32.add
              set_local $p1
              loop $L21
                get_local $l5
                i32.const 1
                i32.add
                tee_local $l5
                get_local $l3
                i32.ge_u
                br_if $B7
                get_local $p2
                i32.load
                get_local $l4
                i32.load
                get_local $p1
                i32.load
                i32.load offset=16
                call_indirect (type $t1)
                i32.eqz
                br_if $L21
              end
            end
            i32.const 1
            set_local $l5
            br $B4
          end
          get_local $p0
          i32.const 4
          i32.add
          i32.load
          set_local $l4
          i32.const 1
          set_local $l5
          get_local $p0
          i32.const 24
          i32.add
          tee_local $l3
          i32.load
          get_local $p3
          get_local $p4
          get_local $p0
          i32.const 28
          i32.add
          tee_local $p2
          i32.load
          i32.load offset=12
          call_indirect (type $t0)
          br_if $B4
          get_local $l3
          i32.load
          set_local $p0
          i32.const -1
          set_local $l3
          get_local $p2
          i32.load
          i32.const 16
          i32.add
          set_local $p2
          loop $L22
            get_local $l3
            i32.const 1
            i32.add
            tee_local $l3
            get_local $l2
            i32.ge_u
            br_if $B5
            i32.const 1
            set_local $l5
            get_local $p0
            get_local $l4
            get_local $p2
            i32.load
            call_indirect (type $t1)
            i32.eqz
            br_if $L22
            br $B4
          end
        end
        i32.const 0
        return
      end
      i32.const 0
      return
    end
    get_local $l5)
  (func $_ZN3std9panicking20rust_panic_with_hook17hefd1961cb73ff006E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32)
    i32.const 1
    set_local $l0
    block $B0
      block $B1
        block $B2
          block $B3
            i32.const 0
            i32.load offset=72768
            i32.const 1
            i32.ne
            br_if $B3
            i32.const 0
            i32.const 0
            i32.load offset=72772
            i32.const 1
            i32.add
            tee_local $l0
            i32.store offset=72772
            get_local $l0
            i32.const 3
            i32.lt_u
            br_if $B2
            br $B1
          end
          i32.const 0
          i64.const 4294967297
          i64.store offset=72768
        end
        i32.const 0
        i32.load offset=72776
        tee_local $l1
        i32.const -1
        i32.le_s
        br_if $B1
        i32.const 0
        get_local $l1
        i32.store offset=72776
        get_local $l0
        i32.const 2
        i32.lt_u
        br_if $B0
      end
      unreachable
      unreachable
    end
    call $rust_panic
    unreachable)
  (func $rust_panic (type $t8)
    unreachable
    unreachable)
  (func $_ZN3std9panicking18continue_panic_fmt17h8c6629cbc8212d9fE (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.load offset=8
    call $_ZN4core6option15Option$LT$T$GT$6unwrap17h1251be00da79d034E
    drop
    get_local $l0
    get_local $p0
    i32.const 20
    i32.add
    i64.load align=4
    i64.store offset=8
    get_local $l0
    get_local $p0
    i64.load offset=12 align=4
    i64.store
    get_local $l0
    call $_ZN3std9panicking20rust_panic_with_hook17hefd1961cb73ff006E
    unreachable)
  (func $_ZN4core6option15Option$LT$T$GT$6unwrap17h1251be00da79d034E (type $t3) (param $p0 i32) (result i32)
    block $B0
      get_local $p0
      i32.eqz
      br_if $B0
      get_local $p0
      return
    end
    i32.const 72220
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $_ZN4core3ptr18real_drop_in_place17h198c3d448ebf8f05E (type $t2) (param $p0 i32)
    block $B0
      get_local $p0
      i32.load offset=4
      i32.eqz
      br_if $B0
      get_local $p0
      i32.load
      call $__rust_dealloc
    end)
  (func $_ZN111_$LT$std..sys_common..process..DefaultEnvKey$u20$as$u20$core..borrow..Borrow$LT$std..ffi..os_str..OsStr$GT$$GT$6borrow17h92dc1cb852cfd40dE (type $t4) (param $p0 i32) (param $p1 i32)
    get_local $p0
    get_local $p1
    i32.load offset=8
    i32.store offset=4
    get_local $p0
    get_local $p1
    i32.load
    i32.store)
  (func $_ZN3std5error5Error5cause17hc22d55c663012a04E (type $t4) (param $p0 i32) (param $p1 i32)
    get_local $p0
    i32.const 0
    i32.store)
  (func $_ZN3std5error5Error7type_id17hc0fd654050e42636E (type $t12) (param $p0 i32) (result i64)
    i64.const -7612414196685646406)
  (func $_ZN249_$LT$std..error..$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..boxed..Box$LT$dyn$u20$$u2b$std..error..Error$u2b$core..marker..Sync$u2b$core..marker..Send$GT$$GT$..from..StringError$u20$as$u20$core..fmt..Display$GT$3fmt17hf5ecbeb9aafbf6efE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    get_local $p0
    i32.load
    get_local $p0
    i32.load offset=8
    call $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE)
  (func $_ZN247_$LT$std..error..$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..boxed..Box$LT$dyn$u20$$u2b$std..error..Error$u2b$core..marker..Sync$u2b$core..marker..Send$GT$$GT$..from..StringError$u20$as$u20$core..fmt..Debug$GT$3fmt17hd9e8742f7e5307dfE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    get_global $g0
    i32.const 80
    i32.sub
    tee_local $l0
    set_global $g0
    i32.const 1
    set_local $l1
    block $B0
      get_local $p1
      i32.load offset=24
      i32.const 66132
      i32.const 11
      get_local $p1
      i32.const 28
      i32.add
      tee_local $l2
      i32.load
      i32.load offset=12
      call_indirect (type $t0)
      br_if $B0
      get_local $p1
      i32.const 24
      i32.add
      i32.load
      set_local $l3
      get_local $l2
      i32.load
      i32.load offset=12
      set_local $l2
      block $B1
        block $B2
          get_local $p1
          i32.load8_u
          i32.const 4
          i32.and
          br_if $B2
          i32.const 1
          set_local $l1
          get_local $l3
          i32.const 71742
          i32.const 1
          get_local $l2
          call_indirect (type $t0)
          br_if $B0
          get_local $p0
          get_local $p1
          call $_ZN42_$LT$$RF$T$u20$as$u20$core..fmt..Debug$GT$3fmt17hd20f46a7ef90ae03E
          i32.eqz
          br_if $B1
          br $B0
        end
        get_local $l3
        i32.const 71740
        i32.const 2
        get_local $l2
        call_indirect (type $t0)
        br_if $B0
        get_local $p1
        i32.load
        set_local $l2
        get_local $l0
        i32.const 52
        i32.add
        i32.const 71688
        i32.store
        i32.const 1
        set_local $l1
        get_local $l0
        i32.const 1
        i32.store8 offset=16
        get_local $l0
        get_local $l2
        i32.store offset=24
        get_local $l0
        get_local $p1
        i32.const 24
        i32.add
        i64.load align=4
        i64.store offset=8
        get_local $l0
        get_local $p1
        i32.load8_u offset=48
        i32.store8 offset=72
        get_local $l0
        get_local $p1
        i32.load offset=4
        i32.store offset=28
        get_local $l0
        get_local $p1
        i64.load offset=8 align=4
        i64.store offset=32
        get_local $l0
        get_local $p1
        i64.load offset=40 align=4
        i64.store offset=64
        get_local $l0
        get_local $p1
        i64.load offset=32 align=4
        i64.store offset=56
        get_local $l0
        get_local $p1
        i64.load offset=16 align=4
        i64.store offset=40
        get_local $l0
        get_local $l0
        i32.const 8
        i32.add
        i32.store offset=48
        get_local $p0
        get_local $l0
        i32.const 24
        i32.add
        call $_ZN42_$LT$$RF$T$u20$as$u20$core..fmt..Debug$GT$3fmt17hd20f46a7ef90ae03E
        br_if $B0
        get_local $l0
        i32.const 8
        i32.add
        i32.const 71712
        i32.const 2
        call $_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h11c6108e80c941f6E
        br_if $B0
      end
      get_local $p1
      i32.const 24
      i32.add
      i32.load
      i32.const 71743
      i32.const 1
      get_local $p1
      i32.const 28
      i32.add
      i32.load
      i32.load offset=12
      call_indirect (type $t0)
      set_local $l1
    end
    get_local $l0
    i32.const 80
    i32.add
    set_global $g0
    get_local $l1)
  (func $_ZN42_$LT$$RF$T$u20$as$u20$core..fmt..Debug$GT$3fmt17hd20f46a7ef90ae03E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i32) (local $l9 i32) (local $l10 i32) (local $l11 i32) (local $l12 i32) (local $l13 i32) (local $l14 i32) (local $l15 i32) (local $l16 i64)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.load offset=8
    set_local $l1
    get_local $p0
    i32.load
    set_local $l2
    i32.const 1
    set_local $l3
    block $B0
      get_local $p1
      i32.load offset=24
      i32.const 34
      get_local $p1
      i32.const 28
      i32.add
      i32.load
      i32.load offset=16
      call_indirect (type $t1)
      br_if $B0
      block $B1
        block $B2
          get_local $l1
          i32.eqz
          br_if $B2
          get_local $l2
          get_local $l1
          i32.add
          set_local $l4
          get_local $p1
          i32.const 24
          i32.add
          set_local $l5
          get_local $p1
          i32.const 28
          i32.add
          set_local $l6
          get_local $l2
          set_local $l7
          i32.const 0
          set_local $l8
          i32.const 0
          set_local $l9
          block $B3
            loop $L4
              get_local $l7
              set_local $l10
              get_local $l7
              i32.const 1
              i32.add
              set_local $p0
              block $B5
                block $B6
                  get_local $l7
                  i32.load8_s
                  tee_local $l11
                  i32.const 0
                  i32.lt_s
                  br_if $B6
                  get_local $l11
                  i32.const 255
                  i32.and
                  set_local $l11
                  get_local $p0
                  set_local $l7
                  br $B5
                end
                block $B7
                  block $B8
                    get_local $p0
                    get_local $l4
                    i32.eq
                    br_if $B8
                    get_local $p0
                    i32.load8_u
                    i32.const 63
                    i32.and
                    set_local $l12
                    get_local $l7
                    i32.const 2
                    i32.add
                    tee_local $l7
                    set_local $p0
                    br $B7
                  end
                  i32.const 0
                  set_local $l12
                  get_local $l4
                  set_local $l7
                end
                get_local $l11
                i32.const 31
                i32.and
                set_local $l13
                block $B9
                  block $B10
                    block $B11
                      get_local $l11
                      i32.const 255
                      i32.and
                      tee_local $l11
                      i32.const 224
                      i32.lt_u
                      br_if $B11
                      get_local $l7
                      get_local $l4
                      i32.eq
                      br_if $B10
                      get_local $l7
                      i32.load8_u
                      i32.const 63
                      i32.and
                      set_local $l14
                      get_local $l7
                      i32.const 1
                      i32.add
                      tee_local $p0
                      set_local $l15
                      br $B9
                    end
                    get_local $l12
                    get_local $l13
                    i32.const 6
                    i32.shl
                    i32.or
                    set_local $l11
                    get_local $p0
                    set_local $l7
                    br $B5
                  end
                  i32.const 0
                  set_local $l14
                  get_local $l4
                  set_local $l15
                end
                get_local $l14
                get_local $l12
                i32.const 6
                i32.shl
                i32.or
                set_local $l12
                block $B12
                  block $B13
                    block $B14
                      get_local $l11
                      i32.const 240
                      i32.lt_u
                      br_if $B14
                      get_local $l15
                      get_local $l4
                      i32.eq
                      br_if $B13
                      get_local $l15
                      i32.const 1
                      i32.add
                      set_local $l7
                      get_local $l15
                      i32.load8_u
                      i32.const 63
                      i32.and
                      set_local $l11
                      br $B12
                    end
                    get_local $l12
                    get_local $l13
                    i32.const 12
                    i32.shl
                    i32.or
                    set_local $l11
                    get_local $p0
                    set_local $l7
                    br $B5
                  end
                  i32.const 0
                  set_local $l11
                  get_local $p0
                  set_local $l7
                end
                get_local $l12
                i32.const 6
                i32.shl
                get_local $l13
                i32.const 18
                i32.shl
                i32.const 1835008
                i32.and
                i32.or
                get_local $l11
                i32.or
                tee_local $l11
                i32.const 1114112
                i32.eq
                br_if $B3
              end
              i32.const 2
              set_local $p0
              block $B15
                block $B16
                  block $B17
                    block $B18
                      block $B19
                        block $B20
                          block $B21
                            block $B22
                              block $B23
                                get_local $l11
                                i32.const -9
                                i32.add
                                tee_local $l13
                                i32.const 30
                                i32.gt_u
                                br_if $B23
                                i32.const 116
                                set_local $l12
                                block $B24
                                  get_local $l13
                                  br_table $B16 $B24 $B21 $B21 $B20 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B21 $B22 $B21 $B21 $B21 $B21 $B22 $B16
                                end
                                i32.const 110
                                set_local $l12
                                br $B19
                              end
                              get_local $l11
                              i32.const 92
                              i32.ne
                              br_if $B21
                            end
                            get_local $l11
                            set_local $l12
                            br $B16
                          end
                          get_local $l11
                          call $_ZN4core7unicode9bool_trie8BoolTrie6lookup17h3d273d837ffaaa8eE
                          i32.eqz
                          br_if $B18
                          br $B17
                        end
                        i32.const 114
                        set_local $l12
                      end
                      br $B16
                    end
                    block $B25
                      get_local $l11
                      i32.const 65535
                      i32.gt_u
                      br_if $B25
                      get_local $l11
                      i32.const 67096
                      i32.const 40
                      i32.const 67176
                      i32.const 303
                      i32.const 67479
                      i32.const 316
                      call $_ZN4core7unicode9printable5check17h0590145f81e49885E
                      i32.eqz
                      br_if $B17
                      br $B15
                    end
                    block $B26
                      get_local $l11
                      i32.const 131071
                      i32.gt_u
                      br_if $B26
                      get_local $l11
                      i32.const 67795
                      i32.const 33
                      i32.const 67861
                      i32.const 158
                      i32.const 68019
                      i32.const 381
                      call $_ZN4core7unicode9printable5check17h0590145f81e49885E
                      i32.eqz
                      br_if $B17
                      br $B15
                    end
                    get_local $l11
                    i32.const 917999
                    i32.gt_u
                    br_if $B17
                    get_local $l11
                    i32.const -195102
                    i32.add
                    i32.const 722658
                    i32.lt_u
                    br_if $B17
                    get_local $l11
                    i32.const -191457
                    i32.add
                    i32.const 3103
                    i32.lt_u
                    br_if $B17
                    get_local $l11
                    i32.const -183970
                    i32.add
                    i32.const 14
                    i32.lt_u
                    br_if $B17
                    get_local $l11
                    i32.const 2097150
                    i32.and
                    i32.const 178206
                    i32.eq
                    br_if $B17
                    get_local $l11
                    i32.const -173783
                    i32.add
                    i32.const 41
                    i32.lt_u
                    br_if $B17
                    get_local $l11
                    i32.const -177973
                    i32.add
                    i32.const 10
                    i32.gt_u
                    br_if $B15
                  end
                  get_local $l11
                  i32.const 1
                  i32.or
                  i32.clz
                  i32.const 2
                  i32.shr_u
                  i32.const 7
                  i32.xor
                  i64.extend_u/i32
                  i64.const 21474836480
                  i64.or
                  set_local $l16
                  i32.const 3
                  set_local $p0
                  get_local $l11
                  set_local $l12
                end
                get_local $l0
                get_local $l1
                i32.store offset=4
                get_local $l0
                get_local $l2
                i32.store
                get_local $l0
                get_local $l8
                i32.store offset=8
                get_local $l0
                get_local $l9
                i32.store offset=12
                block $B27
                  get_local $l9
                  get_local $l8
                  i32.lt_u
                  br_if $B27
                  block $B28
                    get_local $l8
                    i32.eqz
                    br_if $B28
                    get_local $l8
                    get_local $l1
                    i32.eq
                    br_if $B28
                    get_local $l8
                    get_local $l1
                    i32.ge_u
                    br_if $B27
                    get_local $l2
                    get_local $l8
                    i32.add
                    i32.load8_s
                    i32.const -65
                    i32.le_s
                    br_if $B27
                  end
                  block $B29
                    get_local $l9
                    i32.eqz
                    br_if $B29
                    get_local $l9
                    get_local $l1
                    i32.eq
                    br_if $B29
                    get_local $l9
                    get_local $l1
                    i32.ge_u
                    br_if $B27
                    get_local $l2
                    get_local $l9
                    i32.add
                    i32.load8_s
                    i32.const -65
                    i32.le_s
                    br_if $B27
                  end
                  block $B30
                    get_local $l5
                    i32.load
                    get_local $l2
                    get_local $l8
                    i32.add
                    get_local $l9
                    get_local $l8
                    i32.sub
                    get_local $l6
                    i32.load
                    i32.load offset=12
                    call_indirect (type $t0)
                    br_if $B30
                    loop $L31
                      block $B32
                        block $B33
                          block $B34
                            block $B35
                              block $B36
                                block $B37
                                  block $B38
                                    get_local $p0
                                    i32.const 1
                                    i32.eq
                                    br_if $B38
                                    i32.const 92
                                    set_local $l8
                                    block $B39
                                      get_local $p0
                                      i32.const 2
                                      i32.eq
                                      br_if $B39
                                      get_local $p0
                                      i32.const 3
                                      i32.ne
                                      br_if $B33
                                      get_local $l16
                                      i64.const 32
                                      i64.shr_u
                                      i32.wrap/i64
                                      i32.const 255
                                      i32.and
                                      i32.const -1
                                      i32.add
                                      tee_local $p0
                                      i32.const 4
                                      i32.gt_u
                                      br_if $B33
                                      block $B40
                                        get_local $p0
                                        br_table $B40 $B34 $B36 $B35 $B37 $B40
                                      end
                                      get_local $l16
                                      i64.const -1095216660481
                                      i64.and
                                      set_local $l16
                                      i32.const 3
                                      set_local $p0
                                      i32.const 125
                                      set_local $l8
                                      br $B32
                                    end
                                    i32.const 1
                                    set_local $p0
                                    br $B32
                                  end
                                  i32.const 0
                                  set_local $p0
                                  get_local $l12
                                  set_local $l8
                                  br $B32
                                end
                                get_local $l16
                                i64.const -1095216660481
                                i64.and
                                i64.const 17179869184
                                i64.or
                                set_local $l16
                                i32.const 3
                                set_local $p0
                                br $B32
                              end
                              get_local $l16
                              i64.const -1095216660481
                              i64.and
                              i64.const 8589934592
                              i64.or
                              set_local $l16
                              i32.const 3
                              set_local $p0
                              i32.const 123
                              set_local $l8
                              br $B32
                            end
                            get_local $l16
                            i64.const -1095216660481
                            i64.and
                            i64.const 12884901888
                            i64.or
                            set_local $l16
                            i32.const 3
                            set_local $p0
                            i32.const 117
                            set_local $l8
                            br $B32
                          end
                          get_local $l12
                          get_local $l16
                          i32.wrap/i64
                          tee_local $l13
                          i32.const 2
                          i32.shl
                          i32.const 28
                          i32.and
                          i32.shr_u
                          i32.const 15
                          i32.and
                          tee_local $p0
                          i32.const 48
                          i32.or
                          get_local $p0
                          i32.const 87
                          i32.add
                          get_local $p0
                          i32.const 10
                          i32.lt_u
                          select
                          set_local $l8
                          block $B41
                            get_local $l13
                            i32.eqz
                            br_if $B41
                            get_local $l16
                            i64.const -1
                            i64.add
                            i64.const 4294967295
                            i64.and
                            get_local $l16
                            i64.const -4294967296
                            i64.and
                            i64.or
                            set_local $l16
                            i32.const 3
                            set_local $p0
                            br $B32
                          end
                          get_local $l16
                          i64.const -1095216660481
                          i64.and
                          i64.const 4294967296
                          i64.or
                          set_local $l16
                          i32.const 3
                          set_local $p0
                          br $B32
                        end
                        i32.const 1
                        set_local $p0
                        block $B42
                          get_local $l11
                          i32.const 128
                          i32.lt_u
                          br_if $B42
                          i32.const 2
                          set_local $p0
                          get_local $l11
                          i32.const 2048
                          i32.lt_u
                          br_if $B42
                          i32.const 3
                          i32.const 4
                          get_local $l11
                          i32.const 65536
                          i32.lt_u
                          select
                          set_local $p0
                        end
                        get_local $p0
                        get_local $l9
                        i32.add
                        set_local $l8
                        br $B15
                      end
                      get_local $l5
                      i32.load
                      get_local $l8
                      get_local $l6
                      i32.load
                      i32.load offset=16
                      call_indirect (type $t1)
                      i32.eqz
                      br_if $L31
                    end
                  end
                  i32.const 1
                  set_local $l3
                  br $B0
                end
                get_local $l0
                get_local $l0
                i32.const 12
                i32.add
                i32.store offset=24
                get_local $l0
                get_local $l0
                i32.const 8
                i32.add
                i32.store offset=20
                get_local $l0
                get_local $l0
                i32.store offset=16
                get_local $l0
                i32.const 16
                i32.add
                call $_ZN4core3str6traits101_$LT$impl$u20$core..slice..SliceIndex$LT$str$GT$$u20$for$u20$core..ops..range..Range$LT$usize$GT$$GT$5index28_$u7b$$u7b$closure$u7d$$u7d$17h5d95040c80ffde5aE
                unreachable
              end
              get_local $l9
              get_local $l10
              i32.sub
              get_local $l7
              i32.add
              set_local $l9
              get_local $l4
              get_local $l7
              i32.ne
              br_if $L4
            end
          end
          get_local $l8
          i32.eqz
          br_if $B1
          get_local $l8
          get_local $l1
          i32.eq
          br_if $B1
          block $B43
            get_local $l8
            get_local $l1
            i32.ge_u
            br_if $B43
            get_local $l2
            get_local $l8
            i32.add
            i32.load8_s
            i32.const -65
            i32.gt_s
            br_if $B1
          end
          get_local $l2
          get_local $l1
          get_local $l8
          get_local $l1
          call $_ZN4core3str16slice_error_fail17h900806e520ed8aa4E
          unreachable
        end
        i32.const 0
        set_local $l8
      end
      get_local $p1
      i32.const 24
      i32.add
      tee_local $p0
      i32.load
      get_local $l2
      get_local $l8
      i32.add
      get_local $l1
      get_local $l8
      i32.sub
      get_local $p1
      i32.const 28
      i32.add
      tee_local $l9
      i32.load
      i32.load offset=12
      call_indirect (type $t0)
      br_if $B0
      get_local $p0
      i32.load
      i32.const 34
      get_local $l9
      i32.load
      i32.load offset=16
      call_indirect (type $t1)
      set_local $l3
    end
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $l3)
  (func $_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h11c6108e80c941f6E (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i32) (local $l9 i32) (local $l10 i32) (local $l11 i32) (local $l12 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p2
              i32.eqz
              br_if $B4
              get_local $l0
              i32.const 40
              i32.add
              set_local $l1
              get_local $p0
              i32.const 8
              i32.add
              set_local $l2
              get_local $l0
              i32.const 32
              i32.add
              set_local $l3
              get_local $l0
              i32.const 28
              i32.add
              set_local $l4
              get_local $l0
              i32.const 36
              i32.add
              set_local $l5
              get_local $p0
              i32.const 4
              i32.add
              set_local $l6
              loop $L5
                block $B6
                  get_local $l2
                  i32.load8_u
                  i32.eqz
                  br_if $B6
                  get_local $p0
                  i32.load
                  i32.const 71682
                  i32.const 4
                  get_local $l6
                  i32.load
                  i32.load offset=12
                  call_indirect (type $t0)
                  br_if $B3
                end
                get_local $l1
                i32.const 10
                i32.store
                get_local $l3
                i64.const 4294967306
                i64.store
                get_local $l4
                get_local $p2
                i32.store
                get_local $l0
                i32.const 16
                i32.add
                i32.const 8
                i32.add
                tee_local $l7
                i32.const 0
                i32.store
                get_local $l0
                get_local $p2
                i32.store offset=20
                get_local $l0
                get_local $p1
                i32.store offset=16
                get_local $l0
                i32.const 8
                i32.add
                i32.const 10
                get_local $p1
                get_local $p2
                call $_ZN4core5slice6memchr6memchr17h2b18dfe5a03392f7E
                block $B7
                  block $B8
                    block $B9
                      block $B10
                        block $B11
                          get_local $l0
                          i32.load offset=8
                          i32.const 1
                          i32.ne
                          br_if $B11
                          get_local $l0
                          i32.load offset=12
                          set_local $l8
                          loop $L12
                            get_local $l7
                            get_local $l8
                            get_local $l7
                            i32.load
                            i32.add
                            i32.const 1
                            i32.add
                            tee_local $l8
                            i32.store
                            block $B13
                              block $B14
                                get_local $l8
                                get_local $l5
                                i32.load
                                tee_local $l9
                                i32.ge_u
                                br_if $B14
                                get_local $l0
                                i32.load offset=20
                                set_local $l10
                                br $B13
                              end
                              get_local $l0
                              i32.load offset=20
                              tee_local $l10
                              get_local $l8
                              i32.lt_u
                              br_if $B13
                              get_local $l9
                              i32.const 5
                              i32.ge_u
                              br_if $B8
                              get_local $l0
                              i32.load offset=16
                              get_local $l8
                              get_local $l9
                              i32.sub
                              tee_local $l11
                              i32.add
                              tee_local $l12
                              get_local $l1
                              i32.eq
                              br_if $B9
                              get_local $l12
                              get_local $l1
                              get_local $l9
                              call $memcmp
                              i32.eqz
                              br_if $B9
                            end
                            get_local $l4
                            i32.load
                            tee_local $l12
                            get_local $l8
                            i32.lt_u
                            br_if $B10
                            get_local $l10
                            get_local $l12
                            i32.lt_u
                            br_if $B10
                            get_local $l0
                            get_local $l0
                            i32.const 16
                            i32.add
                            get_local $l9
                            i32.add
                            i32.const 23
                            i32.add
                            i32.load8_u
                            get_local $l0
                            i32.load offset=16
                            get_local $l8
                            i32.add
                            get_local $l12
                            get_local $l8
                            i32.sub
                            call $_ZN4core5slice6memchr6memchr17h2b18dfe5a03392f7E
                            get_local $l0
                            i32.load offset=4
                            set_local $l8
                            get_local $l0
                            i32.load
                            i32.const 1
                            i32.eq
                            br_if $L12
                          end
                        end
                        get_local $l7
                        get_local $l4
                        i32.load
                        i32.store
                      end
                      get_local $l2
                      i32.const 0
                      i32.store8
                      get_local $p2
                      set_local $l8
                      br $B7
                    end
                    get_local $l2
                    i32.const 1
                    i32.store8
                    get_local $l11
                    i32.const 1
                    i32.add
                    set_local $l8
                    br $B7
                  end
                  get_local $l9
                  i32.const 4
                  call $_ZN4core5slice20slice_index_len_fail17h00bfcf67cecaf929E
                  unreachable
                end
                get_local $l6
                i32.load
                set_local $l12
                get_local $p0
                i32.load
                set_local $l9
                block $B15
                  get_local $l8
                  i32.eqz
                  get_local $p2
                  get_local $l8
                  i32.eq
                  i32.or
                  tee_local $l7
                  br_if $B15
                  get_local $p2
                  get_local $l8
                  i32.le_u
                  br_if $B1
                  get_local $p1
                  get_local $l8
                  i32.add
                  i32.load8_s
                  i32.const -65
                  i32.le_s
                  br_if $B1
                end
                get_local $l9
                get_local $p1
                get_local $l8
                get_local $l12
                i32.load offset=12
                call_indirect (type $t0)
                br_if $B3
                block $B16
                  get_local $l7
                  br_if $B16
                  get_local $p2
                  get_local $l8
                  i32.le_u
                  br_if $B0
                  get_local $p1
                  get_local $l8
                  i32.add
                  i32.load8_s
                  i32.const -65
                  i32.le_s
                  br_if $B0
                end
                get_local $p1
                get_local $l8
                i32.add
                set_local $p1
                get_local $p2
                get_local $l8
                i32.sub
                tee_local $p2
                br_if $L5
              end
            end
            i32.const 0
            set_local $l8
            br $B2
          end
          i32.const 1
          set_local $l8
        end
        get_local $l0
        i32.const 48
        i32.add
        set_global $g0
        get_local $l8
        return
      end
      get_local $p1
      get_local $p2
      i32.const 0
      get_local $l8
      call $_ZN4core3str16slice_error_fail17h900806e520ed8aa4E
      unreachable
    end
    get_local $p1
    get_local $p2
    get_local $l8
    get_local $p2
    call $_ZN4core3str16slice_error_fail17h900806e520ed8aa4E
    unreachable)
  (func $_ZN4core7unicode9bool_trie8BoolTrie6lookup17h3d273d837ffaaa8eE (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32)
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                block $B6
                  get_local $p0
                  i32.const 2047
                  i32.gt_u
                  br_if $B6
                  get_local $p0
                  i32.const 3
                  i32.shr_u
                  i32.const 536870904
                  i32.and
                  i32.const 68400
                  i32.add
                  set_local $l0
                  br $B5
                end
                block $B7
                  get_local $p0
                  i32.const 65535
                  i32.gt_u
                  br_if $B7
                  get_local $p0
                  i32.const 6
                  i32.shr_u
                  i32.const -32
                  i32.add
                  tee_local $l0
                  i32.const 991
                  i32.gt_u
                  br_if $B4
                  get_local $l0
                  i32.const 68680
                  i32.add
                  i32.load8_u
                  tee_local $l0
                  i32.const 73
                  i32.gt_u
                  br_if $B3
                  get_local $l0
                  i32.const 3
                  i32.shl
                  i32.const 70048
                  i32.add
                  set_local $l0
                  br $B5
                end
                get_local $p0
                i32.const 12
                i32.shr_u
                i32.const -16
                i32.add
                tee_local $l0
                i32.const 255
                i32.gt_u
                br_if $B2
                get_local $l0
                i32.const 69672
                i32.add
                i32.load8_u
                i32.const 6
                i32.shl
                get_local $p0
                i32.const 6
                i32.shr_u
                i32.const 63
                i32.and
                i32.or
                tee_local $l0
                i32.const 511
                i32.gt_u
                br_if $B1
                get_local $l0
                i32.const 70640
                i32.add
                i32.load8_u
                tee_local $l0
                i32.const 54
                i32.gt_u
                br_if $B0
                get_local $l0
                i32.const 3
                i32.shl
                i32.const 71152
                i32.add
                set_local $l0
              end
              get_local $l0
              i64.load
              i64.const 1
              get_local $p0
              i32.const 63
              i32.and
              i64.extend_u/i32
              i64.shl
              i64.and
              i64.const 0
              i64.ne
              return
            end
            i32.const 69928
            get_local $l0
            i32.const 992
            call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
            unreachable
          end
          i32.const 69944
          get_local $l0
          i32.const 74
          call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
          unreachable
        end
        i32.const 69960
        get_local $l0
        i32.const 256
        call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
        unreachable
      end
      i32.const 69976
      get_local $l0
      i32.const 512
      call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
      unreachable
    end
    i32.const 69992
    get_local $l0
    i32.const 55
    call $_ZN4core9panicking18panic_bounds_check17h683d2ab324274178E
    unreachable)
  (func $_ZN4core7unicode9printable5check17h0590145f81e49885E (type $t13) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32) (param $p4 i32) (param $p5 i32) (param $p6 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32)
    get_local $p1
    get_local $p2
    i32.const 1
    i32.shl
    i32.add
    set_local $l0
    get_local $p0
    i32.const 65280
    i32.and
    i32.const 8
    i32.shr_u
    set_local $l1
    i32.const 0
    set_local $l2
    get_local $p0
    i32.const 255
    i32.and
    set_local $l3
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                loop $L6
                  get_local $p1
                  i32.const 2
                  i32.add
                  set_local $l4
                  get_local $l2
                  get_local $p1
                  i32.load8_u offset=1
                  tee_local $p2
                  i32.add
                  set_local $l5
                  block $B7
                    block $B8
                      get_local $p1
                      i32.load8_u
                      tee_local $p1
                      get_local $l1
                      i32.ne
                      br_if $B8
                      get_local $l5
                      get_local $l2
                      i32.lt_u
                      br_if $B2
                      get_local $l5
                      get_local $p4
                      i32.gt_u
                      br_if $B1
                      get_local $p3
                      get_local $l2
                      i32.add
                      set_local $p1
                      loop $L9
                        get_local $p2
                        i32.eqz
                        br_if $B7
                        get_local $p2
                        i32.const -1
                        i32.add
                        set_local $p2
                        get_local $p1
                        i32.load8_u
                        set_local $l2
                        get_local $p1
                        i32.const 1
                        i32.add
                        set_local $p1
                        get_local $l2
                        get_local $l3
                        i32.ne
                        br_if $L9
                        br $B4
                      end
                    end
                    get_local $p1
                    get_local $l1
                    i32.gt_u
                    br_if $B5
                    get_local $l5
                    set_local $l2
                    get_local $l4
                    set_local $p1
                    get_local $l4
                    get_local $l0
                    i32.ne
                    br_if $L6
                    br $B5
                  end
                  get_local $l5
                  set_local $l2
                  get_local $l4
                  set_local $p1
                  get_local $l4
                  get_local $l0
                  i32.ne
                  br_if $L6
                end
              end
              get_local $p0
              i32.const 65535
              i32.and
              set_local $l2
              get_local $p5
              get_local $p6
              i32.add
              set_local $l5
              i32.const 1
              set_local $p2
              loop $L10
                get_local $p5
                i32.const 1
                i32.add
                set_local $l3
                block $B11
                  block $B12
                    get_local $p5
                    i32.load8_u
                    tee_local $p1
                    i32.const 24
                    i32.shl
                    i32.const 24
                    i32.shr_s
                    tee_local $l4
                    i32.const -1
                    i32.le_s
                    br_if $B12
                    get_local $l3
                    set_local $p5
                    br $B11
                  end
                  get_local $l3
                  get_local $l5
                  i32.eq
                  br_if $B0
                  get_local $l4
                  i32.const 127
                  i32.and
                  i32.const 8
                  i32.shl
                  get_local $p5
                  i32.const 1
                  i32.add
                  i32.load8_u
                  i32.or
                  set_local $p1
                  get_local $p5
                  i32.const 2
                  i32.add
                  set_local $p5
                end
                get_local $l2
                get_local $p1
                i32.sub
                tee_local $l2
                i32.const 0
                i32.lt_s
                br_if $B3
                get_local $p2
                i32.const 1
                i32.xor
                set_local $p2
                get_local $p5
                get_local $l5
                i32.ne
                br_if $L10
                br $B3
              end
            end
            i32.const 0
            set_local $p2
          end
          get_local $p2
          i32.const 1
          i32.and
          return
        end
        get_local $l2
        get_local $l5
        call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
        unreachable
      end
      get_local $l5
      get_local $p4
      call $_ZN4core5slice20slice_index_len_fail17h00bfcf67cecaf929E
      unreachable
    end
    i32.const 72220
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $_ZN4core3str6traits101_$LT$impl$u20$core..slice..SliceIndex$LT$str$GT$$u20$for$u20$core..ops..range..Range$LT$usize$GT$$GT$5index28_$u7b$$u7b$closure$u7d$$u7d$17h5d95040c80ffde5aE (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_local $p0
    i32.load
    tee_local $l0
    i32.load
    get_local $l0
    i32.load offset=4
    get_local $p0
    i32.load offset=4
    i32.load
    get_local $p0
    i32.load offset=8
    i32.load
    call $_ZN4core3str16slice_error_fail17h900806e520ed8aa4E
    unreachable)
  (func $_ZN4core3str16slice_error_fail17h900806e520ed8aa4E (type $t7) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32)
    get_global $g0
    i32.const 112
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p3
    i32.store offset=12
    get_local $l0
    get_local $p2
    i32.store offset=8
    i32.const 1
    set_local $l1
    get_local $p1
    set_local $l2
    block $B0
      get_local $p1
      i32.const 257
      i32.lt_u
      br_if $B0
      i32.const 0
      get_local $p1
      i32.sub
      set_local $l3
      i32.const 256
      set_local $l4
      block $B1
        loop $L2
          block $B3
            get_local $l4
            get_local $p1
            i32.ge_u
            br_if $B3
            get_local $p0
            get_local $l4
            i32.add
            i32.load8_s
            i32.const -65
            i32.gt_s
            br_if $B1
          end
          get_local $l4
          i32.const -1
          i32.add
          set_local $l2
          i32.const 0
          set_local $l1
          get_local $l4
          i32.const 1
          i32.eq
          br_if $B0
          get_local $l3
          get_local $l4
          i32.add
          set_local $l5
          get_local $l2
          set_local $l4
          get_local $l5
          i32.const 1
          i32.ne
          br_if $L2
          br $B0
        end
      end
      i32.const 0
      set_local $l1
      get_local $l4
      set_local $l2
    end
    get_local $l0
    get_local $l2
    i32.store offset=20
    get_local $l0
    get_local $p0
    i32.store offset=16
    get_local $l0
    i32.const 0
    i32.const 5
    get_local $l1
    select
    i32.store offset=28
    get_local $l0
    i32.const 66356
    i32.const 66790
    get_local $l1
    select
    i32.store offset=24
    block $B4
      block $B5
        block $B6
          get_local $p2
          get_local $p1
          i32.gt_u
          tee_local $l4
          br_if $B6
          get_local $p3
          get_local $p1
          i32.gt_u
          br_if $B6
          get_local $p2
          get_local $p3
          i32.gt_u
          br_if $B5
          block $B7
            block $B8
              get_local $p2
              i32.eqz
              br_if $B8
              get_local $p1
              get_local $p2
              i32.eq
              br_if $B8
              get_local $p1
              get_local $p2
              i32.le_u
              br_if $B7
              get_local $p0
              get_local $p2
              i32.add
              i32.load8_s
              i32.const -64
              i32.lt_s
              br_if $B7
            end
            get_local $p3
            set_local $p2
          end
          get_local $l0
          get_local $p2
          i32.store offset=32
          block $B9
            block $B10
              get_local $p2
              i32.eqz
              br_if $B10
              get_local $p2
              get_local $p1
              i32.eq
              br_if $B10
              get_local $p1
              i32.const 1
              i32.add
              set_local $l5
              loop $L11
                block $B12
                  get_local $p2
                  get_local $p1
                  i32.ge_u
                  br_if $B12
                  get_local $p0
                  get_local $p2
                  i32.add
                  i32.load8_s
                  i32.const -64
                  i32.ge_s
                  br_if $B10
                end
                get_local $p2
                i32.const -1
                i32.add
                set_local $l4
                get_local $p2
                i32.const 1
                i32.eq
                br_if $B9
                get_local $l5
                get_local $p2
                i32.eq
                set_local $l2
                get_local $l4
                set_local $p2
                get_local $l2
                i32.eqz
                br_if $L11
                br $B9
              end
            end
            get_local $p2
            set_local $l4
          end
          get_local $l4
          get_local $p1
          i32.eq
          br_if $B4
          i32.const 1
          set_local $l2
          i32.const 0
          set_local $l1
          block $B13
            block $B14
              get_local $p0
              get_local $l4
              i32.add
              tee_local $l5
              i32.load8_s
              tee_local $p2
              i32.const 0
              i32.lt_s
              br_if $B14
              get_local $l0
              get_local $p2
              i32.const 255
              i32.and
              i32.store offset=36
              get_local $l0
              i32.const 40
              i32.add
              set_local $p2
              br $B13
            end
            get_local $p0
            get_local $p1
            i32.add
            tee_local $l2
            set_local $p1
            block $B15
              get_local $l5
              i32.const 1
              i32.add
              get_local $l2
              i32.eq
              br_if $B15
              get_local $l5
              i32.const 2
              i32.add
              set_local $p1
              get_local $l5
              i32.const 1
              i32.add
              i32.load8_u
              i32.const 63
              i32.and
              set_local $l1
            end
            get_local $p2
            i32.const 31
            i32.and
            set_local $l5
            block $B16
              block $B17
                block $B18
                  get_local $p2
                  i32.const 255
                  i32.and
                  i32.const 224
                  i32.lt_u
                  br_if $B18
                  i32.const 0
                  set_local $p0
                  get_local $l2
                  set_local $l3
                  block $B19
                    get_local $p1
                    get_local $l2
                    i32.eq
                    br_if $B19
                    get_local $p1
                    i32.const 1
                    i32.add
                    set_local $l3
                    get_local $p1
                    i32.load8_u
                    i32.const 63
                    i32.and
                    set_local $p0
                  end
                  get_local $p0
                  get_local $l1
                  i32.const 6
                  i32.shl
                  i32.or
                  set_local $p1
                  get_local $p2
                  i32.const 255
                  i32.and
                  i32.const 240
                  i32.lt_u
                  br_if $B17
                  i32.const 0
                  set_local $p2
                  block $B20
                    get_local $l3
                    get_local $l2
                    i32.eq
                    br_if $B20
                    get_local $l3
                    i32.load8_u
                    i32.const 63
                    i32.and
                    set_local $p2
                  end
                  get_local $p1
                  i32.const 6
                  i32.shl
                  get_local $l5
                  i32.const 18
                  i32.shl
                  i32.const 1835008
                  i32.and
                  i32.or
                  get_local $p2
                  i32.or
                  tee_local $p1
                  i32.const 1114112
                  i32.eq
                  br_if $B4
                  br $B16
                end
                get_local $l1
                get_local $l5
                i32.const 6
                i32.shl
                i32.or
                set_local $p1
                br $B16
              end
              get_local $p1
              get_local $l5
              i32.const 12
              i32.shl
              i32.or
              set_local $p1
            end
            get_local $l0
            get_local $p1
            i32.store offset=36
            i32.const 1
            set_local $l2
            get_local $l0
            i32.const 40
            i32.add
            set_local $p2
            get_local $p1
            i32.const 128
            i32.lt_u
            br_if $B13
            i32.const 2
            set_local $l2
            get_local $p1
            i32.const 2048
            i32.lt_u
            br_if $B13
            i32.const 3
            i32.const 4
            get_local $p1
            i32.const 65536
            i32.lt_u
            select
            set_local $l2
          end
          get_local $l0
          get_local $l4
          i32.store offset=40
          get_local $l0
          get_local $l2
          get_local $l4
          i32.add
          i32.store offset=44
          get_local $l0
          i32.const 108
          i32.add
          i32.const 14
          i32.store
          get_local $l0
          i32.const 100
          i32.add
          i32.const 14
          i32.store
          get_local $l0
          i32.const 72
          i32.add
          i32.const 20
          i32.add
          i32.const 15
          i32.store
          get_local $l0
          i32.const 84
          i32.add
          i32.const 16
          i32.store
          get_local $l0
          i32.const 48
          i32.add
          i32.const 20
          i32.add
          i32.const 5
          i32.store
          get_local $l0
          get_local $p2
          i32.store offset=88
          get_local $l0
          i32.const 10
          i32.store offset=76
          get_local $l0
          i64.const 5
          i64.store offset=52 align=4
          get_local $l0
          i32.const 66884
          i32.store offset=48
          get_local $l0
          get_local $l0
          i32.const 24
          i32.add
          i32.store offset=104
          get_local $l0
          get_local $l0
          i32.const 16
          i32.add
          i32.store offset=96
          get_local $l0
          get_local $l0
          i32.const 36
          i32.add
          i32.store offset=80
          get_local $l0
          get_local $l0
          i32.const 32
          i32.add
          i32.store offset=72
          get_local $l0
          get_local $l0
          i32.const 72
          i32.add
          i32.store offset=64
          get_local $l0
          i32.const 48
          i32.add
          i32.const 66924
          call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
          unreachable
        end
        get_local $l0
        get_local $p2
        get_local $p3
        get_local $l4
        select
        i32.store offset=40
        get_local $l0
        i32.const 72
        i32.add
        i32.const 20
        i32.add
        i32.const 14
        i32.store
        get_local $l0
        i32.const 84
        i32.add
        i32.const 14
        i32.store
        get_local $l0
        i32.const 48
        i32.add
        i32.const 20
        i32.add
        i32.const 3
        i32.store
        get_local $l0
        i32.const 10
        i32.store offset=76
        get_local $l0
        i64.const 3
        i64.store offset=52 align=4
        get_local $l0
        i32.const 66796
        i32.store offset=48
        get_local $l0
        get_local $l0
        i32.const 24
        i32.add
        i32.store offset=88
        get_local $l0
        get_local $l0
        i32.const 16
        i32.add
        i32.store offset=80
        get_local $l0
        get_local $l0
        i32.const 40
        i32.add
        i32.store offset=72
        get_local $l0
        get_local $l0
        i32.const 72
        i32.add
        i32.store offset=64
        get_local $l0
        i32.const 48
        i32.add
        i32.const 66820
        call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
        unreachable
      end
      get_local $l0
      i32.const 100
      i32.add
      i32.const 14
      i32.store
      get_local $l0
      i32.const 72
      i32.add
      i32.const 20
      i32.add
      i32.const 14
      i32.store
      get_local $l0
      i32.const 84
      i32.add
      i32.const 10
      i32.store
      get_local $l0
      i32.const 48
      i32.add
      i32.const 20
      i32.add
      i32.const 4
      i32.store
      get_local $l0
      i32.const 10
      i32.store offset=76
      get_local $l0
      i64.const 4
      i64.store offset=52 align=4
      get_local $l0
      i32.const 66836
      i32.store offset=48
      get_local $l0
      get_local $l0
      i32.const 24
      i32.add
      i32.store offset=96
      get_local $l0
      get_local $l0
      i32.const 16
      i32.add
      i32.store offset=88
      get_local $l0
      get_local $l0
      i32.const 12
      i32.add
      i32.store offset=80
      get_local $l0
      get_local $l0
      i32.const 8
      i32.add
      i32.store offset=72
      get_local $l0
      get_local $l0
      i32.const 72
      i32.add
      i32.store offset=64
      get_local $l0
      i32.const 48
      i32.add
      i32.const 66868
      call $_ZN4core9panicking9panic_fmt17h315e732055dee1aaE
      unreachable
    end
    i32.const 72220
    call $_ZN4core9panicking5panic17ha366c5556fbdacabE
    unreachable)
  (func $__rdl_alloc (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p1
              i32.const 8
              i32.le_u
              br_if $B4
              i32.const 0
              set_local $l0
              i32.const -65587
              get_local $p1
              i32.const 16
              get_local $p1
              i32.const 16
              i32.gt_u
              select
              tee_local $p1
              i32.sub
              get_local $p0
              i32.le_u
              br_if $B0
              get_local $p1
              i32.const 16
              get_local $p0
              i32.const 11
              i32.add
              i32.const -8
              i32.and
              get_local $p0
              i32.const 11
              i32.lt_u
              select
              tee_local $l1
              i32.add
              i32.const 12
              i32.add
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc6malloc17hfb413fb9fd725095E
              tee_local $p0
              i32.eqz
              br_if $B0
              get_local $p0
              i32.const -8
              i32.add
              set_local $l0
              get_local $p1
              i32.const -1
              i32.add
              tee_local $l2
              get_local $p0
              i32.and
              i32.eqz
              br_if $B3
              get_local $p0
              i32.const -4
              i32.add
              tee_local $l3
              i32.load
              tee_local $l4
              i32.const -8
              i32.and
              get_local $l2
              get_local $p0
              i32.add
              i32.const 0
              get_local $p1
              i32.sub
              i32.and
              i32.const -8
              i32.add
              tee_local $p0
              get_local $p0
              get_local $p1
              i32.add
              get_local $p0
              get_local $l0
              i32.sub
              i32.const 16
              i32.gt_u
              select
              tee_local $p1
              get_local $l0
              i32.sub
              tee_local $p0
              i32.sub
              set_local $l2
              get_local $l4
              i32.const 3
              i32.and
              i32.eqz
              br_if $B2
              get_local $p1
              get_local $l2
              get_local $p1
              i32.load offset=4
              i32.const 1
              i32.and
              i32.or
              i32.const 2
              i32.or
              i32.store offset=4
              get_local $p1
              get_local $l2
              i32.add
              tee_local $l2
              get_local $l2
              i32.load offset=4
              i32.const 1
              i32.or
              i32.store offset=4
              get_local $l3
              get_local $p0
              get_local $l3
              i32.load
              i32.const 1
              i32.and
              i32.or
              i32.const 2
              i32.or
              i32.store
              get_local $p1
              get_local $p1
              i32.load offset=4
              i32.const 1
              i32.or
              i32.store offset=4
              get_local $l0
              get_local $p0
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc13dispose_chunk17hae5b7b0a563f1cedE
              br $B1
            end
            get_local $p0
            call $_ZN8dlmalloc8dlmalloc8Dlmalloc6malloc17hfb413fb9fd725095E
            return
          end
          get_local $l0
          set_local $p1
          br $B1
        end
        get_local $l0
        i32.load
        set_local $l0
        get_local $p1
        get_local $l2
        i32.store offset=4
        get_local $p1
        get_local $l0
        get_local $p0
        i32.add
        i32.store
      end
      block $B5
        get_local $p1
        i32.load offset=4
        tee_local $p0
        i32.const 3
        i32.and
        i32.eqz
        br_if $B5
        get_local $p0
        i32.const -8
        i32.and
        tee_local $l0
        get_local $l1
        i32.const 16
        i32.add
        i32.le_u
        br_if $B5
        get_local $p1
        i32.const 4
        i32.add
        get_local $l1
        get_local $p0
        i32.const 1
        i32.and
        i32.or
        i32.const 2
        i32.or
        i32.store
        get_local $p1
        get_local $l1
        i32.add
        tee_local $p0
        get_local $l0
        get_local $l1
        i32.sub
        tee_local $l1
        i32.const 3
        i32.or
        i32.store offset=4
        get_local $p1
        get_local $l0
        i32.add
        tee_local $l0
        get_local $l0
        i32.load offset=4
        i32.const 1
        i32.or
        i32.store offset=4
        get_local $p0
        get_local $l1
        call $_ZN8dlmalloc8dlmalloc8Dlmalloc13dispose_chunk17hae5b7b0a563f1cedE
      end
      get_local $p1
      i32.const 8
      i32.add
      set_local $l0
    end
    get_local $l0)
  (func $_ZN8dlmalloc8dlmalloc8Dlmalloc6malloc17hfb413fb9fd725095E (type $t3) (param $p0 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32) (local $l8 i64)
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                block $B6
                  block $B7
                    block $B8
                      block $B9
                        block $B10
                          block $B11
                            block $B12
                              block $B13
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
                                                        block $B26
                                                          block $B27
                                                            block $B28
                                                              block $B29
                                                                block $B30
                                                                  block $B31
                                                                    block $B32
                                                                      block $B33
                                                                        block $B34
                                                                          block $B35
                                                                            block $B36
                                                                              get_local $p0
                                                                              i32.const 244
                                                                              i32.gt_u
                                                                              br_if $B36
                                                                              i32.const 0
                                                                              i32.load offset=72312
                                                                              tee_local $l0
                                                                              i32.const 16
                                                                              get_local $p0
                                                                              i32.const 11
                                                                              i32.add
                                                                              i32.const -8
                                                                              i32.and
                                                                              get_local $p0
                                                                              i32.const 11
                                                                              i32.lt_u
                                                                              select
                                                                              tee_local $l1
                                                                              i32.const 3
                                                                              i32.shr_u
                                                                              tee_local $l2
                                                                              i32.const 31
                                                                              i32.and
                                                                              tee_local $l3
                                                                              i32.shr_u
                                                                              tee_local $p0
                                                                              i32.const 3
                                                                              i32.and
                                                                              i32.eqz
                                                                              br_if $B35
                                                                              get_local $p0
                                                                              i32.const -1
                                                                              i32.xor
                                                                              i32.const 1
                                                                              i32.and
                                                                              get_local $l2
                                                                              i32.add
                                                                              tee_local $l1
                                                                              i32.const 3
                                                                              i32.shl
                                                                              tee_local $l4
                                                                              i32.const 72328
                                                                              i32.add
                                                                              i32.load
                                                                              tee_local $p0
                                                                              i32.const 8
                                                                              i32.add
                                                                              set_local $l2
                                                                              get_local $p0
                                                                              i32.load offset=8
                                                                              tee_local $l3
                                                                              get_local $l4
                                                                              i32.const 72320
                                                                              i32.add
                                                                              tee_local $l4
                                                                              i32.eq
                                                                              br_if $B34
                                                                              get_local $l3
                                                                              get_local $l4
                                                                              i32.store offset=12
                                                                              get_local $l4
                                                                              i32.const 8
                                                                              i32.add
                                                                              get_local $l3
                                                                              i32.store
                                                                              br $B33
                                                                            end
                                                                            i32.const 0
                                                                            set_local $l2
                                                                            get_local $p0
                                                                            i32.const -65588
                                                                            i32.gt_u
                                                                            br_if $B0
                                                                            get_local $p0
                                                                            i32.const 11
                                                                            i32.add
                                                                            tee_local $p0
                                                                            i32.const -8
                                                                            i32.and
                                                                            set_local $l1
                                                                            i32.const 0
                                                                            i32.load offset=72316
                                                                            tee_local $l5
                                                                            i32.eqz
                                                                            br_if $B26
                                                                            i32.const 0
                                                                            set_local $l6
                                                                            block $B37
                                                                              get_local $p0
                                                                              i32.const 8
                                                                              i32.shr_u
                                                                              tee_local $p0
                                                                              i32.eqz
                                                                              br_if $B37
                                                                              i32.const 31
                                                                              set_local $l6
                                                                              get_local $l1
                                                                              i32.const 16777215
                                                                              i32.gt_u
                                                                              br_if $B37
                                                                              get_local $l1
                                                                              i32.const 38
                                                                              get_local $p0
                                                                              i32.clz
                                                                              tee_local $p0
                                                                              i32.sub
                                                                              i32.const 31
                                                                              i32.and
                                                                              i32.shr_u
                                                                              i32.const 1
                                                                              i32.and
                                                                              i32.const 31
                                                                              get_local $p0
                                                                              i32.sub
                                                                              i32.const 1
                                                                              i32.shl
                                                                              i32.or
                                                                              set_local $l6
                                                                            end
                                                                            i32.const 0
                                                                            get_local $l1
                                                                            i32.sub
                                                                            set_local $l2
                                                                            get_local $l6
                                                                            i32.const 2
                                                                            i32.shl
                                                                            i32.const 72584
                                                                            i32.add
                                                                            i32.load
                                                                            tee_local $p0
                                                                            i32.eqz
                                                                            br_if $B29
                                                                            i32.const 0
                                                                            set_local $l3
                                                                            get_local $l1
                                                                            i32.const 0
                                                                            i32.const 25
                                                                            get_local $l6
                                                                            i32.const 1
                                                                            i32.shr_u
                                                                            i32.sub
                                                                            i32.const 31
                                                                            i32.and
                                                                            get_local $l6
                                                                            i32.const 31
                                                                            i32.eq
                                                                            select
                                                                            i32.shl
                                                                            set_local $l4
                                                                            i32.const 0
                                                                            set_local $l0
                                                                            loop $L38
                                                                              block $B39
                                                                                get_local $p0
                                                                                i32.load offset=4
                                                                                i32.const -8
                                                                                i32.and
                                                                                tee_local $l7
                                                                                get_local $l1
                                                                                i32.lt_u
                                                                                br_if $B39
                                                                                get_local $l7
                                                                                get_local $l1
                                                                                i32.sub
                                                                                tee_local $l7
                                                                                get_local $l2
                                                                                i32.ge_u
                                                                                br_if $B39
                                                                                get_local $l7
                                                                                set_local $l2
                                                                                get_local $p0
                                                                                set_local $l0
                                                                                get_local $l7
                                                                                i32.eqz
                                                                                br_if $B31
                                                                              end
                                                                              get_local $p0
                                                                              i32.const 20
                                                                              i32.add
                                                                              i32.load
                                                                              tee_local $l7
                                                                              get_local $l3
                                                                              get_local $l7
                                                                              get_local $p0
                                                                              get_local $l4
                                                                              i32.const 29
                                                                              i32.shr_u
                                                                              i32.const 4
                                                                              i32.and
                                                                              i32.add
                                                                              i32.const 16
                                                                              i32.add
                                                                              i32.load
                                                                              tee_local $p0
                                                                              i32.ne
                                                                              select
                                                                              get_local $l3
                                                                              get_local $l7
                                                                              select
                                                                              set_local $l3
                                                                              get_local $l4
                                                                              i32.const 1
                                                                              i32.shl
                                                                              set_local $l4
                                                                              get_local $p0
                                                                              br_if $L38
                                                                            end
                                                                            get_local $l3
                                                                            i32.eqz
                                                                            br_if $B30
                                                                            get_local $l3
                                                                            set_local $p0
                                                                            br $B28
                                                                          end
                                                                          get_local $l1
                                                                          i32.const 0
                                                                          i32.load offset=72712
                                                                          i32.le_u
                                                                          br_if $B26
                                                                          get_local $p0
                                                                          i32.eqz
                                                                          br_if $B32
                                                                          get_local $p0
                                                                          get_local $l3
                                                                          i32.shl
                                                                          i32.const 2
                                                                          get_local $l3
                                                                          i32.shl
                                                                          tee_local $p0
                                                                          i32.const 0
                                                                          get_local $p0
                                                                          i32.sub
                                                                          i32.or
                                                                          i32.and
                                                                          tee_local $p0
                                                                          i32.const 0
                                                                          get_local $p0
                                                                          i32.sub
                                                                          i32.and
                                                                          i32.ctz
                                                                          tee_local $l2
                                                                          i32.const 3
                                                                          i32.shl
                                                                          tee_local $l4
                                                                          i32.const 72328
                                                                          i32.add
                                                                          i32.load
                                                                          tee_local $p0
                                                                          i32.load offset=8
                                                                          tee_local $l3
                                                                          get_local $l4
                                                                          i32.const 72320
                                                                          i32.add
                                                                          tee_local $l4
                                                                          i32.eq
                                                                          br_if $B24
                                                                          get_local $l3
                                                                          get_local $l4
                                                                          i32.store offset=12
                                                                          get_local $l4
                                                                          i32.const 8
                                                                          i32.add
                                                                          get_local $l3
                                                                          i32.store
                                                                          br $B23
                                                                        end
                                                                        i32.const 0
                                                                        get_local $l0
                                                                        i32.const -2
                                                                        get_local $l1
                                                                        i32.rotl
                                                                        i32.and
                                                                        i32.store offset=72312
                                                                      end
                                                                      get_local $p0
                                                                      get_local $l1
                                                                      i32.const 3
                                                                      i32.shl
                                                                      tee_local $l1
                                                                      i32.const 3
                                                                      i32.or
                                                                      i32.store offset=4
                                                                      get_local $p0
                                                                      get_local $l1
                                                                      i32.add
                                                                      tee_local $p0
                                                                      get_local $p0
                                                                      i32.load offset=4
                                                                      i32.const 1
                                                                      i32.or
                                                                      i32.store offset=4
                                                                      br $B0
                                                                    end
                                                                    i32.const 0
                                                                    i32.load offset=72316
                                                                    tee_local $p0
                                                                    i32.eqz
                                                                    br_if $B26
                                                                    get_local $p0
                                                                    i32.const 0
                                                                    get_local $p0
                                                                    i32.sub
                                                                    i32.and
                                                                    i32.ctz
                                                                    i32.const 2
                                                                    i32.shl
                                                                    i32.const 72584
                                                                    i32.add
                                                                    i32.load
                                                                    tee_local $l0
                                                                    i32.load offset=4
                                                                    i32.const -8
                                                                    i32.and
                                                                    get_local $l1
                                                                    i32.sub
                                                                    set_local $l3
                                                                    get_local $l0
                                                                    set_local $l4
                                                                    get_local $l0
                                                                    i32.load offset=16
                                                                    tee_local $p0
                                                                    i32.eqz
                                                                    br_if $B11
                                                                    i32.const 1
                                                                    set_local $l2
                                                                    br $B10
                                                                  end
                                                                  i32.const 0
                                                                  set_local $l2
                                                                  get_local $p0
                                                                  set_local $l0
                                                                  br $B28
                                                                end
                                                                get_local $l0
                                                                br_if $B27
                                                              end
                                                              i32.const 0
                                                              set_local $l0
                                                              i32.const 2
                                                              get_local $l6
                                                              i32.const 31
                                                              i32.and
                                                              i32.shl
                                                              tee_local $p0
                                                              i32.const 0
                                                              get_local $p0
                                                              i32.sub
                                                              i32.or
                                                              get_local $l5
                                                              i32.and
                                                              tee_local $p0
                                                              i32.eqz
                                                              br_if $B26
                                                              get_local $p0
                                                              i32.const 0
                                                              get_local $p0
                                                              i32.sub
                                                              i32.and
                                                              i32.ctz
                                                              i32.const 2
                                                              i32.shl
                                                              i32.const 72584
                                                              i32.add
                                                              i32.load
                                                              tee_local $p0
                                                              i32.eqz
                                                              br_if $B26
                                                            end
                                                            loop $L40
                                                              get_local $p0
                                                              i32.load offset=4
                                                              i32.const -8
                                                              i32.and
                                                              tee_local $l3
                                                              get_local $l1
                                                              i32.ge_u
                                                              get_local $l3
                                                              get_local $l1
                                                              i32.sub
                                                              tee_local $l7
                                                              get_local $l2
                                                              i32.lt_u
                                                              i32.and
                                                              set_local $l4
                                                              block $B41
                                                                get_local $p0
                                                                i32.load offset=16
                                                                tee_local $l3
                                                                br_if $B41
                                                                get_local $p0
                                                                i32.const 20
                                                                i32.add
                                                                i32.load
                                                                set_local $l3
                                                              end
                                                              get_local $p0
                                                              get_local $l0
                                                              get_local $l4
                                                              select
                                                              set_local $l0
                                                              get_local $l7
                                                              get_local $l2
                                                              get_local $l4
                                                              select
                                                              set_local $l2
                                                              get_local $l3
                                                              set_local $p0
                                                              get_local $l3
                                                              br_if $L40
                                                            end
                                                            get_local $l0
                                                            i32.eqz
                                                            br_if $B26
                                                          end
                                                          i32.const 0
                                                          i32.load offset=72712
                                                          tee_local $p0
                                                          get_local $l1
                                                          i32.lt_u
                                                          br_if $B25
                                                          get_local $l2
                                                          get_local $p0
                                                          get_local $l1
                                                          i32.sub
                                                          i32.lt_u
                                                          br_if $B25
                                                        end
                                                        block $B42
                                                          block $B43
                                                            block $B44
                                                              block $B45
                                                                i32.const 0
                                                                i32.load offset=72712
                                                                tee_local $l2
                                                                get_local $l1
                                                                i32.ge_u
                                                                br_if $B45
                                                                i32.const 0
                                                                i32.load offset=72716
                                                                tee_local $p0
                                                                get_local $l1
                                                                i32.le_u
                                                                br_if $B44
                                                                i32.const 0
                                                                get_local $p0
                                                                get_local $l1
                                                                i32.sub
                                                                tee_local $l2
                                                                i32.store offset=72716
                                                                i32.const 0
                                                                i32.const 0
                                                                i32.load offset=72724
                                                                tee_local $p0
                                                                get_local $l1
                                                                i32.add
                                                                tee_local $l3
                                                                i32.store offset=72724
                                                                get_local $l3
                                                                get_local $l2
                                                                i32.const 1
                                                                i32.or
                                                                i32.store offset=4
                                                                get_local $p0
                                                                get_local $l1
                                                                i32.const 3
                                                                i32.or
                                                                i32.store offset=4
                                                                get_local $p0
                                                                i32.const 8
                                                                i32.add
                                                                return
                                                              end
                                                              i32.const 0
                                                              i32.load offset=72720
                                                              set_local $p0
                                                              get_local $l2
                                                              get_local $l1
                                                              i32.sub
                                                              tee_local $l3
                                                              i32.const 16
                                                              i32.ge_u
                                                              br_if $B43
                                                              i32.const 0
                                                              i32.const 0
                                                              i32.store offset=72720
                                                              i32.const 0
                                                              i32.const 0
                                                              i32.store offset=72712
                                                              get_local $p0
                                                              get_local $l2
                                                              i32.const 3
                                                              i32.or
                                                              i32.store offset=4
                                                              get_local $p0
                                                              get_local $l2
                                                              i32.add
                                                              tee_local $l2
                                                              i32.const 4
                                                              i32.add
                                                              set_local $l1
                                                              get_local $l2
                                                              i32.load offset=4
                                                              i32.const 1
                                                              i32.or
                                                              set_local $l2
                                                              br $B42
                                                            end
                                                            i32.const 0
                                                            set_local $l2
                                                            get_local $l1
                                                            i32.const 65583
                                                            i32.add
                                                            tee_local $l3
                                                            i32.const 16
                                                            i32.shr_u
                                                            memory.grow
                                                            tee_local $p0
                                                            i32.const -1
                                                            i32.eq
                                                            br_if $B0
                                                            get_local $p0
                                                            i32.const 16
                                                            i32.shl
                                                            tee_local $l4
                                                            i32.eqz
                                                            br_if $B0
                                                            i32.const 0
                                                            i32.const 0
                                                            i32.load offset=72728
                                                            get_local $l3
                                                            i32.const -65536
                                                            i32.and
                                                            tee_local $l7
                                                            i32.add
                                                            tee_local $p0
                                                            i32.store offset=72728
                                                            i32.const 0
                                                            i32.const 0
                                                            i32.load offset=72732
                                                            tee_local $l2
                                                            get_local $p0
                                                            get_local $p0
                                                            get_local $l2
                                                            i32.lt_u
                                                            select
                                                            i32.store offset=72732
                                                            i32.const 0
                                                            i32.load offset=72724
                                                            tee_local $l2
                                                            i32.eqz
                                                            br_if $B18
                                                            i32.const 72736
                                                            set_local $p0
                                                            loop $L46
                                                              get_local $p0
                                                              i32.load
                                                              tee_local $l3
                                                              get_local $p0
                                                              i32.load offset=4
                                                              tee_local $l0
                                                              i32.add
                                                              get_local $l4
                                                              i32.eq
                                                              br_if $B17
                                                              get_local $p0
                                                              i32.load offset=8
                                                              tee_local $p0
                                                              br_if $L46
                                                              br $B9
                                                            end
                                                          end
                                                          i32.const 0
                                                          get_local $l3
                                                          i32.store offset=72712
                                                          i32.const 0
                                                          get_local $p0
                                                          get_local $l1
                                                          i32.add
                                                          tee_local $l4
                                                          i32.store offset=72720
                                                          get_local $l4
                                                          get_local $l3
                                                          i32.const 1
                                                          i32.or
                                                          i32.store offset=4
                                                          get_local $p0
                                                          get_local $l2
                                                          i32.add
                                                          get_local $l3
                                                          i32.store
                                                          get_local $l1
                                                          i32.const 3
                                                          i32.or
                                                          set_local $l2
                                                          get_local $p0
                                                          i32.const 4
                                                          i32.add
                                                          set_local $l1
                                                        end
                                                        get_local $l1
                                                        get_local $l2
                                                        i32.store
                                                        get_local $p0
                                                        i32.const 8
                                                        i32.add
                                                        return
                                                      end
                                                      get_local $l0
                                                      call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
                                                      get_local $l2
                                                      i32.const 15
                                                      i32.gt_u
                                                      br_if $B22
                                                      get_local $l0
                                                      get_local $l2
                                                      get_local $l1
                                                      i32.add
                                                      tee_local $p0
                                                      i32.const 3
                                                      i32.or
                                                      i32.store offset=4
                                                      get_local $l0
                                                      get_local $p0
                                                      i32.add
                                                      tee_local $p0
                                                      get_local $p0
                                                      i32.load offset=4
                                                      i32.const 1
                                                      i32.or
                                                      i32.store offset=4
                                                      br $B12
                                                    end
                                                    i32.const 0
                                                    get_local $l0
                                                    i32.const -2
                                                    get_local $l2
                                                    i32.rotl
                                                    i32.and
                                                    i32.store offset=72312
                                                  end
                                                  get_local $p0
                                                  i32.const 8
                                                  i32.add
                                                  set_local $l3
                                                  get_local $p0
                                                  get_local $l1
                                                  i32.const 3
                                                  i32.or
                                                  i32.store offset=4
                                                  get_local $p0
                                                  get_local $l1
                                                  i32.add
                                                  tee_local $l4
                                                  get_local $l2
                                                  i32.const 3
                                                  i32.shl
                                                  tee_local $l2
                                                  get_local $l1
                                                  i32.sub
                                                  tee_local $l1
                                                  i32.const 1
                                                  i32.or
                                                  i32.store offset=4
                                                  get_local $p0
                                                  get_local $l2
                                                  i32.add
                                                  get_local $l1
                                                  i32.store
                                                  i32.const 0
                                                  i32.load offset=72712
                                                  tee_local $p0
                                                  i32.eqz
                                                  br_if $B19
                                                  get_local $p0
                                                  i32.const 3
                                                  i32.shr_u
                                                  tee_local $l0
                                                  i32.const 3
                                                  i32.shl
                                                  i32.const 72320
                                                  i32.add
                                                  set_local $l2
                                                  i32.const 0
                                                  i32.load offset=72720
                                                  set_local $p0
                                                  i32.const 0
                                                  i32.load offset=72312
                                                  tee_local $l7
                                                  i32.const 1
                                                  get_local $l0
                                                  i32.const 31
                                                  i32.and
                                                  i32.shl
                                                  tee_local $l0
                                                  i32.and
                                                  i32.eqz
                                                  br_if $B21
                                                  get_local $l2
                                                  i32.load offset=8
                                                  set_local $l0
                                                  br $B20
                                                end
                                                get_local $l0
                                                get_local $l1
                                                i32.const 3
                                                i32.or
                                                i32.store offset=4
                                                get_local $l0
                                                get_local $l1
                                                i32.add
                                                tee_local $p0
                                                get_local $l2
                                                i32.const 1
                                                i32.or
                                                i32.store offset=4
                                                get_local $p0
                                                get_local $l2
                                                i32.add
                                                get_local $l2
                                                i32.store
                                                get_local $l2
                                                i32.const 255
                                                i32.gt_u
                                                br_if $B16
                                                get_local $l2
                                                i32.const 3
                                                i32.shr_u
                                                tee_local $l2
                                                i32.const 3
                                                i32.shl
                                                i32.const 72320
                                                i32.add
                                                set_local $l1
                                                i32.const 0
                                                i32.load offset=72312
                                                tee_local $l3
                                                i32.const 1
                                                get_local $l2
                                                i32.const 31
                                                i32.and
                                                i32.shl
                                                tee_local $l2
                                                i32.and
                                                i32.eqz
                                                br_if $B14
                                                get_local $l1
                                                i32.load offset=8
                                                set_local $l2
                                                br $B13
                                              end
                                              i32.const 0
                                              get_local $l7
                                              get_local $l0
                                              i32.or
                                              i32.store offset=72312
                                              get_local $l2
                                              set_local $l0
                                            end
                                            get_local $l2
                                            get_local $p0
                                            i32.store offset=8
                                            get_local $l0
                                            get_local $p0
                                            i32.store offset=12
                                            get_local $p0
                                            get_local $l2
                                            i32.store offset=12
                                            get_local $p0
                                            get_local $l0
                                            i32.store offset=8
                                          end
                                          i32.const 0
                                          get_local $l4
                                          i32.store offset=72720
                                          i32.const 0
                                          get_local $l1
                                          i32.store offset=72712
                                          get_local $l3
                                          return
                                        end
                                        block $B47
                                          block $B48
                                            i32.const 0
                                            i32.load offset=72756
                                            tee_local $p0
                                            i32.eqz
                                            br_if $B48
                                            get_local $p0
                                            get_local $l4
                                            i32.le_u
                                            br_if $B47
                                          end
                                          i32.const 0
                                          get_local $l4
                                          i32.store offset=72756
                                        end
                                        i32.const 0
                                        set_local $p0
                                        i32.const 0
                                        i32.const 4095
                                        i32.store offset=72760
                                        i32.const 0
                                        get_local $l7
                                        i32.store offset=72740
                                        i32.const 0
                                        get_local $l4
                                        i32.store offset=72736
                                        i32.const 0
                                        i32.const 0
                                        i32.store offset=72748
                                        loop $L49
                                          get_local $p0
                                          i32.const 72328
                                          i32.add
                                          get_local $p0
                                          i32.const 72320
                                          i32.add
                                          tee_local $l2
                                          i32.store
                                          get_local $p0
                                          i32.const 72332
                                          i32.add
                                          get_local $l2
                                          i32.store
                                          get_local $p0
                                          i32.const 8
                                          i32.add
                                          tee_local $p0
                                          i32.const 256
                                          i32.ne
                                          br_if $L49
                                        end
                                        i32.const 0
                                        get_local $l4
                                        i32.store offset=72724
                                        i32.const 0
                                        get_local $l7
                                        i32.const -40
                                        i32.add
                                        tee_local $p0
                                        i32.store offset=72716
                                        get_local $l4
                                        get_local $p0
                                        i32.const 1
                                        i32.or
                                        i32.store offset=4
                                        get_local $l4
                                        get_local $p0
                                        i32.add
                                        i32.const 40
                                        i32.store offset=4
                                        i32.const 0
                                        i32.const 2097152
                                        i32.store offset=72752
                                        br $B8
                                      end
                                      get_local $p0
                                      i32.load offset=12
                                      i32.eqz
                                      br_if $B15
                                      br $B9
                                    end
                                    get_local $p0
                                    get_local $l2
                                    call $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E
                                    br $B12
                                  end
                                  get_local $l4
                                  get_local $l2
                                  i32.le_u
                                  br_if $B9
                                  get_local $l3
                                  get_local $l2
                                  i32.gt_u
                                  br_if $B9
                                  get_local $p0
                                  i32.const 4
                                  i32.add
                                  get_local $l0
                                  get_local $l7
                                  i32.add
                                  i32.store
                                  i32.const 0
                                  i32.const 0
                                  i32.load offset=72724
                                  tee_local $p0
                                  i32.const 15
                                  i32.add
                                  i32.const -8
                                  i32.and
                                  tee_local $l2
                                  i32.const -8
                                  i32.add
                                  tee_local $l3
                                  i32.store offset=72724
                                  i32.const 0
                                  i32.const 0
                                  i32.load offset=72716
                                  get_local $l7
                                  i32.add
                                  tee_local $l4
                                  get_local $p0
                                  i32.const 8
                                  i32.add
                                  get_local $l2
                                  i32.sub
                                  i32.add
                                  tee_local $l2
                                  i32.store offset=72716
                                  get_local $l3
                                  get_local $l2
                                  i32.const 1
                                  i32.or
                                  i32.store offset=4
                                  get_local $p0
                                  get_local $l4
                                  i32.add
                                  i32.const 40
                                  i32.store offset=4
                                  i32.const 0
                                  i32.const 2097152
                                  i32.store offset=72752
                                  br $B8
                                end
                                i32.const 0
                                get_local $l3
                                get_local $l2
                                i32.or
                                i32.store offset=72312
                                get_local $l1
                                set_local $l2
                              end
                              get_local $l1
                              get_local $p0
                              i32.store offset=8
                              get_local $l2
                              get_local $p0
                              i32.store offset=12
                              get_local $p0
                              get_local $l1
                              i32.store offset=12
                              get_local $p0
                              get_local $l2
                              i32.store offset=8
                            end
                            get_local $l0
                            i32.const 8
                            i32.add
                            return
                          end
                          i32.const 0
                          set_local $l2
                        end
                        loop $L50
                          block $B51
                            block $B52
                              block $B53
                                block $B54
                                  get_local $l2
                                  br_table $B53 $B54 $B54
                                end
                                get_local $p0
                                i32.load offset=4
                                i32.const -8
                                i32.and
                                get_local $l1
                                i32.sub
                                tee_local $l2
                                get_local $l3
                                get_local $l2
                                get_local $l3
                                i32.lt_u
                                tee_local $l2
                                select
                                set_local $l3
                                get_local $p0
                                get_local $l4
                                get_local $l2
                                select
                                set_local $l4
                                get_local $p0
                                tee_local $l0
                                i32.load offset=16
                                tee_local $p0
                                br_if $B52
                                i32.const 0
                                set_local $l2
                                br $L50
                              end
                              get_local $l0
                              i32.const 20
                              i32.add
                              i32.load
                              tee_local $p0
                              br_if $B51
                              get_local $l4
                              call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
                              block $B55
                                block $B56
                                  get_local $l3
                                  i32.const 16
                                  i32.ge_u
                                  br_if $B56
                                  get_local $l4
                                  get_local $l3
                                  get_local $l1
                                  i32.add
                                  tee_local $p0
                                  i32.const 3
                                  i32.or
                                  i32.store offset=4
                                  get_local $l4
                                  get_local $p0
                                  i32.add
                                  tee_local $p0
                                  get_local $p0
                                  i32.load offset=4
                                  i32.const 1
                                  i32.or
                                  i32.store offset=4
                                  br $B55
                                end
                                get_local $l4
                                get_local $l1
                                i32.const 3
                                i32.or
                                i32.store offset=4
                                get_local $l4
                                get_local $l1
                                i32.add
                                tee_local $l1
                                get_local $l3
                                i32.const 1
                                i32.or
                                i32.store offset=4
                                get_local $l1
                                get_local $l3
                                i32.add
                                get_local $l3
                                i32.store
                                block $B57
                                  i32.const 0
                                  i32.load offset=72712
                                  tee_local $p0
                                  i32.eqz
                                  br_if $B57
                                  get_local $p0
                                  i32.const 3
                                  i32.shr_u
                                  tee_local $l0
                                  i32.const 3
                                  i32.shl
                                  i32.const 72320
                                  i32.add
                                  set_local $l2
                                  i32.const 0
                                  i32.load offset=72720
                                  set_local $p0
                                  block $B58
                                    block $B59
                                      i32.const 0
                                      i32.load offset=72312
                                      tee_local $l7
                                      i32.const 1
                                      get_local $l0
                                      i32.const 31
                                      i32.and
                                      i32.shl
                                      tee_local $l0
                                      i32.and
                                      i32.eqz
                                      br_if $B59
                                      get_local $l2
                                      i32.load offset=8
                                      set_local $l0
                                      br $B58
                                    end
                                    i32.const 0
                                    get_local $l7
                                    get_local $l0
                                    i32.or
                                    i32.store offset=72312
                                    get_local $l2
                                    set_local $l0
                                  end
                                  get_local $l2
                                  get_local $p0
                                  i32.store offset=8
                                  get_local $l0
                                  get_local $p0
                                  i32.store offset=12
                                  get_local $p0
                                  get_local $l2
                                  i32.store offset=12
                                  get_local $p0
                                  get_local $l0
                                  i32.store offset=8
                                end
                                i32.const 0
                                get_local $l1
                                i32.store offset=72720
                                i32.const 0
                                get_local $l3
                                i32.store offset=72712
                              end
                              get_local $l4
                              i32.const 8
                              i32.add
                              return
                            end
                            i32.const 1
                            set_local $l2
                            br $L50
                          end
                          i32.const 1
                          set_local $l2
                          br $L50
                        end
                      end
                      i32.const 0
                      i32.const 0
                      i32.load offset=72756
                      tee_local $p0
                      get_local $l4
                      get_local $p0
                      get_local $l4
                      i32.lt_u
                      select
                      i32.store offset=72756
                      get_local $l4
                      get_local $l7
                      i32.add
                      set_local $l3
                      i32.const 72736
                      set_local $p0
                      block $B60
                        block $B61
                          block $B62
                            block $B63
                              block $B64
                                loop $L65
                                  get_local $p0
                                  i32.load
                                  get_local $l3
                                  i32.eq
                                  br_if $B64
                                  get_local $p0
                                  i32.load offset=8
                                  tee_local $p0
                                  br_if $L65
                                  br $B63
                                end
                              end
                              get_local $p0
                              i32.load offset=12
                              i32.eqz
                              br_if $B62
                            end
                            i32.const 72736
                            set_local $p0
                            block $B66
                              loop $L67
                                block $B68
                                  get_local $p0
                                  i32.load
                                  tee_local $l3
                                  get_local $l2
                                  i32.gt_u
                                  br_if $B68
                                  get_local $l3
                                  get_local $p0
                                  i32.load offset=4
                                  i32.add
                                  tee_local $l3
                                  get_local $l2
                                  i32.gt_u
                                  br_if $B66
                                end
                                get_local $p0
                                i32.load offset=8
                                set_local $p0
                                br $L67
                              end
                            end
                            i32.const 0
                            get_local $l4
                            i32.store offset=72724
                            i32.const 0
                            get_local $l7
                            i32.const -40
                            i32.add
                            tee_local $p0
                            i32.store offset=72716
                            get_local $l4
                            get_local $p0
                            i32.const 1
                            i32.or
                            i32.store offset=4
                            get_local $l4
                            get_local $p0
                            i32.add
                            i32.const 40
                            i32.store offset=4
                            i32.const 0
                            i32.const 2097152
                            i32.store offset=72752
                            get_local $l2
                            get_local $l3
                            i32.const -32
                            i32.add
                            i32.const -8
                            i32.and
                            i32.const -8
                            i32.add
                            tee_local $p0
                            get_local $p0
                            get_local $l2
                            i32.const 16
                            i32.add
                            i32.lt_u
                            select
                            tee_local $l0
                            i32.const 27
                            i32.store offset=4
                            i32.const 0
                            i64.load offset=72736 align=4
                            set_local $l8
                            get_local $l0
                            i32.const 16
                            i32.add
                            i32.const 0
                            i64.load offset=72744 align=4
                            i64.store align=4
                            get_local $l0
                            get_local $l8
                            i64.store offset=8 align=4
                            i32.const 0
                            get_local $l7
                            i32.store offset=72740
                            i32.const 0
                            get_local $l4
                            i32.store offset=72736
                            i32.const 0
                            get_local $l0
                            i32.const 8
                            i32.add
                            i32.store offset=72744
                            i32.const 0
                            i32.const 0
                            i32.store offset=72748
                            get_local $l0
                            i32.const 28
                            i32.add
                            set_local $p0
                            loop $L69
                              get_local $p0
                              i32.const 7
                              i32.store
                              get_local $l3
                              get_local $p0
                              i32.const 4
                              i32.add
                              tee_local $p0
                              i32.gt_u
                              br_if $L69
                            end
                            get_local $l0
                            get_local $l2
                            i32.eq
                            br_if $B8
                            get_local $l0
                            get_local $l0
                            i32.load offset=4
                            i32.const -2
                            i32.and
                            i32.store offset=4
                            get_local $l2
                            get_local $l0
                            get_local $l2
                            i32.sub
                            tee_local $p0
                            i32.const 1
                            i32.or
                            i32.store offset=4
                            get_local $l0
                            get_local $p0
                            i32.store
                            block $B70
                              get_local $p0
                              i32.const 255
                              i32.gt_u
                              br_if $B70
                              get_local $p0
                              i32.const 3
                              i32.shr_u
                              tee_local $l3
                              i32.const 3
                              i32.shl
                              i32.const 72320
                              i32.add
                              set_local $p0
                              i32.const 0
                              i32.load offset=72312
                              tee_local $l4
                              i32.const 1
                              get_local $l3
                              i32.const 31
                              i32.and
                              i32.shl
                              tee_local $l3
                              i32.and
                              i32.eqz
                              br_if $B61
                              get_local $p0
                              i32.load offset=8
                              set_local $l3
                              br $B60
                            end
                            get_local $l2
                            get_local $p0
                            call $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E
                            br $B8
                          end
                          get_local $p0
                          get_local $l4
                          i32.store
                          get_local $p0
                          get_local $p0
                          i32.load offset=4
                          get_local $l7
                          i32.add
                          i32.store offset=4
                          get_local $l4
                          get_local $l1
                          i32.const 3
                          i32.or
                          i32.store offset=4
                          get_local $l4
                          get_local $l1
                          i32.add
                          set_local $p0
                          get_local $l3
                          get_local $l4
                          i32.sub
                          get_local $l1
                          i32.sub
                          set_local $l1
                          i32.const 0
                          i32.load offset=72724
                          get_local $l3
                          i32.eq
                          br_if $B7
                          i32.const 0
                          i32.load offset=72720
                          get_local $l3
                          i32.eq
                          br_if $B6
                          get_local $l3
                          i32.load offset=4
                          tee_local $l2
                          i32.const 3
                          i32.and
                          i32.const 1
                          i32.ne
                          br_if $B2
                          get_local $l2
                          i32.const -8
                          i32.and
                          tee_local $l0
                          i32.const 255
                          i32.gt_u
                          br_if $B5
                          get_local $l3
                          i32.load offset=12
                          tee_local $l7
                          get_local $l3
                          i32.load offset=8
                          tee_local $l6
                          i32.eq
                          br_if $B4
                          get_local $l6
                          get_local $l7
                          i32.store offset=12
                          get_local $l7
                          get_local $l6
                          i32.store offset=8
                          br $B3
                        end
                        i32.const 0
                        get_local $l4
                        get_local $l3
                        i32.or
                        i32.store offset=72312
                        get_local $p0
                        set_local $l3
                      end
                      get_local $p0
                      get_local $l2
                      i32.store offset=8
                      get_local $l3
                      get_local $l2
                      i32.store offset=12
                      get_local $l2
                      get_local $p0
                      i32.store offset=12
                      get_local $l2
                      get_local $l3
                      i32.store offset=8
                    end
                    i32.const 0
                    set_local $l2
                    i32.const 0
                    i32.load offset=72716
                    tee_local $p0
                    get_local $l1
                    i32.le_u
                    br_if $B0
                    i32.const 0
                    get_local $p0
                    get_local $l1
                    i32.sub
                    tee_local $l2
                    i32.store offset=72716
                    i32.const 0
                    i32.const 0
                    i32.load offset=72724
                    tee_local $p0
                    get_local $l1
                    i32.add
                    tee_local $l3
                    i32.store offset=72724
                    get_local $l3
                    get_local $l2
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    get_local $p0
                    get_local $l1
                    i32.const 3
                    i32.or
                    i32.store offset=4
                    get_local $p0
                    i32.const 8
                    i32.add
                    return
                  end
                  i32.const 0
                  get_local $p0
                  i32.store offset=72724
                  i32.const 0
                  i32.const 0
                  i32.load offset=72716
                  get_local $l1
                  i32.add
                  tee_local $l1
                  i32.store offset=72716
                  get_local $p0
                  get_local $l1
                  i32.const 1
                  i32.or
                  i32.store offset=4
                  br $B1
                end
                i32.const 0
                get_local $p0
                i32.store offset=72720
                i32.const 0
                i32.const 0
                i32.load offset=72712
                get_local $l1
                i32.add
                tee_local $l1
                i32.store offset=72712
                get_local $p0
                get_local $l1
                i32.const 1
                i32.or
                i32.store offset=4
                get_local $p0
                get_local $l1
                i32.add
                get_local $l1
                i32.store
                br $B1
              end
              get_local $l3
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
              br $B3
            end
            i32.const 0
            i32.const 0
            i32.load offset=72312
            i32.const -2
            get_local $l2
            i32.const 3
            i32.shr_u
            i32.rotl
            i32.and
            i32.store offset=72312
          end
          get_local $l0
          get_local $l1
          i32.add
          set_local $l1
          get_local $l3
          get_local $l0
          i32.add
          set_local $l3
        end
        get_local $l3
        get_local $l3
        i32.load offset=4
        i32.const -2
        i32.and
        i32.store offset=4
        get_local $p0
        get_local $l1
        i32.const 1
        i32.or
        i32.store offset=4
        get_local $p0
        get_local $l1
        i32.add
        get_local $l1
        i32.store
        block $B71
          block $B72
            block $B73
              get_local $l1
              i32.const 255
              i32.gt_u
              br_if $B73
              get_local $l1
              i32.const 3
              i32.shr_u
              tee_local $l2
              i32.const 3
              i32.shl
              i32.const 72320
              i32.add
              set_local $l1
              i32.const 0
              i32.load offset=72312
              tee_local $l3
              i32.const 1
              get_local $l2
              i32.const 31
              i32.and
              i32.shl
              tee_local $l2
              i32.and
              i32.eqz
              br_if $B72
              get_local $l1
              i32.load offset=8
              set_local $l2
              br $B71
            end
            get_local $p0
            get_local $l1
            call $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E
            br $B1
          end
          i32.const 0
          get_local $l3
          get_local $l2
          i32.or
          i32.store offset=72312
          get_local $l1
          set_local $l2
        end
        get_local $l1
        get_local $p0
        i32.store offset=8
        get_local $l2
        get_local $p0
        i32.store offset=12
        get_local $p0
        get_local $l1
        i32.store offset=12
        get_local $p0
        get_local $l2
        i32.store offset=8
      end
      get_local $l4
      i32.const 8
      i32.add
      return
    end
    get_local $l2)
  (func $_ZN8dlmalloc8dlmalloc8Dlmalloc13dispose_chunk17hae5b7b0a563f1cedE (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    get_local $p0
    get_local $p1
    i32.add
    set_local $l0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                block $B6
                  block $B7
                    get_local $p0
                    i32.load offset=4
                    tee_local $l1
                    i32.const 1
                    i32.and
                    br_if $B7
                    get_local $l1
                    i32.const 3
                    i32.and
                    i32.eqz
                    br_if $B6
                    get_local $p0
                    i32.load
                    tee_local $l1
                    get_local $p1
                    i32.add
                    set_local $p1
                    block $B8
                      block $B9
                        block $B10
                          i32.const 0
                          i32.load offset=72720
                          get_local $p0
                          get_local $l1
                          i32.sub
                          tee_local $p0
                          i32.eq
                          br_if $B10
                          get_local $l1
                          i32.const 255
                          i32.gt_u
                          br_if $B9
                          get_local $p0
                          i32.load offset=12
                          tee_local $l2
                          get_local $p0
                          i32.load offset=8
                          tee_local $l3
                          i32.eq
                          br_if $B8
                          get_local $l3
                          get_local $l2
                          i32.store offset=12
                          get_local $l2
                          get_local $l3
                          i32.store offset=8
                          br $B7
                        end
                        get_local $l0
                        i32.load offset=4
                        i32.const 3
                        i32.and
                        i32.const 3
                        i32.ne
                        br_if $B7
                        i32.const 0
                        get_local $p1
                        i32.store offset=72712
                        get_local $l0
                        i32.const 4
                        i32.add
                        tee_local $l1
                        get_local $l1
                        i32.load
                        i32.const -2
                        i32.and
                        i32.store
                        get_local $p0
                        get_local $p1
                        i32.const 1
                        i32.or
                        i32.store offset=4
                        get_local $l0
                        get_local $p1
                        i32.store
                        return
                      end
                      get_local $p0
                      call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
                      br $B7
                    end
                    i32.const 0
                    i32.const 0
                    i32.load offset=72312
                    i32.const -2
                    get_local $l1
                    i32.const 3
                    i32.shr_u
                    i32.rotl
                    i32.and
                    i32.store offset=72312
                  end
                  block $B11
                    block $B12
                      get_local $l0
                      i32.load offset=4
                      tee_local $l1
                      i32.const 2
                      i32.and
                      br_if $B12
                      i32.const 0
                      i32.load offset=72724
                      get_local $l0
                      i32.eq
                      br_if $B11
                      i32.const 0
                      i32.load offset=72720
                      get_local $l0
                      i32.eq
                      br_if $B5
                      get_local $l1
                      i32.const -8
                      i32.and
                      tee_local $l2
                      get_local $p1
                      i32.add
                      set_local $p1
                      get_local $l2
                      i32.const 255
                      i32.gt_u
                      br_if $B4
                      get_local $l0
                      i32.load offset=12
                      tee_local $l2
                      get_local $l0
                      i32.load offset=8
                      tee_local $l0
                      i32.eq
                      br_if $B2
                      get_local $l0
                      get_local $l2
                      i32.store offset=12
                      get_local $l2
                      get_local $l0
                      i32.store offset=8
                      br $B1
                    end
                    get_local $l0
                    i32.const 4
                    i32.add
                    get_local $l1
                    i32.const -2
                    i32.and
                    i32.store
                    get_local $p0
                    get_local $p1
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    get_local $p0
                    get_local $p1
                    i32.add
                    get_local $p1
                    i32.store
                    br $B0
                  end
                  i32.const 0
                  get_local $p0
                  i32.store offset=72724
                  i32.const 0
                  i32.const 0
                  i32.load offset=72716
                  get_local $p1
                  i32.add
                  tee_local $p1
                  i32.store offset=72716
                  get_local $p0
                  get_local $p1
                  i32.const 1
                  i32.or
                  i32.store offset=4
                  get_local $p0
                  i32.const 0
                  i32.load offset=72720
                  i32.eq
                  br_if $B3
                end
                return
              end
              i32.const 0
              get_local $p0
              i32.store offset=72720
              i32.const 0
              i32.const 0
              i32.load offset=72712
              get_local $p1
              i32.add
              tee_local $p1
              i32.store offset=72712
              get_local $p0
              get_local $p1
              i32.const 1
              i32.or
              i32.store offset=4
              get_local $p0
              get_local $p1
              i32.add
              get_local $p1
              i32.store
              return
            end
            get_local $l0
            call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
            br $B1
          end
          i32.const 0
          i32.const 0
          i32.store offset=72712
          i32.const 0
          i32.const 0
          i32.store offset=72720
          return
        end
        i32.const 0
        i32.const 0
        i32.load offset=72312
        i32.const -2
        get_local $l1
        i32.const 3
        i32.shr_u
        i32.rotl
        i32.and
        i32.store offset=72312
      end
      get_local $p0
      get_local $p1
      i32.const 1
      i32.or
      i32.store offset=4
      get_local $p0
      get_local $p1
      i32.add
      get_local $p1
      i32.store
      get_local $p0
      i32.const 0
      i32.load offset=72720
      i32.ne
      br_if $B0
      i32.const 0
      get_local $p1
      i32.store offset=72712
      return
    end
    block $B13
      block $B14
        block $B15
          get_local $p1
          i32.const 255
          i32.gt_u
          br_if $B15
          get_local $p1
          i32.const 3
          i32.shr_u
          tee_local $l0
          i32.const 3
          i32.shl
          i32.const 72320
          i32.add
          set_local $p1
          i32.const 0
          i32.load offset=72312
          tee_local $l1
          i32.const 1
          get_local $l0
          i32.const 31
          i32.and
          i32.shl
          tee_local $l0
          i32.and
          i32.eqz
          br_if $B14
          get_local $p1
          i32.load offset=8
          set_local $l0
          br $B13
        end
        get_local $p0
        get_local $p1
        call $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E
        return
      end
      i32.const 0
      get_local $l1
      get_local $l0
      i32.or
      i32.store offset=72312
      get_local $p1
      set_local $l0
    end
    get_local $p1
    get_local $p0
    i32.store offset=8
    get_local $l0
    get_local $p0
    i32.store offset=12
    get_local $p0
    get_local $p1
    i32.store offset=12
    get_local $p0
    get_local $l0
    i32.store offset=8)
  (func $__rdl_dealloc (type $t2) (param $p0 i32)
    get_local $p0
    call $_ZN8dlmalloc8dlmalloc8Dlmalloc4free17hd564262fdf262c88E)
  (func $_ZN8dlmalloc8dlmalloc8Dlmalloc4free17hd564262fdf262c88E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    get_local $p0
    i32.const -8
    i32.add
    tee_local $l0
    get_local $p0
    i32.const -4
    i32.add
    i32.load
    tee_local $l1
    i32.const -8
    i32.and
    tee_local $p0
    i32.add
    set_local $l2
    block $B0
      block $B1
        get_local $l1
        i32.const 1
        i32.and
        br_if $B1
        get_local $l1
        i32.const 3
        i32.and
        i32.eqz
        br_if $B0
        get_local $l0
        i32.load
        tee_local $l1
        get_local $p0
        i32.add
        set_local $p0
        block $B2
          block $B3
            block $B4
              i32.const 0
              i32.load offset=72720
              get_local $l0
              get_local $l1
              i32.sub
              tee_local $l0
              i32.eq
              br_if $B4
              get_local $l1
              i32.const 255
              i32.gt_u
              br_if $B3
              get_local $l0
              i32.load offset=12
              tee_local $l3
              get_local $l0
              i32.load offset=8
              tee_local $l4
              i32.eq
              br_if $B2
              get_local $l4
              get_local $l3
              i32.store offset=12
              get_local $l3
              get_local $l4
              i32.store offset=8
              br $B1
            end
            get_local $l2
            i32.load offset=4
            i32.const 3
            i32.and
            i32.const 3
            i32.ne
            br_if $B1
            i32.const 0
            get_local $p0
            i32.store offset=72712
            get_local $l2
            i32.const 4
            i32.add
            tee_local $l2
            get_local $l2
            i32.load
            i32.const -2
            i32.and
            i32.store
            get_local $l0
            get_local $p0
            i32.const 1
            i32.or
            i32.store offset=4
            get_local $l0
            get_local $p0
            i32.add
            get_local $p0
            i32.store
            return
          end
          get_local $l0
          call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
          br $B1
        end
        i32.const 0
        i32.const 0
        i32.load offset=72312
        i32.const -2
        get_local $l1
        i32.const 3
        i32.shr_u
        i32.rotl
        i32.and
        i32.store offset=72312
      end
      block $B5
        block $B6
          block $B7
            block $B8
              block $B9
                block $B10
                  block $B11
                    block $B12
                      block $B13
                        get_local $l2
                        i32.load offset=4
                        tee_local $l1
                        i32.const 2
                        i32.and
                        br_if $B13
                        i32.const 0
                        i32.load offset=72724
                        get_local $l2
                        i32.eq
                        br_if $B12
                        i32.const 0
                        i32.load offset=72720
                        get_local $l2
                        i32.eq
                        br_if $B11
                        get_local $l1
                        i32.const -8
                        i32.and
                        tee_local $l3
                        get_local $p0
                        i32.add
                        set_local $p0
                        get_local $l3
                        i32.const 255
                        i32.gt_u
                        br_if $B10
                        get_local $l2
                        i32.load offset=12
                        tee_local $l3
                        get_local $l2
                        i32.load offset=8
                        tee_local $l2
                        i32.eq
                        br_if $B9
                        get_local $l2
                        get_local $l3
                        i32.store offset=12
                        get_local $l3
                        get_local $l2
                        i32.store offset=8
                        br $B8
                      end
                      get_local $l2
                      i32.const 4
                      i32.add
                      get_local $l1
                      i32.const -2
                      i32.and
                      i32.store
                      get_local $l0
                      get_local $p0
                      i32.const 1
                      i32.or
                      i32.store offset=4
                      get_local $l0
                      get_local $p0
                      i32.add
                      get_local $p0
                      i32.store
                      br $B5
                    end
                    i32.const 0
                    get_local $l0
                    i32.store offset=72724
                    i32.const 0
                    i32.const 0
                    i32.load offset=72716
                    get_local $p0
                    i32.add
                    tee_local $p0
                    i32.store offset=72716
                    get_local $l0
                    get_local $p0
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    block $B14
                      get_local $l0
                      i32.const 0
                      i32.load offset=72720
                      i32.ne
                      br_if $B14
                      i32.const 0
                      i32.const 0
                      i32.store offset=72712
                      i32.const 0
                      i32.const 0
                      i32.store offset=72720
                    end
                    i32.const 0
                    i32.load offset=72752
                    tee_local $l1
                    get_local $p0
                    i32.ge_u
                    br_if $B0
                    i32.const 0
                    i32.load offset=72724
                    tee_local $p0
                    i32.eqz
                    br_if $B0
                    block $B15
                      i32.const 0
                      i32.load offset=72716
                      tee_local $l3
                      i32.const 41
                      i32.lt_u
                      br_if $B15
                      i32.const 72736
                      set_local $l0
                      loop $L16
                        block $B17
                          get_local $l0
                          i32.load
                          tee_local $l2
                          get_local $p0
                          i32.gt_u
                          br_if $B17
                          get_local $l2
                          get_local $l0
                          i32.load offset=4
                          i32.add
                          get_local $p0
                          i32.gt_u
                          br_if $B15
                        end
                        get_local $l0
                        i32.load offset=8
                        tee_local $l0
                        br_if $L16
                      end
                    end
                    i32.const 0
                    i32.load offset=72744
                    tee_local $p0
                    i32.eqz
                    br_if $B7
                    i32.const 0
                    set_local $l0
                    loop $L18
                      get_local $l0
                      i32.const 1
                      i32.add
                      set_local $l0
                      get_local $p0
                      i32.load offset=8
                      tee_local $p0
                      br_if $L18
                    end
                    get_local $l0
                    i32.const 4095
                    get_local $l0
                    i32.const 4095
                    i32.gt_u
                    select
                    set_local $l0
                    br $B6
                  end
                  i32.const 0
                  get_local $l0
                  i32.store offset=72720
                  i32.const 0
                  i32.const 0
                  i32.load offset=72712
                  get_local $p0
                  i32.add
                  tee_local $p0
                  i32.store offset=72712
                  get_local $l0
                  get_local $p0
                  i32.const 1
                  i32.or
                  i32.store offset=4
                  get_local $l0
                  get_local $p0
                  i32.add
                  get_local $p0
                  i32.store
                  return
                end
                get_local $l2
                call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
                br $B8
              end
              i32.const 0
              i32.const 0
              i32.load offset=72312
              i32.const -2
              get_local $l1
              i32.const 3
              i32.shr_u
              i32.rotl
              i32.and
              i32.store offset=72312
            end
            get_local $l0
            get_local $p0
            i32.const 1
            i32.or
            i32.store offset=4
            get_local $l0
            get_local $p0
            i32.add
            get_local $p0
            i32.store
            get_local $l0
            i32.const 0
            i32.load offset=72720
            i32.ne
            br_if $B5
            i32.const 0
            get_local $p0
            i32.store offset=72712
            return
          end
          i32.const 4095
          set_local $l0
        end
        i32.const 0
        get_local $l0
        i32.store offset=72760
        get_local $l3
        get_local $l1
        i32.le_u
        br_if $B0
        i32.const 0
        i32.const -1
        i32.store offset=72752
        return
      end
      block $B19
        block $B20
          block $B21
            block $B22
              block $B23
                get_local $p0
                i32.const 255
                i32.gt_u
                br_if $B23
                get_local $p0
                i32.const 3
                i32.shr_u
                tee_local $l2
                i32.const 3
                i32.shl
                i32.const 72320
                i32.add
                set_local $p0
                i32.const 0
                i32.load offset=72312
                tee_local $l1
                i32.const 1
                get_local $l2
                i32.const 31
                i32.and
                i32.shl
                tee_local $l2
                i32.and
                i32.eqz
                br_if $B22
                get_local $p0
                i32.load offset=8
                set_local $l2
                br $B21
              end
              get_local $l0
              get_local $p0
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E
              i32.const 0
              i32.const 0
              i32.load offset=72760
              i32.const -1
              i32.add
              tee_local $l0
              i32.store offset=72760
              get_local $l0
              br_if $B0
              i32.const 0
              i32.load offset=72744
              tee_local $p0
              i32.eqz
              br_if $B20
              i32.const 0
              set_local $l0
              loop $L24
                get_local $l0
                i32.const 1
                i32.add
                set_local $l0
                get_local $p0
                i32.load offset=8
                tee_local $p0
                br_if $L24
              end
              get_local $l0
              i32.const 4095
              get_local $l0
              i32.const 4095
              i32.gt_u
              select
              set_local $l0
              br $B19
            end
            i32.const 0
            get_local $l1
            get_local $l2
            i32.or
            i32.store offset=72312
            get_local $p0
            set_local $l2
          end
          get_local $p0
          get_local $l0
          i32.store offset=8
          get_local $l2
          get_local $l0
          i32.store offset=12
          get_local $l0
          get_local $p0
          i32.store offset=12
          get_local $l0
          get_local $l2
          i32.store offset=8
          return
        end
        i32.const 4095
        set_local $l0
      end
      i32.const 0
      get_local $l0
      i32.store offset=72760
    end)
  (func $__rdl_realloc (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32) (local $l7 i32)
    i32.const 0
    set_local $l0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p1
              i32.const -65588
              i32.gt_u
              br_if $B4
              i32.const 16
              get_local $p1
              i32.const 11
              i32.add
              i32.const -8
              i32.and
              get_local $p1
              i32.const 11
              i32.lt_u
              select
              set_local $l1
              get_local $p0
              i32.const -4
              i32.add
              tee_local $l2
              i32.load
              tee_local $l3
              i32.const -8
              i32.and
              set_local $l4
              block $B5
                block $B6
                  block $B7
                    block $B8
                      block $B9
                        get_local $l3
                        i32.const 3
                        i32.and
                        i32.eqz
                        br_if $B9
                        get_local $p0
                        i32.const -8
                        i32.add
                        tee_local $l5
                        get_local $l4
                        i32.add
                        set_local $l6
                        get_local $l4
                        get_local $l1
                        i32.ge_u
                        br_if $B8
                        i32.const 0
                        i32.load offset=72724
                        get_local $l6
                        i32.eq
                        br_if $B7
                        i32.const 0
                        i32.load offset=72720
                        get_local $l6
                        i32.eq
                        br_if $B6
                        get_local $l6
                        i32.load offset=4
                        tee_local $l3
                        i32.const 2
                        i32.and
                        br_if $B5
                        get_local $l3
                        i32.const -8
                        i32.and
                        tee_local $l7
                        get_local $l4
                        i32.add
                        tee_local $l4
                        get_local $l1
                        i32.lt_u
                        br_if $B5
                        get_local $l4
                        get_local $l1
                        i32.sub
                        set_local $p1
                        get_local $l7
                        i32.const 255
                        i32.gt_u
                        br_if $B2
                        get_local $l6
                        i32.load offset=12
                        tee_local $l0
                        get_local $l6
                        i32.load offset=8
                        tee_local $l6
                        i32.eq
                        br_if $B1
                        get_local $l6
                        get_local $l0
                        i32.store offset=12
                        get_local $l0
                        get_local $l6
                        i32.store offset=8
                        br $B0
                      end
                      get_local $l1
                      i32.const 256
                      i32.lt_u
                      br_if $B5
                      get_local $l4
                      get_local $l1
                      i32.const 4
                      i32.or
                      i32.lt_u
                      br_if $B5
                      get_local $l4
                      get_local $l1
                      i32.sub
                      i32.const 131073
                      i32.ge_u
                      br_if $B5
                      get_local $p0
                      return
                    end
                    block $B10
                      get_local $l4
                      get_local $l1
                      i32.sub
                      tee_local $p1
                      i32.const 16
                      i32.ge_u
                      br_if $B10
                      get_local $p0
                      return
                    end
                    get_local $l2
                    get_local $l1
                    get_local $l3
                    i32.const 1
                    i32.and
                    i32.or
                    i32.const 2
                    i32.or
                    i32.store
                    get_local $l5
                    get_local $l1
                    i32.add
                    tee_local $l0
                    get_local $p1
                    i32.const 3
                    i32.or
                    i32.store offset=4
                    get_local $l6
                    get_local $l6
                    i32.load offset=4
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    get_local $l0
                    get_local $p1
                    call $_ZN8dlmalloc8dlmalloc8Dlmalloc13dispose_chunk17hae5b7b0a563f1cedE
                    get_local $p0
                    return
                  end
                  i32.const 0
                  i32.load offset=72716
                  get_local $l4
                  i32.add
                  tee_local $l4
                  get_local $l1
                  i32.le_u
                  br_if $B5
                  get_local $l2
                  get_local $l1
                  get_local $l3
                  i32.const 1
                  i32.and
                  i32.or
                  i32.const 2
                  i32.or
                  i32.store
                  get_local $l5
                  get_local $l1
                  i32.add
                  tee_local $p1
                  get_local $l4
                  get_local $l1
                  i32.sub
                  tee_local $l0
                  i32.const 1
                  i32.or
                  i32.store offset=4
                  i32.const 0
                  get_local $l0
                  i32.store offset=72716
                  i32.const 0
                  get_local $p1
                  i32.store offset=72724
                  get_local $p0
                  return
                end
                i32.const 0
                i32.load offset=72712
                get_local $l4
                i32.add
                tee_local $l4
                get_local $l1
                i32.ge_u
                br_if $B3
              end
              get_local $p1
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc6malloc17hfb413fb9fd725095E
              tee_local $l1
              i32.eqz
              br_if $B4
              get_local $l1
              get_local $p0
              get_local $p1
              get_local $l2
              i32.load
              tee_local $l0
              i32.const -8
              i32.and
              i32.const 4
              i32.const 8
              get_local $l0
              i32.const 3
              i32.and
              select
              i32.sub
              tee_local $l0
              get_local $l0
              get_local $p1
              i32.gt_u
              select
              call $memcpy
              set_local $p1
              get_local $p0
              call $_ZN8dlmalloc8dlmalloc8Dlmalloc4free17hd564262fdf262c88E
              get_local $p1
              set_local $l0
            end
            get_local $l0
            return
          end
          block $B11
            block $B12
              get_local $l4
              get_local $l1
              i32.sub
              tee_local $p1
              i32.const 16
              i32.ge_u
              br_if $B12
              get_local $l2
              get_local $l3
              i32.const 1
              i32.and
              get_local $l4
              i32.or
              i32.const 2
              i32.or
              i32.store
              get_local $l5
              get_local $l4
              i32.add
              tee_local $p1
              get_local $p1
              i32.load offset=4
              i32.const 1
              i32.or
              i32.store offset=4
              i32.const 0
              set_local $p1
              i32.const 0
              set_local $l0
              br $B11
            end
            get_local $l2
            get_local $l1
            get_local $l3
            i32.const 1
            i32.and
            i32.or
            i32.const 2
            i32.or
            i32.store
            get_local $l5
            get_local $l1
            i32.add
            tee_local $l0
            get_local $p1
            i32.const 1
            i32.or
            i32.store offset=4
            get_local $l5
            get_local $l4
            i32.add
            tee_local $l1
            get_local $p1
            i32.store
            get_local $l1
            get_local $l1
            i32.load offset=4
            i32.const -2
            i32.and
            i32.store offset=4
          end
          i32.const 0
          get_local $l0
          i32.store offset=72720
          i32.const 0
          get_local $p1
          i32.store offset=72712
          get_local $p0
          return
        end
        get_local $l6
        call $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E
        br $B0
      end
      i32.const 0
      i32.const 0
      i32.load offset=72312
      i32.const -2
      get_local $l3
      i32.const 3
      i32.shr_u
      i32.rotl
      i32.and
      i32.store offset=72312
    end
    block $B13
      get_local $p1
      i32.const 15
      i32.gt_u
      br_if $B13
      get_local $l2
      get_local $l4
      get_local $l2
      i32.load
      i32.const 1
      i32.and
      i32.or
      i32.const 2
      i32.or
      i32.store
      get_local $l5
      get_local $l4
      i32.add
      tee_local $p1
      get_local $p1
      i32.load offset=4
      i32.const 1
      i32.or
      i32.store offset=4
      get_local $p0
      return
    end
    get_local $l2
    get_local $l1
    get_local $l2
    i32.load
    i32.const 1
    i32.and
    i32.or
    i32.const 2
    i32.or
    i32.store
    get_local $l5
    get_local $l1
    i32.add
    tee_local $l0
    get_local $p1
    i32.const 3
    i32.or
    i32.store offset=4
    get_local $l5
    get_local $l4
    i32.add
    tee_local $l1
    get_local $l1
    i32.load offset=4
    i32.const 1
    i32.or
    i32.store offset=4
    get_local $l0
    get_local $p1
    call $_ZN8dlmalloc8dlmalloc8Dlmalloc13dispose_chunk17hae5b7b0a563f1cedE
    get_local $p0)
  (func $_ZN8dlmalloc8dlmalloc8Dlmalloc18unlink_large_chunk17h2e93a8ff6becc561E (type $t2) (param $p0 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32)
    get_local $p0
    i32.load offset=24
    set_local $l0
    block $B0
      block $B1
        block $B2
          block $B3
            get_local $p0
            i32.load offset=12
            tee_local $l1
            get_local $p0
            i32.eq
            br_if $B3
            get_local $p0
            i32.load offset=8
            tee_local $l2
            get_local $l1
            i32.store offset=12
            get_local $l1
            get_local $l2
            i32.store offset=8
            get_local $l0
            br_if $B2
            br $B1
          end
          block $B4
            get_local $p0
            i32.const 20
            i32.const 16
            get_local $p0
            i32.const 20
            i32.add
            tee_local $l1
            i32.load
            tee_local $l3
            select
            i32.add
            i32.load
            tee_local $l2
            i32.eqz
            br_if $B4
            get_local $l1
            get_local $p0
            i32.const 16
            i32.add
            get_local $l3
            select
            set_local $l3
            block $B5
              loop $L6
                get_local $l3
                set_local $l4
                block $B7
                  get_local $l2
                  tee_local $l1
                  i32.const 20
                  i32.add
                  tee_local $l3
                  i32.load
                  tee_local $l2
                  i32.eqz
                  br_if $B7
                  get_local $l2
                  br_if $L6
                  br $B5
                end
                get_local $l1
                i32.const 16
                i32.add
                set_local $l3
                get_local $l1
                i32.load offset=16
                tee_local $l2
                br_if $L6
              end
            end
            get_local $l4
            i32.const 0
            i32.store
            get_local $l0
            br_if $B2
            br $B1
          end
          i32.const 0
          set_local $l1
          get_local $l0
          i32.eqz
          br_if $B1
        end
        block $B8
          block $B9
            get_local $p0
            i32.load offset=28
            i32.const 2
            i32.shl
            i32.const 72584
            i32.add
            tee_local $l2
            i32.load
            get_local $p0
            i32.eq
            br_if $B9
            get_local $l0
            i32.const 16
            i32.const 20
            get_local $l0
            i32.load offset=16
            get_local $p0
            i32.eq
            select
            i32.add
            get_local $l1
            i32.store
            get_local $l1
            br_if $B8
            br $B1
          end
          get_local $l2
          get_local $l1
          i32.store
          get_local $l1
          i32.eqz
          br_if $B0
        end
        get_local $l1
        get_local $l0
        i32.store offset=24
        block $B10
          get_local $p0
          i32.load offset=16
          tee_local $l2
          i32.eqz
          br_if $B10
          get_local $l1
          get_local $l2
          i32.store offset=16
          get_local $l2
          get_local $l1
          i32.store offset=24
        end
        get_local $p0
        i32.const 20
        i32.add
        i32.load
        tee_local $l2
        i32.eqz
        br_if $B1
        get_local $l1
        i32.const 20
        i32.add
        get_local $l2
        i32.store
        get_local $l2
        get_local $l1
        i32.store offset=24
      end
      return
    end
    i32.const 0
    i32.const 0
    i32.load offset=72316
    i32.const -2
    get_local $p0
    i32.const 28
    i32.add
    i32.load
    i32.rotl
    i32.and
    i32.store offset=72316)
  (func $rust_begin_unwind (type $t2) (param $p0 i32)
    get_local $p0
    call $_ZN3std9panicking18continue_panic_fmt17h8c6629cbc8212d9fE
    unreachable)
  (func $_ZN8dlmalloc8dlmalloc8Dlmalloc18insert_large_chunk17h71e31a434e422216E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32)
    i32.const 0
    set_local $l0
    block $B0
      get_local $p1
      i32.const 8
      i32.shr_u
      tee_local $l1
      i32.eqz
      br_if $B0
      i32.const 31
      set_local $l0
      get_local $p1
      i32.const 16777215
      i32.gt_u
      br_if $B0
      get_local $p1
      i32.const 38
      get_local $l1
      i32.clz
      tee_local $l0
      i32.sub
      i32.const 31
      i32.and
      i32.shr_u
      i32.const 1
      i32.and
      i32.const 31
      get_local $l0
      i32.sub
      i32.const 1
      i32.shl
      i32.or
      set_local $l0
    end
    get_local $p0
    i64.const 0
    i64.store offset=16 align=4
    get_local $p0
    get_local $l0
    i32.store offset=28
    get_local $l0
    i32.const 2
    i32.shl
    i32.const 72584
    i32.add
    set_local $l1
    block $B1
      block $B2
        block $B3
          block $B4
            block $B5
              i32.const 0
              i32.load offset=72316
              tee_local $l2
              i32.const 1
              get_local $l0
              i32.const 31
              i32.and
              i32.shl
              tee_local $l3
              i32.and
              i32.eqz
              br_if $B5
              get_local $l1
              i32.load
              tee_local $l2
              i32.load offset=4
              i32.const -8
              i32.and
              get_local $p1
              i32.ne
              br_if $B4
              get_local $l2
              set_local $l0
              br $B3
            end
            i32.const 0
            get_local $l2
            get_local $l3
            i32.or
            i32.store offset=72316
            get_local $l1
            get_local $p0
            i32.store
            get_local $p0
            get_local $l1
            i32.store offset=24
            br $B1
          end
          get_local $p1
          i32.const 0
          i32.const 25
          get_local $l0
          i32.const 1
          i32.shr_u
          i32.sub
          i32.const 31
          i32.and
          get_local $l0
          i32.const 31
          i32.eq
          select
          i32.shl
          set_local $l1
          loop $L6
            get_local $l2
            get_local $l1
            i32.const 29
            i32.shr_u
            i32.const 4
            i32.and
            i32.add
            i32.const 16
            i32.add
            tee_local $l3
            i32.load
            tee_local $l0
            i32.eqz
            br_if $B2
            get_local $l1
            i32.const 1
            i32.shl
            set_local $l1
            get_local $l0
            set_local $l2
            get_local $l0
            i32.load offset=4
            i32.const -8
            i32.and
            get_local $p1
            i32.ne
            br_if $L6
          end
        end
        get_local $l0
        i32.load offset=8
        tee_local $l1
        get_local $p0
        i32.store offset=12
        get_local $l0
        get_local $p0
        i32.store offset=8
        get_local $p0
        i32.const 0
        i32.store offset=24
        get_local $p0
        get_local $l0
        i32.store offset=12
        get_local $p0
        get_local $l1
        i32.store offset=8
        return
      end
      get_local $l3
      get_local $p0
      i32.store
      get_local $p0
      get_local $l2
      i32.store offset=24
    end
    get_local $p0
    get_local $p0
    i32.store offset=12
    get_local $p0
    get_local $p0
    i32.store offset=8)
  (func $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9c70dbf9f62fc318E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32)
    block $B0
      get_local $p0
      i32.load offset=4
      tee_local $l0
      get_local $p0
      i32.load offset=8
      tee_local $l1
      i32.sub
      get_local $p1
      i32.ge_u
      br_if $B0
      block $B1
        block $B2
          get_local $l1
          get_local $p1
          i32.add
          tee_local $p1
          get_local $l1
          i32.lt_u
          br_if $B2
          get_local $l0
          i32.const 1
          i32.shl
          tee_local $l1
          get_local $p1
          get_local $p1
          get_local $l1
          i32.lt_u
          select
          tee_local $p1
          i32.const 0
          i32.lt_s
          br_if $B2
          block $B3
            block $B4
              get_local $l0
              i32.eqz
              br_if $B4
              get_local $p0
              i32.load
              get_local $p1
              call $__rust_realloc
              tee_local $l0
              i32.eqz
              br_if $B3
              br $B1
            end
            get_local $p1
            i32.const 1
            call $__rust_alloc
            tee_local $l0
            br_if $B1
          end
          unreachable
          unreachable
        end
        call $_ZN5alloc7raw_vec17capacity_overflow17hc18be88cbff328c0E
        unreachable
      end
      get_local $p0
      get_local $l0
      i32.store
      get_local $p0
      i32.const 4
      i32.add
      get_local $p1
      i32.store
    end)
  (func $_ZN53_$LT$core..fmt..Error$u20$as$u20$core..fmt..Debug$GT$3fmt17h85215da58150d31eE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    i32.load offset=24
    i32.const 71744
    i32.const 5
    get_local $p1
    i32.const 28
    i32.add
    i32.load
    i32.load offset=12
    call_indirect (type $t0))
  (func $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17hc0ede3078af99198E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    get_local $p0
    i32.load
    get_local $p0
    i32.load offset=4
    call $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE)
  (func $_ZN4core3ptr18real_drop_in_place17h054501119c4a3b2aE (type $t2) (param $p0 i32))
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_str17hf3cf317ad18176deE (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32)
    get_local $p0
    i32.load
    tee_local $p0
    get_local $p2
    call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9c70dbf9f62fc318E
    get_local $p0
    get_local $p0
    i32.load offset=8
    tee_local $l0
    get_local $p2
    i32.add
    i32.store offset=8
    get_local $l0
    get_local $p0
    i32.load
    i32.add
    get_local $p1
    get_local $p2
    call $memcpy
    drop
    i32.const 0)
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$10write_char17ha07dfd0e93c05d86E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $p0
    i32.load
    set_local $p0
    block $B0
      block $B1
        get_local $p1
        i32.const 128
        i32.ge_u
        br_if $B1
        block $B2
          get_local $p0
          i32.load offset=8
          tee_local $l1
          get_local $p0
          i32.load offset=4
          i32.ne
          br_if $B2
          get_local $p0
          i32.const 1
          call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9c70dbf9f62fc318E
          get_local $p0
          i32.const 8
          i32.add
          i32.load
          set_local $l1
        end
        get_local $p0
        i32.load
        get_local $l1
        i32.add
        get_local $p1
        i32.store8
        get_local $p0
        i32.const 8
        i32.add
        tee_local $p0
        get_local $p0
        i32.load
        i32.const 1
        i32.add
        i32.store
        br $B0
      end
      get_local $l0
      i32.const 0
      i32.store offset=12
      block $B3
        block $B4
          get_local $p1
          i32.const 2048
          i32.ge_u
          br_if $B4
          get_local $l0
          get_local $p1
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=13
          get_local $l0
          get_local $p1
          i32.const 6
          i32.shr_u
          i32.const 31
          i32.and
          i32.const 192
          i32.or
          i32.store8 offset=12
          i32.const 2
          set_local $p1
          br $B3
        end
        block $B5
          get_local $p1
          i32.const 65535
          i32.gt_u
          br_if $B5
          get_local $l0
          get_local $p1
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=14
          get_local $l0
          get_local $p1
          i32.const 6
          i32.shr_u
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=13
          get_local $l0
          get_local $p1
          i32.const 12
          i32.shr_u
          i32.const 15
          i32.and
          i32.const 224
          i32.or
          i32.store8 offset=12
          i32.const 3
          set_local $p1
          br $B3
        end
        get_local $l0
        get_local $p1
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=15
        get_local $l0
        get_local $p1
        i32.const 18
        i32.shr_u
        i32.const 240
        i32.or
        i32.store8 offset=12
        get_local $l0
        get_local $p1
        i32.const 6
        i32.shr_u
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=14
        get_local $l0
        get_local $p1
        i32.const 12
        i32.shr_u
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=13
        i32.const 4
        set_local $p1
      end
      get_local $p0
      get_local $p1
      call $_ZN5alloc3vec12Vec$LT$T$GT$7reserve17h9c70dbf9f62fc318E
      get_local $p0
      get_local $p0
      i32.load offset=8
      tee_local $l1
      get_local $p1
      i32.add
      i32.store offset=8
      get_local $l1
      get_local $p0
      i32.load
      i32.add
      get_local $l0
      i32.const 12
      i32.add
      get_local $p1
      call $memcpy
      drop
    end
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    i32.const 0)
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_fmt17h074b16b834addde1E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    i32.load
    i32.store offset=4
    get_local $l0
    i32.const 8
    i32.add
    i32.const 16
    i32.add
    get_local $p1
    i32.const 16
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 8
    i32.add
    get_local $p1
    i32.const 8
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    get_local $p1
    i64.load align=4
    i64.store offset=8
    get_local $l0
    i32.const 4
    i32.add
    i32.const 66208
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
    set_local $p1
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $p1)
  (func $_ZN4core3fmt3num3imp7fmt_u6417hbdd21d5900fb3af9E (type $t14) (param $p0 i64) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i64) (local $l4 i32) (local $l5 i32)
    get_global $g0
    i32.const 48
    i32.sub
    tee_local $l0
    set_global $g0
    i32.const 39
    set_local $l1
    block $B0
      block $B1
        get_local $p0
        i64.const 10000
        i64.lt_u
        br_if $B1
        i32.const 39
        set_local $l1
        loop $L2
          get_local $l0
          i32.const 9
          i32.add
          get_local $l1
          i32.add
          tee_local $l2
          i32.const -4
          i32.add
          get_local $p0
          get_local $p0
          i64.const 10000
          i64.div_u
          tee_local $l3
          i64.const -10000
          i64.mul
          i64.add
          i32.wrap/i64
          tee_local $l4
          i32.const 100
          i32.div_u
          tee_local $l5
          i32.const 1
          i32.shl
          i32.const 66422
          i32.add
          i32.load16_u align=1
          i32.store16 align=1
          get_local $l2
          i32.const -2
          i32.add
          get_local $l5
          i32.const -100
          i32.mul
          get_local $l4
          i32.add
          i32.const 1
          i32.shl
          i32.const 66422
          i32.add
          i32.load16_u align=1
          i32.store16 align=1
          get_local $l1
          i32.const -4
          i32.add
          set_local $l1
          get_local $p0
          i64.const 99999999
          i64.gt_u
          set_local $l2
          get_local $l3
          set_local $p0
          get_local $l2
          br_if $L2
          br $B0
        end
      end
      get_local $p0
      set_local $l3
    end
    block $B3
      get_local $l3
      i32.wrap/i64
      tee_local $l2
      i32.const 99
      i32.le_s
      br_if $B3
      get_local $l0
      i32.const 9
      i32.add
      get_local $l1
      i32.const -2
      i32.add
      tee_local $l1
      i32.add
      get_local $l3
      i32.wrap/i64
      tee_local $l4
      i32.const 65535
      i32.and
      i32.const 100
      i32.div_u
      tee_local $l2
      i32.const -100
      i32.mul
      get_local $l4
      i32.add
      i32.const 65535
      i32.and
      i32.const 1
      i32.shl
      i32.const 66422
      i32.add
      i32.load16_u align=1
      i32.store16 align=1
    end
    block $B4
      block $B5
        get_local $l2
        i32.const 9
        i32.gt_s
        br_if $B5
        get_local $l0
        i32.const 9
        i32.add
        get_local $l1
        i32.const -1
        i32.add
        tee_local $l1
        i32.add
        get_local $l2
        i32.const 48
        i32.add
        i32.store8
        br $B4
      end
      get_local $l0
      i32.const 9
      i32.add
      get_local $l1
      i32.const -2
      i32.add
      tee_local $l1
      i32.add
      get_local $l2
      i32.const 1
      i32.shl
      i32.const 66422
      i32.add
      i32.load16_u align=1
      i32.store16 align=1
    end
    get_local $p1
    i32.const 66356
    i32.const 0
    get_local $l0
    i32.const 9
    i32.add
    get_local $l1
    i32.add
    i32.const 39
    get_local $l1
    i32.sub
    call $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE
    set_local $l1
    get_local $l0
    i32.const 48
    i32.add
    set_global $g0
    get_local $l1)
  (func $_ZN4core3ptr18real_drop_in_place17hf80635c1d9e9fcfeE (type $t2) (param $p0 i32))
  (func $_ZN36_$LT$T$u20$as$u20$core..any..Any$GT$7type_id17ha426714c6c623d5bE (type $t12) (param $p0 i32) (result i64)
    i64.const 1530670907205313052)
  (func $_ZN4core3fmt9Formatter12pad_integral12write_prefix17h233a3de9c8db3d12E (type $t15) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32) (result i32)
    (local $l0 i32)
    block $B0
      block $B1
        block $B2
          get_local $p1
          i32.const 1114112
          i32.eq
          br_if $B2
          i32.const 1
          set_local $l0
          get_local $p0
          i32.load offset=24
          get_local $p1
          get_local $p0
          i32.const 28
          i32.add
          i32.load
          i32.load offset=16
          call_indirect (type $t1)
          br_if $B1
        end
        get_local $p2
        i32.eqz
        br_if $B0
        get_local $p0
        i32.load offset=24
        get_local $p2
        get_local $p3
        get_local $p0
        i32.const 28
        i32.add
        i32.load
        i32.load offset=12
        call_indirect (type $t0)
        set_local $l0
      end
      get_local $l0
      return
    end
    i32.const 0)
  (func $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17h468011cee9e37c3cE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p1
    get_local $p0
    i32.load
    get_local $p0
    i32.load offset=4
    call $_ZN4core3fmt9Formatter3pad17h1e4b11204d50181cE)
  (func $_ZN71_$LT$core..ops..range..Range$LT$Idx$GT$$u20$as$u20$core..fmt..Debug$GT$3fmt17haa371cb72d173c09E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      block $B1
        get_local $p0
        i32.load
        get_local $p1
        call $_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..Debug$u20$for$u20$usize$GT$3fmt17h2ac732504b8a5f3dE
        br_if $B1
        get_local $p1
        i32.const 28
        i32.add
        i32.load
        set_local $l1
        get_local $p1
        i32.load offset=24
        set_local $l2
        get_local $l0
        i32.const 28
        i32.add
        i32.const 0
        i32.store
        get_local $l0
        i32.const 66356
        i32.store offset=24
        get_local $l0
        i64.const 1
        i64.store offset=12 align=4
        get_local $l0
        i32.const 67028
        i32.store offset=8
        get_local $l2
        get_local $l1
        get_local $l0
        i32.const 8
        i32.add
        call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
        i32.eqz
        br_if $B0
      end
      get_local $l0
      i32.const 32
      i32.add
      set_global $g0
      i32.const 1
      return
    end
    get_local $p0
    i32.load offset=4
    get_local $p1
    call $_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..Debug$u20$for$u20$usize$GT$3fmt17h2ac732504b8a5f3dE
    set_local $p1
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $p1)
  (func $_ZN41_$LT$char$u20$as$u20$core..fmt..Debug$GT$3fmt17hd562093c67995a2cE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i64) (local $l4 i32) (local $l5 i32)
    i32.const 1
    set_local $l0
    block $B0
      get_local $p1
      i32.load offset=24
      i32.const 39
      get_local $p1
      i32.const 28
      i32.add
      i32.load
      i32.load offset=16
      call_indirect (type $t1)
      br_if $B0
      i32.const 2
      set_local $l0
      block $B1
        block $B2
          block $B3
            block $B4
              block $B5
                block $B6
                  block $B7
                    block $B8
                      block $B9
                        block $B10
                          get_local $p0
                          i32.load
                          tee_local $p0
                          i32.const -9
                          i32.add
                          tee_local $l1
                          i32.const 30
                          i32.gt_u
                          br_if $B10
                          i32.const 116
                          set_local $l2
                          block $B11
                            get_local $l1
                            br_table $B1 $B11 $B9 $B9 $B8 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B9 $B5 $B9 $B9 $B9 $B9 $B5 $B1
                          end
                          i32.const 110
                          set_local $l2
                          br $B7
                        end
                        get_local $p0
                        i32.const 92
                        i32.eq
                        br_if $B5
                      end
                      get_local $p0
                      call $_ZN4core7unicode9bool_trie8BoolTrie6lookup17h3d273d837ffaaa8eE
                      i32.eqz
                      br_if $B6
                      get_local $p0
                      i32.const 1
                      i32.or
                      i32.clz
                      i32.const 2
                      i32.shr_u
                      i32.const 7
                      i32.xor
                      i64.extend_u/i32
                      i64.const 21474836480
                      i64.or
                      set_local $l3
                      br $B3
                    end
                    i32.const 114
                    set_local $l2
                  end
                  br $B1
                end
                block $B12
                  block $B13
                    get_local $p0
                    i32.const 65535
                    i32.gt_u
                    br_if $B13
                    get_local $p0
                    i32.const 67096
                    i32.const 40
                    i32.const 67176
                    i32.const 303
                    i32.const 67479
                    i32.const 316
                    call $_ZN4core7unicode9printable5check17h0590145f81e49885E
                    i32.eqz
                    br_if $B4
                    br $B12
                  end
                  block $B14
                    get_local $p0
                    i32.const 131071
                    i32.gt_u
                    br_if $B14
                    get_local $p0
                    i32.const 67795
                    i32.const 33
                    i32.const 67861
                    i32.const 158
                    i32.const 68019
                    i32.const 381
                    call $_ZN4core7unicode9printable5check17h0590145f81e49885E
                    br_if $B12
                    br $B4
                  end
                  get_local $p0
                  i32.const 917999
                  i32.gt_u
                  br_if $B4
                  get_local $p0
                  i32.const -195102
                  i32.add
                  i32.const 722658
                  i32.lt_u
                  br_if $B4
                  get_local $p0
                  i32.const -191457
                  i32.add
                  i32.const 3103
                  i32.lt_u
                  br_if $B4
                  get_local $p0
                  i32.const -183970
                  i32.add
                  i32.const 14
                  i32.lt_u
                  br_if $B4
                  get_local $p0
                  i32.const 2097150
                  i32.and
                  i32.const 178206
                  i32.eq
                  br_if $B4
                  get_local $p0
                  i32.const -173783
                  i32.add
                  i32.const 41
                  i32.lt_u
                  br_if $B4
                  get_local $p0
                  i32.const -177973
                  i32.add
                  i32.const 10
                  i32.le_u
                  br_if $B4
                end
                i32.const 1
                set_local $l0
              end
              br $B2
            end
            get_local $p0
            i32.const 1
            i32.or
            i32.clz
            i32.const 2
            i32.shr_u
            i32.const 7
            i32.xor
            i64.extend_u/i32
            i64.const 21474836480
            i64.or
            set_local $l3
          end
          i32.const 3
          set_local $l0
        end
        get_local $p0
        set_local $l2
      end
      get_local $p1
      i32.const 24
      i32.add
      set_local $l1
      get_local $p1
      i32.const 28
      i32.add
      set_local $l4
      block $B15
        loop $L16
          block $B17
            block $B18
              block $B19
                block $B20
                  block $B21
                    block $B22
                      block $B23
                        block $B24
                          block $B25
                            get_local $l0
                            i32.const 1
                            i32.eq
                            br_if $B25
                            i32.const 92
                            set_local $p0
                            get_local $l0
                            i32.const 2
                            i32.eq
                            br_if $B24
                            get_local $l0
                            i32.const 3
                            i32.ne
                            br_if $B15
                            get_local $l3
                            i64.const 32
                            i64.shr_u
                            i32.wrap/i64
                            i32.const 255
                            i32.and
                            i32.const -1
                            i32.add
                            tee_local $l0
                            i32.const 4
                            i32.gt_u
                            br_if $B15
                            block $B26
                              get_local $l0
                              br_table $B26 $B23 $B22 $B21 $B20 $B26
                            end
                            get_local $l3
                            i64.const -1095216660481
                            i64.and
                            set_local $l3
                            i32.const 125
                            set_local $p0
                            br $B18
                          end
                          i32.const 0
                          set_local $l0
                          get_local $l2
                          set_local $p0
                          br $B17
                        end
                        i32.const 1
                        set_local $l0
                        br $B17
                      end
                      get_local $l2
                      get_local $l3
                      i32.wrap/i64
                      tee_local $l5
                      i32.const 2
                      i32.shl
                      i32.const 28
                      i32.and
                      i32.shr_u
                      i32.const 15
                      i32.and
                      tee_local $l0
                      i32.const 48
                      i32.or
                      get_local $l0
                      i32.const 87
                      i32.add
                      get_local $l0
                      i32.const 10
                      i32.lt_u
                      select
                      set_local $p0
                      get_local $l5
                      i32.eqz
                      br_if $B19
                      get_local $l3
                      i64.const -1
                      i64.add
                      i64.const 4294967295
                      i64.and
                      get_local $l3
                      i64.const -4294967296
                      i64.and
                      i64.or
                      set_local $l3
                      br $B18
                    end
                    get_local $l3
                    i64.const -1095216660481
                    i64.and
                    i64.const 8589934592
                    i64.or
                    set_local $l3
                    i32.const 123
                    set_local $p0
                    br $B18
                  end
                  get_local $l3
                  i64.const -1095216660481
                  i64.and
                  i64.const 12884901888
                  i64.or
                  set_local $l3
                  i32.const 117
                  set_local $p0
                  br $B18
                end
                get_local $l3
                i64.const -1095216660481
                i64.and
                i64.const 17179869184
                i64.or
                set_local $l3
                br $B18
              end
              get_local $l3
              i64.const -1095216660481
              i64.and
              i64.const 4294967296
              i64.or
              set_local $l3
            end
            i32.const 3
            set_local $l0
          end
          get_local $l1
          i32.load
          get_local $p0
          get_local $l4
          i32.load
          i32.load offset=16
          call_indirect (type $t1)
          i32.eqz
          br_if $L16
        end
        i32.const 1
        return
      end
      get_local $p1
      i32.const 24
      i32.add
      i32.load
      i32.const 39
      get_local $p1
      i32.const 28
      i32.add
      i32.load
      i32.load offset=16
      call_indirect (type $t1)
      set_local $l0
    end
    get_local $l0)
  (func $_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..Debug$u20$for$u20$usize$GT$3fmt17h2ac732504b8a5f3dE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    get_global $g0
    i32.const 128
    i32.sub
    tee_local $l0
    set_global $g0
    block $B0
      block $B1
        block $B2
          block $B3
            block $B4
              get_local $p1
              i32.load
              tee_local $l1
              i32.const 16
              i32.and
              br_if $B4
              get_local $l1
              i32.const 32
              i32.and
              br_if $B3
              get_local $p0
              i64.extend_u/i32
              get_local $p1
              call $_ZN4core3fmt3num3imp7fmt_u6417hbdd21d5900fb3af9E
              set_local $p0
              br $B2
            end
            i32.const 0
            set_local $l1
            loop $L5
              get_local $l0
              get_local $l1
              i32.add
              i32.const 127
              i32.add
              get_local $p0
              i32.const 15
              i32.and
              tee_local $l2
              i32.const 48
              i32.or
              get_local $l2
              i32.const 87
              i32.add
              get_local $l2
              i32.const 10
              i32.lt_u
              select
              i32.store8
              get_local $l1
              i32.const -1
              i32.add
              set_local $l1
              get_local $p0
              i32.const 4
              i32.shr_u
              tee_local $p0
              br_if $L5
            end
            get_local $l1
            i32.const 128
            i32.add
            tee_local $p0
            i32.const 129
            i32.ge_u
            br_if $B1
            get_local $p1
            i32.const 66788
            i32.const 2
            get_local $l0
            get_local $l1
            i32.add
            i32.const 128
            i32.add
            i32.const 0
            get_local $l1
            i32.sub
            call $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE
            set_local $p0
            br $B2
          end
          i32.const 0
          set_local $l1
          loop $L6
            get_local $l0
            get_local $l1
            i32.add
            i32.const 127
            i32.add
            get_local $p0
            i32.const 15
            i32.and
            tee_local $l2
            i32.const 48
            i32.or
            get_local $l2
            i32.const 55
            i32.add
            get_local $l2
            i32.const 10
            i32.lt_u
            select
            i32.store8
            get_local $l1
            i32.const -1
            i32.add
            set_local $l1
            get_local $p0
            i32.const 4
            i32.shr_u
            tee_local $p0
            br_if $L6
          end
          get_local $l1
          i32.const 128
          i32.add
          tee_local $p0
          i32.const 129
          i32.ge_u
          br_if $B0
          get_local $p1
          i32.const 66788
          i32.const 2
          get_local $l0
          get_local $l1
          i32.add
          i32.const 128
          i32.add
          i32.const 0
          get_local $l1
          i32.sub
          call $_ZN4core3fmt9Formatter12pad_integral17h42589000db7da52eE
          set_local $p0
        end
        get_local $l0
        i32.const 128
        i32.add
        set_global $g0
        get_local $p0
        return
      end
      get_local $p0
      i32.const 128
      call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
      unreachable
    end
    get_local $p0
    i32.const 128
    call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
    unreachable)
  (func $_ZN4core3fmt10ArgumentV110show_usize17hc9a12049e7f6c81dE (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    i64.load32_u
    get_local $p1
    call $_ZN4core3fmt3num3imp7fmt_u6417hbdd21d5900fb3af9E)
  (func $_ZN4core5slice6memchr6memchr17h2b18dfe5a03392f7E (type $t7) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32) (local $l3 i32) (local $l4 i32) (local $l5 i32) (local $l6 i32)
    i32.const 0
    set_local $l0
    block $B0
      block $B1
        get_local $p2
        i32.const 3
        i32.and
        tee_local $l1
        i32.eqz
        br_if $B1
        i32.const 4
        get_local $l1
        i32.sub
        tee_local $l1
        i32.eqz
        br_if $B1
        get_local $p2
        get_local $p3
        get_local $l1
        get_local $l1
        get_local $p3
        i32.gt_u
        select
        tee_local $l0
        i32.add
        set_local $l2
        i32.const 0
        set_local $l1
        get_local $p1
        i32.const 255
        i32.and
        set_local $l3
        get_local $l0
        set_local $l4
        get_local $p2
        set_local $l5
        block $B2
          block $B3
            loop $L4
              get_local $l2
              get_local $l5
              i32.sub
              i32.const 3
              i32.le_u
              br_if $B3
              get_local $l1
              get_local $l5
              i32.load8_u
              tee_local $l6
              get_local $l3
              i32.ne
              i32.add
              set_local $l1
              get_local $l6
              get_local $l3
              i32.eq
              br_if $B2
              get_local $l1
              get_local $l5
              i32.const 1
              i32.add
              i32.load8_u
              tee_local $l6
              get_local $l3
              i32.ne
              i32.add
              set_local $l1
              get_local $l6
              get_local $l3
              i32.eq
              br_if $B2
              get_local $l1
              get_local $l5
              i32.const 2
              i32.add
              i32.load8_u
              tee_local $l6
              get_local $l3
              i32.ne
              i32.add
              set_local $l1
              get_local $l6
              get_local $l3
              i32.eq
              br_if $B2
              get_local $l1
              get_local $l5
              i32.const 3
              i32.add
              i32.load8_u
              tee_local $l6
              get_local $l3
              i32.ne
              i32.add
              set_local $l1
              get_local $l4
              i32.const -4
              i32.add
              set_local $l4
              get_local $l5
              i32.const 4
              i32.add
              set_local $l5
              get_local $l6
              get_local $l3
              i32.ne
              br_if $L4
              br $B2
            end
          end
          i32.const 0
          set_local $l3
          get_local $p1
          i32.const 255
          i32.and
          set_local $l2
          loop $L5
            get_local $l4
            i32.eqz
            br_if $B1
            get_local $l5
            get_local $l3
            i32.add
            set_local $l6
            get_local $l4
            i32.const -1
            i32.add
            set_local $l4
            get_local $l3
            i32.const 1
            i32.add
            set_local $l3
            get_local $l6
            i32.load8_u
            tee_local $l6
            get_local $l2
            i32.ne
            br_if $L5
          end
          get_local $l6
          get_local $p1
          i32.const 255
          i32.and
          i32.eq
          i32.const 1
          i32.add
          i32.const 1
          i32.and
          get_local $l1
          i32.add
          get_local $l3
          i32.add
          i32.const -1
          i32.add
          set_local $l1
        end
        i32.const 1
        set_local $l5
        br $B0
      end
      get_local $p1
      i32.const 255
      i32.and
      set_local $l3
      block $B6
        block $B7
          get_local $p3
          i32.const 8
          i32.lt_u
          br_if $B7
          get_local $l0
          get_local $p3
          i32.const -8
          i32.add
          tee_local $l6
          i32.gt_u
          br_if $B7
          get_local $l3
          i32.const 16843009
          i32.mul
          set_local $l1
          block $B8
            loop $L9
              get_local $p2
              get_local $l0
              i32.add
              tee_local $l5
              i32.const 4
              i32.add
              i32.load
              get_local $l1
              i32.xor
              tee_local $l4
              i32.const -1
              i32.xor
              get_local $l4
              i32.const -16843009
              i32.add
              i32.and
              get_local $l5
              i32.load
              get_local $l1
              i32.xor
              tee_local $l5
              i32.const -1
              i32.xor
              get_local $l5
              i32.const -16843009
              i32.add
              i32.and
              i32.or
              i32.const -2139062144
              i32.and
              br_if $B8
              get_local $l0
              i32.const 8
              i32.add
              tee_local $l0
              get_local $l6
              i32.le_u
              br_if $L9
            end
          end
          get_local $l0
          get_local $p3
          i32.gt_u
          br_if $B6
        end
        get_local $p2
        get_local $l0
        i32.add
        set_local $l5
        get_local $p2
        get_local $p3
        i32.add
        set_local $p2
        get_local $p3
        get_local $l0
        i32.sub
        set_local $l4
        i32.const 0
        set_local $l1
        block $B10
          block $B11
            block $B12
              loop $L13
                get_local $p2
                get_local $l5
                i32.sub
                i32.const 3
                i32.le_u
                br_if $B12
                get_local $l1
                get_local $l5
                i32.load8_u
                tee_local $l6
                get_local $l3
                i32.ne
                i32.add
                set_local $l1
                get_local $l6
                get_local $l3
                i32.eq
                br_if $B11
                get_local $l1
                get_local $l5
                i32.const 1
                i32.add
                i32.load8_u
                tee_local $l6
                get_local $l3
                i32.ne
                i32.add
                set_local $l1
                get_local $l6
                get_local $l3
                i32.eq
                br_if $B11
                get_local $l1
                get_local $l5
                i32.const 2
                i32.add
                i32.load8_u
                tee_local $l6
                get_local $l3
                i32.ne
                i32.add
                set_local $l1
                get_local $l6
                get_local $l3
                i32.eq
                br_if $B11
                get_local $l1
                get_local $l5
                i32.const 3
                i32.add
                i32.load8_u
                tee_local $l6
                get_local $l3
                i32.ne
                i32.add
                set_local $l1
                get_local $l4
                i32.const -4
                i32.add
                set_local $l4
                get_local $l5
                i32.const 4
                i32.add
                set_local $l5
                get_local $l6
                get_local $l3
                i32.ne
                br_if $L13
                br $B11
              end
            end
            i32.const 0
            set_local $l3
            get_local $p1
            i32.const 255
            i32.and
            set_local $p2
            loop $L14
              get_local $l4
              i32.eqz
              br_if $B10
              get_local $l5
              get_local $l3
              i32.add
              set_local $l6
              get_local $l4
              i32.const -1
              i32.add
              set_local $l4
              get_local $l3
              i32.const 1
              i32.add
              set_local $l3
              get_local $l6
              i32.load8_u
              tee_local $l6
              get_local $p2
              i32.ne
              br_if $L14
            end
            get_local $l6
            get_local $p1
            i32.const 255
            i32.and
            i32.eq
            i32.const 1
            i32.add
            i32.const 1
            i32.and
            get_local $l1
            i32.add
            get_local $l3
            i32.add
            i32.const -1
            i32.add
            set_local $l1
          end
          i32.const 1
          set_local $l5
          get_local $l1
          get_local $l0
          i32.add
          set_local $l1
          br $B0
        end
        i32.const 0
        set_local $l5
        get_local $l1
        get_local $l3
        i32.add
        get_local $l0
        i32.add
        set_local $l1
        br $B0
      end
      get_local $l0
      get_local $p3
      call $_ZN4core5slice22slice_index_order_fail17h73311624cbf066c4E
      unreachable
    end
    get_local $p0
    get_local $l1
    i32.store offset=4
    get_local $p0
    get_local $l5
    i32.store)
  (func $_ZN4core3ptr18real_drop_in_place17h1f9696819172dca5E (type $t2) (param $p0 i32))
  (func $_ZN4core3fmt5Write10write_char17h2ed46215e30dc0b8E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 0
    i32.store offset=12
    block $B0
      block $B1
        get_local $p1
        i32.const 127
        i32.gt_u
        br_if $B1
        get_local $l0
        get_local $p1
        i32.store8 offset=12
        i32.const 1
        set_local $p1
        br $B0
      end
      block $B2
        get_local $p1
        i32.const 2047
        i32.gt_u
        br_if $B2
        get_local $l0
        get_local $p1
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=13
        get_local $l0
        get_local $p1
        i32.const 6
        i32.shr_u
        i32.const 31
        i32.and
        i32.const 192
        i32.or
        i32.store8 offset=12
        i32.const 2
        set_local $p1
        br $B0
      end
      block $B3
        get_local $p1
        i32.const 65535
        i32.gt_u
        br_if $B3
        get_local $l0
        get_local $p1
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=14
        get_local $l0
        get_local $p1
        i32.const 6
        i32.shr_u
        i32.const 63
        i32.and
        i32.const 128
        i32.or
        i32.store8 offset=13
        get_local $l0
        get_local $p1
        i32.const 12
        i32.shr_u
        i32.const 15
        i32.and
        i32.const 224
        i32.or
        i32.store8 offset=12
        i32.const 3
        set_local $p1
        br $B0
      end
      get_local $l0
      get_local $p1
      i32.const 63
      i32.and
      i32.const 128
      i32.or
      i32.store8 offset=15
      get_local $l0
      get_local $p1
      i32.const 18
      i32.shr_u
      i32.const 240
      i32.or
      i32.store8 offset=12
      get_local $l0
      get_local $p1
      i32.const 6
      i32.shr_u
      i32.const 63
      i32.and
      i32.const 128
      i32.or
      i32.store8 offset=14
      get_local $l0
      get_local $p1
      i32.const 12
      i32.shr_u
      i32.const 63
      i32.and
      i32.const 128
      i32.or
      i32.store8 offset=13
      i32.const 4
      set_local $p1
    end
    get_local $p0
    get_local $l0
    i32.const 12
    i32.add
    get_local $p1
    call $_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h11c6108e80c941f6E
    set_local $p1
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0
    get_local $p1)
  (func $_ZN4core3fmt5Write9write_fmt17ha045dd71041e1298E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    i32.store offset=4
    get_local $l0
    i32.const 8
    i32.add
    i32.const 16
    i32.add
    get_local $p1
    i32.const 16
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 8
    i32.add
    get_local $p1
    i32.const 8
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    get_local $p1
    i64.load align=4
    i64.store offset=8
    get_local $l0
    i32.const 4
    i32.add
    i32.const 71716
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
    set_local $p1
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $p1)
  (func $_ZN4core3ptr18real_drop_in_place17h042e5dfd8e37a666E (type $t2) (param $p0 i32))
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_str17hf460eac3bb7cd594E (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    get_local $p0
    i32.load
    get_local $p1
    get_local $p2
    call $_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h11c6108e80c941f6E)
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$10write_char17h38bc840b3a0afc36E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    get_local $p0
    i32.load
    get_local $p1
    call $_ZN4core3fmt5Write10write_char17h2ed46215e30dc0b8E)
  (func $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_fmt17h67f9ec9ffa1edb73E (type $t1) (param $p0 i32) (param $p1 i32) (result i32)
    (local $l0 i32)
    get_global $g0
    i32.const 32
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    i32.load
    i32.store offset=4
    get_local $l0
    i32.const 8
    i32.add
    i32.const 16
    i32.add
    get_local $p1
    i32.const 16
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    i32.const 8
    i32.add
    i32.const 8
    i32.add
    get_local $p1
    i32.const 8
    i32.add
    i64.load align=4
    i64.store
    get_local $l0
    get_local $p1
    i64.load align=4
    i64.store offset=8
    get_local $l0
    i32.const 4
    i32.add
    i32.const 71716
    get_local $l0
    i32.const 8
    i32.add
    call $_ZN4core3fmt5write17h169d0abdd64fe5b9E
    set_local $p1
    get_local $l0
    i32.const 32
    i32.add
    set_global $g0
    get_local $p1)
  (func $_ZN4core3ptr18real_drop_in_place17h31b6e3a475bfede3E (type $t2) (param $p0 i32)
    get_local $p0
    i32.load offset=4
    get_local $p0
    i32.const 8
    i32.add
    i32.load
    call $_ZN77_$LT$alloc..raw_vec..RawVec$LT$T$C$A$GT$$u20$as$u20$core..ops..drop..Drop$GT$4drop17h6fdbf669a9da6c0eE)
  (func $_ZN8ink_core3env3api6return17h4c7486d53da12064E (type $t2) (param $p0 i32)
    (local $l0 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    get_local $p0
    call $_ZN12parity_codec5codec6Encode6encode17h9ea988c7b7fac586E
    get_local $l0
    i32.load
    get_local $l0
    i32.load offset=8
    call $_ZN102_$LT$ink_core..env..srml..srml_only..impls..SrmlEnv$LT$T$GT$$u20$as$u20$ink_core..env..traits..Env$GT$6return17hbe7183c0b809ce22E
    unreachable)
  (func $_ZN102_$LT$ink_core..env..srml..srml_only..impls..SrmlEnv$LT$T$GT$$u20$as$u20$ink_core..env..traits..Env$GT$6return17hbe7183c0b809ce22E (type $t4) (param $p0 i32) (param $p1 i32)
    get_local $p0
    get_local $p1
    call $ext_return
    unreachable)
  (func $_ZN12parity_codec5codec6Encode6encode17h9ea988c7b7fac586E (type $t4) (param $p0 i32) (param $p1 i32)
    (local $l0 i32) (local $l1 i32)
    get_global $g0
    i32.const 16
    i32.sub
    tee_local $l0
    set_global $g0
    get_local $l0
    i32.const 0
    i32.store offset=8
    get_local $l0
    i64.const 1
    i64.store
    get_local $p1
    i32.load
    set_local $l1
    block $B0
      block $B1
        get_local $p1
        i32.load offset=8
        tee_local $p1
        i32.const 63
        i32.gt_u
        br_if $B1
        get_local $l0
        get_local $p1
        i32.const 2
        i32.shl
        call $_ZN12parity_codec5codec6Output9push_byte17h60c47774d3e8492eE
        br $B0
      end
      block $B2
        get_local $p1
        i32.const 16384
        i32.ge_u
        br_if $B2
        get_local $l0
        get_local $p1
        i32.const 2
        i32.shl
        i32.const 1
        i32.or
        i32.store16 offset=14
        get_local $l0
        get_local $l0
        i32.const 14
        i32.add
        get_local $l0
        i32.const 14
        i32.add
        i32.const 2
        i32.add
        call $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE
        br $B0
      end
      block $B3
        get_local $p1
        i32.const 1073741824
        i32.ge_u
        br_if $B3
        get_local $p1
        i32.const 2
        i32.shl
        i32.const 2
        i32.or
        get_local $l0
        call $_ZN12parity_codec5codec6Encode9encode_to17h73a00f1df427205aE
        br $B0
      end
      get_local $l0
      i32.const 3
      call $_ZN12parity_codec5codec6Output9push_byte17h60c47774d3e8492eE
      get_local $p1
      get_local $l0
      call $_ZN12parity_codec5codec6Encode9encode_to17h73a00f1df427205aE
    end
    get_local $l0
    get_local $l1
    get_local $l1
    get_local $p1
    i32.add
    call $_ZN109_$LT$alloc..vec..Vec$LT$T$GT$$u20$as$u20$alloc..vec..SpecExtend$LT$$RF$T$C$core..slice..Iter$LT$T$GT$$GT$$GT$11spec_extend17h8e5c375d7ce6a5abE
    get_local $p0
    i32.const 8
    i32.add
    get_local $l0
    i32.const 8
    i32.add
    i32.load
    i32.store
    get_local $p0
    get_local $l0
    i64.load
    i64.store align=4
    get_local $l0
    i32.const 16
    i32.add
    set_global $g0)
  (func $memcpy (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32)
    block $B0
      get_local $p2
      i32.eqz
      br_if $B0
      get_local $p0
      set_local $l0
      loop $L1
        get_local $l0
        get_local $p1
        i32.load8_u
        i32.store8
        get_local $l0
        i32.const 1
        i32.add
        set_local $l0
        get_local $p1
        i32.const 1
        i32.add
        set_local $p1
        get_local $p2
        i32.const -1
        i32.add
        tee_local $p2
        br_if $L1
      end
    end
    get_local $p0)
  (func $memcmp (type $t0) (param $p0 i32) (param $p1 i32) (param $p2 i32) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    block $B0
      block $B1
        get_local $p2
        i32.eqz
        br_if $B1
        i32.const 0
        set_local $l0
        loop $L2
          get_local $p0
          get_local $l0
          i32.add
          i32.load8_u
          tee_local $l1
          get_local $p1
          get_local $l0
          i32.add
          i32.load8_u
          tee_local $l2
          i32.ne
          br_if $B0
          get_local $l0
          i32.const 1
          i32.add
          tee_local $l0
          get_local $p2
          i32.lt_u
          br_if $L2
        end
        i32.const 0
        return
      end
      i32.const 0
      return
    end
    get_local $l1
    get_local $l2
    i32.sub)
  (table $T0 37 37 anyfunc)
  (global $g0 (mut i32) (i32.const 65536))
  (global $__heap_base i32 (i32.const 72780))
  (global $__data_end i32 (i32.const 72780))
  (export "__heap_base" (global 1))
  (export "__data_end" (global 2))
  (export "deploy" (func $deploy))
  (export "call" (func $call))
  (elem (i32.const 1) $_ZN41_$LT$bool$u20$as$u20$core..fmt..Debug$GT$3fmt17h6e76691aa32b4959E $_ZN4core3fmt10ArgumentV110show_usize17hc9a12049e7f6c81dE $_ZN53_$LT$core..fmt..Error$u20$as$u20$core..fmt..Debug$GT$3fmt17h85215da58150d31eE $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17hc0ede3078af99198E $_ZN4core3ops8function6FnOnce9call_once17h7e1ab6538c08cd8dE $_ZN4core3ops8function6FnOnce9call_once17he980da835ebbfea8E $_ZN4core3ops8function6FnOnce9call_once17h37b6823600c7a586E $_ZN59_$LT$core..fmt..Arguments$u20$as$u20$core..fmt..Display$GT$3fmt17h8bde5d3365f3f301E $_ZN42_$LT$$RF$T$u20$as$u20$core..fmt..Debug$GT$3fmt17h935f3c1118c8b920E $_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u32$GT$3fmt17hcc01d718c23da93bE $_ZN63_$LT$core..cell..BorrowMutError$u20$as$u20$core..fmt..Debug$GT$3fmt17h83f9fd6e715251a1E $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17h0cbe85a258a2765aE $_ZN60_$LT$core..cell..BorrowError$u20$as$u20$core..fmt..Debug$GT$3fmt17hdc09f16504a2fabcE $_ZN44_$LT$$RF$T$u20$as$u20$core..fmt..Display$GT$3fmt17h468011cee9e37c3cE $_ZN71_$LT$core..ops..range..Range$LT$Idx$GT$$u20$as$u20$core..fmt..Debug$GT$3fmt17haa371cb72d173c09E $_ZN41_$LT$char$u20$as$u20$core..fmt..Debug$GT$3fmt17hd562093c67995a2cE $_ZN4core3ptr18real_drop_in_place17h198c3d448ebf8f05E $_ZN111_$LT$std..sys_common..process..DefaultEnvKey$u20$as$u20$core..borrow..Borrow$LT$std..ffi..os_str..OsStr$GT$$GT$6borrow17h92dc1cb852cfd40dE $_ZN3std5error5Error5cause17hc22d55c663012a04E $_ZN3std5error5Error7type_id17hc0fd654050e42636E $_ZN249_$LT$std..error..$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..boxed..Box$LT$dyn$u20$$u2b$std..error..Error$u2b$core..marker..Sync$u2b$core..marker..Send$GT$$GT$..from..StringError$u20$as$u20$core..fmt..Display$GT$3fmt17hf5ecbeb9aafbf6efE $_ZN247_$LT$std..error..$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..boxed..Box$LT$dyn$u20$$u2b$std..error..Error$u2b$core..marker..Sync$u2b$core..marker..Send$GT$$GT$..from..StringError$u20$as$u20$core..fmt..Debug$GT$3fmt17hd9e8742f7e5307dfE $_ZN4core3ptr18real_drop_in_place17h054501119c4a3b2aE $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_str17hf3cf317ad18176deE $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$10write_char17ha07dfd0e93c05d86E $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_fmt17h074b16b834addde1E $_ZN4core3ptr18real_drop_in_place17hf80635c1d9e9fcfeE $_ZN36_$LT$T$u20$as$u20$core..any..Any$GT$7type_id17ha426714c6c623d5bE $_ZN4core3ptr18real_drop_in_place17h1f9696819172dca5E $_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h11c6108e80c941f6E $_ZN4core3fmt5Write10write_char17h2ed46215e30dc0b8E $_ZN4core3fmt5Write9write_fmt17ha045dd71041e1298E $_ZN4core3ptr18real_drop_in_place17h042e5dfd8e37a666E $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_str17hf460eac3bb7cd594E $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$10write_char17h38bc840b3a0afc36E $_ZN50_$LT$$RF$mut$u20$W$u20$as$u20$core..fmt..Write$GT$9write_fmt17h67f9ec9ffa1edb73E)
  (data (i32.const 65536) "Storage Value: \00\00\00\01\00\0f\00\00\00encountered invalid arguments for selected messageencountered invalid message selector\00\00\80\00\01\00d\00\00\00/\00\00\00\09\00\00\00/home/sunrisevizag01/.cargo/registry/src/github.com-1ecc6299db9ec823/parity-codec-4.1.3/src/codec.rsinternal error: entered unreachable codefailed to fill whole buffer\00@\01\01\00F\00\00\00\ef\00\00\00\16\00\00\00\00\00\00\00\00\00\00\00/rustc/d35181ad8785fa958e43580a29a982afe02c728f/src/libstd/io/impls.rs\00\00\a0\01\01\00-\00\00\00\cd\01\01\00\0c\00\00\00\d9\01\01\00\03\00\00\00assertion failed: `(left == right)`\0a  left: ``,\0a right: ``: \e4\01\01\004\00\00\00destination and source slices have different lengths`\04\01\00\18\00\00\00K\08\00\00\09\00\00\00\00\00\00\00\00\00\00\00\11\00\00\00\0c\00\00\00\04\00\00\00\12\00\00\00\13\00\00\00\13\00\00\00\14\00\00\00\15\00\00\00\16\00\00\00StringError\00x\02\01\00\11\00\00\00\89\02\01\00\17\00\00\00\ea\02\00\00\05\00\00\00capacity overflowsrc/liballoc/raw_vec.rs\17\00\00\00\04\00\00\00\04\00\00\00\18\00\00\00\19\00\00\00\1a\00\00\00a formatting trait implementation returned an error\004\03\01\00\00\00\00\00!\03\01\00\02\00\00\00\0c\03\01\00\15\00\00\00\e7\03\00\00\05\00\00\00src/libcore/result.rs: \00D\03\01\00 \00\00\00d\03\01\00\12\00\00\00\1b\00\00\00\00\00\00\00\01\00\00\00\1c\00\00\00index out of bounds: the len is  but the index is 00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899\00\00x\04\01\00\06\00\00\00~\04\01\00\22\00\00\00`\04\01\00\18\00\00\00\09\0a\00\00\05\00\00\00src/libcore/slice/mod.rsindex  out of range for slice of length \c0\04\01\00\16\00\00\00\d6\04\01\00\0d\00\00\00`\04\01\00\18\00\00\00\0f\0a\00\00\05\00\00\00slice index starts at  but ends at `0x[...]\00\92\05\01\00\0b\00\00\00\ca\17\01\00\16\00\00\00\e3\04\01\00\01\00\00\00|\05\01\00\16\00\00\00\eb\07\00\00\09\00\00\00\a8\17\01\00\0e\00\00\00\b6\17\01\00\04\00\00\00\ba\17\01\00\10\00\00\00\e3\04\01\00\01\00\00\00|\05\01\00\16\00\00\00\ef\07\00\00\05\00\00\00\92\05\01\00\0b\00\00\00\9d\05\01\00&\00\00\00\c3\05\01\00\08\00\00\00\cb\05\01\00\06\00\00\00\e3\04\01\00\01\00\00\00|\05\01\00\16\00\00\00\fc\07\00\00\05\00\00\00src/libcore/str/mod.rsbyte index  is not a char boundary; it is inside  (bytes ) of `\00\00\00\16\06\01\00\02\00\00\00\00\06\01\00\16\00\00\00T\04\00\00\11\00\00\00\00\06\01\00\16\00\00\00H\04\00\00(\00\00\00\00\00\00\00src/libcore/fmt/mod.rs..\00\01\03\05\05\06\06\03\07\06\08\08\09\11\0a\1c\0b\19\0c\14\0d\12\0e\16\0f\04\10\03\12\12\13\09\16\01\17\05\18\02\19\03\1a\07\1c\02\1d\01\1f\16 \03+\06,\02-\0b.\010\031\022\02\a9\02\aa\04\ab\08\fa\02\fb\05\fd\04\fe\03\ff\09\adxy\8b\8d\a20WX\8b\8c\90\1c\1d\dd\0e\0fKL\fb\fc./?\5c]_\b5\e2\84\8d\8e\91\92\a9\b1\ba\bb\c5\c6\c9\ca\de\e4\e5\ff\00\04\11\12)147:;=IJ]\84\8e\92\a9\b1\b4\ba\bb\c6\ca\ce\cf\e4\e5\00\04\0d\0e\11\12)14:;EFIJ^de\84\91\9b\9d\c9\ce\cf\0d\11)EIWde\8d\91\a9\b4\ba\bb\c5\c9\df\e4\e5\f0\04\0d\11EIde\80\81\84\b2\bc\be\bf\d5\d7\f0\f1\83\85\86\89\8b\8c\98\a0\a4\a6\a8\a9\ac\ba\be\bf\c5\c7\ce\cf\da\dbH\98\bd\cd\c6\ce\cfINOWY^_\89\8e\8f\b1\b6\b7\bf\c1\c6\c7\d7\11\16\17[\5c\f6\f7\fe\ff\80\0dmq\de\df\0e\0f\1fno\1c\1d_}~\ae\af\bb\bc\fa\16\17\1e\1fFGNOXZ\5c^~\7f\b5\c5\d4\d5\dc\f0\f1\f5rs\8ftu\96\97\c9\ff/_&./\a7\af\b7\bf\c7\cf\d7\df\9a@\97\980\8f\1f\ff\ce\ffNOZ[\07\08\0f\10'/\ee\efno7=?BE\90\91\fe\ffSgu\c8\c9\d0\d1\d8\d9\e7\fe\ff\00 _\22\82\df\04\82D\08\1b\04\06\11\81\ac\0e\80\ab5\1e\15\80\e0\03\19\08\01\04/\044\04\07\03\01\07\06\07\11\0aP\0f\12\07U\08\02\04\1c\0a\09\03\08\03\07\03\02\03\03\03\0c\04\05\03\0b\06\01\0e\15\05:\03\11\07\06\05\10\08V\07\02\07\15\0dP\04C\03-\03\01\04\11\06\0f\0c:\04\1d%\0d\06L m\04j%\80\c8\05\82\b0\03\1a\06\82\fd\03Y\07\15\0b\17\09\14\0c\14\0cj\06\0a\06\1a\06Y\07+\05F\0a,\04\0c\04\01\031\0b,\04\1a\06\0b\03\80\ac\06\0a\06\1fAL\04-\03t\08<\03\0f\03<\078\08*\06\82\ff\11\18\08/\11-\03 \10!\0f\80\8c\04\82\97\19\0b\15\88\94\05/\05;\07\02\0e\18\09\80\af1t\0c\80\d6\1a\0c\05\80\ff\05\80\b6\05$\0c\9b\c6\0a\d20\10\84\8d\037\09\81\5c\14\80\b8\08\80\ba=5\04\0a\068\08F\08\0c\06t\0b\1e\03Z\04Y\09\80\83\18\1c\0a\16\09F\0a\80\8a\06\ab\a4\0c\17\041\a1\04\81\da&\07\0c\05\05\80\a5\11\81m\10x(*\06L\04\80\8d\04\80\be\03\1b\03\0f\0d\00\06\01\01\03\01\04\02\08\08\09\02\0a\05\0b\02\10\01\11\04\12\05\13\11\14\02\15\02\17\02\1a\02\1c\05\1d\08$\01j\03k\02\bc\02\d1\02\d4\0c\d5\09\d6\02\d7\02\da\01\e0\05\e8\02\ee \f0\04\f9\04\0c';>NO\8f\9e\9e\9f\06\07\096=>V\f3\d0\d1\04\14\1867VW\bd5\ce\cf\e0\12\87\89\8e\9e\04\0d\0e\11\12)14:EFIJNOdeZ\5c\b6\b7\1b\1c\84\85\097\90\91\a8\07\0a;>fi\8f\92o_\ee\efZb\9a\9b'(U\9d\a0\a1\a3\a4\a7\a8\ad\ba\bc\c4\06\0b\0c\15\1d:?EQ\a6\a7\cc\cd\a0\07\19\1a\22%\c5\c6\04 #%&(38:HJLPSUVXZ\5c^`cefksx}\7f\8a\a4\aa\af\b0\c0\d0?qr{^\22{\05\03\04-\03e\04\01/.\80\82\1d\031\0f\1c\04$\09\1e\05+\05D\04\0e*\80\aa\06$\04$\04(\084\0b\01\80\90\817\09\16\0a\08\80\989\03c\08\090\16\05!\03\1b\05\01@8\04K\05/\04\0a\07\09\07@ '\04\0c\096\03:\05\1a\07\04\0c\07PI73\0d3\07.\08\0a\81&\1f\80\81(\08*\80\a6N\04\1e\0fC\0e\19\07\0a\06G\09'\09u\0b?A*\06;\05\0a\06Q\06\01\05\10\03\05\80\8b_!H\08\0a\80\a6^\22E\0b\0a\06\0d\138\08\0a6,\04\10\80\c0<dS\0c\01\81\00H\08S\1d9\81\07F\0a\1d\03GI7\03\0e\08\0a\069\07\0a\816\19\81\07\83\9afu\0b\80\c4\8a\bc\84/\8f\d1\82G\a1\b9\829\07*\04\02`&\0aF\0a(\05\13\82\b0[eE\0b/\10\11@\02\1e\97\f2\0e\82\f3\a5\0d\81\1fQ\81\8c\89\04k\05\0d\03\09\07\10\93`\80\f6\0as\08n\17F\80\9a\14\0cW\09\19\80\87\81G\03\85B\0f\15\85P+\87\d5\80\d7)K\05\0a\04\02\83\11D\81K<\06\01\04U\05\1b4\02\81\0e,\04d\0cV\0a\0d\03\5c\04=9\1d\0d,\04\09\07\02\0e\06\80\9a\83\d5\0b\0d\03\0a\06t\0cY'\0c\048\08\0a\06(\08\1eR\0c\04g\03)\0d\0a\06\03\0d0`\0e\85\92\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\f8\03\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\fe\ff\ff\ff\ff\bf\b6\00\00\00\00\00\00\00\00\00\ff\07\00\00\00\00\00\f8\ff\ff\00\00\01\00\00\00\00\00\00\00\00\00\00\00\c0\9f\9f=\00\00\00\00\02\00\00\00\ff\ff\ff\07\00\00\00\00\00\00\00\00\00\00\c0\ff\01\00\00\00\00\00\00\f8\0f \a0\11\01\00J\00\00\00\f0\13\01\00\00\02\00\00\f0\15\01\007\00\00\00\00\01\02\03\04\05\06\07\08\09\08\0a\0b\0c\0d\0e\0f\10\11\12\13\14\02\15\16\17\18\19\1a\1b\1c\1d\1e\1f \02\02\02\02\02\02\02\02\02\02!\02\02\02\02\02\02\02\02\02\02\02\02\02\02\22#$%&\02'\02(\02\02\02)*+\02,-./0\02\021\02\02\022\02\02\02\02\02\02\02\023\02\024\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\025\026\027\02\02\02\02\02\02\02\028\029\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02:;<\02\02\02\02=\02\02>?@ABCDEF\02\02\02G\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02H\02\02\02\02\02\02\02\02\02\02\02I\02\02\02\02\02;\02\00\01\02\02\02\02\03\02\02\02\02\04\02\05\06\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\07\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\80\11\01\00 \00\00\00'\00\00\00\19\00\00\00\80\11\01\00 \00\00\00(\00\00\00 \00\00\00\80\11\01\00 \00\00\00*\00\00\00\19\00\00\00\80\11\01\00 \00\00\00+\00\00\00\18\00\00\00\80\11\01\00 \00\00\00,\00\00\00 \00\00\00\00\00\00\00\00\00\00\00src/libcore/unicode/bool_trie.rs\00\00\c0\fb\ef>\00\00\00\00\00\0e\00\00\00\00\00\00\00\00\00\00\00\00\00\00\f8\ff\fb\ff\ff\ff\07\00\00\00\00\00\00\14\fe!\fe\00\0c\00\00\00\02\00\00\00\00\00\00P\1e \80\00\0c\00\00@\06\00\00\00\00\00\00\10\869\02\00\00\00#\00\be!\00\00\0c\00\00\fc\02\00\00\00\00\00\00\d0\1e \c0\00\0c\00\00\00\04\00\00\00\00\00\00@\01 \80\00\00\00\00\00\11\00\00\00\00\00\00\c0\c1=`\00\0c\00\00\00\02\00\00\00\00\00\00\90D0`\00\0c\00\00\00\03\00\00\00\00\00\00X\1e \80\00\0c\00\00\00\00\84\5c\80\00\00\00\00\00\00\00\00\00\00\f2\07\80\7f\00\00\00\00\00\00\00\00\00\00\00\00\f2\1b\00?\00\00\00\00\00\00\00\00\00\03\00\00\a0\02\00\00\00\00\00\00\fe\7f\df\e0\ff\fe\ff\ff\ff\1f@\00\00\00\00\00\00\00\00\00\00\00\00\e0\fdf\00\00\00\c3\01\00\1e\00d \00 \00\00\00\00\00\00\00\e0\00\00\00\00\00\00\1c\00\00\00\1c\00\00\00\0c\00\00\00\0c\00\00\00\00\00\00\00\b0?@\fe\0f \00\00\00\00\008\00\00\00\00\00\00`\00\00\00\00\02\00\00\00\00\00\00\87\01\04\0e\00\00\80\09\00\00\00\00\00\00@\7f\e5\1f\f8\9f\00\00\00\00\00\00\ff\7f\0f\00\00\00\00\00\d0\17\04\00\00\00\00\f8\0f\00\03\00\00\00<;\00\00\00\00\00\00@\a3\03\00\00\00\00\00\00\f0\cf\00\00\00\f7\ff\fd!\10\03\ff\ff\ff\ff\ff\ff\ff\fb\00\10\00\00\00\00\00\00\00\00\ff\ff\ff\ff\01\00\00\00\00\00\00\80\03\00\00\00\00\00\00\00\00\80\00\00\00\00\ff\ff\ff\ff\00\00\00\00\00\fc\00\00\00\00\00\06\00\00\00\00\00\00\00\00\00\80\f7?\00\00\00\c0\00\00\00\00\00\00\00\00\00\00\03\00D\08\00\00`\00\00\000\00\00\00\ff\ff\03\80\00\00\00\00\c0?\00\00\80\ff\03\00\00\00\00\00\07\00\00\00\00\00\c8\13\00\00\00\00 \00\00\00\00\00\00\00\00~f\00\08\10\00\00\00\00\00\10\00\00\00\00\00\00\9d\c1\02\00\00\00\000@\00\00\00\00\00 !\00\00\00\00\00@\00\00\00\00\ff\ff\00\00\ff\ff\00\00\00\00\00\00\00\00\00\01\00\00\00\02\00\03\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\04\00\00\05\00\00\00\00\00\00\00\00\06\00\00\00\00\00\00\00\00\07\00\00\08\09\0a\00\0b\0c\0d\0e\0f\00\00\10\11\12\00\00\13\14\15\16\00\00\17\18\19\1a\1b\00\1c\00\00\00\1d\00\00\00\00\00\00\00\1e\1f \00\00\00\00\00!\00\22\00#$%\00\00\00\00&\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00'(\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00)\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00*\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00+,\00\00-\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00./0\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\001\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\002\003\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0045\00\005556\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00 \00\00\00\00\01\00\00\00\00\00\00\00\00\00\c0\07n\f0\00\00\00\00\00\87\00\00\00\00`\00\00\00\00\00\00\00\f0\00\00\00\c0\ff\01\00\00\00\00\00\02\00\00\00\00\00\00\ff\7f\00\00\00\00\00\00\80\03\00\00\00\00\00x\06\07\00\00\00\80\ef\1f\00\00\00\00\00\00\00\08\00\03\00\00\00\00\00\c0\7f\00\1e\00\00\00\00\00\00\00\00\00\00\00\80\d3@\00\00\00\80\f8\07\00\00\03\00\00\00\00\00\00X\01\00\80\00\c0\1f\1f\00\00\00\00\00\00\00\00\ff\5c\00\00@\00\00\00\00\00\00\00\00\00\00\f9\a5\0d\00\00\00\00\00\00\00\00\00\00\00\00\80<\b0\01\00\000\00\00\00\00\00\00\00\00\00\00\f8\a7\01\00\00\00\00\00\00\00\00\00\00\00\00(\bf\00\00\00\00\e0\bc\0f\00\00\00\00\00\00\00\80\ff\06\fe\07\00\00\00\00\f8y\80\00~\0e\00\00\00\00\00\fc\7f\03\00\00\00\00\00\00\00\00\00\00\7f\bf\00\00\fc\ff\ff\fcm\00\00\00\00\00\00\00~\b4\bf\00\00\00\00\00\00\00\00\00\a3\00\00\00\00\00\00\00\00\00\00\00\18\00\00\00\00\00\00\00\1f\00\00\00\00\00\00\00\7f\00\00\80\07\00\00\00\00\00\00\00\00`\00\00\00\00\00\00\00\00\a0\c3\07\f8\e7\0f\00\00\00<\00\00\1c\00\00\00\00\00\00\00\ff\ff\ff\ff\ff\ff\7f\f8\ff\ff\ff\ff\ff\1f \00\10\00\00\f8\fe\ff\00\00\7f\ff\ff\f9\db\07\00\00\00\00\7f\00\00\00\00\00\f0\07\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\ff\00\00begin <= end ( <= ) when slicing ` is out of bounds of `falsetrueBorrowErrorBorrowMutError    \00\00\1d\00\00\00\0c\00\00\00\04\00\00\00\1e\00\00\00\1f\00\00\00 \00\00\00,\0a\00\00!\00\00\00\04\00\00\00\04\00\00\00\22\00\00\00#\00\00\00$\00\00\00(\0a()Erroralready borrowed[ink_core::sync_cell::CacheEntry::get_mut] Error: tried to get the value from a desync cache\00\00\00\c4\18\01\00i\00\00\00\c8\00\00\00\11\00\00\00/home/sunrisevizag01/.cargo/git/checkouts/ink-1add513eda8f5a89/22c4b2d/core/src/storage/cell/sync_cell.rsalready mutably borrowed[ink_core::sync_cell::CacheEntry::get] Error: tried to get the value from a desync cache\00\00\00\c4\18\01\00i\00\00\00\b7\00\00\00\11\00\00\00\c0\19\01\00\5c\00\00\00\cc\01\00\00\19\00\00\00/home/sunrisevizag01/.cargo/git/checkouts/ink-1add513eda8f5a89/22c4b2d/model/src/contract.rs4\1a\01\00+\00\00\00_\1a\01\00\15\00\00\00[\01\00\00\15\00\00\00called `Option::unwrap()` on a `None` valuesrc/libcore/option.rs")
  (data (i32.const 72312) "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"))
