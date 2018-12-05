(module
(import "i" "m" (memory 1))
(export "SearchStartCodePrefix" (func $SearchStartCodePrefix))
(func $SearchStartCodePrefix
	(param $pStream i32) (param $pStreamEnd i32) (result i32)
	(local $pTemp i32)

	block $Return

	(set_local $pTemp (i32.add (get_local $pStreamEnd) (i32.const -3)))

	loop $LSearchStart

		(if (i32.load8_u offset=2 (get_local $pStream)) (then
			(br_if $LSearchStart (i32.le_s
				(tee_local $pStream (i32.add (get_local $pStream) (i32.const 3)))
				(get_local $pTemp)))
			br $Return
		))
		(if (i32.load8_u offset=1 (get_local $pStream)) (then
			(br_if $LSearchStart (i32.le_s
				(tee_local $pStream (i32.add (get_local $pStream) (i32.const 2)))
				(get_local $pTemp)))
			br $Return
		))
		(if (i32.load8_u (get_local $pStream)) (then
			(br_if $LSearchStart (i32.le_s
				(tee_local $pStream (i32.add (get_local $pStream) (i32.const 1)))
				(get_local $pTemp)))
			br $Return
		))

	end

	(set_local $pTemp (get_local $pStream))
	(i32.store (i32.const 0)
		(i32.sub
			(get_local $pStream)
			(get_local $pTemp)))
	(return (get_local $pTemp))

	end $Return
	(return (get_local $pStreamEnd))
))
