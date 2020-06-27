

@final class ptr<T> {
  @inline constructor(offset: usize = 0) {
    return changetype<ptr<T>>(offset);
  }
  @inline get deref(): T {
    return changetype<T>(this);
  }
}

let fooPtr = new ptr<i32>(0x200);
let foo = fooPtr.deref;
