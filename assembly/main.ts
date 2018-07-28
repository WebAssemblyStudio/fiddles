import "allocator/arena";

class aaa {
  time: f64;
}

const bbb = new aaa();

export function fuck(): void {
  bbb.time = ((2 * Math.PI) / 60) * bbb.time + ((2 * Math.PI) / 60000) * bbb.time;
}

export function get_ptr(): aaa {
  return bbb;
}
