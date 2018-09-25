(module
  (import "utils" "int_log" (func $int_log (param i32)))
  (import "utils" "str_log" (func $str_log (param i32) (param i32)))

  (import "js" "mem" (memory 1))

  (data (i32.const 0) "Hello World!")
  (data (i32.const 100) "Something else")

  (func $sayHello (export "sayHello")
    i32.const 100
    i32.const 12
    call $str_log)

  (func $sayHello5 (export "sayHello5")
    (local $i i32)
    i32.const 0
    set_local $i
    loop $L1
      call $sayHello

      get_local $i
      i32.const 1
      i32.add
      set_local $i
      get_local $i
      i32.const 5
      i32.lt_s
      br_if $L1
    end)

  (func $add (export "add") (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    get_local $rhs
    i32.add)

  (func $factorial (export "factorial") (param $n i32) (result i32)
    get_local $n
    i32.const 0
    i32.ne
    if $check_1
    get_local $n
    i32.const 1
    i32.sub
    call $factorial
    get_local $n
    i32.mul
    return
    end $check_1
    i32.const 1
    return)

  (func $testing (export "testing") (param $n i32) (result i32)
    get_local $n
    call $int_log
    i32.const 0
    return)
)