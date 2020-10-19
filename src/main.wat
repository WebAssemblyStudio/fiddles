(module 
(import "env" "memory" (memory 0)) ;;
	(global $__stack_top (mut i32) (i32.const 262144))
;; constant
;; constant
	(global $U_$P$LYFF_$$_BOARDA i32 (i32.const 0))
	(global $U_$P$LYFF_$$_BOARDB i32 (i32.const 1300))
	(global $TC_$P$LYFF_$$_BOARD i32 (i32.const 2600))
(func $P$LYFF_$$_main
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_GET_CELL$LONGINT$LONGINT$$BYTE
	(param	i32)
	(param	i32)
	(result	i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	8
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	get_local	1
	set_local	6
	get_local	6
	i32.const	102
	i32.mul
	set_local	6
	get_local	0
	set_local	7
	get_local	7
	get_local	6
	i32.add
	set_local	6
	get_local	6
	set_local	3
	get_local	3
	i32.const	8
	i32.div_s
	set_local	6
	get_local	6
	set_local	4
	get_local	3
	i32.const	8
	i32.rem_s
	set_local	6
	i32.const	1
	get_local	6
	i32.shl
	set_local	6
	get_local	6
	set_local	5
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	6
	get_local	4
	set_local	7
	get_local	6
	get_local	7
	i32.add
	i32.load8_u	offset=0
	i32.const	255
	i32.and
	set_local	6
	get_local	5
	set_local	7
	get_local	7
	get_local	6
	i32.and
	set_local	6
	get_local	6
	set_local	6
	get_local	6
	set_local	6
	get_local	6
	set_local	2
	get_local	2
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_SET_CELL_REF$PBYTE$LONGINT$LONGINT
	(param	i32)
	(param	i32)
	(param	i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	12
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	get_local	2
	set_local	6
	get_local	6
	i32.const	102
	i32.mul
	set_local	6
	get_local	1
	set_local	7
	get_local	7
	get_local	6
	i32.add
	set_local	6
	get_local	6
	set_local	3
	get_local	3
	i32.const	8
	i32.div_s
	set_local	6
	get_local	6
	set_local	4
	get_local	3
	i32.const	8
	i32.rem_s
	set_local	6
	i32.const	1
	get_local	6
	i32.shl
	set_local	6
	get_local	6
	set_local	5
	get_local	0
	set_local	6
	get_local	4
	set_local	7
	get_local	6
	get_local	7
	i32.add
	i32.load8_u	offset=0
	i32.const	255
	i32.and
	set_local	6
	get_local	5
	set_local	7
	get_local	7
	get_local	6
	i32.or
	set_local	6
	get_local	6
	set_local	6
	get_local	6
	set_local	6
	get_local	0
	set_local	7
	get_local	4
	set_local	8
	get_local	7
	get_local	8
	i32.add
	get_local	6
	i32.store8	offset=0
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_CLEAR_BOARD_REF$PBYTE
	(param	i32)
	(local i32)
	(local i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	4
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	i32.const	-1
	set_local	1
	block
	loop
	block
	get_local	1
	set_local	2
	get_local	2
	i32.const	1
	i32.add
	set_local	2
	get_local	2
	set_local	1
	get_local	0
	set_local	2
	get_local	1
	set_local	3
	get_local	2
	get_local	3
	i32.add
	i32.const	0
	i32.store8	offset=0
	end
	get_local	1
	i32.const	1299
	i32.ge_s
	br_if	1
	br	0
	end
	end
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_BOARD_STEP$$LONGINT
	(result	i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	16
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	i32.const	0
	set_local	1
	i32.const	0
	set_local	2
	get_global	$U_$P$LYFF_$$_BOARDA
	set_local	14
	get_local	14
	set_local	3
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	14
	get_local	14
	get_local	3
	i32.eq
	if (result i32)
	get_global	$U_$P$LYFF_$$_BOARDB
	set_local	14
	get_local	14
	set_local	3
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	get_local	3
	call	$P$LYFF_$$_CLEAR_BOARD_REF$PBYTE
	i32.const	0
	set_local	10
	block
	loop
	block
	get_local	10
	set_local	14
	get_local	14
	i32.const	1
	i32.add
	set_local	14
	get_local	14
	set_local	10
	i32.const	0
	set_local	11
	block
	loop
	block
	get_local	11
	set_local	14
	get_local	14
	i32.const	1
	i32.add
	set_local	14
	get_local	14
	set_local	11
	get_local	10
	get_local	11
	call	$P$LYFF_$$_GET_CELL$LONGINT$LONGINT$$BYTE
	set_local	12
	get_local	12
	set_local	4
	i32.const	0
	set_local	5
	i32.const	0
	set_local	6
	i32.const	-1
	set_local	7
	block
	loop
	block
	get_local	7
	set_local	14
	get_local	14
	i32.const	1
	i32.add
	set_local	14
	get_local	14
	set_local	7
	get_local	7
	i32.const	4
	i32.eq
	if (result i32)
	i32.const	0
	br	1
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	get_local	7
	i32.const	3
	i32.rem_s
	set_local	14
	get_local	14
	i32.const	1
	i32.sub
	set_local	14
	get_local	14
	set_local	8
	get_local	7
	i32.const	3
	i32.div_s
	set_local	14
	get_local	14
	i32.const	1
	i32.sub
	set_local	14
	get_local	14
	set_local	9
	get_local	10
	set_local	14
	get_local	8
	set_local	15
	get_local	15
	get_local	14
	i32.add
	set_local	14
	get_local	14
	get_local	11
	set_local	14
	get_local	9
	set_local	15
	get_local	15
	get_local	14
	i32.add
	set_local	14
	get_local	14
	call	$P$LYFF_$$_GET_CELL$LONGINT$LONGINT$$BYTE
	set_local	13
	get_local	13
	i32.const	0
	i32.eq
	if (result i32)
	i32.const	0
	br	1
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	get_local	6
	i32.const	1
	i32.add
	set_local	6
	get_local	6
	i32.const	3
	i32.gt_s
	if (result i32)
	i32.const	0
	br	3
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	end
	get_local	7
	i32.const	8
	i32.ge_s
	br_if	1
	br	0
	end
	end
	get_local	6
	i32.const	3
	i32.eq
	if (result i32)
	i32.const	1
	else
	get_local	6
	i32.const	2
	i32.eq
	if (result i32)
	get_local	4
	i32.const	0
	i32.gt_u
	else
	i32.const	0
	end
	end
	if (result i32)
	i32.const	1
	set_local	5
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	get_local	5
	i32.const	0
	i32.gt_u
	if (result i32)
	get_local	3
	get_local	10
	get_local	11
	call	$P$LYFF_$$_SET_CELL_REF$PBYTE$LONGINT$LONGINT
	get_local	1
	i32.const	1
	i32.add
	set_local	1
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	get_local	5
	set_local	14
	get_local	14
	get_local	4
	i32.ne
	if (result i32)
	get_local	2
	i32.const	1
	i32.add
	set_local	2
	i32.const	0
	else
	nop
	i32.const	0
	end
	drop
	end
	get_local	11
	i32.const	99
	i32.ge_s
	br_if	1
	br	0
	end
	end
	end
	get_local	10
	i32.const	99
	i32.ge_s
	br_if	1
	br	0
	end
	end
	get_global	$TC_$P$LYFF_$$_BOARD
	get_local	3
	i32.store	offset=0
	get_local	2
	i32.const	0
	i32.eq
	if (result i32)
	i32.const	-1
	set_local	0
	i32.const	1
	else
	get_local	1
	set_local	0
	i32.const	0
	end
	drop
	get_local	0
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_BOARD_COUNT$$LONGINT
	(result	i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	8
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	i32.const	0
	set_local	1
	i32.const	-1
	set_local	3
	block
	loop
	block
	get_local	3
	set_local	4
	get_local	4
	i32.const	1
	i32.add
	set_local	4
	get_local	4
	set_local	3
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	4
	get_local	3
	set_local	5
	get_local	4
	get_local	5
	i32.add
	i32.load8_u	offset=0
	i32.const	255
	i32.and
	set_local	2
	block
	loop
	get_local	2
	i32.const	0
	i32.gt_u
	i32.const	1
	i32.xor
	br_if	1
	block
	get_local	2
	set_local	4
	get_local	4
	i32.const	1
	i32.and
	set_local	4
	get_local	4
	set_local	4
	get_local	1
	set_local	5
	get_local	5
	get_local	4
	i32.add
	set_local	4
	get_local	4
	set_local	1
	get_local	2
	set_local	4
	get_local	4
	i32.const	1
	i32.shr_u
	set_local	4
	get_local	4
	set_local	4
	get_local	4
	set_local	4
	get_local	4
	set_local	2
	br	1
	end
	br	0
	end
	end
	end
	get_local	3
	i32.const	1299
	i32.ge_s
	br_if	1
	br	0
	end
	end
	get_local	1
	set_local	0
	get_local	0
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_BOARD_REF$$PBYTE
	(result	i32)
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	4
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	get_local	$bp
	set_global	$__stack_top
	return
	)

(func $P$LYFF_$$_BOARD_INIT
	(local i32)
	(local  $fp i32)
	(local  $bp i32)
	get_global	$__stack_top
	set_local	$bp
	get_local	$bp
	i32.const	4
	i32.sub
	set_local	$fp
	get_local	$fp
	set_global	$__stack_top
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	call	$P$LYFF_$$_CLEAR_BOARD_REF$PBYTE
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=85
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=120
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=132
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=800
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	254
	i32.store8	offset=720
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=700
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=600
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=601
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=602
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=603
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=604
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=605
	get_global	$TC_$P$LYFF_$$_BOARD
	i32.load	offset=0
	set_local	0
	get_local	0
	i32.const	255
	i32.store8	offset=606
	get_local	$bp
	set_global	$__stack_top
	return
	)

	(table 3 anyfunc)	(elem 0 (i32.const 0) 
		$P$LYFF_$$_BOARD_INIT
		$P$LYFF_$$_BOARD_REF$$PBYTE
		$P$LYFF_$$_BOARD_STEP$$LONGINT
	) 
		(export "_board_init" (func $P$LYFF_$$_BOARD_INIT))
		(export "_board_ref" (func $P$LYFF_$$_BOARD_REF$$PBYTE))
		(export "_board_step" (func $P$LYFF_$$_BOARD_STEP$$LONGINT))
)

