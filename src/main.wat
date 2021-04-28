(module
  ;; imports
  (import "eval" "(function(w,h){window.canvas=document.createElement('canvas'); window.canvas.width=w; window.canvas.height=h; window.ctx=window.canvas.getContext('2d'); document.body.appendChild(window.canvas);})"
    (func $initCanvas (param i32) (param i32)))
  (import "eval" "(function(offset, width, height, x, y){ window.ctx.putImageData(  new ImageData(  new Uint8ClampedArray(window.memory.buffer,offset,width*height*4),width,height  ), x, y  ); })"
    (func $updateCanvas (param i32 i32 i32 i32 i32)))
  ;; data
  (import "eval" "(function(){ return window.memory=new WebAssembly.Memory({initial:8}); })()" (memory 1))
  ;; code
  (func $main
    (local $x i32)
    (local $y i32)
    (local $width i32)
    (local $height i32)

    i32.const 128
    set_local $width
    i32.const 128
    set_local $height

    get_local $width ;; width
    get_local $height ;; height
    call $initCanvas

    i32.const 0
    set_local $x
    i32.const 0
    set_local $y

    (loop
      get_local $x
      i32.const 1
      i32.add
      set_local $x

      (br_if 1 (i32.eq (get_local $x) (get_local $width)))
      (br 0)
    )

    i32.const 0
    i32.const 0xFF
    i32.store8
    i32.const 1
    i32.const 0x00
    i32.store8
    i32.const 2
    i32.const 0x00
    i32.store8
    i32.const 3
    i32.const 0xFF
    i32.store8
    

    i32.const 0   ;; offset
    i32.const 128 ;; width
    i32.const 128 ;; height
    i32.const 0   ;; x
    i32.const 0   ;; y
    call $updateCanvas 
  )
  (export "main" (func $main))
)
