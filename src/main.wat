(module
  (memory (export "mem") 1)
  (func (export "fill") (param i32 i32 i32)
    local.get 0
    local.get 1
    local.get 2
    memory.fill))
