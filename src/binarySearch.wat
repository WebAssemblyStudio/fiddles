(module
	(import "env" "memory" (memory $memory 1))
	(export "binarySearch" (func $binarySearch))
	(func $binarySearch (param $end i32) (param $number f64) (result i32)
		(local $middle i32)
		(local $value f64)
		(local $address i32)
		(local $start i32)
		(local $result i32)

		i32.const 0
		set_local $start

		i32.const -1
		set_local $result

		loop $rangeLoop
			get_local $start
			get_local $end
			i32.le_s
			if $loopIf
				get_local $end
				get_local $start
				i32.sub
				i32.const 2
				i32.div_s
				get_local $start
				i32.add
				tee_local $middle

				i32.const 8
				i32.mul
				f64.load
				tee_local $value

				get_local $number
				f64.eq
				if $checkIf
					get_local $middle
					set_local $result
				else
					get_local $number
					get_local $value
					f64.lt
					if 
						get_local $middle
						i32.const 1
						i32.sub
						set_local $end
					else
						get_local $middle
						i32.const 1
						i32.add
						set_local $start
					end

					br $rangeLoop
				end $checkIf

			end $loopIf
		end $rangeLoop

		get_local $result
	)
)