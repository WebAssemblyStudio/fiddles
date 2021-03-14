(module
  (import "imports" "log" (func $log (param i32)))
  (import "js" "memory" (memory 256))
  (global $framePointer (mut i32) (i32.const 0))
  (func $malloc (param $size i32) (result i32)
    (set_global $framePointer (i32.add (get_global $framePointer) (get_local $size)))
    (get_global $framePointer)
  )
  (func $initArray (param $size i32) (result i32)
    (local $arrayPointer i32)
    (set_local $arrayPointer (get_global $framePointer))
    (i32.store
      (i32.add (get_global $framePointer) (i32.const 0))
      (get_local $size)
    )
    (i32.store
      (i32.add (get_global $framePointer) (i32.const 1))
      (i32.add (get_local $size) (i32.const 64))
    )
    (set_global $framePointer
      (i32.add (get_global $framePointer)
      (i32.const 2))
    )
    (i32.store
      (i32.add (get_global $framePointer) (i32.const 2))
      (call $malloc (get_local $size))
    )
    (get_local $arrayPointer)
  )
  (func $reallocArray (param $arrayPointer i32)
    (local $newPointer i32)
    (local $oldSize i32)
    (local $newSize i32)   
    (set_local $oldSize (i32.add (i32.const 1) (get_local $arrayPointer)))
    (set_local $newSize (i32.add (get_local $oldSize) (i32.const 16)))
    (set_local $newPointer (call $malloc (get_local $newSize)))
    (i32.store
      (i32.add (i32.const 1) (get_local $arrayPointer))
      (get_local $newSize)
    )
    (i32.store
      (i32.add (i32.const 2) (get_local $arrayPointer))
      (get_local $newPointer)
    )
    (memory.copy
      (get_local $newPointer)
      (i32.add (i32.const 2) (get_local $arrayPointer))
      (get_local $oldSize)
    )
  )
  
  (func $getAtIndex (param $arrayPointer i32) (param $index i32) (result i32)
    (local $valueStart i32)
    (set_local $valueStart (i32.load (i32.add (get_local $arrayPointer) (i32.const 2))))
    (if 
      (i32.ge_s
        (get_local $arrayPointer)
        (i32.load (get_local $arrayPointer))
      )
      (then
        i32.const -1
        return
      )
    )
    (i32.load (i32.add (get_local $valueStart) (get_local $index)))
  )

  (func $setAtIndex (param $arrayPointer i32) (param $index i32)
    (param $element i32) (result i32) (local $valueStart i32)
    (set_local $valueStart (i32.load (i32.add (get_local $arrayPointer) (i32.const 2))))
    (if 
      (i32.ge_s
        (get_local $arrayPointer)
        (i32.load (get_local $arrayPointer))
      )
      (then
        i32.const -1
        return
      )
    )
    (i32.store (i32.add (get_local $valueStart) (get_local $index)) (get_local $element))
  )

  (func $add (param $lhs i32) (param $rhs i32) (result i32)
    (i32.store (i32.const 0) (i32.const 0))
    (i32.add (get_local $lhs) (get_local $rhs))
  )

  (export "add" (func $add))
)