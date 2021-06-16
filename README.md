# Decorator in WASM

Module `core` has 3 "methods":

* `store` a value
* `inc`rement the stored value
* `get` the stored value

Module `decorator` exposes same API,
wrapping the `core` module and adding logging messages on each "method".