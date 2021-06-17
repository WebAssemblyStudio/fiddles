(module
  (import "main" "print" (func $print (param i32)))
  (func $_main (export "_main") (param i32) (param $p0 i32)
    get_local $p0
    i32.const 5
    i32.lt_s
    if $I0
      i32.const 1
      call $print
    end
  )
  ;;(start 0)
)
