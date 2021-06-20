(module
  (import "main" "print" (func $print (param i32)))
  (func $_main (export "_main")
    i32.const 1
    if $I0
      i32.const 1
      call $print
    end
  )
  (start 1)
)
