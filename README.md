# BithumbChain Rust WebAssembly Contract Project

This is a sample Rust project which uses the [`bithumb_chain_std` crate][crate] to
enable richer interactions between Rust and bithumb chain wasm virtual machine such as communicating with
strings rather than just numbers and environment interface.

Some files you may be interested in are:

* `lib.rs` - this is the main body of Rust code, annotated with
  `#[bithumb_chain_abi]` is a trait exported to bithumbchaim webassembly virtual machine.

When building the project you'll get `out/contract.wasm`, the generated wasm
filtered through the `wasm-bindgen` CLI tool.

[crate]: https://github.com/bithumb-network/bithumb-chain-rust-cdt.git
