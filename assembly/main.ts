import "allocator/arena";

export function run(dummy: i32): i32 {
  let sarr: Array<String> = ["tag1", "tag2", "tag3", "tag4", "tag5", "tag6", "tag7", "tag8", "tag9", "tag10"];
  let amap = new Map<String, i32>();
  let arr = new Array<String>();

  for (let i = 0; i < sarr.length; i++) {
	  let x = sarr[i];
    arr.push(x);
    amap.set(x, 1);
  }

  return 0;
}