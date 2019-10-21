declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

const I4_HEX_CACHE = new Map<i8,string>();
I4_HEX_CACHE.set(0,'0')
I4_HEX_CACHE.set(1,'1')
I4_HEX_CACHE.set(2,'2')
I4_HEX_CACHE.set(3,'3')
I4_HEX_CACHE.set(4,'4')
I4_HEX_CACHE.set(5,'5')
I4_HEX_CACHE.set(6,'6')
I4_HEX_CACHE.set(7,'7')
I4_HEX_CACHE.set(8,'8')
I4_HEX_CACHE.set(9,'9')
I4_HEX_CACHE.set(10,'a')
I4_HEX_CACHE.set(11,'b')
I4_HEX_CACHE.set(12,'c')
I4_HEX_CACHE.set(13,'d')
I4_HEX_CACHE.set(14,'e')
I4_HEX_CACHE.set(15,'f')

function toString16(i:i8):string {
  const g:i8 = i%16;
  const s:i8 = i>>4;
  return I4_HEX_CACHE.get(s)+I4_HEX_CACHE.get(g);
}

const BINARY_HEX_CACHE = new Map<i8,string>();
const HEX_BINARY_CACHE = new Map<string,i8>();
for(let byte:i8 = 0;byte<256;byte++){
  const hex = toString16(byte);
  BINARY_HEX_CACHE.set(byte, hex);
  HEX_BINARY_CACHE.set(hex, byte);
}

export function encodeHex(binary:Uint8Array):string {
  let res = "";
  // for(let i:i8 = 0;i<binary.length;i+=1){
  //   res+=BINARY_HEX_CACHE.get(i)
  // }
  return res
}