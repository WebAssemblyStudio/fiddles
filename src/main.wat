;; hello.wat
(module
  ;; Import our trace function so that we can call it in main
  (import "env" "trace" (func $trace (param i32)))
  ;; Define our initial memory with a single page (64KiB).
  (memory $0 1)
  ;; Store a null terminated string at byte offset 0. 
  (data (i32.const 0) "Hello world!\00")
  ;; Export the memory so it can be read in the host environment.
  (export "memory" (memory $0))
  ;; Define the main function with no parameters.
  (func $main
    ;; Call the trace function with the constant value 0.
    (call $trace (i32.const 0))
  )
  ;; Export the main function so that the host can call it.
  (export "main" (func $main))
)