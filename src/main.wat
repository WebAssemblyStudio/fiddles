;; resource loader
(module
  ;; this chonky boi needs 632kb for resources, ~4kb for memlist.bat, and a few extra bytes for strings
  ;; at least it doesn't malloc
  (memory (import "env" "memory") 10)
  (global $membase (import "env" "__memory_base") i32)
  (func $open (import "./fs.wasm" "open") (param i32 i32) (result i32))
  (func $readAll (import "./fs.wasm" "readAll") (param i32 i32 i32) (result i32))
  (func $log (import "log" "bytes") (param i32 i32))
  (func $num (import "log" "num") (param i32))
  (func (param i32)
    (local i32 i32)
    (local.set $writeloc
      (i32.add (global.get $membase) (i32.const 0x9e000)))
    (call $readAll
      (call $open (i32.add (global.get $membase) (i32.const 0x9ef00)) (i32.const 11))
      (local.get $writeloc))
    (local.set $size)
    (call $log
      (local.get $writeloc) (local.get $size)))
  (data (i32.const 0x9ef40) "MEMLIST.BIN")) ;; TODO shouldn't need to hardcode the offset 