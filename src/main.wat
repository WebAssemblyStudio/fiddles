(module
  (memory (export "mem") 1)
  (func (export "load_mem") (param i32) (result i32)
    get_local 0
    i32.load)
    (func (export "write_mem") (param i32 i32)
    get_local 0
    get_local 1
    i32.store)
)
