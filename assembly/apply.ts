export class apply0<ReturnType, Runner0> {
  execute(typeId: i32): ReturnType {
    const runner = instantiate<Runner0>();

    if (typeId == 0) return runner.execute<ReturnType, i16>();
    if (typeId == 1) return runner.execute<ReturnType, i32>();
    if (typeId == 2) return runner.execute<ReturnType, i64>();

    throw new Error("Unknown typeId.");
  }
}

export class apply1<ReturnType, Runner1> {
  execute<Arg1Type>(typeId: i32, arg1: Arg1Type): ReturnType {
    const runner = instantiate<Runner1>();

    if (typeId == 0) return runner.execute<ReturnType, i16>(arg1);
    if (typeId == 1) return runner.execute<ReturnType, i32>(arg1);
    if (typeId == 2) return runner.execute<ReturnType, i64>(arg1);

    throw new Error("Unknown typeId.");
  }
}
