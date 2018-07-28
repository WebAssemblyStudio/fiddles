import "allocator/arena";

class aaa {
  time: Float64Array;
}

const bbb = new aaa();

declare namespace console {
  function log(value: i32): void;
}

export function animate(duration: f64): void {
  const frames = (<i32>Math.round(duration / 1000 * 60));
  let ddd = new Float64Array(frames);
  for (let i = 0; i < frames; i++)
    ddd[i] = 10 / i;
  bbb.time = ddd;
}

export function get_ptr(): aaa {
  return bbb;
}
