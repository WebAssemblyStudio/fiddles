(module
  (func $RecursiveCount (param i32) (result i32)
        get_local 0
        i32.const 10
        i32.eq
        if (result i32)
          i32.const 10
        else
          get_local 0
          get_local 0
          i32.const 1
          i32.add
          call $RecursiveCount
          i32.add
         end)
        
        (export "RecursiveCount" (func $RecursiveCount)))
