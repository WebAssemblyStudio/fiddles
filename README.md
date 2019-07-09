# WebAssembly Workshop 1 - Webasssembly Text Format

## Workspace

This workspace contains two files that you need to edit:
1. ***main.wat***: Contains the webassembly code
2. ***main.js***: Contains the glue code between javascript and webassembly. 

### Test it works
1. Press Build & Run in the top bar of the website. If all goes well, you should a white screen in the bottom right corner displaying '3'.

## Add a multiply function

Extend the provided Webassembly module by adding a `mul` function. This function should take two 32-bit integers as input, and produce the multiplied result. 
[Operator overview](https://webassembly.org/docs/semantics/#32-bit-integer-operators) contains a list of all build-in functions and operators.

> In order to test your created function, you have to export it from you webassembly module and call it from main.js

## Add a debug function

Extend the provided Webassembly module by adding a `debug` function. This function should take a 32-bit integer as input, print the argument to the console and then return the result again.

The following code should work:

```webassembly
(func $add (param $lhs i32) (param $rhs i32) (result i32)
    get_local $lhs
    call $debug
    get_local $rhs
    i32.add)
```

> You should use Javascript bindings to console.log. Note that console.log does ***not*** show up in the white box, but instead in your browser console.
Note that console.log is already provided via the "interop" "print" function.

## Modifying memory
StringToUpper contains implementation of ASCII string uppercasing. The current implementation uses Javascript to uppercase the character. Modify the `$charToUpper` function in webassembly to perform the uppercasing in webassembly. 

> Note that it is easy to convert an uppercase ASCII character to uppercase by subtracting 32 from the byte representation of the character.

This should be done by reading the character from the shared memory, calculate the lowercase byte value, and write that back to the shared memory.