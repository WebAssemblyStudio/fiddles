(module
  (type (;0;) (func (param i32 i32)))
  (type (;1;) (func (result i64)))
  (type (;2;) (func (param i64 i32 i32 i32 i32) (result i32)))
  (type (;3;) (func))
  (type (;4;) (func (param i32)))
  (type (;5;) (func (param i64 i64) (result i64)))
  (type (;6;) (func (param i64 i64 i64) (result i64)))
  (type (;7;) (func (param i64 i64 i64 i64 i64 i64 i64)))
  (type (;8;) (func (param i32) (result i64)))
  (import "ethereum" "getExternalBalance" (func (;0;) (type 0)))
  (import "ethereum" "getGasLeft" (func (;1;) (type 1)))
  (import "ethereum" "call" (func (;2;) (type 2)))
  (import "ethereum" "revert" (func (;3;) (type 0)))
  (func (;4;) (type 3))
  (func (;5;) (type 3))
  (func (;6;) (type 4) (param i32)
    local.get 0
    i64.const 0
    i64.store offset=8
    local.get 0
    i64.const 1
    i64.store
    local.get 0
    i64.const 0
    i64.store32 offset=16)
  (func (;7;) (type 4) (param i32)
    (local i32)
    global.get 0
    i32.const 32
    i32.sub
    local.tee 1
    global.set 0
    local.get 1
    i32.const 8
    i32.add
    call 6
    local.get 0
    local.get 1
    i32.const 16
    i32.add
    i64.load
    i64.store offset=8
    local.get 0
    local.get 1
    i64.load offset=8
    i64.store
    local.get 0
    local.get 1
    i32.const 24
    i32.add
    i64.load32_u
    i64.store32 offset=16
    local.get 1
    i32.const 32
    i32.add
    global.set 0)
  (func (;8;) (type 5) (param i64 i64) (result i64)
    (local i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 2
    i64.const 0
    i64.store
    local.get 2
    i64.const 1
    i64.store offset=8
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i64.load
        local.get 1
        i64.ge_s
        br_if 1 (;@1;)
        local.get 2
        local.get 2
        i64.load offset=8
        local.get 0
        i64.mul
        i64.store offset=8
        local.get 2
        local.get 2
        i64.load
        i64.const 1
        i64.add
        i64.store
        br 0 (;@2;)
      end
    end
    local.get 2
    i64.load offset=8)
  (func (;9;) (type 6) (param i64 i64 i64) (result i64)
    (local i32)
    global.get 0
    i32.const 48
    i32.sub
    local.tee 3
    global.set 0
    local.get 3
    local.get 1
    i64.store offset=32
    local.get 3
    local.get 0
    i64.store offset=24
    local.get 3
    local.get 2
    i64.store32 offset=40
    local.get 3
    i32.const 24
    i32.add
    local.get 3
    i32.const 8
    i32.add
    call 0
    local.get 3
    i64.load offset=8
    local.set 2
    local.get 3
    i32.const 48
    i32.add
    global.set 0
    local.get 2)
  (func (;10;) (type 7) (param i64 i64 i64 i64 i64 i64 i64)
    (local i32 i64 i32)
    global.get 0
    i32.const 48
    i32.sub
    local.tee 7
    global.set 0
    call 1
    local.set 8
    local.get 7
    local.tee 9
    local.get 4
    i64.store offset=32
    local.get 9
    local.get 3
    i64.store offset=24
    local.get 9
    local.get 5
    i64.store32 offset=40
    local.get 9
    i64.const 0
    i64.store
    local.get 9
    local.get 6
    i64.store offset=8
    local.get 9
    local.get 6
    i64.const 63
    i64.shr_s
    i64.store offset=16
    block  ;; label = @1
      local.get 8
      local.get 9
      i32.const 24
      i32.add
      local.get 9
      i32.const 8
      i32.add
      local.get 9
      i32.const 0
      call 2
      br_if 0 (;@1;)
      local.get 9
      i32.const 48
      i32.add
      global.set 0
      return
    end
    local.get 7
    i32.const -16
    i32.add
    local.tee 9
    global.set 0
    local.get 9
    i32.const 0
    i32.store
    local.get 9
    i32.const 0
    call 3
    unreachable)
  (func (;11;) (type 4) (param i32))
  (func (;12;) (type 6) (param i64 i64 i64) (result i64)
    local.get 0
    local.get 1
    local.get 2
    call 9)
  (func (;13;) (type 7) (param i64 i64 i64 i64 i64 i64 i64)
    local.get 0
    local.get 1
    local.get 2
    local.get 3
    local.get 4
    local.get 5
    local.get 6
    call 10)
  (func (;14;) (type 3)
    i32.const 0
    i64.const 0
    i64.store offset=1024)
  (func (;15;) (type 8) (param i32) (result i64)
    local.get 0
    i64.load)
  (func (;16;) (type 1) (result i64)
    i32.const 1024
    call 15)
  (func (;17;) (type 4) (param i32)
    local.get 0
    local.get 0
    i64.load
    i64.const 1
    i64.add
    i64.store)
  (func (;18;) (type 3)
    i32.const 1024
    call 17)
  (func (;19;) (type 4) (param i32)
    local.get 0
    local.get 0
    i64.load
    i64.const -1
    i64.add
    i64.store)
  (func (;20;) (type 3)
    i32.const 1024
    call 19)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 2)
  (global (;0;) (mut i32) (i32.const 66576))
  (global (;1;) i32 (i32.const 1024))
  (global (;2;) i32 (i32.const 1024))
  (global (;3;) i32 (i32.const 1032))
  (global (;4;) i32 (i32.const 1024))
  (global (;5;) i32 (i32.const 66576))
  (global (;6;) i32 (i32.const 0))
  (global (;7;) i32 (i32.const 1))
  (export "memory" (memory 0))
  (export "main" (func 5))
)