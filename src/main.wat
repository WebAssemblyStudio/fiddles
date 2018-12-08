(module
  (import "ethereum" "storageStore" (func $storageStore (param i32 i32)))
  (import "ethereum" "storageLoad" (func $storageLoad (param i32 i32)))
  (import "ethereum" "getBlockNumber" (func $getBlockNumber (result i64)))
  (memory 1)
  (export "main" (func $main))
  (export "memory" (memory 0))
  (fun $main
    (i32.store (i32.const 512)  (i32.const 88)) 
    (i32.store (i32.const 1024) (i32.const 99)) 
    (i64.store (i32.const 32) (call $getBlockNumber)) 
    (call $storageStore (i32.const 512) (i32.const 32))

    (call $storageLoad (i32.const 512) (i32.const 2048))
    (call $storageStore (i32.const 512) (i32.const 2048))
))
  