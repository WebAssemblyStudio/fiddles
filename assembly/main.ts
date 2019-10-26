

export function test1(arr: i32[]): usize {
   let dataStart = arr.dataStart;
   let cur = dataStart + 1;
   let end = dataStart + 2;
   return cur + end;
}

// export function test2(arr: i32[]): usize {
//    let cur = arr.dataStart + 1;
//    let end = arr.dataStart + 2;
//    return cur + end;
// }
