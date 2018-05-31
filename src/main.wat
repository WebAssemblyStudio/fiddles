(module
  (func $main (result i64) (local $count i64)
    i64.const 3
    set_local $count
    
		get_local $count
		i64.const 5
		i64.add
    set_local $count

    get_local $count
	)
  (export "main" (func $main))
)
