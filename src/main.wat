(module
  (import "js" "memory" (memory 1))
  (import "js" "log" (func $log (param i32 i32)))

  (func $decrement (param $value i32) (result i32)
    get_local $value
    i32.const 1
    i32.sub
  )

  (func $increment (param $value i32) (result i32)
    get_local $value
    i32.const 1
    i32.add
  )

;;THIS FUNCTION TAKES AN ADDRESS AND A BYTE, STORES THE BYTE AT THE ADDRESS, AND RETUNRS THE NEXT ADDRESS.
  (func $storeByteAndMove (param $address i32) (param $value i32) (result i32)
    get_local $address
    get_local $value
    i32.store8
    get_local $address
    call $increment
  )




  (func $helloWorldCount (export "helloWorldCount") (param $count i32) 
    (local $address i32)

    block $block
      loop $loop

;;      IF COUNT IS GREATER THAN ZERO, CONTINUE THE LOOP, OTHERWISE EXIT
        get_local $count
        i32.eqz
        br_if $block            ;; LIKE A BREAK STATEMENT IN JS


        get_local $address

        i32.const 72            ;; "H"
        call $storeByteAndMove

        i32.const 101           ;; "e"
        call $storeByteAndMove

        i32.const 108           ;; "l"
        call $storeByteAndMove

        i32.const 108           ;; "l"
        call $storeByteAndMove

        i32.const 111           ;; "o"
        call $storeByteAndMove

        i32.const 44            ;; ","
        call $storeByteAndMove

        i32.const 32            ;; " "
        call $storeByteAndMove

        i32.const 87            ;; "W"
        call $storeByteAndMove

        i32.const 111           ;; "o"
        call $storeByteAndMove

        i32.const 114           ;; "r"
        call $storeByteAndMove

        i32.const 108           ;; "l"
        call $storeByteAndMove

        i32.const 100           ;; "d"
        call $storeByteAndMove

        i32.const 33            ;; "!"
        call $storeByteAndMove

        i32.const 10            ;; "\n"
        call $storeByteAndMove
        
        set_local $address


;;      DECREMENT COUNT VARIABLE
        get_local $count
        call $decrement
        set_local $count

        br $loop                ;; LIKE A CONTINUE STATEMENT IN JS
        end
      end
    
    i32.const 0                 ;; STARTING ADDRESS
    get_local $address          ;; GET LAST ADDRESS
    call $increment             ;; INCREMENT LAST ADDRESS
    call $log                   ;; LOG DATA
  )
)