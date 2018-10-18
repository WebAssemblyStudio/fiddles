import "allocator/arena";

declare function logc(char: i32): void;

var str = "a,b,c,";

var end = str.indexOf(",", 6);
var chr = str.substring(6, end);

logc(chr.charCodeAt(0));