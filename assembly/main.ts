import "allocator/tlsf";

declare function log(): void;

class star {
  x: f64;
  y: f64;
  color: u8;
  speed: f64;
}

var starCount: i32 = 1000;
var stars: i32;

export function main(): i32 {
  var starCount: i32 = 1000;
  Math.random();
  log();
  stars = memory.allocate(sizeof<star>() * starCount);
  for (let i = 0; i < 1000; i++) {
    var index: i32 = stars + i * sizeof<star>();
    store<f64>(index + offsetof<star>("x"), Math.random() * 800);
    store<f64>(index + offsetof<star>("y"), Math.random() * 600);
    store<u8>(index + offsetof<star>("color"), <u8>Math.ceil(Math.random() * 2));
    store<f64>(index + offsetof<star>("speed"), Math.random() * 9 + 1);
  }
  
  return stars;
}

export function frame(dt: f64): void {
  var index: i32;
  var y: f64;
  var speed: f64;
  for (var i = 0; i < starCount; i++) {
    index = stars + i * sizeof<star>();
    y = load<f64>(index + offsetof<star>("y"));
    speed = load<f64>(index + offsetof<star>("speed"));
    y += dt * speed;
    if (y > 800) {
      y -= 800;
    }
    store<f64>(index + offsetof<star>("y"), y);
  }
}
