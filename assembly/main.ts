
interface IFace {
  run(): i32;
}

abstract class Base implements IFace {
  abstract run(): i32;
}

class Instance extends Base {
  run(): i32 {
    return 88;
  }
}

var instance: IFace | null = null;

export function run(): i32 {
  instance = new Instance();
  let temp: IFace = instance;
  if (temp !== null) {
    return temp.run();
  }
  return 0;
}
