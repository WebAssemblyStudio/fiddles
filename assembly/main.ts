namespace boo {
  namespace foo {
    function isNull(value: i32): bool {
      return value == 0;
    }
  }
}

boo.foo.isNull(1);
