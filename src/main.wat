(module                              
  (memory 1)                         
  (func                              
    (export "main")                  
    (result i32)                     
    (i32.load (i32.const 10000000))  
  )                                  
)