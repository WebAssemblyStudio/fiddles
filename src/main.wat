(module
  (type $t0 (func))
  (type $t1 (func (param i32 i32 i32 f64 f64 f64)))
  (func $__wasm_call_ctors (export "__wasm_call_ctors") (type $t0))
  (func $mandelbrot (export "mandelbrot") (type $t1) (param $p0 i32) (param $p1 i32) (param $p2 i32) (param $p3 f64) (param $p4 f64) (param $p5 f64)
    (local $l0 f64) (local $l1 f64) (local $l2 f64) (local $l3 f64) (local $l4 f64) (local $l5 f64) (local $l6 f64) (local $l7 f64) (local $l8 f64) (local $l9 f64)
    block $B0
      get_local $p2
      i32.const 1
      i32.lt_s
      br_if $B0
      get_local $p1
      i32.const 1
      i32.lt_s
      br_if $B0
      get_local $p3
      f64.const 0x1.8p+1 (;=3;)
      f64.div
      set_local $l0
      get_local $p1
      f64.convert_s/i32
      set_local $l1
      get_local $p2
      f64.convert_s/i32
      set_local $l2
      f64.const 0x0p+0 (;=0;)
      set_local $l3
      i32.const 0
      set_local $p1
      loop $L1
        get_local $l3
        get_local $l2
        f64.div
        f64.const -0x1p-1 (;=-0.5;)
        f64.add
        get_local $l0
        f64.div
        get_local $p5
        f64.sub
        set_local $l4
        f64.const 0x0p+0 (;=0;)
        set_local $l5
        loop $L2
          get_local $l5
          get_local $l1
          f64.div
          f64.const -0x1p-1 (;=-0.5;)
          f64.add
          get_local $l0
          f64.div
          get_local $p4
          f64.add
          set_local $l6
          i32.const 1
          set_local $p2
          f64.const 0x0p+0 (;=0;)
          set_local $p3
          f64.const 0x0p+0 (;=0;)
          set_local $l7
          loop $L3
            get_local $l7
            get_local $l7
            f64.mul
            set_local $l8
            get_local $l4
            get_local $l7
            get_local $p3
            get_local $p3
            f64.add
            f64.mul
            f64.add
            tee_local $l9
            set_local $l7
            i32.const 1000000
            get_local $p2
            i32.const 1
            i32.add
            get_local $l6
            get_local $p3
            get_local $p3
            f64.mul
            get_local $l8
            f64.sub
            f64.add
            tee_local $p3
            get_local $p3
            f64.mul
            get_local $l9
            get_local $l9
            f64.mul
            f64.add
            f64.const 0x1p+2 (;=4;)
            f64.gt
            select
            tee_local $p2
            i32.const 100
            i32.lt_u
            br_if $L3
          end
          get_local $p0
          get_local $p1
          i32.const 2
          i32.shl
          i32.add
          i32.const -65536
          i32.const -65281
          get_local $p2
          i32.const 10000
          i32.lt_u
          select
          i32.store
          get_local $p1
          i32.const 1
          i32.add
          set_local $p1
          get_local $l5
          f64.const 0x1p+0 (;=1;)
          f64.add
          tee_local $l5
          get_local $l1
          f64.lt
          br_if $L2
        end
        get_local $l3
        f64.const 0x1p+0 (;=1;)
        f64.add
        tee_local $l3
        get_local $l2
        f64.lt
        br_if $L1
      end
    end)
  (memory $memory (export "memory") 100)
  (global $g0 (mut i32) (i32.const 66560))
  (global $__dso_handle (export "__dso_handle") i32 (i32.const 1024))
  (global $__data_end (export "__data_end") i32 (i32.const 1024))
  (global $__global_base (export "__global_base") i32 (i32.const 1024))
  (global $__heap_base (export "__heap_base") i32 (i32.const 66560))
  (global $__memory_base (export "__memory_base") i32 (i32.const 0))
  (global $__table_base (export "__table_base") i32 (i32.const 1)))
