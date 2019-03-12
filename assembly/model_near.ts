import {
  FooBar as wrapped_FooBar,
  ContainerClass as wrapped_ContainerClass,
} from "./model";


export class FooBar extends wrapped_FooBar {
  static decode(json: Uint8Array): FooBar {
    return <FooBar>null;
  }
  encode(): Uint8Array {
    return <Uint8Array>null;
  }
}

export class ContainerClass extends wrapped_ContainerClass {
  static decode(json: Uint8Array): ContainerClass {
    return <ContainerClass>null;
  }
  encode(): Uint8Array {
    return <Uint8Array>null;
  }
}

