(module
  (import "console" "log" (func $log (param i32)))
  (import "console" "line" (func $linel))
  (import "console" "found" (func $found (param i32) (param i32)))
  (memory $memory 1)
  (export "memory" (memory $memory))
  (func $logg (param $a i32) (result i32)
  	get_local $a
    call $log
    get_local $a
  )
  (func $line (param $a i32) (result i32)
    call $linel
    get_local $a
  )
  (func $getOnBlockPos (export "getOnBlockPos") (param $x i32) (param $z i32) (result i32) (local $i i32)
    get_local $x
    call $logg
    i32.const 3129871
    i32.mul
    get_local $z
    i32.const 116129781
    i32.mul
    i32.xor
    get_local $i
    i32.const 42317861
    get_local $i
    i32.mul
    i32.const 11
    i32.add
    get_local $i
    i32.mul
    get_local $i
    get_local $i
    i32.const 19
    i32.shr_u
    i32.const 1
    i32.and
    get_local $i
    i32.const 26
    i32.shr_u
    i32.const 2
    i32.and
    i32.or
  )
  (func $getOffset (param $index i32) (param $param i32) (result i32)
  	get_local $index
    i32.const 3
    i32.mul
    get_local $param
    i32.add
  )
  (func $setFlowerPosition (export "setFlowerPosition") (param $index i32) (param $relativeX i32) (param $relativeZ i32) (param $position i32)
    get_local $index
    i32.const 12
    i32.mul
    set_local $index
    ;;store x
    get_local $index
    get_local $relativeX
    i32.store
    ;;store z
    get_local $index
    i32.const 4
    i32.add
    get_local $relativeZ
    i32.store
	;;store o
    get_local $index
    i32.const 8
    i32.add
    get_local $position
    i32.store
  )
  (func $testPosition (export "testPosition") (param $x i32) (param $z i32) (param $memoryLength i32) (result i32) (local $memoryPos i32)
    i32.const 0
    set_local $memoryPos
    (block
      (loop
        ;;calculate absolute x
        get_local $memoryPos
        i32.load
        get_local $x
        i32.add
        ;;calculate absolute z
        get_local $z
        get_local $memoryPos
        i32.const 4
        i32.add
        i32.load
        i32.add
        ;;calculate position on block
        call $getOnBlockPos
        ;;get position on block
        get_local $memoryPos
        i32.const 8
        i32.add
        i32.load
        ;;compare unequal
        i32.ne
        ;;quit loop directly if end isnt reashed (optional)
        br_if 1
        ;;increment memory pos
        get_local $memoryPos
        i32.const 12
        i32.add
        set_local $memoryPos
        ;;test if end of blocklist is reached
        get_local $memoryPos
        get_local $memoryLength
        i32.eq
        ;; add 'i32.or' for 1 check
        br_if 1
        br 0
      )
    )
    ;;Generate return value
    get_local $memoryPos
    get_local $memoryLength
    i32.eq
  )
  (func $testChunk (export "testChunk") (param $maxX i32) (param $maxZ i32) (param $memoryLength i32) (result i32) (local $pointerX i32) (local $pointerZ i32)
  	;;resize for memory use
    get_local $memoryLength
    i32.const 12
    i32.mul
    set_local $memoryLength
    ;;create ranges for x
    i32.const 10
    get_local $maxX
    i32.mul
    i32.const 10
    i32.add
    set_local $maxX
    ;;create ranges for z
    i32.const 10
    get_local $maxZ
    i32.mul
    i32.const 10
    i32.add
    set_local $maxZ
    ;;prepare pointer x for loop
    i32.const 10
    get_local $maxX
    i32.sub
    set_local $pointerX
    ;;begin loop
    (block
      (loop
        ;;prepare pointer z for loop
        i32.const 10
        get_local $maxZ
        i32.sub
        set_local $pointerZ
        (block
          (loop
            ;;test position
            get_local $pointerX
            get_local $pointerZ
            get_local $memoryLength
            call $testPosition
            br_if 3
            ;;increment z
            get_local $pointerZ
            i32.const 1
            i32.add
            set_local $pointerZ
            ;;test if z end
            get_local $maxZ
            get_local $pointerZ
            i32.eq
            br_if 1
            br 0
          )
        )
        ;;increment x
        get_local $pointerX
        i32.const 1
        i32.add
        set_local $pointerX
        ;;test if x end
        get_local $maxX
        get_local $pointerX
        i32.eq
        br_if 1
        br 0
      )
    )
    get_local $pointerZ
    get_local $maxZ
    i32.ne
    if
      get_local $pointerX
      get_local $pointerZ
      call $found
    end
    get_local $pointerZ
    get_local $maxZ
    i32.ne
  )
) 
