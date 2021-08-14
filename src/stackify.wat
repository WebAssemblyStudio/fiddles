(module
  (func $random (import "imports" "random") (result f32))
  (func $throwNeedle (param $rep i32) (result i32)
    (local $c i32)
    (local $i i32)
    (local $x f32)
    block $B0
      loop $L1
        call $random
        set_local $x
        get_local $x
        get_local $x
        f32.mul
        call $random
        set_local $x
        get_local $x
        get_local $x
        f32.mul
        f32.add
        f32.const 1
        f32.le
        if
          get_local $c
          i32.const 1
          i32.add
          set_local $c
        end
        get_local $i
        i32.const 1
        i32.add
        set_local $i
        get_local $i
        get_local $rep
        i32.ge_u
        br_if $B0
        br $L1
      end
    end
    get_local $c
    return
  )
  (export "throwNeedle" (func $throwNeedle))
)