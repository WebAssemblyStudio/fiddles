(module
  (func $add (param i32) (param i32) (result i32)
    get_local 0
    get_local 1
    i32.add
  )
  (export "add" (func $add))
)


if (result i32)
else
end

i32.const 1

i32.sub

i32.ge_s
i32.le_u

call $add