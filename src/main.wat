(module
	(import "env" "console::clear" (func $console::clear))
	(import "env" "console::log" (func $console::log (param $message_length i32) (param $message_pointer i32)))
	(func $main(export "main")
		(call $console::clear)
		(call $console::log
			(i32.const 13)
			(i32.const 0)
		)
		(call $console::log
			(i32.const 14)
			(i32.const 13)
		)
	)
	(memory $memory 1)
	(export "memory" (memory $memory))
	(data $memory (i32.const 0) "Hello, world!")
	(data $memory (i32.const 13) "Hello, Anluin!")
)
