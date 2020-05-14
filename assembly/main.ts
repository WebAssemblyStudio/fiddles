declare function console_log(str: string): void;

class OtherClass {
  stuff: i32;

  constructor(newStuff: i32) {
    this.stuff = newStuff;
  }
}

class MyClassInit {
  otherClass: OtherClass;
}

class MyClass {
  _myParam: i32;
  _otherClass: OtherClass;

  constructor(param: i32, init: MyClassInit) {
    this._myParam = param;
    this._otherClass = init.otherClass;
  }

  toString(): string {
    return this._otherClass.stuff.toString();
  }
}

export function _start(): void {

  // Make our Other class
  let otherClass = new OtherClass(24);

  // Pass to my class as an object literal
  let myClass = new MyClass(2424, {
    otherClass: otherClass
  });

  // This will all work
  console_log("Logging myClass.toString() ...\n");
  console_log(myClass.toString());
  console_log("\n");
}