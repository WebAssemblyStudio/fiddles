(module
 (func $act (import "system" "act") (param i32) (result i32))
 (func (export "helloWorld") (result i32)
   (call $act (i32.const 101))))
