declare function sayHello(str?: ArrayBuffer, test2?: string, length?: number): void;
/*
const x = new ArrayBuffer(2);
ArrayBuffer[0] = "a";
ArrayBuffer[1] = "b";*/
sayHello(str2ab("This is a test"), "asdf", "This is a test".length);

export function add(x: i32, y: i32): i32 {
  return x + y;
}

function str2ab(str: string): ArrayBuffer {
  var buf = new ArrayBuffer(str.length*2); // 2 bytes for each char
  var bufView = new Uint16Array(<ArrayBuffer> buf);
  for (var i: i32 = 0; i < str.length; i++) {
    bufView[i] = str.charCodeAt(i);
  }
  return buf;
}