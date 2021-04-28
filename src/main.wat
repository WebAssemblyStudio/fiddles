(module
  ;; imports
  (import "eval" "(function(w,h){window.memory.grow(Math.max(1,Math.ceil(w*h*4/65536))); window.canvas=document.createElement('canvas'); window.canvas.width=w; window.canvas.height=h; window.ctx=window.canvas.getContext('2d'); document.body.appendChild(window.canvas);})"
    (func $initCanvas (param i32) (param i32)))
  (import "eval" "(function(offset, width, height, x, y){ window.ctx.putImageData(  new ImageData(  new Uint8ClampedArray(window.memory.buffer,offset,width*height*4),width,height  ), x, y  ); })"
    (func $updateCanvas (param i32 i32 i32 i32 i32)))
  (import "eval" "console.log" (func $logi32 (param i32)))
  (import "eval" "console.log" (func $logi32_2 (param i32 i32)))
  ;; data
  (import "eval" "(function(){ return window.memory=new WebAssembly.Memory({initial:0}); })()" (memory 0))
  ;; code
  (func $main
    (local $x i32)
    (local $y i32)
    (local $width i32)
    (local $height i32)
    (local $tmp i32)

    (set_local $width  (i32.const 256))
    (set_local $height (i32.const 256))

    (call $initCanvas (get_local $width) (get_local $height))

    (set_local $x (i32.const 0))
    (block (loop
      (set_local $y (i32.const 0))
      (block (loop
        (set_local $tmp
          (i32.mul
            (i32.add
              (i32.mul (get_local $y) (get_local $width))
              (get_local $x)
            )
          (i32.const 4)
          )
        )
        
        ;; calculate and set pixel colors
        (i32.store8 ;; r
          (get_local $tmp)
          (get_local $x))
        (i32.store8 ;; g
          (i32.add (get_local $tmp) (i32.const 1))
          (get_local $y))
        (i32.store8 ;; b
          (i32.add (get_local $tmp) (i32.const 2))
          (i32.const 0x00))
        (i32.store8 ;; a
          (i32.add (get_local $tmp) (i32.const 3))
          (i32.const 0xFF))

        ;; y++
        (set_local $y
          (i32.add (get_local $y) (i32.const 1)))

        (br_if 1 (i32.eq (get_local $y) (get_local $height)))
        (br 0)
      ))

      ;; x++
      (set_local $x
        (i32.add (get_local $x) (i32.const 1)))

      (br_if 1 (i32.eq (get_local $x) (get_local $width)))
      (br 0)
    ))
    
    (call $updateCanvas
      (i32.const 0)       ;; offset
      (get_local $width)  ;; width
      (get_local $height) ;; height
      (i32.const 0)       ;; x
      (i32.const 0))      ;; y
  )
  (export "main" (func $main))
)
