(module
  (type (;0;) (func (param i32 i32 i32) (result i32)))
  (type (;1;) (func (param i32 i64 i32) (result i64)))
  (type (;2;) (func (param i32)))
  (type (;3;) (func (param i32 i32) (result i32)))
  (type (;4;) (func (param i32) (result i32)))
  (type (;5;) (func (result i32)))
  (type (;6;) (func (param i32 i64 i32 i32) (result i32)))
  (type (;7;) (func (param i32 i32 i32 i32) (result i32)))
  (type (;8;) (func))
  (type (;9;) (func (param i32 i32 i32 i32 i32) (result i32)))
  (type (;10;) (func (param i32 i32 i32)))
  (type (;11;) (func (param f64 i32) (result f64)))
  (import "wasi_snapshot_preview1" "proc_exit" (func $__wasi_proc_exit (type 2)))
  (import "env" "op1" (func $op1 (type 3)))
  (import "env" "op2" (func $op2 (type 3)))
  (import "env" "op4" (func $op4 (type 4)))
  (import "env" "op3" (func $op3 (type 3)))
  (import "env" "op0" (func $op0 (type 5)))
  (import "wasi_snapshot_preview1" "args_sizes_get" (func $__wasi_args_sizes_get (type 3)))
  (import "wasi_snapshot_preview1" "args_get" (func $__wasi_args_get (type 3)))
  (import "wasi_snapshot_preview1" "fd_seek" (func $__wasi_fd_seek (type 6)))
  (import "wasi_snapshot_preview1" "fd_close" (func $__wasi_fd_close (type 4)))
  (import "wasi_snapshot_preview1" "fd_fdstat_get" (func $__wasi_fd_fdstat_get (type 3)))
  (import "wasi_snapshot_preview1" "fd_read" (func $__wasi_fd_read (type 7)))
  (import "wasi_snapshot_preview1" "fd_write" (func $__wasi_fd_write (type 7)))
  (func $__wasm_call_ctors (type 8))
  (func $_start (type 8)
    (local i32)
    call $__wasm_call_ctors
    call $__original_main
    local.set 0
    call $__prepare_for_exit
    block  ;; label = @1
      local.get 0
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      call $__wasi_proc_exit
      unreachable
    end)
  (func $fnv1a32 (type 3) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    i32.const 0
    local.set 5
    i32.const -2128831035
    local.set 6
    local.get 4
    local.get 0
    i32.store offset=12
    local.get 4
    local.get 1
    i32.store offset=8
    local.get 4
    local.get 6
    i32.store offset=4
    local.get 4
    local.get 5
    i32.store
    block  ;; label = @1
      loop  ;; label = @2
        local.get 4
        i32.load
        local.set 7
        local.get 4
        i32.load offset=8
        local.set 8
        local.get 7
        local.set 9
        local.get 8
        local.set 10
        local.get 9
        local.get 10
        i32.lt_u
        local.set 11
        i32.const 1
        local.set 12
        local.get 11
        local.get 12
        i32.and
        local.set 13
        local.get 13
        i32.eqz
        br_if 1 (;@1;)
        local.get 4
        i32.load offset=4
        local.set 14
        local.get 4
        i32.load offset=12
        local.set 15
        local.get 4
        i32.load
        local.set 16
        local.get 15
        local.get 16
        i32.add
        local.set 17
        local.get 17
        i32.load8_u
        local.set 18
        i32.const 24
        local.set 19
        local.get 18
        local.get 19
        i32.shl
        local.set 20
        local.get 20
        local.get 19
        i32.shr_s
        local.set 21
        local.get 14
        local.get 21
        i32.xor
        local.set 22
        local.get 4
        local.get 22
        i32.store offset=4
        local.get 4
        i32.load offset=4
        local.set 23
        i32.const 16777619
        local.set 24
        local.get 23
        local.get 24
        i32.mul
        local.set 25
        local.get 4
        local.get 25
        i32.store offset=4
        local.get 4
        i32.load
        local.set 26
        i32.const 1
        local.set 27
        local.get 26
        local.get 27
        i32.add
        local.set 28
        local.get 4
        local.get 28
        i32.store
        br 0 (;@2;)
      end
    end
    local.get 4
    i32.load offset=4
    local.set 29
    local.get 29
    return)
  (func $calculate_hash (type 4) (param i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i64 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 1
    i32.const 48
    local.set 2
    local.get 1
    local.get 2
    i32.sub
    local.set 3
    local.get 3
    global.set 0
    i32.const 0
    local.set 4
    i32.const 32
    local.set 5
    local.get 3
    local.get 0
    i32.store offset=40
    local.get 5
    call $malloc
    local.set 6
    local.get 3
    local.get 6
    i32.store offset=16
    local.get 3
    i32.load offset=16
    local.set 7
    local.get 7
    local.set 8
    local.get 4
    local.set 9
    local.get 8
    local.get 9
    i32.ne
    local.set 10
    i32.const 1
    local.set 11
    local.get 10
    local.get 11
    i32.and
    local.set 12
    block  ;; label = @1
      block  ;; label = @2
        local.get 12
        br_if 0 (;@2;)
        i32.const 1024
        local.set 13
        i32.const 0
        local.set 14
        local.get 13
        local.get 14
        call $printf
        drop
        i32.const 0
        local.set 15
        local.get 3
        local.get 15
        i32.store offset=44
        br 1 (;@1;)
      end
      i32.const 0
      local.set 16
      local.get 3
      i32.load offset=16
      local.set 17
      i64.const 0
      local.set 18
      local.get 17
      local.get 18
      i64.store align=1
      i32.const 24
      local.set 19
      local.get 17
      local.get 19
      i32.add
      local.set 20
      local.get 20
      local.get 18
      i64.store align=1
      i32.const 16
      local.set 21
      local.get 17
      local.get 21
      i32.add
      local.set 22
      local.get 22
      local.get 18
      i64.store align=1
      i32.const 8
      local.set 23
      local.get 17
      local.get 23
      i32.add
      local.set 24
      local.get 24
      local.get 18
      i64.store align=1
      local.get 3
      local.get 16
      i32.store offset=20
      block  ;; label = @2
        loop  ;; label = @3
          i32.const 32
          local.set 25
          local.get 3
          i32.load offset=20
          local.set 26
          local.get 26
          local.set 27
          local.get 25
          local.set 28
          local.get 27
          local.get 28
          i32.lt_u
          local.set 29
          i32.const 1
          local.set 30
          local.get 29
          local.get 30
          i32.and
          local.set 31
          local.get 31
          i32.eqz
          br_if 1 (;@2;)
          local.get 3
          i32.load offset=20
          local.set 32
          i32.const 31
          local.set 33
          local.get 32
          local.get 33
          i32.and
          local.set 34
          i32.const 3568
          local.set 35
          local.get 34
          local.get 35
          i32.add
          local.set 36
          local.get 36
          i32.load8_u
          local.set 37
          local.get 3
          local.get 37
          i32.store8 offset=14
          local.get 3
          i32.load offset=40
          local.set 38
          local.get 3
          i32.load offset=20
          local.set 39
          local.get 38
          local.get 39
          i32.add
          local.set 40
          local.get 40
          i32.load8_u
          local.set 41
          local.get 3
          local.get 41
          i32.store8 offset=15
          local.get 3
          i32.load8_u offset=14
          local.set 42
          i32.const -65
          local.set 43
          local.get 42
          local.get 43
          i32.add
          local.set 44
          i32.const 22
          local.set 45
          local.get 44
          local.get 45
          i32.gt_u
          local.set 46
          block  ;; label = @4
            local.get 46
            br_if 0 (;@4;)
            block  ;; label = @5
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    local.get 44
                    br_table 1 (;@7;) 4 (;@4;) 4 (;@4;) 3 (;@5;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 2 (;@6;) 4 (;@4;) 4 (;@4;) 4 (;@4;) 0 (;@8;) 1 (;@7;)
                  end
                  local.get 3
                  i32.load8_u offset=15
                  local.set 47
                  i32.const 255
                  local.set 48
                  local.get 47
                  local.get 48
                  i32.and
                  local.set 49
                  local.get 3
                  i32.load offset=20
                  local.set 50
                  i32.const 3
                  local.set 51
                  local.get 50
                  local.get 51
                  i32.and
                  local.set 52
                  i32.const 0
                  local.set 53
                  local.get 52
                  local.get 53
                  i32.shr_u
                  local.set 54
                  local.get 54
                  i32.load8_u offset=3552
                  local.set 55
                  i32.const 24
                  local.set 56
                  local.get 55
                  local.get 56
                  i32.shl
                  local.set 57
                  local.get 57
                  local.get 56
                  i32.shr_s
                  local.set 58
                  local.get 3
                  i32.load offset=20
                  local.set 59
                  local.get 58
                  local.get 59
                  i32.add
                  local.set 60
                  local.get 49
                  local.get 60
                  call $op1
                  local.set 61
                  local.get 3
                  i32.load offset=16
                  local.set 62
                  local.get 3
                  i32.load offset=20
                  local.set 63
                  local.get 62
                  local.get 63
                  i32.add
                  local.set 64
                  local.get 64
                  local.get 61
                  i32.store8
                  br 3 (;@4;)
                end
                local.get 3
                i32.load8_u offset=15
                local.set 65
                i32.const 255
                local.set 66
                local.get 65
                local.get 66
                i32.and
                local.set 67
                local.get 3
                i32.load offset=20
                local.set 68
                i32.const 7
                local.set 69
                local.get 68
                local.get 69
                i32.and
                local.set 70
                local.get 67
                local.get 70
                call $op2
                local.set 71
                local.get 3
                i32.load offset=16
                local.set 72
                local.get 3
                i32.load offset=20
                local.set 73
                local.get 72
                local.get 73
                i32.add
                local.set 74
                local.get 74
                local.get 71
                i32.store8
                br 2 (;@4;)
              end
              local.get 3
              i32.load8_u offset=15
              local.set 75
              i32.const 255
              local.set 76
              local.get 75
              local.get 76
              i32.and
              local.set 77
              local.get 77
              call $op4
              local.set 78
              local.get 3
              i32.load offset=16
              local.set 79
              local.get 3
              i32.load offset=20
              local.set 80
              local.get 79
              local.get 80
              i32.add
              local.set 81
              local.get 81
              local.get 78
              i32.store8
              br 1 (;@4;)
            end
            local.get 3
            i32.load8_u offset=15
            local.set 82
            i32.const 255
            local.set 83
            local.get 82
            local.get 83
            i32.and
            local.set 84
            local.get 3
            i32.load offset=20
            local.set 85
            i32.const 7
            local.set 86
            local.get 85
            local.get 86
            i32.and
            local.set 87
            local.get 84
            local.get 87
            call $op3
            local.set 88
            local.get 3
            i32.load offset=16
            local.set 89
            local.get 3
            i32.load offset=20
            local.set 90
            local.get 89
            local.get 90
            i32.add
            local.set 91
            local.get 91
            local.get 88
            i32.store8
          end
          local.get 3
          i32.load offset=20
          local.set 92
          i32.const 1
          local.set 93
          local.get 92
          local.get 93
          i32.add
          local.set 94
          local.get 3
          local.get 94
          i32.store offset=20
          br 0 (;@3;)
        end
      end
      i32.const 0
      local.set 95
      local.get 3
      local.get 95
      i32.store offset=20
      block  ;; label = @2
        loop  ;; label = @3
          i32.const 8
          local.set 96
          local.get 3
          i32.load offset=20
          local.set 97
          local.get 97
          local.set 98
          local.get 96
          local.set 99
          local.get 98
          local.get 99
          i32.lt_u
          local.set 100
          i32.const 1
          local.set 101
          local.get 100
          local.get 101
          i32.and
          local.set 102
          local.get 102
          i32.eqz
          br_if 1 (;@2;)
          i32.const 4
          local.set 103
          i32.const 36
          local.set 104
          local.get 3
          local.get 104
          i32.add
          local.set 105
          local.get 105
          local.set 106
          local.get 3
          i32.load offset=16
          local.set 107
          local.get 3
          i32.load offset=20
          local.set 108
          i32.const 2
          local.set 109
          local.get 108
          local.get 109
          i32.shl
          local.set 110
          local.get 107
          local.get 110
          i32.add
          local.set 111
          local.get 3
          local.get 111
          i32.store offset=24
          local.get 3
          i32.load offset=40
          local.set 112
          local.get 3
          i32.load offset=20
          local.set 113
          i32.const 2
          local.set 114
          local.get 113
          local.get 114
          i32.shl
          local.set 115
          local.get 112
          local.get 115
          i32.add
          local.set 116
          local.get 116
          i32.load
          local.set 117
          local.get 3
          local.get 117
          i32.store offset=36
          local.get 106
          local.get 103
          call $fnv1a32
          local.set 118
          local.get 3
          local.get 118
          i32.store offset=32
          local.get 3
          i32.load offset=24
          local.set 119
          local.get 119
          i32.load
          local.set 120
          local.get 3
          i32.load offset=32
          local.set 121
          local.get 120
          local.get 121
          i32.xor
          local.set 122
          local.get 3
          i32.load offset=24
          local.set 123
          local.get 123
          local.get 122
          i32.store
          local.get 3
          i32.load offset=20
          local.set 124
          i32.const 1
          local.set 125
          local.get 124
          local.get 125
          i32.add
          local.set 126
          local.get 3
          local.get 126
          i32.store offset=20
          br 0 (;@3;)
        end
      end
      local.get 3
      i32.load offset=16
      local.set 127
      local.get 3
      local.get 127
      i32.store offset=44
    end
    local.get 3
    i32.load offset=44
    local.set 128
    i32.const 48
    local.set 129
    local.get 3
    local.get 129
    i32.add
    local.set 130
    local.get 130
    global.set 0
    local.get 128
    return)
  (func $main (type 3) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 2
    i32.const 160
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    global.set 0
    i32.const 238
    local.set 5
    i32.const 0
    local.set 6
    local.get 4
    local.get 6
    i32.store offset=156
    local.get 4
    local.get 0
    i32.store offset=152
    local.get 4
    local.get 1
    i32.store offset=148
    local.get 4
    local.get 6
    i32.store offset=144
    call $op0
    local.set 7
    local.get 4
    local.get 7
    i32.store offset=12
    local.get 4
    i32.load offset=12
    local.set 8
    local.get 8
    local.set 9
    local.get 5
    local.set 10
    local.get 9
    local.get 10
    i32.ne
    local.set 11
    i32.const 1
    local.set 12
    local.get 11
    local.get 12
    i32.and
    local.set 13
    block  ;; label = @1
      block  ;; label = @2
        local.get 13
        i32.eqz
        br_if 0 (;@2;)
        i32.const 1040
        local.set 14
        i32.const 0
        local.set 15
        local.get 14
        local.get 15
        call $printf
        drop
        i32.const 0
        local.set 16
        local.get 4
        local.get 16
        i32.store offset=156
        br 1 (;@1;)
      end
      i32.const 1075
      local.set 17
      i32.const 0
      local.set 18
      local.get 17
      local.get 18
      call $printf
      drop
      i32.const 0
      local.set 19
      i32.const 33
      local.set 20
      i32.const 96
      local.set 21
      local.get 4
      local.get 21
      i32.add
      local.set 22
      local.get 22
      local.set 23
      i32.const 0
      local.set 24
      local.get 24
      i32.load offset=3544
      local.set 25
      local.get 23
      local.get 20
      local.get 25
      call $fgets
      local.set 26
      local.get 26
      local.set 27
      local.get 19
      local.set 28
      local.get 27
      local.get 28
      i32.eq
      local.set 29
      i32.const 1
      local.set 30
      local.get 29
      local.get 30
      i32.and
      local.set 31
      block  ;; label = @2
        local.get 31
        i32.eqz
        br_if 0 (;@2;)
        i32.const 1095
        local.set 32
        i32.const 0
        local.set 33
        local.get 32
        local.get 33
        call $printf
        drop
        i32.const 0
        local.set 34
        local.get 4
        local.get 34
        i32.store offset=156
        br 1 (;@1;)
      end
      i32.const 1
      local.set 35
      i32.const 96
      local.set 36
      local.get 4
      local.get 36
      i32.add
      local.set 37
      local.get 37
      local.set 38
      local.get 38
      call $strlen
      local.set 39
      local.get 39
      local.set 40
      local.get 35
      local.set 41
      local.get 40
      local.get 41
      i32.eq
      local.set 42
      i32.const 1
      local.set 43
      local.get 42
      local.get 43
      i32.and
      local.set 44
      block  ;; label = @2
        local.get 44
        i32.eqz
        br_if 0 (;@2;)
        i32.const 1116
        local.set 45
        i32.const 0
        local.set 46
        local.get 45
        local.get 46
        call $printf
        drop
        i32.const 0
        local.set 47
        local.get 4
        local.get 47
        i32.store offset=156
        br 1 (;@1;)
      end
      i32.const 13
      local.set 48
      i32.const 96
      local.set 49
      local.get 4
      local.get 49
      i32.add
      local.set 50
      local.get 50
      local.set 51
      local.get 51
      call $strlen
      local.set 52
      i32.const 1
      local.set 53
      local.get 52
      local.get 53
      i32.sub
      local.set 54
      local.get 51
      local.get 54
      i32.add
      local.set 55
      local.get 55
      i32.load8_u
      local.set 56
      local.get 4
      local.get 56
      i32.store8 offset=95
      local.get 4
      i32.load8_u offset=95
      local.set 57
      i32.const 24
      local.set 58
      local.get 57
      local.get 58
      i32.shl
      local.set 59
      local.get 59
      local.get 58
      i32.shr_s
      local.set 60
      local.get 60
      local.set 61
      local.get 48
      local.set 62
      local.get 61
      local.get 62
      i32.eq
      local.set 63
      i32.const 1
      local.set 64
      local.get 63
      local.get 64
      i32.and
      local.set 65
      block  ;; label = @2
        block  ;; label = @3
          local.get 65
          br_if 0 (;@3;)
          i32.const 10
          local.set 66
          local.get 4
          i32.load8_u offset=95
          local.set 67
          i32.const 24
          local.set 68
          local.get 67
          local.get 68
          i32.shl
          local.set 69
          local.get 69
          local.get 68
          i32.shr_s
          local.set 70
          local.get 70
          local.set 71
          local.get 66
          local.set 72
          local.get 71
          local.get 72
          i32.eq
          local.set 73
          i32.const 1
          local.set 74
          local.get 73
          local.get 74
          i32.and
          local.set 75
          local.get 75
          i32.eqz
          br_if 1 (;@2;)
        end
        i32.const 0
        local.set 76
        i32.const 96
        local.set 77
        local.get 4
        local.get 77
        i32.add
        local.set 78
        local.get 78
        local.set 79
        local.get 79
        call $strlen
        local.set 80
        i32.const 1
        local.set 81
        local.get 80
        local.get 81
        i32.sub
        local.set 82
        local.get 79
        local.get 82
        i32.add
        local.set 83
        local.get 83
        local.get 76
        i32.store8
      end
      i32.const 32
      local.set 84
      i32.const 96
      local.set 85
      local.get 4
      local.get 85
      i32.add
      local.set 86
      local.get 86
      local.set 87
      local.get 87
      call $strlen
      local.set 88
      local.get 88
      local.set 89
      local.get 84
      local.set 90
      local.get 89
      local.get 90
      i32.ne
      local.set 91
      i32.const 1
      local.set 92
      local.get 91
      local.get 92
      i32.and
      local.set 93
      block  ;; label = @2
        local.get 93
        i32.eqz
        br_if 0 (;@2;)
        i32.const 1130
        local.set 94
        i32.const 0
        local.set 95
        local.get 94
        local.get 95
        call $printf
        drop
        i32.const 0
        local.set 96
        local.get 4
        local.get 96
        i32.store offset=156
        br 1 (;@1;)
      end
      i32.const 96
      local.set 97
      local.get 4
      local.get 97
      i32.add
      local.set 98
      local.get 98
      local.set 99
      local.get 99
      call $calculate_hash
      local.set 100
      local.get 4
      local.get 100
      i32.store offset=88
      local.get 4
      i32.load offset=88
      local.set 101
      i32.const 3600
      local.set 102
      i32.const 32
      local.set 103
      local.get 101
      local.get 102
      local.get 103
      call $memcmp
      local.set 104
      block  ;; label = @2
        block  ;; label = @3
          local.get 104
          br_if 0 (;@3;)
          i32.const 1151
          local.set 105
          i32.const 0
          local.set 106
          local.get 105
          local.get 106
          call $printf
          drop
          br 1 (;@2;)
        end
        i32.const 1164
        local.set 107
        i32.const 0
        local.set 108
        local.get 107
        local.get 108
        call $printf
        drop
      end
      i32.const 0
      local.set 109
      local.get 4
      local.get 109
      i32.store offset=156
    end
    local.get 4
    i32.load offset=156
    local.set 110
    i32.const 160
    local.set 111
    local.get 4
    local.get 111
    i32.add
    local.set 112
    local.get 112
    global.set 0
    local.get 110
    return)
  (func $malloc (type 4) (param i32) (result i32)
    local.get 0
    call $dlmalloc)
  (func $dlmalloc (type 4) (param i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 1
    global.set 0
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    block  ;; label = @9
                      block  ;; label = @10
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 0
                            i32.const 236
                            i32.gt_u
                            br_if 0 (;@12;)
                            block  ;; label = @13
                              i32.const 0
                              i32.load offset=4000
                              local.tee 2
                              i32.const 16
                              local.get 0
                              i32.const 19
                              i32.add
                              i32.const -16
                              i32.and
                              local.get 0
                              i32.const 11
                              i32.lt_u
                              select
                              local.tee 3
                              i32.const 3
                              i32.shr_u
                              local.tee 4
                              i32.shr_u
                              local.tee 0
                              i32.const 3
                              i32.and
                              i32.eqz
                              br_if 0 (;@13;)
                              local.get 0
                              i32.const 1
                              i32.and
                              local.get 4
                              i32.or
                              i32.const 1
                              i32.xor
                              local.tee 3
                              i32.const 3
                              i32.shl
                              local.tee 5
                              i32.const 4048
                              i32.add
                              i32.load
                              local.tee 4
                              i32.const 8
                              i32.add
                              local.set 0
                              block  ;; label = @14
                                block  ;; label = @15
                                  local.get 4
                                  i32.load offset=8
                                  local.tee 6
                                  local.get 5
                                  i32.const 4040
                                  i32.add
                                  local.tee 5
                                  i32.ne
                                  br_if 0 (;@15;)
                                  i32.const 0
                                  local.get 2
                                  i32.const -2
                                  local.get 3
                                  i32.rotl
                                  i32.and
                                  i32.store offset=4000
                                  br 1 (;@14;)
                                end
                                i32.const 0
                                i32.load offset=4016
                                local.get 6
                                i32.gt_u
                                drop
                                local.get 5
                                local.get 6
                                i32.store offset=8
                                local.get 6
                                local.get 5
                                i32.store offset=12
                              end
                              local.get 4
                              local.get 3
                              i32.const 3
                              i32.shl
                              local.tee 6
                              i32.const 3
                              i32.or
                              i32.store offset=4
                              local.get 4
                              local.get 6
                              i32.add
                              local.tee 4
                              local.get 4
                              i32.load offset=4
                              i32.const 1
                              i32.or
                              i32.store offset=4
                              br 12 (;@1;)
                            end
                            local.get 3
                            i32.const 0
                            i32.load offset=4008
                            local.tee 7
                            i32.le_u
                            br_if 1 (;@11;)
                            block  ;; label = @13
                              local.get 0
                              i32.eqz
                              br_if 0 (;@13;)
                              block  ;; label = @14
                                block  ;; label = @15
                                  local.get 0
                                  local.get 4
                                  i32.shl
                                  i32.const 2
                                  local.get 4
                                  i32.shl
                                  local.tee 0
                                  i32.const 0
                                  local.get 0
                                  i32.sub
                                  i32.or
                                  i32.and
                                  local.tee 0
                                  i32.const 0
                                  local.get 0
                                  i32.sub
                                  i32.and
                                  i32.const -1
                                  i32.add
                                  local.tee 0
                                  local.get 0
                                  i32.const 12
                                  i32.shr_u
                                  i32.const 16
                                  i32.and
                                  local.tee 0
                                  i32.shr_u
                                  local.tee 4
                                  i32.const 5
                                  i32.shr_u
                                  i32.const 8
                                  i32.and
                                  local.tee 6
                                  local.get 0
                                  i32.or
                                  local.get 4
                                  local.get 6
                                  i32.shr_u
                                  local.tee 0
                                  i32.const 2
                                  i32.shr_u
                                  i32.const 4
                                  i32.and
                                  local.tee 4
                                  i32.or
                                  local.get 0
                                  local.get 4
                                  i32.shr_u
                                  local.tee 0
                                  i32.const 1
                                  i32.shr_u
                                  i32.const 2
                                  i32.and
                                  local.tee 4
                                  i32.or
                                  local.get 0
                                  local.get 4
                                  i32.shr_u
                                  local.tee 0
                                  i32.const 1
                                  i32.shr_u
                                  i32.const 1
                                  i32.and
                                  local.tee 4
                                  i32.or
                                  local.get 0
                                  local.get 4
                                  i32.shr_u
                                  i32.add
                                  local.tee 6
                                  i32.const 3
                                  i32.shl
                                  local.tee 5
                                  i32.const 4048
                                  i32.add
                                  i32.load
                                  local.tee 4
                                  i32.load offset=8
                                  local.tee 0
                                  local.get 5
                                  i32.const 4040
                                  i32.add
                                  local.tee 5
                                  i32.ne
                                  br_if 0 (;@15;)
                                  i32.const 0
                                  local.get 2
                                  i32.const -2
                                  local.get 6
                                  i32.rotl
                                  i32.and
                                  local.tee 2
                                  i32.store offset=4000
                                  br 1 (;@14;)
                                end
                                i32.const 0
                                i32.load offset=4016
                                local.get 0
                                i32.gt_u
                                drop
                                local.get 5
                                local.get 0
                                i32.store offset=8
                                local.get 0
                                local.get 5
                                i32.store offset=12
                              end
                              local.get 4
                              i32.const 8
                              i32.add
                              local.set 0
                              local.get 4
                              local.get 3
                              i32.const 3
                              i32.or
                              i32.store offset=4
                              local.get 4
                              local.get 6
                              i32.const 3
                              i32.shl
                              local.tee 6
                              i32.add
                              local.get 6
                              local.get 3
                              i32.sub
                              local.tee 6
                              i32.store
                              local.get 4
                              local.get 3
                              i32.add
                              local.tee 5
                              local.get 6
                              i32.const 1
                              i32.or
                              i32.store offset=4
                              block  ;; label = @14
                                local.get 7
                                i32.eqz
                                br_if 0 (;@14;)
                                local.get 7
                                i32.const 3
                                i32.shr_u
                                local.tee 8
                                i32.const 3
                                i32.shl
                                i32.const 4040
                                i32.add
                                local.set 3
                                i32.const 0
                                i32.load offset=4020
                                local.set 4
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 2
                                    i32.const 1
                                    local.get 8
                                    i32.shl
                                    local.tee 8
                                    i32.and
                                    br_if 0 (;@16;)
                                    i32.const 0
                                    local.get 2
                                    local.get 8
                                    i32.or
                                    i32.store offset=4000
                                    local.get 3
                                    local.set 8
                                    br 1 (;@15;)
                                  end
                                  local.get 3
                                  i32.load offset=8
                                  local.set 8
                                end
                                local.get 8
                                local.get 4
                                i32.store offset=12
                                local.get 3
                                local.get 4
                                i32.store offset=8
                                local.get 4
                                local.get 3
                                i32.store offset=12
                                local.get 4
                                local.get 8
                                i32.store offset=8
                              end
                              i32.const 0
                              local.get 5
                              i32.store offset=4020
                              i32.const 0
                              local.get 6
                              i32.store offset=4008
                              br 12 (;@1;)
                            end
                            i32.const 0
                            i32.load offset=4004
                            local.tee 9
                            i32.eqz
                            br_if 1 (;@11;)
                            local.get 9
                            i32.const 0
                            local.get 9
                            i32.sub
                            i32.and
                            i32.const -1
                            i32.add
                            local.tee 0
                            local.get 0
                            i32.const 12
                            i32.shr_u
                            i32.const 16
                            i32.and
                            local.tee 0
                            i32.shr_u
                            local.tee 4
                            i32.const 5
                            i32.shr_u
                            i32.const 8
                            i32.and
                            local.tee 6
                            local.get 0
                            i32.or
                            local.get 4
                            local.get 6
                            i32.shr_u
                            local.tee 0
                            i32.const 2
                            i32.shr_u
                            i32.const 4
                            i32.and
                            local.tee 4
                            i32.or
                            local.get 0
                            local.get 4
                            i32.shr_u
                            local.tee 0
                            i32.const 1
                            i32.shr_u
                            i32.const 2
                            i32.and
                            local.tee 4
                            i32.or
                            local.get 0
                            local.get 4
                            i32.shr_u
                            local.tee 0
                            i32.const 1
                            i32.shr_u
                            i32.const 1
                            i32.and
                            local.tee 4
                            i32.or
                            local.get 0
                            local.get 4
                            i32.shr_u
                            i32.add
                            i32.const 2
                            i32.shl
                            i32.const 4304
                            i32.add
                            i32.load
                            local.tee 5
                            i32.load offset=4
                            i32.const -8
                            i32.and
                            local.get 3
                            i32.sub
                            local.set 4
                            local.get 5
                            local.set 6
                            block  ;; label = @13
                              loop  ;; label = @14
                                block  ;; label = @15
                                  local.get 6
                                  i32.load offset=16
                                  local.tee 0
                                  br_if 0 (;@15;)
                                  local.get 6
                                  i32.const 20
                                  i32.add
                                  i32.load
                                  local.tee 0
                                  i32.eqz
                                  br_if 2 (;@13;)
                                end
                                local.get 0
                                i32.load offset=4
                                i32.const -8
                                i32.and
                                local.get 3
                                i32.sub
                                local.tee 6
                                local.get 4
                                local.get 6
                                local.get 4
                                i32.lt_u
                                local.tee 6
                                select
                                local.set 4
                                local.get 0
                                local.get 5
                                local.get 6
                                select
                                local.set 5
                                local.get 0
                                local.set 6
                                br 0 (;@14;)
                              end
                            end
                            local.get 5
                            i32.load offset=24
                            local.set 10
                            block  ;; label = @13
                              local.get 5
                              i32.load offset=12
                              local.tee 8
                              local.get 5
                              i32.eq
                              br_if 0 (;@13;)
                              block  ;; label = @14
                                i32.const 0
                                i32.load offset=4016
                                local.get 5
                                i32.load offset=8
                                local.tee 0
                                i32.gt_u
                                br_if 0 (;@14;)
                                local.get 0
                                i32.load offset=12
                                local.get 5
                                i32.ne
                                drop
                              end
                              local.get 8
                              local.get 0
                              i32.store offset=8
                              local.get 0
                              local.get 8
                              i32.store offset=12
                              br 11 (;@2;)
                            end
                            block  ;; label = @13
                              local.get 5
                              i32.const 20
                              i32.add
                              local.tee 6
                              i32.load
                              local.tee 0
                              br_if 0 (;@13;)
                              local.get 5
                              i32.load offset=16
                              local.tee 0
                              i32.eqz
                              br_if 3 (;@10;)
                              local.get 5
                              i32.const 16
                              i32.add
                              local.set 6
                            end
                            loop  ;; label = @13
                              local.get 6
                              local.set 11
                              local.get 0
                              local.tee 8
                              i32.const 20
                              i32.add
                              local.tee 6
                              i32.load
                              local.tee 0
                              br_if 0 (;@13;)
                              local.get 8
                              i32.const 16
                              i32.add
                              local.set 6
                              local.get 8
                              i32.load offset=16
                              local.tee 0
                              br_if 0 (;@13;)
                            end
                            local.get 11
                            i32.const 0
                            i32.store
                            br 10 (;@2;)
                          end
                          i32.const -1
                          local.set 3
                          local.get 0
                          i32.const -65
                          i32.gt_u
                          br_if 0 (;@11;)
                          local.get 0
                          i32.const 19
                          i32.add
                          local.tee 0
                          i32.const -16
                          i32.and
                          local.set 3
                          i32.const 0
                          i32.load offset=4004
                          local.tee 7
                          i32.eqz
                          br_if 0 (;@11;)
                          i32.const 0
                          local.set 11
                          block  ;; label = @12
                            local.get 0
                            i32.const 8
                            i32.shr_u
                            local.tee 0
                            i32.eqz
                            br_if 0 (;@12;)
                            i32.const 31
                            local.set 11
                            local.get 3
                            i32.const 16777215
                            i32.gt_u
                            br_if 0 (;@12;)
                            local.get 0
                            local.get 0
                            i32.const 1048320
                            i32.add
                            i32.const 16
                            i32.shr_u
                            i32.const 8
                            i32.and
                            local.tee 4
                            i32.shl
                            local.tee 0
                            local.get 0
                            i32.const 520192
                            i32.add
                            i32.const 16
                            i32.shr_u
                            i32.const 4
                            i32.and
                            local.tee 0
                            i32.shl
                            local.tee 6
                            local.get 6
                            i32.const 245760
                            i32.add
                            i32.const 16
                            i32.shr_u
                            i32.const 2
                            i32.and
                            local.tee 6
                            i32.shl
                            i32.const 15
                            i32.shr_u
                            local.get 0
                            local.get 4
                            i32.or
                            local.get 6
                            i32.or
                            i32.sub
                            local.tee 0
                            i32.const 1
                            i32.shl
                            local.get 3
                            local.get 0
                            i32.const 21
                            i32.add
                            i32.shr_u
                            i32.const 1
                            i32.and
                            i32.or
                            i32.const 28
                            i32.add
                            local.set 11
                          end
                          i32.const 0
                          local.get 3
                          i32.sub
                          local.set 6
                          block  ;; label = @12
                            block  ;; label = @13
                              block  ;; label = @14
                                block  ;; label = @15
                                  local.get 11
                                  i32.const 2
                                  i32.shl
                                  i32.const 4304
                                  i32.add
                                  i32.load
                                  local.tee 4
                                  br_if 0 (;@15;)
                                  i32.const 0
                                  local.set 0
                                  i32.const 0
                                  local.set 8
                                  br 1 (;@14;)
                                end
                                local.get 3
                                i32.const 0
                                i32.const 25
                                local.get 11
                                i32.const 1
                                i32.shr_u
                                i32.sub
                                local.get 11
                                i32.const 31
                                i32.eq
                                select
                                i32.shl
                                local.set 5
                                i32.const 0
                                local.set 0
                                i32.const 0
                                local.set 8
                                loop  ;; label = @15
                                  block  ;; label = @16
                                    local.get 4
                                    i32.load offset=4
                                    i32.const -8
                                    i32.and
                                    local.get 3
                                    i32.sub
                                    local.tee 2
                                    local.get 6
                                    i32.ge_u
                                    br_if 0 (;@16;)
                                    local.get 2
                                    local.set 6
                                    local.get 4
                                    local.set 8
                                    local.get 2
                                    br_if 0 (;@16;)
                                    i32.const 0
                                    local.set 6
                                    local.get 4
                                    local.set 8
                                    local.get 4
                                    local.set 0
                                    br 3 (;@13;)
                                  end
                                  local.get 0
                                  local.get 4
                                  i32.const 20
                                  i32.add
                                  i32.load
                                  local.tee 2
                                  local.get 2
                                  local.get 4
                                  local.get 5
                                  i32.const 29
                                  i32.shr_u
                                  i32.const 4
                                  i32.and
                                  i32.add
                                  i32.const 16
                                  i32.add
                                  i32.load
                                  local.tee 4
                                  i32.eq
                                  select
                                  local.get 0
                                  local.get 2
                                  select
                                  local.set 0
                                  local.get 5
                                  local.get 4
                                  i32.const 0
                                  i32.ne
                                  i32.shl
                                  local.set 5
                                  local.get 4
                                  br_if 0 (;@15;)
                                end
                              end
                              block  ;; label = @14
                                local.get 0
                                local.get 8
                                i32.or
                                br_if 0 (;@14;)
                                i32.const 2
                                local.get 11
                                i32.shl
                                local.tee 0
                                i32.const 0
                                local.get 0
                                i32.sub
                                i32.or
                                local.get 7
                                i32.and
                                local.tee 0
                                i32.eqz
                                br_if 3 (;@11;)
                                local.get 0
                                i32.const 0
                                local.get 0
                                i32.sub
                                i32.and
                                i32.const -1
                                i32.add
                                local.tee 0
                                local.get 0
                                i32.const 12
                                i32.shr_u
                                i32.const 16
                                i32.and
                                local.tee 0
                                i32.shr_u
                                local.tee 4
                                i32.const 5
                                i32.shr_u
                                i32.const 8
                                i32.and
                                local.tee 5
                                local.get 0
                                i32.or
                                local.get 4
                                local.get 5
                                i32.shr_u
                                local.tee 0
                                i32.const 2
                                i32.shr_u
                                i32.const 4
                                i32.and
                                local.tee 4
                                i32.or
                                local.get 0
                                local.get 4
                                i32.shr_u
                                local.tee 0
                                i32.const 1
                                i32.shr_u
                                i32.const 2
                                i32.and
                                local.tee 4
                                i32.or
                                local.get 0
                                local.get 4
                                i32.shr_u
                                local.tee 0
                                i32.const 1
                                i32.shr_u
                                i32.const 1
                                i32.and
                                local.tee 4
                                i32.or
                                local.get 0
                                local.get 4
                                i32.shr_u
                                i32.add
                                i32.const 2
                                i32.shl
                                i32.const 4304
                                i32.add
                                i32.load
                                local.set 0
                              end
                              local.get 0
                              i32.eqz
                              br_if 1 (;@12;)
                            end
                            loop  ;; label = @13
                              local.get 0
                              i32.load offset=4
                              i32.const -8
                              i32.and
                              local.get 3
                              i32.sub
                              local.tee 2
                              local.get 6
                              i32.lt_u
                              local.set 5
                              block  ;; label = @14
                                local.get 0
                                i32.load offset=16
                                local.tee 4
                                br_if 0 (;@14;)
                                local.get 0
                                i32.const 20
                                i32.add
                                i32.load
                                local.set 4
                              end
                              local.get 2
                              local.get 6
                              local.get 5
                              select
                              local.set 6
                              local.get 0
                              local.get 8
                              local.get 5
                              select
                              local.set 8
                              local.get 4
                              local.set 0
                              local.get 4
                              br_if 0 (;@13;)
                            end
                          end
                          local.get 8
                          i32.eqz
                          br_if 0 (;@11;)
                          local.get 6
                          i32.const 0
                          i32.load offset=4008
                          local.get 3
                          i32.sub
                          i32.ge_u
                          br_if 0 (;@11;)
                          local.get 8
                          i32.load offset=24
                          local.set 11
                          block  ;; label = @12
                            local.get 8
                            i32.load offset=12
                            local.tee 5
                            local.get 8
                            i32.eq
                            br_if 0 (;@12;)
                            block  ;; label = @13
                              i32.const 0
                              i32.load offset=4016
                              local.get 8
                              i32.load offset=8
                              local.tee 0
                              i32.gt_u
                              br_if 0 (;@13;)
                              local.get 0
                              i32.load offset=12
                              local.get 8
                              i32.ne
                              drop
                            end
                            local.get 5
                            local.get 0
                            i32.store offset=8
                            local.get 0
                            local.get 5
                            i32.store offset=12
                            br 9 (;@3;)
                          end
                          block  ;; label = @12
                            local.get 8
                            i32.const 20
                            i32.add
                            local.tee 4
                            i32.load
                            local.tee 0
                            br_if 0 (;@12;)
                            local.get 8
                            i32.load offset=16
                            local.tee 0
                            i32.eqz
                            br_if 3 (;@9;)
                            local.get 8
                            i32.const 16
                            i32.add
                            local.set 4
                          end
                          loop  ;; label = @12
                            local.get 4
                            local.set 2
                            local.get 0
                            local.tee 5
                            i32.const 20
                            i32.add
                            local.tee 4
                            i32.load
                            local.tee 0
                            br_if 0 (;@12;)
                            local.get 5
                            i32.const 16
                            i32.add
                            local.set 4
                            local.get 5
                            i32.load offset=16
                            local.tee 0
                            br_if 0 (;@12;)
                          end
                          local.get 2
                          i32.const 0
                          i32.store
                          br 8 (;@3;)
                        end
                        block  ;; label = @11
                          i32.const 0
                          i32.load offset=4008
                          local.tee 0
                          local.get 3
                          i32.lt_u
                          br_if 0 (;@11;)
                          i32.const 0
                          i32.load offset=4020
                          local.set 4
                          block  ;; label = @12
                            block  ;; label = @13
                              local.get 0
                              local.get 3
                              i32.sub
                              local.tee 6
                              i32.const 16
                              i32.lt_u
                              br_if 0 (;@13;)
                              local.get 4
                              local.get 3
                              i32.add
                              local.tee 5
                              local.get 6
                              i32.const 1
                              i32.or
                              i32.store offset=4
                              i32.const 0
                              local.get 6
                              i32.store offset=4008
                              i32.const 0
                              local.get 5
                              i32.store offset=4020
                              local.get 4
                              local.get 0
                              i32.add
                              local.get 6
                              i32.store
                              local.get 4
                              local.get 3
                              i32.const 3
                              i32.or
                              i32.store offset=4
                              br 1 (;@12;)
                            end
                            local.get 4
                            local.get 0
                            i32.const 3
                            i32.or
                            i32.store offset=4
                            local.get 4
                            local.get 0
                            i32.add
                            local.tee 0
                            local.get 0
                            i32.load offset=4
                            i32.const 1
                            i32.or
                            i32.store offset=4
                            i32.const 0
                            i32.const 0
                            i32.store offset=4020
                            i32.const 0
                            i32.const 0
                            i32.store offset=4008
                          end
                          local.get 4
                          i32.const 8
                          i32.add
                          local.set 0
                          br 10 (;@1;)
                        end
                        block  ;; label = @11
                          i32.const 0
                          i32.load offset=4012
                          local.tee 5
                          local.get 3
                          i32.le_u
                          br_if 0 (;@11;)
                          i32.const 0
                          i32.load offset=4024
                          local.tee 0
                          local.get 3
                          i32.add
                          local.tee 4
                          local.get 5
                          local.get 3
                          i32.sub
                          local.tee 6
                          i32.const 1
                          i32.or
                          i32.store offset=4
                          i32.const 0
                          local.get 6
                          i32.store offset=4012
                          i32.const 0
                          local.get 4
                          i32.store offset=4024
                          local.get 0
                          local.get 3
                          i32.const 3
                          i32.or
                          i32.store offset=4
                          local.get 0
                          i32.const 8
                          i32.add
                          local.set 0
                          br 10 (;@1;)
                        end
                        block  ;; label = @11
                          block  ;; label = @12
                            i32.const 0
                            i32.load offset=4472
                            i32.eqz
                            br_if 0 (;@12;)
                            i32.const 0
                            i32.load offset=4480
                            local.set 4
                            br 1 (;@11;)
                          end
                          i32.const 0
                          i64.const -1
                          i64.store offset=4484 align=4
                          i32.const 0
                          i64.const 281474976776192
                          i64.store offset=4476 align=4
                          i32.const 0
                          local.get 1
                          i32.const 12
                          i32.add
                          i32.const -16
                          i32.and
                          i32.const 1431655768
                          i32.xor
                          i32.store offset=4472
                          i32.const 0
                          i32.const 0
                          i32.store offset=4492
                          i32.const 0
                          i32.const 0
                          i32.store offset=4444
                          i32.const 65536
                          local.set 4
                        end
                        i32.const 0
                        local.set 0
                        block  ;; label = @11
                          local.get 4
                          local.get 3
                          i32.const 71
                          i32.add
                          local.tee 7
                          i32.add
                          local.tee 2
                          i32.const 0
                          local.get 4
                          i32.sub
                          local.tee 11
                          i32.and
                          local.tee 8
                          local.get 3
                          i32.gt_u
                          br_if 0 (;@11;)
                          i32.const 0
                          i32.const 48
                          i32.store offset=4496
                          br 10 (;@1;)
                        end
                        block  ;; label = @11
                          i32.const 0
                          i32.load offset=4440
                          local.tee 0
                          i32.eqz
                          br_if 0 (;@11;)
                          block  ;; label = @12
                            i32.const 0
                            i32.load offset=4432
                            local.tee 4
                            local.get 8
                            i32.add
                            local.tee 6
                            local.get 4
                            i32.le_u
                            br_if 0 (;@12;)
                            local.get 6
                            local.get 0
                            i32.le_u
                            br_if 1 (;@11;)
                          end
                          i32.const 0
                          local.set 0
                          i32.const 0
                          i32.const 48
                          i32.store offset=4496
                          br 10 (;@1;)
                        end
                        i32.const 0
                        i32.load8_u offset=4444
                        i32.const 4
                        i32.and
                        br_if 4 (;@6;)
                        block  ;; label = @11
                          block  ;; label = @12
                            block  ;; label = @13
                              i32.const 0
                              i32.load offset=4024
                              local.tee 4
                              i32.eqz
                              br_if 0 (;@13;)
                              i32.const 4448
                              local.set 0
                              loop  ;; label = @14
                                block  ;; label = @15
                                  local.get 0
                                  i32.load
                                  local.tee 6
                                  local.get 4
                                  i32.gt_u
                                  br_if 0 (;@15;)
                                  local.get 6
                                  local.get 0
                                  i32.load offset=4
                                  i32.add
                                  local.get 4
                                  i32.gt_u
                                  br_if 3 (;@12;)
                                end
                                local.get 0
                                i32.load offset=8
                                local.tee 0
                                br_if 0 (;@14;)
                              end
                            end
                            i32.const 0
                            call $sbrk
                            local.tee 5
                            i32.const -1
                            i32.eq
                            br_if 5 (;@7;)
                            local.get 8
                            local.set 2
                            block  ;; label = @13
                              i32.const 0
                              i32.load offset=4476
                              local.tee 0
                              i32.const -1
                              i32.add
                              local.tee 4
                              local.get 5
                              i32.and
                              i32.eqz
                              br_if 0 (;@13;)
                              local.get 8
                              local.get 5
                              i32.sub
                              local.get 4
                              local.get 5
                              i32.add
                              i32.const 0
                              local.get 0
                              i32.sub
                              i32.and
                              i32.add
                              local.set 2
                            end
                            local.get 2
                            local.get 3
                            i32.le_u
                            br_if 5 (;@7;)
                            local.get 2
                            i32.const 2147483646
                            i32.gt_u
                            br_if 5 (;@7;)
                            block  ;; label = @13
                              i32.const 0
                              i32.load offset=4440
                              local.tee 0
                              i32.eqz
                              br_if 0 (;@13;)
                              i32.const 0
                              i32.load offset=4432
                              local.tee 4
                              local.get 2
                              i32.add
                              local.tee 6
                              local.get 4
                              i32.le_u
                              br_if 6 (;@7;)
                              local.get 6
                              local.get 0
                              i32.gt_u
                              br_if 6 (;@7;)
                            end
                            local.get 2
                            call $sbrk
                            local.tee 0
                            local.get 5
                            i32.ne
                            br_if 1 (;@11;)
                            br 7 (;@5;)
                          end
                          local.get 2
                          local.get 5
                          i32.sub
                          local.get 11
                          i32.and
                          local.tee 2
                          i32.const 2147483646
                          i32.gt_u
                          br_if 4 (;@7;)
                          local.get 2
                          call $sbrk
                          local.tee 5
                          local.get 0
                          i32.load
                          local.get 0
                          i32.load offset=4
                          i32.add
                          i32.eq
                          br_if 3 (;@8;)
                          local.get 5
                          local.set 0
                        end
                        local.get 0
                        local.set 5
                        block  ;; label = @11
                          local.get 3
                          i32.const 72
                          i32.add
                          local.get 2
                          i32.le_u
                          br_if 0 (;@11;)
                          local.get 2
                          i32.const 2147483646
                          i32.gt_u
                          br_if 0 (;@11;)
                          local.get 5
                          i32.const -1
                          i32.eq
                          br_if 0 (;@11;)
                          local.get 7
                          local.get 2
                          i32.sub
                          i32.const 0
                          i32.load offset=4480
                          local.tee 0
                          i32.add
                          i32.const 0
                          local.get 0
                          i32.sub
                          i32.and
                          local.tee 0
                          i32.const 2147483646
                          i32.gt_u
                          br_if 6 (;@5;)
                          block  ;; label = @12
                            local.get 0
                            call $sbrk
                            i32.const -1
                            i32.eq
                            br_if 0 (;@12;)
                            local.get 0
                            local.get 2
                            i32.add
                            local.set 2
                            br 7 (;@5;)
                          end
                          i32.const 0
                          local.get 2
                          i32.sub
                          call $sbrk
                          drop
                          br 4 (;@7;)
                        end
                        local.get 5
                        i32.const -1
                        i32.ne
                        br_if 5 (;@5;)
                        br 3 (;@7;)
                      end
                      i32.const 0
                      local.set 8
                      br 7 (;@2;)
                    end
                    i32.const 0
                    local.set 5
                    br 5 (;@3;)
                  end
                  local.get 5
                  i32.const -1
                  i32.ne
                  br_if 2 (;@5;)
                end
                i32.const 0
                i32.const 0
                i32.load offset=4444
                i32.const 4
                i32.or
                i32.store offset=4444
              end
              local.get 8
              i32.const 2147483646
              i32.gt_u
              br_if 1 (;@4;)
              local.get 8
              call $sbrk
              local.tee 5
              i32.const 0
              call $sbrk
              local.tee 0
              i32.ge_u
              br_if 1 (;@4;)
              local.get 5
              i32.const -1
              i32.eq
              br_if 1 (;@4;)
              local.get 0
              i32.const -1
              i32.eq
              br_if 1 (;@4;)
              local.get 0
              local.get 5
              i32.sub
              local.tee 2
              local.get 3
              i32.const 56
              i32.add
              i32.le_u
              br_if 1 (;@4;)
            end
            i32.const 0
            i32.const 0
            i32.load offset=4432
            local.get 2
            i32.add
            local.tee 0
            i32.store offset=4432
            block  ;; label = @5
              local.get 0
              i32.const 0
              i32.load offset=4436
              i32.le_u
              br_if 0 (;@5;)
              i32.const 0
              local.get 0
              i32.store offset=4436
            end
            block  ;; label = @5
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    i32.const 0
                    i32.load offset=4024
                    local.tee 4
                    i32.eqz
                    br_if 0 (;@8;)
                    i32.const 4448
                    local.set 0
                    loop  ;; label = @9
                      local.get 5
                      local.get 0
                      i32.load
                      local.tee 6
                      local.get 0
                      i32.load offset=4
                      local.tee 8
                      i32.add
                      i32.eq
                      br_if 2 (;@7;)
                      local.get 0
                      i32.load offset=8
                      local.tee 0
                      br_if 0 (;@9;)
                      br 3 (;@6;)
                    end
                  end
                  block  ;; label = @8
                    block  ;; label = @9
                      i32.const 0
                      i32.load offset=4016
                      local.tee 0
                      i32.eqz
                      br_if 0 (;@9;)
                      local.get 5
                      local.get 0
                      i32.ge_u
                      br_if 1 (;@8;)
                    end
                    i32.const 0
                    local.get 5
                    i32.store offset=4016
                  end
                  i32.const 0
                  local.set 0
                  i32.const 0
                  local.get 2
                  i32.store offset=4452
                  i32.const 0
                  local.get 5
                  i32.store offset=4448
                  i32.const 0
                  i32.const -1
                  i32.store offset=4032
                  i32.const 0
                  i32.const 0
                  i32.load offset=4472
                  i32.store offset=4036
                  i32.const 0
                  i32.const 0
                  i32.store offset=4460
                  loop  ;; label = @8
                    local.get 0
                    i32.const 4048
                    i32.add
                    local.get 0
                    i32.const 4040
                    i32.add
                    local.tee 4
                    i32.store
                    local.get 0
                    i32.const 4052
                    i32.add
                    local.get 4
                    i32.store
                    local.get 0
                    i32.const 8
                    i32.add
                    local.tee 0
                    i32.const 256
                    i32.ne
                    br_if 0 (;@8;)
                  end
                  local.get 5
                  i32.const -8
                  local.get 5
                  i32.sub
                  i32.const 15
                  i32.and
                  i32.const 0
                  local.get 5
                  i32.const 8
                  i32.add
                  i32.const 15
                  i32.and
                  select
                  local.tee 0
                  i32.add
                  local.tee 4
                  local.get 2
                  i32.const -56
                  i32.add
                  local.tee 6
                  local.get 0
                  i32.sub
                  local.tee 0
                  i32.const 1
                  i32.or
                  i32.store offset=4
                  i32.const 0
                  i32.const 0
                  i32.load offset=4488
                  i32.store offset=4028
                  i32.const 0
                  local.get 0
                  i32.store offset=4012
                  i32.const 0
                  local.get 4
                  i32.store offset=4024
                  local.get 5
                  local.get 6
                  i32.add
                  i32.const 56
                  i32.store offset=4
                  br 2 (;@5;)
                end
                local.get 0
                i32.load8_u offset=12
                i32.const 8
                i32.and
                br_if 0 (;@6;)
                local.get 5
                local.get 4
                i32.le_u
                br_if 0 (;@6;)
                local.get 6
                local.get 4
                i32.gt_u
                br_if 0 (;@6;)
                local.get 4
                i32.const -8
                local.get 4
                i32.sub
                i32.const 15
                i32.and
                i32.const 0
                local.get 4
                i32.const 8
                i32.add
                i32.const 15
                i32.and
                select
                local.tee 6
                i32.add
                local.tee 5
                i32.const 0
                i32.load offset=4012
                local.get 2
                i32.add
                local.tee 11
                local.get 6
                i32.sub
                local.tee 6
                i32.const 1
                i32.or
                i32.store offset=4
                local.get 0
                local.get 8
                local.get 2
                i32.add
                i32.store offset=4
                i32.const 0
                i32.const 0
                i32.load offset=4488
                i32.store offset=4028
                i32.const 0
                local.get 6
                i32.store offset=4012
                i32.const 0
                local.get 5
                i32.store offset=4024
                local.get 4
                local.get 11
                i32.add
                i32.const 56
                i32.store offset=4
                br 1 (;@5;)
              end
              block  ;; label = @6
                local.get 5
                i32.const 0
                i32.load offset=4016
                local.tee 8
                i32.ge_u
                br_if 0 (;@6;)
                i32.const 0
                local.get 5
                i32.store offset=4016
                local.get 5
                local.set 8
              end
              local.get 5
              local.get 2
              i32.add
              local.set 6
              i32.const 4448
              local.set 0
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    block  ;; label = @9
                      block  ;; label = @10
                        block  ;; label = @11
                          block  ;; label = @12
                            loop  ;; label = @13
                              local.get 0
                              i32.load
                              local.get 6
                              i32.eq
                              br_if 1 (;@12;)
                              local.get 0
                              i32.load offset=8
                              local.tee 0
                              br_if 0 (;@13;)
                              br 2 (;@11;)
                            end
                          end
                          local.get 0
                          i32.load8_u offset=12
                          i32.const 8
                          i32.and
                          i32.eqz
                          br_if 1 (;@10;)
                        end
                        i32.const 4448
                        local.set 0
                        loop  ;; label = @11
                          block  ;; label = @12
                            local.get 0
                            i32.load
                            local.tee 6
                            local.get 4
                            i32.gt_u
                            br_if 0 (;@12;)
                            local.get 6
                            local.get 0
                            i32.load offset=4
                            i32.add
                            local.tee 6
                            local.get 4
                            i32.gt_u
                            br_if 3 (;@9;)
                          end
                          local.get 0
                          i32.load offset=8
                          local.set 0
                          br 0 (;@11;)
                        end
                      end
                      local.get 0
                      local.get 5
                      i32.store
                      local.get 0
                      local.get 0
                      i32.load offset=4
                      local.get 2
                      i32.add
                      i32.store offset=4
                      local.get 5
                      i32.const -8
                      local.get 5
                      i32.sub
                      i32.const 15
                      i32.and
                      i32.const 0
                      local.get 5
                      i32.const 8
                      i32.add
                      i32.const 15
                      i32.and
                      select
                      i32.add
                      local.tee 11
                      local.get 3
                      i32.const 3
                      i32.or
                      i32.store offset=4
                      local.get 6
                      i32.const -8
                      local.get 6
                      i32.sub
                      i32.const 15
                      i32.and
                      i32.const 0
                      local.get 6
                      i32.const 8
                      i32.add
                      i32.const 15
                      i32.and
                      select
                      i32.add
                      local.tee 5
                      local.get 11
                      i32.sub
                      local.get 3
                      i32.sub
                      local.set 0
                      local.get 11
                      local.get 3
                      i32.add
                      local.set 6
                      block  ;; label = @10
                        local.get 4
                        local.get 5
                        i32.ne
                        br_if 0 (;@10;)
                        i32.const 0
                        local.get 6
                        i32.store offset=4024
                        i32.const 0
                        i32.const 0
                        i32.load offset=4012
                        local.get 0
                        i32.add
                        local.tee 0
                        i32.store offset=4012
                        local.get 6
                        local.get 0
                        i32.const 1
                        i32.or
                        i32.store offset=4
                        br 3 (;@7;)
                      end
                      block  ;; label = @10
                        i32.const 0
                        i32.load offset=4020
                        local.get 5
                        i32.ne
                        br_if 0 (;@10;)
                        i32.const 0
                        local.get 6
                        i32.store offset=4020
                        i32.const 0
                        i32.const 0
                        i32.load offset=4008
                        local.get 0
                        i32.add
                        local.tee 0
                        i32.store offset=4008
                        local.get 6
                        local.get 0
                        i32.const 1
                        i32.or
                        i32.store offset=4
                        local.get 6
                        local.get 0
                        i32.add
                        local.get 0
                        i32.store
                        br 3 (;@7;)
                      end
                      block  ;; label = @10
                        local.get 5
                        i32.load offset=4
                        local.tee 4
                        i32.const 3
                        i32.and
                        i32.const 1
                        i32.ne
                        br_if 0 (;@10;)
                        local.get 4
                        i32.const -8
                        i32.and
                        local.set 7
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 4
                            i32.const 255
                            i32.gt_u
                            br_if 0 (;@12;)
                            local.get 5
                            i32.load offset=12
                            local.set 3
                            block  ;; label = @13
                              local.get 5
                              i32.load offset=8
                              local.tee 2
                              local.get 4
                              i32.const 3
                              i32.shr_u
                              local.tee 9
                              i32.const 3
                              i32.shl
                              i32.const 4040
                              i32.add
                              local.tee 4
                              i32.eq
                              br_if 0 (;@13;)
                              local.get 8
                              local.get 2
                              i32.gt_u
                              drop
                            end
                            block  ;; label = @13
                              local.get 3
                              local.get 2
                              i32.ne
                              br_if 0 (;@13;)
                              i32.const 0
                              i32.const 0
                              i32.load offset=4000
                              i32.const -2
                              local.get 9
                              i32.rotl
                              i32.and
                              i32.store offset=4000
                              br 2 (;@11;)
                            end
                            block  ;; label = @13
                              local.get 3
                              local.get 4
                              i32.eq
                              br_if 0 (;@13;)
                              local.get 8
                              local.get 3
                              i32.gt_u
                              drop
                            end
                            local.get 3
                            local.get 2
                            i32.store offset=8
                            local.get 2
                            local.get 3
                            i32.store offset=12
                            br 1 (;@11;)
                          end
                          local.get 5
                          i32.load offset=24
                          local.set 9
                          block  ;; label = @12
                            block  ;; label = @13
                              local.get 5
                              i32.load offset=12
                              local.tee 2
                              local.get 5
                              i32.eq
                              br_if 0 (;@13;)
                              block  ;; label = @14
                                local.get 8
                                local.get 5
                                i32.load offset=8
                                local.tee 4
                                i32.gt_u
                                br_if 0 (;@14;)
                                local.get 4
                                i32.load offset=12
                                local.get 5
                                i32.ne
                                drop
                              end
                              local.get 2
                              local.get 4
                              i32.store offset=8
                              local.get 4
                              local.get 2
                              i32.store offset=12
                              br 1 (;@12;)
                            end
                            block  ;; label = @13
                              local.get 5
                              i32.const 20
                              i32.add
                              local.tee 4
                              i32.load
                              local.tee 3
                              br_if 0 (;@13;)
                              local.get 5
                              i32.const 16
                              i32.add
                              local.tee 4
                              i32.load
                              local.tee 3
                              br_if 0 (;@13;)
                              i32.const 0
                              local.set 2
                              br 1 (;@12;)
                            end
                            loop  ;; label = @13
                              local.get 4
                              local.set 8
                              local.get 3
                              local.tee 2
                              i32.const 20
                              i32.add
                              local.tee 4
                              i32.load
                              local.tee 3
                              br_if 0 (;@13;)
                              local.get 2
                              i32.const 16
                              i32.add
                              local.set 4
                              local.get 2
                              i32.load offset=16
                              local.tee 3
                              br_if 0 (;@13;)
                            end
                            local.get 8
                            i32.const 0
                            i32.store
                          end
                          local.get 9
                          i32.eqz
                          br_if 0 (;@11;)
                          block  ;; label = @12
                            block  ;; label = @13
                              local.get 5
                              i32.load offset=28
                              local.tee 3
                              i32.const 2
                              i32.shl
                              i32.const 4304
                              i32.add
                              local.tee 4
                              i32.load
                              local.get 5
                              i32.ne
                              br_if 0 (;@13;)
                              local.get 4
                              local.get 2
                              i32.store
                              local.get 2
                              br_if 1 (;@12;)
                              i32.const 0
                              i32.const 0
                              i32.load offset=4004
                              i32.const -2
                              local.get 3
                              i32.rotl
                              i32.and
                              i32.store offset=4004
                              br 2 (;@11;)
                            end
                            local.get 9
                            i32.const 16
                            i32.const 20
                            local.get 9
                            i32.load offset=16
                            local.get 5
                            i32.eq
                            select
                            i32.add
                            local.get 2
                            i32.store
                            local.get 2
                            i32.eqz
                            br_if 1 (;@11;)
                          end
                          local.get 2
                          local.get 9
                          i32.store offset=24
                          block  ;; label = @12
                            local.get 5
                            i32.load offset=16
                            local.tee 4
                            i32.eqz
                            br_if 0 (;@12;)
                            local.get 2
                            local.get 4
                            i32.store offset=16
                            local.get 4
                            local.get 2
                            i32.store offset=24
                          end
                          local.get 5
                          i32.load offset=20
                          local.tee 4
                          i32.eqz
                          br_if 0 (;@11;)
                          local.get 2
                          i32.const 20
                          i32.add
                          local.get 4
                          i32.store
                          local.get 4
                          local.get 2
                          i32.store offset=24
                        end
                        local.get 7
                        local.get 0
                        i32.add
                        local.set 0
                        local.get 5
                        local.get 7
                        i32.add
                        local.set 5
                      end
                      local.get 5
                      local.get 5
                      i32.load offset=4
                      i32.const -2
                      i32.and
                      i32.store offset=4
                      local.get 6
                      local.get 0
                      i32.add
                      local.get 0
                      i32.store
                      local.get 6
                      local.get 0
                      i32.const 1
                      i32.or
                      i32.store offset=4
                      block  ;; label = @10
                        local.get 0
                        i32.const 255
                        i32.gt_u
                        br_if 0 (;@10;)
                        local.get 0
                        i32.const 3
                        i32.shr_u
                        local.tee 4
                        i32.const 3
                        i32.shl
                        i32.const 4040
                        i32.add
                        local.set 0
                        block  ;; label = @11
                          block  ;; label = @12
                            i32.const 0
                            i32.load offset=4000
                            local.tee 3
                            i32.const 1
                            local.get 4
                            i32.shl
                            local.tee 4
                            i32.and
                            br_if 0 (;@12;)
                            i32.const 0
                            local.get 3
                            local.get 4
                            i32.or
                            i32.store offset=4000
                            local.get 0
                            local.set 4
                            br 1 (;@11;)
                          end
                          local.get 0
                          i32.load offset=8
                          local.set 4
                        end
                        local.get 4
                        local.get 6
                        i32.store offset=12
                        local.get 0
                        local.get 6
                        i32.store offset=8
                        local.get 6
                        local.get 0
                        i32.store offset=12
                        local.get 6
                        local.get 4
                        i32.store offset=8
                        br 3 (;@7;)
                      end
                      i32.const 0
                      local.set 4
                      block  ;; label = @10
                        local.get 0
                        i32.const 8
                        i32.shr_u
                        local.tee 3
                        i32.eqz
                        br_if 0 (;@10;)
                        i32.const 31
                        local.set 4
                        local.get 0
                        i32.const 16777215
                        i32.gt_u
                        br_if 0 (;@10;)
                        local.get 3
                        local.get 3
                        i32.const 1048320
                        i32.add
                        i32.const 16
                        i32.shr_u
                        i32.const 8
                        i32.and
                        local.tee 4
                        i32.shl
                        local.tee 3
                        local.get 3
                        i32.const 520192
                        i32.add
                        i32.const 16
                        i32.shr_u
                        i32.const 4
                        i32.and
                        local.tee 3
                        i32.shl
                        local.tee 5
                        local.get 5
                        i32.const 245760
                        i32.add
                        i32.const 16
                        i32.shr_u
                        i32.const 2
                        i32.and
                        local.tee 5
                        i32.shl
                        i32.const 15
                        i32.shr_u
                        local.get 3
                        local.get 4
                        i32.or
                        local.get 5
                        i32.or
                        i32.sub
                        local.tee 4
                        i32.const 1
                        i32.shl
                        local.get 0
                        local.get 4
                        i32.const 21
                        i32.add
                        i32.shr_u
                        i32.const 1
                        i32.and
                        i32.or
                        i32.const 28
                        i32.add
                        local.set 4
                      end
                      local.get 6
                      local.get 4
                      i32.store offset=28
                      local.get 6
                      i64.const 0
                      i64.store offset=16 align=4
                      local.get 4
                      i32.const 2
                      i32.shl
                      i32.const 4304
                      i32.add
                      local.set 3
                      block  ;; label = @10
                        i32.const 0
                        i32.load offset=4004
                        local.tee 5
                        i32.const 1
                        local.get 4
                        i32.shl
                        local.tee 8
                        i32.and
                        br_if 0 (;@10;)
                        local.get 3
                        local.get 6
                        i32.store
                        i32.const 0
                        local.get 5
                        local.get 8
                        i32.or
                        i32.store offset=4004
                        local.get 6
                        local.get 3
                        i32.store offset=24
                        local.get 6
                        local.get 6
                        i32.store offset=8
                        local.get 6
                        local.get 6
                        i32.store offset=12
                        br 3 (;@7;)
                      end
                      local.get 0
                      i32.const 0
                      i32.const 25
                      local.get 4
                      i32.const 1
                      i32.shr_u
                      i32.sub
                      local.get 4
                      i32.const 31
                      i32.eq
                      select
                      i32.shl
                      local.set 4
                      local.get 3
                      i32.load
                      local.set 5
                      loop  ;; label = @10
                        local.get 5
                        local.tee 3
                        i32.load offset=4
                        i32.const -8
                        i32.and
                        local.get 0
                        i32.eq
                        br_if 2 (;@8;)
                        local.get 4
                        i32.const 29
                        i32.shr_u
                        local.set 5
                        local.get 4
                        i32.const 1
                        i32.shl
                        local.set 4
                        local.get 3
                        local.get 5
                        i32.const 4
                        i32.and
                        i32.add
                        i32.const 16
                        i32.add
                        local.tee 8
                        i32.load
                        local.tee 5
                        br_if 0 (;@10;)
                      end
                      local.get 8
                      local.get 6
                      i32.store
                      local.get 6
                      local.get 3
                      i32.store offset=24
                      local.get 6
                      local.get 6
                      i32.store offset=12
                      local.get 6
                      local.get 6
                      i32.store offset=8
                      br 2 (;@7;)
                    end
                    local.get 5
                    i32.const -8
                    local.get 5
                    i32.sub
                    i32.const 15
                    i32.and
                    i32.const 0
                    local.get 5
                    i32.const 8
                    i32.add
                    i32.const 15
                    i32.and
                    select
                    local.tee 0
                    i32.add
                    local.tee 11
                    local.get 2
                    i32.const -56
                    i32.add
                    local.tee 8
                    local.get 0
                    i32.sub
                    local.tee 0
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    local.get 5
                    local.get 8
                    i32.add
                    i32.const 56
                    i32.store offset=4
                    local.get 4
                    local.get 6
                    i32.const 55
                    local.get 6
                    i32.sub
                    i32.const 15
                    i32.and
                    i32.const 0
                    local.get 6
                    i32.const -55
                    i32.add
                    i32.const 15
                    i32.and
                    select
                    i32.add
                    i32.const -63
                    i32.add
                    local.tee 8
                    local.get 8
                    local.get 4
                    i32.const 16
                    i32.add
                    i32.lt_u
                    select
                    local.tee 8
                    i32.const 35
                    i32.store offset=4
                    i32.const 0
                    i32.const 0
                    i32.load offset=4488
                    i32.store offset=4028
                    i32.const 0
                    local.get 0
                    i32.store offset=4012
                    i32.const 0
                    local.get 11
                    i32.store offset=4024
                    local.get 8
                    i32.const 16
                    i32.add
                    i32.const 0
                    i64.load offset=4456 align=4
                    i64.store align=4
                    local.get 8
                    i32.const 0
                    i64.load offset=4448 align=4
                    i64.store offset=8 align=4
                    i32.const 0
                    local.get 8
                    i32.const 8
                    i32.add
                    i32.store offset=4456
                    i32.const 0
                    local.get 2
                    i32.store offset=4452
                    i32.const 0
                    local.get 5
                    i32.store offset=4448
                    i32.const 0
                    i32.const 0
                    i32.store offset=4460
                    local.get 8
                    i32.const 36
                    i32.add
                    local.set 0
                    loop  ;; label = @9
                      local.get 0
                      i32.const 7
                      i32.store
                      local.get 6
                      local.get 0
                      i32.const 4
                      i32.add
                      local.tee 0
                      i32.gt_u
                      br_if 0 (;@9;)
                    end
                    local.get 8
                    local.get 4
                    i32.eq
                    br_if 3 (;@5;)
                    local.get 8
                    local.get 8
                    i32.load offset=4
                    i32.const -2
                    i32.and
                    i32.store offset=4
                    local.get 8
                    local.get 8
                    local.get 4
                    i32.sub
                    local.tee 2
                    i32.store
                    local.get 4
                    local.get 2
                    i32.const 1
                    i32.or
                    i32.store offset=4
                    block  ;; label = @9
                      local.get 2
                      i32.const 255
                      i32.gt_u
                      br_if 0 (;@9;)
                      local.get 2
                      i32.const 3
                      i32.shr_u
                      local.tee 6
                      i32.const 3
                      i32.shl
                      i32.const 4040
                      i32.add
                      local.set 0
                      block  ;; label = @10
                        block  ;; label = @11
                          i32.const 0
                          i32.load offset=4000
                          local.tee 5
                          i32.const 1
                          local.get 6
                          i32.shl
                          local.tee 6
                          i32.and
                          br_if 0 (;@11;)
                          i32.const 0
                          local.get 5
                          local.get 6
                          i32.or
                          i32.store offset=4000
                          local.get 0
                          local.set 6
                          br 1 (;@10;)
                        end
                        local.get 0
                        i32.load offset=8
                        local.set 6
                      end
                      local.get 6
                      local.get 4
                      i32.store offset=12
                      local.get 0
                      local.get 4
                      i32.store offset=8
                      local.get 4
                      local.get 0
                      i32.store offset=12
                      local.get 4
                      local.get 6
                      i32.store offset=8
                      br 4 (;@5;)
                    end
                    i32.const 0
                    local.set 0
                    block  ;; label = @9
                      local.get 2
                      i32.const 8
                      i32.shr_u
                      local.tee 6
                      i32.eqz
                      br_if 0 (;@9;)
                      i32.const 31
                      local.set 0
                      local.get 2
                      i32.const 16777215
                      i32.gt_u
                      br_if 0 (;@9;)
                      local.get 6
                      local.get 6
                      i32.const 1048320
                      i32.add
                      i32.const 16
                      i32.shr_u
                      i32.const 8
                      i32.and
                      local.tee 0
                      i32.shl
                      local.tee 6
                      local.get 6
                      i32.const 520192
                      i32.add
                      i32.const 16
                      i32.shr_u
                      i32.const 4
                      i32.and
                      local.tee 6
                      i32.shl
                      local.tee 5
                      local.get 5
                      i32.const 245760
                      i32.add
                      i32.const 16
                      i32.shr_u
                      i32.const 2
                      i32.and
                      local.tee 5
                      i32.shl
                      i32.const 15
                      i32.shr_u
                      local.get 6
                      local.get 0
                      i32.or
                      local.get 5
                      i32.or
                      i32.sub
                      local.tee 0
                      i32.const 1
                      i32.shl
                      local.get 2
                      local.get 0
                      i32.const 21
                      i32.add
                      i32.shr_u
                      i32.const 1
                      i32.and
                      i32.or
                      i32.const 28
                      i32.add
                      local.set 0
                    end
                    local.get 4
                    i64.const 0
                    i64.store offset=16 align=4
                    local.get 4
                    i32.const 28
                    i32.add
                    local.get 0
                    i32.store
                    local.get 0
                    i32.const 2
                    i32.shl
                    i32.const 4304
                    i32.add
                    local.set 6
                    block  ;; label = @9
                      i32.const 0
                      i32.load offset=4004
                      local.tee 5
                      i32.const 1
                      local.get 0
                      i32.shl
                      local.tee 8
                      i32.and
                      br_if 0 (;@9;)
                      local.get 6
                      local.get 4
                      i32.store
                      i32.const 0
                      local.get 5
                      local.get 8
                      i32.or
                      i32.store offset=4004
                      local.get 4
                      i32.const 24
                      i32.add
                      local.get 6
                      i32.store
                      local.get 4
                      local.get 4
                      i32.store offset=8
                      local.get 4
                      local.get 4
                      i32.store offset=12
                      br 4 (;@5;)
                    end
                    local.get 2
                    i32.const 0
                    i32.const 25
                    local.get 0
                    i32.const 1
                    i32.shr_u
                    i32.sub
                    local.get 0
                    i32.const 31
                    i32.eq
                    select
                    i32.shl
                    local.set 0
                    local.get 6
                    i32.load
                    local.set 5
                    loop  ;; label = @9
                      local.get 5
                      local.tee 6
                      i32.load offset=4
                      i32.const -8
                      i32.and
                      local.get 2
                      i32.eq
                      br_if 3 (;@6;)
                      local.get 0
                      i32.const 29
                      i32.shr_u
                      local.set 5
                      local.get 0
                      i32.const 1
                      i32.shl
                      local.set 0
                      local.get 6
                      local.get 5
                      i32.const 4
                      i32.and
                      i32.add
                      i32.const 16
                      i32.add
                      local.tee 8
                      i32.load
                      local.tee 5
                      br_if 0 (;@9;)
                    end
                    local.get 8
                    local.get 4
                    i32.store
                    local.get 4
                    i32.const 24
                    i32.add
                    local.get 6
                    i32.store
                    local.get 4
                    local.get 4
                    i32.store offset=12
                    local.get 4
                    local.get 4
                    i32.store offset=8
                    br 3 (;@5;)
                  end
                  local.get 3
                  i32.load offset=8
                  local.set 0
                  local.get 3
                  local.get 6
                  i32.store offset=8
                  local.get 0
                  local.get 6
                  i32.store offset=12
                  local.get 6
                  i32.const 0
                  i32.store offset=24
                  local.get 6
                  local.get 0
                  i32.store offset=8
                  local.get 6
                  local.get 3
                  i32.store offset=12
                end
                local.get 11
                i32.const 8
                i32.add
                local.set 0
                br 5 (;@1;)
              end
              local.get 6
              i32.load offset=8
              local.set 0
              local.get 6
              local.get 4
              i32.store offset=8
              local.get 0
              local.get 4
              i32.store offset=12
              local.get 4
              i32.const 24
              i32.add
              i32.const 0
              i32.store
              local.get 4
              local.get 0
              i32.store offset=8
              local.get 4
              local.get 6
              i32.store offset=12
            end
            i32.const 0
            i32.load offset=4012
            local.tee 0
            local.get 3
            i32.le_u
            br_if 0 (;@4;)
            i32.const 0
            i32.load offset=4024
            local.tee 4
            local.get 3
            i32.add
            local.tee 6
            local.get 0
            local.get 3
            i32.sub
            local.tee 0
            i32.const 1
            i32.or
            i32.store offset=4
            i32.const 0
            local.get 0
            i32.store offset=4012
            i32.const 0
            local.get 6
            i32.store offset=4024
            local.get 4
            local.get 3
            i32.const 3
            i32.or
            i32.store offset=4
            local.get 4
            i32.const 8
            i32.add
            local.set 0
            br 3 (;@1;)
          end
          i32.const 0
          local.set 0
          i32.const 0
          i32.const 48
          i32.store offset=4496
          br 2 (;@1;)
        end
        block  ;; label = @3
          local.get 11
          i32.eqz
          br_if 0 (;@3;)
          block  ;; label = @4
            block  ;; label = @5
              local.get 8
              local.get 8
              i32.load offset=28
              local.tee 4
              i32.const 2
              i32.shl
              i32.const 4304
              i32.add
              local.tee 0
              i32.load
              i32.ne
              br_if 0 (;@5;)
              local.get 0
              local.get 5
              i32.store
              local.get 5
              br_if 1 (;@4;)
              i32.const 0
              local.get 7
              i32.const -2
              local.get 4
              i32.rotl
              i32.and
              local.tee 7
              i32.store offset=4004
              br 2 (;@3;)
            end
            local.get 11
            i32.const 16
            i32.const 20
            local.get 11
            i32.load offset=16
            local.get 8
            i32.eq
            select
            i32.add
            local.get 5
            i32.store
            local.get 5
            i32.eqz
            br_if 1 (;@3;)
          end
          local.get 5
          local.get 11
          i32.store offset=24
          block  ;; label = @4
            local.get 8
            i32.load offset=16
            local.tee 0
            i32.eqz
            br_if 0 (;@4;)
            local.get 5
            local.get 0
            i32.store offset=16
            local.get 0
            local.get 5
            i32.store offset=24
          end
          local.get 8
          i32.const 20
          i32.add
          i32.load
          local.tee 0
          i32.eqz
          br_if 0 (;@3;)
          local.get 5
          i32.const 20
          i32.add
          local.get 0
          i32.store
          local.get 0
          local.get 5
          i32.store offset=24
        end
        block  ;; label = @3
          block  ;; label = @4
            local.get 6
            i32.const 15
            i32.gt_u
            br_if 0 (;@4;)
            local.get 8
            local.get 6
            local.get 3
            i32.add
            local.tee 0
            i32.const 3
            i32.or
            i32.store offset=4
            local.get 8
            local.get 0
            i32.add
            local.tee 0
            local.get 0
            i32.load offset=4
            i32.const 1
            i32.or
            i32.store offset=4
            br 1 (;@3;)
          end
          local.get 8
          local.get 3
          i32.add
          local.tee 5
          local.get 6
          i32.const 1
          i32.or
          i32.store offset=4
          local.get 8
          local.get 3
          i32.const 3
          i32.or
          i32.store offset=4
          local.get 5
          local.get 6
          i32.add
          local.get 6
          i32.store
          block  ;; label = @4
            local.get 6
            i32.const 255
            i32.gt_u
            br_if 0 (;@4;)
            local.get 6
            i32.const 3
            i32.shr_u
            local.tee 4
            i32.const 3
            i32.shl
            i32.const 4040
            i32.add
            local.set 0
            block  ;; label = @5
              block  ;; label = @6
                i32.const 0
                i32.load offset=4000
                local.tee 6
                i32.const 1
                local.get 4
                i32.shl
                local.tee 4
                i32.and
                br_if 0 (;@6;)
                i32.const 0
                local.get 6
                local.get 4
                i32.or
                i32.store offset=4000
                local.get 0
                local.set 4
                br 1 (;@5;)
              end
              local.get 0
              i32.load offset=8
              local.set 4
            end
            local.get 4
            local.get 5
            i32.store offset=12
            local.get 0
            local.get 5
            i32.store offset=8
            local.get 5
            local.get 0
            i32.store offset=12
            local.get 5
            local.get 4
            i32.store offset=8
            br 1 (;@3;)
          end
          block  ;; label = @4
            block  ;; label = @5
              local.get 6
              i32.const 8
              i32.shr_u
              local.tee 4
              br_if 0 (;@5;)
              i32.const 0
              local.set 0
              br 1 (;@4;)
            end
            i32.const 31
            local.set 0
            local.get 6
            i32.const 16777215
            i32.gt_u
            br_if 0 (;@4;)
            local.get 4
            local.get 4
            i32.const 1048320
            i32.add
            i32.const 16
            i32.shr_u
            i32.const 8
            i32.and
            local.tee 0
            i32.shl
            local.tee 4
            local.get 4
            i32.const 520192
            i32.add
            i32.const 16
            i32.shr_u
            i32.const 4
            i32.and
            local.tee 4
            i32.shl
            local.tee 3
            local.get 3
            i32.const 245760
            i32.add
            i32.const 16
            i32.shr_u
            i32.const 2
            i32.and
            local.tee 3
            i32.shl
            i32.const 15
            i32.shr_u
            local.get 4
            local.get 0
            i32.or
            local.get 3
            i32.or
            i32.sub
            local.tee 0
            i32.const 1
            i32.shl
            local.get 6
            local.get 0
            i32.const 21
            i32.add
            i32.shr_u
            i32.const 1
            i32.and
            i32.or
            i32.const 28
            i32.add
            local.set 0
          end
          local.get 5
          local.get 0
          i32.store offset=28
          local.get 5
          i64.const 0
          i64.store offset=16 align=4
          local.get 0
          i32.const 2
          i32.shl
          i32.const 4304
          i32.add
          local.set 4
          block  ;; label = @4
            local.get 7
            i32.const 1
            local.get 0
            i32.shl
            local.tee 3
            i32.and
            br_if 0 (;@4;)
            local.get 4
            local.get 5
            i32.store
            i32.const 0
            local.get 7
            local.get 3
            i32.or
            i32.store offset=4004
            local.get 5
            local.get 4
            i32.store offset=24
            local.get 5
            local.get 5
            i32.store offset=8
            local.get 5
            local.get 5
            i32.store offset=12
            br 1 (;@3;)
          end
          local.get 6
          i32.const 0
          i32.const 25
          local.get 0
          i32.const 1
          i32.shr_u
          i32.sub
          local.get 0
          i32.const 31
          i32.eq
          select
          i32.shl
          local.set 0
          local.get 4
          i32.load
          local.set 3
          block  ;; label = @4
            loop  ;; label = @5
              local.get 3
              local.tee 4
              i32.load offset=4
              i32.const -8
              i32.and
              local.get 6
              i32.eq
              br_if 1 (;@4;)
              local.get 0
              i32.const 29
              i32.shr_u
              local.set 3
              local.get 0
              i32.const 1
              i32.shl
              local.set 0
              local.get 4
              local.get 3
              i32.const 4
              i32.and
              i32.add
              i32.const 16
              i32.add
              local.tee 2
              i32.load
              local.tee 3
              br_if 0 (;@5;)
            end
            local.get 2
            local.get 5
            i32.store
            local.get 5
            local.get 4
            i32.store offset=24
            local.get 5
            local.get 5
            i32.store offset=12
            local.get 5
            local.get 5
            i32.store offset=8
            br 1 (;@3;)
          end
          local.get 4
          i32.load offset=8
          local.set 0
          local.get 4
          local.get 5
          i32.store offset=8
          local.get 0
          local.get 5
          i32.store offset=12
          local.get 5
          i32.const 0
          i32.store offset=24
          local.get 5
          local.get 0
          i32.store offset=8
          local.get 5
          local.get 4
          i32.store offset=12
        end
        local.get 8
        i32.const 8
        i32.add
        local.set 0
        br 1 (;@1;)
      end
      block  ;; label = @2
        local.get 10
        i32.eqz
        br_if 0 (;@2;)
        block  ;; label = @3
          block  ;; label = @4
            local.get 5
            local.get 5
            i32.load offset=28
            local.tee 6
            i32.const 2
            i32.shl
            i32.const 4304
            i32.add
            local.tee 0
            i32.load
            i32.ne
            br_if 0 (;@4;)
            local.get 0
            local.get 8
            i32.store
            local.get 8
            br_if 1 (;@3;)
            i32.const 0
            local.get 9
            i32.const -2
            local.get 6
            i32.rotl
            i32.and
            i32.store offset=4004
            br 2 (;@2;)
          end
          local.get 10
          i32.const 16
          i32.const 20
          local.get 10
          i32.load offset=16
          local.get 5
          i32.eq
          select
          i32.add
          local.get 8
          i32.store
          local.get 8
          i32.eqz
          br_if 1 (;@2;)
        end
        local.get 8
        local.get 10
        i32.store offset=24
        block  ;; label = @3
          local.get 5
          i32.load offset=16
          local.tee 0
          i32.eqz
          br_if 0 (;@3;)
          local.get 8
          local.get 0
          i32.store offset=16
          local.get 0
          local.get 8
          i32.store offset=24
        end
        local.get 5
        i32.const 20
        i32.add
        i32.load
        local.tee 0
        i32.eqz
        br_if 0 (;@2;)
        local.get 8
        i32.const 20
        i32.add
        local.get 0
        i32.store
        local.get 0
        local.get 8
        i32.store offset=24
      end
      block  ;; label = @2
        block  ;; label = @3
          local.get 4
          i32.const 15
          i32.gt_u
          br_if 0 (;@3;)
          local.get 5
          local.get 4
          local.get 3
          i32.add
          local.tee 0
          i32.const 3
          i32.or
          i32.store offset=4
          local.get 5
          local.get 0
          i32.add
          local.tee 0
          local.get 0
          i32.load offset=4
          i32.const 1
          i32.or
          i32.store offset=4
          br 1 (;@2;)
        end
        local.get 5
        local.get 3
        i32.add
        local.tee 6
        local.get 4
        i32.const 1
        i32.or
        i32.store offset=4
        local.get 5
        local.get 3
        i32.const 3
        i32.or
        i32.store offset=4
        local.get 6
        local.get 4
        i32.add
        local.get 4
        i32.store
        block  ;; label = @3
          local.get 7
          i32.eqz
          br_if 0 (;@3;)
          local.get 7
          i32.const 3
          i32.shr_u
          local.tee 8
          i32.const 3
          i32.shl
          i32.const 4040
          i32.add
          local.set 3
          i32.const 0
          i32.load offset=4020
          local.set 0
          block  ;; label = @4
            block  ;; label = @5
              i32.const 1
              local.get 8
              i32.shl
              local.tee 8
              local.get 2
              i32.and
              br_if 0 (;@5;)
              i32.const 0
              local.get 8
              local.get 2
              i32.or
              i32.store offset=4000
              local.get 3
              local.set 8
              br 1 (;@4;)
            end
            local.get 3
            i32.load offset=8
            local.set 8
          end
          local.get 8
          local.get 0
          i32.store offset=12
          local.get 3
          local.get 0
          i32.store offset=8
          local.get 0
          local.get 3
          i32.store offset=12
          local.get 0
          local.get 8
          i32.store offset=8
        end
        i32.const 0
        local.get 6
        i32.store offset=4020
        i32.const 0
        local.get 4
        i32.store offset=4008
      end
      local.get 5
      i32.const 8
      i32.add
      local.set 0
    end
    local.get 1
    i32.const 16
    i32.add
    global.set 0
    local.get 0)
  (func $free (type 2) (param i32)
    local.get 0
    call $dlfree)
  (func $dlfree (type 2) (param i32)
    (local i32 i32 i32 i32 i32 i32 i32)
    block  ;; label = @1
      local.get 0
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      i32.const -8
      i32.add
      local.tee 1
      local.get 0
      i32.const -4
      i32.add
      i32.load
      local.tee 2
      i32.const -8
      i32.and
      local.tee 0
      i32.add
      local.set 3
      block  ;; label = @2
        local.get 2
        i32.const 1
        i32.and
        br_if 0 (;@2;)
        local.get 2
        i32.const 3
        i32.and
        i32.eqz
        br_if 1 (;@1;)
        local.get 1
        local.get 1
        i32.load
        local.tee 2
        i32.sub
        local.tee 1
        i32.const 0
        i32.load offset=4016
        local.tee 4
        i32.lt_u
        br_if 1 (;@1;)
        local.get 2
        local.get 0
        i32.add
        local.set 0
        block  ;; label = @3
          i32.const 0
          i32.load offset=4020
          local.get 1
          i32.eq
          br_if 0 (;@3;)
          block  ;; label = @4
            local.get 2
            i32.const 255
            i32.gt_u
            br_if 0 (;@4;)
            local.get 1
            i32.load offset=12
            local.set 5
            block  ;; label = @5
              local.get 1
              i32.load offset=8
              local.tee 6
              local.get 2
              i32.const 3
              i32.shr_u
              local.tee 7
              i32.const 3
              i32.shl
              i32.const 4040
              i32.add
              local.tee 2
              i32.eq
              br_if 0 (;@5;)
              local.get 4
              local.get 6
              i32.gt_u
              drop
            end
            block  ;; label = @5
              local.get 5
              local.get 6
              i32.ne
              br_if 0 (;@5;)
              i32.const 0
              i32.const 0
              i32.load offset=4000
              i32.const -2
              local.get 7
              i32.rotl
              i32.and
              i32.store offset=4000
              br 3 (;@2;)
            end
            block  ;; label = @5
              local.get 5
              local.get 2
              i32.eq
              br_if 0 (;@5;)
              local.get 4
              local.get 5
              i32.gt_u
              drop
            end
            local.get 5
            local.get 6
            i32.store offset=8
            local.get 6
            local.get 5
            i32.store offset=12
            br 2 (;@2;)
          end
          local.get 1
          i32.load offset=24
          local.set 7
          block  ;; label = @4
            block  ;; label = @5
              local.get 1
              i32.load offset=12
              local.tee 5
              local.get 1
              i32.eq
              br_if 0 (;@5;)
              block  ;; label = @6
                local.get 4
                local.get 1
                i32.load offset=8
                local.tee 2
                i32.gt_u
                br_if 0 (;@6;)
                local.get 2
                i32.load offset=12
                local.get 1
                i32.ne
                drop
              end
              local.get 5
              local.get 2
              i32.store offset=8
              local.get 2
              local.get 5
              i32.store offset=12
              br 1 (;@4;)
            end
            block  ;; label = @5
              local.get 1
              i32.const 20
              i32.add
              local.tee 2
              i32.load
              local.tee 4
              br_if 0 (;@5;)
              local.get 1
              i32.const 16
              i32.add
              local.tee 2
              i32.load
              local.tee 4
              br_if 0 (;@5;)
              i32.const 0
              local.set 5
              br 1 (;@4;)
            end
            loop  ;; label = @5
              local.get 2
              local.set 6
              local.get 4
              local.tee 5
              i32.const 20
              i32.add
              local.tee 2
              i32.load
              local.tee 4
              br_if 0 (;@5;)
              local.get 5
              i32.const 16
              i32.add
              local.set 2
              local.get 5
              i32.load offset=16
              local.tee 4
              br_if 0 (;@5;)
            end
            local.get 6
            i32.const 0
            i32.store
          end
          local.get 7
          i32.eqz
          br_if 1 (;@2;)
          block  ;; label = @4
            block  ;; label = @5
              local.get 1
              i32.load offset=28
              local.tee 4
              i32.const 2
              i32.shl
              i32.const 4304
              i32.add
              local.tee 2
              i32.load
              local.get 1
              i32.ne
              br_if 0 (;@5;)
              local.get 2
              local.get 5
              i32.store
              local.get 5
              br_if 1 (;@4;)
              i32.const 0
              i32.const 0
              i32.load offset=4004
              i32.const -2
              local.get 4
              i32.rotl
              i32.and
              i32.store offset=4004
              br 3 (;@2;)
            end
            local.get 7
            i32.const 16
            i32.const 20
            local.get 7
            i32.load offset=16
            local.get 1
            i32.eq
            select
            i32.add
            local.get 5
            i32.store
            local.get 5
            i32.eqz
            br_if 2 (;@2;)
          end
          local.get 5
          local.get 7
          i32.store offset=24
          block  ;; label = @4
            local.get 1
            i32.load offset=16
            local.tee 2
            i32.eqz
            br_if 0 (;@4;)
            local.get 5
            local.get 2
            i32.store offset=16
            local.get 2
            local.get 5
            i32.store offset=24
          end
          local.get 1
          i32.load offset=20
          local.tee 2
          i32.eqz
          br_if 1 (;@2;)
          local.get 5
          i32.const 20
          i32.add
          local.get 2
          i32.store
          local.get 2
          local.get 5
          i32.store offset=24
          br 1 (;@2;)
        end
        local.get 3
        i32.load offset=4
        local.tee 2
        i32.const 3
        i32.and
        i32.const 3
        i32.ne
        br_if 0 (;@2;)
        local.get 3
        local.get 2
        i32.const -2
        i32.and
        i32.store offset=4
        i32.const 0
        local.get 0
        i32.store offset=4008
        local.get 1
        local.get 0
        i32.add
        local.get 0
        i32.store
        local.get 1
        local.get 0
        i32.const 1
        i32.or
        i32.store offset=4
        return
      end
      local.get 3
      local.get 1
      i32.le_u
      br_if 0 (;@1;)
      local.get 3
      i32.load offset=4
      local.tee 2
      i32.const 1
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        block  ;; label = @3
          local.get 2
          i32.const 2
          i32.and
          br_if 0 (;@3;)
          block  ;; label = @4
            i32.const 0
            i32.load offset=4024
            local.get 3
            i32.ne
            br_if 0 (;@4;)
            i32.const 0
            local.get 1
            i32.store offset=4024
            i32.const 0
            i32.const 0
            i32.load offset=4012
            local.get 0
            i32.add
            local.tee 0
            i32.store offset=4012
            local.get 1
            local.get 0
            i32.const 1
            i32.or
            i32.store offset=4
            local.get 1
            i32.const 0
            i32.load offset=4020
            i32.ne
            br_if 3 (;@1;)
            i32.const 0
            i32.const 0
            i32.store offset=4008
            i32.const 0
            i32.const 0
            i32.store offset=4020
            return
          end
          block  ;; label = @4
            i32.const 0
            i32.load offset=4020
            local.get 3
            i32.ne
            br_if 0 (;@4;)
            i32.const 0
            local.get 1
            i32.store offset=4020
            i32.const 0
            i32.const 0
            i32.load offset=4008
            local.get 0
            i32.add
            local.tee 0
            i32.store offset=4008
            local.get 1
            local.get 0
            i32.const 1
            i32.or
            i32.store offset=4
            local.get 1
            local.get 0
            i32.add
            local.get 0
            i32.store
            return
          end
          local.get 2
          i32.const -8
          i32.and
          local.get 0
          i32.add
          local.set 0
          block  ;; label = @4
            block  ;; label = @5
              local.get 2
              i32.const 255
              i32.gt_u
              br_if 0 (;@5;)
              local.get 3
              i32.load offset=12
              local.set 4
              block  ;; label = @6
                local.get 3
                i32.load offset=8
                local.tee 5
                local.get 2
                i32.const 3
                i32.shr_u
                local.tee 3
                i32.const 3
                i32.shl
                i32.const 4040
                i32.add
                local.tee 2
                i32.eq
                br_if 0 (;@6;)
                i32.const 0
                i32.load offset=4016
                local.get 5
                i32.gt_u
                drop
              end
              block  ;; label = @6
                local.get 4
                local.get 5
                i32.ne
                br_if 0 (;@6;)
                i32.const 0
                i32.const 0
                i32.load offset=4000
                i32.const -2
                local.get 3
                i32.rotl
                i32.and
                i32.store offset=4000
                br 2 (;@4;)
              end
              block  ;; label = @6
                local.get 4
                local.get 2
                i32.eq
                br_if 0 (;@6;)
                i32.const 0
                i32.load offset=4016
                local.get 4
                i32.gt_u
                drop
              end
              local.get 4
              local.get 5
              i32.store offset=8
              local.get 5
              local.get 4
              i32.store offset=12
              br 1 (;@4;)
            end
            local.get 3
            i32.load offset=24
            local.set 7
            block  ;; label = @5
              block  ;; label = @6
                local.get 3
                i32.load offset=12
                local.tee 5
                local.get 3
                i32.eq
                br_if 0 (;@6;)
                block  ;; label = @7
                  i32.const 0
                  i32.load offset=4016
                  local.get 3
                  i32.load offset=8
                  local.tee 2
                  i32.gt_u
                  br_if 0 (;@7;)
                  local.get 2
                  i32.load offset=12
                  local.get 3
                  i32.ne
                  drop
                end
                local.get 5
                local.get 2
                i32.store offset=8
                local.get 2
                local.get 5
                i32.store offset=12
                br 1 (;@5;)
              end
              block  ;; label = @6
                local.get 3
                i32.const 20
                i32.add
                local.tee 2
                i32.load
                local.tee 4
                br_if 0 (;@6;)
                local.get 3
                i32.const 16
                i32.add
                local.tee 2
                i32.load
                local.tee 4
                br_if 0 (;@6;)
                i32.const 0
                local.set 5
                br 1 (;@5;)
              end
              loop  ;; label = @6
                local.get 2
                local.set 6
                local.get 4
                local.tee 5
                i32.const 20
                i32.add
                local.tee 2
                i32.load
                local.tee 4
                br_if 0 (;@6;)
                local.get 5
                i32.const 16
                i32.add
                local.set 2
                local.get 5
                i32.load offset=16
                local.tee 4
                br_if 0 (;@6;)
              end
              local.get 6
              i32.const 0
              i32.store
            end
            local.get 7
            i32.eqz
            br_if 0 (;@4;)
            block  ;; label = @5
              block  ;; label = @6
                local.get 3
                i32.load offset=28
                local.tee 4
                i32.const 2
                i32.shl
                i32.const 4304
                i32.add
                local.tee 2
                i32.load
                local.get 3
                i32.ne
                br_if 0 (;@6;)
                local.get 2
                local.get 5
                i32.store
                local.get 5
                br_if 1 (;@5;)
                i32.const 0
                i32.const 0
                i32.load offset=4004
                i32.const -2
                local.get 4
                i32.rotl
                i32.and
                i32.store offset=4004
                br 2 (;@4;)
              end
              local.get 7
              i32.const 16
              i32.const 20
              local.get 7
              i32.load offset=16
              local.get 3
              i32.eq
              select
              i32.add
              local.get 5
              i32.store
              local.get 5
              i32.eqz
              br_if 1 (;@4;)
            end
            local.get 5
            local.get 7
            i32.store offset=24
            block  ;; label = @5
              local.get 3
              i32.load offset=16
              local.tee 2
              i32.eqz
              br_if 0 (;@5;)
              local.get 5
              local.get 2
              i32.store offset=16
              local.get 2
              local.get 5
              i32.store offset=24
            end
            local.get 3
            i32.load offset=20
            local.tee 2
            i32.eqz
            br_if 0 (;@4;)
            local.get 5
            i32.const 20
            i32.add
            local.get 2
            i32.store
            local.get 2
            local.get 5
            i32.store offset=24
          end
          local.get 1
          local.get 0
          i32.add
          local.get 0
          i32.store
          local.get 1
          local.get 0
          i32.const 1
          i32.or
          i32.store offset=4
          local.get 1
          i32.const 0
          i32.load offset=4020
          i32.ne
          br_if 1 (;@2;)
          i32.const 0
          local.get 0
          i32.store offset=4008
          return
        end
        local.get 3
        local.get 2
        i32.const -2
        i32.and
        i32.store offset=4
        local.get 1
        local.get 0
        i32.add
        local.get 0
        i32.store
        local.get 1
        local.get 0
        i32.const 1
        i32.or
        i32.store offset=4
      end
      block  ;; label = @2
        local.get 0
        i32.const 255
        i32.gt_u
        br_if 0 (;@2;)
        local.get 0
        i32.const 3
        i32.shr_u
        local.tee 2
        i32.const 3
        i32.shl
        i32.const 4040
        i32.add
        local.set 0
        block  ;; label = @3
          block  ;; label = @4
            i32.const 0
            i32.load offset=4000
            local.tee 4
            i32.const 1
            local.get 2
            i32.shl
            local.tee 2
            i32.and
            br_if 0 (;@4;)
            i32.const 0
            local.get 4
            local.get 2
            i32.or
            i32.store offset=4000
            local.get 0
            local.set 2
            br 1 (;@3;)
          end
          local.get 0
          i32.load offset=8
          local.set 2
        end
        local.get 2
        local.get 1
        i32.store offset=12
        local.get 0
        local.get 1
        i32.store offset=8
        local.get 1
        local.get 0
        i32.store offset=12
        local.get 1
        local.get 2
        i32.store offset=8
        return
      end
      i32.const 0
      local.set 2
      block  ;; label = @2
        local.get 0
        i32.const 8
        i32.shr_u
        local.tee 4
        i32.eqz
        br_if 0 (;@2;)
        i32.const 31
        local.set 2
        local.get 0
        i32.const 16777215
        i32.gt_u
        br_if 0 (;@2;)
        local.get 4
        local.get 4
        i32.const 1048320
        i32.add
        i32.const 16
        i32.shr_u
        i32.const 8
        i32.and
        local.tee 2
        i32.shl
        local.tee 4
        local.get 4
        i32.const 520192
        i32.add
        i32.const 16
        i32.shr_u
        i32.const 4
        i32.and
        local.tee 4
        i32.shl
        local.tee 5
        local.get 5
        i32.const 245760
        i32.add
        i32.const 16
        i32.shr_u
        i32.const 2
        i32.and
        local.tee 5
        i32.shl
        i32.const 15
        i32.shr_u
        local.get 4
        local.get 2
        i32.or
        local.get 5
        i32.or
        i32.sub
        local.tee 2
        i32.const 1
        i32.shl
        local.get 0
        local.get 2
        i32.const 21
        i32.add
        i32.shr_u
        i32.const 1
        i32.and
        i32.or
        i32.const 28
        i32.add
        local.set 2
      end
      local.get 1
      i64.const 0
      i64.store offset=16 align=4
      local.get 1
      i32.const 28
      i32.add
      local.get 2
      i32.store
      local.get 2
      i32.const 2
      i32.shl
      i32.const 4304
      i32.add
      local.set 4
      block  ;; label = @2
        block  ;; label = @3
          i32.const 0
          i32.load offset=4004
          local.tee 5
          i32.const 1
          local.get 2
          i32.shl
          local.tee 3
          i32.and
          br_if 0 (;@3;)
          local.get 4
          local.get 1
          i32.store
          i32.const 0
          local.get 5
          local.get 3
          i32.or
          i32.store offset=4004
          local.get 1
          i32.const 24
          i32.add
          local.get 4
          i32.store
          local.get 1
          local.get 1
          i32.store offset=8
          local.get 1
          local.get 1
          i32.store offset=12
          br 1 (;@2;)
        end
        local.get 0
        i32.const 0
        i32.const 25
        local.get 2
        i32.const 1
        i32.shr_u
        i32.sub
        local.get 2
        i32.const 31
        i32.eq
        select
        i32.shl
        local.set 2
        local.get 4
        i32.load
        local.set 5
        block  ;; label = @3
          loop  ;; label = @4
            local.get 5
            local.tee 4
            i32.load offset=4
            i32.const -8
            i32.and
            local.get 0
            i32.eq
            br_if 1 (;@3;)
            local.get 2
            i32.const 29
            i32.shr_u
            local.set 5
            local.get 2
            i32.const 1
            i32.shl
            local.set 2
            local.get 4
            local.get 5
            i32.const 4
            i32.and
            i32.add
            i32.const 16
            i32.add
            local.tee 3
            i32.load
            local.tee 5
            br_if 0 (;@4;)
          end
          local.get 3
          local.get 1
          i32.store
          local.get 1
          i32.const 24
          i32.add
          local.get 4
          i32.store
          local.get 1
          local.get 1
          i32.store offset=12
          local.get 1
          local.get 1
          i32.store offset=8
          br 1 (;@2;)
        end
        local.get 4
        i32.load offset=8
        local.set 0
        local.get 4
        local.get 1
        i32.store offset=8
        local.get 0
        local.get 1
        i32.store offset=12
        local.get 1
        i32.const 24
        i32.add
        i32.const 0
        i32.store
        local.get 1
        local.get 0
        i32.store offset=8
        local.get 1
        local.get 4
        i32.store offset=12
      end
      i32.const 0
      i32.const 0
      i32.load offset=4032
      i32.const -1
      i32.add
      local.tee 1
      i32.store offset=4032
      local.get 1
      br_if 0 (;@1;)
      i32.const 4456
      local.set 1
      loop  ;; label = @2
        local.get 1
        i32.load
        local.tee 0
        i32.const 8
        i32.add
        local.set 1
        local.get 0
        br_if 0 (;@2;)
      end
      i32.const 0
      i32.const -1
      i32.store offset=4032
    end)
  (func $calloc (type 3) (param i32 i32) (result i32)
    (local i32 i64)
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        br_if 0 (;@2;)
        i32.const 0
        local.set 2
        br 1 (;@1;)
      end
      local.get 0
      i64.extend_i32_u
      local.get 1
      i64.extend_i32_u
      i64.mul
      local.tee 3
      i32.wrap_i64
      local.set 2
      local.get 1
      local.get 0
      i32.or
      i32.const 65536
      i32.lt_u
      br_if 0 (;@1;)
      i32.const -1
      local.get 2
      local.get 3
      i64.const 32
      i64.shr_u
      i32.wrap_i64
      i32.const 0
      i32.ne
      select
      local.set 2
    end
    block  ;; label = @1
      local.get 2
      call $dlmalloc
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      i32.const -4
      i32.add
      i32.load8_u
      i32.const 3
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      i32.const 0
      local.get 2
      call $memset
      drop
    end
    local.get 0)
  (func $__original_main (type 5) (result i32)
    call $__main_void)
  (func $__main_argc_argv (type 3) (param i32 i32) (result i32)
    local.get 0
    local.get 1
    call $main)
  (func $_Exit (type 2) (param i32)
    local.get 0
    call $__wasi_proc_exit
    unreachable)
  (func $__main_void (type 5) (result i32)
    (local i32 i32 i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 0
    global.set 0
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              local.get 0
              i32.const 8
              i32.add
              local.get 0
              i32.const 12
              i32.add
              call $__wasi_args_sizes_get
              br_if 0 (;@5;)
              local.get 0
              i32.load offset=8
              local.tee 1
              i32.const 1
              i32.add
              local.tee 2
              local.get 1
              i32.lt_u
              br_if 1 (;@4;)
              local.get 0
              i32.load offset=12
              call $malloc
              local.tee 3
              i32.eqz
              br_if 2 (;@3;)
              local.get 2
              i32.const 4
              call $calloc
              local.tee 1
              i32.eqz
              br_if 3 (;@2;)
              local.get 1
              local.get 3
              call $__wasi_args_get
              br_if 4 (;@1;)
              local.get 0
              i32.load offset=8
              local.get 1
              call $__main_argc_argv
              local.set 1
              local.get 0
              i32.const 16
              i32.add
              global.set 0
              local.get 1
              return
            end
            i32.const 71
            call $_Exit
            unreachable
          end
          i32.const 70
          call $_Exit
          unreachable
        end
        i32.const 70
        call $_Exit
        unreachable
      end
      local.get 3
      call $free
      i32.const 70
      call $_Exit
      unreachable
    end
    local.get 3
    call $free
    local.get 1
    call $free
    i32.const 71
    call $_Exit
    unreachable)
  (func $abort (type 8)
    unreachable
    unreachable)
  (func $sbrk (type 4) (param i32) (result i32)
    block  ;; label = @1
      local.get 0
      br_if 0 (;@1;)
      memory.size
      i32.const 16
      i32.shl
      return
    end
    block  ;; label = @1
      local.get 0
      i32.const 65535
      i32.and
      br_if 0 (;@1;)
      local.get 0
      i32.const -1
      i32.le_s
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 0
        i32.const 16
        i32.shr_u
        memory.grow
        local.tee 0
        i32.const -1
        i32.ne
        br_if 0 (;@2;)
        i32.const 0
        i32.const 48
        i32.store offset=4496
        i32.const -1
        return
      end
      local.get 0
      i32.const 16
      i32.shl
      return
    end
    call $abort
    unreachable)
  (func $dummy (type 8))
  (func $__prepare_for_exit (type 8)
    call $dummy
    call $__stdio_exit)
  (func $printf (type 3) (param i32 i32) (result i32)
    (local i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 2
    global.set 0
    local.get 2
    local.get 1
    i32.store offset=12
    i32.const 3752
    local.get 0
    local.get 1
    call $vfprintf
    local.set 1
    local.get 2
    i32.const 16
    i32.add
    global.set 0
    local.get 1)
  (func $strerror (type 4) (param i32) (result i32)
    (local i32 i32 i32 i32)
    i32.const 0
    local.set 1
    block  ;; label = @1
      i32.const 0
      i32.load offset=4524
      local.tee 2
      br_if 0 (;@1;)
      i32.const 4500
      local.set 2
      i32.const 0
      i32.const 4500
      i32.store offset=4524
    end
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          loop  ;; label = @4
            local.get 1
            i32.const 1200
            i32.add
            i32.load8_u
            local.get 0
            i32.eq
            br_if 1 (;@3;)
            i32.const 77
            local.set 3
            local.get 1
            i32.const 1
            i32.add
            local.tee 1
            i32.const 77
            i32.ne
            br_if 0 (;@4;)
            br 2 (;@2;)
          end
        end
        local.get 1
        local.set 3
        local.get 1
        br_if 0 (;@2;)
        i32.const 1280
        local.set 4
        br 1 (;@1;)
      end
      i32.const 1280
      local.set 1
      loop  ;; label = @2
        local.get 1
        i32.load8_u
        local.set 0
        local.get 1
        i32.const 1
        i32.add
        local.tee 4
        local.set 1
        local.get 0
        br_if 0 (;@2;)
        local.get 4
        local.set 1
        local.get 3
        i32.const -1
        i32.add
        local.tee 3
        br_if 0 (;@2;)
      end
    end
    local.get 4
    local.get 2
    i32.load offset=20
    call $__lctrans)
  (func $vfprintf (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32)
    global.get 0
    i32.const 208
    i32.sub
    local.tee 3
    global.set 0
    local.get 3
    local.get 2
    i32.store offset=204
    local.get 3
    i32.const 160
    i32.add
    i32.const 32
    i32.add
    i64.const 0
    i64.store
    local.get 3
    i32.const 184
    i32.add
    i64.const 0
    i64.store
    local.get 3
    i32.const 176
    i32.add
    i64.const 0
    i64.store
    local.get 3
    i64.const 0
    i64.store offset=168
    local.get 3
    i64.const 0
    i64.store offset=160
    local.get 3
    local.get 2
    i32.store offset=200
    block  ;; label = @1
      block  ;; label = @2
        i32.const 0
        local.get 1
        local.get 3
        i32.const 200
        i32.add
        local.get 3
        i32.const 80
        i32.add
        local.get 3
        i32.const 160
        i32.add
        call $printf_core
        i32.const 0
        i32.ge_s
        br_if 0 (;@2;)
        i32.const -1
        local.set 0
        br 1 (;@1;)
      end
      local.get 0
      i32.load
      local.set 4
      block  ;; label = @2
        local.get 0
        i32.load offset=60
        i32.const 0
        i32.gt_s
        br_if 0 (;@2;)
        local.get 0
        local.get 4
        i32.const -33
        i32.and
        i32.store
      end
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              local.get 0
              i32.load offset=44
              br_if 0 (;@5;)
              local.get 0
              i32.const 80
              i32.store offset=44
              local.get 0
              i32.const 0
              i32.store offset=24
              local.get 0
              i64.const 0
              i64.store offset=16
              local.get 0
              i32.load offset=40
              local.set 5
              local.get 0
              local.get 3
              i32.store offset=40
              br 1 (;@4;)
            end
            i32.const 0
            local.set 5
            local.get 0
            i32.load offset=16
            br_if 1 (;@3;)
          end
          i32.const -1
          local.set 2
          local.get 0
          call $__towrite
          br_if 1 (;@2;)
        end
        local.get 0
        local.get 1
        local.get 3
        i32.const 200
        i32.add
        local.get 3
        i32.const 80
        i32.add
        local.get 3
        i32.const 160
        i32.add
        call $printf_core
        local.set 2
      end
      local.get 4
      i32.const 32
      i32.and
      local.set 1
      block  ;; label = @2
        local.get 5
        i32.eqz
        br_if 0 (;@2;)
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=32
        call_indirect (type 0)
        drop
        local.get 0
        i32.const 0
        i32.store offset=44
        local.get 0
        local.get 5
        i32.store offset=40
        local.get 0
        i32.const 0
        i32.store offset=24
        local.get 0
        i32.const 0
        i32.store offset=16
        local.get 0
        i32.load offset=20
        local.set 5
        local.get 0
        i32.const 0
        i32.store offset=20
        local.get 2
        i32.const -1
        local.get 5
        select
        local.set 2
      end
      local.get 0
      local.get 0
      i32.load
      local.tee 5
      local.get 1
      i32.or
      i32.store
      i32.const -1
      local.get 2
      local.get 5
      i32.const 32
      i32.and
      select
      local.set 0
    end
    local.get 3
    i32.const 208
    i32.add
    global.set 0
    local.get 0)
  (func $printf_core (type 9) (param i32 i32 i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i64 i64 f64 i32 i32 f64 i32 i32 i32 i32)
    global.get 0
    i32.const 880
    i32.sub
    local.tee 5
    global.set 0
    local.get 5
    i32.const 336
    i32.add
    i32.const 8
    i32.or
    local.set 6
    local.get 5
    i32.const 55
    i32.add
    local.set 7
    i32.const -2
    local.get 5
    i32.const 336
    i32.add
    i32.sub
    local.set 8
    local.get 5
    i32.const 336
    i32.add
    i32.const 9
    i32.or
    local.set 9
    local.get 5
    i32.const 656
    i32.add
    local.set 10
    local.get 5
    i32.const 324
    i32.add
    i32.const 12
    i32.add
    local.set 11
    i32.const 0
    local.get 5
    i32.const 336
    i32.add
    i32.sub
    local.set 12
    local.get 5
    i32.const 56
    i32.add
    local.set 13
    i32.const 0
    local.set 14
    i32.const 0
    local.set 15
    i32.const 0
    local.set 16
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          loop  ;; label = @4
            local.get 1
            local.set 17
            local.get 16
            i32.const 2147483647
            local.get 15
            i32.sub
            i32.gt_s
            br_if 1 (;@3;)
            local.get 16
            local.get 15
            i32.add
            local.set 15
            block  ;; label = @5
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    local.get 17
                    i32.load8_u
                    local.tee 16
                    i32.eqz
                    br_if 0 (;@8;)
                    local.get 17
                    local.set 1
                    loop  ;; label = @9
                      block  ;; label = @10
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 16
                            i32.const 255
                            i32.and
                            local.tee 16
                            i32.eqz
                            br_if 0 (;@12;)
                            local.get 16
                            i32.const 37
                            i32.ne
                            br_if 2 (;@10;)
                            local.get 1
                            local.set 18
                            local.get 1
                            local.set 16
                            loop  ;; label = @13
                              block  ;; label = @14
                                local.get 16
                                i32.const 1
                                i32.add
                                i32.load8_u
                                i32.const 37
                                i32.eq
                                br_if 0 (;@14;)
                                local.get 16
                                local.set 1
                                br 3 (;@11;)
                              end
                              local.get 18
                              i32.const 1
                              i32.add
                              local.set 18
                              local.get 16
                              i32.load8_u offset=2
                              local.set 19
                              local.get 16
                              i32.const 2
                              i32.add
                              local.tee 1
                              local.set 16
                              local.get 19
                              i32.const 37
                              i32.eq
                              br_if 0 (;@13;)
                              br 2 (;@11;)
                            end
                          end
                          local.get 1
                          local.set 18
                        end
                        local.get 18
                        local.get 17
                        i32.sub
                        local.tee 16
                        i32.const 2147483647
                        local.get 15
                        i32.sub
                        local.tee 19
                        i32.gt_s
                        br_if 7 (;@3;)
                        block  ;; label = @11
                          local.get 0
                          i32.eqz
                          br_if 0 (;@11;)
                          local.get 0
                          i32.load8_u
                          i32.const 32
                          i32.and
                          br_if 0 (;@11;)
                          local.get 17
                          local.get 16
                          local.get 0
                          call $__fwritex
                          drop
                        end
                        local.get 16
                        br_if 6 (;@4;)
                        local.get 1
                        i32.const 1
                        i32.add
                        local.set 16
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 1
                            i32.load8_s offset=1
                            local.tee 20
                            i32.const -48
                            i32.add
                            local.tee 21
                            i32.const 9
                            i32.le_u
                            br_if 0 (;@12;)
                            i32.const -1
                            local.set 22
                            br 1 (;@11;)
                          end
                          local.get 1
                          i32.const 3
                          i32.add
                          local.get 16
                          local.get 1
                          i32.load8_u offset=2
                          i32.const 36
                          i32.eq
                          local.tee 18
                          select
                          local.set 16
                          local.get 21
                          i32.const -1
                          local.get 18
                          select
                          local.set 22
                          i32.const 1
                          local.get 14
                          local.get 18
                          select
                          local.set 14
                          local.get 1
                          i32.const 3
                          i32.const 1
                          local.get 18
                          select
                          i32.add
                          i32.load8_s
                          local.set 20
                        end
                        i32.const 0
                        local.set 18
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 20
                            i32.const -32
                            i32.add
                            local.tee 1
                            i32.const 31
                            i32.le_u
                            br_if 0 (;@12;)
                            local.get 16
                            local.set 1
                            br 1 (;@11;)
                          end
                          block  ;; label = @12
                            i32.const 1
                            local.get 1
                            i32.shl
                            local.tee 21
                            i32.const 75913
                            i32.and
                            br_if 0 (;@12;)
                            local.get 16
                            local.set 1
                            br 1 (;@11;)
                          end
                          i32.const 0
                          local.set 18
                          loop  ;; label = @12
                            local.get 16
                            i32.const 1
                            i32.add
                            local.set 1
                            local.get 21
                            local.get 18
                            i32.or
                            local.set 18
                            local.get 16
                            i32.load8_s offset=1
                            local.tee 20
                            i32.const -32
                            i32.add
                            local.tee 21
                            i32.const 31
                            i32.gt_u
                            br_if 1 (;@11;)
                            local.get 1
                            local.set 16
                            i32.const 1
                            local.get 21
                            i32.shl
                            local.tee 21
                            i32.const 75913
                            i32.and
                            br_if 0 (;@12;)
                          end
                        end
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 20
                            i32.const 42
                            i32.ne
                            br_if 0 (;@12;)
                            block  ;; label = @13
                              block  ;; label = @14
                                local.get 1
                                i32.load8_s offset=1
                                i32.const -48
                                i32.add
                                local.tee 16
                                i32.const 9
                                i32.gt_u
                                br_if 0 (;@14;)
                                local.get 1
                                i32.load8_u offset=2
                                i32.const 36
                                i32.ne
                                br_if 0 (;@14;)
                                local.get 4
                                local.get 16
                                i32.const 2
                                i32.shl
                                i32.add
                                i32.const 10
                                i32.store
                                local.get 1
                                i32.const 3
                                i32.add
                                local.set 23
                                local.get 1
                                i32.load8_s offset=1
                                i32.const 3
                                i32.shl
                                local.get 3
                                i32.add
                                i32.const -384
                                i32.add
                                i32.load
                                local.set 24
                                i32.const 1
                                local.set 14
                                br 1 (;@13;)
                              end
                              local.get 14
                              br_if 6 (;@7;)
                              local.get 1
                              i32.const 1
                              i32.add
                              local.set 23
                              block  ;; label = @14
                                local.get 0
                                br_if 0 (;@14;)
                                i32.const 0
                                local.set 14
                                i32.const 0
                                local.set 24
                                br 3 (;@11;)
                              end
                              local.get 2
                              local.get 2
                              i32.load
                              local.tee 1
                              i32.const 4
                              i32.add
                              i32.store
                              local.get 1
                              i32.load
                              local.set 24
                              i32.const 0
                              local.set 14
                            end
                            local.get 24
                            i32.const -1
                            i32.gt_s
                            br_if 1 (;@11;)
                            i32.const 0
                            local.get 24
                            i32.sub
                            local.set 24
                            local.get 18
                            i32.const 8192
                            i32.or
                            local.set 18
                            br 1 (;@11;)
                          end
                          i32.const 0
                          local.set 24
                          block  ;; label = @12
                            local.get 20
                            i32.const -48
                            i32.add
                            local.tee 21
                            i32.const 9
                            i32.le_u
                            br_if 0 (;@12;)
                            local.get 1
                            local.set 23
                            br 1 (;@11;)
                          end
                          i32.const 0
                          local.set 16
                          loop  ;; label = @12
                            i32.const -1
                            local.set 24
                            block  ;; label = @13
                              local.get 16
                              i32.const 214748364
                              i32.gt_u
                              br_if 0 (;@13;)
                              i32.const -1
                              local.get 16
                              i32.const 10
                              i32.mul
                              local.tee 16
                              local.get 21
                              i32.add
                              local.get 21
                              i32.const 2147483647
                              local.get 16
                              i32.sub
                              i32.gt_s
                              select
                              local.set 24
                            end
                            local.get 1
                            i32.load8_s offset=1
                            local.set 21
                            local.get 1
                            i32.const 1
                            i32.add
                            local.tee 23
                            local.set 1
                            local.get 24
                            local.set 16
                            local.get 21
                            i32.const -48
                            i32.add
                            local.tee 21
                            i32.const 10
                            i32.lt_u
                            br_if 0 (;@12;)
                          end
                          local.get 24
                          i32.const 0
                          i32.lt_s
                          br_if 8 (;@3;)
                        end
                        i32.const 0
                        local.set 16
                        i32.const -1
                        local.set 20
                        block  ;; label = @11
                          block  ;; label = @12
                            local.get 23
                            i32.load8_u
                            i32.const 46
                            i32.eq
                            br_if 0 (;@12;)
                            local.get 23
                            local.set 1
                            i32.const 0
                            local.set 25
                            br 1 (;@11;)
                          end
                          block  ;; label = @12
                            local.get 23
                            i32.load8_s offset=1
                            local.tee 21
                            i32.const 42
                            i32.ne
                            br_if 0 (;@12;)
                            block  ;; label = @13
                              block  ;; label = @14
                                local.get 23
                                i32.load8_s offset=2
                                i32.const -48
                                i32.add
                                local.tee 1
                                i32.const 9
                                i32.gt_u
                                br_if 0 (;@14;)
                                local.get 23
                                i32.load8_u offset=3
                                i32.const 36
                                i32.ne
                                br_if 0 (;@14;)
                                local.get 4
                                local.get 1
                                i32.const 2
                                i32.shl
                                i32.add
                                i32.const 10
                                i32.store
                                local.get 23
                                i32.const 4
                                i32.add
                                local.set 1
                                local.get 23
                                i32.load8_s offset=2
                                i32.const 3
                                i32.shl
                                local.get 3
                                i32.add
                                i32.const -384
                                i32.add
                                i32.load
                                local.set 20
                                br 1 (;@13;)
                              end
                              local.get 14
                              br_if 6 (;@7;)
                              local.get 23
                              i32.const 2
                              i32.add
                              local.set 1
                              block  ;; label = @14
                                local.get 0
                                br_if 0 (;@14;)
                                i32.const 0
                                local.set 20
                                br 1 (;@13;)
                              end
                              local.get 2
                              local.get 2
                              i32.load
                              local.tee 21
                              i32.const 4
                              i32.add
                              i32.store
                              local.get 21
                              i32.load
                              local.set 20
                            end
                            local.get 20
                            i32.const -1
                            i32.xor
                            i32.const 31
                            i32.shr_u
                            local.set 25
                            br 1 (;@11;)
                          end
                          local.get 23
                          i32.const 1
                          i32.add
                          local.set 1
                          block  ;; label = @12
                            local.get 21
                            i32.const -48
                            i32.add
                            local.tee 26
                            i32.const 9
                            i32.le_u
                            br_if 0 (;@12;)
                            i32.const 1
                            local.set 25
                            i32.const 0
                            local.set 20
                            br 1 (;@11;)
                          end
                          i32.const 0
                          local.set 23
                          local.get 1
                          local.set 21
                          loop  ;; label = @12
                            i32.const -1
                            local.set 20
                            block  ;; label = @13
                              local.get 23
                              i32.const 214748364
                              i32.gt_u
                              br_if 0 (;@13;)
                              i32.const -1
                              local.get 23
                              i32.const 10
                              i32.mul
                              local.tee 1
                              local.get 26
                              i32.add
                              local.get 26
                              i32.const 2147483647
                              local.get 1
                              i32.sub
                              i32.gt_s
                              select
                              local.set 20
                            end
                            i32.const 1
                            local.set 25
                            local.get 21
                            i32.load8_s offset=1
                            local.set 26
                            local.get 21
                            i32.const 1
                            i32.add
                            local.tee 1
                            local.set 21
                            local.get 20
                            local.set 23
                            local.get 26
                            i32.const -48
                            i32.add
                            local.tee 26
                            i32.const 10
                            i32.lt_u
                            br_if 0 (;@12;)
                          end
                        end
                        loop  ;; label = @11
                          local.get 16
                          local.set 21
                          local.get 1
                          i32.load8_s
                          i32.const -65
                          i32.add
                          local.tee 16
                          i32.const 57
                          i32.gt_u
                          br_if 4 (;@7;)
                          local.get 1
                          i32.const 1
                          i32.add
                          local.set 1
                          local.get 21
                          i32.const 58
                          i32.mul
                          local.get 16
                          i32.add
                          i32.const 2880
                          i32.add
                          i32.load8_u
                          local.tee 16
                          i32.const -1
                          i32.add
                          i32.const 8
                          i32.lt_u
                          br_if 0 (;@11;)
                        end
                        local.get 16
                        i32.eqz
                        br_if 3 (;@7;)
                        block  ;; label = @11
                          block  ;; label = @12
                            block  ;; label = @13
                              block  ;; label = @14
                                local.get 16
                                i32.const 27
                                i32.ne
                                br_if 0 (;@14;)
                                local.get 22
                                i32.const -1
                                i32.le_s
                                br_if 1 (;@13;)
                                br 7 (;@7;)
                              end
                              local.get 22
                              i32.const 0
                              i32.lt_s
                              br_if 1 (;@12;)
                              local.get 4
                              local.get 22
                              i32.const 2
                              i32.shl
                              i32.add
                              local.get 16
                              i32.store
                              local.get 5
                              local.get 3
                              local.get 22
                              i32.const 3
                              i32.shl
                              i32.add
                              i64.load
                              i64.store offset=56
                            end
                            i32.const 0
                            local.set 16
                            local.get 0
                            i32.eqz
                            br_if 8 (;@4;)
                            br 1 (;@11;)
                          end
                          block  ;; label = @12
                            local.get 0
                            br_if 0 (;@12;)
                            i32.const 0
                            local.set 15
                            br 11 (;@1;)
                          end
                          local.get 5
                          i32.const 56
                          i32.add
                          local.get 16
                          local.get 2
                          call $pop_arg
                        end
                        local.get 18
                        i32.const -65537
                        i32.and
                        local.tee 23
                        local.get 18
                        local.get 18
                        i32.const 8192
                        i32.and
                        select
                        local.set 22
                        block  ;; label = @11
                          block  ;; label = @12
                            block  ;; label = @13
                              local.get 1
                              i32.const -1
                              i32.add
                              i32.load8_s
                              local.tee 16
                              i32.const -33
                              i32.and
                              local.get 16
                              local.get 16
                              i32.const 15
                              i32.and
                              i32.const 3
                              i32.eq
                              select
                              local.get 16
                              local.get 21
                              select
                              local.tee 27
                              i32.const -65
                              i32.add
                              local.tee 16
                              i32.const 55
                              i32.gt_u
                              br_if 0 (;@13;)
                              block  ;; label = @14
                                block  ;; label = @15
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          block  ;; label = @20
                                            block  ;; label = @21
                                              block  ;; label = @22
                                                block  ;; label = @23
                                                  block  ;; label = @24
                                                    block  ;; label = @25
                                                      block  ;; label = @26
                                                        block  ;; label = @27
                                                          block  ;; label = @28
                                                            block  ;; label = @29
                                                              block  ;; label = @30
                                                                local.get 16
                                                                br_table 16 (;@14;) 17 (;@13;) 13 (;@17;) 17 (;@13;) 16 (;@14;) 16 (;@14;) 16 (;@14;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 12 (;@18;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 3 (;@27;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 16 (;@14;) 17 (;@13;) 8 (;@22;) 5 (;@25;) 16 (;@14;) 16 (;@14;) 16 (;@14;) 17 (;@13;) 5 (;@25;) 17 (;@13;) 17 (;@13;) 17 (;@13;) 9 (;@21;) 1 (;@29;) 4 (;@26;) 2 (;@28;) 17 (;@13;) 17 (;@13;) 10 (;@20;) 17 (;@13;) 0 (;@30;) 17 (;@13;) 17 (;@13;) 3 (;@27;) 16 (;@14;)
                                                              end
                                                              i32.const 0
                                                              local.set 28
                                                              i32.const 2854
                                                              local.set 29
                                                              local.get 5
                                                              i64.load offset=56
                                                              local.set 30
                                                              br 5 (;@24;)
                                                            end
                                                            i32.const 0
                                                            local.set 16
                                                            local.get 21
                                                            i32.const 255
                                                            i32.and
                                                            local.tee 18
                                                            i32.const 7
                                                            i32.gt_u
                                                            br_if 24 (;@4;)
                                                            block  ;; label = @29
                                                              block  ;; label = @30
                                                                block  ;; label = @31
                                                                  block  ;; label = @32
                                                                    block  ;; label = @33
                                                                      block  ;; label = @34
                                                                        block  ;; label = @35
                                                                          local.get 18
                                                                          br_table 0 (;@35;) 1 (;@34;) 2 (;@33;) 3 (;@32;) 4 (;@31;) 31 (;@4;) 5 (;@30;) 6 (;@29;) 0 (;@35;)
                                                                        end
                                                                        local.get 5
                                                                        i32.load offset=56
                                                                        local.get 15
                                                                        i32.store
                                                                        br 30 (;@4;)
                                                                      end
                                                                      local.get 5
                                                                      i32.load offset=56
                                                                      local.get 15
                                                                      i32.store
                                                                      br 29 (;@4;)
                                                                    end
                                                                    local.get 5
                                                                    i32.load offset=56
                                                                    local.get 15
                                                                    i64.extend_i32_s
                                                                    i64.store
                                                                    br 28 (;@4;)
                                                                  end
                                                                  local.get 5
                                                                  i32.load offset=56
                                                                  local.get 15
                                                                  i32.store16
                                                                  br 27 (;@4;)
                                                                end
                                                                local.get 5
                                                                i32.load offset=56
                                                                local.get 15
                                                                i32.store8
                                                                br 26 (;@4;)
                                                              end
                                                              local.get 5
                                                              i32.load offset=56
                                                              local.get 15
                                                              i32.store
                                                              br 25 (;@4;)
                                                            end
                                                            local.get 5
                                                            i32.load offset=56
                                                            local.get 15
                                                            i64.extend_i32_s
                                                            i64.store
                                                            br 24 (;@4;)
                                                          end
                                                          local.get 20
                                                          i32.const 8
                                                          local.get 20
                                                          i32.const 8
                                                          i32.gt_u
                                                          select
                                                          local.set 20
                                                          local.get 22
                                                          i32.const 8
                                                          i32.or
                                                          local.set 22
                                                          i32.const 120
                                                          local.set 27
                                                        end
                                                        i32.const 0
                                                        local.set 28
                                                        i32.const 2854
                                                        local.set 29
                                                        block  ;; label = @27
                                                          local.get 5
                                                          i64.load offset=56
                                                          local.tee 30
                                                          i64.eqz
                                                          i32.eqz
                                                          br_if 0 (;@27;)
                                                          local.get 13
                                                          local.set 17
                                                          br 4 (;@23;)
                                                        end
                                                        local.get 27
                                                        i32.const 32
                                                        i32.and
                                                        local.set 16
                                                        local.get 13
                                                        local.set 17
                                                        loop  ;; label = @27
                                                          local.get 17
                                                          i32.const -1
                                                          i32.add
                                                          local.tee 17
                                                          local.get 30
                                                          i32.wrap_i64
                                                          i32.const 15
                                                          i32.and
                                                          i32.const 3488
                                                          i32.add
                                                          i32.load8_u
                                                          local.get 16
                                                          i32.or
                                                          i32.store8
                                                          local.get 30
                                                          i64.const 4
                                                          i64.shr_u
                                                          local.tee 30
                                                          i64.const 0
                                                          i64.ne
                                                          br_if 0 (;@27;)
                                                        end
                                                        local.get 22
                                                        i32.const 8
                                                        i32.and
                                                        i32.eqz
                                                        br_if 3 (;@23;)
                                                        local.get 5
                                                        i64.load offset=56
                                                        i64.eqz
                                                        br_if 3 (;@23;)
                                                        local.get 27
                                                        i32.const 4
                                                        i32.shr_s
                                                        i32.const 2854
                                                        i32.add
                                                        local.set 29
                                                        i32.const 2
                                                        local.set 28
                                                        br 3 (;@23;)
                                                      end
                                                      local.get 13
                                                      local.set 17
                                                      block  ;; label = @26
                                                        local.get 5
                                                        i64.load offset=56
                                                        local.tee 30
                                                        i64.eqz
                                                        br_if 0 (;@26;)
                                                        local.get 13
                                                        local.set 17
                                                        loop  ;; label = @27
                                                          local.get 17
                                                          i32.const -1
                                                          i32.add
                                                          local.tee 17
                                                          local.get 30
                                                          i32.wrap_i64
                                                          i32.const 7
                                                          i32.and
                                                          i32.const 48
                                                          i32.or
                                                          i32.store8
                                                          local.get 30
                                                          i64.const 3
                                                          i64.shr_u
                                                          local.tee 30
                                                          i64.const 0
                                                          i64.ne
                                                          br_if 0 (;@27;)
                                                        end
                                                      end
                                                      i32.const 0
                                                      local.set 28
                                                      i32.const 2854
                                                      local.set 29
                                                      local.get 22
                                                      i32.const 8
                                                      i32.and
                                                      i32.eqz
                                                      br_if 2 (;@23;)
                                                      local.get 20
                                                      local.get 13
                                                      local.get 17
                                                      i32.sub
                                                      local.tee 16
                                                      i32.const 1
                                                      i32.add
                                                      local.get 20
                                                      local.get 16
                                                      i32.gt_s
                                                      select
                                                      local.set 20
                                                      br 2 (;@23;)
                                                    end
                                                    block  ;; label = @25
                                                      local.get 5
                                                      i64.load offset=56
                                                      local.tee 30
                                                      i64.const -1
                                                      i64.gt_s
                                                      br_if 0 (;@25;)
                                                      local.get 5
                                                      i64.const 0
                                                      local.get 30
                                                      i64.sub
                                                      local.tee 30
                                                      i64.store offset=56
                                                      i32.const 1
                                                      local.set 28
                                                      i32.const 2854
                                                      local.set 29
                                                      br 1 (;@24;)
                                                    end
                                                    block  ;; label = @25
                                                      local.get 22
                                                      i32.const 2048
                                                      i32.and
                                                      i32.eqz
                                                      br_if 0 (;@25;)
                                                      i32.const 1
                                                      local.set 28
                                                      i32.const 2855
                                                      local.set 29
                                                      br 1 (;@24;)
                                                    end
                                                    i32.const 2856
                                                    i32.const 2854
                                                    local.get 22
                                                    i32.const 1
                                                    i32.and
                                                    local.tee 28
                                                    select
                                                    local.set 29
                                                  end
                                                  block  ;; label = @24
                                                    block  ;; label = @25
                                                      local.get 30
                                                      i64.const 4294967296
                                                      i64.ge_u
                                                      br_if 0 (;@25;)
                                                      local.get 30
                                                      local.set 31
                                                      local.get 13
                                                      local.set 17
                                                      br 1 (;@24;)
                                                    end
                                                    local.get 13
                                                    local.set 17
                                                    loop  ;; label = @25
                                                      local.get 17
                                                      i32.const -1
                                                      i32.add
                                                      local.tee 17
                                                      local.get 30
                                                      local.get 30
                                                      i64.const 10
                                                      i64.div_u
                                                      local.tee 31
                                                      i64.const 10
                                                      i64.mul
                                                      i64.sub
                                                      i32.wrap_i64
                                                      i32.const 48
                                                      i32.or
                                                      i32.store8
                                                      local.get 30
                                                      i64.const 42949672959
                                                      i64.gt_u
                                                      local.set 16
                                                      local.get 31
                                                      local.set 30
                                                      local.get 16
                                                      br_if 0 (;@25;)
                                                    end
                                                  end
                                                  local.get 31
                                                  i32.wrap_i64
                                                  local.tee 16
                                                  i32.eqz
                                                  br_if 0 (;@23;)
                                                  loop  ;; label = @24
                                                    local.get 17
                                                    i32.const -1
                                                    i32.add
                                                    local.tee 17
                                                    local.get 16
                                                    local.get 16
                                                    i32.const 10
                                                    i32.div_u
                                                    local.tee 18
                                                    i32.const 10
                                                    i32.mul
                                                    i32.sub
                                                    i32.const 48
                                                    i32.or
                                                    i32.store8
                                                    local.get 16
                                                    i32.const 9
                                                    i32.gt_u
                                                    local.set 21
                                                    local.get 18
                                                    local.set 16
                                                    local.get 21
                                                    br_if 0 (;@24;)
                                                  end
                                                end
                                                block  ;; label = @23
                                                  local.get 25
                                                  i32.eqz
                                                  br_if 0 (;@23;)
                                                  local.get 20
                                                  i32.const 0
                                                  i32.lt_s
                                                  br_if 20 (;@3;)
                                                end
                                                local.get 22
                                                i32.const -65537
                                                i32.and
                                                local.get 22
                                                local.get 25
                                                select
                                                local.set 22
                                                local.get 5
                                                i64.load offset=56
                                                local.set 30
                                                block  ;; label = @23
                                                  local.get 20
                                                  br_if 0 (;@23;)
                                                  local.get 30
                                                  i64.eqz
                                                  i32.eqz
                                                  br_if 0 (;@23;)
                                                  local.get 13
                                                  local.set 17
                                                  local.get 13
                                                  local.set 16
                                                  i32.const 0
                                                  local.set 20
                                                  br 18 (;@5;)
                                                end
                                                local.get 20
                                                local.get 13
                                                local.get 17
                                                i32.sub
                                                local.get 30
                                                i64.eqz
                                                i32.add
                                                local.tee 16
                                                local.get 20
                                                local.get 16
                                                i32.gt_s
                                                select
                                                local.set 20
                                                br 10 (;@12;)
                                              end
                                              local.get 5
                                              local.get 5
                                              i64.load offset=56
                                              i64.store8 offset=55
                                              i32.const 0
                                              local.set 28
                                              i32.const 2854
                                              local.set 29
                                              i32.const 1
                                              local.set 20
                                              local.get 7
                                              local.set 17
                                              local.get 13
                                              local.set 16
                                              local.get 23
                                              local.set 22
                                              br 16 (;@5;)
                                            end
                                            i32.const 0
                                            i32.load offset=4496
                                            call $strerror
                                            local.set 17
                                            br 1 (;@19;)
                                          end
                                          local.get 5
                                          i32.load offset=56
                                          local.tee 16
                                          i32.const 2864
                                          local.get 16
                                          select
                                          local.set 17
                                        end
                                        i32.const 0
                                        local.set 28
                                        local.get 17
                                        local.get 17
                                        i32.const 2147483647
                                        local.get 20
                                        local.get 20
                                        i32.const 0
                                        i32.lt_s
                                        select
                                        call $strnlen
                                        local.tee 18
                                        i32.add
                                        local.set 16
                                        i32.const 2854
                                        local.set 29
                                        local.get 20
                                        i32.const -1
                                        i32.le_s
                                        br_if 7 (;@11;)
                                        local.get 23
                                        local.set 22
                                        local.get 18
                                        local.set 20
                                        br 13 (;@5;)
                                      end
                                      local.get 5
                                      i32.load offset=56
                                      local.set 17
                                      local.get 20
                                      br_if 1 (;@16;)
                                      i32.const 0
                                      local.set 16
                                      br 2 (;@15;)
                                    end
                                    local.get 5
                                    i32.const 0
                                    i32.store offset=12
                                    local.get 5
                                    local.get 5
                                    i64.load offset=56
                                    i64.store32 offset=8
                                    local.get 5
                                    local.get 5
                                    i32.const 8
                                    i32.add
                                    i32.store offset=56
                                    i32.const -1
                                    local.set 20
                                    local.get 5
                                    i32.const 8
                                    i32.add
                                    local.set 17
                                  end
                                  i32.const 0
                                  local.set 16
                                  local.get 17
                                  local.set 18
                                  block  ;; label = @16
                                    loop  ;; label = @17
                                      local.get 18
                                      i32.load
                                      local.tee 19
                                      i32.eqz
                                      br_if 1 (;@16;)
                                      block  ;; label = @18
                                        local.get 5
                                        i32.const 4
                                        i32.add
                                        local.get 19
                                        call $wctomb
                                        local.tee 19
                                        i32.const 0
                                        i32.lt_s
                                        local.tee 21
                                        br_if 0 (;@18;)
                                        local.get 19
                                        local.get 20
                                        local.get 16
                                        i32.sub
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.const 4
                                        i32.add
                                        local.set 18
                                        local.get 20
                                        local.get 19
                                        local.get 16
                                        i32.add
                                        local.tee 16
                                        i32.gt_u
                                        br_if 1 (;@17;)
                                        br 2 (;@16;)
                                      end
                                    end
                                    local.get 21
                                    br_if 14 (;@2;)
                                  end
                                  local.get 16
                                  i32.const 0
                                  i32.lt_s
                                  br_if 12 (;@3;)
                                end
                                block  ;; label = @15
                                  local.get 22
                                  i32.const 73728
                                  i32.and
                                  local.tee 23
                                  br_if 0 (;@15;)
                                  local.get 24
                                  local.get 16
                                  i32.le_s
                                  br_if 0 (;@15;)
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  i32.const 32
                                  local.get 24
                                  local.get 16
                                  i32.sub
                                  local.tee 26
                                  i32.const 256
                                  local.get 26
                                  i32.const 256
                                  i32.lt_u
                                  local.tee 18
                                  select
                                  call $memset
                                  drop
                                  local.get 0
                                  i32.load
                                  local.tee 21
                                  i32.const 32
                                  i32.and
                                  local.set 19
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 18
                                      br_if 0 (;@17;)
                                      local.get 19
                                      i32.eqz
                                      local.set 18
                                      local.get 26
                                      local.set 19
                                      loop  ;; label = @18
                                        block  ;; label = @19
                                          local.get 18
                                          i32.const 1
                                          i32.and
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          local.get 5
                                          i32.const 64
                                          i32.add
                                          i32.const 256
                                          local.get 0
                                          call $__fwritex
                                          drop
                                          local.get 0
                                          i32.load
                                          local.set 21
                                        end
                                        local.get 21
                                        i32.const 32
                                        i32.and
                                        local.tee 20
                                        i32.eqz
                                        local.set 18
                                        local.get 19
                                        i32.const -256
                                        i32.add
                                        local.tee 19
                                        i32.const 255
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 20
                                      br_if 2 (;@15;)
                                      local.get 26
                                      i32.const 255
                                      i32.and
                                      local.set 26
                                      br 1 (;@16;)
                                    end
                                    local.get 19
                                    br_if 1 (;@15;)
                                  end
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  local.get 26
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                block  ;; label = @15
                                  local.get 16
                                  i32.eqz
                                  br_if 0 (;@15;)
                                  i32.const 0
                                  local.set 18
                                  loop  ;; label = @16
                                    local.get 17
                                    i32.load
                                    local.tee 19
                                    i32.eqz
                                    br_if 1 (;@15;)
                                    local.get 5
                                    i32.const 4
                                    i32.add
                                    local.get 19
                                    call $wctomb
                                    local.tee 19
                                    local.get 18
                                    i32.add
                                    local.tee 18
                                    local.get 16
                                    i32.gt_u
                                    br_if 1 (;@15;)
                                    block  ;; label = @17
                                      local.get 0
                                      i32.load8_u
                                      i32.const 32
                                      i32.and
                                      br_if 0 (;@17;)
                                      local.get 5
                                      i32.const 4
                                      i32.add
                                      local.get 19
                                      local.get 0
                                      call $__fwritex
                                      drop
                                    end
                                    local.get 17
                                    i32.const 4
                                    i32.add
                                    local.set 17
                                    local.get 18
                                    local.get 16
                                    i32.lt_u
                                    br_if 0 (;@16;)
                                  end
                                end
                                block  ;; label = @15
                                  local.get 23
                                  i32.const 8192
                                  i32.ne
                                  br_if 0 (;@15;)
                                  local.get 24
                                  local.get 16
                                  i32.le_s
                                  br_if 0 (;@15;)
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  i32.const 32
                                  local.get 24
                                  local.get 16
                                  i32.sub
                                  local.tee 20
                                  i32.const 256
                                  local.get 20
                                  i32.const 256
                                  i32.lt_u
                                  local.tee 18
                                  select
                                  call $memset
                                  drop
                                  local.get 0
                                  i32.load
                                  local.tee 17
                                  i32.const 32
                                  i32.and
                                  local.set 19
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 18
                                      br_if 0 (;@17;)
                                      local.get 19
                                      i32.eqz
                                      local.set 18
                                      local.get 20
                                      local.set 19
                                      loop  ;; label = @18
                                        block  ;; label = @19
                                          local.get 18
                                          i32.const 1
                                          i32.and
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          local.get 5
                                          i32.const 64
                                          i32.add
                                          i32.const 256
                                          local.get 0
                                          call $__fwritex
                                          drop
                                          local.get 0
                                          i32.load
                                          local.set 17
                                        end
                                        local.get 17
                                        i32.const 32
                                        i32.and
                                        local.tee 21
                                        i32.eqz
                                        local.set 18
                                        local.get 19
                                        i32.const -256
                                        i32.add
                                        local.tee 19
                                        i32.const 255
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 21
                                      br_if 2 (;@15;)
                                      local.get 20
                                      i32.const 255
                                      i32.and
                                      local.set 20
                                      br 1 (;@16;)
                                    end
                                    local.get 19
                                    br_if 1 (;@15;)
                                  end
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  local.get 20
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                local.get 24
                                local.get 16
                                local.get 24
                                local.get 16
                                i32.gt_s
                                select
                                local.set 16
                                br 10 (;@4;)
                              end
                              block  ;; label = @14
                                local.get 20
                                i32.const -1
                                i32.gt_s
                                br_if 0 (;@14;)
                                local.get 25
                                br_if 11 (;@3;)
                              end
                              local.get 5
                              f64.load offset=56
                              local.set 32
                              local.get 5
                              i32.const 0
                              i32.store offset=364
                              block  ;; label = @14
                                block  ;; label = @15
                                  local.get 32
                                  i64.reinterpret_f64
                                  i64.const -1
                                  i64.gt_s
                                  br_if 0 (;@15;)
                                  local.get 32
                                  f64.neg
                                  local.set 32
                                  i32.const 1
                                  local.set 33
                                  i32.const 3504
                                  local.set 34
                                  br 1 (;@14;)
                                end
                                block  ;; label = @15
                                  local.get 22
                                  i32.const 2048
                                  i32.and
                                  i32.eqz
                                  br_if 0 (;@15;)
                                  i32.const 1
                                  local.set 33
                                  i32.const 3507
                                  local.set 34
                                  br 1 (;@14;)
                                end
                                i32.const 3510
                                i32.const 3505
                                local.get 22
                                i32.const 1
                                i32.and
                                local.tee 33
                                select
                                local.set 34
                              end
                              block  ;; label = @14
                                block  ;; label = @15
                                  local.get 32
                                  f64.abs
                                  local.tee 35
                                  f64.const inf (;=inf;)
                                  f64.ne
                                  local.get 35
                                  local.get 35
                                  f64.eq
                                  i32.and
                                  br_if 0 (;@15;)
                                  local.get 33
                                  i32.const 3
                                  i32.add
                                  local.set 21
                                  block  ;; label = @16
                                    local.get 22
                                    i32.const 8192
                                    i32.and
                                    br_if 0 (;@16;)
                                    local.get 24
                                    local.get 21
                                    i32.le_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 32
                                    local.get 24
                                    local.get 21
                                    i32.sub
                                    local.tee 20
                                    i32.const 256
                                    local.get 20
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 20
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 20
                                        i32.const 255
                                        i32.and
                                        local.set 20
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 20
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 0
                                    i32.load
                                    local.tee 16
                                    i32.const 32
                                    i32.and
                                    br_if 0 (;@16;)
                                    local.get 34
                                    local.get 33
                                    local.get 0
                                    call $__fwritex
                                    drop
                                    local.get 0
                                    i32.load
                                    local.set 16
                                  end
                                  block  ;; label = @16
                                    local.get 16
                                    i32.const 32
                                    i32.and
                                    br_if 0 (;@16;)
                                    i32.const 3531
                                    i32.const 3535
                                    local.get 27
                                    i32.const 32
                                    i32.and
                                    i32.const 5
                                    i32.shr_u
                                    local.tee 16
                                    select
                                    i32.const 3523
                                    i32.const 3527
                                    local.get 16
                                    select
                                    local.get 32
                                    local.get 32
                                    f64.ne
                                    select
                                    i32.const 3
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 22
                                    i32.const 73728
                                    i32.and
                                    i32.const 8192
                                    i32.ne
                                    br_if 0 (;@16;)
                                    local.get 24
                                    local.get 21
                                    i32.le_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 32
                                    local.get 24
                                    local.get 21
                                    i32.sub
                                    local.tee 20
                                    i32.const 256
                                    local.get 20
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 20
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 20
                                        i32.const 255
                                        i32.and
                                        local.set 20
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 20
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  local.get 24
                                  local.get 21
                                  local.get 24
                                  local.get 21
                                  i32.gt_s
                                  select
                                  local.set 16
                                  br 1 (;@14;)
                                end
                                block  ;; label = @15
                                  local.get 32
                                  local.get 5
                                  i32.const 364
                                  i32.add
                                  call $frexp
                                  local.tee 32
                                  local.get 32
                                  f64.add
                                  local.tee 32
                                  f64.const 0x0p+0 (;=0;)
                                  f64.eq
                                  br_if 0 (;@15;)
                                  local.get 5
                                  local.get 5
                                  i32.load offset=364
                                  i32.const -1
                                  i32.add
                                  i32.store offset=364
                                end
                                block  ;; label = @15
                                  local.get 27
                                  i32.const 32
                                  i32.or
                                  local.tee 29
                                  i32.const 97
                                  i32.ne
                                  br_if 0 (;@15;)
                                  local.get 34
                                  i32.const 9
                                  i32.add
                                  local.get 34
                                  local.get 27
                                  i32.const 32
                                  i32.and
                                  local.tee 21
                                  select
                                  local.set 28
                                  block  ;; label = @16
                                    local.get 20
                                    i32.const 11
                                    i32.gt_u
                                    br_if 0 (;@16;)
                                    i32.const 12
                                    local.get 20
                                    i32.sub
                                    i32.eqz
                                    br_if 0 (;@16;)
                                    local.get 20
                                    i32.const -12
                                    i32.add
                                    local.set 16
                                    f64.const 0x1p+4 (;=16;)
                                    local.set 35
                                    loop  ;; label = @17
                                      local.get 35
                                      f64.const 0x1p+4 (;=16;)
                                      f64.mul
                                      local.set 35
                                      local.get 16
                                      i32.const 1
                                      i32.add
                                      local.tee 18
                                      local.get 16
                                      i32.ge_u
                                      local.set 19
                                      local.get 18
                                      local.set 16
                                      local.get 19
                                      br_if 0 (;@17;)
                                    end
                                    block  ;; label = @17
                                      local.get 28
                                      i32.load8_u
                                      i32.const 45
                                      i32.ne
                                      br_if 0 (;@17;)
                                      local.get 35
                                      local.get 32
                                      f64.neg
                                      local.get 35
                                      f64.sub
                                      f64.add
                                      f64.neg
                                      local.set 32
                                      br 1 (;@16;)
                                    end
                                    local.get 32
                                    local.get 35
                                    f64.add
                                    local.get 35
                                    f64.sub
                                    local.set 32
                                  end
                                  local.get 11
                                  local.set 19
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 5
                                      i32.load offset=364
                                      local.tee 23
                                      local.get 23
                                      i32.const 31
                                      i32.shr_s
                                      local.tee 16
                                      i32.add
                                      local.get 16
                                      i32.xor
                                      local.tee 16
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      i32.const 0
                                      local.set 18
                                      loop  ;; label = @18
                                        local.get 5
                                        i32.const 324
                                        i32.add
                                        local.get 18
                                        i32.add
                                        i32.const 11
                                        i32.add
                                        local.get 16
                                        local.get 16
                                        i32.const 10
                                        i32.div_u
                                        local.tee 19
                                        i32.const 10
                                        i32.mul
                                        i32.sub
                                        i32.const 48
                                        i32.or
                                        i32.store8
                                        local.get 18
                                        i32.const -1
                                        i32.add
                                        local.set 18
                                        local.get 16
                                        i32.const 9
                                        i32.gt_u
                                        local.set 17
                                        local.get 19
                                        local.set 16
                                        local.get 17
                                        br_if 0 (;@18;)
                                      end
                                      local.get 5
                                      i32.const 324
                                      i32.add
                                      local.get 18
                                      i32.add
                                      i32.const 12
                                      i32.add
                                      local.set 19
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 19
                                    i32.const -1
                                    i32.add
                                    local.tee 19
                                    i32.const 48
                                    i32.store8
                                  end
                                  local.get 33
                                  i32.const 2
                                  i32.or
                                  local.set 26
                                  local.get 19
                                  i32.const -2
                                  i32.add
                                  local.tee 25
                                  local.get 27
                                  i32.const 15
                                  i32.add
                                  i32.store8
                                  local.get 19
                                  i32.const -1
                                  i32.add
                                  i32.const 45
                                  i32.const 43
                                  local.get 23
                                  i32.const 0
                                  i32.lt_s
                                  select
                                  i32.store8
                                  local.get 22
                                  i32.const 8
                                  i32.and
                                  local.set 19
                                  local.get 5
                                  i32.const 336
                                  i32.add
                                  local.set 18
                                  loop  ;; label = @16
                                    local.get 18
                                    local.set 16
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 32
                                        f64.abs
                                        f64.const 0x1p+31 (;=2.14748e+09;)
                                        f64.lt
                                        i32.eqz
                                        br_if 0 (;@18;)
                                        local.get 32
                                        i32.trunc_f64_s
                                        local.set 18
                                        br 1 (;@17;)
                                      end
                                      i32.const -2147483648
                                      local.set 18
                                    end
                                    local.get 16
                                    local.get 18
                                    i32.const 3488
                                    i32.add
                                    i32.load8_u
                                    local.get 21
                                    i32.or
                                    i32.store8
                                    local.get 32
                                    local.get 18
                                    f64.convert_i32_s
                                    f64.sub
                                    f64.const 0x1p+4 (;=16;)
                                    f64.mul
                                    local.set 32
                                    block  ;; label = @17
                                      local.get 16
                                      i32.const 1
                                      i32.add
                                      local.tee 18
                                      local.get 5
                                      i32.const 336
                                      i32.add
                                      i32.sub
                                      i32.const 1
                                      i32.ne
                                      br_if 0 (;@17;)
                                      block  ;; label = @18
                                        local.get 19
                                        br_if 0 (;@18;)
                                        local.get 20
                                        i32.const 0
                                        i32.gt_s
                                        br_if 0 (;@18;)
                                        local.get 32
                                        f64.const 0x0p+0 (;=0;)
                                        f64.eq
                                        br_if 1 (;@17;)
                                      end
                                      local.get 16
                                      i32.const 46
                                      i32.store8 offset=1
                                      local.get 16
                                      i32.const 2
                                      i32.add
                                      local.set 18
                                    end
                                    local.get 32
                                    f64.const 0x0p+0 (;=0;)
                                    f64.ne
                                    br_if 0 (;@16;)
                                  end
                                  i32.const -1
                                  local.set 16
                                  i32.const 2147483645
                                  local.get 26
                                  local.get 11
                                  local.get 25
                                  i32.sub
                                  local.tee 36
                                  i32.add
                                  local.tee 19
                                  i32.sub
                                  local.get 20
                                  i32.lt_s
                                  br_if 1 (;@14;)
                                  local.get 19
                                  local.get 20
                                  i32.const 2
                                  i32.add
                                  local.get 18
                                  local.get 5
                                  i32.const 336
                                  i32.add
                                  i32.sub
                                  local.tee 23
                                  local.get 8
                                  local.get 18
                                  i32.add
                                  local.get 20
                                  i32.lt_s
                                  select
                                  local.get 23
                                  local.get 20
                                  select
                                  local.tee 20
                                  i32.add
                                  local.set 21
                                  block  ;; label = @16
                                    local.get 22
                                    i32.const 73728
                                    i32.and
                                    local.tee 22
                                    br_if 0 (;@16;)
                                    local.get 24
                                    local.get 21
                                    i32.le_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 32
                                    local.get 24
                                    local.get 21
                                    i32.sub
                                    local.tee 27
                                    i32.const 256
                                    local.get 27
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 27
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 27
                                        i32.const 255
                                        i32.and
                                        local.set 27
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 27
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 0
                                    i32.load8_u
                                    i32.const 32
                                    i32.and
                                    br_if 0 (;@16;)
                                    local.get 28
                                    local.get 26
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 22
                                    i32.const 65536
                                    i32.ne
                                    br_if 0 (;@16;)
                                    local.get 24
                                    local.get 21
                                    i32.le_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 48
                                    local.get 24
                                    local.get 21
                                    i32.sub
                                    local.tee 26
                                    i32.const 256
                                    local.get 26
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 26
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 26
                                        i32.const 255
                                        i32.and
                                        local.set 26
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 26
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 0
                                    i32.load8_u
                                    i32.const 32
                                    i32.and
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 336
                                    i32.add
                                    local.get 23
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 20
                                    local.get 23
                                    i32.sub
                                    local.tee 20
                                    i32.const 1
                                    i32.lt_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 48
                                    local.get 20
                                    i32.const 256
                                    local.get 20
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 20
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 20
                                        i32.const 255
                                        i32.and
                                        local.set 20
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 20
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 0
                                    i32.load8_u
                                    i32.const 32
                                    i32.and
                                    br_if 0 (;@16;)
                                    local.get 25
                                    local.get 36
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  block  ;; label = @16
                                    local.get 22
                                    i32.const 8192
                                    i32.ne
                                    br_if 0 (;@16;)
                                    local.get 24
                                    local.get 21
                                    i32.le_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 32
                                    local.get 24
                                    local.get 21
                                    i32.sub
                                    local.tee 20
                                    i32.const 256
                                    local.get 20
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 20
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 20
                                        i32.const 255
                                        i32.and
                                        local.set 20
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 20
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  local.get 24
                                  local.get 21
                                  local.get 24
                                  local.get 21
                                  i32.gt_s
                                  select
                                  local.set 16
                                  br 1 (;@14;)
                                end
                                local.get 20
                                i32.const 0
                                i32.lt_s
                                local.set 16
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 32
                                    f64.const 0x0p+0 (;=0;)
                                    f64.ne
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.load offset=364
                                    local.set 17
                                    br 1 (;@15;)
                                  end
                                  local.get 5
                                  local.get 5
                                  i32.load offset=364
                                  i32.const -28
                                  i32.add
                                  local.tee 17
                                  i32.store offset=364
                                  local.get 32
                                  f64.const 0x1p+28 (;=2.68435e+08;)
                                  f64.mul
                                  local.set 32
                                end
                                i32.const 6
                                local.get 20
                                local.get 16
                                select
                                local.set 36
                                local.get 5
                                i32.const 368
                                i32.add
                                local.get 10
                                local.get 17
                                i32.const 0
                                i32.lt_s
                                select
                                local.tee 28
                                local.set 19
                                loop  ;; label = @15
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 32
                                      f64.const 0x1p+32 (;=4.29497e+09;)
                                      f64.lt
                                      local.get 32
                                      f64.const 0x0p+0 (;=0;)
                                      f64.ge
                                      i32.and
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      local.get 32
                                      i32.trunc_f64_u
                                      local.set 16
                                      br 1 (;@16;)
                                    end
                                    i32.const 0
                                    local.set 16
                                  end
                                  local.get 19
                                  local.get 16
                                  i32.store
                                  local.get 19
                                  i32.const 4
                                  i32.add
                                  local.set 19
                                  local.get 32
                                  local.get 16
                                  f64.convert_i32_u
                                  f64.sub
                                  f64.const 0x1.dcd65p+29 (;=1e+09;)
                                  f64.mul
                                  local.tee 32
                                  f64.const 0x0p+0 (;=0;)
                                  f64.ne
                                  br_if 0 (;@15;)
                                end
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 17
                                    i32.const 1
                                    i32.ge_s
                                    br_if 0 (;@16;)
                                    local.get 19
                                    local.set 16
                                    local.get 28
                                    local.set 18
                                    br 1 (;@15;)
                                  end
                                  local.get 28
                                  local.set 18
                                  loop  ;; label = @16
                                    local.get 17
                                    i32.const 29
                                    local.get 17
                                    i32.const 29
                                    i32.lt_s
                                    select
                                    local.set 17
                                    block  ;; label = @17
                                      local.get 19
                                      i32.const -4
                                      i32.add
                                      local.tee 16
                                      local.get 18
                                      i32.lt_u
                                      br_if 0 (;@17;)
                                      local.get 17
                                      i64.extend_i32_u
                                      local.set 31
                                      i64.const 0
                                      local.set 30
                                      loop  ;; label = @18
                                        local.get 16
                                        local.get 16
                                        i64.load32_u
                                        local.get 31
                                        i64.shl
                                        local.get 30
                                        i64.const 4294967295
                                        i64.and
                                        i64.add
                                        local.tee 30
                                        local.get 30
                                        i64.const 1000000000
                                        i64.div_u
                                        local.tee 30
                                        i64.const 1000000000
                                        i64.mul
                                        i64.sub
                                        i64.store32
                                        local.get 16
                                        i32.const -4
                                        i32.add
                                        local.tee 16
                                        local.get 18
                                        i32.ge_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 30
                                      i32.wrap_i64
                                      local.tee 16
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      local.get 18
                                      i32.const -4
                                      i32.add
                                      local.tee 18
                                      local.get 16
                                      i32.store
                                    end
                                    block  ;; label = @17
                                      loop  ;; label = @18
                                        local.get 19
                                        local.tee 16
                                        local.get 18
                                        i32.le_u
                                        br_if 1 (;@17;)
                                        local.get 16
                                        i32.const -4
                                        i32.add
                                        local.tee 19
                                        i32.load
                                        i32.eqz
                                        br_if 0 (;@18;)
                                      end
                                    end
                                    local.get 5
                                    local.get 5
                                    i32.load offset=364
                                    local.get 17
                                    i32.sub
                                    local.tee 17
                                    i32.store offset=364
                                    local.get 16
                                    local.set 19
                                    local.get 17
                                    i32.const 0
                                    i32.gt_s
                                    br_if 0 (;@16;)
                                  end
                                end
                                block  ;; label = @15
                                  local.get 17
                                  i32.const -1
                                  i32.gt_s
                                  br_if 0 (;@15;)
                                  local.get 36
                                  i32.const 25
                                  i32.add
                                  i32.const 9
                                  i32.div_u
                                  i32.const 1
                                  i32.add
                                  local.set 25
                                  loop  ;; label = @16
                                    i32.const 9
                                    i32.const 0
                                    local.get 17
                                    i32.sub
                                    local.get 17
                                    i32.const -9
                                    i32.lt_s
                                    select
                                    local.set 20
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 18
                                        local.get 16
                                        i32.lt_u
                                        br_if 0 (;@18;)
                                        local.get 18
                                        local.get 18
                                        i32.const 4
                                        i32.add
                                        local.get 18
                                        i32.load
                                        select
                                        local.set 18
                                        br 1 (;@17;)
                                      end
                                      i32.const 1000000000
                                      local.get 20
                                      i32.shr_u
                                      local.set 23
                                      i32.const -1
                                      local.get 20
                                      i32.shl
                                      i32.const -1
                                      i32.xor
                                      local.set 26
                                      i32.const 0
                                      local.set 17
                                      local.get 18
                                      local.set 19
                                      loop  ;; label = @18
                                        local.get 19
                                        local.get 19
                                        i32.load
                                        local.tee 21
                                        local.get 20
                                        i32.shr_u
                                        local.get 17
                                        i32.add
                                        i32.store
                                        local.get 21
                                        local.get 26
                                        i32.and
                                        local.get 23
                                        i32.mul
                                        local.set 17
                                        local.get 19
                                        i32.const 4
                                        i32.add
                                        local.tee 19
                                        local.get 16
                                        i32.lt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 18
                                      local.get 18
                                      i32.const 4
                                      i32.add
                                      local.get 18
                                      i32.load
                                      select
                                      local.set 18
                                      local.get 17
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      local.get 16
                                      local.get 17
                                      i32.store
                                      local.get 16
                                      i32.const 4
                                      i32.add
                                      local.set 16
                                    end
                                    local.get 5
                                    local.get 5
                                    i32.load offset=364
                                    local.get 20
                                    i32.add
                                    local.tee 17
                                    i32.store offset=364
                                    local.get 28
                                    local.get 18
                                    local.get 29
                                    i32.const 102
                                    i32.eq
                                    select
                                    local.tee 19
                                    local.get 25
                                    i32.const 2
                                    i32.shl
                                    i32.add
                                    local.get 16
                                    local.get 16
                                    local.get 19
                                    i32.sub
                                    i32.const 2
                                    i32.shr_s
                                    local.get 25
                                    i32.gt_s
                                    select
                                    local.set 16
                                    local.get 17
                                    i32.const 0
                                    i32.lt_s
                                    br_if 0 (;@16;)
                                  end
                                end
                                i32.const 0
                                local.set 19
                                block  ;; label = @15
                                  local.get 18
                                  local.get 16
                                  i32.ge_u
                                  br_if 0 (;@15;)
                                  local.get 28
                                  local.get 18
                                  i32.sub
                                  i32.const 2
                                  i32.shr_s
                                  i32.const 9
                                  i32.mul
                                  local.set 19
                                  local.get 18
                                  i32.load
                                  local.tee 21
                                  i32.const 10
                                  i32.lt_u
                                  br_if 0 (;@15;)
                                  i32.const 10
                                  local.set 17
                                  loop  ;; label = @16
                                    local.get 19
                                    i32.const 1
                                    i32.add
                                    local.set 19
                                    local.get 21
                                    local.get 17
                                    i32.const 10
                                    i32.mul
                                    local.tee 17
                                    i32.ge_u
                                    br_if 0 (;@16;)
                                  end
                                end
                                block  ;; label = @15
                                  local.get 36
                                  i32.const 0
                                  local.get 19
                                  local.get 29
                                  i32.const 102
                                  i32.eq
                                  select
                                  local.tee 21
                                  i32.sub
                                  local.get 36
                                  i32.const 0
                                  i32.ne
                                  local.get 29
                                  i32.const 103
                                  i32.eq
                                  local.tee 23
                                  i32.and
                                  local.tee 26
                                  i32.sub
                                  local.tee 17
                                  local.get 16
                                  local.get 28
                                  i32.sub
                                  i32.const 2
                                  i32.shr_s
                                  i32.const 9
                                  i32.mul
                                  i32.const -9
                                  i32.add
                                  i32.ge_s
                                  br_if 0 (;@15;)
                                  local.get 17
                                  i32.const 9216
                                  i32.add
                                  local.tee 25
                                  i32.const 9
                                  i32.div_s
                                  local.tee 29
                                  i32.const 2
                                  i32.shl
                                  local.get 28
                                  i32.add
                                  local.tee 37
                                  i32.const -4092
                                  i32.add
                                  local.set 20
                                  i32.const 10
                                  local.set 17
                                  block  ;; label = @16
                                    local.get 25
                                    local.get 29
                                    i32.const 9
                                    i32.mul
                                    local.tee 29
                                    i32.sub
                                    i32.const 7
                                    i32.gt_s
                                    br_if 0 (;@16;)
                                    local.get 36
                                    i32.const 0
                                    local.get 26
                                    i32.sub
                                    i32.add
                                    local.get 21
                                    i32.sub
                                    local.get 29
                                    i32.sub
                                    i32.const 9215
                                    i32.add
                                    local.set 21
                                    i32.const 10
                                    local.set 17
                                    loop  ;; label = @17
                                      local.get 17
                                      i32.const 10
                                      i32.mul
                                      local.set 17
                                      local.get 21
                                      i32.const 1
                                      i32.add
                                      local.tee 21
                                      i32.const 7
                                      i32.lt_s
                                      br_if 0 (;@17;)
                                    end
                                  end
                                  local.get 20
                                  i32.load
                                  local.tee 26
                                  local.get 26
                                  local.get 17
                                  i32.div_u
                                  local.tee 25
                                  local.get 17
                                  i32.mul
                                  i32.sub
                                  local.set 21
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 20
                                      i32.const 4
                                      i32.add
                                      local.tee 29
                                      local.get 16
                                      i32.ne
                                      br_if 0 (;@17;)
                                      local.get 21
                                      i32.eqz
                                      br_if 1 (;@16;)
                                    end
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 25
                                        i32.const 1
                                        i32.and
                                        br_if 0 (;@18;)
                                        f64.const 0x1p+53 (;=9.0072e+15;)
                                        local.set 32
                                        local.get 20
                                        local.get 18
                                        i32.le_u
                                        br_if 1 (;@17;)
                                        local.get 17
                                        i32.const 1000000000
                                        i32.ne
                                        br_if 1 (;@17;)
                                        local.get 20
                                        i32.const -4
                                        i32.add
                                        i32.load8_u
                                        i32.const 1
                                        i32.and
                                        i32.eqz
                                        br_if 1 (;@17;)
                                      end
                                      f64.const 0x1.0000000000001p+53 (;=9.0072e+15;)
                                      local.set 32
                                    end
                                    f64.const 0x1p-1 (;=0.5;)
                                    f64.const 0x1p+0 (;=1;)
                                    f64.const 0x1.8p+0 (;=1.5;)
                                    local.get 21
                                    local.get 17
                                    i32.const 1
                                    i32.shr_u
                                    local.tee 25
                                    i32.eq
                                    select
                                    f64.const 0x1.8p+0 (;=1.5;)
                                    local.get 29
                                    local.get 16
                                    i32.eq
                                    select
                                    local.get 21
                                    local.get 25
                                    i32.lt_u
                                    select
                                    local.set 35
                                    block  ;; label = @17
                                      local.get 33
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      local.get 34
                                      i32.load8_u
                                      i32.const 45
                                      i32.ne
                                      br_if 0 (;@17;)
                                      local.get 35
                                      f64.neg
                                      local.set 35
                                      local.get 32
                                      f64.neg
                                      local.set 32
                                    end
                                    local.get 20
                                    local.get 26
                                    local.get 21
                                    i32.sub
                                    local.tee 21
                                    i32.store
                                    local.get 32
                                    local.get 35
                                    f64.add
                                    local.get 32
                                    f64.eq
                                    br_if 0 (;@16;)
                                    local.get 20
                                    local.get 21
                                    local.get 17
                                    i32.add
                                    local.tee 19
                                    i32.store
                                    block  ;; label = @17
                                      local.get 19
                                      i32.const 1000000000
                                      i32.lt_u
                                      br_if 0 (;@17;)
                                      local.get 37
                                      i32.const -4096
                                      i32.add
                                      local.set 19
                                      loop  ;; label = @18
                                        local.get 19
                                        i32.const 4
                                        i32.add
                                        i32.const 0
                                        i32.store
                                        block  ;; label = @19
                                          local.get 19
                                          local.get 18
                                          i32.ge_u
                                          br_if 0 (;@19;)
                                          local.get 18
                                          i32.const -4
                                          i32.add
                                          local.tee 18
                                          i32.const 0
                                          i32.store
                                        end
                                        local.get 19
                                        local.get 19
                                        i32.load
                                        i32.const 1
                                        i32.add
                                        local.tee 17
                                        i32.store
                                        local.get 19
                                        i32.const -4
                                        i32.add
                                        local.set 19
                                        local.get 17
                                        i32.const 999999999
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 19
                                      i32.const 4
                                      i32.add
                                      local.set 20
                                    end
                                    local.get 28
                                    local.get 18
                                    i32.sub
                                    i32.const 2
                                    i32.shr_s
                                    i32.const 9
                                    i32.mul
                                    local.set 19
                                    local.get 18
                                    i32.load
                                    local.tee 21
                                    i32.const 10
                                    i32.lt_u
                                    br_if 0 (;@16;)
                                    i32.const 10
                                    local.set 17
                                    loop  ;; label = @17
                                      local.get 19
                                      i32.const 1
                                      i32.add
                                      local.set 19
                                      local.get 21
                                      local.get 17
                                      i32.const 10
                                      i32.mul
                                      local.tee 17
                                      i32.ge_u
                                      br_if 0 (;@17;)
                                    end
                                  end
                                  local.get 20
                                  i32.const 4
                                  i32.add
                                  local.tee 17
                                  local.get 16
                                  local.get 16
                                  local.get 17
                                  i32.gt_u
                                  select
                                  local.set 16
                                end
                                block  ;; label = @15
                                  loop  ;; label = @16
                                    block  ;; label = @17
                                      local.get 16
                                      local.tee 21
                                      local.get 18
                                      i32.gt_u
                                      br_if 0 (;@17;)
                                      i32.const 0
                                      local.set 29
                                      br 2 (;@15;)
                                    end
                                    local.get 21
                                    i32.const -4
                                    i32.add
                                    local.tee 16
                                    i32.load
                                    i32.eqz
                                    br_if 0 (;@16;)
                                  end
                                  i32.const 1
                                  local.set 29
                                end
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 23
                                    br_if 0 (;@16;)
                                    local.get 22
                                    i32.const 8
                                    i32.and
                                    local.set 26
                                    br 1 (;@15;)
                                  end
                                  local.get 19
                                  i32.const -1
                                  i32.xor
                                  i32.const -1
                                  local.get 36
                                  i32.const 1
                                  local.get 36
                                  select
                                  local.tee 16
                                  local.get 19
                                  i32.gt_s
                                  local.get 19
                                  i32.const -5
                                  i32.gt_s
                                  i32.and
                                  local.tee 17
                                  select
                                  local.get 16
                                  i32.add
                                  local.set 36
                                  i32.const -1
                                  i32.const -2
                                  local.get 17
                                  select
                                  local.get 27
                                  i32.add
                                  local.set 27
                                  local.get 22
                                  i32.const 8
                                  i32.and
                                  local.tee 26
                                  br_if 0 (;@15;)
                                  i32.const 9
                                  local.set 16
                                  block  ;; label = @16
                                    local.get 29
                                    i32.eqz
                                    br_if 0 (;@16;)
                                    local.get 21
                                    i32.const -4
                                    i32.add
                                    i32.load
                                    local.tee 20
                                    i32.eqz
                                    br_if 0 (;@16;)
                                    i32.const 0
                                    local.set 16
                                    local.get 20
                                    i32.const 10
                                    i32.rem_u
                                    br_if 0 (;@16;)
                                    i32.const 10
                                    local.set 17
                                    i32.const 0
                                    local.set 16
                                    loop  ;; label = @17
                                      local.get 16
                                      i32.const 1
                                      i32.add
                                      local.set 16
                                      local.get 20
                                      local.get 17
                                      i32.const 10
                                      i32.mul
                                      local.tee 17
                                      i32.rem_u
                                      i32.eqz
                                      br_if 0 (;@17;)
                                    end
                                  end
                                  local.get 21
                                  local.get 28
                                  i32.sub
                                  i32.const 2
                                  i32.shr_s
                                  i32.const 9
                                  i32.mul
                                  i32.const -9
                                  i32.add
                                  local.set 17
                                  block  ;; label = @16
                                    local.get 27
                                    i32.const 32
                                    i32.or
                                    i32.const 102
                                    i32.ne
                                    br_if 0 (;@16;)
                                    i32.const 0
                                    local.set 26
                                    local.get 36
                                    local.get 17
                                    local.get 16
                                    i32.sub
                                    local.tee 16
                                    i32.const 0
                                    local.get 16
                                    i32.const 0
                                    i32.gt_s
                                    select
                                    local.tee 16
                                    local.get 36
                                    local.get 16
                                    i32.lt_s
                                    select
                                    local.set 36
                                    br 1 (;@15;)
                                  end
                                  i32.const 0
                                  local.set 26
                                  local.get 36
                                  local.get 17
                                  local.get 19
                                  i32.add
                                  local.get 16
                                  i32.sub
                                  local.tee 16
                                  i32.const 0
                                  local.get 16
                                  i32.const 0
                                  i32.gt_s
                                  select
                                  local.tee 16
                                  local.get 36
                                  local.get 16
                                  i32.lt_s
                                  select
                                  local.set 36
                                end
                                i32.const -1
                                local.set 16
                                local.get 36
                                i32.const 2147483645
                                i32.const 2147483646
                                local.get 36
                                local.get 26
                                i32.or
                                local.tee 25
                                select
                                i32.gt_s
                                br_if 0 (;@14;)
                                local.get 36
                                local.get 25
                                i32.const 0
                                i32.ne
                                i32.add
                                i32.const 1
                                i32.add
                                local.set 37
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 27
                                    i32.const 32
                                    i32.or
                                    i32.const 102
                                    i32.ne
                                    local.tee 38
                                    br_if 0 (;@16;)
                                    local.get 19
                                    i32.const 2147483647
                                    local.get 37
                                    i32.sub
                                    i32.gt_s
                                    br_if 2 (;@14;)
                                    local.get 19
                                    i32.const 0
                                    local.get 19
                                    i32.const 0
                                    i32.gt_s
                                    select
                                    local.set 19
                                    br 1 (;@15;)
                                  end
                                  local.get 11
                                  local.set 17
                                  block  ;; label = @16
                                    local.get 19
                                    local.get 19
                                    i32.const 31
                                    i32.shr_s
                                    local.tee 16
                                    i32.add
                                    local.get 16
                                    i32.xor
                                    local.tee 16
                                    i32.eqz
                                    br_if 0 (;@16;)
                                    loop  ;; label = @17
                                      local.get 17
                                      i32.const -1
                                      i32.add
                                      local.tee 17
                                      local.get 16
                                      local.get 16
                                      i32.const 10
                                      i32.div_u
                                      local.tee 20
                                      i32.const 10
                                      i32.mul
                                      i32.sub
                                      i32.const 48
                                      i32.or
                                      i32.store8
                                      local.get 16
                                      i32.const 9
                                      i32.gt_u
                                      local.set 23
                                      local.get 20
                                      local.set 16
                                      local.get 23
                                      br_if 0 (;@17;)
                                    end
                                  end
                                  block  ;; label = @16
                                    local.get 11
                                    local.get 17
                                    i32.sub
                                    i32.const 1
                                    i32.gt_s
                                    br_if 0 (;@16;)
                                    local.get 17
                                    i32.const -1
                                    i32.add
                                    local.set 16
                                    loop  ;; label = @17
                                      local.get 16
                                      i32.const 48
                                      i32.store8
                                      local.get 11
                                      local.get 16
                                      i32.sub
                                      local.set 17
                                      local.get 16
                                      i32.const -1
                                      i32.add
                                      local.tee 20
                                      local.set 16
                                      local.get 17
                                      i32.const 2
                                      i32.lt_s
                                      br_if 0 (;@17;)
                                    end
                                    local.get 20
                                    i32.const 1
                                    i32.add
                                    local.set 17
                                  end
                                  local.get 17
                                  i32.const -2
                                  i32.add
                                  local.tee 39
                                  local.get 27
                                  i32.store8
                                  i32.const -1
                                  local.set 16
                                  local.get 17
                                  i32.const -1
                                  i32.add
                                  i32.const 45
                                  i32.const 43
                                  local.get 19
                                  i32.const 0
                                  i32.lt_s
                                  select
                                  i32.store8
                                  local.get 11
                                  local.get 39
                                  i32.sub
                                  local.tee 19
                                  i32.const 2147483647
                                  local.get 37
                                  i32.sub
                                  i32.gt_s
                                  br_if 1 (;@14;)
                                end
                                i32.const -1
                                local.set 16
                                local.get 19
                                local.get 37
                                i32.add
                                local.tee 19
                                local.get 33
                                i32.const 2147483647
                                i32.xor
                                i32.gt_s
                                br_if 0 (;@14;)
                                local.get 19
                                local.get 33
                                i32.add
                                local.set 27
                                block  ;; label = @15
                                  local.get 22
                                  i32.const 73728
                                  i32.and
                                  local.tee 22
                                  br_if 0 (;@15;)
                                  local.get 24
                                  local.get 27
                                  i32.le_s
                                  br_if 0 (;@15;)
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  i32.const 32
                                  local.get 24
                                  local.get 27
                                  i32.sub
                                  local.tee 23
                                  i32.const 256
                                  local.get 23
                                  i32.const 256
                                  i32.lt_u
                                  local.tee 16
                                  select
                                  call $memset
                                  drop
                                  local.get 0
                                  i32.load
                                  local.tee 17
                                  i32.const 32
                                  i32.and
                                  local.set 19
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 16
                                      br_if 0 (;@17;)
                                      local.get 19
                                      i32.eqz
                                      local.set 16
                                      local.get 23
                                      local.set 19
                                      loop  ;; label = @18
                                        block  ;; label = @19
                                          local.get 16
                                          i32.const 1
                                          i32.and
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          local.get 5
                                          i32.const 64
                                          i32.add
                                          i32.const 256
                                          local.get 0
                                          call $__fwritex
                                          drop
                                          local.get 0
                                          i32.load
                                          local.set 17
                                        end
                                        local.get 17
                                        i32.const 32
                                        i32.and
                                        local.tee 20
                                        i32.eqz
                                        local.set 16
                                        local.get 19
                                        i32.const -256
                                        i32.add
                                        local.tee 19
                                        i32.const 255
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 20
                                      br_if 2 (;@15;)
                                      local.get 23
                                      i32.const 255
                                      i32.and
                                      local.set 23
                                      br 1 (;@16;)
                                    end
                                    local.get 19
                                    br_if 1 (;@15;)
                                  end
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  local.get 23
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                block  ;; label = @15
                                  local.get 0
                                  i32.load8_u
                                  i32.const 32
                                  i32.and
                                  br_if 0 (;@15;)
                                  local.get 34
                                  local.get 33
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                block  ;; label = @15
                                  local.get 22
                                  i32.const 65536
                                  i32.ne
                                  br_if 0 (;@15;)
                                  local.get 24
                                  local.get 27
                                  i32.le_s
                                  br_if 0 (;@15;)
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  i32.const 48
                                  local.get 24
                                  local.get 27
                                  i32.sub
                                  local.tee 23
                                  i32.const 256
                                  local.get 23
                                  i32.const 256
                                  i32.lt_u
                                  local.tee 16
                                  select
                                  call $memset
                                  drop
                                  local.get 0
                                  i32.load
                                  local.tee 17
                                  i32.const 32
                                  i32.and
                                  local.set 19
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 16
                                      br_if 0 (;@17;)
                                      local.get 19
                                      i32.eqz
                                      local.set 16
                                      local.get 23
                                      local.set 19
                                      loop  ;; label = @18
                                        block  ;; label = @19
                                          local.get 16
                                          i32.const 1
                                          i32.and
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          local.get 5
                                          i32.const 64
                                          i32.add
                                          i32.const 256
                                          local.get 0
                                          call $__fwritex
                                          drop
                                          local.get 0
                                          i32.load
                                          local.set 17
                                        end
                                        local.get 17
                                        i32.const 32
                                        i32.and
                                        local.tee 20
                                        i32.eqz
                                        local.set 16
                                        local.get 19
                                        i32.const -256
                                        i32.add
                                        local.tee 19
                                        i32.const 255
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 20
                                      br_if 2 (;@15;)
                                      local.get 23
                                      i32.const 255
                                      i32.and
                                      local.set 23
                                      br 1 (;@16;)
                                    end
                                    local.get 19
                                    br_if 1 (;@15;)
                                  end
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  local.get 23
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                block  ;; label = @15
                                  block  ;; label = @16
                                    local.get 38
                                    br_if 0 (;@16;)
                                    local.get 28
                                    local.get 18
                                    local.get 18
                                    local.get 28
                                    i32.gt_u
                                    select
                                    local.tee 23
                                    local.set 20
                                    loop  ;; label = @17
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          local.get 20
                                          i32.load
                                          local.tee 16
                                          br_if 0 (;@19;)
                                          i32.const 0
                                          local.set 18
                                          br 1 (;@18;)
                                        end
                                        i32.const 0
                                        local.set 18
                                        loop  ;; label = @19
                                          local.get 6
                                          local.get 18
                                          i32.add
                                          local.get 16
                                          local.get 16
                                          i32.const 10
                                          i32.div_u
                                          local.tee 19
                                          i32.const 10
                                          i32.mul
                                          i32.sub
                                          i32.const 48
                                          i32.or
                                          i32.store8
                                          local.get 18
                                          i32.const -1
                                          i32.add
                                          local.set 18
                                          local.get 16
                                          i32.const 9
                                          i32.gt_u
                                          local.set 17
                                          local.get 19
                                          local.set 16
                                          local.get 17
                                          br_if 0 (;@19;)
                                        end
                                      end
                                      local.get 9
                                      local.get 18
                                      i32.add
                                      local.set 16
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          local.get 20
                                          local.get 23
                                          i32.eq
                                          br_if 0 (;@19;)
                                          local.get 16
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          i32.le_u
                                          br_if 1 (;@18;)
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          i32.const 48
                                          local.get 18
                                          i32.const 9
                                          i32.add
                                          call $memset
                                          drop
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          local.set 16
                                          br 1 (;@18;)
                                        end
                                        local.get 18
                                        br_if 0 (;@18;)
                                        local.get 16
                                        i32.const -1
                                        i32.add
                                        local.tee 16
                                        i32.const 48
                                        i32.store8
                                      end
                                      block  ;; label = @18
                                        local.get 0
                                        i32.load8_u
                                        i32.const 32
                                        i32.and
                                        br_if 0 (;@18;)
                                        local.get 16
                                        local.get 9
                                        local.get 16
                                        i32.sub
                                        local.get 0
                                        call $__fwritex
                                        drop
                                      end
                                      local.get 20
                                      i32.const 4
                                      i32.add
                                      local.tee 20
                                      local.get 28
                                      i32.le_u
                                      br_if 0 (;@17;)
                                    end
                                    block  ;; label = @17
                                      local.get 25
                                      i32.eqz
                                      br_if 0 (;@17;)
                                      local.get 0
                                      i32.load8_u
                                      i32.const 32
                                      i32.and
                                      br_if 0 (;@17;)
                                      i32.const 3539
                                      i32.const 1
                                      local.get 0
                                      call $__fwritex
                                      drop
                                    end
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 36
                                        i32.const 1
                                        i32.ge_s
                                        br_if 0 (;@18;)
                                        local.get 36
                                        local.set 16
                                        br 1 (;@17;)
                                      end
                                      block  ;; label = @18
                                        local.get 20
                                        local.get 21
                                        i32.lt_u
                                        br_if 0 (;@18;)
                                        local.get 36
                                        local.set 16
                                        br 1 (;@17;)
                                      end
                                      loop  ;; label = @18
                                        local.get 9
                                        local.set 16
                                        block  ;; label = @19
                                          block  ;; label = @20
                                            local.get 20
                                            i32.load
                                            local.tee 18
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 9
                                            local.set 16
                                            loop  ;; label = @21
                                              local.get 16
                                              i32.const -1
                                              i32.add
                                              local.tee 16
                                              local.get 18
                                              local.get 18
                                              i32.const 10
                                              i32.div_u
                                              local.tee 19
                                              i32.const 10
                                              i32.mul
                                              i32.sub
                                              i32.const 48
                                              i32.or
                                              i32.store8
                                              local.get 18
                                              i32.const 9
                                              i32.gt_u
                                              local.set 17
                                              local.get 19
                                              local.set 18
                                              local.get 17
                                              br_if 0 (;@21;)
                                            end
                                            local.get 16
                                            local.get 5
                                            i32.const 336
                                            i32.add
                                            i32.le_u
                                            br_if 1 (;@19;)
                                          end
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          i32.const 48
                                          local.get 16
                                          local.get 12
                                          i32.add
                                          call $memset
                                          drop
                                          loop  ;; label = @20
                                            local.get 16
                                            i32.const -1
                                            i32.add
                                            local.tee 16
                                            local.get 5
                                            i32.const 336
                                            i32.add
                                            i32.gt_u
                                            br_if 0 (;@20;)
                                          end
                                        end
                                        block  ;; label = @19
                                          local.get 0
                                          i32.load8_u
                                          i32.const 32
                                          i32.and
                                          br_if 0 (;@19;)
                                          local.get 16
                                          local.get 36
                                          i32.const 9
                                          local.get 36
                                          i32.const 9
                                          i32.lt_s
                                          select
                                          local.get 0
                                          call $__fwritex
                                          drop
                                        end
                                        local.get 36
                                        i32.const -9
                                        i32.add
                                        local.set 16
                                        local.get 36
                                        i32.const 10
                                        i32.lt_s
                                        br_if 1 (;@17;)
                                        local.get 16
                                        local.set 36
                                        local.get 20
                                        i32.const 4
                                        i32.add
                                        local.tee 20
                                        local.get 21
                                        i32.lt_u
                                        br_if 0 (;@18;)
                                      end
                                    end
                                    local.get 16
                                    i32.const 1
                                    i32.lt_s
                                    br_if 1 (;@15;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 48
                                    local.get 16
                                    i32.const 256
                                    local.get 16
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 18
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 17
                                    i32.const 32
                                    i32.and
                                    local.set 19
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 18
                                        br_if 0 (;@18;)
                                        local.get 19
                                        i32.eqz
                                        local.set 18
                                        local.get 16
                                        local.set 19
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 18
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 17
                                          end
                                          local.get 17
                                          i32.const 32
                                          i32.and
                                          local.tee 21
                                          i32.eqz
                                          local.set 18
                                          local.get 19
                                          i32.const -256
                                          i32.add
                                          local.tee 19
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 21
                                        br_if 3 (;@15;)
                                        local.get 16
                                        i32.const 255
                                        i32.and
                                        local.set 16
                                        br 1 (;@17;)
                                      end
                                      local.get 19
                                      br_if 2 (;@15;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 16
                                    local.get 0
                                    call $__fwritex
                                    drop
                                    br 1 (;@15;)
                                  end
                                  block  ;; label = @16
                                    local.get 36
                                    i32.const 0
                                    i32.lt_s
                                    br_if 0 (;@16;)
                                    local.get 21
                                    local.get 18
                                    i32.const 4
                                    i32.add
                                    local.get 29
                                    select
                                    local.set 23
                                    local.get 18
                                    local.set 20
                                    loop  ;; label = @17
                                      local.get 9
                                      local.set 17
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          local.get 20
                                          i32.load
                                          local.tee 16
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          i32.const 0
                                          local.set 19
                                          loop  ;; label = @20
                                            local.get 5
                                            i32.const 336
                                            i32.add
                                            local.get 19
                                            i32.add
                                            i32.const 8
                                            i32.add
                                            local.get 16
                                            local.get 16
                                            i32.const 10
                                            i32.div_u
                                            local.tee 17
                                            i32.const 10
                                            i32.mul
                                            i32.sub
                                            i32.const 48
                                            i32.or
                                            i32.store8
                                            local.get 19
                                            i32.const -1
                                            i32.add
                                            local.set 19
                                            local.get 16
                                            i32.const 9
                                            i32.gt_u
                                            local.set 21
                                            local.get 17
                                            local.set 16
                                            local.get 21
                                            br_if 0 (;@20;)
                                          end
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          local.get 19
                                          i32.add
                                          i32.const 9
                                          i32.add
                                          local.set 17
                                          local.get 19
                                          br_if 1 (;@18;)
                                        end
                                        local.get 17
                                        i32.const -1
                                        i32.add
                                        local.tee 17
                                        i32.const 48
                                        i32.store8
                                      end
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          local.get 20
                                          local.get 18
                                          i32.eq
                                          br_if 0 (;@19;)
                                          local.get 17
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          i32.le_u
                                          br_if 1 (;@18;)
                                          local.get 5
                                          i32.const 336
                                          i32.add
                                          i32.const 48
                                          local.get 17
                                          local.get 12
                                          i32.add
                                          call $memset
                                          drop
                                          loop  ;; label = @20
                                            local.get 17
                                            i32.const -1
                                            i32.add
                                            local.tee 17
                                            local.get 5
                                            i32.const 336
                                            i32.add
                                            i32.gt_u
                                            br_if 0 (;@20;)
                                            br 2 (;@18;)
                                          end
                                        end
                                        block  ;; label = @19
                                          local.get 0
                                          i32.load8_u
                                          i32.const 32
                                          i32.and
                                          br_if 0 (;@19;)
                                          local.get 17
                                          i32.const 1
                                          local.get 0
                                          call $__fwritex
                                          drop
                                        end
                                        local.get 17
                                        i32.const 1
                                        i32.add
                                        local.set 17
                                        block  ;; label = @19
                                          local.get 26
                                          br_if 0 (;@19;)
                                          local.get 36
                                          i32.const 1
                                          i32.lt_s
                                          br_if 1 (;@18;)
                                        end
                                        local.get 0
                                        i32.load8_u
                                        i32.const 32
                                        i32.and
                                        br_if 0 (;@18;)
                                        i32.const 3539
                                        i32.const 1
                                        local.get 0
                                        call $__fwritex
                                        drop
                                      end
                                      local.get 9
                                      local.get 17
                                      i32.sub
                                      local.set 16
                                      block  ;; label = @18
                                        local.get 0
                                        i32.load8_u
                                        i32.const 32
                                        i32.and
                                        br_if 0 (;@18;)
                                        local.get 17
                                        local.get 16
                                        local.get 36
                                        local.get 36
                                        local.get 16
                                        i32.gt_s
                                        select
                                        local.get 0
                                        call $__fwritex
                                        drop
                                      end
                                      local.get 36
                                      local.get 16
                                      i32.sub
                                      local.set 36
                                      block  ;; label = @18
                                        local.get 20
                                        i32.const 4
                                        i32.add
                                        local.tee 20
                                        local.get 23
                                        i32.ge_u
                                        br_if 0 (;@18;)
                                        local.get 36
                                        i32.const -1
                                        i32.gt_s
                                        br_if 1 (;@17;)
                                      end
                                    end
                                    local.get 36
                                    i32.const 1
                                    i32.lt_s
                                    br_if 0 (;@16;)
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    i32.const 48
                                    local.get 36
                                    i32.const 256
                                    local.get 36
                                    i32.const 256
                                    i32.lt_u
                                    local.tee 16
                                    select
                                    call $memset
                                    drop
                                    local.get 0
                                    i32.load
                                    local.tee 19
                                    i32.const 32
                                    i32.and
                                    local.set 18
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        local.get 16
                                        br_if 0 (;@18;)
                                        local.get 18
                                        i32.eqz
                                        local.set 16
                                        local.get 36
                                        local.set 18
                                        loop  ;; label = @19
                                          block  ;; label = @20
                                            local.get 16
                                            i32.const 1
                                            i32.and
                                            i32.eqz
                                            br_if 0 (;@20;)
                                            local.get 5
                                            i32.const 64
                                            i32.add
                                            i32.const 256
                                            local.get 0
                                            call $__fwritex
                                            drop
                                            local.get 0
                                            i32.load
                                            local.set 19
                                          end
                                          local.get 19
                                          i32.const 32
                                          i32.and
                                          local.tee 17
                                          i32.eqz
                                          local.set 16
                                          local.get 18
                                          i32.const -256
                                          i32.add
                                          local.tee 18
                                          i32.const 255
                                          i32.gt_u
                                          br_if 0 (;@19;)
                                        end
                                        local.get 17
                                        br_if 2 (;@16;)
                                        local.get 36
                                        i32.const 255
                                        i32.and
                                        local.set 36
                                        br 1 (;@17;)
                                      end
                                      local.get 18
                                      br_if 1 (;@16;)
                                    end
                                    local.get 5
                                    i32.const 64
                                    i32.add
                                    local.get 36
                                    local.get 0
                                    call $__fwritex
                                    drop
                                  end
                                  local.get 0
                                  i32.load8_u
                                  i32.const 32
                                  i32.and
                                  br_if 0 (;@15;)
                                  local.get 39
                                  local.get 11
                                  local.get 39
                                  i32.sub
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                block  ;; label = @15
                                  local.get 22
                                  i32.const 8192
                                  i32.ne
                                  br_if 0 (;@15;)
                                  local.get 24
                                  local.get 27
                                  i32.le_s
                                  br_if 0 (;@15;)
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  i32.const 32
                                  local.get 24
                                  local.get 27
                                  i32.sub
                                  local.tee 21
                                  i32.const 256
                                  local.get 21
                                  i32.const 256
                                  i32.lt_u
                                  local.tee 16
                                  select
                                  call $memset
                                  drop
                                  local.get 0
                                  i32.load
                                  local.tee 19
                                  i32.const 32
                                  i32.and
                                  local.set 18
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      local.get 16
                                      br_if 0 (;@17;)
                                      local.get 18
                                      i32.eqz
                                      local.set 16
                                      local.get 21
                                      local.set 18
                                      loop  ;; label = @18
                                        block  ;; label = @19
                                          local.get 16
                                          i32.const 1
                                          i32.and
                                          i32.eqz
                                          br_if 0 (;@19;)
                                          local.get 5
                                          i32.const 64
                                          i32.add
                                          i32.const 256
                                          local.get 0
                                          call $__fwritex
                                          drop
                                          local.get 0
                                          i32.load
                                          local.set 19
                                        end
                                        local.get 19
                                        i32.const 32
                                        i32.and
                                        local.tee 17
                                        i32.eqz
                                        local.set 16
                                        local.get 18
                                        i32.const -256
                                        i32.add
                                        local.tee 18
                                        i32.const 255
                                        i32.gt_u
                                        br_if 0 (;@18;)
                                      end
                                      local.get 17
                                      br_if 2 (;@15;)
                                      local.get 21
                                      i32.const 255
                                      i32.and
                                      local.set 21
                                      br 1 (;@16;)
                                    end
                                    local.get 18
                                    br_if 1 (;@15;)
                                  end
                                  local.get 5
                                  i32.const 64
                                  i32.add
                                  local.get 21
                                  local.get 0
                                  call $__fwritex
                                  drop
                                end
                                local.get 24
                                local.get 27
                                local.get 24
                                local.get 27
                                i32.gt_s
                                select
                                local.set 16
                              end
                              local.get 16
                              i32.const 0
                              i32.ge_s
                              br_if 9 (;@4;)
                              br 10 (;@3;)
                            end
                            i32.const 0
                            local.set 28
                            i32.const 2854
                            local.set 29
                          end
                          local.get 13
                          local.set 16
                          br 6 (;@5;)
                        end
                        local.get 23
                        local.set 22
                        local.get 18
                        local.set 20
                        local.get 16
                        i32.load8_u
                        i32.eqz
                        br_if 5 (;@5;)
                        br 7 (;@3;)
                      end
                      local.get 1
                      i32.load8_u offset=1
                      local.set 16
                      local.get 1
                      i32.const 1
                      i32.add
                      local.set 1
                      br 0 (;@9;)
                    end
                  end
                  local.get 0
                  br_if 6 (;@1;)
                  block  ;; label = @8
                    local.get 14
                    br_if 0 (;@8;)
                    i32.const 0
                    local.set 15
                    br 7 (;@1;)
                  end
                  block  ;; label = @8
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=4
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 1
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 8
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=8
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 2
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 16
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=12
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 3
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 24
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=16
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 4
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 32
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=20
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 5
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 40
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=24
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 6
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 48
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=28
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 7
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 56
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    block  ;; label = @9
                      local.get 4
                      i32.load offset=32
                      local.tee 1
                      br_if 0 (;@9;)
                      i32.const 8
                      local.set 1
                      br 1 (;@8;)
                    end
                    local.get 3
                    i32.const 64
                    i32.add
                    local.get 1
                    local.get 2
                    call $pop_arg
                    local.get 4
                    i32.load offset=36
                    local.tee 1
                    br_if 2 (;@6;)
                    i32.const 9
                    local.set 1
                  end
                  local.get 1
                  i32.const -1
                  i32.add
                  local.set 16
                  local.get 4
                  local.get 1
                  i32.const 2
                  i32.shl
                  i32.add
                  local.set 1
                  loop  ;; label = @8
                    local.get 1
                    i32.load
                    br_if 1 (;@7;)
                    local.get 1
                    i32.const 4
                    i32.add
                    local.set 1
                    i32.const 1
                    local.set 15
                    local.get 16
                    i32.const 1
                    i32.add
                    local.tee 16
                    i32.const 8
                    i32.gt_u
                    br_if 7 (;@1;)
                    br 0 (;@8;)
                  end
                end
                i32.const 0
                i32.const 28
                i32.store offset=4496
                br 4 (;@2;)
              end
              local.get 3
              i32.const 72
              i32.add
              local.get 1
              local.get 2
              call $pop_arg
              i32.const 1
              local.set 15
              br 4 (;@1;)
            end
            local.get 16
            local.get 17
            i32.sub
            local.tee 25
            local.get 20
            local.get 20
            local.get 25
            i32.lt_s
            select
            local.tee 36
            i32.const 2147483647
            local.get 28
            i32.sub
            i32.gt_s
            br_if 1 (;@3;)
            local.get 28
            local.get 36
            i32.add
            local.tee 26
            local.get 24
            local.get 24
            local.get 26
            i32.lt_s
            select
            local.tee 16
            local.get 19
            i32.gt_s
            br_if 1 (;@3;)
            block  ;; label = @5
              local.get 22
              i32.const 73728
              i32.and
              local.tee 22
              br_if 0 (;@5;)
              local.get 26
              local.get 24
              i32.ge_s
              br_if 0 (;@5;)
              local.get 5
              i32.const 64
              i32.add
              i32.const 32
              local.get 16
              local.get 26
              i32.sub
              local.tee 27
              i32.const 256
              local.get 27
              i32.const 256
              i32.lt_u
              local.tee 18
              select
              call $memset
              drop
              local.get 0
              i32.load
              local.tee 21
              i32.const 32
              i32.and
              local.set 19
              block  ;; label = @6
                block  ;; label = @7
                  local.get 18
                  br_if 0 (;@7;)
                  local.get 19
                  i32.eqz
                  local.set 18
                  local.get 27
                  local.set 19
                  loop  ;; label = @8
                    block  ;; label = @9
                      local.get 18
                      i32.const 1
                      i32.and
                      i32.eqz
                      br_if 0 (;@9;)
                      local.get 5
                      i32.const 64
                      i32.add
                      i32.const 256
                      local.get 0
                      call $__fwritex
                      drop
                      local.get 0
                      i32.load
                      local.set 21
                    end
                    local.get 21
                    i32.const 32
                    i32.and
                    local.tee 23
                    i32.eqz
                    local.set 18
                    local.get 19
                    i32.const -256
                    i32.add
                    local.tee 19
                    i32.const 255
                    i32.gt_u
                    br_if 0 (;@8;)
                  end
                  local.get 23
                  br_if 2 (;@5;)
                  local.get 27
                  i32.const 255
                  i32.and
                  local.set 27
                  br 1 (;@6;)
                end
                local.get 19
                br_if 1 (;@5;)
              end
              local.get 5
              i32.const 64
              i32.add
              local.get 27
              local.get 0
              call $__fwritex
              drop
            end
            block  ;; label = @5
              local.get 0
              i32.load8_u
              i32.const 32
              i32.and
              br_if 0 (;@5;)
              local.get 29
              local.get 28
              local.get 0
              call $__fwritex
              drop
            end
            block  ;; label = @5
              local.get 22
              i32.const 65536
              i32.ne
              br_if 0 (;@5;)
              local.get 26
              local.get 24
              i32.ge_s
              br_if 0 (;@5;)
              local.get 5
              i32.const 64
              i32.add
              i32.const 48
              local.get 16
              local.get 26
              i32.sub
              local.tee 28
              i32.const 256
              local.get 28
              i32.const 256
              i32.lt_u
              local.tee 18
              select
              call $memset
              drop
              local.get 0
              i32.load
              local.tee 21
              i32.const 32
              i32.and
              local.set 19
              block  ;; label = @6
                block  ;; label = @7
                  local.get 18
                  br_if 0 (;@7;)
                  local.get 19
                  i32.eqz
                  local.set 18
                  local.get 28
                  local.set 19
                  loop  ;; label = @8
                    block  ;; label = @9
                      local.get 18
                      i32.const 1
                      i32.and
                      i32.eqz
                      br_if 0 (;@9;)
                      local.get 5
                      i32.const 64
                      i32.add
                      i32.const 256
                      local.get 0
                      call $__fwritex
                      drop
                      local.get 0
                      i32.load
                      local.set 21
                    end
                    local.get 21
                    i32.const 32
                    i32.and
                    local.tee 23
                    i32.eqz
                    local.set 18
                    local.get 19
                    i32.const -256
                    i32.add
                    local.tee 19
                    i32.const 255
                    i32.gt_u
                    br_if 0 (;@8;)
                  end
                  local.get 23
                  br_if 2 (;@5;)
                  local.get 28
                  i32.const 255
                  i32.and
                  local.set 28
                  br 1 (;@6;)
                end
                local.get 19
                br_if 1 (;@5;)
              end
              local.get 5
              i32.const 64
              i32.add
              local.get 28
              local.get 0
              call $__fwritex
              drop
            end
            block  ;; label = @5
              local.get 25
              local.get 20
              i32.ge_s
              br_if 0 (;@5;)
              local.get 5
              i32.const 64
              i32.add
              i32.const 48
              local.get 36
              local.get 25
              i32.sub
              local.tee 23
              i32.const 256
              local.get 23
              i32.const 256
              i32.lt_u
              local.tee 18
              select
              call $memset
              drop
              local.get 0
              i32.load
              local.tee 21
              i32.const 32
              i32.and
              local.set 19
              block  ;; label = @6
                block  ;; label = @7
                  local.get 18
                  br_if 0 (;@7;)
                  local.get 19
                  i32.eqz
                  local.set 18
                  local.get 23
                  local.set 19
                  loop  ;; label = @8
                    block  ;; label = @9
                      local.get 18
                      i32.const 1
                      i32.and
                      i32.eqz
                      br_if 0 (;@9;)
                      local.get 5
                      i32.const 64
                      i32.add
                      i32.const 256
                      local.get 0
                      call $__fwritex
                      drop
                      local.get 0
                      i32.load
                      local.set 21
                    end
                    local.get 21
                    i32.const 32
                    i32.and
                    local.tee 20
                    i32.eqz
                    local.set 18
                    local.get 19
                    i32.const -256
                    i32.add
                    local.tee 19
                    i32.const 255
                    i32.gt_u
                    br_if 0 (;@8;)
                  end
                  local.get 20
                  br_if 2 (;@5;)
                  local.get 23
                  i32.const 255
                  i32.and
                  local.set 23
                  br 1 (;@6;)
                end
                local.get 19
                br_if 1 (;@5;)
              end
              local.get 5
              i32.const 64
              i32.add
              local.get 23
              local.get 0
              call $__fwritex
              drop
            end
            block  ;; label = @5
              local.get 0
              i32.load8_u
              i32.const 32
              i32.and
              br_if 0 (;@5;)
              local.get 17
              local.get 25
              local.get 0
              call $__fwritex
              drop
            end
            local.get 22
            i32.const 8192
            i32.ne
            br_if 0 (;@4;)
            local.get 26
            local.get 24
            i32.ge_s
            br_if 0 (;@4;)
            local.get 5
            i32.const 64
            i32.add
            i32.const 32
            local.get 16
            local.get 26
            i32.sub
            local.tee 24
            i32.const 256
            local.get 24
            i32.const 256
            i32.lt_u
            local.tee 18
            select
            call $memset
            drop
            local.get 0
            i32.load
            local.tee 17
            i32.const 32
            i32.and
            local.set 19
            block  ;; label = @5
              block  ;; label = @6
                local.get 18
                br_if 0 (;@6;)
                local.get 19
                i32.eqz
                local.set 18
                local.get 24
                local.set 19
                loop  ;; label = @7
                  block  ;; label = @8
                    local.get 18
                    i32.const 1
                    i32.and
                    i32.eqz
                    br_if 0 (;@8;)
                    local.get 5
                    i32.const 64
                    i32.add
                    i32.const 256
                    local.get 0
                    call $__fwritex
                    drop
                    local.get 0
                    i32.load
                    local.set 17
                  end
                  local.get 17
                  i32.const 32
                  i32.and
                  local.tee 21
                  i32.eqz
                  local.set 18
                  local.get 19
                  i32.const -256
                  i32.add
                  local.tee 19
                  i32.const 255
                  i32.gt_u
                  br_if 0 (;@7;)
                end
                local.get 21
                br_if 2 (;@4;)
                local.get 24
                i32.const 255
                i32.and
                local.set 24
                br 1 (;@5;)
              end
              local.get 19
              br_if 1 (;@4;)
            end
            local.get 5
            i32.const 64
            i32.add
            local.get 24
            local.get 0
            call $__fwritex
            drop
            br 0 (;@4;)
          end
        end
        i32.const 0
        i32.const 61
        i32.store offset=4496
      end
      i32.const -1
      local.set 15
    end
    local.get 5
    i32.const 880
    i32.add
    global.set 0
    local.get 15)
  (func $pop_arg (type 10) (param i32 i32 i32)
    block  ;; label = @1
      local.get 1
      i32.const -9
      i32.add
      local.tee 1
      i32.const 17
      i32.gt_u
      br_if 0 (;@1;)
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              block  ;; label = @6
                block  ;; label = @7
                  block  ;; label = @8
                    block  ;; label = @9
                      block  ;; label = @10
                        block  ;; label = @11
                          block  ;; label = @12
                            block  ;; label = @13
                              block  ;; label = @14
                                block  ;; label = @15
                                  block  ;; label = @16
                                    block  ;; label = @17
                                      block  ;; label = @18
                                        block  ;; label = @19
                                          local.get 1
                                          br_table 17 (;@2;) 0 (;@19;) 1 (;@18;) 4 (;@15;) 2 (;@17;) 3 (;@16;) 5 (;@14;) 6 (;@13;) 7 (;@12;) 8 (;@11;) 9 (;@10;) 10 (;@9;) 11 (;@8;) 12 (;@7;) 13 (;@6;) 14 (;@5;) 15 (;@4;) 16 (;@3;) 17 (;@2;)
                                        end
                                        local.get 2
                                        local.get 2
                                        i32.load
                                        local.tee 1
                                        i32.const 4
                                        i32.add
                                        i32.store
                                        local.get 0
                                        local.get 1
                                        i64.load32_s
                                        i64.store
                                        return
                                      end
                                      local.get 2
                                      local.get 2
                                      i32.load
                                      local.tee 1
                                      i32.const 4
                                      i32.add
                                      i32.store
                                      local.get 0
                                      local.get 1
                                      i64.load32_u
                                      i64.store
                                      return
                                    end
                                    local.get 2
                                    local.get 2
                                    i32.load
                                    local.tee 1
                                    i32.const 4
                                    i32.add
                                    i32.store
                                    local.get 0
                                    local.get 1
                                    i64.load32_s
                                    i64.store
                                    return
                                  end
                                  local.get 2
                                  local.get 2
                                  i32.load
                                  local.tee 1
                                  i32.const 4
                                  i32.add
                                  i32.store
                                  local.get 0
                                  local.get 1
                                  i64.load32_u
                                  i64.store
                                  return
                                end
                                local.get 2
                                local.get 2
                                i32.load
                                i32.const 7
                                i32.add
                                i32.const -8
                                i32.and
                                local.tee 1
                                i32.const 8
                                i32.add
                                i32.store
                                local.get 0
                                local.get 1
                                i64.load
                                i64.store
                                return
                              end
                              local.get 2
                              local.get 2
                              i32.load
                              local.tee 1
                              i32.const 4
                              i32.add
                              i32.store
                              local.get 0
                              local.get 1
                              i64.load16_s
                              i64.store
                              return
                            end
                            local.get 2
                            local.get 2
                            i32.load
                            local.tee 1
                            i32.const 4
                            i32.add
                            i32.store
                            local.get 0
                            local.get 1
                            i64.load16_u
                            i64.store
                            return
                          end
                          local.get 2
                          local.get 2
                          i32.load
                          local.tee 1
                          i32.const 4
                          i32.add
                          i32.store
                          local.get 0
                          local.get 1
                          i64.load8_s
                          i64.store
                          return
                        end
                        local.get 2
                        local.get 2
                        i32.load
                        local.tee 1
                        i32.const 4
                        i32.add
                        i32.store
                        local.get 0
                        local.get 1
                        i64.load8_u
                        i64.store
                        return
                      end
                      local.get 2
                      local.get 2
                      i32.load
                      i32.const 7
                      i32.add
                      i32.const -8
                      i32.and
                      local.tee 1
                      i32.const 8
                      i32.add
                      i32.store
                      local.get 0
                      local.get 1
                      i64.load
                      i64.store
                      return
                    end
                    local.get 2
                    local.get 2
                    i32.load
                    local.tee 1
                    i32.const 4
                    i32.add
                    i32.store
                    local.get 0
                    local.get 1
                    i64.load32_u
                    i64.store
                    return
                  end
                  local.get 2
                  local.get 2
                  i32.load
                  i32.const 7
                  i32.add
                  i32.const -8
                  i32.and
                  local.tee 1
                  i32.const 8
                  i32.add
                  i32.store
                  local.get 0
                  local.get 1
                  i64.load
                  i64.store
                  return
                end
                local.get 2
                local.get 2
                i32.load
                i32.const 7
                i32.add
                i32.const -8
                i32.and
                local.tee 1
                i32.const 8
                i32.add
                i32.store
                local.get 0
                local.get 1
                i64.load
                i64.store
                return
              end
              local.get 2
              local.get 2
              i32.load
              local.tee 1
              i32.const 4
              i32.add
              i32.store
              local.get 0
              local.get 1
              i64.load32_s
              i64.store
              return
            end
            local.get 2
            local.get 2
            i32.load
            local.tee 1
            i32.const 4
            i32.add
            i32.store
            local.get 0
            local.get 1
            i64.load32_u
            i64.store
            return
          end
          local.get 2
          local.get 2
          i32.load
          i32.const 7
          i32.add
          i32.const -8
          i32.and
          local.tee 1
          i32.const 8
          i32.add
          i32.store
          local.get 0
          local.get 1
          i64.load
          i64.store
          return
        end
        call $long_double_not_supported
        unreachable
      end
      local.get 2
      local.get 2
      i32.load
      local.tee 1
      i32.const 4
      i32.add
      i32.store
      local.get 0
      local.get 1
      i32.load
      i32.store
    end)
  (func $long_double_not_supported (type 8)
    i32.const 3344
    i32.const 3872
    call $fputs
    drop
    call $abort
    unreachable)
  (func $__lseek (type 1) (param i32 i64 i32) (result i64)
    (local i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        local.get 1
        local.get 2
        i32.const 255
        i32.and
        local.get 3
        i32.const 8
        i32.add
        call $__wasi_fd_seek
        local.tee 0
        i32.eqz
        br_if 0 (;@2;)
        i32.const 0
        i32.const 70
        local.get 0
        local.get 0
        i32.const 76
        i32.eq
        select
        i32.store offset=4496
        i64.const -1
        local.set 1
        br 1 (;@1;)
      end
      local.get 3
      i64.load offset=8
      local.set 1
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 1)
  (func $__stdio_seek (type 1) (param i32 i64 i32) (result i64)
    local.get 0
    i32.load offset=56
    local.get 1
    local.get 2
    call $__lseek)
  (func $__towrite (type 4) (param i32) (result i32)
    (local i32)
    local.get 0
    local.get 0
    i32.load offset=60
    local.tee 1
    i32.const -1
    i32.add
    local.get 1
    i32.or
    i32.store offset=60
    block  ;; label = @1
      local.get 0
      i32.load
      local.tee 1
      i32.const 8
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.const 32
      i32.or
      i32.store
      i32.const -1
      return
    end
    local.get 0
    i64.const 0
    i64.store offset=4 align=4
    local.get 0
    local.get 0
    i32.load offset=40
    local.tee 1
    i32.store offset=24
    local.get 0
    local.get 1
    i32.store offset=20
    local.get 0
    local.get 1
    local.get 0
    i32.load offset=44
    i32.add
    i32.store offset=16
    i32.const 0)
  (func $fputs (type 3) (param i32 i32) (result i32)
    (local i32)
    i32.const -1
    i32.const 0
    local.get 0
    call $strlen
    local.tee 2
    local.get 0
    i32.const 1
    local.get 2
    local.get 1
    call $fwrite
    i32.ne
    select)
  (func $close (type 4) (param i32) (result i32)
    block  ;; label = @1
      local.get 0
      call $__wasi_fd_close
      local.tee 0
      br_if 0 (;@1;)
      i32.const 0
      return
    end
    i32.const 0
    local.get 0
    i32.store offset=4496
    i32.const -1)
  (func $__stdio_close (type 4) (param i32) (result i32)
    local.get 0
    i32.load offset=56
    call $close)
  (func $fgets (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32)
    local.get 1
    i32.const -1
    i32.add
    local.set 3
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          local.get 1
          i32.const 2
          i32.lt_s
          br_if 0 (;@3;)
          local.get 0
          local.set 1
          block  ;; label = @4
            loop  ;; label = @5
              local.get 3
              i32.eqz
              br_if 1 (;@4;)
              block  ;; label = @6
                block  ;; label = @7
                  local.get 2
                  i32.load offset=4
                  local.tee 4
                  local.get 2
                  i32.load offset=8
                  local.tee 5
                  i32.eq
                  br_if 0 (;@7;)
                  local.get 1
                  local.get 4
                  local.get 4
                  i32.const 10
                  local.get 5
                  local.get 4
                  i32.sub
                  local.tee 5
                  call $memchr
                  local.tee 6
                  local.get 4
                  i32.sub
                  i32.const 1
                  i32.add
                  local.get 5
                  local.get 6
                  select
                  local.tee 5
                  local.get 3
                  local.get 5
                  local.get 3
                  i32.lt_u
                  select
                  local.tee 5
                  call $memcpy
                  local.set 1
                  local.get 2
                  local.get 2
                  i32.load offset=4
                  local.get 5
                  i32.add
                  local.tee 4
                  i32.store offset=4
                  local.get 1
                  local.get 5
                  i32.add
                  local.set 1
                  local.get 6
                  br_if 3 (;@4;)
                  local.get 3
                  local.get 5
                  i32.sub
                  local.tee 3
                  i32.eqz
                  br_if 3 (;@4;)
                  local.get 4
                  local.get 2
                  i32.load offset=8
                  i32.eq
                  br_if 0 (;@7;)
                  local.get 2
                  local.get 4
                  i32.const 1
                  i32.add
                  i32.store offset=4
                  local.get 4
                  i32.load8_u
                  local.set 4
                  br 1 (;@6;)
                end
                local.get 2
                call $__uflow
                local.tee 4
                i32.const -1
                i32.gt_s
                br_if 0 (;@6;)
                i32.const 0
                local.set 4
                local.get 1
                local.get 0
                i32.eq
                br_if 5 (;@1;)
                local.get 2
                i32.load8_u
                i32.const 16
                i32.and
                i32.eqz
                br_if 5 (;@1;)
                br 2 (;@4;)
              end
              local.get 1
              local.get 4
              i32.store8
              local.get 1
              i32.const 1
              i32.add
              local.set 1
              local.get 3
              i32.const -1
              i32.add
              local.set 3
              local.get 4
              i32.const 255
              i32.and
              i32.const 10
              i32.ne
              br_if 0 (;@5;)
            end
          end
          block  ;; label = @4
            local.get 0
            br_if 0 (;@4;)
            i32.const 0
            return
          end
          local.get 1
          i32.const 0
          i32.store8
          br 1 (;@2;)
        end
        local.get 2
        local.get 2
        i32.load offset=60
        local.tee 1
        i32.const -1
        i32.add
        local.get 1
        i32.or
        i32.store offset=60
        i32.const 0
        local.set 4
        local.get 3
        br_if 1 (;@1;)
        local.get 0
        i32.const 0
        i32.store8
      end
      local.get 0
      local.set 4
    end
    local.get 4)
  (func $__stdio_exit (type 8)
    (local i32 i32 i32)
    block  ;; label = @1
      call $__ofl_lock
      i32.load
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      loop  ;; label = @2
        block  ;; label = @3
          local.get 0
          i32.load offset=20
          local.get 0
          i32.load offset=24
          i32.eq
          br_if 0 (;@3;)
          local.get 0
          i32.const 0
          i32.const 0
          local.get 0
          i32.load offset=32
          call_indirect (type 0)
          drop
        end
        block  ;; label = @3
          local.get 0
          i32.load offset=4
          local.tee 1
          local.get 0
          i32.load offset=8
          local.tee 2
          i32.eq
          br_if 0 (;@3;)
          local.get 0
          local.get 1
          local.get 2
          i32.sub
          i64.extend_i32_s
          i32.const 1
          local.get 0
          i32.load offset=36
          call_indirect (type 1)
          drop
        end
        local.get 0
        i32.load offset=52
        local.tee 0
        br_if 0 (;@2;)
      end
    end
    block  ;; label = @1
      i32.const 0
      i32.load offset=3744
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 0
        i32.load offset=20
        local.get 0
        i32.load offset=24
        i32.eq
        br_if 0 (;@2;)
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=32
        call_indirect (type 0)
        drop
      end
      local.get 0
      i32.load offset=4
      local.tee 1
      local.get 0
      i32.load offset=8
      local.tee 2
      i32.eq
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      local.get 2
      i32.sub
      i64.extend_i32_s
      i32.const 1
      local.get 0
      i32.load offset=36
      call_indirect (type 1)
      drop
    end
    block  ;; label = @1
      i32.const 0
      i32.load offset=3864
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 0
        i32.load offset=20
        local.get 0
        i32.load offset=24
        i32.eq
        br_if 0 (;@2;)
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=32
        call_indirect (type 0)
        drop
      end
      local.get 0
      i32.load offset=4
      local.tee 1
      local.get 0
      i32.load offset=8
      local.tee 2
      i32.eq
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      local.get 2
      i32.sub
      i64.extend_i32_s
      i32.const 1
      local.get 0
      i32.load offset=36
      call_indirect (type 1)
      drop
    end
    block  ;; label = @1
      i32.const 0
      i32.load offset=3984
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 0
        i32.load offset=20
        local.get 0
        i32.load offset=24
        i32.eq
        br_if 0 (;@2;)
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=32
        call_indirect (type 0)
        drop
      end
      local.get 0
      i32.load offset=4
      local.tee 1
      local.get 0
      i32.load offset=8
      local.tee 2
      i32.eq
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      local.get 2
      i32.sub
      i64.extend_i32_s
      i32.const 1
      local.get 0
      i32.load offset=36
      call_indirect (type 1)
      drop
    end)
  (func $__isatty (type 4) (param i32) (result i32)
    (local i32 i32)
    global.get 0
    i32.const 32
    i32.sub
    local.tee 1
    global.set 0
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        local.get 1
        i32.const 8
        i32.add
        call $__wasi_fd_fdstat_get
        local.tee 0
        br_if 0 (;@2;)
        i32.const 59
        local.set 0
        local.get 1
        i32.load8_u offset=8
        i32.const 2
        i32.ne
        br_if 0 (;@2;)
        local.get 1
        i32.load8_u offset=16
        i32.const 36
        i32.and
        br_if 0 (;@2;)
        i32.const 1
        local.set 2
        br 1 (;@1;)
      end
      i32.const 0
      local.set 2
      i32.const 0
      local.get 0
      i32.store offset=4496
    end
    local.get 1
    i32.const 32
    i32.add
    global.set 0
    local.get 2)
  (func $__stdout_write (type 0) (param i32 i32 i32) (result i32)
    local.get 0
    i32.const 5
    i32.store offset=32
    block  ;; label = @1
      local.get 0
      i32.load8_u
      i32.const 64
      i32.and
      br_if 0 (;@1;)
      local.get 0
      i32.load offset=56
      call $__isatty
      br_if 0 (;@1;)
      local.get 0
      i32.const -1
      i32.store offset=64
    end
    local.get 0
    local.get 1
    local.get 2
    call $__stdio_write)
  (func $readv (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    i32.const -1
    local.set 4
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.const -1
        i32.gt_s
        br_if 0 (;@2;)
        i32.const 0
        i32.const 28
        i32.store offset=4496
        br 1 (;@1;)
      end
      block  ;; label = @2
        local.get 0
        local.get 1
        local.get 2
        local.get 3
        i32.const 12
        i32.add
        call $__wasi_fd_read
        local.tee 2
        i32.eqz
        br_if 0 (;@2;)
        i32.const 0
        local.get 2
        i32.store offset=4496
        i32.const -1
        local.set 4
        br 1 (;@1;)
      end
      local.get 3
      i32.load offset=12
      local.set 4
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 4)
  (func $read (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    local.get 3
    local.get 2
    i32.store offset=12
    local.get 3
    local.get 1
    i32.store offset=8
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        local.get 3
        i32.const 8
        i32.add
        i32.const 1
        local.get 3
        i32.const 4
        i32.add
        call $__wasi_fd_read
        local.tee 0
        i32.eqz
        br_if 0 (;@2;)
        i32.const 0
        i32.const 8
        local.get 0
        local.get 0
        i32.const 76
        i32.eq
        select
        i32.store offset=4496
        i32.const -1
        local.set 0
        br 1 (;@1;)
      end
      local.get 3
      i32.load offset=4
      local.set 0
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 0)
  (func $__stdio_read (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    local.get 3
    local.get 1
    i32.store
    local.get 3
    local.get 0
    i32.load offset=44
    local.tee 4
    i32.store offset=12
    local.get 3
    local.get 0
    i32.load offset=40
    local.tee 5
    i32.store offset=8
    local.get 3
    local.get 2
    local.get 4
    i32.const 0
    i32.ne
    i32.sub
    local.tee 6
    i32.store offset=4
    local.get 0
    i32.load offset=56
    local.set 7
    block  ;; label = @1
      block  ;; label = @2
        local.get 6
        i32.eqz
        br_if 0 (;@2;)
        local.get 7
        local.get 3
        i32.const 2
        call $readv
        local.set 4
        br 1 (;@1;)
      end
      local.get 7
      local.get 5
      local.get 4
      call $read
      local.set 4
    end
    i32.const 0
    local.set 6
    block  ;; label = @1
      block  ;; label = @2
        local.get 4
        i32.const 0
        i32.gt_s
        br_if 0 (;@2;)
        local.get 0
        local.get 0
        i32.load
        i32.const 32
        i32.const 16
        local.get 4
        select
        i32.or
        i32.store
        br 1 (;@1;)
      end
      block  ;; label = @2
        local.get 4
        local.get 3
        i32.load offset=4
        local.tee 7
        i32.gt_u
        br_if 0 (;@2;)
        local.get 4
        local.set 6
        br 1 (;@1;)
      end
      local.get 0
      local.get 0
      i32.load offset=40
      local.tee 6
      i32.store offset=4
      local.get 0
      local.get 6
      local.get 4
      local.get 7
      i32.sub
      i32.add
      i32.store offset=8
      block  ;; label = @2
        local.get 0
        i32.load offset=44
        i32.eqz
        br_if 0 (;@2;)
        local.get 0
        local.get 6
        i32.const 1
        i32.add
        i32.store offset=4
        local.get 2
        local.get 1
        i32.add
        i32.const -1
        i32.add
        local.get 6
        i32.load8_u
        i32.store8
      end
      local.get 2
      local.set 6
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 6)
  (func $__fwritex (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32)
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.load offset=16
        local.tee 3
        br_if 0 (;@2;)
        i32.const 0
        local.set 4
        local.get 2
        call $__towrite
        br_if 1 (;@1;)
        local.get 2
        i32.load offset=16
        local.set 3
      end
      block  ;; label = @2
        local.get 3
        local.get 2
        i32.load offset=20
        local.tee 5
        i32.sub
        local.get 1
        i32.ge_u
        br_if 0 (;@2;)
        local.get 2
        local.get 0
        local.get 1
        local.get 2
        i32.load offset=32
        call_indirect (type 0)
        return
      end
      i32.const 0
      local.set 6
      block  ;; label = @2
        local.get 2
        i32.load offset=64
        i32.const 0
        i32.lt_s
        br_if 0 (;@2;)
        i32.const 0
        local.set 6
        local.get 0
        local.set 4
        i32.const 0
        local.set 3
        loop  ;; label = @3
          local.get 1
          local.get 3
          i32.eq
          br_if 1 (;@2;)
          local.get 3
          i32.const 1
          i32.add
          local.set 3
          local.get 4
          local.get 1
          i32.add
          local.set 7
          local.get 4
          i32.const -1
          i32.add
          local.tee 8
          local.set 4
          local.get 7
          i32.const -1
          i32.add
          i32.load8_u
          i32.const 10
          i32.ne
          br_if 0 (;@3;)
        end
        local.get 2
        local.get 0
        local.get 1
        local.get 3
        i32.sub
        i32.const 1
        i32.add
        local.tee 6
        local.get 2
        i32.load offset=32
        call_indirect (type 0)
        local.tee 4
        local.get 6
        i32.lt_u
        br_if 1 (;@1;)
        local.get 8
        local.get 1
        i32.add
        i32.const 1
        i32.add
        local.set 0
        local.get 2
        i32.load offset=20
        local.set 5
        local.get 3
        i32.const -1
        i32.add
        local.set 1
      end
      local.get 5
      local.get 0
      local.get 1
      call $memcpy
      drop
      local.get 2
      local.get 2
      i32.load offset=20
      local.get 1
      i32.add
      i32.store offset=20
      local.get 6
      local.get 1
      i32.add
      local.set 4
    end
    local.get 4)
  (func $fwrite (type 7) (param i32 i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32)
    local.get 2
    local.get 1
    i32.mul
    local.set 4
    block  ;; label = @1
      block  ;; label = @2
        local.get 3
        i32.load offset=16
        local.tee 5
        br_if 0 (;@2;)
        i32.const 0
        local.set 5
        local.get 3
        call $__towrite
        br_if 1 (;@1;)
        local.get 3
        i32.load offset=16
        local.set 5
      end
      block  ;; label = @2
        local.get 5
        local.get 3
        i32.load offset=20
        local.tee 6
        i32.sub
        local.get 4
        i32.ge_u
        br_if 0 (;@2;)
        local.get 3
        local.get 0
        local.get 4
        local.get 3
        i32.load offset=32
        call_indirect (type 0)
        local.set 5
        br 1 (;@1;)
      end
      i32.const 0
      local.set 7
      block  ;; label = @2
        block  ;; label = @3
          local.get 3
          i32.load offset=64
          i32.const 0
          i32.ge_s
          br_if 0 (;@3;)
          local.get 4
          local.set 5
          br 1 (;@2;)
        end
        local.get 0
        local.get 4
        i32.add
        local.set 8
        i32.const 0
        local.set 7
        i32.const 0
        local.set 5
        loop  ;; label = @3
          block  ;; label = @4
            local.get 4
            local.get 5
            i32.add
            br_if 0 (;@4;)
            local.get 4
            local.set 5
            br 2 (;@2;)
          end
          local.get 8
          local.get 5
          i32.add
          local.set 9
          local.get 5
          i32.const -1
          i32.add
          local.tee 10
          local.set 5
          local.get 9
          i32.const -1
          i32.add
          i32.load8_u
          i32.const 10
          i32.ne
          br_if 0 (;@3;)
        end
        local.get 3
        local.get 0
        local.get 4
        local.get 10
        i32.add
        i32.const 1
        i32.add
        local.tee 7
        local.get 3
        i32.load offset=32
        call_indirect (type 0)
        local.tee 5
        local.get 7
        i32.lt_u
        br_if 1 (;@1;)
        local.get 10
        i32.const -1
        i32.xor
        local.set 5
        local.get 8
        local.get 10
        i32.add
        i32.const 1
        i32.add
        local.set 0
        local.get 3
        i32.load offset=20
        local.set 6
      end
      local.get 6
      local.get 0
      local.get 5
      call $memcpy
      drop
      local.get 3
      local.get 3
      i32.load offset=20
      local.get 5
      i32.add
      i32.store offset=20
      local.get 7
      local.get 5
      i32.add
      local.set 5
    end
    block  ;; label = @1
      local.get 5
      local.get 4
      i32.ne
      br_if 0 (;@1;)
      local.get 2
      i32.const 0
      local.get 1
      select
      return
    end
    local.get 5
    local.get 1
    i32.div_u)
  (func $writev (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    i32.const -1
    local.set 4
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.const -1
        i32.gt_s
        br_if 0 (;@2;)
        i32.const 0
        i32.const 28
        i32.store offset=4496
        br 1 (;@1;)
      end
      block  ;; label = @2
        local.get 0
        local.get 1
        local.get 2
        local.get 3
        i32.const 12
        i32.add
        call $__wasi_fd_write
        local.tee 2
        i32.eqz
        br_if 0 (;@2;)
        i32.const 0
        local.get 2
        i32.store offset=4496
        i32.const -1
        local.set 4
        br 1 (;@1;)
      end
      local.get 3
      i32.load offset=12
      local.set 4
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 4)
  (func $__stdio_write (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 3
    global.set 0
    local.get 3
    local.get 2
    i32.store offset=12
    local.get 3
    local.get 1
    i32.store offset=8
    local.get 3
    local.get 0
    i32.load offset=24
    local.tee 1
    i32.store
    local.get 3
    local.get 0
    i32.load offset=20
    local.get 1
    i32.sub
    local.tee 1
    i32.store offset=4
    i32.const 2
    local.set 4
    block  ;; label = @1
      block  ;; label = @2
        local.get 1
        local.get 2
        i32.add
        local.tee 5
        local.get 0
        i32.load offset=56
        local.get 3
        i32.const 2
        call $writev
        local.tee 6
        i32.eq
        br_if 0 (;@2;)
        local.get 3
        local.set 1
        loop  ;; label = @3
          block  ;; label = @4
            local.get 6
            i32.const -1
            i32.gt_s
            br_if 0 (;@4;)
            i32.const 0
            local.set 6
            local.get 0
            i32.const 0
            i32.store offset=24
            local.get 0
            i64.const 0
            i64.store offset=16
            local.get 0
            local.get 0
            i32.load
            i32.const 32
            i32.or
            i32.store
            local.get 4
            i32.const 2
            i32.eq
            br_if 3 (;@1;)
            local.get 2
            local.get 1
            i32.load offset=4
            i32.sub
            local.set 6
            br 3 (;@1;)
          end
          local.get 1
          i32.const 8
          i32.add
          local.get 1
          local.get 6
          local.get 1
          i32.load offset=4
          local.tee 7
          i32.gt_u
          local.tee 8
          select
          local.tee 1
          local.get 1
          i32.load
          local.get 6
          local.get 7
          i32.const 0
          local.get 8
          select
          i32.sub
          local.tee 7
          i32.add
          i32.store
          local.get 1
          local.get 1
          i32.load offset=4
          local.get 7
          i32.sub
          i32.store offset=4
          local.get 5
          local.get 6
          i32.sub
          local.set 5
          local.get 0
          i32.load offset=56
          local.get 1
          local.get 4
          local.get 8
          i32.sub
          local.tee 4
          call $writev
          local.tee 8
          local.set 6
          local.get 5
          local.get 8
          i32.ne
          br_if 0 (;@3;)
        end
      end
      local.get 0
      local.get 0
      i32.load offset=40
      local.tee 1
      i32.store offset=24
      local.get 0
      local.get 1
      i32.store offset=20
      local.get 0
      local.get 1
      local.get 0
      i32.load offset=44
      i32.add
      i32.store offset=16
      local.get 2
      local.set 6
    end
    local.get 3
    i32.const 16
    i32.add
    global.set 0
    local.get 6)
  (func $__uflow (type 4) (param i32) (result i32)
    (local i32 i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 1
    global.set 0
    i32.const -1
    local.set 2
    block  ;; label = @1
      local.get 0
      call $__toread
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.const 15
      i32.add
      i32.const 1
      local.get 0
      i32.load offset=28
      call_indirect (type 0)
      i32.const 1
      i32.ne
      br_if 0 (;@1;)
      local.get 1
      i32.load8_u offset=15
      local.set 2
    end
    local.get 1
    i32.const 16
    i32.add
    global.set 0
    local.get 2)
  (func $__toread (type 4) (param i32) (result i32)
    (local i32 i32)
    local.get 0
    local.get 0
    i32.load offset=60
    local.tee 1
    i32.const -1
    i32.add
    local.get 1
    i32.or
    i32.store offset=60
    block  ;; label = @1
      local.get 0
      i32.load offset=20
      local.get 0
      i32.load offset=24
      i32.eq
      br_if 0 (;@1;)
      local.get 0
      i32.const 0
      i32.const 0
      local.get 0
      i32.load offset=32
      call_indirect (type 0)
      drop
    end
    local.get 0
    i32.const 0
    i32.store offset=24
    local.get 0
    i64.const 0
    i64.store offset=16
    block  ;; label = @1
      local.get 0
      i32.load
      local.tee 1
      i32.const 4
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.const 32
      i32.or
      i32.store
      i32.const -1
      return
    end
    local.get 0
    local.get 0
    i32.load offset=40
    local.get 0
    i32.load offset=44
    i32.add
    local.tee 2
    i32.store offset=8
    local.get 0
    local.get 2
    i32.store offset=4
    local.get 1
    i32.const 27
    i32.shl
    i32.const 31
    i32.shr_s)
  (func $__ofl_lock (type 5) (result i32)
    i32.const 6608)
  (func $memcmp (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32)
    i32.const 0
    local.set 3
    block  ;; label = @1
      local.get 2
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        loop  ;; label = @3
          local.get 0
          i32.load8_u
          local.tee 4
          local.get 1
          i32.load8_u
          local.tee 5
          i32.ne
          br_if 1 (;@2;)
          local.get 1
          i32.const 1
          i32.add
          local.set 1
          local.get 0
          i32.const 1
          i32.add
          local.set 0
          local.get 2
          i32.const -1
          i32.add
          local.tee 2
          br_if 0 (;@3;)
          br 2 (;@1;)
        end
      end
      local.get 4
      local.get 5
      i32.sub
      local.set 3
    end
    local.get 3)
  (func $strnlen (type 3) (param i32 i32) (result i32)
    (local i32)
    local.get 0
    i32.const 0
    local.get 1
    call $memchr
    local.tee 2
    local.get 0
    i32.sub
    local.get 1
    local.get 2
    select)
  (func $memcpy (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32)
    block  ;; label = @1
      block  ;; label = @2
        local.get 2
        i32.eqz
        br_if 0 (;@2;)
        local.get 1
        i32.const 3
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 0
        local.set 3
        loop  ;; label = @3
          local.get 3
          local.get 1
          i32.load8_u
          i32.store8
          local.get 2
          i32.const -1
          i32.add
          local.set 4
          local.get 3
          i32.const 1
          i32.add
          local.set 3
          local.get 1
          i32.const 1
          i32.add
          local.set 1
          local.get 2
          i32.const 1
          i32.eq
          br_if 2 (;@1;)
          local.get 4
          local.set 2
          local.get 1
          i32.const 3
          i32.and
          br_if 0 (;@3;)
          br 2 (;@1;)
        end
      end
      local.get 2
      local.set 4
      local.get 0
      local.set 3
    end
    block  ;; label = @1
      block  ;; label = @2
        local.get 3
        i32.const 3
        i32.and
        local.tee 2
        br_if 0 (;@2;)
        block  ;; label = @3
          block  ;; label = @4
            local.get 4
            i32.const 16
            i32.ge_u
            br_if 0 (;@4;)
            local.get 4
            local.set 2
            br 1 (;@3;)
          end
          local.get 4
          i32.const -16
          i32.add
          local.set 2
          loop  ;; label = @4
            local.get 3
            local.get 1
            i32.load
            i32.store
            local.get 3
            i32.const 4
            i32.add
            local.get 1
            i32.const 4
            i32.add
            i32.load
            i32.store
            local.get 3
            i32.const 8
            i32.add
            local.get 1
            i32.const 8
            i32.add
            i32.load
            i32.store
            local.get 3
            i32.const 12
            i32.add
            local.get 1
            i32.const 12
            i32.add
            i32.load
            i32.store
            local.get 3
            i32.const 16
            i32.add
            local.set 3
            local.get 1
            i32.const 16
            i32.add
            local.set 1
            local.get 4
            i32.const -16
            i32.add
            local.tee 4
            i32.const 15
            i32.gt_u
            br_if 0 (;@4;)
          end
        end
        block  ;; label = @3
          local.get 2
          i32.const 8
          i32.and
          i32.eqz
          br_if 0 (;@3;)
          local.get 3
          local.get 1
          i64.load align=4
          i64.store align=4
          local.get 1
          i32.const 8
          i32.add
          local.set 1
          local.get 3
          i32.const 8
          i32.add
          local.set 3
        end
        block  ;; label = @3
          local.get 2
          i32.const 4
          i32.and
          i32.eqz
          br_if 0 (;@3;)
          local.get 3
          local.get 1
          i32.load
          i32.store
          local.get 1
          i32.const 4
          i32.add
          local.set 1
          local.get 3
          i32.const 4
          i32.add
          local.set 3
        end
        block  ;; label = @3
          local.get 2
          i32.const 2
          i32.and
          i32.eqz
          br_if 0 (;@3;)
          local.get 3
          local.get 1
          i32.load8_u
          i32.store8
          local.get 3
          local.get 1
          i32.load8_u offset=1
          i32.store8 offset=1
          local.get 3
          i32.const 2
          i32.add
          local.set 3
          local.get 1
          i32.const 2
          i32.add
          local.set 1
        end
        local.get 2
        i32.const 1
        i32.and
        i32.eqz
        br_if 1 (;@1;)
        local.get 3
        local.get 1
        i32.load8_u
        i32.store8
        local.get 0
        return
      end
      block  ;; label = @2
        local.get 4
        i32.const 32
        i32.lt_u
        br_if 0 (;@2;)
        local.get 2
        i32.const -1
        i32.add
        local.tee 2
        i32.const 2
        i32.gt_u
        br_if 0 (;@2;)
        block  ;; label = @3
          block  ;; label = @4
            block  ;; label = @5
              local.get 2
              br_table 0 (;@5;) 1 (;@4;) 2 (;@3;) 0 (;@5;)
            end
            local.get 3
            local.get 1
            i32.load8_u offset=1
            i32.store8 offset=1
            local.get 3
            local.get 1
            i32.load
            local.tee 5
            i32.store8
            local.get 3
            local.get 1
            i32.load8_u offset=2
            i32.store8 offset=2
            local.get 4
            i32.const -3
            i32.add
            local.set 6
            local.get 3
            i32.const 3
            i32.add
            local.set 7
            local.get 4
            i32.const -20
            i32.add
            i32.const -16
            i32.and
            local.set 8
            i32.const 0
            local.set 2
            loop  ;; label = @5
              local.get 7
              local.get 2
              i32.add
              local.tee 3
              local.get 1
              local.get 2
              i32.add
              local.tee 9
              i32.const 4
              i32.add
              i32.load
              local.tee 10
              i32.const 8
              i32.shl
              local.get 5
              i32.const 24
              i32.shr_u
              i32.or
              i32.store
              local.get 3
              i32.const 4
              i32.add
              local.get 9
              i32.const 8
              i32.add
              i32.load
              local.tee 5
              i32.const 8
              i32.shl
              local.get 10
              i32.const 24
              i32.shr_u
              i32.or
              i32.store
              local.get 3
              i32.const 8
              i32.add
              local.get 9
              i32.const 12
              i32.add
              i32.load
              local.tee 10
              i32.const 8
              i32.shl
              local.get 5
              i32.const 24
              i32.shr_u
              i32.or
              i32.store
              local.get 3
              i32.const 12
              i32.add
              local.get 9
              i32.const 16
              i32.add
              i32.load
              local.tee 5
              i32.const 8
              i32.shl
              local.get 10
              i32.const 24
              i32.shr_u
              i32.or
              i32.store
              local.get 2
              i32.const 16
              i32.add
              local.set 2
              local.get 6
              i32.const -16
              i32.add
              local.tee 6
              i32.const 16
              i32.gt_u
              br_if 0 (;@5;)
            end
            local.get 7
            local.get 2
            i32.add
            local.set 3
            local.get 1
            local.get 2
            i32.add
            i32.const 3
            i32.add
            local.set 1
            local.get 4
            local.get 8
            i32.sub
            i32.const -19
            i32.add
            local.set 4
            br 2 (;@2;)
          end
          local.get 3
          local.get 1
          i32.load
          local.tee 5
          i32.store8
          local.get 3
          local.get 1
          i32.load8_u offset=1
          i32.store8 offset=1
          local.get 4
          i32.const -2
          i32.add
          local.set 6
          local.get 3
          i32.const 2
          i32.add
          local.set 7
          local.get 4
          i32.const -20
          i32.add
          i32.const -16
          i32.and
          local.set 8
          i32.const 0
          local.set 2
          loop  ;; label = @4
            local.get 7
            local.get 2
            i32.add
            local.tee 3
            local.get 1
            local.get 2
            i32.add
            local.tee 9
            i32.const 4
            i32.add
            i32.load
            local.tee 10
            i32.const 16
            i32.shl
            local.get 5
            i32.const 16
            i32.shr_u
            i32.or
            i32.store
            local.get 3
            i32.const 4
            i32.add
            local.get 9
            i32.const 8
            i32.add
            i32.load
            local.tee 5
            i32.const 16
            i32.shl
            local.get 10
            i32.const 16
            i32.shr_u
            i32.or
            i32.store
            local.get 3
            i32.const 8
            i32.add
            local.get 9
            i32.const 12
            i32.add
            i32.load
            local.tee 10
            i32.const 16
            i32.shl
            local.get 5
            i32.const 16
            i32.shr_u
            i32.or
            i32.store
            local.get 3
            i32.const 12
            i32.add
            local.get 9
            i32.const 16
            i32.add
            i32.load
            local.tee 5
            i32.const 16
            i32.shl
            local.get 10
            i32.const 16
            i32.shr_u
            i32.or
            i32.store
            local.get 2
            i32.const 16
            i32.add
            local.set 2
            local.get 6
            i32.const -16
            i32.add
            local.tee 6
            i32.const 17
            i32.gt_u
            br_if 0 (;@4;)
          end
          local.get 7
          local.get 2
          i32.add
          local.set 3
          local.get 1
          local.get 2
          i32.add
          i32.const 2
          i32.add
          local.set 1
          local.get 4
          local.get 8
          i32.sub
          i32.const -18
          i32.add
          local.set 4
          br 1 (;@2;)
        end
        local.get 3
        local.get 1
        i32.load
        local.tee 5
        i32.store8
        local.get 4
        i32.const -1
        i32.add
        local.set 6
        local.get 3
        i32.const 1
        i32.add
        local.set 7
        local.get 4
        i32.const -20
        i32.add
        i32.const -16
        i32.and
        local.set 8
        i32.const 0
        local.set 2
        loop  ;; label = @3
          local.get 7
          local.get 2
          i32.add
          local.tee 3
          local.get 1
          local.get 2
          i32.add
          local.tee 9
          i32.const 4
          i32.add
          i32.load
          local.tee 10
          i32.const 24
          i32.shl
          local.get 5
          i32.const 8
          i32.shr_u
          i32.or
          i32.store
          local.get 3
          i32.const 4
          i32.add
          local.get 9
          i32.const 8
          i32.add
          i32.load
          local.tee 5
          i32.const 24
          i32.shl
          local.get 10
          i32.const 8
          i32.shr_u
          i32.or
          i32.store
          local.get 3
          i32.const 8
          i32.add
          local.get 9
          i32.const 12
          i32.add
          i32.load
          local.tee 10
          i32.const 24
          i32.shl
          local.get 5
          i32.const 8
          i32.shr_u
          i32.or
          i32.store
          local.get 3
          i32.const 12
          i32.add
          local.get 9
          i32.const 16
          i32.add
          i32.load
          local.tee 5
          i32.const 24
          i32.shl
          local.get 10
          i32.const 8
          i32.shr_u
          i32.or
          i32.store
          local.get 2
          i32.const 16
          i32.add
          local.set 2
          local.get 6
          i32.const -16
          i32.add
          local.tee 6
          i32.const 18
          i32.gt_u
          br_if 0 (;@3;)
        end
        local.get 7
        local.get 2
        i32.add
        local.set 3
        local.get 1
        local.get 2
        i32.add
        i32.const 1
        i32.add
        local.set 1
        local.get 4
        local.get 8
        i32.sub
        i32.const -17
        i32.add
        local.set 4
      end
      block  ;; label = @2
        local.get 4
        i32.const 16
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 3
        local.get 1
        i32.load16_u align=1
        i32.store16 align=1
        local.get 3
        local.get 1
        i32.load8_u offset=2
        i32.store8 offset=2
        local.get 3
        local.get 1
        i32.load8_u offset=3
        i32.store8 offset=3
        local.get 3
        local.get 1
        i32.load8_u offset=4
        i32.store8 offset=4
        local.get 3
        local.get 1
        i32.load8_u offset=5
        i32.store8 offset=5
        local.get 3
        local.get 1
        i32.load8_u offset=6
        i32.store8 offset=6
        local.get 3
        local.get 1
        i32.load8_u offset=7
        i32.store8 offset=7
        local.get 3
        local.get 1
        i32.load8_u offset=8
        i32.store8 offset=8
        local.get 3
        local.get 1
        i32.load8_u offset=9
        i32.store8 offset=9
        local.get 3
        local.get 1
        i32.load8_u offset=10
        i32.store8 offset=10
        local.get 3
        local.get 1
        i32.load8_u offset=11
        i32.store8 offset=11
        local.get 3
        local.get 1
        i32.load8_u offset=12
        i32.store8 offset=12
        local.get 3
        local.get 1
        i32.load8_u offset=13
        i32.store8 offset=13
        local.get 3
        local.get 1
        i32.load8_u offset=14
        i32.store8 offset=14
        local.get 3
        local.get 1
        i32.load8_u offset=15
        i32.store8 offset=15
        local.get 3
        i32.const 16
        i32.add
        local.set 3
        local.get 1
        i32.const 16
        i32.add
        local.set 1
      end
      block  ;; label = @2
        local.get 4
        i32.const 8
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 3
        local.get 1
        i32.load8_u
        i32.store8
        local.get 3
        local.get 1
        i32.load8_u offset=1
        i32.store8 offset=1
        local.get 3
        local.get 1
        i32.load8_u offset=2
        i32.store8 offset=2
        local.get 3
        local.get 1
        i32.load8_u offset=3
        i32.store8 offset=3
        local.get 3
        local.get 1
        i32.load8_u offset=4
        i32.store8 offset=4
        local.get 3
        local.get 1
        i32.load8_u offset=5
        i32.store8 offset=5
        local.get 3
        local.get 1
        i32.load8_u offset=6
        i32.store8 offset=6
        local.get 3
        local.get 1
        i32.load8_u offset=7
        i32.store8 offset=7
        local.get 3
        i32.const 8
        i32.add
        local.set 3
        local.get 1
        i32.const 8
        i32.add
        local.set 1
      end
      block  ;; label = @2
        local.get 4
        i32.const 4
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 3
        local.get 1
        i32.load8_u
        i32.store8
        local.get 3
        local.get 1
        i32.load8_u offset=1
        i32.store8 offset=1
        local.get 3
        local.get 1
        i32.load8_u offset=2
        i32.store8 offset=2
        local.get 3
        local.get 1
        i32.load8_u offset=3
        i32.store8 offset=3
        local.get 3
        i32.const 4
        i32.add
        local.set 3
        local.get 1
        i32.const 4
        i32.add
        local.set 1
      end
      block  ;; label = @2
        local.get 4
        i32.const 2
        i32.and
        i32.eqz
        br_if 0 (;@2;)
        local.get 3
        local.get 1
        i32.load8_u
        i32.store8
        local.get 3
        local.get 1
        i32.load8_u offset=1
        i32.store8 offset=1
        local.get 3
        i32.const 2
        i32.add
        local.set 3
        local.get 1
        i32.const 2
        i32.add
        local.set 1
      end
      local.get 4
      i32.const 1
      i32.and
      i32.eqz
      br_if 0 (;@1;)
      local.get 3
      local.get 1
      i32.load8_u
      i32.store8
    end
    local.get 0)
  (func $strlen (type 4) (param i32) (result i32)
    (local i32 i32 i32)
    local.get 0
    local.set 1
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          local.get 0
          i32.const 3
          i32.and
          i32.eqz
          br_if 0 (;@3;)
          block  ;; label = @4
            local.get 0
            i32.load8_u
            br_if 0 (;@4;)
            local.get 0
            local.get 0
            i32.sub
            return
          end
          local.get 0
          i32.const 1
          i32.add
          local.set 1
          loop  ;; label = @4
            local.get 1
            i32.const 3
            i32.and
            i32.eqz
            br_if 1 (;@3;)
            local.get 1
            i32.load8_u
            local.set 2
            local.get 1
            i32.const 1
            i32.add
            local.tee 3
            local.set 1
            local.get 2
            i32.eqz
            br_if 2 (;@2;)
            br 0 (;@4;)
          end
        end
        local.get 1
        i32.const -4
        i32.add
        local.set 1
        loop  ;; label = @3
          local.get 1
          i32.const 4
          i32.add
          local.tee 1
          i32.load
          local.tee 2
          i32.const -1
          i32.xor
          local.get 2
          i32.const -16843009
          i32.add
          i32.and
          i32.const -2139062144
          i32.and
          i32.eqz
          br_if 0 (;@3;)
        end
        block  ;; label = @3
          local.get 2
          i32.const 255
          i32.and
          br_if 0 (;@3;)
          local.get 1
          local.get 0
          i32.sub
          return
        end
        loop  ;; label = @3
          local.get 1
          i32.load8_u offset=1
          local.set 2
          local.get 1
          i32.const 1
          i32.add
          local.tee 3
          local.set 1
          local.get 2
          br_if 0 (;@3;)
          br 2 (;@1;)
        end
      end
      local.get 3
      i32.const -1
      i32.add
      local.set 3
    end
    local.get 3
    local.get 0
    i32.sub)
  (func $memset (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i64)
    block  ;; label = @1
      local.get 2
      i32.eqz
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.store8
      local.get 2
      local.get 0
      i32.add
      local.tee 3
      i32.const -1
      i32.add
      local.get 1
      i32.store8
      local.get 2
      i32.const 3
      i32.lt_u
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.store8 offset=2
      local.get 0
      local.get 1
      i32.store8 offset=1
      local.get 3
      i32.const -3
      i32.add
      local.get 1
      i32.store8
      local.get 3
      i32.const -2
      i32.add
      local.get 1
      i32.store8
      local.get 2
      i32.const 7
      i32.lt_u
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      i32.store8 offset=3
      local.get 3
      i32.const -4
      i32.add
      local.get 1
      i32.store8
      local.get 2
      i32.const 9
      i32.lt_u
      br_if 0 (;@1;)
      local.get 0
      i32.const 0
      local.get 0
      i32.sub
      i32.const 3
      i32.and
      local.tee 4
      i32.add
      local.tee 3
      local.get 1
      i32.const 255
      i32.and
      i32.const 16843009
      i32.mul
      local.tee 1
      i32.store
      local.get 3
      local.get 2
      local.get 4
      i32.sub
      i32.const -4
      i32.and
      local.tee 4
      i32.add
      local.tee 2
      i32.const -4
      i32.add
      local.get 1
      i32.store
      local.get 4
      i32.const 9
      i32.lt_u
      br_if 0 (;@1;)
      local.get 3
      local.get 1
      i32.store offset=8
      local.get 3
      local.get 1
      i32.store offset=4
      local.get 2
      i32.const -8
      i32.add
      local.get 1
      i32.store
      local.get 2
      i32.const -12
      i32.add
      local.get 1
      i32.store
      local.get 4
      i32.const 25
      i32.lt_u
      br_if 0 (;@1;)
      local.get 3
      local.get 1
      i32.store offset=24
      local.get 3
      local.get 1
      i32.store offset=20
      local.get 3
      local.get 1
      i32.store offset=16
      local.get 3
      local.get 1
      i32.store offset=12
      local.get 2
      i32.const -16
      i32.add
      local.get 1
      i32.store
      local.get 2
      i32.const -20
      i32.add
      local.get 1
      i32.store
      local.get 2
      i32.const -24
      i32.add
      local.get 1
      i32.store
      local.get 2
      i32.const -28
      i32.add
      local.get 1
      i32.store
      local.get 4
      local.get 3
      i32.const 4
      i32.and
      i32.const 24
      i32.or
      local.tee 5
      i32.sub
      local.tee 2
      i32.const 32
      i32.lt_u
      br_if 0 (;@1;)
      local.get 1
      i64.extend_i32_u
      local.tee 6
      i64.const 32
      i64.shl
      local.get 6
      i64.or
      local.set 6
      local.get 3
      local.get 5
      i32.add
      local.set 1
      loop  ;; label = @2
        local.get 1
        local.get 6
        i64.store
        local.get 1
        i32.const 24
        i32.add
        local.get 6
        i64.store
        local.get 1
        i32.const 16
        i32.add
        local.get 6
        i64.store
        local.get 1
        i32.const 8
        i32.add
        local.get 6
        i64.store
        local.get 1
        i32.const 32
        i32.add
        local.set 1
        local.get 2
        i32.const -32
        i32.add
        local.tee 2
        i32.const 31
        i32.gt_u
        br_if 0 (;@2;)
      end
    end
    local.get 0)
  (func $memchr (type 0) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32)
    local.get 2
    i32.const 0
    i32.ne
    local.set 3
    block  ;; label = @1
      block  ;; label = @2
        block  ;; label = @3
          block  ;; label = @4
            local.get 2
            br_if 0 (;@4;)
            local.get 2
            local.set 4
            br 1 (;@3;)
          end
          block  ;; label = @4
            local.get 0
            i32.const 3
            i32.and
            br_if 0 (;@4;)
            local.get 2
            local.set 4
            br 1 (;@3;)
          end
          local.get 1
          i32.const 255
          i32.and
          local.set 5
          loop  ;; label = @4
            block  ;; label = @5
              local.get 0
              i32.load8_u
              local.get 5
              i32.ne
              br_if 0 (;@5;)
              local.get 2
              local.set 4
              br 3 (;@2;)
            end
            local.get 2
            i32.const 1
            i32.ne
            local.set 3
            local.get 2
            i32.const -1
            i32.add
            local.set 4
            local.get 0
            i32.const 1
            i32.add
            local.set 0
            local.get 2
            i32.const 1
            i32.eq
            br_if 1 (;@3;)
            local.get 4
            local.set 2
            local.get 0
            i32.const 3
            i32.and
            br_if 0 (;@4;)
          end
        end
        local.get 3
        i32.eqz
        br_if 1 (;@1;)
      end
      block  ;; label = @2
        local.get 0
        i32.load8_u
        local.get 1
        i32.const 255
        i32.and
        i32.eq
        br_if 0 (;@2;)
        local.get 4
        i32.const 4
        i32.lt_u
        br_if 0 (;@2;)
        local.get 1
        i32.const 255
        i32.and
        i32.const 16843009
        i32.mul
        local.set 3
        local.get 4
        i32.const -4
        i32.add
        local.tee 2
        i32.const 3
        i32.and
        local.set 5
        local.get 2
        i32.const -4
        i32.and
        local.get 0
        i32.add
        i32.const 4
        i32.add
        local.set 6
        loop  ;; label = @3
          local.get 0
          i32.load
          local.get 3
          i32.xor
          local.tee 2
          i32.const -1
          i32.xor
          local.get 2
          i32.const -16843009
          i32.add
          i32.and
          i32.const -2139062144
          i32.and
          br_if 1 (;@2;)
          local.get 0
          i32.const 4
          i32.add
          local.set 0
          local.get 4
          i32.const -4
          i32.add
          local.tee 4
          i32.const 3
          i32.gt_u
          br_if 0 (;@3;)
        end
        local.get 5
        local.set 4
        local.get 6
        local.set 0
      end
      local.get 4
      i32.eqz
      br_if 0 (;@1;)
      local.get 1
      i32.const 255
      i32.and
      local.set 2
      loop  ;; label = @2
        block  ;; label = @3
          local.get 0
          i32.load8_u
          local.get 2
          i32.ne
          br_if 0 (;@3;)
          local.get 0
          return
        end
        local.get 0
        i32.const 1
        i32.add
        local.set 0
        local.get 4
        i32.const -1
        i32.add
        local.tee 4
        br_if 0 (;@2;)
      end
    end
    i32.const 0)
  (func $dummy.1 (type 3) (param i32 i32) (result i32)
    local.get 0)
  (func $__lctrans (type 3) (param i32 i32) (result i32)
    local.get 0
    local.get 1
    call $dummy.1)
  (func $wctomb (type 3) (param i32 i32) (result i32)
    block  ;; label = @1
      local.get 0
      br_if 0 (;@1;)
      i32.const 0
      return
    end
    local.get 0
    local.get 1
    i32.const 0
    call $wcrtomb)
  (func $wcrtomb (type 0) (param i32 i32 i32) (result i32)
    (local i32)
    i32.const 1
    local.set 3
    block  ;; label = @1
      local.get 0
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 1
        i32.const 127
        i32.gt_u
        br_if 0 (;@2;)
        local.get 0
        local.get 1
        i32.store8
        i32.const 1
        return
      end
      block  ;; label = @2
        block  ;; label = @3
          i32.const 0
          i32.load offset=4500
          br_if 0 (;@3;)
          block  ;; label = @4
            local.get 1
            i32.const -128
            i32.and
            i32.const 57216
            i32.eq
            br_if 0 (;@4;)
            i32.const 0
            i32.const 25
            i32.store offset=4496
            br 2 (;@2;)
          end
          local.get 0
          local.get 1
          i32.store8
          i32.const 1
          return
        end
        block  ;; label = @3
          local.get 1
          i32.const 2047
          i32.gt_u
          br_if 0 (;@3;)
          local.get 0
          local.get 1
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=1
          local.get 0
          local.get 1
          i32.const 6
          i32.shr_u
          i32.const 192
          i32.or
          i32.store8
          i32.const 2
          return
        end
        block  ;; label = @3
          block  ;; label = @4
            local.get 1
            i32.const 55296
            i32.lt_u
            br_if 0 (;@4;)
            local.get 1
            i32.const -8192
            i32.and
            i32.const 57344
            i32.ne
            br_if 1 (;@3;)
          end
          local.get 0
          local.get 1
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=2
          local.get 0
          local.get 1
          i32.const 12
          i32.shr_u
          i32.const 224
          i32.or
          i32.store8
          local.get 0
          local.get 1
          i32.const 6
          i32.shr_u
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=1
          i32.const 3
          return
        end
        block  ;; label = @3
          local.get 1
          i32.const -65536
          i32.add
          i32.const 1048575
          i32.gt_u
          br_if 0 (;@3;)
          local.get 0
          local.get 1
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=3
          local.get 0
          local.get 1
          i32.const 18
          i32.shr_u
          i32.const 240
          i32.or
          i32.store8
          local.get 0
          local.get 1
          i32.const 6
          i32.shr_u
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=2
          local.get 0
          local.get 1
          i32.const 12
          i32.shr_u
          i32.const 63
          i32.and
          i32.const 128
          i32.or
          i32.store8 offset=1
          i32.const 4
          return
        end
        i32.const 0
        i32.const 25
        i32.store offset=4496
      end
      i32.const -1
      local.set 3
    end
    local.get 3)
  (func $frexp (type 11) (param f64 i32) (result f64)
    (local i64 i32)
    block  ;; label = @1
      local.get 0
      i64.reinterpret_f64
      local.tee 2
      i64.const 52
      i64.shr_u
      i32.wrap_i64
      i32.const 2047
      i32.and
      local.tee 3
      i32.const 2047
      i32.eq
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 3
        br_if 0 (;@2;)
        block  ;; label = @3
          local.get 0
          f64.const 0x0p+0 (;=0;)
          f64.ne
          br_if 0 (;@3;)
          local.get 1
          i32.const 0
          i32.store
          local.get 0
          return
        end
        local.get 0
        f64.const 0x1p+64 (;=1.84467e+19;)
        f64.mul
        local.get 1
        call $frexp
        local.set 0
        local.get 1
        local.get 1
        i32.load
        i32.const -64
        i32.add
        i32.store
        local.get 0
        return
      end
      local.get 1
      local.get 3
      i32.const -1022
      i32.add
      i32.store
      local.get 2
      i64.const -9218868437227405313
      i64.and
      i64.const 4602678819172646912
      i64.or
      f64.reinterpret_i64
      local.set 0
    end
    local.get 0)
  (table (;0;) 6 6 funcref)
  (memory (;0;) 2)
  (global (;0;) (mut i32) (i32.const 72160))
  (export "memory" (memory 0))
  (export "_start" (func $_start))
  (elem (;0;) (i32.const 1) func $__stdio_close $__stdio_read $__stdio_seek $__stdout_write $__stdio_write)
  (data (;0;) (i32.const 1024) "malloc failed.\0a\00I refuse to run under this style.\0a\00Enter your token: \0a\00fgets returned NULL\0a\00Empty token.\0a\00Wrong token length.\0a\00You win! :)\0a\00That token doesn't look legit.\0a\00\00\00\00\00\00\19\12D;\02?,G\14=30\0a\1b\06FKE7\0fI\0e\17\03@\1d<+6\1fJ-\1c\01 %)!\08\0c\15\16\22.\108>\0b41\18/A\099\11#C2B:\05\04&('\0d*\1e5\07\1aH\13$L\ff\00\00Success\00Illegal byte sequence\00Domain error\00Result not representable\00Not a tty\00Permission denied\00Operation not permitted\00No such file or directory\00No such process\00File exists\00Value too large for data type\00No space left on device\00Out of memory\00Resource busy\00Interrupted system call\00Resource temporarily unavailable\00Invalid seek\00Cross-device link\00Read-only file system\00Directory not empty\00Connection reset by peer\00Operation timed out\00Connection refused\00Host is unreachable\00Address in use\00Broken pipe\00I/O error\00No such device or address\00No such device\00Not a directory\00Is a directory\00Text file busy\00Exec format error\00Invalid argument\00Argument list too long\00Symbolic link loop\00Filename too long\00Too many open files in system\00No file descriptors available\00Bad file descriptor\00No child process\00Bad address\00File too large\00Too many links\00No locks available\00Resource deadlock would occur\00State not recoverable\00Previous owner died\00Operation canceled\00Function not implemented\00No message of desired type\00Identifier removed\00Link has been severed\00Protocol error\00Bad message\00Not a socket\00Destination address required\00Message too large\00Protocol wrong type for socket\00Protocol not available\00Protocol not supported\00Not supported\00Address family not supported by protocol\00Address not available\00Network is down\00Network unreachable\00Connection reset by network\00Connection aborted\00No buffer space available\00Socket is connected\00Socket not connected\00Operation already in progress\00Operation in progress\00Stale file handle\00Quota exceeded\00Multihop attempted\00Capabilities insufficient\00No error information\00\00-+   0X0x\00(null)\00\00\00\00\00\00\00\00\00\00\19\00\0a\00\19\19\19\00\00\00\00\05\00\00\00\00\00\00\09\00\00\00\00\0b\00\00\00\00\00\00\00\00\19\00\11\0a\19\19\19\03\0a\07\00\01\1b\09\0b\18\00\00\09\06\0b\00\00\0b\00\06\19\00\00\00\19\19\19\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0e\00\00\00\00\00\00\00\00\19\00\0a\0d\19\19\19\00\0d\00\00\02\00\09\0e\00\00\00\09\00\0e\00\00\0e\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\13\00\00\00\00\13\00\00\00\00\09\0c\00\00\00\00\00\0c\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\10\00\00\00\00\00\00\00\00\00\00\00\0f\00\00\00\04\0f\00\00\00\00\09\10\00\00\00\00\00\10\00\00\10\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\12\00\00\00\00\00\00\00\00\00\00\00\11\00\00\00\00\11\00\00\00\00\09\12\00\00\00\00\00\12\00\00\12\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\09\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\14\00\00\00\00\00\00\00\00\00\00\00\17\00\00\00\00\17\00\00\00\00\09\14\00\00\00\00\00\14\00\00\14\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\16\00\00\00\00\00\00\00\00\00\00\00\15\00\00\00\00\15\00\00\00\00\09\16\00\00\00\00\00\16\00\00\16\00\00Support for formatting long double values is currently disabled.\0aTo enable it, add -lc-printscan-long-double to the link command.\0a\00\00\00\00\00\00\00\00\00\00\00\00\00\000123456789ABCDEF-0X+0X 0X-0x+0x 0x\00inf\00INF\00nan\00NAN\00.\00\00\00\000\0e\00\00")
  (data (;1;) (i32.const 3552) "KEKW\00\00\00\00\00\00\00\00\00\00\00\00WASDSWDAWSDADAWSAWSDDWSADAWSSWAD\d6\d2\f8\a7E|\af\88\14\c6\06\a1\d4\18)_\e3L\1c\0a\fb\13\96w\80\b9\221Z\e7\afs\09\00\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\03\00\00\00\b8\11\00\00\00\04\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\000\0e\00\00\00\00\00\00\05\00\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\04\00\00\00\03\00\00\00\c8\15\00\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\0a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\a8\0e\00\00\00\00\00\00\05\00\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\05\00\00\00\03\00\00\00\d0\19\00\00\00\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00 \0f\00\00"))
