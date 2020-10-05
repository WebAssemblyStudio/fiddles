# Hello DxLib in C++

Level: *Advanced*

This project has simple DxLib code for WebGL app. This project owes to [emscripten compiler backend](https://github.com/nokotan/emscripten-compiler) and [DxLib for HTML5](https://github.com/nokotan/DxLibForHTML5).

### Project Overview

* `main.cpp` - Imports `DxLib.h` and draws red circle using `DrawCircle`.
* `main.html` - For canvas to be rendered.
* `DxLib.wasm` - Precompiled library. Should be listed in `Module.dynamicLibraries` and loaded dynamically by emscripten runtime.

### Things to Explore

1. Click Build to compile `main.cpp` file to `src/main.wasm`.

2. Click Run
