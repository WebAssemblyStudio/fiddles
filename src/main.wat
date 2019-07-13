(module
  (func $sayHello (import "imports" "say_hello"))

  (func $getAnswer (result i32) i32.const 42)
  
  (func (export "getAnswerPlus1") (result i32)
    call $sayHello
    call $getAnswer
    i32.const 1
    i32.add
    ))
