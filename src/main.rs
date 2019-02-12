(if (i32.eq (call $gethealth) (i32.const 0))
(then (call $doDeath))
(else (call $stillAlive))
)