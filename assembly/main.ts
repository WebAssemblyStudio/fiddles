
function testGenric<T>(t: T): void {}

class StaticProperties {
  static get x(): i32 {
    return 0;
  }

  get i_x(): i32 {
    return 1;
  }
}

testGenric((new StaticProperties).i_x);
testGenric(StaticProperties.x);
