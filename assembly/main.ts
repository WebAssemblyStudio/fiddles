// The entry file of your WebAssembly module.
import "allocator/buddy";

/*
interface simetypeFn<T,B> {
  new (value: T): simetype<T,B>;
};
*/

// first should be v128, second should be base type i.e. f32, i32 or u32 (planned type casting)
/*abstract class simetype<T,B> {
  public abstract add(a: T, b: T): T;
  public abstract get(a: T): B;
  public abstract splat(a: B): T;
};*/

// based on v128, f32, type methods, there is no data (align=0)
/*
let f32x4_t: simetype<f32, f32> = {
  add: (a: f32, b: f32) => { return a + b; },
  get: (a: f32) => { return a; },
  splat: (a: f32) => { return a; }
};
*/

// use class with prototype methods
class f32x4_t { 
  public add(a: f32, b: f32): f32 { return a + b; };
  public get(a: f32): f32 { return a; };
  public splat(a: f32): f32 { return a; };
}


// imported function for logging
class simd_wrap<T,B> {
  constructor(protected a: T, protected M: f32x4_t) {};
  @inline public splat(a: B): simd_wrap<T,B> { return new simd_wrap(this.M.splat(a), this.M); };
  @inline public get(): T { return this.a; };
  @inline public set(a: T): simd_wrap<T,B> { this.a = a; return this; };
  @inline public add(b: simd_wrap<T,B>, c: simd_wrap<T,B>): simd_wrap<T,B> { return c.set(this.M.add(this.get(),b.get())); };
  @inline public ptr(): simd_wrap<T,B> { return this; };
};

// create constructor by template (zero argument, typed methods)
let f32x4_wrap = new simd_wrap<f32,f32>(0, new f32x4_t());

// splat constructor wrap (fixed*, with return state)
function f32x4_splat(a: f32): simd_wrap<f32,f32> { 
  return f32x4_wrap.splat(a); 
}

// should be possible to export as WebAssembly module function (constructor)
export {
  f32x4_splat
};