declare function log(v: i32): void;

class A {
  public call(): i32 {
    log(2);
    return this.callImpl();
  }
  public callImpl(): i32 {
    throw new Error("need to be implemented");
  }
}

class B extends A {
  public callImpl(): i32 {
    log(3);
    return 3;
  }
}

class Base {
  run(): i32 {
    throw new Error("not implemented in base.");
  }
}

class Bar extends Base {
  run(): i32 {
    log(1);
    return new B().call();
  }
}

export function main(): i32 {
  // let instance: Bar = new Bar(); // this don't panic
  let instance: Base = new Bar();
  return instance.run();
}
