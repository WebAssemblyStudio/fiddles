import { apply0, apply1 } from "./apply";

function foo<T1, T2>(): i32 {
  return sizeof<T1>() + sizeof<T2>();
}

class runner0<T1> {
  execute<ReturnType, T2>(): ReturnType {
    return foo<T1, T2>();
  }
}

class runner1 {
  execute<ReturnType, T1>(typeId: i32): ReturnType {
    return new apply0<i32, runner0<T1>>().execute(typeId);
  }
}

export function fooWithTypeId(typeId1: i32, typeId2: i32): i32 {
  return new apply1<i32, runner1>().execute(typeId1, typeId2);
}