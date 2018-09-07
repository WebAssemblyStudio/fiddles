var result = Module.ccall(
    'funcName',     // name of C function 
    'number',       // return type
    ['number'],     // argument types
    [42]);

var result = _funcName();