// let a:Array<i32>;

export function init(n: i32, m: i32):Array<i32> {
  const a = new Array<i32>(n*m);
  for(let i:i32=0; i<a.length; i++){
    a[i] = 0;
  }
  let x = floor(n/2) - 1;
  let y = floor(m/2) - 1;
  a[x*n + y] = 1;
  return a; 
}