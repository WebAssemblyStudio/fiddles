(module
 
(func $hxp2019::check::h578f31d490e10a31 (param i32 i32) (result i32)
(local i32 i32 i32 i32 i32 i32 i32 i32 i32)
  global.get 0
  i32.const 32
  i32.sub
  local.tee 2
  global.set 0
  i32.const 0
  local.set 3
  block
    local.get 1
    i32.const 50
    i32.ne
    br_if 0
    local.get 2
    i32.const 50
    i32.store offset=4 align=4
    local.get 2
    local.get 0
    i32.store offset=0 align=4
    local.get 2
    i32.const 0
    i32.store offset=8 align=4
    local.get 2
    i32.const 4
    i32.store offset=12 align=4
    block
      block
        local.get 0
        i32.load8_s offset=4 align=1
        i32.const -65
        i32.le_s
        br_if 0
        local.get 0
        i32.const 1049664
        i32.eq
        br_if 1
        i32.const 0
        local.set 3
        local.get 0
        i32.load offset=0 align=1
        i32.const 2070968424
        i32.eq
        br_if 1
        br 2
      end
      local.get 2
      local.get 2
      i32.const 12
      i32.add
      i32.store offset=24 align=4
      local.get 2
      local.get 2
      i32.const 8
      i32.add
      i32.store offset=20 align=4
      local.get 2
      local.get 2
      i32.store offset=16 align=4
      local.get 2
      i32.const 16
      i32.add
      call 42
      unreachable
    end
    local.get 2
    i32.const 50
    i32.store offset=4 align=4
    local.get 2
    local.get 0
    i32.store offset=0 align=4
    local.get 2
    i32.const 49
    i32.store offset=8 align=4
    local.get 2
    i32.const 50
    i32.store offset=12 align=4
    block
      local.get 0
      i32.load8_s offset=49 align=1
      local.tee 1
      i32.const -65
      i32.le_s
      br_if 0
      block
        local.get 0
        i32.const 49
        i32.add
        local.tee 4
        i32.const 1049668
        i32.eq
        br_if 0
        i32.const 0
        local.set 3
        local.get 1
        i32.const 125
        i32.ne
        br_if 2
      end
      local.get 0
      i32.const 4
      i32.add
      local.set 0
      i32.const 0
      local.set 1
      i32.const 1
      local.set 3
      block
        block
          loop
            local.get 4
            local.get 0
            i32.eq
            br_if 4
            local.get 0
            i32.const 1
            i32.add
            local.set 5
            block
              block
                local.get 0
                i32.load8_s offset=0 align=1
                local.tee 6
                i32.const -1
                i32.gt_s
                br_if 0
                block
                  block
                    local.get 5
                    local.get 4
                    i32.ne
                    br_if 0
                    i32.const 0
                    local.set 7
                    local.get 4
                    local.set 8
                    br 1
                  end
                  local.get 0
                  i32.load8_u offset=1 align=1
                  i32.const 63
                  i32.and
                  local.set 7
                  local.get 0
                  i32.const 2
                  i32.add
                  local.tee 5
                  local.set 8
                end
                local.get 6
                i32.const 31
                i32.and
                local.set 9
                block
                  local.get 6
                  i32.const 255
                  i32.and
                  local.tee 6
                  i32.const 223
                  i32.gt_u
                  br_if 0
                  local.get 7
                  local.get 9
                  i32.const 6
                  i32.shl
                  i32.or
                  local.set 6
                  br 2
                end
                block
                  block
                    local.get 8
                    local.get 4
                    i32.ne
                    br_if 0
                    i32.const 0
                    local.set 10
                    local.get 4
                    local.set 8
                    br 1
                  end
                  local.get 8
                  i32.load8_u offset=0 align=1
                  i32.const 63
                  i32.and
                  local.set 10
                  local.get 8
                  i32.const 1
                  i32.add
                  local.tee 5
                  local.set 8
                end
                local.get 10
                local.get 7
                i32.const 6
                i32.shl
                i32.or
                local.set 7
                block
                  local.get 6
                  i32.const 240
                  i32.ge_u
                  br_if 0
                  local.get 7
                  local.get 9
                  i32.const 12
                  i32.shl
                  i32.or
                  local.set 6
                  br 2
                end
                block
                  block
                    local.get 8
                    local.get 4
                    i32.ne
                    br_if 0
                    i32.const 0
                    local.set 6
                    br 1
                  end
                  local.get 8
                  i32.const 1
                  i32.add
                  local.set 5
                  local.get 8
                  i32.load8_u offset=0 align=1
                  i32.const 63
                  i32.and
                  local.set 6
                end
                local.get 7
                i32.const 6
                i32.shl
                local.get 9
                i32.const 18
                i32.shl
                i32.const 1835008
                i32.and
                i32.or
                local.get 6
                i32.or
                local.tee 6
                i32.const 1114112
                i32.eq
                br_if 6
                br 1
              end
              local.get 6
              i32.const 255
              i32.and
              local.set 6
            end
            local.get 1
            i32.const 44
            i32.gt_u
            br_if 1
            local.get 1
            i32.const 2
            i32.shl
            i32.const 1049716
            i32.add
            i32.load offset=0 align=4
            local.get 1
            i32.const 1337
            i32.mul
            i32.xor
            local.tee 8
            i32.const 44
            i32.gt_u
            br_if 2
            local.get 1
            local.get 0
            i32.sub
            local.get 5
            i32.add
            local.set 1
            local.get 5
            local.set 0
            local.get 8
            i32.const 1049669
            i32.add
            i32.load8_u offset=0 align=1
            local.get 6
            i32.const 255
            i32.and
            i32.eq
            br_if 0
          end
          i32.const 0
          local.set 3
          br 3
        end
        i32.const 1049908
        local.get 1
        i32.const 45
        call 26
        unreachable
      end
      i32.const 1049924
      local.get 8
      i32.const 45
      call 26
      unreachable
    end
    local.get 2
    local.get 2
    i32.const 12
    i32.add
    i32.store offset=24 align=4
    local.get 2
    local.get 2
    i32.const 8
    i32.add
    i32.store offset=20 align=4
    local.get 2
    local.get 2
    i32.store offset=16 align=4
    local.get 2
    i32.const 16
    i32.add
    call 42
    unreachable
  end
  local.get 2
  i32.const 32
  i32.add
  global.set 0
  local.get 3
end)

  (export "$hxp2019::check::h578f31d490e10a31" (func $$hxp2019::check::h578f31d490e10a31))
)