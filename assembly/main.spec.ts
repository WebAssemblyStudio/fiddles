class FakeValue {
  value: i32;

  @operator("==")
  private __eq(other: FakeValue): bool {
    return this.value == other.value;
  }
}

class Test {
  private value: FakeValue | null;
}

describe("Test", () => {
  it("works with expectations", () => {
    const t1 = new Test();
    const t2 = new Test();

    expect<Test>(t1).toStrictEqual(t2);
  });
});

/*
Compilation error:

ERROR TS2322: Type 'test/internal-types.spec/FakeValue | null' is not assignable to type 'test/internal-types.spec/FakeValue'.

     if (left == right) return Reflect.SUCCESSFUL_MATCH; // works immutably for string comparison
                 ~~~~~
 in node_modules/@as-pect/cli/node_modules/@as-pect/assembly/assembly/internal/Reflect.ts(393,16)
*/