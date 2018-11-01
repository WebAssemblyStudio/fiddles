;; clicks.wat

(module

    ;; import the updateClickCount function from JavaScript land

    (import "button" "updateClickCount"
        (func $updateClickCount
            (param $x i32)
        )
    )

    ;; Define a mutable static i32 initialized at 0

    (global $count (mut i32) (i32.const 0))

    ;; Define and export a function to JS land

    (func (export "onClick")

        ;; Increment the global count

        get_global $count
        i32.const 1
        i32.add
        set_global $count

        ;; Push the count on the stack and call the imported function

        get_global $count
        call $updateClickCount
    )
)