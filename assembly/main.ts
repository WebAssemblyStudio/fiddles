import "allocator/tlsf";

//@ts-ignore
export { memory };

declare function logi(x: i32): void;
declare function logf(x: f64): void;
declare function logl(lo: u32, hi: u32): void;
declare function log_ref(x: usize): void;
declare function log_str(x: string): void;

export function log<T>(item: T): void {
  if (isReference<T>()) {
    if (isString<T>()) {
      log_str(changetype<string>(item));
    } else {
      log_ref(changetype<usize>(item));
    }
  } else {
    if (isInteger<T>()) {
      if (sizeof<T>() <= 4) {
        // @ts-ignore
        logi(<i32>item);
      } else {
        // @ts-ignore
        let lo = <u32>item;
        // @ts-ignore
        let hi = <u32>(<u64>item >>> 32);
        logl(lo, hi);
      }
    } else {
      // @ts-ignore
      logf(<f64>item);
    }
  }
}

class A {
  public a: i32 = 800;
  public c: i32;
}

class B extends A {
  public b: i32 = 600;
}

let aInst = instantiate<B>();
store<i32>(<usize>changetype<usize>(aInst) + offsetof<B>('c'), <i32>200);
log(aInst.a);
log(aInst.c);

//Here a and c are correctly assigned, but in iceclam, and the member variables in webglcontext are not assigned.