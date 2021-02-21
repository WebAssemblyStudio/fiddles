declare function sayHello(): void;

sayHello();
// 0 atk 1 hp

export function add(pa: i32, ph: i32, ea: i32, eh: i32): i32 {
  let p = new Array<i32>(2)
  let e = new Array<i32>(2)
  let b = false
  let returncode: i32
  p[0] = pa
  p[1] = ph
  e[1] = eh
  e[0] = ea
  while (b == false){
  if (e[1] <= 0){
    returncode = 0
    b = true
  }
  else if (p[1] <= 0){
    returncode = 1
    b = true
  }
  e[1] -= p[0]
  p[1] -= e[0]
  }
  return returncode
}
