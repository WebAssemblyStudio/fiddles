(module
    (func $ofp (param $x i32) (param $y i32) (result i32)
        (i32.shl
            (i32.add
                (i32.shl
                    (get_local $y)
                    (i32.const 3)
                )
                (get_local $x)
            )
            (i32.const 2)
        )
    )
    (export "ofp" (func $ofp))
)