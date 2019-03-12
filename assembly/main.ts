import { FooBar, ContainerClass } from "./model_near";

export function convertFoobars(foobars: Array<FooBar>): Array<ContainerClass> {
    /* TODO: Fix compiler bug https://github.com/AssemblyScript/assemblyscript/issues/539 */
  return foobars.map<ContainerClass>((it: FooBar, i: i32, arr: Array<FooBar>): ContainerClass => {
      return { foobar: it};
  });
}
