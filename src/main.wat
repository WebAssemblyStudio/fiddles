(module
  (type $t0 (func (param i32)))
  (import "print" (func $print (type $t0)))
  (func $_main (export "_main") (type $t0) (param $p0 i32)
    get_local $p0
    i32.const 5
    i32.lt_s
    if $I0
      i32.const 1
      call $main.print
    end
  )
)
