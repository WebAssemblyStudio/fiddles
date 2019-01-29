import "allocator/arena";

class F<T> {
  prop: T = null;
}

@inline 
function TEST<G extends F<T>, T>(
  val: G,
  callback: (val: T) => T,
): void {
  val.prop = callback(val.prop);
}

export function add(a: i32 , b: i32): i32 {
  var test = new F<i32>();
  test.prop = 1;
  TEST(test, (val: i32): i32 => val + 2);
  return a + b;
}