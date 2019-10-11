class Struct {
  a:i32;
}

export function report(): i32 {
  let arr:Struct[] = [];
  
  for(let i=0;i<10;i++) {
    arr.push(new Struct());
  }
  arr.length = 0; // will throw here
  return arr.length;
}