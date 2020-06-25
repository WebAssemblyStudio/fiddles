;;programStart
(module
  (func $program (param i32 $inputSize) (local i32 $pointer)
    ;;loopHeader
    (local i32 $loop_i)
    ;;loopStart
      (block 
        (loop
    ;;loopEnd
          get_local $loop_i
          i32.const 1
          i32.add
          set_local $loop_i
          get_local $loop_i
          get_local $inputSize
          i32.eq
          br_if 1
          br 0
        )
      )
    ;;>
    get_local $pointer
    i32.const 4
    i32.add
    set_local $pointer
    ;;<
    get_local $pointer
    i32.const 4
    i32.sub
    set_local $pointer
    ;;+
    get_local $pointer
    get_local $pointer
    i32.load
    i32.const 1
    i32.add
    i32.store
    ;;-
    get_local $pointer
    get_local $pointer
    i32.load
    i32.const 1
    i32.add
    i32.store
    ;;[
    get_local $pointer
    i32.load
    (if
      (then
    ;;]
      )
    )
    ;;programEnd
  )
  (memory $memory 1)

  (export "memory" (memory $memory))
  (export "program" (func $program))
)