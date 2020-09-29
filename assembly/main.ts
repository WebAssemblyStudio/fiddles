abstract class Base {
  abstract run(): i32;
}

abstract class Instance extends Base {
  run(): i32 {
    return this.getValue();
  }

  abstract getValue(): i32;
}

class Instance2 extends Instance {
  getValue(): i32 {
    return 13;
  }
}

var instance: Base | null = null;

export function run(): i32 {
  instance = new Instance2();
  let temp = instance;
  if (temp !== null) {
    return temp.run();
  }
  return 0;
}