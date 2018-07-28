import "allocator/arena";

class aaa {
  time: Float64Array;
}

const bbb = new aaa();

export function fuck(time: f64): void {
  let ddd = new Float64Array(100);
  for (let i = 0; i < 100; i++)
    ddd[i] = ((2 * Math.PI) / 60) * (time + i * (1000 / 60)) + ((2 * Math.PI) / 60000) * (time + i * (1000 / 60));
  bbb.time = ddd;
}

export function get_ptr(): aaa {
  return bbb;
}
