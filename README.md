# Timing Fibonacci

This example compares JavaScript and WebAssembly performance computing Fibonacci numbers.

JavaScript implementations are in `main.js` and C implementations are in `main.c`. The C implementations are compiled to WebAssembly when you `Build` the example.

The `fib` implementation is the straightforward Fibonacci implemenation often used to teach recursion.

The `memoize` implemenation improves on the recursive approach by memoizing results along the way. Memoization is often referred to as the top-down approach to dynamic proramming. 

The `tabulate` implementation is an iterative approach that also stores results along the way. Tabulation is the bottom-up approach to dynamic programming.

`Build` the program and then `Run` to calculate the 45th Fibonacci number. You can change to Fibonacci number to be computed in `main.js`, but fair warning, even computing 50 Fibonacci numbers may trigger warnings in your browser that something has gone terribly wrong.