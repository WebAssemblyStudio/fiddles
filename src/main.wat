(module
  (func $add (param $width i32) (param $height i32) (result i32)
    (i32.add (get_local $width) (i32.const 7) (get_local $height))

    (i32.add
       ;; {wiresChunked, signalsChunked}
       (i32.shl (i32.const 4))

       ;; last row of image
       (i32.mul
           (i32.sub (get_local $height) (i32.const 1))
           (i32.shl (get_local $width)  (i32.const 2))))
           
    i32.add)
  (export "add" (func $add))
)