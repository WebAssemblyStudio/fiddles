(module
 (func $act (import "system" "act") (param i32) (result i32))
 (func (result i32)
       (call $act (i32.const 101)))
 (export "helloWorld" (func 0))
)
