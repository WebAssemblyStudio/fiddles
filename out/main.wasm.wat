(module
  (type $t0 (func (result i32)))
  (func $f0 (type $t0) (result i32)
    block $B0
      i32.const 33
      drop
      i32.const 1
      br_if $B0
    end
    block $B1 (result i32)
      i32.const 42
      i32.const 1
      br_if $B1
      drop
      i32.const 11
    end
    return))
