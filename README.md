# Timing Fibonacci

This example compares three implementations that calculate Fibonacci numbers. All implementations are in `main.c`.

The `fib` implementation is the straightforward Fibonacci implemenation often used to teach recursion.

The `memoize` implemenation improves on the recursive approach by memoizing results along the way. Storing results speeds things up significantly. 
Memoization is often referred to as the top-down approach to dynamic proramming. 

The `tabulate` implementation is an iterative approach that also stores results along the way. Tabulation is the bottom-up approach 
to dynamic programming.

The results show the dramatic benefits gained from dynamic programming. `Build` the program and then `Run` to calculate the 45th Fibonacci number.
You can change to Fibonacci number to be computed in `main.js`, but fair warning, even setting this to 50 may trigger warnings in your browser 
that something has gone terribly wrong.