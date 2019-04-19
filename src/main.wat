

(module
  (import "js" "print" (func $print))
  ;; Requires that we have at least 1 page of memory available (64kb)
  (memory (import "js" "memory") 1)
  ;; Declare a global variable representing a pointer initalised to index 0 - 
  ;; each element is a 32bit integer and thus 4 bytes wide
  (global $ptr (mut i32) (i32.const 0))
  (global $currCellVal (mut i32) (i32.const 0))
  (func $get_ptr (result i32)
   get_global $ptr
  )
  
  ;; Increment our global pointer variable
  (func $inc_ptr 
    get_global $ptr
    i32.const 1
    i32.add
    set_global $ptr 
   )

  ;; Decrement our global pointer variable
  (func $dec_ptr 
    get_global $ptr
    i32.const 1
    i32.sub
    set_global $ptr 
   )
  
  (func $load_num (param $index i32) (result i32)
    (i32.mul (get_local $index) (i32.const 4))
    i32.load
  )
  (func $store_num (param $index i32) (param $num i32)
    ;; calculate the memory address offset in bytes. 32 bit integer takes up 4 bytes 
    ;; so multiply the index of the element by the space each element takes up - Index * 4 (bytes) 
    (i32.mul (get_local $index) (i32.const 4)) 
    ;; push value to store at address offset to stack
    get_local $num 
    ;; write the value to the address in memory
    i32.store 
  )
  (export "main" (func $main)) 
  (func $main
  get_global $ptr
  i32.const 1
  i32.add
  set_global $ptr
  get_global $ptr
  get_global $ptr
  i32.const 4
  i32.mul
  i32.load
  i32.const 1
  i32.add
  i32.store
  )
    
  (export "store_num" (func $store_num))
  (export "load_num" (func $load_num))
  (export "get_ptr" (func $get_ptr))
  (export "inc_ptr" (func $inc_ptr))
  (export "dec_ptr" (func $dec_ptr))
)


