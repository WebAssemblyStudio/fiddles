(func $camlStdlib__char__lowercase_1015 (export "camlStdlib__char__lowercase_1015") (type $t4) (param $p0 i32) (result i32)
    (local $l0 i32)
    block $B0 (result i32)
      block $B1 (result i32)
        block $B2 (result i32)
          block $B3 (result i32)
            get_local $p0
            i32.const 131
            i32.ge_s
            if $I4 (result i32)
              get_local $p0
              i32.const 181
              i32.le_s
              if $I5 (result i32)
                i32.const 0
                br $I4
              else
                i32.const 0
                br $I5
              end
            else
              i32.const 0
              br $I4
            end
          end
          block $B6 (result i32)
            block $B7 (result i32)
              get_local $p0
              i32.const 385
              i32.ge_s
              if $I8 (result i32)
                get_local $p0
                i32.const 429
                i32.le_s
                if $I9 (result i32)
                  i32.const 0
                  br $B7
                else
                  i32.const 0
                  br $I9
                end
              else
                i32.const 0
                br $I8
              end
            end
            block $B10 (result i32)
              block $B11 (result i32)
                get_local $p0
                i32.const 433
                i32.ge_s
                if $I12 (result i32)
                  get_local $p0
                  i32.const 445
                  i32.le_s
                  if $I13 (result i32)
                    i32.const 0
                    br $B10
                  else
                    i32.const 0
                    br $I13
                  end
                else
                  i32.const 0
                  br $I12
                end
              end
              get_local $p0
              br $B10
            end
          end
        end
      end
      get_local $p0
      i32.const 64
      i32.add
      br $B0
    end)