class SomeOtherClass {
  value: i32;

  @operator("==")
  private __eq(other: SomeOtherClass): bool {
    return this.value == other.value;
  }
}

class Test {
  private value: SomeOtherClass | null;
}

describe("Test", () => {
  it("works with expectations", () => {
    const t1 = new Test();
    const t2 = new Test();

    expect<Test>(t1).toStrictEqual(t2);
  });
});