class A {
    public call(): i32 {
        return this.callImpl();
    }

    public callImpl(): i32 {
      throw new Error("need to be implemented");
    }
}

class B extends A {
    public callImpl(): i32 {
        return 3;
    }
}

class Base {
    run(): i32 {
      throw new Error("not implemented in base.");
    }
}

class Foo extends Base {
    run(): i32 {
        return 1;
    }
}

class Bar extends Base {
    run(): i32 {
        return new B().call();
    }
}

let i = 2;

export function main(): i32 {
    let instance: Base;
    if (i<0) {
      instance = new Foo();
    } else {
      instance = new Bar();
    }
    return instance.run();

}
