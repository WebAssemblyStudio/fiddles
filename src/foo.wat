
  (func $camlStdlib__list__sort_1320 (export "camlStdlib__list__sort_1320") (type 2) (param i32 i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    block (result i32)  ;; label = @1
      block  ;; label = @2
        get_local 2
        i32.const 5
        i32.ne
        if  ;; label = @3
          get_local 2
          i32.const 7
          i32.ne
          if  ;; label = @4
            br 2 (;@2;)
          else
            get_local 1
            i32.const 1
            i32.ne
            if  ;; label = @5
              get_local 1
              i32.const 4
              i32.add
              i32.load align=1
              set_local 3
              get_local 3
              i32.const 1
              i32.ne
              if  ;; label = @6
                get_local 3
                i32.const 4
                i32.add
                i32.load align=1
                set_local 4
                get_local 4
                i32.const 1
                i32.ne
                if  ;; label = @7
                  get_local 4
                  i32.load align=1
                  set_local 5
                  get_local 3
                  i32.load align=1
                  set_local 6
                  get_local 1
                  i32.load align=1
                  set_local 7
                  get_local 7
                  get_local 6
                  get_local 0
                  i32.const 28
                  i32.add
                  i32.load align=1
                  call $caml_apply2
                  i32.const 1
                  i32.le_s
                  if (result i32)  ;; label = @8
                    get_local 6
                    get_local 5
                    get_local 0
                    i32.const 28
                    i32.add
                    i32.load align=1
                    call $caml_apply2
                    i32.const 1
                    i32.le_s
                    if (result i32)  ;; label = @9
                      i32.const 2
                      call $caml_alloc
                      set_local 8
                      get_local 8
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 8
                      i32.const 2
                      i32.add
                      get_local 7
                      i32.store align=1
                      get_local 8
                      i32.const 4
                      i32.add
                      i32.const 2
                      call $caml_alloc
                      set_local 9
                      get_local 9
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 9
                      i32.const 2
                      i32.add
                      get_local 6
                      i32.store align=1
                      get_local 9
                      i32.const 4
                      i32.add
                      i32.const 2
                      call $caml_alloc
                      set_local 10
                      get_local 10
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 10
                      i32.const 2
                      i32.add
                      get_local 5
                      i32.store align=1
                      get_local 10
                      i32.const 4
                      i32.add
                      i32.const 1
                      i32.store align=1
                      get_local 10
                      i32.store align=1
                      get_local 9
                      i32.store align=1
                      get_local 8
                      br 6 (;@3;)
                    else
                      get_local 7
                      get_local 5
                      get_local 0
                      i32.const 28
                      i32.add
                      i32.load align=1
                      call $caml_apply2
                      i32.const 1
                      i32.le_s
                      if (result i32)  ;; label = @10
                        i32.const 2
                        call $caml_alloc
                        set_local 11
                        get_local 11
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 11
                        i32.const 2
                        i32.add
                        get_local 7
                        i32.store align=1
                        get_local 11
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 12
                        get_local 12
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 12
                        i32.const 2
                        i32.add
                        get_local 5
                        i32.store align=1
                        get_local 12
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 13
                        get_local 13
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 13
                        i32.const 2
                        i32.add
                        get_local 6
                        i32.store align=1
                        get_local 13
                        i32.const 4
                        i32.add
                        i32.const 1
                        i32.store align=1
                        get_local 13
                        i32.store align=1
                        get_local 12
                        i32.store align=1
                        get_local 11
                        br 7 (;@3;)
                      else
                        i32.const 2
                        call $caml_alloc
                        set_local 14
                        get_local 14
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 14
                        i32.const 2
                        i32.add
                        get_local 5
                        i32.store align=1
                        get_local 14
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 15
                        get_local 15
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 15
                        i32.const 2
                        i32.add
                        get_local 7
                        i32.store align=1
                        get_local 15
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 16
                        get_local 16
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 16
                        i32.const 2
                        i32.add
                        get_local 6
                        i32.store align=1
                        get_local 16
                        i32.const 4
                        i32.add
                        i32.const 1
                        i32.store align=1
                        get_local 16
                        i32.store align=1
                        get_local 15
                        i32.store align=1
                        get_local 14
                        br 7 (;@3;)
                      end
                    end
                  else
                    get_local 7
                    get_local 5
                    get_local 0
                    i32.const 28
                    i32.add
                    i32.load align=1
                    call $caml_apply2
                    i32.const 1
                    i32.le_s
                    if (result i32)  ;; label = @9
                      i32.const 2
                      call $caml_alloc
                      set_local 17
                      get_local 17
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 17
                      i32.const 2
                      i32.add
                      get_local 6
                      i32.store align=1
                      get_local 17
                      i32.const 4
                      i32.add
                      i32.const 2
                      call $caml_alloc
                      set_local 18
                      get_local 18
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 18
                      i32.const 2
                      i32.add
                      get_local 7
                      i32.store align=1
                      get_local 18
                      i32.const 4
                      i32.add
                      i32.const 2
                      call $caml_alloc
                      set_local 19
                      get_local 19
                      i32.const 0
                      i32.add
                      i32.const 2048
                      i32.store align=1
                      get_local 19
                      i32.const 2
                      i32.add
                      get_local 5
                      i32.store align=1
                      get_local 19
                      i32.const 4
                      i32.add
                      i32.const 1
                      i32.store align=1
                      get_local 19
                      i32.store align=1
                      get_local 18
                      i32.store align=1
                      get_local 17
                      br 6 (;@3;)
                    else
                      get_local 6
                      get_local 5
                      get_local 0
                      i32.const 28
                      i32.add
                      i32.load align=1
                      call $caml_apply2
                      i32.const 1
                      i32.le_s
                      if (result i32)  ;; label = @10
                        i32.const 2
                        call $caml_alloc
                        set_local 20
                        get_local 20
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 20
                        i32.const 2
                        i32.add
                        get_local 6
                        i32.store align=1
                        get_local 20
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 21
                        get_local 21
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 21
                        i32.const 2
                        i32.add
                        get_local 5
                        i32.store align=1
                        get_local 21
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 22
                        get_local 22
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 22
                        i32.const 2
                        i32.add
                        get_local 7
                        i32.store align=1
                        get_local 22
                        i32.const 4
                        i32.add
                        i32.const 1
                        i32.store align=1
                        get_local 22
                        i32.store align=1
                        get_local 21
                        i32.store align=1
                        get_local 20
                        br 7 (;@3;)
                      else
                        i32.const 2
                        call $caml_alloc
                        set_local 23
                        get_local 23
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 23
                        i32.const 2
                        i32.add
                        get_local 5
                        i32.store align=1
                        get_local 23
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 24
                        get_local 24
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 24
                        i32.const 2
                        i32.add
                        get_local 6
                        i32.store align=1
                        get_local 24
                        i32.const 4
                        i32.add
                        i32.const 2
                        call $caml_alloc
                        set_local 25
                        get_local 25
                        i32.const 0
                        i32.add
                        i32.const 2048
                        i32.store align=1
                        get_local 25
                        i32.const 2
                        i32.add
                        get_local 7
                        i32.store align=1
                        get_local 25
                        i32.const 4
                        i32.add
                        i32.const 1
                        i32.store align=1
                        get_local 25
                        i32.store align=1
                        get_local 24
                        i32.store align=1
                        get_local 23
                        br 7 (;@3;)
                      end
                    end
                  end
                else
                  br 5 (;@2;)
                end
              else
                br 4 (;@2;)
              end
            else
              br 3 (;@2;)
            end
          end
        else
          get_local 1
          i32.const 1
          i32.ne
          if  ;; label = @4
            get_local 1
            i32.const 4
            i32.add
            i32.load align=1
            set_local 26
            get_local 26
            i32.const 1
            i32.ne
            if  ;; label = @5
              get_local 26
              i32.load align=1
              set_local 27
              get_local 1
              i32.load align=1
              set_local 28
              get_local 28
              get_local 27
              get_local 0
              i32.const 28
              i32.add
              i32.load align=1
              call $caml_apply2
              i32.const 1
              i32.le_s
              if (result i32)  ;; label = @6
                i32.const 2
                call $caml_alloc
                set_local 29
                get_local 29
                i32.const 0
                i32.add
                i32.const 2048
                i32.store align=1
                get_local 29
                i32.const 2
                i32.add
                get_local 28
                i32.store align=1
                get_local 29
                i32.const 4
                i32.add
                i32.const 2
                call $caml_alloc
                set_local 30
                get_local 30
                i32.const 0
                i32.add
                i32.const 2048
                i32.store align=1
                get_local 30
                i32.const 2
                i32.add
                get_local 27
                i32.store align=1
                get_local 30
                i32.const 4
                i32.add
                i32.const 1
                i32.store align=1
                get_local 30
                i32.store align=1
                get_local 29
                br 3 (;@3;)
              else
                i32.const 2
                call $caml_alloc
                set_local 31
                get_local 31
                i32.const 0
                i32.add
                i32.const 2048
                i32.store align=1
                get_local 31
                i32.const 2
                i32.add
                get_local 27
                i32.store align=1
                get_local 31
                i32.const 4
                i32.add
                i32.const 2
                call $caml_alloc
                set_local 32
                get_local 32
                i32.const 0
                i32.add
                i32.const 2048
                i32.store align=1
                get_local 32
                i32.const 2
                i32.add
                get_local 28
                i32.store align=1
                get_local 32
                i32.const 4
                i32.add
                i32.const 1
                i32.store align=1
                get_local 32
                i32.store align=1
                get_local 31
                br 3 (;@3;)
              end
            else
              br 3 (;@2;)
            end
          else
            br 2 (;@2;)
          end
        end
      end
      get_local 2
      i32.const 1
      i32.shr_s
      i32.const 1
      i32.or
      set_local 33
      get_local 2
      get_local 33
      i32.sub
      i32.const 1
      i32.add
      set_local 34
      get_local 33
      get_local 1
      call $camlStdlib__list__chop_1293
      set_local 35
      get_local 33
      get_local 1
      get_local 0
      i32.const 16
      i32.add
      call $camlStdlib__list__rev_sort_1321
      set_local 36
      get_local 34
      get_local 35
      get_local 0
      i32.const 16
      i32.add
      call $camlStdlib__list__rev_sort_1321
      set_local 37
      get_local 36
      get_local 37
      i32.const 1
      get_local 0
      i32.const 36
      i32.add
      i32.load align=1
      call $camlStdlib__list__rev_merge_rev_1310
      br 0 (;@1;)
    end)
 