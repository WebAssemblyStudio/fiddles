

declare function log1(x: i32): void;

@external('env', 'log2')
declare function log2(x: i32): void;


log1(123);
log2(123);